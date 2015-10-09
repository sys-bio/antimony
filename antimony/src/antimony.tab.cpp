/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         antimony_yyparse
#define yylex           antimony_yylex
#define yyerror         antimony_yyerror
#define yydebug         antimony_yydebug
#define yynerrs         antimony_yynerrs

#define yylval          antimony_yylval
#define yychar          antimony_yychar

/* Copy the first part of user declarations.  */
#line 26 "antimony.ypp" /* yacc.c:339  */

  //#define YYSTYPE double
#include <cassert>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#ifndef NSBML
#include <sbml/SBMLTypes.h>
#endif
#include "registry.h"
#include "module.h"
#include "unitdef.h"
#include "stringx.h"

  class Formula;
  class ReactantList;
  class AntimonyReaction;
  class Variable;

  using namespace std;
  int antimony_yylex(void);
  void antimony_yyerror(char const *);
  Registry g_registry;
  int antimony_yylloc_first_line = 1;
  int antimony_yylloc_last_line = 1;
  vector<int> antimony_yylloc_last_lines;

#line 106 "antimony.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int antimony_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEOF = 0,
    NUM = 259,
    AFTER = 260,
    ANTWORD = 261,
    AT = 262,
    BECOMESIRREV = 263,
    COMPARTMENT = 264,
    CONSTANT = 265,
    CONSTRAINTWORD = 266,
    CONSTWORD = 267,
    DASHES = 268,
    DELETEWORD = 269,
    DNA = 270,
    ELLIPSES = 271,
    END = 272,
    ERROR = 273,
    EVENT = 274,
    FORMULA = 275,
    FUNCTION = 276,
    FUNCTIONWORD = 277,
    GENE = 278,
    HASWORD = 279,
    IMPORT = 280,
    INWORD = 281,
    IS = 282,
    MAXIMIZEWORD = 283,
    MINIMIZEWORD = 284,
    MODNAME = 285,
    MODULE = 286,
    OPERATOR = 287,
    REACTION = 288,
    SPECIES = 289,
    SUBSTONLY = 290,
    TEXTSTRING = 291,
    UNITWORD = 292,
    VARWORD = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 59 "antimony.ypp" /* yacc.c:355  */

  char character;
  const string* word;
  double num;
  rd_type reactionDivider;
  Formula* formula;
  Formula* spacedformula;
  Formula* commaformula;
  Module* module;
  ReactantList* reactantList;
  Variable* variable;
  Variable* variablein;
  Variable* varmaybeis;
  Variable* maybein;
  Variable* unitdef;
  bool maybemain;
  bool maxormin;
  constraint_type inequality;

#line 202 "antimony.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE antimony_yylval;

int antimony_yyparse (void);



/* Copy the second part of user declarations.  */

#line 219 "antimony.tab.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   835

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  204
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  367

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      61,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,     2,    51,    10,     4,    54,
      47,    48,     8,     7,    49,     6,    50,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    55,
      57,    52,    56,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    11,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     5,    60,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   137,   137,   138,   139,   140,   141,   142,   143,   146,
     149,   149,   155,   155,   161,   162,   165,   166,   169,   169,
     170,   171,   174,   175,   176,   186,   187,   188,   191,   192,
     198,   201,   204,   205,   208,   209,   210,   211,   212,   215,
     216,   219,   220,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   237,   245,   255,   256,   257,
     258,   259,   263,   264,   265,   266,   267,   268,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   293,   294,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   308,   309,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   324,   324,   325,   325,   329,
     330,   331,   332,   333,   337,   338,   342,   346,   347,   348,
     349,   350,   351,   353,   354,   357,   358,   359,   360,   361,
     362,   363,   364,   367,   368,   369,   370,   373,   374,   375,
     376,   379,   380,   381,   382,   385,   386,   387,   388,   391,
     392,   393,   394,   398,   399,   400,   401,   404,   405,   406,
     409,   412,   415,   416,   419,   420,   421,   422,   423,   426,
     427,   430,   430,   431,   431,   432,   432,   433,   433,   436,
     437,   440,   441,   448,   449,   450,   451,   452,   455,   456,
     459,   474,   475,   476,   477,   478,   479,   482,   483,   484,
     485,   486,   489,   492,   493
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"mathematical symbol\"",
  "'&'", "'|'", "'-'", "'+'", "'*'", "'/'", "'%'", "'^'", "\"number\"",
  "\"'after'\"", "\"element name\"", "\"'@' or 'at'\"", "\"=>\"",
  "\"'compartment'\"", "\"name of a pre-defined constant\"",
  "\"'constraint'\"", "\"'const'\"", "\"--\"", "\"'delete'\"", "\"'DNA'\"",
  "\"...\"", "\"'end'\"", "\"an error\"", "\"'event'\"", "\"'formula'\"",
  "\"name of an existing function\"", "\"'function'\"", "\"'gene'\"",
  "\"'has'\"", "\"'import'\"", "\"'in'\"", "\"'is'\"", "\"'maximize'\"",
  "\"'minimize'\"", "\"name of an existing module\"",
  "\"'model' or 'module'\"", "\"'operator'\"", "\"'reaction'\"",
  "\"'species'\"", "\"'substanceOnly'\"", "\"text string\"", "\"'unit'\"",
  "\"'var'\"", "'('", "')'", "','", "'.'", "'$'", "'='", "':'", "'\\''",
  "';'", "'>'", "'<'", "'!'", "'{'", "'}'", "'\\n'", "$accept", "input",
  "import", "module", "$@1", "$@2", "maybemain", "function", "$@3",
  "spacedformula", "variableexportlist", "variable", "variablein",
  "varmaybein", "varmaybeis", "maybein", "modulebody", "modulepart",
  "reaction", "reactantList", "reactionDivider", "formula", "commaformula",
  "mathThing", "lineend", "assignment", "submodule", "$@4", "$@5",
  "variableimportlist", "submodifications", "varinitialize", "specinit",
  "formulainit", "reactioninit", "dnainit", "geneinit", "operatorinit",
  "compartmentinit", "varconstinit", "unitinit", "dnadef", "dnastrand",
  "dnamiddle", "event", "$@6", "$@7", "$@8", "$@9", "colonret",
  "eventmodifications", "assignmentlist", "deletion", "unitdef",
  "constraint", "inequality", "objective", "maxormin", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,    38,   124,    45,    43,    42,    47,
      37,    94,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,    40,    41,    44,
      46,    36,    61,    58,    39,    59,    62,    60,    33,   123,
     125,    10
};
# endif

