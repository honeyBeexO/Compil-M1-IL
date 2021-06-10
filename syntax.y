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
    int quadNumber = 0;
    int temp = 0;
    char *op1="",*op2="";
    int isFisrtTime = 0;
    char typeDroite[10];
    char typeGauche[10];
    int quadAffectNum = 0;
    int i = 0;
    
    void printStack(Pile *p);
    void push(Pile *p, char x[]);
    char *pop(Pile *p);
    void toPostfix(Pile *_expression, Pile *_result);
    char *generateTemporaryName(int number);
    int compatibilityTest(Pile *_pile);

    Pile _compatible = NULL;
    
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
<str>MC_NOT_EQUAL <str>MC_EQUAL

%token <integer>INTEGER_CONST <real>REAL_CONST <str>STRING_CONST <myChar>CHAR_CONST

%token MC_IF MC_WHILE MC_WHEN MC_PROD
%token MC_EXECUTE MC_DO MC_OTHERWISE

%%
S:MC_CODE MC_IDF Declaration MC_START Instruction MC_END MC_DOT{
      printf("\n --- Votre Programme a compilé correct --- \n");
      YYACCEPT;
      }
;

Declaration: Variable Declaration
           | Constante Declaration
           |
;

Variable:Type list_idf MC_SEMI 
;

Constante:MC_CONST MC_IDF MC_AFFECT Value MC_SEMI{
     if(doubleDeclaration($2) == 0){
        inserIdfDecl($2);
        insererType($2,"Constante","Const",1);
    }else{
        printf("ERROR: Double declaration DE CONSTANTE %s\n",$2);
    }
}
;


list_idf: MC_IDF {
    if(doubleDeclaration($1) == 0){
        inserIdfDecl($1);
        /* empiler($1); */
        insererType($1,sauvType,"Variable",1);
    }else{
        printf("ERROR: Double declaration\n");
    }
}
        |  MC_IDF MC_COMMA {
    if(doubleDeclaration($1) == 0){
        inserIdfDecl($1);
        /* empiler($1); */
        insererType($1,sauvType,"Variable",1);
    }else{
        printf("ERROR: Double declaration\n");
    }
} list_idf {}
;

Type: MC_INTEGER        {strcpy(sauvType,"INTEGER");}      
    | MC_REAL           {strcpy(sauvType,"REAL");}
    | MC_STRING         {strcpy(sauvType,"STRING");}
    | MC_CHAR           {strcpy(sauvType,"CHAR");}
;



Instruction : Affectation Instruction {}
            | When Instruction               {}
            | IF Instruction                 {}
            | While Instruction              {}
            | Expression MC_SEMI Instruction {}
            |
;


Affectation: BBB Expression MC_SEMI{
    //Evaluer la compatibilite de l'expression
    printStack(&_compatible);
    if(!compatibilityTest(&_compatible)){
        printf("ERROR DE COMPATIBILITÉ LIGNE -> %d:%d\n",lineNumber,columnNumber);
    }
    //Evaluer les quad de la pille
    toPostfix(&_pile,&_postFixed);

    Pile evaluer = NULL;
    Pile temp = _postFixed;

    int size = getSize(&_postFixed);
    char *T[size];
    
    char *x="";
    char *temporaryName="";
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
            temporaryName = generateTemporaryName(i); // generate temporaire name
            push(&evaluer,temporaryName);
            insertQuadreplet(x,op1,op2,temporaryName);
            i++;
        } 
    }
    /* Mettre a jour le quadreplet de resultats final de l'expression*/
    updateQuadreplet(quadAffectNum,1,temporaryName);
    printStack(&evaluer);
}
;
BBB: MC_IDF MC_AFFECT{
    _pile=NULL;
    _postFixed=NULL;
    _compatible=NULL;

    char *type = getType($1);
    push(&_compatible,type);

    if(routinIdfDeclar($1) == 0){
        printf("\n ERREUR IDF %s NON DECLAREE ! \n",$1); 
    }else{
       printf("type de %s est %s\n",$1, getType($1));
       quadAffectNum = qc; //le num de quad courant
       insertQuadreplet(":=","","",$1);
       strcpy(typeGauche,type);
    }
}
;

