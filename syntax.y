%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "pile.h"
    #include "quad.h"

    extern FILE * yyin;
    void yyerror(char *);
    int yylex(void);
    void afficher();
    int doubleDeclaration(char entites[]);
    void insererType(char entites[], char typ[], char nature[], int taille);

    char sauvType[20];
    int quadNumber = 0;
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
            insererType($2,"Constante","Const",1);
}
;


list_idf: MC_IDF {
    if(doubleDeclaration($1) == 0){
        inserIdfDecl($1);
        insererType($1,sauvType,"Variable",1);
    }else{
        printf("ERROR semantique: Double declaration\n");
    }
}
        |  MC_IDF MC_COMMA {
    if(doubleDeclaration($1) == 0){
        inserIdfDecl($1);
        empiler($1);
        insererType($1,sauvType,"Variable",1);
    }else{
        printf("ERROR semantique: Double declaration\n");
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


Affectation: BBB Expression MC_SEMI
;
BBB: MC_IDF MC_AFFECT{
    if(routinIdfDeclar($1) == 0) printf("\n ERREUR IDF %s NON DECLAREE ! \n \n",$1); 
    insertQuadreplet(":=","","",$1);
}
;

Expression : Expression MC_ADD T
           | Expression MC_SUB T
           | T
;
T: T MC_MUL F
 | T MC_DIV F
 | F
;
F:MC_IDF { if(routinIdfDeclar($1) == 0) printf("\n ERREUR IDF %s NON DECLAREE ! \n \n",$1); }
 | Value
 | L_PAREN Expression R_PAREN {}
;


Value:INTEGER_CONST {char *s; asprintf(&s, "%i", $1);updateQuadreplet(quadNumber,1,s);free(s);}
|REAL_CONST {char *s; asprintf(&s, "%f", $1);updateQuadreplet(quadNumber,1,s);free(s);}
|STRING_CONST {updateQuadreplet(quadNumber,1,$1);}
|CHAR_CONST {char *s; asprintf(&s, "%c", $1); updateQuadreplet(quadNumber,1,s);free(s);}
;

/*----------- le grammaire modifiee de : <Condition>  --------
 * La condition peut etre de la forme expression 
 * Operateur_Logique Expression
 * donc on insere les quad de la partie droite de 
 * la condition puis on empile le resultat
 * de ces quad c.a.d le sommet de pile sera 
 * soit un idf | ValeurConst | nomTemporair
 * puis de meme pour la partie gauche de la condition
 * 
      Condition:Expression OP_COND Expression
*/

OP_COND: MC_SUP_EQUAL    
       | MC_INF_EQUAL    
       | MC_STRICT_SUP   
       | MC_STRICT_INF   
       | MC_EQUAL       
       | MC_NOT_EQUAL    
;


Condition:Expression OP_COND Expression{} 
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
