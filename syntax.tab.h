/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    MC_CODE = 258,                 /* MC_CODE  */
    MC_IDF = 259,                  /* MC_IDF  */
    MC_START = 260,                /* MC_START  */
    MC_END = 261,                  /* MC_END  */
    MC_DOT = 262,                  /* MC_DOT  */
    MC_SEMI = 263,                 /* MC_SEMI  */
    MC_COMMA = 264,                /* MC_COMMA  */
    MC_DP = 265,                   /* MC_DP  */
    MC_AFFECT = 266,               /* MC_AFFECT  */
    MC_INTEGER = 267,              /* MC_INTEGER  */
    MC_REAL = 268,                 /* MC_REAL  */
    MC_STRING = 269,               /* MC_STRING  */
    MC_CHAR = 270,                 /* MC_CHAR  */
    MC_CONST = 271,                /* MC_CONST  */
    L_PAREN = 272,                 /* L_PAREN  */
    R_PAREN = 273,                 /* R_PAREN  */
    L_BRACE = 274,                 /* L_BRACE  */
    R_BRACE = 275,                 /* R_BRACE  */
    MC_ADD = 276,                  /* MC_ADD  */
    MC_SUB = 277,                  /* MC_SUB  */
    MC_MUL = 278,                  /* MC_MUL  */
    MC_DIV = 279,                  /* MC_DIV  */
    MC_STRICT_SUP = 280,           /* MC_STRICT_SUP  */
    MC_STRICT_INF = 281,           /* MC_STRICT_INF  */
    MC_SUP_EQUAL = 282,            /* MC_SUP_EQUAL  */
    MC_INF_EQUAL = 283,            /* MC_INF_EQUAL  */
    MC_NOT_EQUAL = 284,            /* MC_NOT_EQUAL  */
    MC_EQUAL = 285,                /* MC_EQUAL  */
    INTEGER_CONST = 286,           /* INTEGER_CONST  */
    REAL_CONST = 287,              /* REAL_CONST  */
    STRING_CONST = 288,            /* STRING_CONST  */
    CHAR_CONST = 289,              /* CHAR_CONST  */
    MC_IF = 290,                   /* MC_IF  */
    MC_WHILE = 291,                /* MC_WHILE  */
    MC_WHEN = 292,                 /* MC_WHEN  */
    MC_PROD = 293,                 /* MC_PROD  */
    MC_EXECUTE = 294,              /* MC_EXECUTE  */
    MC_DO = 295,                   /* MC_DO  */
    MC_OTHERWISE = 296             /* MC_OTHERWISE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "syntax.y"

        int integer;
        float real;
        char *str;
        char myChar;

#line 112 "syntax.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
