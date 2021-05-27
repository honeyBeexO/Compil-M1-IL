/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

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



#line 142 "syntax.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MC_CODE = 3,                    /* MC_CODE  */
  YYSYMBOL_MC_IDF = 4,                     /* MC_IDF  */
  YYSYMBOL_MC_START = 5,                   /* MC_START  */
  YYSYMBOL_MC_END = 6,                     /* MC_END  */
  YYSYMBOL_MC_DOT = 7,                     /* MC_DOT  */
  YYSYMBOL_MC_SEMI = 8,                    /* MC_SEMI  */
  YYSYMBOL_MC_COMMA = 9,                   /* MC_COMMA  */
  YYSYMBOL_MC_DP = 10,                     /* MC_DP  */
  YYSYMBOL_MC_AFFECT = 11,                 /* MC_AFFECT  */
  YYSYMBOL_MC_INTEGER = 12,                /* MC_INTEGER  */
  YYSYMBOL_MC_REAL = 13,                   /* MC_REAL  */
  YYSYMBOL_MC_STRING = 14,                 /* MC_STRING  */
  YYSYMBOL_MC_CHAR = 15,                   /* MC_CHAR  */
  YYSYMBOL_MC_CONST = 16,                  /* MC_CONST  */
  YYSYMBOL_L_PAREN = 17,                   /* L_PAREN  */
  YYSYMBOL_R_PAREN = 18,                   /* R_PAREN  */
  YYSYMBOL_L_BRACE = 19,                   /* L_BRACE  */
  YYSYMBOL_R_BRACE = 20,                   /* R_BRACE  */
  YYSYMBOL_MC_ADD = 21,                    /* MC_ADD  */
  YYSYMBOL_MC_SUB = 22,                    /* MC_SUB  */
  YYSYMBOL_MC_MUL = 23,                    /* MC_MUL  */
  YYSYMBOL_MC_DIV = 24,                    /* MC_DIV  */
  YYSYMBOL_MC_STRICT_SUP = 25,             /* MC_STRICT_SUP  */
  YYSYMBOL_MC_STRICT_INF = 26,             /* MC_STRICT_INF  */
  YYSYMBOL_MC_SUP_EQUAL = 27,              /* MC_SUP_EQUAL  */
  YYSYMBOL_MC_INF_EQUAL = 28,              /* MC_INF_EQUAL  */
  YYSYMBOL_MC_NOT_EQUAL = 29,              /* MC_NOT_EQUAL  */
  YYSYMBOL_MC_EQUAL = 30,                  /* MC_EQUAL  */
  YYSYMBOL_INTEGER_CONST = 31,             /* INTEGER_CONST  */
  YYSYMBOL_REAL_CONST = 32,                /* REAL_CONST  */
  YYSYMBOL_STRING_CONST = 33,              /* STRING_CONST  */
  YYSYMBOL_CHAR_CONST = 34,                /* CHAR_CONST  */
  YYSYMBOL_MC_IF = 35,                     /* MC_IF  */
  YYSYMBOL_MC_WHILE = 36,                  /* MC_WHILE  */
  YYSYMBOL_MC_WHEN = 37,                   /* MC_WHEN  */
  YYSYMBOL_MC_PROD = 38,                   /* MC_PROD  */
  YYSYMBOL_MC_EXECUTE = 39,                /* MC_EXECUTE  */
  YYSYMBOL_MC_DO = 40,                     /* MC_DO  */
  YYSYMBOL_MC_OTHERWISE = 41,              /* MC_OTHERWISE  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_S = 43,                         /* S  */
  YYSYMBOL_Declaration = 44,               /* Declaration  */
  YYSYMBOL_Variable = 45,                  /* Variable  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_Constante = 47,                 /* Constante  */
  YYSYMBOL_48_2 = 48,                      /* $@2  */
  YYSYMBOL_list_idf = 49,                  /* list_idf  */
  YYSYMBOL_Type = 50,                      /* Type  */
  YYSYMBOL_Instruction = 51,               /* Instruction  */
  YYSYMBOL_Affectation = 52,               /* Affectation  */
  YYSYMBOL_BBB = 53,                       /* BBB  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_Expression = 55,                /* Expression  */
  YYSYMBOL_T = 56,                         /* T  */
  YYSYMBOL_F = 57,                         /* F  */
  YYSYMBOL_Value = 58,                     /* Value  */
  YYSYMBOL_OP_COND = 59,                   /* OP_COND  */
  YYSYMBOL_Condition = 60,                 /* Condition  */
  YYSYMBOL_IF = 61,                        /* IF  */
  YYSYMBOL_B = 62,                         /* B  */
  YYSYMBOL_C = 63,                         /* C  */
  YYSYMBOL_D = 64,                         /* D  */
  YYSYMBOL_While = 65,                     /* While  */
  YYSYMBOL_AA = 66,                        /* AA  */
  YYSYMBOL_BB = 67,                        /* BB  */
  YYSYMBOL_CC = 68                         /* CC  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   86

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  94

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   100,   100,   106,   107,   108,   111,   111,   114,   114,
     120,   121,   124,   125,   126,   127,   132,   133,   134,   135,
     136,   140,   142,   142,   144,   145,   146,   149,   150,   151,
     154,   155,   156,   160,   161,   162,   163,   176,   177,   178,
     179,   180,   181,   185,   194,   196,   199,   200,   205,   207,
     210,   213
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MC_CODE", "MC_IDF",
  "MC_START", "MC_END", "MC_DOT", "MC_SEMI", "MC_COMMA", "MC_DP",
  "MC_AFFECT", "MC_INTEGER", "MC_REAL", "MC_STRING", "MC_CHAR", "MC_CONST",
  "L_PAREN", "R_PAREN", "L_BRACE", "R_BRACE", "MC_ADD", "MC_SUB", "MC_MUL",
  "MC_DIV", "MC_STRICT_SUP", "MC_STRICT_INF", "MC_SUP_EQUAL",
  "MC_INF_EQUAL", "MC_NOT_EQUAL", "MC_EQUAL", "INTEGER_CONST",
  "REAL_CONST", "STRING_CONST", "CHAR_CONST", "MC_IF", "MC_WHILE",
  "MC_WHEN", "MC_PROD", "MC_EXECUTE", "MC_DO", "MC_OTHERWISE", "$accept",
  "S", "Declaration", "Variable", "$@1", "Constante", "$@2", "list_idf",
  "Type", "Instruction", "Affectation", "BBB", "$@3", "Expression", "T",
  "F", "Value", "OP_COND", "Condition", "IF", "B", "C", "D", "While", "AA",
  "BB", "CC", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
#endif

#define YYPACT_NINF (-28)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-23)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       4,     9,    18,    39,   -28,   -28,   -28,   -28,   -28,   -28,
      17,    39,    39,   -28,    28,    -3,   -28,   -28,    57,    16,
      51,     6,   -28,   -28,   -28,   -28,    46,   -28,    64,    -3,
       6,    -5,   -19,   -28,   -28,    -3,     6,    54,    -3,    -3,
      52,    55,     6,    65,    67,    35,    66,   -28,    38,   -28,
      69,   -28,    -2,    -3,     6,     6,     6,     6,   -28,    20,
      60,   -28,    44,   -28,   -28,    41,   -28,    57,   -28,    73,
     -28,   -28,   -28,   -28,   -28,   -19,   -19,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,     6,   -28,   -28,    63,   -28,
     -28,     3,    -3,   -28
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     5,     1,    12,    13,    14,    15,     8,
       0,     5,     5,     6,     0,    20,     3,     4,     0,     0,
      30,     0,    33,    34,    35,    36,     0,    47,     0,    20,
       0,     0,    26,    29,    31,    20,     0,     0,    20,    20,
       0,     0,     0,    10,     0,     0,     0,    30,     0,    51,
       0,    16,     0,    20,     0,     0,     0,     0,    17,     0,
       0,    45,     0,    18,    48,     0,    50,     0,     7,     0,
      23,    32,     2,    21,    19,    24,    25,    27,    28,    39,
      40,    37,    38,    42,    41,     0,    44,    46,     0,    11,
       9,    43,    20,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,    23,   -28,   -28,   -28,   -28,    19,   -28,   -27,
     -28,   -28,   -28,   -21,   -11,     1,    40,   -28,    42,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    10,    11,    18,    12,    14,    44,    13,    28,
      29,    30,    46,    31,    32,    33,    34,    85,    60,    35,
      36,    37,    38,    39,    40,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      48,    20,    51,    53,    56,    57,    73,     1,    58,    52,
      47,    62,    63,     3,    21,    59,    54,    55,     4,    54,
      55,    59,    15,    21,    54,    55,    74,    45,    22,    23,
      24,    25,    19,    26,    16,    17,    27,    22,    23,    24,
      25,    54,    55,    75,    76,    79,    80,    81,    82,    83,
      84,     5,     6,     7,     8,     9,    71,    77,    78,    54,
      55,    43,   -22,    49,    91,    93,    22,    23,    24,    25,
      50,    61,    64,    65,    67,    68,    72,    70,    86,    87,
      88,    90,    92,     0,    66,    69,    89
};

static const yytype_int8 yycheck[] =
{
      21,     4,    29,     8,    23,    24,     8,     3,    35,    30,
       4,    38,    39,     4,    17,    36,    21,    22,     0,    21,
      22,    42,     5,    17,    21,    22,    53,    11,    31,    32,
      33,    34,     4,    36,    11,    12,    39,    31,    32,    33,
      34,    21,    22,    54,    55,    25,    26,    27,    28,    29,
      30,    12,    13,    14,    15,    16,    18,    56,    57,    21,
      22,     4,    11,    17,    85,    92,    31,    32,    33,    34,
       6,    17,    20,    18,     9,     8,     7,    11,    18,    35,
      39,     8,    19,    -1,    42,    45,    67
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    43,     4,     0,    12,    13,    14,    15,    16,
      44,    45,    47,    50,    48,     5,    44,    44,    46,     4,
       4,    17,    31,    32,    33,    34,    36,    39,    51,    52,
      53,    55,    56,    57,    58,    61,    62,    63,    64,    65,
      66,    67,    68,     4,    49,    11,    54,     4,    55,    17,
       6,    51,    55,     8,    21,    22,    23,    24,    51,    55,
      60,    17,    51,    51,    20,    18,    60,     9,     8,    58,
      11,    18,     7,     8,    51,    56,    56,    57,    57,    25,
      26,    27,    28,    29,    30,    59,    18,    35,    39,    49,
       8,    55,    19,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    46,    45,    48,    47,
      49,    49,    50,    50,    50,    50,    51,    51,    51,    51,
      51,    52,    54,    53,    55,    55,    55,    56,    56,    56,
      57,    57,    57,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     2,     2,     0,     0,     4,     0,     6,
       1,     3,     1,     1,     1,     1,     2,     2,     2,     3,
       0,     3,     0,     3,     3,     3,     1,     3,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     2,     3,     1,     2,     5,
       2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* S: MC_CODE MC_IDF Declaration MC_START Instruction MC_END MC_DOT  */