#define YYPACT_NINF -288

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-288)))

#define YYTABLE_NINF -59

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -288,    59,  -288,  -288,    16,    93,   223,  -288,   191,   223,
      33,   381,   191,   191,   191,  -288,   191,    10,   191,   -21,
    -288,  -288,    -6,   131,   191,   191,   191,   168,   191,   388,
     191,  -288,  -288,  -288,  -288,  -288,   106,   101,   171,  -288,
     182,     0,  -288,   182,   182,   182,    34,    54,    66,    75,
      85,    98,   158,   178,   182,   182,  -288,   191,   182,   160,
     182,   182,  -288,   223,  -288,    90,   186,   202,   212,  -288,
    -288,   688,    -8,  -288,   179,  -288,  -288,  -288,   203,   191,
     191,   191,   191,   191,  -288,   191,    21,  -288,    96,   191,
     212,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,   250,  -288,  -288,  -288,   191,  -288,   184,   191,
     191,   191,   191,   191,   191,   191,   225,  -288,   212,  -288,
     191,   256,   191,  -288,   169,  -288,   214,   222,  -288,     8,
      18,  -288,   270,    94,  -288,  -288,  -288,   191,   191,   191,
     191,   191,   191,   191,   191,  -288,  -288,   116,  -288,   191,
    -288,  -288,  -288,   776,  -288,  -288,  -288,  -288,   776,   776,
     286,   287,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,  -288,  -288,   239,   244,   245,   248,  -288,   212,
    -288,  -288,  -288,  -288,   252,   260,   776,   776,  -288,  -288,
    -288,  -288,  -288,  -288,  -288,   191,   116,   261,   129,   268,
    -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,   191,
     212,  -288,    76,   776,  -288,  -288,    -7,   776,   191,  -288,
     269,  -288,    96,     0,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,   191,   212,  -288,   212,    -2,  -288,  -288,  -288,  -288,
    -288,  -288,  -288,  -288,  -288,   212,   776,  -288,  -288,   776,
     776,   139,  -288,  -288,  -288,  -288,   257,    82,  -288,   776,
    -288,  -288,   776,  -288,   191,  -288,   212,   192,   273,   604,
     776,  -288,   191,   191,   719,  -288,   776,    94,   776,   776,
     212,  -288,  -288,  -288,  -288,  -288,   309,  -288,     7,   776,
     776,   198,   212,  -288,   150,   191,   153,  -288,   212,   212,
    -288,  -288,   129,    12,   745,    82,   776,   274,  -288,   205,
    -288,   182,   191,   143,  -288,   212,   211,  -288,  -288,   776,
      82,   236,  -288,   191,  -288,     7,  -288,  -288,   -17,   776,
     182,   212,   311,  -288,   604,  -288,     7,  -288,   745,   212,
    -288,   776,   662,  -288,  -288,   182,   275,   556,    82,  -288,
     143,  -288,    11,    77,   188,  -288,     7,  -288,   191,  -288,
     191,  -288,  -288,   212,  -288,  -288,  -288
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     7,     0,     0,    28,    68,     0,     0,
       0,     0,     0,     0,     0,     8,     0,     0,     0,     0,
     203,   204,     0,    16,     0,     0,     0,     0,     0,     0,
       0,    94,    95,     3,     4,     6,    32,    51,     0,     5,
       0,     0,    54,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,     0,   162,   168,     0,     0,
       0,     0,    68,     0,    28,   199,   197,     0,    59,    68,
      68,   171,    32,    33,    34,   153,    68,    68,     0,     0,
       0,     0,     0,     0,   139,     0,     0,   158,   164,   165,
     188,   141,   133,    18,    21,    20,   145,     9,   107,    17,
      15,    14,     0,   149,   137,   125,     0,   129,   161,     0,
       0,     0,     0,     0,     0,     0,     0,   157,    30,   169,
       0,     0,     0,    68,     0,    68,    57,     0,    43,     0,
       0,    66,     0,    57,    44,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,    49,    47,   166,    48,     0,
      50,    52,    53,   202,    68,   200,   198,   201,   191,   194,
       0,     0,    86,    85,    87,    88,    93,    89,    71,    68,
      72,    69,    73,    68,     0,    90,    91,    92,    68,    70,
      75,   181,    68,    68,     0,     0,   193,   195,    68,   155,
     143,   135,   147,   151,   127,     0,   167,     0,   109,    12,
     128,    68,   154,   142,   134,   146,   150,   138,   126,     0,
      31,    29,     0,   190,   104,   101,    98,    97,     0,    68,
       0,    68,    58,     0,   163,    68,    68,    63,    65,    64,
      62,     0,    60,    67,    58,     0,   132,   136,   140,   144,
     148,   152,   156,   159,   170,   189,   192,    80,    81,   173,
      83,     0,    78,    77,    76,    79,     0,     0,    38,    35,
      68,    68,   196,   131,    25,   112,   110,     0,     0,    57,
     160,   130,     0,     0,   175,   105,   102,    57,    96,   103,
      61,    68,   181,    74,    68,    82,     0,   179,     0,    36,
      37,     0,    26,   114,     0,    25,    57,    41,   100,    99,
      68,   181,   109,     0,    39,     0,    84,     0,   180,     0,
     172,    68,     0,    39,   113,   111,     0,    13,    42,   177,
       0,     0,    68,     0,    56,     0,    68,    68,     0,    22,
      68,    27,     0,   108,    57,   181,     0,   114,    39,    40,
     174,   182,   183,    19,    24,    23,     0,    57,     0,   176,
      39,    55,     0,     0,     0,    11,     0,   106,     0,   186,
       0,   184,   116,   115,   178,   187,   185
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,     1,
      35,    -1,    13,    14,   363,  -220,    -5,     2,  -288,  -116,
     109,   237,  -288,  -288,    -9,  -288,  -288,  -288,  -288,    32,
       5,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,   213,   326,  -288,  -288,  -288,  -288,  -288,  -287,
    -281,    20,  -288,    40,  -288,    31,  -288,   217
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    33,    34,   268,   269,   102,    35,   197,   328,
     291,    72,    73,    74,    75,   324,   296,   297,    40,    41,
     133,   213,   251,   180,    42,    43,    44,   302,   198,   267,
     313,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   181,   282,   301,   335,   288,
     257,   310,    59,   214,    60,    69,    61,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,   305,   273,    39,    68,   130,   129,   130,   343,    78,
     223,    88,    90,   227,    37,    38,   131,   235,   325,   130,
     320,    64,   228,    97,    93,    64,   120,   108,    63,   118,
     231,   128,    64,   336,   134,   135,   136,    70,    31,    94,
      76,    98,   121,   121,    32,   145,   146,    64,    95,   148,
     150,   151,   152,   281,   348,   229,   147,   132,    30,     2,
       3,   356,    30,   195,   230,     4,   -57,   322,   308,    30,
     179,     5,   358,     6,     7,   -57,     8,     9,    10,    11,
      12,    13,    14,   137,    30,    15,    77,    16,   196,    17,
      18,    64,    19,   333,   154,    20,    21,    22,    23,    24,
      25,    26,    27,   138,    28,    29,   218,    64,    64,   -33,
      30,   272,   -58,   -58,    31,   139,   -57,   119,   351,   210,
      32,   212,   -58,   216,   140,   222,   121,   119,    30,   232,
     357,   286,   234,   -33,   141,   287,   -33,   244,   360,    99,
     120,   265,   155,    64,    30,    30,   121,   142,   245,    65,
      66,    67,   179,   -33,   -33,   -33,   121,   179,   179,     4,
     100,   303,   314,   -58,    64,     5,   121,     6,     7,   101,
       8,     9,    10,    11,    12,    13,    14,   323,   317,   122,
      30,    16,    64,    64,    18,   179,   179,   283,   284,    20,
      21,    22,   332,    24,    25,    26,    27,   266,    28,    29,
     362,    30,    64,   123,    30,    64,   124,   143,    31,   149,
     106,   182,   179,   215,    32,    31,   179,    68,   256,    30,
      30,    32,   258,   125,   126,   127,   218,   144,    64,   219,
     280,   183,   184,   185,   121,    12,   201,    31,   156,    30,
     293,   294,    30,    32,    71,   179,   311,   312,   179,   179,
      20,    21,   220,   121,   157,   121,   188,   327,   179,   334,
     312,   179,   121,   292,   199,    30,   221,   209,    36,   179,
     211,   298,   299,   179,   226,   179,   234,   179,   179,    65,
      66,    67,    37,    38,   337,   294,   233,   309,   179,   179,
     247,   252,   248,   315,   292,    36,   253,   254,   318,   153,
     255,   266,   330,   179,   260,   179,   158,   159,   264,    37,
      38,   331,   261,   186,   187,   -10,   275,   285,   179,   344,
     295,   330,   339,   307,   309,   346,   326,   354,   179,   347,
     316,   345,   277,    36,   321,   309,   344,   179,    89,   224,
     179,   179,   350,   225,     0,   340,    36,    37,    38,   318,
       0,   309,   309,   363,     0,   309,   349,   309,     0,   309,
      37,    38,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   359,   361,    87,     0,   364,    91,   365,    92,
     366,    96,     0,     0,     0,     0,     0,   103,   104,   105,
     107,   246,   117,     0,     0,    64,     0,     0,    79,     0,
       0,     0,    64,     0,    80,   109,   249,     0,     0,    81,
     250,   110,    82,     0,     0,     0,   111,     0,     0,   112,
     259,    83,    84,    85,    86,   262,     0,     0,   113,   114,
     115,   116,    30,     0,     0,     0,     0,     0,   270,    30,
       0,     0,   189,   190,   191,   192,   193,     0,   194,     0,
       0,     0,     0,     0,     0,     0,   274,     0,   276,     0,
       0,     0,   278,   279,     0,     0,     0,     0,     0,   200,
       0,     0,   202,   203,   204,   205,   206,   207,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   289,   290,     0,
     236,   237,   238,   239,   240,   241,   242,   243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   304,     0,
       0,   306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   319,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   329,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   263,   338,
       0,     0,     4,   341,   342,     0,     0,   329,     5,     0,
       6,     7,   271,     8,     9,    10,    11,    12,    13,    14,
       0,   355,     0,     0,    16,     0,     0,    18,     0,     0,
       0,     0,    20,    21,    22,     0,    24,    25,    26,    27,
       0,    28,    29,     0,     0,     0,     0,    30,     0,     0,
       4,    31,     0,     0,     0,     0,     5,    32,     6,     7,
       0,     8,     9,    10,    11,    12,    13,    14,     0,     0,
       0,     0,    16,     0,     0,    18,     0,     0,     0,     0,
      20,    21,    22,     0,    24,    25,    26,    27,     0,    28,
      29,     0,     0,     0,     0,    30,     0,     0,     0,    31,
       0,     0,     0,     0,     0,    32,   160,   161,   162,   163,
     164,   165,   166,   167,   168,     0,    64,     0,     0,     0,
     170,     0,     0,     0,     0,     0,   171,     0,     0,     0,
       0,   172,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    64,     0,     0,     0,   170,     0,     0,   173,
       0,   352,   171,    30,   174,   353,     0,   172,   175,   176,
     177,   178,     0,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   300,    64,     0,   173,     0,   170,     0,    30,
     174,     0,     0,   171,   175,   176,   177,   178,   172,   160,
     161,   162,   163,   164,   165,   166,   167,   168,     0,    64,
       0,     0,     0,   170,     0,     0,   173,     0,     0,   171,
      30,   174,     0,     0,   172,   175,   176,   177,   178,   323,
     160,   161,   162,   163,   164,   165,   166,   167,   168,     0,
      64,     0,   173,     0,   170,     0,    30,   174,     0,     0,
     171,   175,   176,   177,   178,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,     0,     0,     0,    30,   174,     0,
       0,     0,   175,   176,   177,   178
};

