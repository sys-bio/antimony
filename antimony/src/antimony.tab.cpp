/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

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
#include <utility>
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

#line 107 "antimony.tab.cpp" /* yacc.c:339  */

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
    EOL = 259,
    NUM = 260,
    AFTER = 261,
    ANTWORD = 262,
    AT = 263,
    BECOMESREV = 264,
    BECOMESINH = 265,
    BECOMESMOD = 266,
    BECOMESMOD2 = 267,
    BECOMESIRREV = 268,
    COMPARTMENT = 269,
    CONSTANT = 270,
    CONSTRAINTWORD = 271,
    CONSTWORD = 272,
    DASHES = 273,
    DELETEWORD = 274,
    DNA = 275,
    ELLIPSES = 276,
    END = 277,
    ERROR = 278,
    EVENT = 279,
    FORMULA = 280,
    FUNCTION = 281,
    FUNCTIONWORD = 282,
    GENE = 283,
    HASWORD = 284,
    IMPORT = 285,
    INWORD = 286,
    IS = 287,
    MAXIMIZEWORD = 288,
    MINIMIZEWORD = 289,
    MODNAME = 290,
    MODULE = 291,
    OPERATOR = 292,
    REACTION = 293,
    SPECIES = 294,
    SUBSTONLY = 295,
    TEXTSTRING = 296,
    UNITWORD = 297,
    VARWORD = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 60 "antimony.ypp" /* yacc.c:355  */

  char character;
  const string* word;
  double num;
  int integer;
  bool is_integer;
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
  std::vector<std::string>* stringlist;
  std::vector<std::string>* urilist;

#line 212 "antimony.tab.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE antimony_yylval;

int antimony_yyparse (void);



/* Copy the second part of user declarations.  */

#line 227 "antimony.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   854

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  403

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      66,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,     2,     2,    12,    10,     4,    59,
      54,    55,     8,     7,    56,     6,    13,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    60,
      61,    57,    62,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    11,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     5,    65,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   152,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   166,   184,   184,   190,   190,   196,
     197,   200,   201,   204,   204,   205,   206,   209,   210,   211,
     221,   222,   223,   226,   227,   233,   236,   239,   240,   243,
     244,   245,   246,   247,   250,   251,   254,   255,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   273,   281,   291,   292,   293,   294,   295,   299,   300,
     301,   302,   304,   305,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   330,
     331,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     345,   346,   347,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   362,   362,   363,   363,   367,   368,   369,   370,
     371,   375,   376,   380,   384,   385,   386,   387,   388,   389,
     391,   392,   395,   396,   397,   398,   399,   400,   401,   402,
     405,   406,   407,   408,   411,   412,   413,   414,   417,   418,
     419,   420,   423,   424,   425,   426,   429,   430,   431,   432,
     436,   437,   438,   439,   442,   443,   444,   447,   450,   453,
     454,   457,   458,   459,   460,   461,   464,   465,   468,   468,
     469,   469,   470,   470,   471,   471,   474,   475,   478,   479,
     486,   487,   488,   489,   490,   493,   494,   497,   512,   513,
     514,   515,   516,   517,   520,   521,   522,   523,   524,   527,
     530,   531,   534,   535,   536,   543,   546,   553,   561,   567,
     575,   576
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"mathematical symbol\"",
  "'&'", "'|'", "'-'", "'+'", "'*'", "'/'", "'%'", "'^'", "'$'", "'.'",
  "\"end of line\"", "\"number\"", "\"'after'\"", "\"element name\"",
  "\"'@' or 'at'\"", "\"->\"", "\"-|\"", "\"-(\"", "\"-o\"", "\"=>\"",
  "\"'compartment'\"", "\"name of a pre-defined constant\"",
  "\"'constraint'\"", "\"'const'\"", "\"--\"", "\"'delete'\"", "\"'DNA'\"",
  "\"...\"", "\"'end'\"", "\"an error\"", "\"'event'\"", "\"'formula'\"",
  "\"name of an existing function\"", "\"'function'\"", "\"'gene'\"",
  "\"'has'\"", "\"'import'\"", "\"'in'\"", "\"'is'\"", "\"'maximize'\"",
  "\"'minimize'\"", "\"name of an existing module\"",
  "\"'model' or 'module'\"", "\"'operator'\"", "\"'reaction'\"",
  "\"'species'\"", "\"'substanceOnly'\"", "\"text string\"", "\"'unit'\"",
  "\"'var'\"", "'('", "')'", "','", "'='", "':'", "'\\''", "';'", "'<'",
  "'>'", "'!'", "'{'", "'}'", "'\\n'", "$accept", "input", "import",
  "module", "$@1", "$@2", "maybemain", "function", "$@3", "spacedformula",
  "variableexportlist", "variable", "variablein", "varmaybein",
  "varmaybeis", "maybein", "modulebody", "modulepart", "reaction",
  "reactantList", "reactionDivider", "formula", "commaformula",
  "mathThing", "lineend", "assignment", "submodule", "$@4", "$@5",
  "variableimportlist", "submodifications", "varinitialize", "specinit",
  "formulainit", "reactioninit", "dnainit", "geneinit", "operatorinit",
  "compartmentinit", "varconstinit", "unitinit", "dnadef", "dnastrand",
  "dnamiddle", "event", "$@6", "$@7", "$@8", "$@9", "colonret",
  "eventmodifications", "assignmentlist", "deletion", "unitdef",
  "constraint", "inequality", "objective", "maxormin", "stringlist",
  "cvterm", "toplevel_sbo", "modulename", "functionname", "modulecvterm",
  "functioncvterm", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,    38,   124,    45,    43,    42,    47,
      37,    94,    36,    46,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    40,    41,    44,    61,    58,    39,
      59,    60,    62,    33,   123,   125,    10
};
# endif

#define YYPACT_NINF -303

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-303)))

