%{

      #include "syntax.tab.h"   
      #include "ts.h"
      extern int lineNumber = 1; // initialize to 1
      extern int columnNumber = 1; // initialize to 1
      void ret_print(char *token_type);
      extern YYSTYPE yylval;

%}

alpha      [a-zA-Z]
digit      [0-9]
print      [ -~]

INTEGER_CONST [-+]?{digit}{1,6}
REAL_CONST      [-+]?("0"|{digit}*"."{digit}+)
STRING_CONST      \"{print}*\"
CHAR_CONST \'({alpha}|{digit})'
IDF [A-Z]+({alpha}|{digit}){0,19}
%%

"CODE" {return MC_CODE;}
"START" {return MC_START;}
"END" {return MC_END;}

"INTEGER"|"integer"    {
      yylval.str = strdup(yytext); 
      return MC_INTEGER;
      }
"REAL"|"real"  {
      if(strlen(yytext)>20) printf("IDF too long\n");
      yylval.str = strdup(yytext); 
      return MC_REAL;
      }
"STRING"|"string" {yylval.str = strdup(yytext);return MC_STRING;}
"CHAR" {yylval.str = strdup(yytext);return MC_CHAR;}

"CONST" {
      yylval.str = strdup(yytext); 
      return MC_CONST; 
      }


"WHILE" {
      yylval.str = strdup(yytext);
      return MC_WHILE;
      }
"EXECUTE" {yylval.str = strdup(yytext);return MC_EXECUTE;}


"WHEN" {yylval.str = strdup(yytext);return MC_WHEN;}
"DO"|"do" {yylval.str = strdup(yytext);return MC_DO;}
"OTHERWISE" {yylval.str = strdup(yytext);return MC_OTHERWISE;}
"PROD" {yylval.str = strdup(yytext);return MC_PROD;}

"+"      {yylval.str = strdup(yytext); return MC_ADD;}
"-"      {yylval.str = strdup(yytext); return MC_SUB; }
"*"    {yylval.str = strdup(yytext); return MC_MUL; }
"/"     {yylval.str = strdup(yytext);  return MC_DIV; }

"=="  {yylval.str = strdup(yytext);return MC_EQUAL;}
"!="    {yylval.str = strdup(yytext); return MC_NOT_EQUAL;}
">"      {yylval.str = strdup(yytext); return MC_STRICT_SUP; }
"<"    {yylval.str = strdup(yytext); return MC_STRICT_INF;}
">="    {yylval.str = strdup(yytext); return MC_SUP_EQUAL;}
"<="      {yylval.str = strdup(yytext); return MC_INF_EQUAL; }


"("      {  return L_PAREN;}
")"      {  return R_PAREN; }
"{"      {  return L_BRACE;}
"}"      {  return R_BRACE;}

";"      {  return MC_SEMI;}
","      {  return MC_COMMA;}
":="     {  return MC_AFFECT;}
":"     {  return MC_DP;}
"."     {  return MC_DOT;}

{INTEGER_CONST} {
      int valid_int = atoi(yytext);
      if(yyleng>6){
            printf(":entier trop long\n");
      yyterminate();
      }else{
            if (valid_int <= 32720 && valid_int>= -32720){
                  yylval.integer = valid_int; 
                  return INTEGER_CONST;
      }else{
            printf("entier trop long \n");
      }
      }
      }

{REAL_CONST}  {
      yylval.real = atof(yytext); 
      return REAL_CONST; 
      }

{STRING_CONST} {
       yylval.str = strdup(yytext);
      return STRING_CONST; 
      }
{CHAR_CONST} {
       yylval.myChar = strdup(yytext)[0];
      return CHAR_CONST; 
      }

{IDF} {
      if(strlen(yytext)<20){
            yylval.str = strdup(yytext); 
            inserer(yytext,"IDF", hachage(yytext));
            return MC_IDF; 
      }else{
            printf("line: %d idf trop long: %s \n",lineNumber,yytext);
      }
}

[ \t]
[ \t\r\f]+ /* eat up whitespace */
\n lineNumber++;
. { printf("Error Lexical a la ligne: %d\n",lineNumber);
    yyterminate();
}
%%
void ret_print(char *token_type){
   printf("yytext: %s\ttoken: %s\t linenum: %d\n", yytext, token_type, lineNumber);
}
int yywrap(){
      return 1;
}