static const yytype_int16 yycheck[] =
{
       1,   282,     9,     1,     5,     7,     6,     7,    25,    10,
     126,    12,    13,     5,     1,     1,    16,   133,   305,     7,
     301,    14,    14,    44,    14,    14,    34,    28,    12,    30,
      12,    40,    14,   320,    43,    44,    45,     6,    55,    29,
       9,    47,    50,    50,    61,    54,    55,    14,    38,    58,
      59,    60,    61,    55,   335,    47,    57,    57,    51,     0,
       1,   348,    51,    42,    56,     6,     7,    55,    61,    51,
      71,    12,    61,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    49,    51,    26,    53,    28,    89,    30,
      31,    14,    33,   313,    63,    36,    37,    38,    39,    40,
      41,    42,    43,    49,    45,    46,    12,    14,    14,     8,
      51,    35,     6,     7,    55,    49,    57,    21,   338,   120,
      61,   122,    16,   124,    49,   126,    50,    21,    51,   130,
     350,    49,   133,    32,    49,    53,    35,    21,    61,     8,
      34,    12,    52,    14,    51,    51,    50,    49,   149,    56,
      57,    58,   153,    52,    53,    54,    50,   158,   159,     6,
      29,   277,    12,    57,    14,    12,    50,    14,    15,    38,
      17,    18,    19,    20,    21,    22,    23,    34,    25,     8,
      51,    28,    14,    14,    31,   186,   187,    48,    49,    36,
      37,    38,    49,    40,    41,    42,    43,   198,    45,    46,
      12,    51,    14,    32,    51,    14,    35,    49,    55,    49,
      42,    32,   213,    44,    61,    55,   217,   218,   178,    51,
      51,    61,   182,    52,    53,    54,    12,    49,    14,    15,
     231,    52,    53,    54,    50,    21,    52,    55,    52,    51,
      48,    49,    51,    61,     7,   246,    48,    49,   249,   250,
      36,    37,    38,    50,    52,    50,    53,    52,   259,    48,
      49,   262,    50,   264,    14,    51,    52,    42,   269,   270,
      14,   272,   273,   274,    52,   276,   277,   278,   279,    56,
      57,    58,   269,   269,    48,    49,    16,   288,   289,   290,
       4,    52,     5,   294,   295,   296,    52,    52,   296,    62,
      52,   302,   311,   304,    52,   306,    69,    70,    47,   296,
     296,   312,    52,    76,    77,    47,    47,    60,   319,   328,
      47,   330,   323,    14,   325,    14,    52,    52,   329,   334,
     295,   330,   223,   334,   302,   336,   345,   338,    12,   126,
     341,   342,   337,   126,    -1,   325,   347,   334,   334,   347,
      -1,   352,   353,   354,    -1,   356,   336,   358,    -1,   360,
     347,   347,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   352,   353,    11,    -1,   356,    14,   358,    16,
     360,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,   154,    29,    -1,    -1,    14,    -1,    -1,    17,    -1,
      -1,    -1,    14,    -1,    23,    17,   169,    -1,    -1,    28,
     173,    23,    31,    -1,    -1,    -1,    28,    -1,    -1,    31,
     183,    40,    41,    42,    43,   188,    -1,    -1,    40,    41,
      42,    43,    51,    -1,    -1,    -1,    -1,    -1,   201,    51,
      -1,    -1,    79,    80,    81,    82,    83,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,   221,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   261,    -1,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   281,    -1,
      -1,   284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   322,
      -1,    -1,     6,   326,   327,    -1,    -1,   330,    12,    -1,
      14,    15,   209,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    -1,    -1,    28,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    41,    42,    43,
      -1,    45,    46,    -1,    -1,    -1,    -1,    51,    -1,    -1,
       6,    55,    -1,    -1,    -1,    -1,    12,    61,    14,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    41,    42,    43,    -1,    45,
      46,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    61,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,    47,
      -1,    49,    24,    51,    52,    53,    -1,    29,    56,    57,
      58,    59,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    47,    -1,    18,    -1,    51,
      52,    -1,    -1,    24,    56,    57,    58,    59,    29,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    18,    -1,    -1,    47,    -1,    -1,    24,
      51,    52,    -1,    -1,    29,    56,    57,    58,    59,    34,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    47,    -1,    18,    -1,    51,    52,    -1,    -1,
      24,    56,    57,    58,    59,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    56,    57,    58,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,     0,     1,     6,    12,    14,    15,    17,    18,
      19,    20,    21,    22,    23,    26,    28,    30,    31,    33,
      36,    37,    38,    39,    40,    41,    42,    43,    45,    46,
      51,    55,    61,    64,    65,    69,    73,    74,    75,    79,
      80,    81,    86,    87,    88,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   114,
     116,   118,   119,    12,    14,    56,    57,    58,    73,   117,
     117,    83,    73,    74,    75,    76,   117,    53,    73,    17,
      23,    28,    31,    40,    41,    42,    43,    76,    73,   105,
      73,    76,    76,    14,    29,    38,    76,    44,    47,     8,
      29,    38,    68,    76,    76,    76,    42,    76,    73,    17,
      23,    28,    31,    40,    41,    42,    43,    76,    73,    21,
      34,    50,     8,    32,    35,    52,    53,    54,    86,     6,
       7,    16,    57,    82,    86,    86,    86,    49,    49,    49,
      49,    49,    49,    49,    49,    86,    86,    73,    86,    49,
      86,    86,    86,    83,   117,    52,    52,    52,    83,    83,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      18,    24,    29,    47,    52,    56,    57,    58,    59,    73,
      85,   107,    32,    52,    53,    54,    83,    83,    53,    76,
      76,    76,    76,    76,    76,    42,    73,    70,    90,    14,
      76,    52,    76,    76,    76,    76,    76,    76,    76,    42,
      73,    14,    73,    83,   115,    44,    73,    83,    12,    15,
      38,    52,    73,    81,   104,   119,    52,     5,    14,    47,
      56,    12,    73,    16,    73,    81,    76,    76,    76,    76,
      76,    76,    76,    76,    21,    73,    83,     4,     5,    83,
      83,    84,    52,    52,    52,    52,   115,   112,   115,    83,
      52,    52,    83,    76,    47,    12,    73,    91,    66,    67,
      83,    76,    35,     9,    83,    47,    83,    82,    83,    83,
      73,    55,   108,    48,    49,    60,    49,    53,   111,    83,
      83,    72,    73,    48,    49,    47,    78,    79,    73,    73,
      13,   109,    89,    81,    83,   112,    83,    14,    61,    73,
     113,    48,    49,    92,    12,    73,    72,    25,    79,    83,
     112,    91,    55,    34,    77,   111,    52,    52,    71,    83,
      86,    73,    49,    77,    48,   110,   111,    48,    83,    73,
     113,    83,    83,    25,    86,    71,    14,    78,   112,   113,
      92,    77,    49,    53,    52,    25,   111,    77,    61,   113,
      61,   113,    12,    73,   113,   113,   113
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    63,    63,    63,    63,    63,    64,
      66,    65,    67,    65,    65,    65,    68,    68,    70,    69,
      69,    69,    71,    71,    71,    72,    72,    72,    73,    73,
      73,    74,    75,    75,    76,    76,    76,    76,    76,    77,
      77,    78,    78,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    80,    80,    81,    81,    81,
      81,    81,    82,    82,    82,    82,    82,    82,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    89,    88,    90,    88,    91,
      91,    91,    91,    91,    92,    92,    92,    93,    93,    93,
      93,    93,    93,    93,    93,    94,    94,    94,    94,    94,
      94,    94,    94,    95,    95,    95,    95,    96,    96,    96,
      96,    97,    97,    97,    97,    98,    98,    98,    98,    99,
      99,    99,    99,   100,   100,   100,   100,   101,   101,   101,
     102,   102,   103,   103,   104,   104,   104,   104,   104,   105,
     105,   107,   106,   108,   106,   109,   106,   110,   106,   111,
     111,   112,   112,   113,   113,   113,   113,   113,   114,   114,
     115,   116,   116,   116,   116,   116,   116,   117,   117,   117,
     117,   117,   118,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       0,     9,     0,     6,     2,     2,     0,     1,     0,     8,
       2,     2,     1,     2,     2,     0,     1,     3,     1,     3,
       2,     3,     1,     1,     1,     3,     4,     4,     3,     0,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     1,     8,     6,     0,     1,     2,
       3,     4,     2,     2,     2,     2,     1,     2,     0,     2,
       2,     2,     2,     2,     4,     2,     3,     3,     3,     3,
       3,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     3,     5,
       5,     3,     4,     4,     3,     0,     9,     0,     7,     0,
       1,     3,     1,     3,     0,     5,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     3,     2,
       4,     4,     3,     2,     3,     3,     3,     2,     3,     2,
       3,     2,     3,     3,     3,     2,     3,     3,     3,     2,
       3,     3,     3,     2,     3,     3,     3,     2,     2,     3,
       4,     2,     1,     3,     2,     2,     2,     3,     1,     2,
       3,     0,     6,     0,     8,     0,     8,     0,    10,     1,
       2,     0,     5,     3,     5,     6,     5,     6,     2,     3,
       1,     3,     4,     3,     3,     3,     4,     1,     2,     1,
       2,     2,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 3:
#line 138 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1660 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 139 "antimony.ypp" /* yacc.c:1646  */
    { /*cout << endl << $2->ToString() << endl << endl;*/ }
#line 1666 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 140 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1672 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 141 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1678 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 142 "antimony.ypp" /* yacc.c:1646  */
    {YYABORT;}
#line 1684 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 143 "antimony.ypp" /* yacc.c:1646  */
    {YYABORT;}
#line 1690 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 146 "antimony.ypp" /* yacc.c:1646  */
    { if (g_registry.OpenFile(*((yyvsp[0].word)))==0) YYABORT;}
#line 1696 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 149 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.NewCurrentModule((yyvsp[0].word), (yyvsp[-1].maybemain));}
#line 1702 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 150 "antimony.ypp" /* yacc.c:1646  */
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 1712 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 155 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.NewCurrentModule((yyvsp[0].word), (yyvsp[-1].maybemain));}
#line 1718 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 156 "antimony.ypp" /* yacc.c:1646  */
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 1728 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 161 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("module '" + *((yyvsp[0].word)) + "' already defined."); YYABORT;}
#line 1734 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 162 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a module because it is already a defined function."); YYABORT;}
#line 1740 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 165 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.maybemain) = false;}
#line 1746 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 166 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.maybemain) = true;}
#line 1752 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 169 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.NewUserFunction((yyvsp[0].word));}
#line 1758 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 169 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetUserFunction((yyvsp[-1].formula))) YYABORT;}
#line 1764 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 170 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Cannot use '" + *((yyvsp[0].word)) +"' as a function name because it is already the name of a module."); YYABORT;}
#line 1770 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 171 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a new function because it is already a defined function."); YYABORT;}
#line 1776 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 174 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[0].formula);}
#line 1782 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 175 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[0].formula);}
#line 1788 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 176 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula);}
#line 1794 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 186 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1800 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 187 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 1806 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 188 "antimony.ypp" /* yacc.c:1646  */
    { if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 1812 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 191 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[0].word)); }