#define YYTABLE_NINF -64

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -303,   545,  -303,  -303,    18,   178,  -303,   214,   253,  -303,
     178,   253,    54,   428,   178,   178,   178,  -303,   178,   146,
     124,   178,   -42,  -303,  -303,    97,   101,   178,   178,   178,
     113,   178,   490,  -303,  -303,  -303,  -303,  -303,   144,   150,
     183,  -303,    47,    63,  -303,    47,    47,    47,     7,    40,
      59,    86,    89,   108,   111,   119,    47,    47,  -303,   178,
      47,    67,    47,    47,  -303,    47,  -303,  -303,  -303,  -303,
    -303,   253,  -303,   174,   142,   149,   164,   174,  -303,  -303,
     681,    26,  -303,   171,  -303,  -303,  -303,     6,   178,   178,
     178,   178,   178,  -303,   178,   175,  -303,    61,   178,   174,
    -303,  -303,   216,   185,   206,  -303,  -303,  -303,  -303,  -303,
     217,   185,   212,  -303,  -303,  -303,  -303,   256,  -303,  -303,
    -303,   178,  -303,     3,   178,   178,   178,   178,   178,   178,
     178,   245,  -303,   283,   185,  -303,   178,   178,  -303,    75,
    -303,   252,   254,  -303,   156,  -303,  -303,  -303,  -303,  -303,
     289,   220,  -303,  -303,  -303,   178,   178,   178,   178,   178,
     178,   178,   178,  -303,  -303,    62,  -303,   178,  -303,  -303,
    -303,   790,  -303,  -303,  -303,  -303,  -303,   790,   790,   316,
     318,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,   264,   267,   269,   275,  -303,   174,  -303,
    -303,  -303,  -303,   276,   277,   790,   790,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,   178,    62,   278,  -303,    88,    47,
     292,   280,    88,    47,   244,   294,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,   178,  -303,   293,   174,    15,
     790,  -303,  -303,   187,   790,   178,  -303,   298,  -303,    61,
      63,  -303,  -303,  -303,   178,   174,  -303,   174,    16,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,   174,   790,
    -303,  -303,   790,   790,   100,  -303,  -303,  -303,  -303,   288,
      73,  -303,   790,  -303,  -303,   790,  -303,   340,    81,  -303,
    -303,   178,   342,  -303,  -303,  -303,   174,   157,   305,   618,
     790,  -303,   178,   178,   715,  -303,   790,   220,   790,   790,
     174,  -303,  -303,  -303,  -303,  -303,   344,  -303,    12,   790,
     790,  -303,  -303,   311,   210,   174,  -303,  -303,   270,   178,
     309,   384,  -303,   174,   174,  -303,  -303,   244,    20,   749,
      73,   790,   308,  -303,    64,  -303,  -303,    47,   178,    93,
    -303,   174,   223,  -303,  -303,   790,    73,   236,  -303,   178,
    -303,    12,  -303,  -303,    -7,   790,    47,   174,   349,  -303,
     618,  -303,    12,  -303,   749,   174,  -303,   790,    37,  -303,
    -303,    47,   310,   456,    73,  -303,    93,  -303,    38,    39,
     271,  -303,    12,  -303,   178,  -303,   178,  -303,  -303,   174,
    -303,  -303,  -303
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    12,     0,     0,   102,     0,    33,    74,
       0,     0,     0,     0,     0,     0,     0,    13,     0,     0,
       0,     0,     0,   210,   211,     0,    21,     0,     0,     0,
       0,     0,     0,   100,   101,     3,     4,     6,    64,    57,
       0,     5,     0,     0,    60,     0,     0,     0,   124,   125,
     126,   127,   128,   129,   130,   131,     0,     0,   169,   175,
       0,     0,     0,     0,    74,     0,    11,     7,     8,     9,
      10,     0,    33,    35,   204,   206,     0,    65,    74,    74,
     178,    37,    38,    39,   160,    74,    74,     0,     0,     0,
       0,     0,     0,   146,     0,     0,   165,   171,   172,   195,
     148,   140,     0,     0,     0,    23,    26,    25,   152,    14,
       0,     0,     0,   114,    22,    20,    19,     0,   156,   144,
     132,     0,   136,   168,     0,     0,     0,     0,     0,     0,
       0,     0,   164,     0,     0,   176,     0,     0,    74,     0,
      74,    63,     0,    48,     0,    68,    69,    70,    71,    72,
       0,    63,    49,    50,    51,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    52,   173,    53,     0,    55,    58,
      59,   209,    56,    74,   205,   207,   208,   198,   201,     0,
       0,    92,    91,    93,    94,    99,    95,    77,    74,    78,
      75,    79,    74,     0,    97,    96,    98,    74,    76,    81,
     188,    74,    74,     0,     0,   200,   202,    74,   162,   150,
     142,   154,   158,   134,     0,   174,     0,   212,     0,     0,
       0,     0,     0,     0,   116,    17,   135,    74,   161,   149,
     141,   153,   157,   145,   133,     0,    34,   215,    36,     0,
     197,   111,   108,   105,   104,     0,    74,     0,    74,    64,
       0,   170,    74,    74,     0,    66,    73,    64,     0,   139,
     143,   147,   151,   155,   159,   163,   166,   177,   196,   199,
      86,    87,   180,    89,     0,    84,    82,    83,    85,     0,
       0,    43,    40,    74,    74,   203,   138,     0,     0,   221,
     219,    30,     0,   220,   218,   119,   117,     0,     0,    63,
     167,   137,     0,     0,   182,   112,   109,    63,   103,   110,
      67,    74,   188,    80,    74,    88,     0,   186,     0,    41,
      42,   217,   213,     0,     0,    31,   216,   121,     0,    30,
       0,    63,    46,   107,   106,    74,   188,   116,     0,    44,
       0,    90,     0,   187,     0,   179,   214,    74,     0,    44,
     120,   118,     0,    18,    47,   184,     0,     0,    74,     0,
      62,     0,    74,    74,     0,    27,    74,    32,     0,   115,
      63,   188,     0,   121,    44,    45,   181,   189,   190,    24,
      29,    28,     0,    63,     0,   183,    44,    61,     0,     0,
       0,    16,     0,   113,     0,   193,     0,   191,   123,   122,
     185,   194,   192
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,     2,
      41,    -1,    11,    14,    90,  -221,     4,     0,  -303,  -133,
     122,   265,  -303,  -303,   -25,  -303,  -303,  -303,  -303,    42,
       5,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,   234,   366,  -303,  -303,  -303,  -303,  -303,  -268,
    -302,  -134,  -303,    92,  -303,    -6,  -303,   251,  -108,  -303,
    -303,  -303,  -303,  -303,  -303
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    35,    36,   298,   299,   117,    37,   220,   364,
     324,    81,    82,    83,    84,   360,   331,   332,    42,    43,
     151,   240,   274,   199,    44,    45,    46,   337,   224,   297,
     349,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,   200,   312,   336,   371,   318,
     280,   345,    61,   241,    62,    78,    63,    64,   218,    65,
      66,    67,    68,    69,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    41,    79,   222,    73,    85,    77,     6,   250,   109,
     340,    87,    39,    97,    99,    40,   133,   143,   258,   133,
     152,   153,   154,   144,     5,   379,   237,   144,   133,    72,
     123,   163,   164,    71,   356,   166,   168,   169,   170,   133,
     172,   179,   180,   181,   182,   183,   184,   185,   186,     5,
       5,     5,   187,    33,    72,    72,    72,   302,   165,    34,
     227,     6,   189,   155,   207,   173,     5,   136,   190,   384,
     144,    72,   361,   191,   133,   133,   311,   133,   343,   198,
     358,     6,   145,   146,   147,   148,   149,     5,   372,   135,
     267,   192,    72,   388,   193,   389,   156,   215,   194,   195,
     196,   197,     6,    96,   394,   396,   100,    33,   101,   114,
     110,   108,    86,    34,   111,   157,   392,   118,   119,   120,
     122,   363,   132,   167,   150,     5,   242,    33,   369,   316,
      72,   317,   322,    34,   359,   238,   239,   115,   243,   112,
     249,   105,   158,   255,   288,   159,   116,   323,    33,   368,
     257,   113,   -37,   387,    34,   313,   314,   133,   -38,   102,
     106,   134,   121,   103,   160,   393,   268,   161,     5,   107,
     198,   254,   135,    72,   338,   162,   198,   198,   208,   209,
     210,   211,   212,   -37,   213,   136,   -37,   133,   104,   -38,
       5,   137,   -38,   289,   290,    72,   303,   293,   294,   174,
     133,   -37,   -37,   -37,   198,   198,   175,   -38,   -38,   -38,
     201,   226,   327,   328,   228,   229,   230,   231,   232,   233,
     234,   176,   138,   296,   214,   139,     5,   376,   202,   203,
     204,    72,     5,   216,   221,   245,   217,    72,   385,   198,
     140,   141,   142,   198,    77,   259,   260,   261,   262,   263,
     264,   265,   266,   310,   395,   397,     5,   219,   400,   295,
     401,    72,   402,   223,     5,   347,   348,   245,   198,    72,
     246,   198,   198,   225,    80,    74,    75,    76,   370,   348,
      14,   198,     5,     5,   198,   350,   398,    72,    72,   279,
     325,   373,   328,   281,   235,    23,    24,   247,    38,   198,
     236,   333,   334,   198,   286,   198,   257,   198,   198,   248,
      39,   253,   256,    40,    74,    75,    76,   344,   198,   198,
     270,   275,   366,   271,   276,   301,   277,   351,   325,   171,
      38,   354,   278,   283,   284,   287,   296,   292,   198,   380,
     198,   366,    39,   177,   178,    40,   291,   367,   -15,   288,
     205,   206,   305,   315,   198,   321,   380,   326,   375,   329,
     344,   342,   346,   113,   198,   362,   382,   390,   381,    38,
     352,   344,   307,   198,   383,   251,   198,   198,   386,   357,
      98,    39,    38,   354,    40,     0,     0,   344,   344,   399,
       4,   344,   252,   344,    39,   344,     5,    40,     6,     7,
       0,     8,     9,     0,     0,   244,     0,     0,    10,    11,
      12,    13,    14,    15,    16,     0,   353,     0,     0,    18,
       0,     0,    21,     0,     0,     0,     0,    23,    24,   330,
       0,    27,    28,    29,    30,     0,    31,    32,   269,     0,
       5,     0,     0,     0,    33,    72,     0,     0,     0,     0,
      34,     0,    88,   272,     0,     0,     0,   273,    89,     0,
       0,     0,     4,    90,     0,     0,    91,   282,     5,     0,
       6,     7,   285,     8,     9,    92,    93,    94,    95,     0,
      10,    11,    12,    13,    14,    15,    16,     0,   391,     0,
       0,    18,   300,     0,    21,     0,     0,     0,     0,    23,
      24,   330,     5,    27,    28,    29,    30,    72,    31,    32,
       0,   304,     0,   306,   124,     0,    33,   308,   309,     0,
     125,     0,    34,     0,     0,   126,     0,     0,   127,     0,
       0,     0,     0,     0,     0,     0,     0,   128,   129,   130,
     131,     0,     0,     0,     0,     2,     3,     0,   319,   320,
       0,     4,   -63,     0,     0,     0,     0,     5,     0,     6,
       7,     0,     8,     9,   -63,   -63,   -63,   -63,   -63,    10,
      11,    12,    13,    14,    15,    16,   339,     0,    17,   341,
      18,    19,    20,    21,     0,    22,     0,     0,    23,    24,
      25,    26,    27,    28,    29,    30,     0,    31,    32,     0,
     355,     0,     0,     0,     0,    33,   -63,     0,     0,     0,
       0,    34,   365,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   374,     4,     0,     0,   377,   378,     0,
       5,   365,     6,     7,     0,     8,     9,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,     0,
       0,     0,     0,    18,     0,     0,    21,     0,     0,     0,
       0,    23,    24,   330,     0,    27,    28,    29,    30,     0,
      31,    32,     0,     0,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,    34,   179,   180,   181,   182,   183,
     184,   185,   186,     5,     0,     0,   187,   188,    72,     0,
       0,     0,     0,     0,     0,     0,   189,     0,     0,     0,
       0,     0,   190,     0,     0,     0,     0,   191,     0,   179,
     180,   181,   182,   183,   184,   185,   186,     5,     0,     0,
     187,   335,    72,     0,     0,   192,     0,     0,   193,     0,
     189,     0,   194,   195,   196,   197,   190,     0,     0,     0,
       0,   191,     0,   179,   180,   181,   182,   183,   184,   185,
     186,     5,     0,     0,   187,     0,    72,     0,     0,   192,
       0,     0,   193,     0,   189,     0,   194,   195,   196,   197,
     190,     0,     0,     0,     0,   191,     0,     0,     0,     0,
     359,     0,     0,     0,   179,   180,   181,   182,   183,   184,
     185,   186,     5,   192,     0,   187,   193,    72,     0,     0,
     194,   195,   196,   197,     0,   189,     0,     0,     0,     0,
       0,   190,     0,     0,     0,     0,   191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,     0,     0,   193,     0,     0,
       0,   194,   195,   196,   197
};

