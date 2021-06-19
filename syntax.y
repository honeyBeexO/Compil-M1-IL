%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "pile.h"
    #include "quad.h"
    #include "util.h"

    extern FILE * yyin;
    void yyerror(char *);
    int yylex(void);

    void afficher();
    int doubleDeclaration(char entites[]);
    void insererType(char entites[], char typ[], char nature[], int taille);
    char *getType(char *idf);

    // From lexical.l
    int lineNumber;
    int columnNumber;

    char sauvType[20];
    int quadNumber = 0; // Numero du quad courant: it maps to qc inside quad.h
    char *op1="",*op2="";

    int quadAffectNum = 0;                           // Pour garder le quadreplet de debut de une affectation
    int i = 0;                                       // Pour generer des noms temporaires
    extern int hasCompilingErrors = 0;                      // Pour verifier les errors de compilation en fin du Programme
    char *temporaryName="";                          // This will keep the latest generated temporary name
    int quadCondNum = 0;
    int isAffectation = 0;

    void printStack(Pile *p);
    void push(Pile *p, char x[]);
    char *pop(Pile *p);
    void toPostfix(Pile *_expression, Pile *_result);
    char *generateTemporaryName(int number);
    int compatibilityTest(Pile *_pile);
    int getSize(Pile *p);

    Pile _compatible = NULL;

    /* Variables pour le WHEN   */
    int sauvBZ = 0;
    int sauvBR = 0;



void evaluateExpression(){
    //Evaluer la compatibilite de l'expression
    if(!compatibilityTest(&_compatible)){
        hasCompilingErrors++;
        printf("ERROR DE COMPATIBILITÉ LIGNE -> %d:%d\n",lineNumber,columnNumber);
    }
    //Evaluer les quad de la pille
    toPostfix(&_pile,&_postFixed);

    Pile evaluer = NULL;
    Pile temp = _postFixed;

    int size = getSize(&_postFixed);
    char *T[size];
    
    char *x="";
    // char *temporaryName="";
    if(size == 1 && isAffectation){
        x=pop(&temp);
        updateQuadreplet(quadAffectNum,1,x);
        return;
    }
    if(size == 1 && !isAffectation){
        x=pop(&temp);
        updateQuadreplet(quadCondNum,1,x);
        return;
    }
    while (!pileVide(temp))
    {
        x=pop(&temp);
        if(isOperator(x[0])==0){
            //Operande
            push(&evaluer,x);
        }else{
            //Operateur
            op1 = pop(&evaluer);
            op2 = pop(&evaluer);
            // result = Operation(op1,op2,x);
            if(strcmp(x,"/")==0 && strcmp(op2,"0")==0){
                printf("Division par zero ERROR ligne %d - %d\n", lineNumber,columnNumber);
            }
            temporaryName = generateTemporaryName(i); // generate temporaire name
            push(&evaluer,temporaryName);
            insertQuadreplet(x,op1,op2,temporaryName);
            i++;
        } 
    }
    /* Mettre a jour le quadreplet de resultats final de l expression*/
   if(isAffectation){
        updateQuadreplet(quadAffectNum,1,temporaryName);
   }/*else{
        updateQuadreplet(quadCondNum,1,temporaryName);
   } */
}
%}

%union{
        int integer;
        float real;
        char *str;
        char myChar;
}

%token MC_CODE <str>MC_IDF MC_START MC_END MC_DOT

%token MC_SEMI MC_COMMA MC_DP MC_AFFECT 

%token <integer>MC_INTEGER <real>MC_REAL <str>MC_STRING <myChar>MC_CHAR

%token <str>MC_CONST 

%token L_PAREN R_PAREN L_BRACE R_BRACE

%token <str>MC_ADD <str>MC_SUB <str>MC_MUL <str>MC_DIV

%token <str>MC_STRICT_SUP <str>MC_STRICT_INF <str>MC_SUP_EQUAL <str>MC_INF_EQUAL 
<str>MC_NOT_EQUAL <str>MC_EQUAL <str>MC_EQUAL_S

