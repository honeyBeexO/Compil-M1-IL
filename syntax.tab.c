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
    int quadNumber = 0;
    int temp = 0;
    char *op1="",*op2="";
    int isFisrtTime = 0;
    char typeDroite[10];
    char typeGauche[10];
    int quadAffectNum = 0;
    int i = 0;
    
    void printStack(Pile *p);
    void push(Pile *p, char x[]);
    char *pop(Pile *p);
    void toPostfix(Pile *_expression, Pile *_result);
    char *generateTemporaryName(int number);
    int compatibilityTest(Pile *_pile);

    Pile _compatible = NULL;
    

#line 113 "syntax.tab.c"

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
  YYSYMBOL_Constante = 46,                 /* Constante  */
  YYSYMBOL_list_idf = 47,                  /* list_idf  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_Type = 49,                      /* Type  */
  YYSYMBOL_Instruction = 50,               /* Instruction  */
  YYSYMBOL_Affectation = 51,               /* Affectation  */
  YYSYMBOL_BBB = 52,                       /* BBB  */
  YYSYMBOL_Expression = 53,                /* Expression  */
  YYSYMBOL_54_2 = 54,                      /* $@2  */
  YYSYMBOL_55_3 = 55,                      /* $@3  */
  YYSYMBOL_T = 56,                         /* T  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_58_5 = 58,                      /* $@5  */
  YYSYMBOL_F = 59,                         /* F  */
  YYSYMBOL_Value = 60,                     /* Value  */
  YYSYMBOL_OP_COND = 61,                   /* OP_COND  */
  YYSYMBOL_Condition = 62,                 /* Condition  */
  YYSYMBOL_When = 63,                      /* When  */
  YYSYMBOL_64_6 = 64,                      /* $@6  */
  YYSYMBOL_X2 = 65,                        /* X2  */
  YYSYMBOL_IF = 66,                        /* IF  */
  YYSYMBOL_B = 67,                         /* B  */
  YYSYMBOL_C = 68,                         /* C  */
  YYSYMBOL_D = 69,                         /* D  */
  YYSYMBOL_While = 70,                     /* While  */
  YYSYMBOL_AA = 71,                        /* AA  */
  YYSYMBOL_BB = 72,                        /* BB  */
  YYSYMBOL_CC = 73                         /* CC  */
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
#define YYLAST   103

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

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
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    77,    78,    79,    82,    85,    96,   105,
     105,   116,   117,   118,   119,   124,   125,   126,   127,   128,
     129,   133,   172,   191,   191,   196,   196,   197,   199,   199,
     200,   200,   201,   203,   227,   228,   233,   243,   255,   263,
     273,   274,   275,   276,   277,   278,   282,   294,   294,   299,
     300,   301,   304,   305,   308,   309,   314,   316,   319,   322
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
  "S", "Declaration", "Variable", "Constante", "list_idf", "$@1", "Type",
  "Instruction", "Affectation", "BBB", "Expression", "$@2", "$@3", "T",
  "$@4", "$@5", "F", "Value", "OP_COND", "Condition", "When", "$@6", "X2",
  "IF", "B", "C", "D", "While", "AA", "BB", "CC", YY_NULLPTR
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

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      15,    16,    24,    46,   -41,   -41,   -41,   -41,   -41,    25,
      34,    46,    46,    38,    57,     4,   -41,   -41,    62,    64,
      44,    68,    13,   -41,   -41,   -41,   -41,    56,    65,   -41,
      75,     4,    13,     1,    -8,   -41,   -41,     4,     4,    13,
      66,     4,     4,    67,    70,    13,   -41,   -41,    76,   -41,
     -41,    45,   -41,    13,    78,   -41,     6,     4,   -41,   -41,
     -41,   -41,   -41,   -41,    27,    71,   -41,    51,   -41,    82,
      52,   -41,    38,   -41,   -41,   -41,   -41,   -41,   -41,    13,
      13,    13,    13,   -41,   -41,   -41,   -41,   -41,   -41,    13,
     -41,   -41,   -41,    73,   -41,    77,    -8,    -8,   -41,   -41,
     -18,     4,    53,   -41,    79,     4,    74,    -7,   -41,    80,
     -41,     4,    81,    88,   -41
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     5,     1,    11,    12,    13,    14,     0,
       0,     5,     5,     0,     0,    20,     3,     4,     8,     0,
       0,    33,     0,    36,    37,    38,    39,     0,     0,    55,
       0,    20,     0,     0,    27,    32,    34,    20,    20,     0,
       0,    20,    20,     0,     0,     0,     9,     6,     0,    22,
      33,     0,    59,     0,     0,    15,     0,    20,    23,    25,
      28,    30,    16,    17,     0,     0,    53,     0,    18,     0,
       0,    58,     0,     7,    35,    47,     2,    21,    19,     0,
       0,     0,     0,    42,    43,    40,    41,    45,    44,     0,
      52,    54,    56,     0,    10,     0,    24,    26,    29,    31,
      46,    20,     0,    57,     0,    20,     0,    51,    50,     0,
      48,    20,     0,     0,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,    20,   -41,   -41,    28,   -41,   -41,   -31,   -41,
     -41,   -20,   -41,   -41,   -29,   -41,   -41,   -17,    83,   -41,
     -40,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    10,    11,    12,    19,    72,    13,    30,    31,
      32,    33,    79,    80,    34,    81,    82,    35,    36,    89,
      65,    37,    95,   110,    38,    39,    40,    41,    42,    43,
      44,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      55,   108,    51,    58,    59,    71,    62,    63,    21,    57,
      67,    68,    56,    75,    77,    60,    61,    50,     1,    64,
       3,    22,    58,    59,     4,    64,    78,    58,    59,    14,
      22,    16,    17,    64,   109,    23,    24,    25,    26,    15,
      27,    28,    18,    29,    23,    24,    25,    26,    58,    59,
      96,    97,    83,    84,    85,    86,    87,    88,     5,     6,
       7,     8,     9,    74,    98,    99,    58,    59,    20,   100,
     103,    46,    47,    52,   106,    23,    24,    25,    26,    49,
     112,    54,    53,    66,    73,    76,    91,    69,    70,    90,
      92,    93,   101,   104,   107,   102,   114,     0,   105,   111,
      94,   113,     0,    48
};