#line 100 "syntax.y"
                                                               {
      printf("\n --- Votre Programme a compilé correct --- \n");
      YYACCEPT;
      }
#line 1273 "syntax.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 111 "syntax.y"
              {strcpy(isConst,"non");}
#line 1279 "syntax.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 114 "syntax.y"
                   {strcpy(isConst,"oui");}
#line 1285 "syntax.tab.c"
    break;

  case 10: /* list_idf: MC_IDF  */
#line 120 "syntax.y"
                 {}
#line 1291 "syntax.tab.c"
    break;

  case 11: /* list_idf: MC_IDF MC_COMMA list_idf  */
#line 121 "syntax.y"
                                    {}
#line 1297 "syntax.tab.c"
    break;

  case 12: /* Type: MC_INTEGER  */
#line 124 "syntax.y"
                        { type = 0; }
#line 1303 "syntax.tab.c"
    break;

  case 13: /* Type: MC_REAL  */
#line 125 "syntax.y"
                        { type = 1; }
#line 1309 "syntax.tab.c"
    break;

  case 14: /* Type: MC_STRING  */
#line 126 "syntax.y"
                        { type = 2; }
#line 1315 "syntax.tab.c"
    break;

  case 15: /* Type: MC_CHAR  */
#line 127 "syntax.y"
                        { type = 3; }
