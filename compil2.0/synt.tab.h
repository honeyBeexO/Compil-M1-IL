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
     MC_LANG = 258,
     MC_IDF = 259,
     MC_FINDEC = 260,
     MC_VAR = 261,
     MC_DEBUT = 262,
     MC_FIN = 263,
     MC_SEMI = 264,
     MC_COMMA = 265,
     MC_DP = 266,
     MC_AFFECT = 267,
     MC_DECLARE = 268,
     MC_INT = 269,
     MC_FLOAT = 270,
     MC_STRING = 271,
     MC_TAB = 272,
     MC_CONST = 273,
     MC_BIB_TAB = 274,
     MC_BIB_ARITHM = 275,
     MC_BIB_INOUT = 276,
     L_PAREN = 277,
     R_PAREN = 278,
     L_BRACK = 279,
     R_BRACK = 280,
     L_BRACE = 281,
     R_BRACE = 282,
     MC_ADD = 283,
     MC_SUB = 284,
     MC_MUL = 285,
     MC_DIV = 286,
     MC_MOD = 287,
     MC_STRICT_SUP = 288,
     MC_STRICT_INF = 289,
     MC_SUP_EQUAL = 290,
     MC_INF_EQUAL = 291,
     MC_NOT_EQUAL = 292,
     MC_EQUAL = 293,
     INT_CONST = 294,
     FLOAT_CONST = 295,
     STRING_CONST = 296,
     MC_EXECUTE = 297,
     MC_IF = 298,
     MC_WHILE = 299,
     MC_FAIRE = 300,
     MC_FAIT = 301,
     MC_INPUT = 302,
     MC_OUTPUT = 303
   };
#endif
/* Tokens.  */
#define MC_LANG 258
#define MC_IDF 259
#define MC_FINDEC 260
#define MC_VAR 261
#define MC_DEBUT 262
#define MC_FIN 263
#define MC_SEMI 264
#define MC_COMMA 265
#define MC_DP 266
#define MC_AFFECT 267
#define MC_DECLARE 268
#define MC_INT 269
#define MC_FLOAT 270
#define MC_STRING 271
#define MC_TAB 272
#define MC_CONST 273
#define MC_BIB_TAB 274
#define MC_BIB_ARITHM 275
#define MC_BIB_INOUT 276
#define L_PAREN 277
#define R_PAREN 278
#define L_BRACK 279
#define R_BRACK 280
#define L_BRACE 281
#define R_BRACE 282
#define MC_ADD 283
#define MC_SUB 284
#define MC_MUL 285
#define MC_DIV 286
#define MC_MOD 287
#define MC_STRICT_SUP 288
#define MC_STRICT_INF 289
#define MC_SUP_EQUAL 290
#define MC_INF_EQUAL 291
#define MC_NOT_EQUAL 292
#define MC_EQUAL 293
#define INT_CONST 294
#define FLOAT_CONST 295
#define STRING_CONST 296
#define MC_EXECUTE 297
#define MC_IF 298
#define MC_WHILE 299
#define MC_FAIRE 300
#define MC_FAIT 301
#define MC_INPUT 302
#define MC_OUTPUT 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 73 "synt.y"
{
        int entier;
        float reel;
        char *str;
}
/* Line 1529 of yacc.c.  */
#line 151 "synt.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