static const yytype_int8 yycheck[] =
{
      31,     8,    22,    21,    22,    45,    37,    38,     4,     8,
      41,    42,    32,    53,     8,    23,    24,     4,     3,    39,
       4,    17,    21,    22,     0,    45,    57,    21,    22,     4,
      17,    11,    12,    53,    41,    31,    32,    33,    34,     5,
      36,    37,     4,    39,    31,    32,    33,    34,    21,    22,
      79,    80,    25,    26,    27,    28,    29,    30,    12,    13,
      14,    15,    16,    18,    81,    82,    21,    22,    11,    89,
     101,     9,     8,    17,   105,    31,    32,    33,    34,    11,
     111,     6,    17,    17,     8,     7,    35,    20,    18,    18,
       8,    39,    19,    40,    20,    18,     8,    -1,    19,    19,
      72,    20,    -1,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    43,     4,     0,    12,    13,    14,    15,    16,
      44,    45,    46,    49,     4,     5,    44,    44,     4,    47,
      11,     4,    17,    31,    32,    33,    34,    36,    37,    39,
      50,    51,    52,    53,    56,    59,    60,    63,    66,    67,
      68,    69,    70,    71,    72,    73,     9,     8,    60,    11,
       4,    53,    17,    17,     6,    50,    53,     8,    21,    22,
      23,    24,    50,    50,    53,    62,    17,    50,    50,    20,
      18,    62,    48,     8,    18,    62,     7,     8,    50,    54,
      55,    57,    58,    25,    26,    27,    28,    29,    30,    61,
      18,    35,     8,    39,    47,    64,    56,    56,    59,    59,
      53,    19,    18,    50,    40,    19,    50,    20,     8,    41,
      65,    19,    50,    20,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    45,    46,    47,    48,
      47,    49,    49,    49,    49,    50,    50,    50,    50,    50,
      50,    51,    52,    54,    53,    55,    53,    53,    57,    56,
      58,    56,    56,    59,    59,    59,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    62,    64,    63,    65,
      65,    65,    66,    67,    68,    69,    70,    71,    72,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     2,     2,     0,     3,     5,     1,     0,
       4,     1,     1,     1,     1,     2,     2,     2,     2,     3,
       0,     3,     2,     0,     4,     0,     4,     1,     0,     4,
       0,     4,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     0,    10,     5,
       1,     0,     3,     2,     3,     1,     3,     5,     2,     2
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
#line 71 "syntax.y"
                                                               {
      printf("\n --- Votre Programme a compilé correct --- \n");
      YYACCEPT;
      }
#line 1261 "syntax.tab.c"
    break;

  case 7: /* Constante: MC_CONST MC_IDF MC_AFFECT Value MC_SEMI  */
#line 85 "syntax.y"
                                                 {
     if(doubleDeclaration((yyvsp[-3].str)) == 0){
        inserIdfDecl((yyvsp[-3].str));
        insererType((yyvsp[-3].str),"Constante","Const",1);
    }else{
        printf("ERROR: Double declaration DE CONSTANTE %s\n",(yyvsp[-3].str));
    }
}
#line 1274 "syntax.tab.c"
    break;

  case 8: /* list_idf: MC_IDF  */
#line 96 "syntax.y"
                 {
    if(doubleDeclaration((yyvsp[0].str)) == 0){
        inserIdfDecl((yyvsp[0].str));
        /* empiler($1); */
        insererType((yyvsp[0].str),sauvType,"Variable",1);
    }else{
        printf("ERROR: Double declaration\n");
    }
}
#line 1288 "syntax.tab.c"
    break;

  case 9: /* $@1: %empty  */
#line 105 "syntax.y"
                           {
    if(doubleDeclaration((yyvsp[-1].str)) == 0){
        inserIdfDecl((yyvsp[-1].str));
        /* empiler($1); */
        insererType((yyvsp[-1].str),sauvType,"Variable",1);
    }else{
        printf("ERROR: Double declaration\n");
    }
}
#line 1302 "syntax.tab.c"
    break;

  case 10: /* list_idf: MC_IDF MC_COMMA $@1 list_idf  */
#line 113 "syntax.y"
           {}
#line 1308 "syntax.tab.c"
    break;

  case 11: /* Type: MC_INTEGER  */
#line 116 "syntax.y"
                        {strcpy(sauvType,"INTEGER");}
#line 1314 "syntax.tab.c"
    break;

  case 12: /* Type: MC_REAL  */
#line 117 "syntax.y"
                        {strcpy(sauvType,"REAL");}
#line 1320 "syntax.tab.c"
    break;

  case 13: /* Type: MC_STRING  */
#line 118 "syntax.y"
                        {strcpy(sauvType,"STRING");}
#line 1326 "syntax.tab.c"
    break;

  case 14: /* Type: MC_CHAR  */
#line 119 "syntax.y"
                        {strcpy(sauvType,"CHAR");}
#line 1332 "syntax.tab.c"
    break;

  case 15: /* Instruction: Affectation Instruction  */
#line 124 "syntax.y"
                                      {}
#line 1338 "syntax.tab.c"
    break;

  case 16: /* Instruction: When Instruction  */
#line 125 "syntax.y"
                                             {}
#line 1344 "syntax.tab.c"
    break;

  case 17: /* Instruction: IF Instruction  */
#line 126 "syntax.y"
                                             {}
#line 1350 "syntax.tab.c"
    break;

  case 18: /* Instruction: While Instruction  */
#line 127 "syntax.y"
                                             {}
#line 1356 "syntax.tab.c"
    break;

  case 19: /* Instruction: Expression MC_SEMI Instruction  */
#line 128 "syntax.y"
                                             {}
#line 1362 "syntax.tab.c"
    break;

  case 21: /* Affectation: BBB Expression MC_SEMI  */
#line 133 "syntax.y"
                                   {
    //Evaluer la compatibilite de l'expression
    printStack(&_compatible);
    if(!compatibilityTest(&_compatible)){
        printf("ERROR DE COMPATIBILITÉ LIGNE -> %d:%d\n",lineNumber,columnNumber);
    }
    //Evaluer les quad de la pille
    toPostfix(&_pile,&_postFixed);

    Pile evaluer = NULL;
    Pile temp = _postFixed;

    int size = getSize(&_postFixed);
    char *T[size];
    
    char *x="";
    char *temporaryName="";
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
            temporaryName = generateTemporaryName(i); // generate temporaire name
            push(&evaluer,temporaryName);
            insertQuadreplet(x,op1,op2,temporaryName);
            i++;
        } 
    }
    /* Mettre a jour le quadreplet de resultats final de l'expression*/
    updateQuadreplet(quadAffectNum,1,temporaryName);
    printStack(&evaluer);
}
#line 1405 "syntax.tab.c"
    break;

  case 22: /* BBB: MC_IDF MC_AFFECT  */