static const yytype_int16 yycheck[] =
{
       1,     1,     8,   111,     5,    11,     7,    14,   141,    51,
     312,    12,     1,    14,    15,     1,    13,    42,   151,    13,
      45,    46,    47,     7,    12,    32,   134,     7,    13,    17,
      31,    56,    57,    15,   336,    60,    61,    62,    63,    13,
      65,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      12,    12,    15,    60,    17,    17,    17,    42,    59,    66,
      57,    14,    25,    56,    58,    71,    12,    41,    31,   371,
       7,    17,   340,    36,    13,    13,    60,    13,    66,    80,
      60,    14,    19,    20,    21,    22,    23,    12,   356,    28,
      28,    54,    17,    56,    57,    58,    56,    98,    61,    62,
      63,    64,    14,    13,    66,    66,    16,    60,    18,     8,
      13,    21,    58,    66,    17,    56,   384,    27,    28,    29,
      30,    57,    32,    56,    61,    12,    51,    60,   349,    56,
      17,    58,    51,    66,    41,   136,   137,    36,   139,    42,
     141,    17,    56,   144,    56,    56,    45,    66,    60,    56,
     151,    54,     8,   374,    66,    55,    56,    13,     8,    13,
      36,    17,    49,    17,    56,   386,   167,    56,    12,    45,
     171,    15,    28,    17,   307,    56,   177,   178,    88,    89,
      90,    91,    92,    39,    94,    41,    42,    13,    42,    39,
      12,     8,    42,   218,   219,    17,     9,   222,   223,    57,
      13,    57,    58,    59,   205,   206,    57,    57,    58,    59,
      39,   121,    55,    56,   124,   125,   126,   127,   128,   129,
     130,    57,    39,   224,    49,    42,    12,   361,    57,    58,
      59,    17,    12,    17,    17,    15,    51,    17,   372,   240,
      57,    58,    59,   244,   245,   155,   156,   157,   158,   159,
     160,   161,   162,   254,   388,   389,    12,    51,   392,    15,
     394,    17,   396,    51,    12,    55,    56,    15,   269,    17,
      18,   272,   273,    17,     9,    61,    62,    63,    55,    56,
      28,   282,    12,    12,   285,    15,    15,    17,    17,   197,
     291,    55,    56,   201,    49,    43,    44,    45,   299,   300,
      17,   302,   303,   304,   214,   306,   307,   308,   309,    57,
     299,    57,    23,   299,    61,    62,    63,   318,   319,   320,
       4,    57,   347,     5,    57,   235,    57,   328,   329,    64,
     331,   331,    57,    57,    57,    57,   337,    57,   339,   364,
     341,   366,   331,    78,    79,   331,    54,   348,    54,    56,
      85,    86,    54,    65,   355,    15,   381,    15,   359,    54,
     361,    17,    51,    54,   365,    57,    17,    57,   366,   370,
     329,   372,   250,   374,   370,   141,   377,   378,   373,   337,
      14,   370,   383,   383,   370,    -1,    -1,   388,   389,   390,
       6,   392,   141,   394,   383,   396,    12,   383,    14,    15,
      -1,    17,    18,    -1,    -1,   140,    -1,    -1,    24,    25,
      26,    27,    28,    29,    30,    -1,    32,    -1,    -1,    35,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,
      -1,    47,    48,    49,    50,    -1,    52,    53,   173,    -1,
      12,    -1,    -1,    -1,    60,    17,    -1,    -1,    -1,    -1,
      66,    -1,    24,   188,    -1,    -1,    -1,   192,    30,    -1,
      -1,    -1,     6,    35,    -1,    -1,    38,   202,    12,    -1,
      14,    15,   207,    17,    18,    47,    48,    49,    50,    -1,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    35,   227,    -1,    38,    -1,    -1,    -1,    -1,    43,
      44,    45,    12,    47,    48,    49,    50,    17,    52,    53,
      -1,   246,    -1,   248,    24,    -1,    60,   252,   253,    -1,
      30,    -1,    66,    -1,    -1,    35,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,     0,     1,    -1,   283,   284,
      -1,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,    14,
      15,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,   311,    -1,    33,   314,
      35,    36,    37,    38,    -1,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    52,    53,    -1,
     335,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    66,   347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   358,     6,    -1,    -1,   362,   363,    -1,
      12,   366,    14,    15,    -1,    17,    18,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    43,    44,    45,    -1,    47,    48,    49,    50,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    66,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    36,    -1,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
      15,    16,    17,    -1,    -1,    54,    -1,    -1,    57,    -1,
      25,    -1,    61,    62,    63,    64,    31,    -1,    -1,    -1,
      -1,    36,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    15,    -1,    17,    -1,    -1,    54,
      -1,    -1,    57,    -1,    25,    -1,    61,    62,    63,    64,
      31,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    54,    -1,    15,    57,    17,    -1,    -1,
      61,    62,    63,    64,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    -1,    -1,
      -1,    61,    62,    63,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    68,     0,     1,     6,    12,    14,    15,    17,    18,
      24,    25,    26,    27,    28,    29,    30,    33,    35,    36,
      37,    38,    40,    43,    44,    45,    46,    47,    48,    49,
      50,    52,    53,    60,    66,    69,    70,    74,    78,    79,
      80,    84,    85,    86,    91,    92,    93,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   119,   121,   123,   124,   126,   127,   128,   129,   130,
     131,    15,    17,    78,    61,    62,    63,    78,   122,   122,
      88,    78,    79,    80,    81,   122,    58,    78,    24,    30,
      35,    38,    47,    48,    49,    50,    81,    78,   110,    78,
      81,    81,    13,    17,    42,    17,    36,    45,    81,    51,
      13,    17,    42,    54,     8,    36,    45,    73,    81,    81,
      81,    49,    81,    78,    24,    30,    35,    38,    47,    48,
      49,    50,    81,    13,    17,    28,    41,     8,    39,    42,
      57,    58,    59,    91,     7,    19,    20,    21,    22,    23,
      61,    87,    91,    91,    91,    56,    56,    56,    56,    56,
      56,    56,    56,    91,    91,    78,    91,    56,    91,    91,
      91,    88,    91,   122,    57,    57,    57,    88,    88,     4,
       5,     6,     7,     8,     9,    10,    11,    15,    16,    25,
      31,    36,    54,    57,    61,    62,    63,    64,    78,    90,
     112,    39,    57,    58,    59,    88,    88,    58,    81,    81,
      81,    81,    81,    81,    49,    78,    17,    51,   125,    51,
      75,    17,   125,    51,    95,    17,    81,    57,    81,    81,
      81,    81,    81,    81,    81,    49,    17,   125,    78,    78,
      88,   120,    51,    78,    88,    15,    18,    45,    57,    78,
      86,   109,   124,    57,    15,    78,    23,    78,    86,    81,
      81,    81,    81,    81,    81,    81,    81,    28,    78,    88,
       4,     5,    88,    88,    89,    57,    57,    57,    57,   120,
     117,   120,    88,    57,    57,    88,    81,    57,    56,    91,
      91,    54,    57,    91,    91,    15,    78,    96,    71,    72,
      88,    81,    42,     9,    88,    54,    88,    87,    88,    88,
      78,    60,   113,    55,    56,    65,    56,    58,   116,    88,
      88,    15,    51,    66,    77,    78,    15,    55,    56,    54,
      45,    83,    84,    78,    78,    16,   114,    94,    86,    88,
     117,    88,    17,    66,    78,   118,    51,    55,    56,    97,
      15,    78,    77,    32,    84,    88,   117,    96,    60,    41,
      82,   116,    57,    57,    76,    88,    91,    78,    56,    82,
      55,   115,   116,    55,    88,    78,   118,    88,    88,    32,
      91,    76,    17,    83,   117,   118,    97,    82,    56,    58,
      57,    32,   116,    82,    66,   118,    66,   118,    15,    78,
     118,   118,   118
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    71,    70,    72,    70,    70,
      70,    73,    73,    75,    74,    74,    74,    76,    76,    76,
      77,    77,    77,    78,    78,    78,    79,    80,    80,    81,
      81,    81,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    87,    87,
      87,    87,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    89,
      89,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    94,    93,    95,    93,    96,    96,    96,    96,
      96,    97,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    98,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   100,   100,   101,   101,   101,   101,   102,   102,
     102,   102,   103,   103,   103,   103,   104,   104,   104,   104,
     105,   105,   105,   105,   106,   106,   106,   107,   107,   108,
     108,   109,   109,   109,   109,   109,   110,   110,   112,   111,
     113,   111,   114,   111,   115,   111,   116,   116,   117,   117,
     118,   118,   118,   118,   118,   119,   119,   120,   121,   121,
     121,   121,   121,   121,   122,   122,   122,   122,   122,   123,
     124,   124,   125,   125,   125,   126,   127,   127,   128,   129,
     130,   131
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     0,     9,     0,     6,     2,
       2,     0,     1,     0,     8,     2,     2,     1,     2,     2,
       0,     1,     3,     1,     3,     2,     3,     1,     1,     1,
       3,     4,     4,     3,     0,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     2,
       1,     8,     6,     0,     1,     2,     3,     4,     1,     1,
       1,     1,     1,     2,     0,     2,     2,     2,     2,     2,
       4,     2,     3,     3,     3,     3,     3,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     3,     5,     5,     3,     4,
       4,     3,     0,     9,     0,     7,     0,     1,     3,     1,
       3,     0,     5,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     3,     3,     2,     4,     4,     3,
       2,     3,     3,     3,     2,     3,     2,     3,     2,     3,
       3,     3,     2,     3,     3,     3,     2,     3,     3,     3,
       2,     3,     3,     3,     2,     2,     3,     4,     2,     1,
       3,     2,     2,     2,     3,     1,     2,     3,     0,     6,
       0,     8,     0,     8,     0,    10,     1,     2,     0,     5,
       3,     5,     6,     5,     6,     2,     3,     1,     3,     4,
       3,     3,     3,     4,     1,     2,     1,     2,     2,     2,
       1,     1,     1,     3,     4,     3,     5,     5,     4,     4,
       4,     4
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
#line 153 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1695 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 154 "antimony.ypp" /* yacc.c:1646  */
    { /*cout << endl << $2->ToString() << endl << endl;*/ }
#line 1701 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 155 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1707 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 156 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1713 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 157 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1719 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 158 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1725 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 159 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1731 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 160 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1737 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 161 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1743 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 162 "antimony.ypp" /* yacc.c:1646  */
    {YYABORT;}
#line 1749 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 163 "antimony.ypp" /* yacc.c:1646  */
    {YYABORT;}
#line 1755 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 166 "antimony.ypp" /* yacc.c:1646  */
    { if (g_registry.OpenFile(*((yyvsp[0].word)))==0) YYABORT;}
#line 1761 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 184 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.NewCurrentModule((yyvsp[0].word), NULL, (yyvsp[-1].maybemain));}
#line 1767 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 185 "antimony.ypp" /* yacc.c:1646  */
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 1777 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 190 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.NewCurrentModule((yyvsp[0].word), NULL, (yyvsp[-1].maybemain));}
#line 1783 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 191 "antimony.ypp" /* yacc.c:1646  */
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 1793 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 196 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("module '" + *((yyvsp[0].word)) + "' already defined."); YYABORT;}
#line 1799 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 197 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a module because it is already a defined function."); YYABORT;}
#line 1805 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 200 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.maybemain) = false;}
#line 1811 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 201 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.maybemain) = true;}
#line 1817 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 204 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.NewUserFunction((yyvsp[0].word));}
#line 1823 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 204 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetUserFunction((yyvsp[-1].formula))) YYABORT;}
#line 1829 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 205 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Cannot use '" + *((yyvsp[0].word)) +"' as a function name because it is already the name of a module."); YYABORT;}
#line 1835 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 206 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a new function because it is already a defined function."); YYABORT;}
#line 1841 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 209 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[0].formula);}
#line 1847 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 210 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[0].formula);}
#line 1853 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 211 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula);}
#line 1859 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 221 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1865 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 222 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 1871 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 223 "antimony.ypp" /* yacc.c:1646  */
    { if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 1877 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 226 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[0].word)); }
