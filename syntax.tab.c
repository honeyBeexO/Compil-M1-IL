/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "syntax.y"

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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 105 "syntax.y"
{
        int integer;
        float real;
        char *str;
        char myChar;
}
/* Line 193 of yacc.c.  */
#line 289 "syntax.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 302 "syntax.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    11,    14,    17,    18,    22,    29,    31,
      32,    37,    39,    41,    43,    45,    46,    52,    54,    55,
      60,    63,    66,    69,    73,    74,    78,    81,    82,    87,
      88,    93,    95,    97,    98,   103,   104,   109,   111,   113,
     115,   119,   121,   123,   125,   127,   129,   131,   133,   135,
     137,   139,   143,   144,   145,   146,   147,   161,   167,   169,
     170,   174,   180,   183,   184
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,     3,     4,    44,     5,    54,     6,     7,
      -1,    45,    44,    -1,    46,    44,    -1,    -1,    49,    47,
       8,    -1,    16,    49,     4,    31,    64,     8,    -1,     4,
      -1,    -1,     4,     9,    48,    47,    -1,    12,    -1,    13,
      -1,    14,    -1,    15,    -1,    -1,    38,    51,    17,    52,
      18,    -1,    57,    -1,    -1,    52,     9,    53,    57,    -1,
      55,    54,    -1,    67,    54,    -1,    73,    54,    -1,    57,
       8,    54,    -1,    -1,    56,    57,     8,    -1,     4,    11,
      -1,    -1,    57,    21,    58,    60,    -1,    -1,    57,    22,
      59,    60,    -1,    50,    -1,    60,    -1,    -1,    60,    23,
      61,    63,    -1,    -1,    60,    24,    62,    63,    -1,    63,
      -1,     4,    -1,    64,    -1,    17,    57,    18,    -1,    32,
      -1,    33,    -1,    34,    -1,    35,    -1,    27,    -1,    28,
      -1,    25,    -1,    26,    -1,    30,    -1,    29,    -1,    57,
      65,    57,    -1,    -1,    -1,    -1,    -1,    37,    68,    17,
      66,    69,    18,    70,    40,    19,    54,    71,    20,    72,
      -1,    41,    19,    54,    20,     8,    -1,     8,    -1,    -1,
      74,    20,     8,    -1,    75,    18,    39,    19,    54,    -1,
      76,    66,    -1,    -1,    36,    77,    17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   143,   144,   145,   148,   151,   163,   173,
     173,   185,   186,   187,   188,   191,   191,   192,   193,   193,
     195,   196,   197,   198,   199,   203,   205,   225,   225,   226,
     226,   227,   228,   230,   230,   231,   231,   232,   234,   245,
     246,   251,   258,   266,   273,   283,   284,   285,   286,   287,
     288,   292,   303,   303,   308,   309,   303,   319,   326,   333,
     338,   346,   357,   365,   365
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MC_CODE", "MC_IDF", "MC_START",
  "MC_END", "MC_DOT", "MC_SEMI", "MC_COMMA", "MC_DP", "MC_AFFECT",
  "MC_INTEGER", "MC_REAL", "MC_STRING", "MC_CHAR", "MC_CONST", "L_PAREN",
  "R_PAREN", "L_BRACE", "R_BRACE", "MC_ADD", "MC_SUB", "MC_MUL", "MC_DIV",
  "MC_STRICT_SUP", "MC_STRICT_INF", "MC_SUP_EQUAL", "MC_INF_EQUAL",
  "MC_NOT_EQUAL", "MC_EQUAL", "MC_EQUAL_S", "INTEGER_CONST", "REAL_CONST",
  "STRING_CONST", "CHAR_CONST", "MC_WHILE", "MC_WHEN", "MC_PROD",
  "MC_EXECUTE", "MC_DO", "MC_OTHERWISE", "$accept", "S", "Declaration",
  "Variable", "Constante", "list_idf", "@1", "Type", "Prod", "@2",
  "list_expression", "@3", "Instruction", "Affectation", "BBB",
  "Expression", "@4", "@5", "T", "@6", "@7", "F", "Value", "OP_COND",
  "Condition", "When", "@8", "@9", "@10", "@11", "X2", "While", "AA", "BB",
  "CC", "@12", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    45,    46,    47,    48,
      47,    49,    49,    49,    49,    51,    50,    52,    53,    52,
      54,    54,    54,    54,    54,    55,    56,    58,    57,    59,
      57,    57,    57,    61,    60,    62,    60,    60,    63,    63,
      63,    64,    64,    64,    64,    65,    65,    65,    65,    65,
      65,    66,    68,    69,    70,    71,    67,    72,    72,    72,
      73,    74,    75,    77,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     2,     2,     0,     3,     6,     1,     0,
       4,     1,     1,     1,     1,     0,     5,     1,     0,     4,
       2,     2,     2,     3,     0,     3,     2,     0,     4,     0,
       4,     1,     1,     0,     4,     0,     4,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     0,     0,     0,    13,     5,     1,     0,
       3,     5,     2,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     1,    11,    12,    13,    14,     0,
       0,     5,     5,     0,     0,    24,     3,     4,     8,     0,
       0,    38,     0,    41,    42,    43,    44,    63,    52,    15,
      31,     0,    24,     0,     0,    32,    37,    39,    24,    24,
       0,     0,     0,     9,     6,     0,    26,    38,     0,     0,
       0,     0,     0,    20,     0,    24,    27,    29,    33,    35,
      21,    22,     0,     0,     0,    62,     0,     0,    40,    64,
       0,     0,     2,    25,    23,     0,     0,     0,     0,    60,
       0,    47,    48,    45,    46,    50,    49,     0,    10,     7,
      53,     0,    17,    28,    30,    34,    36,    24,    51,     0,
      18,    16,    61,    54,     0,     0,    19,     0,    24,    55,
       0,    59,    58,     0,    56,    24,     0,     0,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    10,    11,    12,    19,    66,    13,    30,    51,
      91,   104,    31,    32,    33,    34,    75,    76,    35,    77,
      78,    36,    37,    87,    65,    38,    50,    99,   105,   110,
     114,    39,    40,    41,    42,    49
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -33
static const yytype_int8 yypact[] =
{
       9,    11,    26,    32,   -33,   -33,   -33,   -33,   -33,    47,
      49,    32,    32,    24,    37,    -3,   -33,   -33,    57,    64,
      44,    78,     4,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,    84,    -3,     4,    -5,   -19,   -33,   -33,    -3,    -3,
      71,    75,     4,   -33,   -33,    36,   -33,   -33,    31,    77,
      79,    80,    85,   -33,     3,    -3,   -33,   -33,   -33,   -33,
     -33,   -33,    87,    59,    52,   -33,    24,    91,   -33,   -33,
       4,     4,   -33,   -33,   -33,    23,    23,    23,    23,   -33,
      81,   -33,   -33,   -33,   -33,   -33,   -33,     4,   -33,   -33,
     -33,     0,    -2,   -19,   -19,   -33,   -33,    -3,    -2,    83,
     -33,   -33,   -33,   -33,     4,    62,    -2,    86,    -3,   -33,
      88,     2,   -33,    90,   -33,    -3,    92,    95,   -33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,    74,   -33,   -33,    38,   -33,    97,   -33,   -33,
     -33,   -33,   -32,   -33,   -33,   -20,   -33,   -33,   -12,   -33,
     -33,    10,    65,   -33,    41,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      53,    21,    48,    55,    58,    59,    60,    61,    47,   100,
     112,    73,     1,    54,    22,     3,    56,    57,   101,    56,
      57,    22,    64,    74,    56,    57,     4,    47,    18,    23,
      24,    25,    26,    27,    28,    29,    23,    24,    25,    26,
      22,    20,    29,   113,     5,     6,     7,     8,     9,    68,
      64,    92,    56,    57,    15,    23,    24,    25,    26,     5,
       6,     7,     8,    93,    94,   102,    43,    98,    23,    24,
      25,    26,    44,    56,    57,    45,   109,    81,    82,    83,
      84,    85,    86,   116,   106,    16,    17,    95,    96,    46,
      52,    62,    72,    63,    69,    79,    70,    71,    80,    89,
      97,   103,   107,   118,    88,   108,    14,     0,   111,   115,
      67,    90,   117
};