#line 1321 "syntax.tab.c"
    break;

  case 16: /* Instruction: Affectation Instruction  */
#line 132 "syntax.y"
                                      {}
#line 1327 "syntax.tab.c"
    break;

  case 17: /* Instruction: IF Instruction  */
#line 133 "syntax.y"
                                                 {}
#line 1333 "syntax.tab.c"
    break;

  case 18: /* Instruction: While Instruction  */
#line 134 "syntax.y"
                                                 {}
#line 1339 "syntax.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 142 "syntax.y"
            {compatibilite = getType((yyvsp[0].str));}
#line 1345 "syntax.tab.c"
    break;

  case 24: /* Expression: Expression MC_ADD T  */
#line 144 "syntax.y"
                                {printf("expression\n");}
#line 1351 "syntax.tab.c"
    break;

  case 30: /* F: MC_IDF  */
#line 154 "syntax.y"
         { /* NotDeclared & compatibilite & DoubleDeclartion */}
#line 1357 "syntax.tab.c"
    break;

  case 31: /* F: Value  */
#line 155 "syntax.y"
         {/* dans la garmmaire de valeur ====> */}
#line 1363 "syntax.tab.c"
    break;

  case 32: /* F: L_PAREN Expression R_PAREN  */
#line 156 "syntax.y"
                              {}