#line 1883 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 227 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-2].variable)->GetSubVariable((yyvsp[0].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[0].word)) + "' is not a subvariable of '" + (yyvsp[-2].variable)->GetNameDelimitedBy(".") + "'.");
                    YYABORT;
                  }
                }
#line 1894 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 233 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;}
#line 1900 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 236 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetCompartment((yyvsp[0].variable))) YYABORT; (yyval.variable) = (yyvsp[-2].variable);}
#line 1906 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 239 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable);}
#line 1912 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 240 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable);}
#line 1918 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 243 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable);}
#line 1924 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 244 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 1930 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 245 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT; }
#line 1936 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 246 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT; }
#line 1942 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 247 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 1948 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 250 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = NULL;}
#line 1954 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 251 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable);}
#line 1960 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 254 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1966 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 255 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1972 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 258 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1978 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 259 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1984 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 260 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1990 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 261 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1996 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 262 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2002 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 263 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2008 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 264 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2014 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 265 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2020 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 266 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2026 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 267 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2032 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 268 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2038 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 269 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2044 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 270 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2050 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 274 "antimony.ypp" /* yacc.c:1646  */
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-7].variable));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-7].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2062 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 282 "antimony.ypp" /* yacc.c:1646  */
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2074 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 291 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); }
#line 2080 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 292 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[0].variable)); }
#line 2086 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 293 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num)); }
#line 2092 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 294 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactantList) = (yyvsp[-2].reactantList); (yyvsp[-2].reactantList)->AddReactant((yyvsp[0].variable)); }
#line 2098 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 295 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactantList) = (yyvsp[-3].reactantList); (yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num)); }
#line 2104 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 299 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdBecomes;}
#line 2110 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 300 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdInhibits;}
#line 2116 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 301 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdInfluences;}
#line 2122 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 302 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdInfluences;}
#line 2128 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 304 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdBecomesIrreversibly;}
#line 2134 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 305 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdBecomes;}
#line 2140 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 308 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = g_registry.NewBlankFormula(); }
#line 2146 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 309 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddEllipses();}
#line 2152 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 310 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddVariable((yyvsp[0].variable)); }
#line 2158 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 311 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddNum((yyvsp[0].num)); }
#line 2164 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 312 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2170 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 313 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2176 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 314 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2182 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 315 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddMathThing((yyvsp[0].character)); }
#line 2188 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 316 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('<'); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2194 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 317 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('>'); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2200 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 318 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('='); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2206 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 319 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('!'); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2212 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 320 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('&'); (yyvsp[-2].formula)->AddMathThing('&'); }
#line 2218 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 321 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('|'); (yyvsp[-2].formula)->AddMathThing('|'); }
#line 2224 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 323 "antimony.ypp" /* yacc.c:1646  */
    {
                  //Need to create a variable to be this unit definition, or find one that already has this unit definition, and then use that name.
                  (yyval.formula) = (yyvsp[-3].formula);
                  (yyval.formula)->AddVariable((yyvsp[-1].variable));
                }