%token <integer>INTEGER_CONST <real>REAL_CONST <str>STRING_CONST <myChar>CHAR_CONST

%token MC_WHILE MC_WHEN MC_PROD
%token MC_EXECUTE MC_DO MC_OTHERWISE

%%
S:MC_CODE MC_IDF Declaration MC_START Instruction MC_END MC_DOT{
      if(hasCompilingErrors == 0){
          printf("\n --- Votre Programme a compilé avec %d error(s) --- \n",hasCompilingErrors);
      }else{
          printf("\n --- Votre Programme a compilé avec %d errors --- \n", hasCompilingErrors);
      }
      YYACCEPT;
      }
;

Declaration: Variable Declaration
           | Constante Declaration
           |
;

Variable:Type list_idf MC_SEMI 
;

Constante:MC_CONST Type MC_IDF MC_EQUAL_S Value MC_SEMI{
     if(doubleDeclaration($3) == 0){
        inserIdfDecl($3);
        insererType($3,"Constante","CONST",1);
    }else{
        hasCompilingErrors++;
        printf("ERROR: Double declaration de CONSTANTE %s ligne: %d - %d\n",$3,lineNumber,columnNumber);
    }
}
;


list_idf: MC_IDF {
    if(doubleDeclaration($1) == 0){
        inserIdfDecl($1);
        /* empiler($1); */
        insererType($1,sauvType,"Variable",1);
    }else{
        hasCompilingErrors++;
        printf("ERROR: Double declaration de %s ligne: %d - %d\n",$1,lineNumber,columnNumber);
    }
}
        |  MC_IDF MC_COMMA {
    if(doubleDeclaration($1) == 0){
        inserIdfDecl($1);
        /* empiler($1); */
        insererType($1,sauvType,"Variable",1);
    }else{
        hasCompilingErrors++;
        printf("ERROR: Double declaration de %s ligne: %d - %d\n",$1,lineNumber,columnNumber);
    }
} list_idf {}
;

Type: MC_INTEGER        {strcpy(sauvType,"INTEGER");}      
    | MC_REAL           {strcpy(sauvType,"REAL");}
    | MC_STRING         {strcpy(sauvType,"STRING");}
    | MC_CHAR           {strcpy(sauvType,"CHAR");}
;

Prod: MC_PROD{} L_PAREN list_expression R_PAREN
list_expression: Expression
                | list_expression MC_COMMA{push(&_pile,"*");} Expression

Instruction : Affectation Instruction {}
            | When Instruction               {}
            | While Instruction              {}
            | Expression MC_SEMI Instruction {}
            |
;


Affectation: BBB Expression MC_SEMI{evaluateExpression();isAffectation = 0;}
;
BBB: MC_IDF MC_AFFECT{
    _pile=NULL;
    _postFixed=NULL;
    _compatible=NULL;

    isAffectation = 1;

    char *type = getType($1);
    push(&_compatible,type);

    if(routinIdfDeclar($1) == 0){
        hasCompilingErrors++;
        printf("\n ERREUR IDF %s NON DECLAREE -> %d:%d\n",$1,lineNumber,columnNumber); 
    }
    /* else{
       quadAffectNum = qc; //le num de quad courant
       insertQuadreplet(":=","","",$1);
    } */
    quadAffectNum = qc; //le num de quad courant
    insertQuadreplet(":=","","",$1);
}
;

Expression : Expression MC_ADD{push(&_pile,"+");} T {}
           | Expression MC_SUB{push(&_pile,"-");} T {}
           | Prod
           | T {}
;
T: T MC_MUL{push(&_pile,"*");} F
 | T MC_DIV{push(&_pile,"/");} F{}
 | F
;
F:MC_IDF {
    char *type = getType($1);
    push(&_compatible,type);
    if(routinIdfDeclar($1) == 0){        
            hasCompilingErrors++;
            printf("\n ERREUR IDF %s NON DECLAREE -> %d:%d\n",$1,lineNumber,columnNumber); 
    }else{
            char *str = strdup($1);
            push(&_pile,str);
    }
}
 | Value
 | L_PAREN Expression R_PAREN 
 