#line 172 "syntax.y"
                     {
    _pile=NULL;
    _postFixed=NULL;
    _compatible=NULL;

    char *type = getType((yyvsp[-1].str));
    push(&_compatible,type);

    if(routinIdfDeclar((yyvsp[-1].str)) == 0){
        printf("\n ERREUR IDF %s NON DECLAREE ! \n",(yyvsp[-1].str)); 
    }else{
       printf("type de %s est %s\n",(yyvsp[-1].str), getType((yyvsp[-1].str)));
       quadAffectNum = qc; //le num de quad courant
       insertQuadreplet(":=","","",(yyvsp[-1].str));
       strcpy(typeGauche,type);
    }
}
#line 1427 "syntax.tab.c"
    break;

  case 23: /* $@2: %empty  */
#line 191 "syntax.y"
                              {push(&_pile,"+");}
#line 1433 "syntax.tab.c"
    break;

  case 24: /* Expression: Expression MC_ADD $@2 T  */
#line 191 "syntax.y"
                                                   {
    isFisrtTime=0;
    //insertQuadreplet("+",op1,op2,"t1");
    /* updateQuadreplet(quadAffectNum,1,"t1"); */
}
#line 1443 "syntax.tab.c"
    break;

  case 25: /* $@3: %empty  */
#line 196 "syntax.y"
                              {{push(&_pile,"-");}}
