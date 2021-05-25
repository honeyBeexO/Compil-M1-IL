%{
      #include "symbtab.c"
      #include "quadMat.c"
      #include "pile.c"
      extern FILE * yyin;
      void yyerror(char *);
      int yylex(void);
      int sym[26];

      int type = -1;
      int taille = -1;
      char isConst[4] = "non";

       int linenum ;
       int qc ;
       int erro_parenthese;
/*--------------- Pour verifier la compatibilte entre les type : partieGauche compatibe ? partieDroite -----*/
      int compatibilite = -1;

      int compatibilitePdroite = -1;
      int compatibilitePgauche = -1;

      int typeOP1 = -1;
      int typeOP2 = -1;

      Pile compatible;
      int type_const = 0;
      char *cp = "";
/*--------------- pour verifier la division ----------------------------*/
      char operator;
      float fv;
/*--------------- instruction de IF -------------------------------------*/
      int DebInstIF = 0;
      int FinInstIF = 0;
      int FinCondIF = 0;
      int DebCondIf = 0;
/*--------------- instruction de While ---------------------------------*/
      int DebCondWhile = 0;
      int FinCondWhile = 0;
      int FinInstWhile = 0;

      char OP_CON[3];
      int i = 0;

      char *temporaryName = "";
      char *temporaryNameAffect = "";

      char ToString[10];

      Pile p ;
      char expression[100];
      char *e;

/*-------- pour manipuler les expression ----------*/
    char oper[10]="";
    char *op1 ="";
    char *op2 ="";
    char res[10]="";

/*-------- pour manipuler les conditions ----------*/
      char *pDroiteCond = "";
      char *pGaucheCond = "";
      int   quadCondNum = -1;

/*-------- pour manipuler les Affectations ----------*/
      char *pGaucheAffect = "";
      char *pDroiteAffect = "";


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

Variable:Type {strcpy(isConst,"non");} list_idf MC_SEMI 
;

Constante:MC_CONST {strcpy(isConst,"oui");} MC_IDF MC_AFFECT Value MC_SEMI
;



/* check for double declaration and insererType */
list_idf: MC_IDF {}
        |  MC_IDF MC_COMMA list_idf{}
;

Type: MC_INTEGER        { type = 0; }
    | MC_REAL           { type = 1; }
    | MC_STRING         { type = 2; }
    | MC_CHAR           { type = 3; }
;



Instruction :  Affectation Instruction {}
            | IF Instruction                     {}
            | While Instruction                  {}
            | 
;


Affectation: BBB Expression MC_SEMI
;
BBB: MC_IDF{compatibilite = getType($1);} MC_AFFECT
;
Expression : Expression MC_ADD T
           | Expression MC_SUB T
           | T
;

T: T MC_MUL F
 | T MC_DIV F
 | F
;

F:MC_IDF {

      if(NotDeclared($1) == 1){
          //make it equal to 1 later babe OK 
              printf("IDF [%s] at line [%d] not declared\n",$1,linenum);
      }
      //on empile le type de cette idf 
      compatibilite = getType($1); 
      /*----- le type de cette idf est dans i -------*/
      sprintf(ToString,"%d",compatibilite);

      empiler(&compatible,ToString);
      empiler(&p,$1);

      //sprintf(ToString,"%d",compatibilite);
}     
|Value {/* dans la garmmaire de valeur ====> */
}
|L_PAREN Expression R_PAREN {}
;

/*
 *------------- le grammaire des valeur constante      -----------------------------*
 * une valeur constante peut etre : 
 *    int   :     0,1...9
 *    float :     3.14 , 2.5 .....
 *    string:     "isilA",....
 *    CHAR  :     'A'
*/
Value:INTEGER_CONST
{  

      type_const = 0;

      fv = $1;

      sprintf(ToString,"%d",type_const);
      empiler(&compatible,ToString);
      
      sprintf(ToString,"%d",$1);
      empiler(&p,ToString);

      strcpy(ToString,"");
}
|REAL_CONST
{    
    type_const = 1;
        fv = $1;

      sprintf(ToString,"%d",type_const);
      empiler(&compatible,ToString);
      
      sprintf(ToString,"%f",$1);
      empiler(&p,ToString);

      strcpy(ToString,"");
}
|STRING_CONST 
{ 

      type_const = 2;   
      sprintf(ToString,"%d",type_const);
      empiler(&compatible,ToString);


      strcpy(ToString,$1);
      empiler(&p,$1);

      strcpy(ToString,"");
}
|CHAR_CONST 
{ 

      type_const = 3;   

      sprintf(ToString,"%d",type_const);
      empiler(&compatible,ToString);


      strcpy(ToString,&($1));
      empiler(&p,&($1));

      strcpy(ToString,"");
}
;

/*----------- le grammaire modifiee de : <Condition>  -------------------------------
 * La condition peut etre de la forme expression Operateur_Logique Expression
 * donc on insere les quad de la partie droite de la condition puis on empile le resultat
 * de ces quad c.a.d le sommet de pile sera soit un idf | ValeurConst | nomTemporair
 * puis de meme pour la partie gauche de la condition
 * 
 * 
      Condition:Expression OP_COND Expression
;*/

OP_COND:MC_SUP_EQUAL    {  strcpy(OP_CON,$1);      }
       |MC_INF_EQUAL    {  strcpy(OP_CON,$1);      }
       |MC_STRICT_SUP   {  strcpy(OP_CON,$1);      }
       |MC_STRICT_INF   {  strcpy(OP_CON,$1);      }
       |MC_EQUAL        {  strcpy(OP_CON,$1);      }
       |MC_NOT_EQUAL    {  strcpy(OP_CON,$1);      }
;


Condition:Expression OP_COND Expression
{

      pGaucheCond= depiler(&p);
     
      printf("pGauche de Condi %s \n",pGaucheCond);
      quadCondNum = qc;
      insererQUADR(comparateurReverse(OP_CON),"","","");

      pDroiteCond = depiler(&p);
      printf("pDroite de Condi %s \n",pDroiteCond);

      ajour_quad(quadCondNum,2,pDroiteCond);
      ajour_quad(quadCondNum,3,pGaucheCond);
      /***------- ici il restla position 1 dy quad qu'on viens d'insere  
       *          on va la mettre a jour dans le fin de IF et Fin De while
       * ------ ***/
     initializerVar(&pDroiteCond,&pGaucheCond);
     //quadCondNum = -1;
} 
;

/*
AB: OP_COND Expression{

      quadCondNum = qc;
      insererQUADR(comparateurReverse(OP_CON),"","","");
      pDroiteCond = depiler(&p);
}
;

AC: Expression {}
;
*/

/*------------- EXECUTE | <Instructions> |IF | <Condition> |-------*/


IF:B Condition R_PAREN{//R3
//toString contient la valeur de FinCondIF sous forme d'un string

      FinCondIF = qc;
      sprintf(ToString,"%d",FinCondIF);
      ajour_quad(FinInstIF,1,ToString);

      /*-------- mettre a jour le quad de la condition ----*/
        sprintf(ToString,"%d",DebInstIF);
        ajour_quad(quadCondNum,1,ToString);
        ajour_quad(quadCondNum,0,comparateur(OP_CON));

      FinInstIF = -1;
      DebInstIF = -1;
      DebCondIf = -1;
      FinCondIF = -1;

      strcpy(ToString,"");
    
};

B:C L_PAREN {//R2
      
      /*
       *      ensuite il faut mettre a jour le BR de la routine 1 : < C insereQuad> des       
       *          <INstructions>
      */
     DebCondIf = qc;
     sprintf(ToString,"%d",DebCondIf);
     ajour_quad(DebInstIF,1,ToString);

};

C: D Instruction MC_IF {//R1
      
     /*----- pour executer les instructions qu'une seule fois ----*/
     FinInstIF = qc;
     insererQUADR("BR","","","");

};
D:MC_EXECUTE {//R1
      /*----- aller a l'evaluation de la condition -----*/
      DebInstIF = qc;
      insererQUADR("BR","","","");
}


/*------------- While ( Condition )Faire  <Instructions> Fait; -------*/

While:AA R_BRACE {

       sprintf(ToString,"%d",DebCondWhile);
       insererQUADR("BR",ToString,"","");

      FinInstWhile = qc;
      sprintf(ToString,"%d",FinInstWhile);

      ajour_quad(DebCondWhile,1,ToString);
      //ajour_quad(DebCondWhile,0,comparateurReverse(OP_CON));

      quadCondNum = -1;
      strcpy(OP_CON,"");
}
;
AA:BB R_PAREN MC_EXECUTE Instruction {

      //insertion de quad qui fait le branchement sur la condition de while debut de la condition
     

      /*
      mise a jour de quad qui contient la valeur de TemCond pour qu'il fait le jump dans le cas de condition non verifier
      */
      FinInstWhile = qc;
      sprintf(ToString,"%d",FinInstWhile);
      //ajour_quad(quadCondNum,1,ToString);
      //quadCondNum = -1;
}
;

BB:CC Condition {
        FinCondWhile = qc;
}
;

CC:MC_WHILE L_PAREN {
      DebCondWhile = qc;
}


%%

void yyerror(char *s) {
   fprintf(stderr, "%s\n", s);
}
 int main(int argc,char **argv){
     yyin = fopen( "programme.txt", "r" );

      init();           //elle initialise ma table de ymbole
      initialize();     //elle initialiser ma matrice quad

     if (yyin==NULL) 
            printf("ERROR  \n");
     else{ 
            yyparse();
            // afficherTS();
            // printQuad(quadMatrix);
     }
      return 0;
}