#line 1369 "syntax.tab.c"
    break;

  case 37: /* OP_COND: MC_SUP_EQUAL  */
#line 176 "syntax.y"
                         {  strcpy(OP_CON,(yyvsp[0].str));      }
#line 1375 "syntax.tab.c"
    break;

  case 38: /* OP_COND: MC_INF_EQUAL  */
#line 177 "syntax.y"
                         {  strcpy(OP_CON,(yyvsp[0].str));      }
#line 1381 "syntax.tab.c"
    break;

  case 39: /* OP_COND: MC_STRICT_SUP  */
#line 178 "syntax.y"
                         {  strcpy(OP_CON,(yyvsp[0].str));      }
#line 1387 "syntax.tab.c"
    break;

  case 40: /* OP_COND: MC_STRICT_INF  */
#line 179 "syntax.y"
                         {  strcpy(OP_CON,(yyvsp[0].str));      }
#line 1393 "syntax.tab.c"
    break;

  case 41: /* OP_COND: MC_EQUAL  */
#line 180 "syntax.y"
                         {  strcpy(OP_CON,(yyvsp[0].str));      }
#line 1399 "syntax.tab.c"
    break;

  case 42: /* OP_COND: MC_NOT_EQUAL  */
#line 181 "syntax.y"
                         {  strcpy(OP_CON,(yyvsp[0].str));      }
#line 1405 "syntax.tab.c"
    break;

  case 43: /* Condition: Expression OP_COND Expression  */
#line 185 "syntax.y"
                                       {
    printf("condition: \n");
}
#line 1413 "syntax.tab.c"
    break;

  case 44: /* IF: B Condition R_PAREN  */
#line 194 "syntax.y"
                      {}
#line 1419 "syntax.tab.c"
    break;

  case 45: /* B: C L_PAREN  */
#line 196 "syntax.y"
            {}
#line 1425 "syntax.tab.c"
    break;

  case 46: /* C: D Instruction MC_IF  */
#line 199 "syntax.y"
                       {}
#line 1431 "syntax.tab.c"
    break;

  case 47: /* D: MC_EXECUTE  */
#line 200 "syntax.y"
             {/*aller a l'evaluation de la condition       // insererQUADR("BR","","","");*/}
#line 1437 "syntax.tab.c"
    break;

  case 48: /* While: AA R_BRACE  */
#line 205 "syntax.y"
                 {}
#line 1443 "syntax.tab.c"
    break;

  case 49: /* AA: BB R_PAREN MC_EXECUTE L_BRACE Instruction  */
#line 207 "syntax.y"
                                             {}
#line 1449 "syntax.tab.c"
    break;

  case 50: /* BB: CC Condition  */
#line 210 "syntax.y"
                {}
#line 1455 "syntax.tab.c"
    break;

  case 51: /* CC: MC_WHILE L_PAREN  */
#line 213 "syntax.y"
                    {}
#line 1461 "syntax.tab.c"
    break;


#line 1465 "syntax.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 216 "syntax.y"


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