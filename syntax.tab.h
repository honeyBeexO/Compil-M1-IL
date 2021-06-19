/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MC_CODE = 258,
     MC_IDF = 259,
     MC_START = 260,
     MC_END = 261,
     MC_DOT = 262,
     MC_SEMI = 263,
     MC_COMMA = 264,
     MC_DP = 265,
     MC_AFFECT = 266,
     MC_INTEGER = 267,
     MC_REAL = 268,
     MC_STRING = 269,
     MC_CHAR = 270,
     MC_CONST = 271,
     L_PAREN = 272,
     R_PAREN = 273,
     L_BRACE = 274,
     R_BRACE = 275,
     MC_ADD = 276,
     MC_SUB = 277,
     MC_MUL = 278,
     MC_DIV = 279,
     MC_STRICT_SUP = 280,
     MC_STRICT_INF = 281,
     MC_SUP_EQUAL = 282,
     MC_INF_EQUAL = 283,
     MC_NOT_EQUAL = 284,
     MC_EQUAL = 285,
     MC_EQUAL_S = 286,
     INTEGER_CONST = 287,
     REAL_CONST = 288,
     STRING_CONST = 289,
     CHAR_CONST = 290,
     MC_WHILE = 291,
     MC_WHEN = 292,
     MC_PROD = 293,
     MC_EXECUTE = 294,
     MC_DO = 295,
     MC_OTHERWISE = 296
   };
#endif
/* Tokens.  */
#define MC_CODE 258
#define MC_IDF 259
#define MC_START 260
#define MC_END 261
#define MC_DOT 262
#define MC_SEMI 263
#define MC_COMMA 264
#define MC_DP 265
#define MC_AFFECT 266
#define MC_INTEGER 267
#define MC_REAL 268
#define MC_STRING 269
#define MC_CHAR 270
#define MC_CONST 271
#define L_PAREN 272
#define R_PAREN 273
#define L_BRACE 274
#define R_BRACE 275
#define MC_ADD 276
#define MC_SUB 277
#define MC_MUL 278
#define MC_DIV 279
#define MC_STRICT_SUP 280
#define MC_STRICT_INF 281
#define MC_SUP_EQUAL 282
#define MC_INF_EQUAL 283
#define MC_NOT_EQUAL 284
#define MC_EQUAL 285
#define MC_EQUAL_S 286
#define INTEGER_CONST 287
#define REAL_CONST 288
#define STRING_CONST 289
#define CHAR_CONST 290
#define MC_WHILE 291
#define MC_WHEN 292
#define MC_PROD 293
#define MC_EXECUTE 294
#define MC_DO 295
#define MC_OTHERWISE 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 105 "syntax.y"
{
        int integer;
        float real;
        char *str;
        char myChar;
}
/* Line 1529 of yacc.c.  */
#line 138 "syntax.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