#line 1818 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 192 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-2].variable)->GetSubVariable((yyvsp[0].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[0].word)) + "' is not a subvariable of '" + (yyvsp[-2].variable)->GetNameDelimitedBy(".") + "'.");
                    YYABORT;
                  }
                }
#line 1829 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 198 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;}
#line 1835 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 201 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetCompartment((yyvsp[0].variable))) YYABORT; (yyval.variable) = (yyvsp[-2].variable);}
#line 1841 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 204 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable);}
#line 1847 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 205 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable);}
#line 1853 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 208 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable);}
#line 1859 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 209 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 1865 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 210 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT; }
#line 1871 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 211 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT; }
#line 1877 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 212 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 1883 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 215 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = NULL;}
#line 1889 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 216 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable);}
#line 1895 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 219 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1901 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 220 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1907 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 223 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1913 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 224 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1919 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 225 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1925 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 226 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1931 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 227 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1937 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 228 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1943 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 229 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1949 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 230 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1955 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 231 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1961 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 232 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1967 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 233 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1973 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 234 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1979 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 238 "antimony.ypp" /* yacc.c:1646  */
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-7].variable));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-7].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 1991 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 246 "antimony.ypp" /* yacc.c:1646  */
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2003 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 255 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); }
#line 2009 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 256 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[0].variable)); }
#line 2015 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 257 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num)); }
#line 2021 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 258 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactantList) = (yyvsp[-2].reactantList); (yyvsp[-2].reactantList)->AddReactant((yyvsp[0].variable)); }
#line 2027 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 259 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactantList) = (yyvsp[-3].reactantList); (yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num)); }
#line 2033 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 263 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdBecomes;}
#line 2039 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 264 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdInhibits;}
#line 2045 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 265 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdInfluences;}
#line 2051 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 266 "antimony.ypp" /* yacc.c:1646  */
    {if (*(yyvsp[0].word) != "o") {g_registry.SetError("'-" + *(yyvsp[0].word) + "' is not a valid set of characters to demark reactions.  Try '->' for reactions, and '-|', '-o', and '-(' for interactions."); YYABORT;} (yyval.reactionDivider) = rdActivates;}
