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




/* Copy the first part of user declarations.  */
#line 1 "synt.y"


      #include "symbtab.c"
      #include "quadMat.c"
      #include "pile.c"

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
/*-------------- pour operer sur les bibleotheque -----------------------*/
      int BIB_ARITHM_count = 0;
      int BIB_TAB_count = 0;
      int BIB_InOut_count = 0;
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
#line 73 "synt.y"
{
        int entier;
        float reel;
        char *str;
}
/* Line 193 of yacc.c.  */
#line 270 "synt.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 283 "synt.tab.c"

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
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    13,    16,    19,    22,    23,    24,    30,
      31,    38,    47,    49,    53,    55,    57,    59,    62,    65,
      68,    69,    72,    75,    78,    81,    84,    85,    89,    90,
      94,    95,   104,   108,   112,   114,   118,   122,   124,   126,
     128,   132,   134,   136,   138,   143,   145,   147,   149,   151,
     153,   155,   159,   160,   161,   162,   163,   167,   170,   174,
     176,   179,   184,   187,   190,   196,   198,   202,   208,   210,
     212,   216,   220,   221
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,     3,     4,    59,     6,    51,     5,     7,
      60,     8,    -1,    52,    51,    -1,    54,    51,    -1,    56,
      51,    -1,    -1,    -1,    58,    11,    53,    57,     9,    -1,
      -1,    18,    55,    58,    11,    57,     9,    -1,    17,    11,
      58,     4,    25,    39,    24,     9,    -1,     4,    -1,    57,
      10,     4,    -1,    15,    -1,    14,    -1,    16,    -1,    19,
      59,    -1,    20,    59,    -1,    21,    59,    -1,    -1,    61,
      60,    -1,    71,    60,    -1,    75,    60,    -1,    79,    60,
      -1,    81,    60,    -1,    -1,    62,    65,     9,    -1,    -1,
       4,    63,    12,    -1,    -1,     4,    64,    25,    39,    24,
      12,    65,     9,    -1,    65,    28,    66,    -1,    65,    29,
      66,    -1,    66,    -1,    66,    30,    67,    -1,    66,    31,
      67,    -1,    67,    -1,     4,    -1,    68,    -1,    22,    65,
      23,    -1,    39,    -1,    40,    -1,    41,    -1,     4,    25,
      39,    24,    -1,    35,    -1,    36,    -1,    33,    -1,    34,
      -1,    38,    -1,    37,    -1,    65,    69,    65,    -1,    -1,
      -1,    -1,    -1,    72,    70,    23,    -1,    73,    22,    -1,
      74,    60,    43,    -1,    42,    -1,    76,    46,    -1,    77,
      23,    45,    60,    -1,    78,    70,    -1,    44,    22,    -1,
      47,    22,    80,    23,     9,    -1,    41,    -1,    41,    10,
      80,    -1,    48,    22,    82,    23,     9,    -1,     4,    -1,
      56,    -1,     4,    10,    82,    -1,    56,    10,    82,    -1,
      -1,     4,    25,    39,    24,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   111,   112,   113,   114,   117,   117,   120,
     120,   123,   140,   152,   165,   166,   167,   170,   174,   178,
     182,   186,   187,   188,   189,   190,   191,   200,   225,   225,
     234,   234,   253,   296,   332,   335,   375,   415,   417,   433,
     435,   446,   460,   473,   486,   530,   531,   532,   533,   534,
     535,   539,   574,   574,   574,   574,   578,   599,   611,   618,
     627,   642,   657,   662,   667,   674,   675,   678,   685,   690,
     691,   697,   698,   700
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MC_LANG", "MC_IDF", "MC_FINDEC",
  "MC_VAR", "MC_DEBUT", "MC_FIN", "MC_SEMI", "MC_COMMA", "MC_DP",
  "MC_AFFECT", "MC_DECLARE", "MC_INT", "MC_FLOAT", "MC_STRING", "MC_TAB",
  "MC_CONST", "MC_BIB_TAB", "MC_BIB_ARITHM", "MC_BIB_INOUT", "L_PAREN",
  "R_PAREN", "L_BRACK", "R_BRACK", "L_BRACE", "R_BRACE", "MC_ADD",
  "MC_SUB", "MC_MUL", "MC_DIV", "MC_MOD", "MC_STRICT_SUP", "MC_STRICT_INF",
  "MC_SUP_EQUAL", "MC_INF_EQUAL", "MC_NOT_EQUAL", "MC_EQUAL", "INT_CONST",
  "FLOAT_CONST", "STRING_CONST", "MC_EXECUTE", "MC_IF", "MC_WHILE",
  "MC_FAIRE", "MC_FAIT", "MC_INPUT", "MC_OUTPUT", "$accept", "S",
  "Declaration", "Variable", "@1", "Constante", "@2", "Tableaux",
  "list_idf", "Type", "BIB", "Instruction", "Affectation", "BBB", "@3",
  "@4", "Expression", "T", "F", "Value", "OP_COND", "Condition", "IF", "B",
  "C", "D", "While", "AA", "BB", "CC", "Input", "ValidInput", "Output",
  "valid_output", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    51,    53,    52,    55,
      54,    56,    57,    57,    58,    58,    58,    59,    59,    59,
      59,    60,    60,    60,    60,    60,    60,    61,    63,    62,
      64,    62,    65,    65,    65,    66,    66,    66,    67,    67,
      67,    68,    68,    68,    68,    69,    69,    69,    69,    69,
      69,    70,    70,    70,    70,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    80,    81,    82,    82,
      82,    82,    82,    56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     2,     2,     2,     0,     0,     5,     0,
       6,     8,     1,     3,     1,     1,     1,     2,     2,     2,
       0,     2,     2,     2,     2,     2,     0,     3,     0,     3,
       0,     8,     3,     3,     1,     3,     3,     1,     1,     1,
       3,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     3,     0,     0,     0,     0,     3,     2,     3,     1,
       2,     4,     2,     2,     5,     1,     3,     5,     1,     1,
       3,     3,     0,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    20,     1,    20,    20,    20,     0,    17,
      18,    19,     6,     0,    15,    14,    16,     0,     9,     0,
       6,     6,     6,     0,     0,     0,     0,     0,     3,     4,
       5,     7,     0,     0,     0,    26,     0,    73,     0,     0,
      28,    59,     0,     0,     0,     0,    26,     0,    26,    52,
       0,    26,    26,     0,     0,    52,    26,    26,    12,     0,
       0,     0,     0,     0,    63,     0,    72,     2,    21,    38,
       0,    41,    42,    43,     0,    34,    37,    39,    22,     0,
       0,    57,     0,    23,    60,     0,    62,    24,    25,     8,
       0,     0,    10,    29,     0,    65,     0,    68,    69,     0,
       0,     0,    27,     0,     0,     0,     0,    47,    48,    45,
      46,    50,    49,     0,    56,    58,    26,    13,     0,     0,
       0,     0,    72,    72,     0,     0,    40,    32,    33,    35,
      36,    51,    61,    11,     0,    66,    64,    70,    71,    67,
      44,     0,     0,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    19,    20,    36,    21,    26,    22,    59,    23,
       8,    45,    46,    47,    62,    63,    79,    75,    76,    77,
     113,    80,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    96,    57,    99
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -65
static const yytype_int8 yypact[] =
{
      14,    37,    31,     1,   -65,     1,     1,     1,    64,   -65,
     -65,   -65,    22,    18,   -65,   -65,   -65,    69,   -65,    52,
      22,    22,    22,    74,    47,    19,    19,    80,   -65,   -65,
     -65,   -65,    65,    84,    79,     0,    87,   -65,    67,    87,
      68,   -65,    73,    75,    76,    88,     0,    10,     0,    10,
      77,     0,     0,    54,    78,    10,     0,     0,   -65,    36,
      66,    63,    90,    81,   -65,    70,    12,   -65,   -65,    82,
      10,   -65,   -65,   -65,    -4,   -21,   -65,   -65,   -65,    27,
      85,   -65,    60,   -65,   -65,    59,   -65,   -65,   -65,   -65,
     105,    86,   -65,   -65,    83,   102,    91,     5,   103,    92,
      89,   -10,   -65,    10,    10,    10,    10,   -65,   -65,   -65,
     -65,   -65,   -65,    10,   -65,   -65,     0,   -65,   107,    93,
      70,   109,    12,    12,   110,    96,   -65,   -21,   -21,   -65,
     -65,    46,   -65,   -65,   111,   -65,   -65,   -65,   -65,   -65,
     -65,    10,    -1,   -65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,    32,   -65,   -65,   -65,   -65,   -64,    94,    51,
      62,   -45,   -65,   -65,   -65,   -65,   -47,   -25,   -24,   -65,
     -65,    71,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,     4,   -65,   -39
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -31
static const yytype_int16 yytable[] =
{
      74,    68,    98,    78,    40,   102,    82,    83,   143,   105,
     106,    87,    88,   126,    69,   122,    97,     1,   103,   104,
       5,     6,     7,   101,   103,   104,    13,   103,   104,    17,
      24,     4,    70,    14,    15,    16,    14,    15,    16,    17,
      18,     3,    41,    24,    42,    89,    90,    43,    44,    71,
      72,    73,    28,    29,    30,   103,   104,    27,    98,    98,
     107,   108,   109,   110,   111,   112,   131,     9,    10,    11,
      12,   132,    92,    90,   103,   104,    33,    34,   127,   128,
      25,   129,   130,   137,   138,    31,    32,    35,    38,    37,
      39,    58,    60,   -30,   142,    64,    67,    65,    66,    81,
      84,    85,    93,   115,   116,    91,    94,   100,   114,   117,
     118,    95,   120,   123,   121,   124,   133,   134,   136,   139,
     140,     0,   119,   141,   135,     0,    86,     0,   125,     0,
       0,     0,     0,    61
};

static const yytype_int16 yycheck[] =
{
      47,    46,    66,    48,     4,     9,    51,    52,     9,    30,
      31,    56,    57,    23,     4,    10,     4,     3,    28,    29,
      19,    20,    21,    70,    28,    29,     4,    28,    29,    17,
      25,     0,    22,    14,    15,    16,    14,    15,    16,    17,
      18,     4,    42,    25,    44,     9,    10,    47,    48,    39,
      40,    41,    20,    21,    22,    28,    29,     5,   122,   123,
      33,    34,    35,    36,    37,    38,   113,     5,     6,     7,
       6,   116,     9,    10,    28,    29,    25,    26,   103,   104,
      11,   105,   106,   122,   123,    11,    39,     7,     4,    24,
      11,     4,    25,    25,   141,    22,     8,    22,    22,    22,
      46,    23,    12,    43,    45,    39,    25,    25,    23,     4,
      24,    41,    10,    10,    23,    23,     9,    24,     9,     9,
      24,    -1,    39,    12,   120,    -1,    55,    -1,    39,    -1,
      -1,    -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    50,     4,     0,    19,    20,    21,    59,    59,
      59,    59,     6,     4,    14,    15,    16,    17,    18,    51,
      52,    54,    56,    58,    25,    11,    55,     5,    51,    51,
      51,    11,    39,    58,    58,     7,    53,    24,     4,    11,
       4,    42,    44,    47,    48,    60,    61,    62,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    81,     4,    57,
      25,    57,    63,    64,    22,    22,    22,     8,    60,     4,
      22,    39,    40,    41,    65,    66,    67,    68,    60,    65,
      70,    22,    60,    60,    46,    23,    70,    60,    60,     9,
      10,    39,     9,    12,    25,    41,    80,     4,    56,    82,
      25,    65,     9,    28,    29,    30,    31,    33,    34,    35,
      36,    37,    38,    69,    23,    43,    45,     4,    24,    39,
      10,    23,    10,    10,    23,    39,    23,    66,    66,    67,
      67,    65,    60,     9,    24,    80,     9,    82,    82,     9,
      24,    12,    65,     9
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
#line 105 "synt.y"
    {
      printf("\nProgramme correct:D\n");
      YYACCEPT;
      ;}
    break;

  case 7:
#line 117 "synt.y"
    {strcpy(isConst,"non");;}
    break;

  case 9:
#line 120 "synt.y"
    {strcpy(isConst,"oui");;}
    break;

  case 11:
#line 123 "synt.y"
    {
            //verifier la taille du tableau
            if((yyvsp[(6) - (8)].entier) <= 0 ){
                  erro_parentheseSemantic(linenum,"taille du tableau\n");
            }else{
                  if(BIB_TAB_count != 1){
                        missingLibrary(linenum,"BIB_TAB");
                  }else{
                        insererType((yyvsp[(4) - (8)].str),type);
                        setSize((yyvsp[(4) - (8)].str),(yyvsp[(6) - (8)].entier));
                        compatibilite = getType((yyvsp[(4) - (8)].str));
                   }
            }
              ;}
    break;

  case 12:
#line 140 "synt.y"
    {

      if(DoubleDeclaration((yyvsp[(1) - (1)].str)) == 1){

        insererType((yyvsp[(1) - (1)].str),type);
        setConstant((yyvsp[(1) - (1)].str),isConst);

      }else{
          printf("IDF [%s] at line [%d] not declared\n",(yyvsp[(1) - (1)].str),linenum);

      }
;}
    break;

  case 13:
#line 152 "synt.y"
    {
                  //check for double declaration
                  if(DoubleDeclaration((yyvsp[(3) - (3)].str)) == 1) {

                      insererType((yyvsp[(3) - (3)].str),type);
                      setConstant((yyvsp[(3) - (3)].str),isConst);

                  }else{
                        printf("IDF [%s] at line [%d] not declared\n",(yyvsp[(3) - (3)].str),linenum);
                  }
            ;}
    break;

  case 14:
#line 165 "synt.y"
    { type = 1; ;}
    break;

  case 15:
#line 166 "synt.y"
    { type = 0; ;}
    break;

  case 16:
#line 167 "synt.y"
    { type = 2; ;}
    break;

  case 17:
#line 170 "synt.y"
    { 
      BIB_TAB_count ++; 
      if(BIB_TAB_count>1) printf("Warning : %s declaree plusiers fois \n",(yyvsp[(1) - (2)].str));
;}
    break;

  case 18:
#line 174 "synt.y"
    {
             BIB_ARITHM_count ++; 
            if(BIB_TAB_count>1) printf("Warning : %s declaree plusiers fois \n",(yyvsp[(1) - (2)].str));
            ;}
    break;

  case 19:
#line 178 "synt.y"
    { 
         BIB_InOut_count ++; if(BIB_TAB_count>1) 
         printf("Warning : %s declaree plusiers fois \n",(yyvsp[(1) - (2)].str));
         ;}
    break;

  case 21:
#line 186 "synt.y"
    {;}
    break;

  case 22:
#line 187 "synt.y"
    {;}
    break;

  case 23:
#line 188 "synt.y"
    {;}
    break;

  case 24:
#line 189 "synt.y"
    {;}
    break;

  case 25:
#line 190 "synt.y"
    {;}
    break;

  case 27:
#line 200 "synt.y"
    {

      /*--------- l'affectation est de type PartieGauche := PartieDroite 
      * la partie gauche je peux l'obtenir a partire de la pile elle sera en 
      * sommet de la pile elle peut etre : IDF | Constant | temporaire
      * et la partie droite je vais l'avoir a partir ma grammair de mon IDF
      */
                                                                                 // |   |
     pDroiteAffect = depiler(&p);   //----- c'est la partie droite de l'affectation |___|

      cp = depiler(&compatible);
      compatibilitePdroite = atoi(cp); //--- c'est le type de resultat de la partie droite de l'expression
      
if(affect_compatibl(compatibilitePgauche,compatibilitePdroite) == 0){ 
      printf("[line:%d]\tIncompatibilite ICI \t[%s] de type [%d]\t[%s] de type [%d]\n",linenum,pGaucheAffect,compatibilitePgauche,pDroiteAffect,compatibilitePdroite);
}

      insererQUADR(":=",pGaucheAffect,"",pDroiteAffect);
      initializerVar(&pDroiteAffect,&pGaucheAffect);

      compatibilite = -1;
      cp = "";
      strcpy(ToString,"");
;}
    break;

  case 28:
#line 225 "synt.y"
    {compatibilite = getType((yyvsp[(1) - (1)].str));;}
    break;

  case 29:
#line 225 "synt.y"
    {

        if(NotDeclared((yyvsp[(1) - (3)].str)) == 0) 
            printf("[%s] IDF NON DECLARE\t line : [%d] \n",(yyvsp[(1) - (3)].str),linenum);

        compatibilitePgauche = compatibilite;//getType($1);
        pGaucheAffect = (yyvsp[(1) - (3)].str);

;}
    break;

  case 30:
#line 234 "synt.y"
    {compatibilite = getType((yyvsp[(1) - (1)].str));;}
    break;

  case 31:
#line 234 "synt.y"
    {
      /*---- ici vaut mieux d'aller a la declaration de 
        *tableau ou bien vers constantes ,
       * mais je laisse ici pour tester
      ----- */
                  if(NotDeclared((yyvsp[(1) - (8)].str))){ 
                        printf("[%s] IDF NON DECLARE\t line : [%d] \n",(yyvsp[(1) - (8)].str),linenum);
                  }
                  if(indexOutOfBounds((yyvsp[(1) - (8)].str),(yyvsp[(4) - (8)].entier)) == 1){
                        printf("IdexOutOfBounds line [%d]\tIDF: [%s]",(yyvsp[(4) - (8)].entier),(yyvsp[(1) - (8)].str));
                  }
                  
                  compatibilitePgauche = compatibilite;//getType($1);
                  pGaucheAffect = (yyvsp[(1) - (8)].str);

;}
    break;

  case 32:
#line 253 "synt.y"
    {     

      operator = ' '; 

      if(BIB_ARITHM_count == 0)
            printf("#Arithm must be declared\t  [%d]\n",linenum);

     if(taillePile(&p)>=2){

         while(taillePile(&p) >= 2){

            temporaryName = createName("t",i);
            i++;

            cp = depiler(&compatible);
            typeOP2 = atoi(cp);

            cp = depiler(&compatible);
            typeOP1 = atoi(cp);
     
            op2 = depiler(&p);
            op1 = depiler(&p);
            


            insererQUADR((yyvsp[(2) - (3)].str),op1,op2,temporaryName);
      
            initializerVar(&op1,&op2);
            initializeEntier(&typeOP1,&typeOP2);

            if(affect_compatibl(typeOP1,typeOP2) == 1){
                  compatibilite = typeOP1;
                  sprintf(ToString,"%d",compatibilite);}

          }  
            empiler(&p,temporaryName);
            empiler(&compatible,ToString);
}
             strcpy(ToString,"");
             compatibilite = -1;
             cp ="";
      //le else : on sera dans le cas d'une affectation donc pas besoin d'empiler tous est deja dans la pile
;}
    break;

  case 33:
#line 296 "synt.y"
    {

  operator = ' '; 

  if(BIB_ARITHM_count == 0)
            printf("#Arithm must be declared\t  [%d]\n",linenum);

  if(taillePile(&p)>=2){
       while(taillePile(&p) >= 2){

            temporaryName = createName("t",i);
            i++;

            cp = depiler(&compatible);
            typeOP2 = atoi(cp);

            cp = depiler(&compatible);
            typeOP1 = atoi(cp);

            op2 = depiler(&p);
            op1 = depiler(&p);

            insererQUADR((yyvsp[(2) - (3)].str),op1,op2,temporaryName);

             if(affect_compatibl(typeOP1,typeOP2) == 1){
                  compatibilite = typeOP1;
                  sprintf(ToString,"%d",compatibilite);}
       }
            empiler(&p,temporaryName);
        
            empiler(&compatible,ToString);
}
            strcpy(ToString,"");
             compatibilite = -1;
             cp ="";
      /*le else on sera dans le cas d'une affectation donc pas besoin d'empiler*/;}
    break;

  case 35:
#line 335 "synt.y"
    {
      operator = ' ';

      if(BIB_ARITHM_count == 0)
            printf("#Arithm must be declared\t  [%d]\n",linenum);

    if(taillePile(&p)>=2){
      
      while(taillePile(&p) >= 2){

            temporaryName = createName("t",i);
            i++;
            
            cp = depiler(&compatible);
            typeOP2 = atoi(cp);

            cp = depiler(&compatible);
            typeOP1 = atoi(cp);

            op2 = depiler(&p);
            op1 = depiler(&p);

            insererQUADR((yyvsp[(2) - (3)].str),op1,op2,temporaryName);
            initializerVar(&op1,&op2);

             if(affect_compatibl(typeOP1,typeOP2) == 1){
                  compatibilite = typeOP1;
                  sprintf(ToString,"%d",compatibilite);}
     }
      empiler(&p,temporaryName);
      empiler(&compatible,ToString);/* j'empile cp car si op1 est compatible avec op2 donc j'empile le resltas*/
}/*else tous est deja dans la pile : 
      empiler(&p,ToString);
      empiler(&compatible,ToString);
      */
      strcpy(ToString,"");
      compatibilite = -1;
      cp ="";

;}
    break;

  case 36:
#line 375 "synt.y"
    { 
      operator = '/'; 
if(taillePile(&p)>=2){

       while(taillePile(&p) >= 2){
            temporaryName = createName("t",i);
            i++;

            cp = depiler(&compatible);
            typeOP2 = atoi(cp);
            
            cp = depiler(&compatible);
            typeOP1 = atoi(cp); /*---- convertire le type de int vers string -----*/

            op2 = depiler(&p);
            op1 = depiler(&p);

      //if divisonParZero aussi
      if(divByZero(operator ,fv)) 
            printf("DivByZero\t[%s] \tsure [%s] \n",op1,op2);

      if(BIB_ARITHM_count == 0)
            printf("#Arithm must be declared\t  [%d]\n",linenum);

            insererQUADR((yyvsp[(2) - (3)].str),op1,op2,temporaryName);
            //initializerVar(&op1,&op2);

            if(affect_compatibl(typeOP1,typeOP2) == 1){
                  compatibilite = typeOP1;
                  sprintf(ToString,"%d",compatibilite);
                  }
     }
            empiler(&p,temporaryName);
            empiler(&compatible,ToString);
}
                        /*---- on initialize apres utilisation ------*/
            compatibilite = -1;
            cp ="";
            operator = ' ';
                  ;}
    break;

  case 38:
#line 417 "synt.y"
    {

      if(NotDeclared((yyvsp[(1) - (1)].str)) == 1){//make it equal to 1 later babe OK 
              printf("IDF [%s] at line [%d] not declared\n",(yyvsp[(1) - (1)].str),linenum);
      }
      //on empile le type de cette idf 
      compatibilite = getType((yyvsp[(1) - (1)].str)); 
      /*----- le type de cette idf est dans i -------*/
      sprintf(ToString,"%d",compatibilite);


      empiler(&compatible,ToString);
      empiler(&p,(yyvsp[(1) - (1)].str));

      //sprintf(ToString,"%d",compatibilite);
;}
    break;

  case 39:
#line 433 "synt.y"
    {/* dans la garmmaire de valeur ====> */
;}
    break;

  case 40:
#line 435 "synt.y"
    {;}
    break;

  case 41:
#line 446 "synt.y"
    {  

      type_const = 0;

      fv = (yyvsp[(1) - (1)].entier);

      sprintf(ToString,"%d",type_const);
      empiler(&compatible,ToString);
      
      sprintf(ToString,"%d",(yyvsp[(1) - (1)].entier));
      empiler(&p,ToString);

      strcpy(ToString,"");
;}
    break;

  case 42:
#line 460 "synt.y"
    {    
           type_const = 1;

      fv = (yyvsp[(1) - (1)].reel);

      sprintf(ToString,"%d",type_const);
      empiler(&compatible,ToString);
      
      sprintf(ToString,"%f",(yyvsp[(1) - (1)].reel));
      empiler(&p,ToString);

      strcpy(ToString,"");
;}
    break;

  case 43:
#line 473 "synt.y"
    { 

      type_const = 2;   

      sprintf(ToString,"%d",type_const);
      empiler(&compatible,ToString);


      strcpy(ToString,(yyvsp[(1) - (1)].str));
      empiler(&p,(yyvsp[(1) - (1)].str));

      strcpy(ToString,"");
;}
    break;

  case 44:
#line 486 "synt.y"
    {
      /*---- verifier type , bib , et indexOutOfBounds , nonDeclaration
       *
       *compatibilitePdroite = getType($1);
       */

      if((NotDeclared((yyvsp[(1) - (4)].str)) == 1 )){
             printf("tableau IDF [%s] at line [%d] not declared\n",(yyvsp[(1) - (4)].str),linenum);
       }
      //verifier compatibilite de l'affectation ET bibleo
      if(BIB_TAB_count == 0){
            missingLibrary(linenum,"library '#TAB' must be decalred\n");
            }

      if(indexOutOfBounds((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].entier)) == 1){
            printf("IndexOutOfBounds [%s]\t indexValue [%d]\t\n",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].entier));
      }
            compatibilite = getType((yyvsp[(1) - (4)].str));
            sprintf(ToString,"%d",compatibilite);

            empiler(&compatible,ToString);


            empiler(&p,(yyvsp[(1) - (4)].str));

            compatibilite = -1;
            strcpy(ToString,"");