Expression : Expression MC_ADD{push(&_pile,"+");} T{
    isFisrtTime=0;
    //insertQuadreplet("+",op1,op2,"t1");
    /* updateQuadreplet(quadAffectNum,1,"t1"); */
}
           | Expression MC_SUB{{push(&_pile,"-");}} T
           | T
;
T: T MC_MUL{push(&_pile,"*");} F
 | T MC_DIV{push(&_pile,"/");} F{}
 | F
;
F:MC_IDF {
    char *type = getType($1);
    push(&_compatible,type);
     if(routinIdfDeclar($1) == 0) 
        {        
            printf("\n ERREUR IDF %s NON DECLAREE ! \n \n",$1); 
        }else{
            char *str = strdup($1);
            push(&_pile,str);
    }
    /*
    char *type = getType($1);
    printf("Type %s - %s\n",$1,type); 
    if(isFisrtTime == 0){
         strcpy(typeDroite,type);
         strcpy(op1,strdup($1));
         isFisrtTime=1;
     }else{
         if(strcmp(typeDroite,type) == 0){
             printf("Type incompatible\n");
         }
         strcpy(op2,$1);
     } */
    }
 | Value
 | L_PAREN Expression R_PAREN {}
 
;


Value:INTEGER_CONST {
    char *s; 
    asprintf(&s, "%i", $1);
    push(&_pile,s);
    push(&_compatible,"INTEGER");
    if(quadNumber != 0){
        //updateQuadreplet(quadNumber,1,s);
    }
    free(s);
}
|REAL_CONST {
    char *s; 
    asprintf(&s, "%f", $1);
    push(&_pile,s);
    push(&_compatible,"REAL");

    if(quadNumber != 0){
        //updateQuadreplet(quadNumber,1,s);
    }
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


OP_COND: MC_SUP_EQUAL    
       | MC_INF_EQUAL    
       | MC_STRICT_SUP   
       | MC_STRICT_INF   
       | MC_EQUAL       
       | MC_NOT_EQUAL    
;


Condition:Expression OP_COND Expression{
    printf("pile de l'expression: \n");
    printStack(&_pile);
    toPostfix(&_pile,&_postFixed);
    printf("pile de l'expression postifxee: \n");
    printStack(&_postFixed);
} 
;


/*------------- EXECUTE | <Instructions> |IF | <Condition> |-------*/

When: MC_WHEN L_PAREN Condition {
    insertQuadreplet("BZ","","","");
    printf("qc= %i - quadNumber= %i \n",qc,quadNumber);
} R_PAREN MC_DO L_BRACE Instruction R_BRACE X2
; 
X2: MC_OTHERWISE L_BRACE Instruction R_BRACE MC_SEMI
| MC_SEMI
|
;

IF:B Condition R_PAREN{};
B:C L_PAREN {}
;

C: D Instruction MC_IF {};
D:MC_EXECUTE {/*aller a l'evaluation de la condition       // insererQUADR("BR","","","");*/}


/*------------- While ( Condition )Faire  <Instructions> Fait; -------*/

While:AA R_BRACE MC_SEMI {}
;
AA:BB R_PAREN MC_EXECUTE L_BRACE Instruction {}
;

BB:CC Condition {}
;

CC:MC_WHILE L_PAREN {}


%%


void yyerror(char *s) {
   fprintf(stderr, "%s\n", s);
}
 int main(int argc,char **argv){
     initialize();
     yyin = fopen( "programme.txt", "r" );
    if (yyin==NULL) 
            printf("ERROR  \n");
     else{ 
            yyparse();
            afficher();
            afficherDecl();
            printQuadreplet();
     }
      return 0;
}
