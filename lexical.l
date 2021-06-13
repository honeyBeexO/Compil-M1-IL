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

"CODE" {columnNumber+=yyleng; return MC_CODE; }
"START" {columnNumber+=yyleng; return MC_START; }
"END" {columnNumber+=yyleng; return MC_END; }

"INTEGER"    {
      yylval.str = strdup(yytext); 
      columnNumber+=yyleng;
      return MC_INTEGER;
      }
"REAL"  {
      columnNumber+=yyleng;
      if(strlen(yytext)>20) 
            printf("IDF too long\n");
      yylval.str = strdup(yytext); 
      return MC_REAL;
      }
"STRING" {columnNumber+=yyleng; yylval.str = strdup(yytext);return MC_STRING; }
"CHAR" {columnNumber+=yyleng; yylval.str = strdup(yytext);return MC_CHAR;}

"CONST" {
      columnNumber+=yyleng;
      yylval.str = strdup(yytext); 
      return MC_CONST; 
      }


"WHILE" {
      columnNumber+=yyleng;
      yylval.str = strdup(yytext);
      return MC_WHILE;
      }
"EXECUTE" {columnNumber+=yyleng; yylval.str = strdup(yytext);return MC_EXECUTE;}


"WHEN" {columnNumber+=yyleng; yylval.str = strdup(yytext);return MC_WHEN;}
"DO"|"do" {columnNumber+=yyleng; yylval.str = strdup(yytext);return MC_DO;}
"OTHERWISE" {columnNumber+=yyleng; yylval.str = strdup(yytext);return MC_OTHERWISE;}
"PROD" {columnNumber+=yyleng; yylval.str = strdup(yytext);return MC_PROD;}

"+"      {columnNumber+=yyleng; yylval.str = strdup(yytext); return MC_ADD;}
"-"      {columnNumber+=yyleng; yylval.str = strdup(yytext); return MC_SUB; }
"*"    {columnNumber+=yyleng; yylval.str = strdup(yytext); return MC_MUL; }
"/"     {columnNumber+=yyleng; yylval.str = strdup(yytext);  return MC_DIV; }

"=="  {columnNumber+=yyleng; yylval.str = strdup(yytext);return MC_EQUAL;}
"!="    {columnNumber+=yyleng; yylval.str = strdup(yytext); return MC_NOT_EQUAL;}
">"      {columnNumber+=yyleng; yylval.str = strdup(yytext); return MC_STRICT_SUP; }
"<"    {columnNumber+=yyleng; yylval.str = strdup(yytext); return MC_STRICT_INF;}
">="    {columnNumber+=yyleng; yylval.str = strdup(yytext); return MC_SUP_EQUAL;}
"<="      {columnNumber+=yyleng; yylval.str = strdup(yytext); return MC_INF_EQUAL; }


"("      { columnNumber+=yyleng; return L_PAREN;}
")"      { columnNumber+=yyleng; return R_PAREN; }
"{"      {columnNumber+=yyleng;  return L_BRACE;}
"}"      { columnNumber+=yyleng; return R_BRACE;}

";"      { columnNumber+=yyleng; return MC_SEMI;}
","      { columnNumber+=yyleng; return MC_COMMA;}
":="     {columnNumber+=yyleng;  return MC_AFFECT;}
":"     { columnNumber+=yyleng; return MC_DP;}
"."     { columnNumber+=yyleng; return MC_DOT;}

{INTEGER_CONST} {
      columnNumber+=yyleng;
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
      columnNumber+=yyleng;
      yylval.real = atof(yytext); 
      return REAL_CONST; 
      }

{STRING_CONST} {
      columnNumber+=yyleng;
       yylval.str = strdup(yytext);
      return STRING_CONST; 
      }
{CHAR_CONST} {
      columnNumber+=yyleng;
       yylval.myChar = strdup(yytext)[0];
      return CHAR_CONST; 
      }

{IDF} {
      columnNumber+=yyleng;
      if(strlen(yytext)<20){
            yylval.str = strdup(yytext); 
            inserer(yytext,"IDF", hachage(yytext));
            return MC_IDF; 
      }else{
            printf("line: %d idf trop long: %s \n",lineNumber,yytext);
      }
}

[ \t] columnNumber+=yyleng;
[ \t\r\f]+ columnNumber+=yyleng;/* eat up whitespace */
\n {lineNumber++; columnNumber=0;}
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