#line 2057 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 267 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdBecomesIrreversibly;}
#line 2063 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 268 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdBecomes;}
#line 2069 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 271 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = g_registry.NewBlankFormula(); }
#line 2075 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 272 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddEllipses();}
#line 2081 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 273 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddVariable((yyvsp[0].variable)); }
#line 2087 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 274 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddNum((yyvsp[0].num)); }
#line 2093 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 275 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2099 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 276 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2105 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 277 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2111 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 278 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddMathThing((yyvsp[0].character)); }
#line 2117 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 279 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('<'); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2123 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 280 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('>'); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2129 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 281 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('='); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2135 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 282 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('!'); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2141 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 283 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('&'); (yyvsp[-2].formula)->AddMathThing('&'); }
#line 2147 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 284 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('|'); (yyvsp[-2].formula)->AddMathThing('|'); }
#line 2153 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 286 "antimony.ypp" /* yacc.c:1646  */
    {
                  //Need to create a variable to be this unit definition, or find one that already has this unit definition, and then use that name.
                  (yyval.formula) = (yyvsp[-3].formula);
                  (yyval.formula)->AddVariable((yyvsp[-1].variable));
                }
#line 2163 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 293 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[0].formula);}
#line 2169 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 294 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[0].formula)); }
#line 2175 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 297 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '+';}
#line 2181 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 298 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '-';}
#line 2187 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 299 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '*';}
#line 2193 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 300 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '/';}
#line 2199 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 301 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '^';}
#line 2205 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 302 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '>';}
#line 2211 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 303 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '<';}
#line 2217 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 304 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '!';}
#line 2223 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 305 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '%';}
#line 2229 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 308 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2235 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 309 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2241 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 312 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddObjective((yyvsp[-3].variable), (yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 2247 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 313 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2253 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 314 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->Synchronize((yyvsp[0].variable), NULL)) YYABORT;}
#line 2259 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 315 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[-2].variable), (yyvsp[0].variable))) YYABORT;}
#line 2265 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 316 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[0].variable), (yyvsp[-2].variable))) YYABORT;}
#line 2271 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 317 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetDisplayName(*((yyvsp[0].word)))) YYABORT;}
#line 2277 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 318 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT;}
#line 2283 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 319 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT;}
#line 2289 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 320 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2295 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 324 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-3].variable)->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2301 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 324 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[0].variable) != NULL) {if ((yyvsp[-8].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2307 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 325 "antimony.ypp" /* yacc.c:1646  */
    {if(g_registry.CurrentModule()->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2313 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 325 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[0].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2319 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 329 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2325 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 330 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2331 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 331 "antimony.ypp" /* yacc.c:1646  */
    { if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2337 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 332 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2343 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 333 "antimony.ypp" /* yacc.c:1646  */
    { if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2349 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 337 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2355 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 338 "antimony.ypp" /* yacc.c:1646  */
    {if (CaselessStrCmp(*(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].variable));}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2363 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 342 "antimony.ypp" /* yacc.c:1646  */
    {if (CaselessStrCmp(*(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].num));}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2371 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 346 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2377 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 347 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2383 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 348 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2389 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 349 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2395 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 350 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2401 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 351 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2407 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 353 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2413 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 354 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2419 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 357 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2425 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 358 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2431 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 359 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2437 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 360 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2443 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 361 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2449 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 362 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2455 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 363 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2461 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 364 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2467 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 367 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2473 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 368 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2479 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 369 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2485 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 370 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2491 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 373 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 2497 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 374 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 2503 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 375 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; }
#line 2509 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 376 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 2515 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 379 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 2521 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 380 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 2527 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 381 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 2533 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 382 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 2539 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 385 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 2545 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 386 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 2551 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 387 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Genes may not be set 'const'."); YYABORT; }
#line 2557 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 388 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 2563 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 391 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 2569 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 392 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 2575 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 393 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 2581 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 394 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 2587 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 398 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 2593 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 399 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 2599 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 400 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 2605 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 401 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 2611 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 404 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst();}
#line 2617 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 405 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst();}
#line 2623 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 406 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst();}
#line 2629 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 409 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetType(varUnitDefinition)) YYABORT;
                                               if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                                               if ((yyvsp[-2].variable)->GetUnitDef()->SetFromFormula((yyvsp[0].formula))) YYABORT;}
#line 2637 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 412 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[0].variable)->SetType(varUnitDefinition)) YYABORT;}
#line 2643 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 415 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SaveWorkingStrand()) YYABORT;}
#line 2649 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 416 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetStrandAs((yyvsp[-2].variable))) YYABORT;}
#line 2655 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 419 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewUpstreamOpen((yyvsp[0].variable))) YYABORT;}
#line 2661 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 420 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetOpenUpstream(); }
#line 2667 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 421 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 2673 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 422 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 2679 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 423 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2685 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 426 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 2691 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 427 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 2697 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 430 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula))) YYABORT;}
#line 2703 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 430 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2709 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 431 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula))) YYABORT;}
#line 2715 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 431 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2721 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 432 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula), (yyvsp[-3].variable))) YYABORT;}
#line 2727 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 432 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2733 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 433 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula), (yyvsp[-5].variable))) YYABORT;}
#line 2739 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 433 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2745 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 436 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2751 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 437 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2757 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 440 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2763 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 441 "antimony.ypp" /* yacc.c:1646  */
    {if (CaselessStrCmp(*(yyvsp[-2].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[0].formula));}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[0].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;}}
#line 2773 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 448 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 2779 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 449 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 2785 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 450 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 2791 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 451 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 2797 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 452 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 2803 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 455 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 2809 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 456 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 2815 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 459 "antimony.ypp" /* yacc.c:1646  */
    {
                    if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                    if ((yyvsp[0].formula)->IsSingleVariable()) {
                      (yyval.variable) = g_registry.CurrentModule()->GetVariable(((yyvsp[0].formula)->GetVariables())[0]);
                      if ((yyval.variable)==NULL) YYABORT;
                    }
                    else {
                      UnitDef* ud = new UnitDef("", g_registry.CurrentModule()->GetModuleName());
                      if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                      if (ud->SetFromFormula((yyvsp[0].formula))) YYABORT;
                      (yyval.variable) = g_registry.CurrentModule()->AddOrFindUnitDef(ud);
                    }
                }
#line 2833 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 474 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 2839 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 475 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint(-(yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 2845 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 476 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 2851 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 477 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 2857 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 478 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[0].formula))) YYABORT;}
#line 2863 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 479 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 2869 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 482 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constLT;}
#line 2875 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 483 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constLEQ;}
#line 2881 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 484 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constGT;}
#line 2887 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 485 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constGEQ;}
#line 2893 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 486 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constNEQ;}
#line 2899 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 489 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddObjective((yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 2905 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 492 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.maxormin) = true;}
#line 2911 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 493 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.maxormin) = false;}
#line 2917 "antimony.tab.cpp" /* yacc.c:1646  */
    break;


#line 2921 "antimony.tab.cpp" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
  return yyresult;
}
#line 495 "antimony.ypp" /* yacc.c:1906  */