#line 2234 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 330 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[0].formula);}
#line 2240 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 331 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[0].formula)); }
#line 2246 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 334 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '+';}
#line 2252 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 335 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '-';}
#line 2258 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 336 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '*';}
#line 2264 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 337 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '/';}
#line 2270 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 338 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '^';}
#line 2276 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 339 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '>';}
#line 2282 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 340 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '<';}
#line 2288 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 341 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '!';}
#line 2294 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 342 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '%';}
#line 2300 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 345 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2306 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 346 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2312 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 347 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2318 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 350 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddObjective((yyvsp[-3].variable), (yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 2324 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 351 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2330 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 352 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->Synchronize((yyvsp[0].variable), NULL)) YYABORT;}
#line 2336 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 353 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[-2].variable), (yyvsp[0].variable))) YYABORT;}
#line 2342 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 354 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[0].variable), (yyvsp[-2].variable))) YYABORT;}
#line 2348 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 355 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetDisplayName(*((yyvsp[0].word)))) YYABORT;}
#line 2354 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 356 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT;}
#line 2360 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 357 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT;}
#line 2366 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 358 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2372 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 362 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-3].variable)->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2378 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 362 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[0].variable) != NULL) {if ((yyvsp[-8].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2384 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 363 "antimony.ypp" /* yacc.c:1646  */
    {if(g_registry.CurrentModule()->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2390 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 363 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[0].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2396 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 367 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2402 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 368 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2408 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 369 "antimony.ypp" /* yacc.c:1646  */
    { if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2414 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 370 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2420 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 371 "antimony.ypp" /* yacc.c:1646  */
    { if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2426 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 375 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2432 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 376 "antimony.ypp" /* yacc.c:1646  */
    {if (CaselessStrCmp(*(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].variable));}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2440 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 380 "antimony.ypp" /* yacc.c:1646  */
    {if (CaselessStrCmp(*(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].num));}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2448 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 384 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2454 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 385 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2460 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 386 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2466 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 387 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2472 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 388 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2478 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 389 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2484 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 391 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2490 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 392 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2496 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 395 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2502 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 396 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2508 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 397 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2514 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 398 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2520 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 399 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2526 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 400 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2532 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 401 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2538 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 402 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2544 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 405 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2550 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 406 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2556 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 407 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2562 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 408 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2568 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 411 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 2574 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 412 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 2580 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 413 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; }
#line 2586 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 414 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 2592 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 417 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 2598 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 418 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 2604 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 419 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 2610 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 420 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 2616 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 423 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 2622 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 424 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 2628 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 425 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Genes may not be set 'const'."); YYABORT; }
#line 2634 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 426 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 2640 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 429 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 2646 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 430 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 2652 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 431 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 2658 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 432 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 2664 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 436 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 2670 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 437 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 2676 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 438 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 2682 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 439 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 2688 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 442 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst();}
#line 2694 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 443 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst();}
#line 2700 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 444 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst();}
#line 2706 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 447 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetType(varUnitDefinition)) YYABORT;
                                               if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                                               if ((yyvsp[-2].variable)->GetUnitDef()->SetFromFormula((yyvsp[0].formula))) YYABORT;}
#line 2714 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 450 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[0].variable)->SetType(varUnitDefinition)) YYABORT;}
#line 2720 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 453 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SaveWorkingStrand()) YYABORT;}
#line 2726 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 454 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetStrandAs((yyvsp[-2].variable))) YYABORT;}
#line 2732 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 457 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewUpstreamOpen((yyvsp[0].variable))) YYABORT;}
#line 2738 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 458 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetOpenUpstream(); }
#line 2744 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 459 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 2750 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 460 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 2756 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 461 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2762 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 464 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 2768 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 465 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 2774 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 468 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula))) YYABORT;}
#line 2780 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 468 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2786 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 469 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula))) YYABORT;}
#line 2792 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 469 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2798 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 470 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula), (yyvsp[-3].variable))) YYABORT;}
#line 2804 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 470 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2810 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 471 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula), (yyvsp[-5].variable))) YYABORT;}
#line 2816 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 471 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2822 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 474 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2828 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 475 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2834 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 478 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2840 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 479 "antimony.ypp" /* yacc.c:1646  */
    {if (CaselessStrCmp(*(yyvsp[-2].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[0].formula));}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[0].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;}}
#line 2850 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 486 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 2856 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 487 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 2862 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 488 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 2868 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 489 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 2874 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 490 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 2880 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 493 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 2886 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 494 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 2892 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 497 "antimony.ypp" /* yacc.c:1646  */
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
#line 2910 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 512 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 2916 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 513 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint(-(yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 2922 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 514 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 2928 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 515 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 2934 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 516 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[0].formula))) YYABORT;}
#line 2940 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 517 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 2946 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 520 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constLT;}
#line 2952 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 521 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constLEQ;}
#line 2958 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 522 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constGT;}
#line 2964 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 523 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constGEQ;}
#line 2970 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 524 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constNEQ;}
#line 2976 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 527 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddObjective((yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 2982 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 530 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.maxormin) = true;}
#line 2988 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 531 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.maxormin) = false;}
#line 2994 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 534 "antimony.ypp" /* yacc.c:1646  */
    { (yyval.stringlist) = new std::vector<std::string>(); (yyval.stringlist)->push_back(*((yyvsp[0].word))); }
#line 3000 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 535 "antimony.ypp" /* yacc.c:1646  */
    { (yyval.stringlist) = (yyvsp[-2].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3006 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 536 "antimony.ypp" /* yacc.c:1646  */
    { (yyval.stringlist) = (yyvsp[-3].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3012 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 543 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->ProcessCVTerm((yyvsp[-2].variable),(yyvsp[-1].word),(yyvsp[0].stringlist))) YYABORT;}
#line 3018 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 547 "antimony.ypp" /* yacc.c:1646  */
    { Module* module = g_registry.GetModule(*(yyvsp[-4].word));
                    if (module && (yyvsp[-2].word) && *((yyvsp[-2].word)) == "sboTerm") {
                      module->SetSBOTerm((yyvsp[0].num));
                    }
                  }
#line 3028 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 554 "antimony.ypp" /* yacc.c:1646  */
    { Module* function = g_registry.GetModule(*(yyvsp[-4].word));
                    if (function && (yyvsp[-2].word) && *((yyvsp[-2].word)) == "sboTerm") {
                      function->SetSBOTerm((yyvsp[0].num));
                    }
                  }
#line 3038 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 562 "antimony.ypp" /* yacc.c:1646  */
    { Module* module = g_registry.GetModule(*(yyvsp[-3].word));
                  if (module && (yyvsp[-1].word)) {
                    module->SetDisplayName(*(yyvsp[-1].word));
                  }
                }
#line 3048 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 568 "antimony.ypp" /* yacc.c:1646  */
    { Module* function = g_registry.GetModule(*(yyvsp[-3].word));
                  if (function && (yyvsp[-1].word)) {
                    function->SetDisplayName(*(yyvsp[-1].word));
                  }
                }
#line 3058 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 575 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3064 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 576 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3070 "antimony.tab.cpp" /* yacc.c:1646  */
    break;


#line 3074 "antimony.tab.cpp" /* yacc.c:1646  */
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
#line 578 "antimony.ypp" /* yacc.c:1906  */



void antimony_yyerror(char const *s)
{
  if (g_registry.GetError()=="") {
    g_registry.SetError(s);
  }
}

void putback_string(const string& s)
{
  for(unsigned int i=s.size(); i>0; --i)
    g_registry.input->putback(s.at(i-1));
}

bool is_whitespace(const char cc)
{
  if (cc == '\r' || cc == '\n' || cc == ' ' || cc == '\t')
    return true;
  else
    return false;
}

string eat_whitespace()
{
  char cc = 0;
  g_registry.input->get(cc);
  string result;
  while (is_whitespace(cc) && !g_registry.input->eof()) {
    result += cc;
    g_registry.input->get(cc);
  }
  g_registry.input->unget();
  return result;
}

// consumes everything up to and including the eol (win and unix supported)
string consume_rest_of_line()
{
  char cc = 0;
  string result;
  while (!g_registry.input->eof()) {
    g_registry.input->get(cc);
    if (cc == '\r') {
      g_registry.input->get(cc);
      if (cc != '\n') {
        g_registry.input->unget();
      }
      cc = '\n';
    }
    result += cc;
    if (cc == '\n') {
      return result;
    }
  }
  return result;
}

string eat_whitespace_and_comments()
{
  char cc = 0;
  g_registry.input->get(cc);
  string result;
  while ((is_whitespace(cc) || cc == '/' || cc == '#')&& !g_registry.input->eof()) {
    result += cc;
    if (cc == '/') {
      if (g_registry.input->peek() == '/') {
        result += consume_rest_of_line();
        g_registry.input->get(cc);
      } else {
        g_registry.input->unget();
        return result;
      }
    } else if (cc == '#') {
      result += consume_rest_of_line();
      g_registry.input->get(cc);
    } else
      g_registry.input->get(cc);
  }
  g_registry.input->unget();
  return result;
}

int count_newlines_in(const string& s)
{
  int result=0;
  for(string::const_iterator i(s.begin()); i!=s.end(); ++i) {
    if (*i == '\r' || *i == '\n')
      ++result;
  }
  return result;
}

bool is_word_char(const char cc)
{
  if (cc > 0 && (isalpha(cc) || isdigit(cc) || cc == '_'))
    return true;
  else
    return false;
}

// bool is_numeric_char(const char cc)
// {
//   if (cc > 0 && '0' <= cc && cc <= '9')
//     return true;
//   else
//     return false;
// }

// bool is_word_or_numeric_char(const char cc)
// {
//   if (is_word_char(cc) || is_numeric_char(cc))
//     return true;
//   else
//     return false;
// }

// check if it is a valid predicate (e.g.
bool is_valid_prefixed_predicate(const string& prefix, const string& uri)
{
  bool uri_is_numeric = IsNumeric(uri);
  if (CaselessStrCmp(prefix, "bqb")) {
    if (Annotated::isBiomodelsQual(uri))
      return true;
    else
      return false;
  } else if (CaselessStrCmp(prefix, "bqm")) {
    if (Annotated::isBiomodelsQual(uri))
      return true;
    else
      return false;
  } else if (g_registry.IsRegisteredPrefix(prefix))
    // if the prefix is defined it's okay
    return true;
  else
    return false;
}

string make_biomodels_qual_full_uri(const string& predicate)
{
  stringstream ss;
  if (Annotated::DecodeBiolQualifier(predicate) != BQB_UNKNOWN) {
    ss << "https://biomodels.net/biology-qualifiers/" << Annotated::EncodeBiolQualifier(Annotated::DecodeBiolQualifier(predicate));
    return ss.str();
  } else if (Annotated::DecodeModelQualifier(predicate) != BQM_UNKNOWN) {
    ss << "http://biomodels.net/model-qualifiers/" << Annotated::EncodeModelQualifier(Annotated::DecodeModelQualifier(predicate));
    return ss.str();
  } else
    return "";
}

pair<int,string> make_builtin_prefixed_predicate_uri(const string& prefix, const string& predicate)
{
  stringstream ss;
  if (CaselessStrCmp(prefix, "bqb") && Annotated::DecodeModelQualifier(predicate) != BQM_UNKNOWN) {
    ss << "http://biomodels.net/model-qualifiers/" << Annotated::EncodeModelQualifier(Annotated::DecodeModelQualifier(predicate));
    return make_pair(0,ss.str());
  } else if (CaselessStrCmp(prefix, "bqm") && Annotated::DecodeBiolQualifier(predicate) != BQB_UNKNOWN) {
    ss << "https://biomodels.net/biology-qualifiers/" << Annotated::EncodeBiolQualifier(Annotated::DecodeBiolQualifier(predicate));
    return make_pair(0,ss.str());
  } else
    return make_pair(1,"");
}

class PredicateResult
{
public:
  // error condition
  PredicateResult(int e)
    : m_e(e) {}

  // success condition
  PredicateResult(int e, string parsed, string predicate)
    : m_e(e), m_parsed(parsed), m_predicate(predicate) {}

  int getErrorCode() const {
    return m_e;
  }

  const string& getParsedText() const {
    return m_parsed;
  }

  const string& getPredicateAbsoluteURI() const {
    return m_predicate;
  }

  int m_e;
  string m_parsed;
  string m_predicate;
};

// returns zero if it matches a predicate, non-zero otherwise (and puts back everything it read in the latter)
PredicateResult try_parse_predicate()
{
//   cerr << "    try_parse_predicate\n";
  char cc = 0;
  g_registry.input->get(cc);
//   cerr << "    cc " << cc << "\n";
//   cerr << "      " << cc << "\n";
  // first check if it's a built-in predicate (the biomodels quals) or prefixed predicate
  if (cc > 0 && (isalpha(cc) || cc == '_')) {
    string first_word;
    while (is_word_char(cc) && !g_registry.input->eof()) {
      first_word += cc;
      g_registry.input->get(cc);
    }
//     cerr << "    pred " << first_word << "\n";

    // is a prefixed uri?
    if (cc != ':') {
      g_registry.input->unget();
      // is a built-in biomodels qual?
      if (Annotated::isBiomodelsQual(first_word)) {
        string uri = make_biomodels_qual_full_uri(first_word);
        if (uri == "") {
          putback_string(first_word);
          return PredicateResult(1);
        }
        return PredicateResult(0, first_word, uri);
      } else {
        putback_string(first_word);
        return PredicateResult(2);
      }
    }

    // check the prefixed uri
    string second_word;
    g_registry.input->get(cc);
    while (is_word_char(cc) && !g_registry.input->eof()) {
      second_word += cc;
      g_registry.input->get(cc);
    }
    g_registry.input->unget();

    pair<int,string> prefixed_result = make_builtin_prefixed_predicate_uri(first_word, second_word);
    if (!prefixed_result.first) {
      return PredicateResult(0, first_word+":"+second_word, prefixed_result.second);
    } else {
      putback_string(first_word+":"+second_word);
      return PredicateResult(3);
    }
  } else if (cc == '<') {
    // it could be an absolute uri
    string uri;
    while (!is_whitespace(cc) && cc != '>' && !g_registry.input->eof()) {
      uri += cc;
      g_registry.input->get(cc);
    }
    if (cc == '>')
      // it is an absolute uri
      return PredicateResult(0,"<"+uri+">",uri);
    else {
      // it's not an absolute uri
      // we don't know what it is so put everything back
      g_registry.input->unget();
      putback_string("<"+uri);
      return PredicateResult(4);
    }
  } else {
    g_registry.input->unget();
    return PredicateResult(5);
  }
}

class ObjectResult
{
public:
  // error condition
  ObjectResult(int e)
    : m_e(e) {}

  ObjectResult(int e, string parsed, string uri)
    : m_e(e), m_parsed(parsed) {
      m_uris.push_back(uri);
    }

  ObjectResult(int e, string parsed, const vector<string> uris)
    : m_e(e), m_parsed(parsed), m_uris(uris) {}

  ObjectResult combine(const ObjectResult& other) const {
    if (other.m_e)
      // error in second operand, don't combine it
      return *this;
    else {
      vector<string> uris(m_uris);
      uris.insert(uris.end(), other.m_uris.begin(), other.m_uris.end());
      return ObjectResult(m_e, m_parsed+other.m_parsed, uris);
    }
  }

  int getErrorCode() const {
    return m_e;
  }

  const string& getParsedText() const {
    return m_parsed;
  }

  const vector<string>& geAbsoluteURIs() const {
    return m_uris;
  }

  int m_e;
  string m_parsed;
  vector<string> m_uris;
};


// check if it is a valid ontology term uri
pair<int,string> make_builtin_prefixed_ontology_uri(const string& prefix, const string& term)
{
  bool term_is_numeric = IsNumeric(term);
  stringstream ss;
  if (CaselessStrCmp(prefix, "ChEBI") && term_is_numeric) {
    ss << "https://identifiers.org/chebi/CHEBI:" << term;
    return make_pair(0,ss.str());
  } else if (CaselessStrCmp(prefix, "GO") && term_is_numeric) {
    ss << "https://identifiers.org/obo.go/GO:" << term;
    return make_pair(0,ss.str());
  } else if (CaselessStrCmp(prefix, "FMA") && term_is_numeric) {
    ss << "https://identifiers.org/fma/FMA:" << term;
    return make_pair(0,ss.str());
  } else if (CaselessStrCmp(prefix, "OPB") && term_is_numeric) {
    ss << "https://identifiers.org/opb/OPB_" << term;
    return make_pair(0,ss.str());
  } else if (g_registry.IsRegisteredPrefix(prefix) && term_is_numeric) {
    return make_pair(0,g_registry.GetUriForPrefix(prefix));
  } else
    return make_pair(1,"");
}

ObjectResult try_parse_object()
{
//   cerr << "      try_parse_object\n";
  char cc = 0;
  string ws = eat_whitespace();
  g_registry.input->get(cc);
  // first check if it's a built-in predicate (the biomodels quals) or prefixed predicate
  if (cc > 0 && (isalpha(cc) || cc == '_')) {
    string first_word;
    while (is_word_char(cc) && !g_registry.input->eof()) {
      first_word += cc;
      g_registry.input->get(cc);
    }

    // is a prefixed uri?
    if (cc != ':' || g_registry.input->eof()) {
      // not a prefixed uri
      // is it a module, function, or variable name?
      Module* module = g_registry.GetModule(first_word);
      Module* current_module = g_registry.CurrentModule();
      Variable* var=NULL;
      if (current_module) {
        vector<string> fullname;
        fullname.push_back(first_word);
        var = current_module->GetVariable(fullname);
      }
      UserFunction* f = g_registry.GetUserFunction(first_word);

      stringstream ss;
      if (var) {
        ss << "#" << var->GetName().at(0);
        return ObjectResult(0, ws+first_word+eat_whitespace_and_comments(), ss.str());
      } else if (f) {
        ss << "#" << f->GetModuleName();
        return ObjectResult(0, ws+first_word+eat_whitespace_and_comments(), ss.str());
      } else if (module) {
        ss << "#" << module->GetModuleName();
        return ObjectResult(0, ws+first_word+eat_whitespace_and_comments(), ss.str());
      }
      else {
        putback_string(first_word+":");
        return ObjectResult(2);
      }
    }

    // check the prefixed uri
    string second_word;
    g_registry.input->get(cc);
    while (is_word_char(cc) && !g_registry.input->eof()) {
      second_word += cc;
      g_registry.input->get(cc);
    }
    g_registry.input->unget();

    // look for a comma
    string extra = eat_whitespace();
    g_registry.input->get(cc);
    bool comma = false;
    if (cc == ',') {
      extra += ",";
      comma = true;
    } else
      g_registry.input->unget();
    extra += eat_whitespace_and_comments();

    pair<int,string> uri_result = make_builtin_prefixed_ontology_uri(first_word,second_word);
    if (!uri_result.first) {
      return ObjectResult(0,ws+first_word+":"+second_word+extra,uri_result.second).combine(comma ? try_parse_object() : ObjectResult(10));
    } else {
      putback_string(first_word+":"+second_word+extra);
      return ObjectResult(3);
    }
  } else if (cc == '<') {
    // it could be an absolute uri
    g_registry.input->get(cc);
    string uri;
    while (!is_whitespace(cc) && cc != '>' && !g_registry.input->eof()) {
      uri += cc;
      g_registry.input->get(cc);
    }
    if (cc == '>' && !g_registry.input->eof()) {
      // look for a comma
      string extra = eat_whitespace();
      g_registry.input->get(cc);
      bool comma = false;
      if (cc == ',') {
        extra += ",";
        comma = true;
      } else
        g_registry.input->unget();
      extra += eat_whitespace_and_comments();

      // it is an absolute uri
      return ObjectResult(0,"<"+uri+">"+extra,uri).combine(comma ? try_parse_object() : ObjectResult(11));
    }
    else {
      // it's not an absolute uri
      // we don't know what it is so put everything back
      g_registry.input->unget();
      putback_string("<"+uri);
      return ObjectResult(4);
    }
  } else return ObjectResult(5);
}

class PredicatePart
{
public:
  typedef map< string,vector<string> > TermMap;

  // error condition
  PredicatePart(int e)
  : m_e(e) {}

  PredicatePart(int e, const string& ws1, const string ws2, const PredicateResult& predicate, const ObjectResult& object)
  : m_e(e), m_parsed(ws1+predicate.getParsedText()+ws2+object.getParsedText()) {
    string p = predicate.getPredicateAbsoluteURI();
    m_terms_for[p].insert(m_terms_for[p].end(), object.geAbsoluteURIs().begin(), object.geAbsoluteURIs().end());
  }

  PredicatePart combine(const PredicatePart& other) const {
    if (other.m_e)
      // error in second operand, don't combine it
      return *this;
    else {
      PredicatePart new_part(*this);
      new_part.m_parsed += other.m_parsed;
      // merge the maps
      for(TermMap::const_iterator p(other.m_terms_for.begin()); p!=other.m_terms_for.end(); ++p)
        new_part.m_terms_for[p->first].insert(new_part.m_terms_for[p->first].end(), p->second.begin(), p->second.end());
      return new_part;
    }
  }

  int getErrorCode() const {
    return m_e;
  }

  const string& getParsedText() const {
    return m_parsed;
  }

  string toString() const {
    stringstream ss;
    for (TermMap::const_iterator i(m_terms_for.begin()); i!=m_terms_for.end(); ++i) {
      ss << "  " << i->first << " ";
      for (vector<string>::const_iterator j(i->second.begin()); j!=i->second.end(); ++j) {
        if (j != i->second.begin())
          ss << ", ";
        ss << *j;
      }
      ss << "\n";
    }
    return ss.str();
  }

  // add cv terms if possible to any annotatable object
  void AddCVTerms(Annotated* a) {
    for (TermMap::const_iterator i(m_terms_for.begin()); i!=m_terms_for.end(); ++i) {
      ModelQualifierType_t mq = Annotated::DecodeModelQualifierURI  (i->first);
      if (mq != BQM_UNKNOWN)
        a->AppendModelQualifiers(mq, i->second);
      BiolQualifierType_t bq  = Annotated::DecodeBiologyQualifierURI(i->first);
      if (bq != BQB_UNKNOWN)
        a->AppendBiolQualifiers(bq, i->second);
    }
  }

  int m_e;
  string m_parsed;
  // contains all the objects for a given predicate
  TermMap m_terms_for;
};

// parse multiple predicates if encountered
PredicatePart try_parse_predicate_part()
{
//   cerr << "  try_parse_predicate_part\n";
  string ws1 = eat_whitespace();

  // check to see if the next token is a predicate (biomodels qual or prefixed uri)
  PredicateResult predicate_result = try_parse_predicate();
  if (predicate_result.getErrorCode()) {
    putback_string(ws1);
    return PredicatePart(1);
  }

  string ws2 = eat_whitespace();

  // try to parse the object: an ontology term or model entity (in composite annotations)
  ObjectResult object_result = try_parse_object();
  if (object_result.getErrorCode()) {
    putback_string(ws1+predicate_result.getParsedText()+ws2);
    return PredicatePart(2);
  }

  return PredicatePart(0, ws1, ws2, predicate_result, object_result).combine(try_parse_predicate_part());
}

// returns zero if it matches an annotation, non-zero otherwise (and puts back everything it read in the latter)
int try_parse_annotation(char cc)
{
//   cerr << "try_parse_annotation\n";

  // annotation should start with a variable name
  if (cc > 0 && (isalpha(cc) || cc == '_')) {
    string word;
    while (cc > 0 && (isalpha(cc) || isdigit(cc) || cc == '_') && !g_registry.input->eof() && !g_registry.input->bad() && !g_registry.input->fail()) {
      word += cc;
      //cerr << cc << "\n";
      //cerr << word.size() << std::endl;
      g_registry.input->get(cc);
    }
    //cerr << "advanced\n";
    if (g_registry.input->eof())
      return 1;
    g_registry.input->unget();
    //cerr << "  " << word << "\n";

    // determine the type of entity
    Module* module = g_registry.GetModule(word);
    Module* current_module = g_registry.CurrentModule();
    Variable* var=NULL;
    if (current_module) {
      vector<string> fullname;
      fullname.push_back(word);
      var = current_module->GetVariable(fullname);
    }
    UserFunction* f = g_registry.GetUserFunction(word);
    if (module || var || f) {
      PredicatePart predicate_part = try_parse_predicate_part();

      if(predicate_part.getErrorCode()) {
        putback_string(word+predicate_part.getParsedText());
        // read the first char again since that's the state we started with
        g_registry.input->get(cc);
        return 2;
      }
      if (f) {
        cerr << "function " << f->GetModuleName() << "\n" << predicate_part.toString();
        predicate_part.AddCVTerms(f);
      } else if (var) {
        cerr << "variable " << var->GetName().at(0) << "\n" << predicate_part.toString();
        predicate_part.AddCVTerms(var);
      } else if (module) {
        cerr << "module " << module->GetModuleName() << "\n" << predicate_part.toString();
        predicate_part.AddCVTerms(module);
      }

      int num_newlines = count_newlines_in(word+predicate_part.getParsedText());
//       cerr << num_newlines << " new lines\n";
      antimony_yylloc_last_line += num_newlines;

      return 0;
    } else {
      putback_string(word);
      // read the first char again since that's the state we started with
      g_registry.input->get(cc);
      return 3;
    }
  } else
    return 4;
}

int antimony_yylex(void)
{
  char cc = 0;
  if (g_registry.input->bad() || g_registry.input->fail()) {
    return ERROR;
  }
  if (g_registry.GetEOFFlag()) {
    g_registry.ClearEOFFlag();
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
  else {
    g_registry.input->get(cc);
    //If we're done with the file, add a newline
    if (g_registry.input->eof()) {
      g_registry.SetEOFFlag();
      return EOL;
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

  // try to parse annotations (does not change state if not found)
//   cerr << "before: " << (char)g_registry.input->peek() << "\n";
  int parsed_annot = 0;
  while (!parsed_annot) {
    char next = g_registry.input->peek();
    parsed_annot = try_parse_annotation(cc);
    if (g_registry.input->eof()) {
      return 0;
    }
    if (g_registry.GetEOFFlag() || g_registry.input->eof() || g_registry.input->bad() || g_registry.input->fail()) {
      g_registry.ClearEOFFlag();
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
    if (g_registry.input->bad() || g_registry.input->fail()) {
      return ERROR;
    }
    // if success, try again until no more annotations left
    if (!parsed_annot) {
      g_registry.input->get(cc);
    }
//     cerr << "  ->" << cc << (char)g_registry.input->peek() << "\n";
    if ((next != g_registry.input->peek()) && parsed_annot) {
      cerr << "next was " << next << " vs. " << (char)g_registry.input->peek() <<
      "(" << g_registry.input->peek() << ")" <<
      "\n";
      assert(false);
    }
  }

  // Parse words
  if (cc > 0 && cc < 256 && (isalpha(cc) || cc == '_')) {
    string word;
    while (cc > 0 && (isalpha(cc) || isdigit(cc) || cc == '_') && !g_registry.input->eof()) {
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
    if (CaselessStrCmp(word, "sbo") && (g_registry.input->peek() == ':')) {
      // try to parse an SBO term
      g_registry.input->get();
      cc = g_registry.input->peek();
      if (cc > 0 && cc < 256 && (isdigit(cc))) {
        *g_registry.input >> antimony_yylval.integer;
        if (g_registry.input->fail()) {
          g_registry.SetError("Unable to parse SBO term.");
          return ERROR;
        }
        antimony_yylval.num = antimony_yylval.integer;
        antimony_yylval.is_integer = true;
      }
      return NUM;
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
      antimony_yylval.integer = numint;
      antimony_yylval.is_integer = true;
      if (g_registry.input->peek() == '.') {
        antimony_yylval.integer = 0;
        antimony_yylval.is_integer = false;
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

  //Parse '->' and dashes
  if (cc == '-') {
    g_registry.input->get(cc);
    if (cc == '-') {
      while ((cc == '-') && !g_registry.input->eof()) {
        g_registry.input->get(cc);
      }
      g_registry.input->unget();
      return DASHES;
    } else if (cc == '>') {
      return BECOMESREV;
    } else if (cc == '|') {
      return BECOMESINH;
    } else if (cc == '(') {
      return BECOMESMOD;
    } else if (cc == 'o') {
      return BECOMESMOD2;
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

//   //Parse uris
//   if (cc == '<') {
//     static string uristring;
//     long ccount = 0;
//     g_registry.input->get(cc);
//     while (cc != '>' && cc != '\r' && cc != '\n' && !g_registry.input->eof()) {
//       uristring += cc;
//       ccount++;
//       g_registry.input->get(cc);
//     }
//     if (cc == '\r' || cc == '\n' || g_registry.input->eof()) {
//       for (; ccount > 0; ccount--) {
//         g_registry.input->unget();
//       }
//       cc = '>';
//     }
//     else {
//       antimony_yylval.word = &uristring;
//       return URI;
//     }
//   }

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