#line 1449 "syntax.tab.c"
    break;

  case 28: /* $@4: %empty  */
#line 199 "syntax.y"
           {push(&_pile,"*");}
#line 1455 "syntax.tab.c"
    break;

  case 30: /* $@5: %empty  */
#line 200 "syntax.y"
           {push(&_pile,"/");}
#line 1461 "syntax.tab.c"
    break;

  case 31: /* T: T MC_DIV $@5 F  */
#line 200 "syntax.y"
                                {}
#line 1467 "syntax.tab.c"
    break;

  case 33: /* F: MC_IDF  */
#line 203 "syntax.y"
         {
    char *type = getType((yyvsp[0].str));
    push(&_compatible,type);
     if(routinIdfDeclar((yyvsp[0].str)) == 0) 
        {        
            printf("\n ERREUR IDF %s NON DECLAREE ! \n \n",(yyvsp[0].str)); 
        }else{
            char *str = strdup((yyvsp[0].str));
            push(&_pile,str);
    }
    /*
    char *type = getType($1);
    printf("Type %s - %s\n",$1,type); 
    if(isFisrtTime == 0){
         strcpy(typeDroite,type);
         strcpy(op1,strdup($1));
         isFisrtTime=1;
     }else{
         if(strcmp(typeDroite,type) == 0){
             printf("Type incompatible\n");
         }
         strcpy(op2,$1);
     } */
    }
#line 1496 "syntax.tab.c"
    break;

  case 35: /* F: L_PAREN Expression R_PAREN  */