static const yytype_int8 yycheck[] =
{
      32,     4,    22,     8,    23,    24,    38,    39,     4,     9,
       8,     8,     3,    33,    17,     4,    21,    22,    18,    21,
      22,    17,    42,    55,    21,    22,     0,     4,     4,    32,
      33,    34,    35,    36,    37,    38,    32,    33,    34,    35,
      17,     4,    38,    41,    12,    13,    14,    15,    16,    18,
      70,    71,    21,    22,     5,    32,    33,    34,    35,    12,
      13,    14,    15,    75,    76,    97,     9,    87,    32,    33,
      34,    35,     8,    21,    22,    31,   108,    25,    26,    27,
      28,    29,    30,   115,   104,    11,    12,    77,    78,    11,
       6,    20,     7,    18,    17,     8,    17,    17,    39,     8,
      19,    18,    40,     8,    66,    19,     9,    -1,    20,    19,
      45,    70,    20
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,     4,     0,    12,    13,    14,    15,    16,
      44,    45,    46,    49,    49,     5,    44,    44,     4,    47,
       4,     4,    17,    32,    33,    34,    35,    36,    37,    38,
      50,    54,    55,    56,    57,    60,    63,    64,    67,    73,
      74,    75,    76,     9,     8,    31,    11,     4,    57,    77,
      68,    51,     6,    54,    57,     8,    21,    22,    23,    24,
      54,    54,    20,    18,    57,    66,    48,    64,    18,    17,
      17,    17,     7,     8,    54,    58,    59,    61,    62,     8,
      39,    25,    26,    27,    28,    29,    30,    65,    47,     8,
      66,    52,    57,    60,    60,    63,    63,    19,    57,    69,
       9,    18,    54,    18,    53,    70,    57,    40,    19,    54,
      71,    20,     8,    41,    72,    19,    54,    20,     8
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 133 "syntax.y"
    {
      if(hasCompilingErrors == 0){
          printf("\n --- Votre Programme a compilé avec %d error(s) --- \n",hasCompilingErrors);
      }else{
          printf("\n --- Votre Programme a compilé avec %d errors --- \n", hasCompilingErrors);
      }
      YYACCEPT;
      ;}
    break;

  case 7:
#line 151 "syntax.y"
    {
     if(doubleDeclaration((yyvsp[(3) - (6)].str)) == 0){
        inserIdfDecl((yyvsp[(3) - (6)].str));
        insererType((yyvsp[(3) - (6)].str),"Constante","CONST",1);
    }else{
        hasCompilingErrors++;
        printf("ERROR: Double declaration de CONSTANTE %s ligne: %d - %d\n",(yyvsp[(3) - (6)].str),lineNumber,columnNumber);
    }
;}
    break;

  case 8:
#line 163 "syntax.y"
    {
    if(doubleDeclaration((yyvsp[(1) - (1)].str)) == 0){
        inserIdfDecl((yyvsp[(1) - (1)].str));
        /* empiler($1); */
        insererType((yyvsp[(1) - (1)].str),sauvType,"Variable",1);
    }else{
        hasCompilingErrors++;
        printf("ERROR: Double declaration de %s ligne: %d - %d\n",(yyvsp[(1) - (1)].str),lineNumber,columnNumber);
    }
;}
    break;

  case 9:
#line 173 "syntax.y"
    {
    if(doubleDeclaration((yyvsp[(1) - (2)].str)) == 0){
        inserIdfDecl((yyvsp[(1) - (2)].str));
        /* empiler($1); */
        insererType((yyvsp[(1) - (2)].str),sauvType,"Variable",1);
    }else{
        hasCompilingErrors++;
        printf("ERROR: Double declaration de %s ligne: %d - %d\n",(yyvsp[(1) - (2)].str),lineNumber,columnNumber);
    }
;}
    break;

  case 10:
#line 182 "syntax.y"
    {;}
    break;

  case 11:
#line 185 "syntax.y"
    {strcpy(sauvType,"INTEGER");;}
    break;

  case 12:
#line 186 "syntax.y"
    {strcpy(sauvType,"REAL");;}
    break;

  case 13:
#line 187 "syntax.y"
    {strcpy(sauvType,"STRING");;}
    break;

  case 14:
#line 188 "syntax.y"
    {strcpy(sauvType,"CHAR");;}
    break;

  case 15:
#line 191 "syntax.y"
    {;}
    break;

  case 18:
#line 193 "syntax.y"
    {push(&_pile,"*");;}
    break;

  case 20:
#line 195 "syntax.y"
    {;}
    break;

  case 21:
#line 196 "syntax.y"
    {;}
    break;

  case 22:
#line 197 "syntax.y"
    {;}
    break;

  case 23:
#line 198 "syntax.y"
    {;}
    break;

  case 25:
#line 203 "syntax.y"
    {evaluateExpression();isAffectation = 0;;}
    break;

  case 26:
#line 205 "syntax.y"
    {
    _pile=NULL;
    _postFixed=NULL;
    _compatible=NULL;

    isAffectation = 1;

    char *type = getType((yyvsp[(1) - (2)].str));
    push(&_compatible,type);

    if(routinIdfDeclar((yyvsp[(1) - (2)].str)) == 0){
        hasCompilingErrors++;
        printf("\n ERREUR IDF %s NON DECLAREE -> %d:%d\n",(yyvsp[(1) - (2)].str),lineNumber,columnNumber); 
    }else{
       quadAffectNum = qc; //le num de quad courant
       insertQuadreplet(":=","","",(yyvsp[(1) - (2)].str));
    }
;}
    break;

  case 27:
#line 225 "syntax.y"
    {push(&_pile,"+");;}
    break;

  case 28:
#line 225 "syntax.y"
    {;}
    break;

  case 29:
#line 226 "syntax.y"
    {push(&_pile,"-");;}
    break;

  case 30:
#line 226 "syntax.y"
    {;}
    break;

  case 32:
#line 228 "syntax.y"
    {;}
    break;

  case 33:
#line 230 "syntax.y"
    {push(&_pile,"*");;}
    break;

  case 35:
#line 231 "syntax.y"
    {push(&_pile,"/");;}
    break;

  case 36:
#line 231 "syntax.y"
    {;}
    break;

  case 38:
#line 234 "syntax.y"
    {
    char *type = getType((yyvsp[(1) - (1)].str));
    push(&_compatible,type);
    if(routinIdfDeclar((yyvsp[(1) - (1)].str)) == 0){        
            hasCompilingErrors++;
            printf("\n ERREUR IDF %s NON DECLAREE -> %d:%d\n",(yyvsp[(1) - (1)].str),lineNumber,columnNumber); 
    }else{
            char *str = strdup((yyvsp[(1) - (1)].str));
            push(&_pile,str);
    }
;}
    break;

  case 41:
#line 251 "syntax.y"
    {
    char *s; 
    asprintf(&s, "%i", (yyvsp[(1) - (1)].integer));
    push(&_pile,s);
    push(&_compatible,"INTEGER");
    free(s);
;}
    break;

  case 42:
#line 258 "syntax.y"
    {
    char *s; 
    asprintf(&s, "%f", (yyvsp[(1) - (1)].real));
    push(&_pile,s);
    push(&_compatible,"REAL");
    free(s);

;}
    break;

  case 43:
#line 266 "syntax.y"
    {
    char *s; 
    asprintf(&s, "%s", (yyvsp[(1) - (1)].str)); 
    push(&_pile,s);
    push(&_compatible,"STRING");
    free(s);
    ;}
    break;

  case 44:
#line 273 "syntax.y"
    {
    char *s; 
    asprintf(&s, "%c", (yyvsp[(1) - (1)].myChar)); 
    push(&_pile,s);
    push(&_compatible,"CHAR");
    free(s);
    ;}
    break;

  case 45:
#line 283 "syntax.y"
    {push(&_pile,"G");;}
    break;

  case 46:
#line 284 "syntax.y"
    {push(&_pile,"L");;}
    break;

  case 47:
#line 285 "syntax.y"
    {push(&_pile,">");;}
    break;

  case 48:
#line 286 "syntax.y"
    {push(&_pile,"<");;}
    break;

  case 49:
#line 287 "syntax.y"
    {push(&_pile,"=");;}
    break;

  case 50:
#line 288 "syntax.y"
    {push(&_pile,"!");;}
    break;

  case 51:
#line 292 "syntax.y"
    {
    // Evaluer l'expression de la partie gauche 
    // Garder le tomporaire
    quadCondNum = qc;
    evaluateExpression();
;}
    break;

  case 52:
#line 303 "syntax.y"
    { _pile=NULL;_postFixed=NULL;_compatible=NULL; isAffectation=0; ;}
    break;

  case 53:
#line 303 "syntax.y"
    {
    //A
    sauvBZ = qc;
    quadAffectNum = qc; //le num de quad courant
    insertQuadreplet("BZ","","",temporaryName);
;}
    break;

  case 54:
#line 308 "syntax.y"
    {
;}
    break;

  case 55:
#line 309 "syntax.y"
    {
    //B
    sauvBR=qc;
    char *s; 
    asprintf(&s, "%i", qc+1); 
    insertQuadreplet("BR","","","");
    updateQuadreplet(sauvBZ,1,s);
    free(s);
;}
    break;

  case 57:
#line 319 "syntax.y"
    {
    //C
    char *s; 
    asprintf(&s, "%i", qc); 
    updateQuadreplet(sauvBR,1,s);
    free(s);
;}
    break;

  case 58:
#line 326 "syntax.y"
    {
    //C
    char *s; 
    asprintf(&s, "%i", qc); 
    updateQuadreplet(sauvBR,1,s);
    free(s);
;}
    break;

  case 60:
#line 338 "syntax.y"
    {
        //C
    char *s; 
    asprintf(&s, "%i", qc); 
    updateQuadreplet(sauvBR,1,s);
    free(s);
;}
    break;

  case 61:
#line 346 "syntax.y"
    {
        //B
    sauvBR=qc;
    char *s; 
    asprintf(&s, "%i", qc+1); 
    insertQuadreplet("BR","","","");
    updateQuadreplet(sauvBZ,1,s);
    free(s);
;}
    break;

  case 62:
#line 357 "syntax.y"
    {
        //A
    sauvBZ = qc;
    quadAffectNum = qc; //le num de quad courant
    insertQuadreplet("BZ","","",temporaryName);
;}
    break;

  case 63:
#line 365 "syntax.y"
    { _pile=NULL;_postFixed=NULL;_compatible=NULL; isAffectation=0; ;}
    break;

  case 64:
#line 365 "syntax.y"
    {;}
    break;


/* Line 1267 of yacc.c.  */
#line 1978 "syntax.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 368 "syntax.y"



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
            afficherDecl(); // table pour verifier les declarations
            printQuadreplet();
     }
      return 0;
}