void antimony_yyerror(char const *s)
{
  if (g_registry.GetError()=="") {
    g_registry.SetError(s);
  }
}

int antimony_yylex(void)
{
  char cc = 0;
  g_registry.input->get(cc);

  //If we're done with the file:
  if (g_registry.input->eof()) {
    if (g_registry.SwitchToPreviousFile()) {
      if (g_registry.CurrentModule()->Finalize()) {
        return ERROR;
      }
      return 0;
    }
    else {
      antimony_yylloc_first_line = antimony_yylloc_last_lines.back();
      antimony_yylloc_last_line = antimony_yylloc_last_lines.back();
      antimony_yylloc_last_lines.pop_back();
      return antimony_yylex();
    }
  }
  if (!g_registry.input->good()) {
    //Something else went wrong!
    g_registry.SetError("Unparseable content in line " + DoubleToString(antimony_yylloc_last_line) + ".");
    return ERROR;
  }

  antimony_yylloc_first_line = antimony_yylloc_last_line;

  // Skip white space.
  while ((cc == ' ' ||
         cc == '\t') &&
         !g_registry.input->eof()) {
    g_registry.input->get(cc);
  }
  if (g_registry.input->eof()) return antimony_yylex();
  // Skip carriage returns after '\':
  if (cc == '\\') {
    g_registry.input->get(cc);
    if (cc == '\r' || cc == '\n' || cc == ' ') {
      while ((cc == '\r' || cc == '\n' || cc == ' ') && !g_registry.input->eof()) {
        g_registry.input->get(cc);
      }
      ++antimony_yylloc_last_line;
      g_registry.input->unget();
      return antimony_yylex();
    }
    else {
      g_registry.input->unget();
      cc = '\\';
    }
 }

  // Parse words
  if (cc > 0 && cc < 256 && (isalpha(cc) || cc == '_')) {
    string word;
    while (cc > 0 && cc < 256 && (isalpha(cc) || isdigit(cc) || cc == '_') && !g_registry.input->eof()) {
      word += cc;
      g_registry.input->get(cc);
    }
    if (!g_registry.input->eof()) {
      g_registry.input->unget();
    }
    if (CaselessStrCmp(word, "module")) {
      return MODULE;
    }
    if (CaselessStrCmp(word, "model")) {
      return MODULE;
    }
    if (CaselessStrCmp(word, "end")) {
      return END;
    }
    if (CaselessStrCmp(word, "species")) {
      return SPECIES;
    }
    if (CaselessStrCmp(word, "formula")) {
      return FORMULA;
    }
    if (CaselessStrCmp(word, "reaction")) {
      return REACTION;
    }
    if (CaselessStrCmp(word, "DNA")) {
      return DNA;
    }
    if (CaselessStrCmp(word, "gene")) {
      return GENE;
    }
    if (CaselessStrCmp(word, "operator")) {
      return OPERATOR;
    }
    if (CaselessStrCmp(word, "compartment")) {
      return COMPARTMENT;
    }
    if (CaselessStrCmp(word, "has")) {
      return HASWORD;
    }
    if (CaselessStrCmp(word, "in")) {
      return INWORD;
    }
    if (CaselessStrCmp(word, "is")) {
      return IS;
    }
    if (CaselessStrCmp(word, "var")) {
      return VARWORD;
    }
    if (CaselessStrCmp(word, "const")) {
      return CONSTWORD;
    }
    if (CaselessStrCmp(word, "substanceOnly")) {
      return SUBSTONLY;
    }
    if (CaselessStrCmp(word, "ext")) {
      return CONSTWORD;
    }
    if (CaselessStrCmp(word, "import")) {
      return IMPORT;
    }
    if (CaselessStrCmp(word, "event")) {
      return EVENT;
    }
    if (CaselessStrCmp(word, "at")) {
      return AT;
    }
    if (CaselessStrCmp(word, "after")) {
      return AFTER;
    }
    if (CaselessStrCmp(word, "function")) {
      return FUNCTIONWORD;
    }
    if (CaselessStrCmp(word, "unit")) {
      return UNITWORD;
    }
    if (CaselessStrCmp(word, "delete")) {
      return DELETEWORD;
    }
    if (CaselessStrCmp(word, "constraint")) {
      return CONSTRAINTWORD;
    }
    if (CaselessStrCmp(word, "maximize")) {
      return MAXIMIZEWORD;
    }
    if (CaselessStrCmp(word, "minimize")) {
      return MINIMIZEWORD;
    }
    
    if (g_registry.IsFunction(word) != NULL) {
      antimony_yylval.word = g_registry.IsFunction(word);
      return FUNCTION;
    }
    if (g_registry.IsConstant(word) != NULL) {
      antimony_yylval.word = g_registry.IsConstant(word);
      return CONSTANT;
    }
    //Otherwise, it's a user-defined variable:
    antimony_yylval.word = g_registry.AddWord(word);
    //cout << "\tRead word '" << word << "'." << endl;
    if (g_registry.IsModuleName(word)) {
      return MODNAME;
    }
    return ANTWORD;
  }

  // Parse numbers
  if (cc > 0 && cc < 256 && (isdigit(cc) || (cc=='.' && isdigit(g_registry.input->peek())))) {
    double number;
    g_registry.input->unget();
    streampos numbegin = g_registry.input->tellg();
    *g_registry.input >> number;
    streampos numend = g_registry.input->tellg();
    if (g_registry.input->fail()) {
      //The gcc 4.4.3 parser fails if there's an 'e' after a number with no exponent.
      g_registry.input->clear();
      g_registry.input->seekg(numbegin);
      int numint;
      *g_registry.input >> numint;
      antimony_yylval.num = numint;
      if (g_registry.input->peek() == '.') {
        g_registry.input->get();
        *g_registry.input >> numint;
        double fraction = numint;
        while (fraction >= 1.0) {
          fraction = fraction/10;
        }
        antimony_yylval.num += fraction;
      }
      return NUM;
    }
    assert(g_registry.input->good());
    antimony_yylval.num = number;
    //However, pre-4.4.3 parsers would read the 'e' anyway, and we don't want it to, so unget the 'e'.
    g_registry.input->unget();
    if (!g_registry.input->good()) {
      //Sometimes you can't do this?  For some reason?  If this happens we'll assume there was no 'e'.
      g_registry.input->clear();
    }
    else {
      g_registry.input->get(cc);
      if (cc == 'e' || cc == 'E') {
        g_registry.input->unget();
      }
    }
    return NUM;
  }

  //Parse reaction dividers and dashes
  if (cc == '-') {
    g_registry.input->get(cc);
    if (cc == '-') {
      while ((cc == '-') && !g_registry.input->eof()) {
        g_registry.input->get(cc);
      }
      g_registry.input->unget();
      return DASHES;
    }
    g_registry.input->unget();
    cc = '-';
    return cc;
  }

  //Parse '=>'
  if (cc == '=') {
    g_registry.input->get(cc);
    if (cc == '>') {
      return BECOMESIRREV;
    }
    g_registry.input->unget();
    cc = '=';
    return cc;
  }

  //Skip comments:
  if (cc == '/') {
    g_registry.input->get(cc);
    if (cc == '/') {
      while (cc != '\n' && cc != '\r' && !g_registry.input->eof()) {
        g_registry.input->get(cc);
      }
      if (!g_registry.input->eof()) {
        g_registry.input->unget();
      }
      return antimony_yylex();
    }
    else if (cc == '*') {
      bool nextstar = false;
      g_registry.input->get(cc);
      while ((!g_registry.input->eof()) && !(nextstar && cc == '/')) {
        if (cc == '*') {
          nextstar = true;
        }
        else {
          nextstar = false;
        }
        g_registry.input->get(cc);
      }
      return antimony_yylex();
    }
    else {
      g_registry.input->unget();
      cc = '/';
    }
  }
  else if (cc == '#') {
      while (cc != '\n' && cc != '\r' && !g_registry.input->eof()) {
        g_registry.input->get(cc);
      }
      if (!g_registry.input->eof()) {
        g_registry.input->unget();
      }
      return antimony_yylex();
  }

  //Parse ellipses
  if (cc == '.') {
    char c1, c2;
    g_registry.input->get(c1);
    g_registry.input->get(c2);
    if (c1=='.' && c2=='.') {
      return ELLIPSES;
    }
    g_registry.input->unget();
    g_registry.input->unget();
  }

  //Parse text strings
  if (cc == '"') {
    string textstring;
    long ccount = 0;
    g_registry.input->get(cc);
    while (cc != '"' && cc != '\r' && cc != '\n' && !g_registry.input->eof()) {
      textstring += cc;
      ccount++;
      g_registry.input->get(cc);
    }
    if (cc == '\r' || cc == '\n' || g_registry.input->eof()) {
      for (; ccount > 0; ccount--) {
        g_registry.input->unget();
      }
      cc = '"';
    }
    else {
      antimony_yylval.word = g_registry.AddWord(textstring);
      return TEXTSTRING;
    }
  }

  //Parse '@'
  if (cc == '@') {
    return AT;
  }

  //This converts PC and Mac end-of-line characters to \n:
  if (cc == '\r') {
    g_registry.input->get(cc);
    if (cc != '\n') {
      g_registry.input->unget();
    }
    cc = '\n';
  }
  if (cc == '\n') {
    ++antimony_yylloc_last_line;
  }
  return cc;
}
