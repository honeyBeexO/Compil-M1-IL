%{

   #include "synt.tab.h"
   

   extern int linenum = 4; // initialize to 1

   void ret_print(char *token_type);
   void yyerror();

   extern YYSTYPE yylval;
   //extern TS *ts;
%}

%x MY_COMMENT

alpha      [a-zA-Z]
digit      [0-9]
alpha_num      ({alpha}|{digit}|[_])*
print      [ -~]

IDF         [A-Z]+{alpha_num}*
INT_CONST      [-+]?("0"|[0-9]{digit}*)
FLOAT_CONST      [-+]?("0"|{digit}*"."{digit}+)
STRING      \"{print}*\"

%%


"{{" { 
      printf("ignorer les commentaires de ligne %d ", linenum); 
      BEGIN(MY_COMMENT); 
}

<MY_COMMENT>"}}" { 
      printf("a ligne %d\n", linenum); 
      BEGIN(INITIAL); 
      }

<MY_COMMENT>[ -~] {/* SAUTER N'IMPORT QUELLE CARACTERE */}

<MY_COMMENT>"\n" { 
      linenum += 1; 
}

"CONST"|"const"  {
      yylval.str = strdup(yytext); 
      return MC_CONST; 
      }

"int"|"INT"    {
      
      yylval.str = strdup(yytext); 
     
      return MC_INT;
      }
"float"|"FLOAT"  {
      yylval.str = strdup(yytext); 
     
      return MC_FLOAT;
      }
"STRING"|"string" {
      yylval.str = strdup(yytext);
      
      return MC_STRING;
      }

"execute"|"EXECUTE"  { return MC_EXECUTE;}

"if"|"IF"     { return MC_IF; }
"while"|"WHILE"	{ return MC_WHILE;}
"FAIRE"|"faire"  { return MC_FAIRE;}
"FAIT"|"fait"  { return  MC_FAIT;}

"TAB"|"tab" {
      yylval.str = strdup(yytext);
      return MC_TAB;
      }

"LANGAGE"|"langage" {return MC_LANG;}
"VAR"|"var" {return MC_VAR;}
"FINDEC"|"findec" {return MC_FINDEC;}
"DEBUT"|"debut" {return MC_DEBUT;}
"FIN"|"fin" {return MC_FIN;}
"DECLARE"|"declare" {return "MC_DECLARE";}

"input"|"INPUT" return MC_INPUT;
"output"|"OUTPUT" return MC_OUTPUT;

#TAB[ \t]*\n {
     // yylval.str = malloc(yyleng * sizeof(char));
      //strcpy(yylval.str,yytext); 
       yylval.str = strdup(yytext);
      return MC_BIB_TAB;
      }

#ARITHM[ \t]*\n {
     //yylval.str = malloc(yyleng * sizeof(char));
      //strcpy(yylval.str,yytext);
       yylval.str = strdup(yytext); 
      return MC_BIB_ARITHM;
      }

#InOut[ \t]*[\n] {
      yylval.str = strdup(yytext);
      //inserer(ts,yytext,yyleng);
      //yylval.str = malloc(yyleng * sizeof(char));
      //strcpy(yylval.str,yytext); 
      return MC_BIB_INOUT;
      }

"+"      {yylval.str = strdup(yytext); return MC_ADD;}
"-"      {yylval.str = strdup(yytext); return MC_SUB; }
"*"    {yylval.str = strdup(yytext); return MC_MUL; }
"/"     {yylval.str = strdup(yytext);  return MC_DIV; }
"%"   {yylval.str = strdup(yytext); return MC_MOD;}

"=="  {yylval.str = strdup(yytext);return MC_EQUAL;}
"!="    {yylval.str = strdup(yytext); return MC_NOT_EQUAL;}
">"      {yylval.str = strdup(yytext); return MC_STRICT_SUP; }
"<"    {yylval.str = strdup(yytext); return MC_STRICT_INF;}
">="    {yylval.str = strdup(yytext); return MC_SUP_EQUAL;}
"<="      {yylval.str = strdup(yytext); return MC_INF_EQUAL; }


"("      {  return L_PAREN;}
")"      {  return R_PAREN; }
"]"      {  return L_BRACK;}
"["      {  return R_BRACK;}
"{"      {  return L_BRACE;}
"}"      {  return R_BRACE;}

";"      {  return MC_SEMI;}
","      { return MC_COMMA;}
":="     {  return MC_AFFECT;}
"::"     {   return MC_DP;}


{INT_CONST}     {
      if(valid_int(atoi(yytext)) == 1){
      yylval.entier = atoi(yytext); 
      return INT_CONST;
      }else{
            printf("entier trop long \n");
      }
      }

{FLOAT_CONST}  {
      yylval.reel = atof(yytext); 
      return FLOAT_CONST; 
      }

{STRING} {
     // yylval.str = malloc(yyleng * sizeof(char));
      //strcpy(yylval.str,yytext); 
       yylval.str = strdup(yytext);
      return STRING_CONST; }

{IDF} {
      if(valid_idf(yytext)){
            yylval.str = strdup(yytext); 
      
            inserer(yytext);

            return MC_IDF; 
      }else{
            printf("ligne: %d ,idf trop long : ' %s '\n",linenum,yytext);
      }
      }


"\n"  { linenum += 1; }
[ \t\r\f]+  /* eat up whitespace */

. { yyerror(" character not recognized, LEXICAL ERREUR \n"); }

%%

void ret_print(char *token_type){
   printf("yytext: %s\ttoken: %s\tlinenum: %d\n", yytext, token_type, linenum);
}

void yyerror(char *message){
   printf("Error: \"%s\" in line %d. Token = %s\n", message, linenum, yytext);
   exit(1);
}