#line 228 "syntax.y"
                              {}
#line 1502 "syntax.tab.c"
    break;

  case 36: /* Value: INTEGER_CONST  */
#line 233 "syntax.y"
                    {
    char *s; 
    asprintf(&s, "%i", (yyvsp[0].integer));
    push(&_pile,s);
    push(&_compatible,"INTEGER");
    if(quadNumber != 0){
        //updateQuadreplet(quadNumber,1,s);
    }
    free(s);
}
#line 1517 "syntax.tab.c"
    break;

  case 37: /* Value: REAL_CONST  */
#line 243 "syntax.y"
            {
    char *s; 
    asprintf(&s, "%f", (yyvsp[0].real));
    push(&_pile,s);
    push(&_compatible,"REAL");

    if(quadNumber != 0){
        //updateQuadreplet(quadNumber,1,s);
    }
    free(s);

}
#line 1534 "syntax.tab.c"
    break;

  case 38: /* Value: STRING_CONST  */
#line 255 "syntax.y"
              {
    char *s; 
    asprintf(&s, "%s", (yyvsp[0].str)); 
    push(&_pile,s);
    push(&_compatible,"STRING");

    free(s);
    }
#line 1547 "syntax.tab.c"
    break;

  case 39: /* Value: CHAR_CONST  */
#line 263 "syntax.y"
            {
    char *s; 
    asprintf(&s, "%c", (yyvsp[0].myChar)); 
    push(&_pile,s);
    push(&_compatible,"CHAR");
    free(s);
    }
#line 1559 "syntax.tab.c"
    break;

  case 46: /* Condition: Expression OP_COND Expression  */
#line 282 "syntax.y"
                                       {
    printf("pile de l'expression: \n");
    printStack(&_pile);
    toPostfix(&_pile,&_postFixed);
    printf("pile de l'expression postifxee: \n");
    printStack(&_postFixed);
}
#line 1571 "syntax.tab.c"
    break;

  case 47: /* $@6: %empty  */
#line 294 "syntax.y"
                                {
    insertQuadreplet("BZ","","","");
    printf("qc= %i - quadNumber= %i \n",qc,quadNumber);
}
#line 1580 "syntax.tab.c"
    break;

  case 52: /* IF: B Condition R_PAREN  */
#line 304 "syntax.y"
                      {}
#line 1586 "syntax.tab.c"
    break;

  case 53: /* B: C L_PAREN  */
#line 305 "syntax.y"
            {}
#line 1592 "syntax.tab.c"
    break;

  case 54: /* C: D Instruction MC_IF  */
#line 308 "syntax.y"
                       {}
#line 1598 "syntax.tab.c"
    break;

  case 55: /* D: MC_EXECUTE  */
#line 309 "syntax.y"
             {/*aller a l'evaluation de la condition       // insererQUADR("BR","","","");*/}
#line 1604 "syntax.tab.c"
    break;

  case 56: /* While: AA R_BRACE MC_SEMI  */
#line 314 "syntax.y"
                         {}
#line 1610 "syntax.tab.c"
    break;

  case 57: /* AA: BB R_PAREN MC_EXECUTE L_BRACE Instruction  */
#line 316 "syntax.y"
                                             {}
#line 1616 "syntax.tab.c"
    break;

  case 58: /* BB: CC Condition  */
#line 319 "syntax.y"
                {}
#line 1622 "syntax.tab.c"
    break;

  case 59: /* CC: MC_WHILE L_PAREN  */
#line 322 "syntax.y"
                    {}
#line 1628 "syntax.tab.c"
    break;


#line 1632 "syntax.tab.c"

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

#line 325 "syntax.y"



void yyerror(char *s) {
   fprintf(stderr, "%s\n", s);
}
 int main(int argc,char **argv){
     initialize();
     yyin = fopen( "programme.txt", "r" );
    if (yyin==NULL) 
            printf("ERROR  \n");
     else{ 
            yyparse();
            afficher();
            afficherDecl();
            printQuadreplet();
     }
      return 0;
}