/*-------- si le idf n'est pa declarer ca va donner une erreur de segmentation 
 * donc je dois faire un Else
 */
;}
    break;

  case 45:
#line 530 "synt.y"
    {  strcpy(OP_CON,(yyvsp[(1) - (1)].str));      ;}
    break;

  case 46:
#line 531 "synt.y"
    {  strcpy(OP_CON,(yyvsp[(1) - (1)].str));      ;}
    break;

  case 47:
#line 532 "synt.y"
    {  strcpy(OP_CON,(yyvsp[(1) - (1)].str));      ;}
    break;

  case 48:
#line 533 "synt.y"
    {  strcpy(OP_CON,(yyvsp[(1) - (1)].str));      ;}
    break;

  case 49:
#line 534 "synt.y"
    {  strcpy(OP_CON,(yyvsp[(1) - (1)].str));      ;}
    break;

  case 50:
#line 535 "synt.y"
    {  strcpy(OP_CON,(yyvsp[(1) - (1)].str));      ;}
    break;

  case 51:
#line 539 "synt.y"
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
;}
    break;

  case 56:
#line 578 "synt.y"
    {//R3
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
    
;}
    break;

  case 57:
#line 599 "synt.y"
    {//R2
      
      /*
       *      ensuite il faut mettre a jour le BR de la routine 1 : < C insereQuad> des       
       *          <INstructions>
      */
     DebCondIf = qc;
     sprintf(ToString,"%d",DebCondIf);
     ajour_quad(DebInstIF,1,ToString);

;}
    break;

  case 58:
#line 611 "synt.y"
    {//R1
      
     /*----- pour executer les instructions qu'une seule fois ----*/
     FinInstIF = qc;
     insererQUADR("BR","","","");

;}
    break;

  case 59:
#line 618 "synt.y"
    {//R1
      /*----- aller a l'evaluation de la condition -----*/
      DebInstIF = qc;
      insererQUADR("BR","","","");
;}
    break;

  case 60:
#line 627 "synt.y"
    {

       sprintf(ToString,"%d",DebCondWhile);
       insererQUADR("BR",ToString,"","");

      FinInstWhile = qc;
      sprintf(ToString,"%d",FinInstWhile);

      ajour_quad(DebCondWhile,1,ToString);
      //ajour_quad(DebCondWhile,0,comparateurReverse(OP_CON));

      quadCondNum = -1;
      strcpy(OP_CON,"");
;}
    break;

  case 61:
#line 642 "synt.y"
    {

      //insertion de quad qui fait le branchement sur la condition de while debut de la condition
     

      /*
      mise a jour de quad qui contient la valeur de TemCond pour qu'il fait le jump dans le cas de condition non verifier
      */
      FinInstWhile = qc;
      sprintf(ToString,"%d",FinInstWhile);
      //ajour_quad(quadCondNum,1,ToString);
      //quadCondNum = -1;
;}
    break;

  case 62:
#line 657 "synt.y"
    {
        FinCondWhile = qc;
;}
    break;

  case 63:
#line 662 "synt.y"
    {
      DebCondWhile = qc;
;}
    break;

  case 64:
#line 667 "synt.y"
    {
      if(BIB_InOut_count ==0 ){
            missingLibrary(linenum,"#InOut must be declared\n");
      }
;}
    break;

  case 67:
#line 678 "synt.y"
    {
      if(BIB_InOut_count ==0 ){
            missingLibrary(linenum,"#InOut must be declared\n");
      }
;}
    break;

  case 68:
#line 685 "synt.y"
    { 
      if((NotDeclared((yyvsp[(1) - (1)].str)) == 1 )){
            erro_parentheseSemantic(linenum,"NOT DECLARED_IDF\n");
      }
;}
    break;

  case 70:
#line 691 "synt.y"
    {
                  if((NotDeclared((yyvsp[(1) - (3)].str)) == 1 )){
                  erro_parentheseSemantic(linenum,"NOT DECLARED_IDF\n");
                
            }
;}
    break;

  case 73:
#line 700 "synt.y"
    {
                  //verifier compatibilite de l'affectation ET bibleo
         if((indexOutOfBounds((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].entier)) == 1)||(BIB_TAB_count== 0)||(NotDeclared((yyvsp[(1) - (4)].str)) == 1 )){
           erro_parentheseSemantic(linenum,"INPUT erro_parenthese\n");

                  }
;}
    break;


/* Line 1267 of yacc.c.  */
#line 2312 "synt.tab.c"
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


#line 709 "synt.y"

 int main(int argc,char **argv){


      init();           //elle initialise ma table de ymbole
      initialize();     //elle initialiser ma matrice quad

      yyparse();

      afficherTS();
      printQuad(quadMatrix);

}
yywrap(){
}