;


Value:INTEGER_CONST {
    char *s; 
    asprintf(&s, "%i", $1);
    push(&_pile,s);
    push(&_compatible,"INTEGER");
    free(s);
}
|REAL_CONST {
    char *s; 
    asprintf(&s, "%f", $1);
    push(&_pile,s);
    push(&_compatible,"REAL");
    free(s);

}
|STRING_CONST {
    char *s; 
    asprintf(&s, "%s", $1); 
    push(&_pile,s);
    push(&_compatible,"STRING");
    free(s);
    }
|CHAR_CONST {
    char *s; 
    asprintf(&s, "%c", $1); 
    push(&_pile,s);
    push(&_compatible,"CHAR");
    free(s);
    }
;


OP_COND: MC_SUP_EQUAL           {push(&_pile,"G");}    
       | MC_INF_EQUAL           {push(&_pile,"L");}    
       | MC_STRICT_SUP          {push(&_pile,">");}   
       | MC_STRICT_INF          {push(&_pile,"<");}   
       | MC_EQUAL               {push(&_pile,"=");}       
       | MC_NOT_EQUAL           {push(&_pile,"!");}    
;


Condition:Expression OP_COND Expression{
    // Evaluer l'expression de la partie gauche 
    // Garder le tomporaire
    quadCondNum = qc;
    evaluateExpression();
} 
;


/*---WHEN(<condition>)DO{<Instruction>}OTHERWISE{ <Instruction> }; --*/

When: MC_WHEN{ _pile=NULL;_postFixed=NULL;_compatible=NULL; isAffectation=0; } L_PAREN Condition {
    //A
    sauvBZ = qc;
    quadAffectNum = qc; //le num de quad courant
    insertQuadreplet("BZ","","",temporaryName);
} R_PAREN{
} MC_DO L_BRACE Instruction{
    //B
    sauvBR=qc;
    char *s; 
    asprintf(&s, "%i", qc+1); 
    insertQuadreplet("BR","","","");
    updateQuadreplet(sauvBZ,1,s);
    free(s);
} R_BRACE X2
; 
X2: MC_OTHERWISE L_BRACE Instruction R_BRACE MC_SEMI{
    //C
    char *s; 
    asprintf(&s, "%i", qc); 
    updateQuadreplet(sauvBR,1,s);
    free(s);
}
| MC_SEMI{
    //C
    char *s; 
    asprintf(&s, "%i", qc); 
    updateQuadreplet(sauvBR,1,s);
    free(s);
}
|
;

/*------------- While ( Condition )Faire  <Instructions> Fait; -------*/

While:AA R_BRACE MC_SEMI {
        //C
    char *s; 
    asprintf(&s, "%i", qc); 
    updateQuadreplet(sauvBR,1,s);
    free(s);
}
;
AA:BB R_PAREN MC_EXECUTE L_BRACE Instruction {
        //B
    sauvBR=qc;
    char *s; 
    asprintf(&s, "%i", qc+1); 
    insertQuadreplet("BR","","","");
    updateQuadreplet(sauvBZ,1,s);
    free(s);
}
;

BB:CC Condition {
        //A
    sauvBZ = qc;
    quadAffectNum = qc; //le num de quad courant
    insertQuadreplet("BZ","","",temporaryName);
}
;

CC:MC_WHILE{ _pile=NULL;_postFixed=NULL;_compatible=NULL; isAffectation=0; } L_PAREN {}


%%


void yyerror(char *s) {
   fprintf(stderr, "%s\n", s);
}
 int main(int argc,char **argv){
     initialize();
     yyin = fopen( "programme.txt", "r" );
    if (yyin==NULL) 
            printf("ERROR Lors de l'ouverture de fichier... \n");
     else{ 
            yyparse();
            afficher();
            //afficherDecl(); // table pour verifier les declarations
            printQuadreplet();
     }
      return 0;
}
