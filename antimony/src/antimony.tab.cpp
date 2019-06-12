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
    EOL = 259,
    NUM = 260,
    AFTER = 261,
    ANTWORD = 262,
    AT = 263,
    BECOMESREV = 264,
    BECOMESINH = 265,
    BECOMESMOD2 = 266,
    BECOMESIRREV = 267,
    COMPARTMENT = 268,
    CONSTANT = 269,
    CONSTRAINTWORD = 270,
    CONSTWORD = 271,
    DASHES = 272,
    DELETEWORD = 273,
    DNA = 274,
    ELLIPSES = 275,
    END = 276,
    ERROR = 277,
    EVENT = 278,
    FORMULA = 279,
    FUNCTION = 280,
    FUNCTIONWORD = 281,
    GENE = 282,
    GEQ = 283,
    NEQ = 284,
    HASWORD = 285,
    IMPORT = 286,
    INWORD = 287,
    IS = 288,
    LEQ = 289,
    MAXIMIZEWORD = 290,
    MINIMIZEWORD = 291,
    MODNAME = 292,
    MODULE = 293,
    OPERATOR = 294,
    REACTION = 295,
    SPECIES = 296,
    SUBSTONLY = 297,
    TEXTSTRING = 298,
    UNITWORD = 299,
    VARWORD = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 59 "antimony.ypp" /* yacc.c:355  */

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
#define YYLAST   1042

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  219
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  413

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      68,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,     2,     2,    12,    10,     4,    61,
      56,    57,     8,     7,    58,     6,    13,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,    62,
      66,    59,    67,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    11,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,     5,    64,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
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
     270,   273,   281,   289,   297,   305,   313,   331,   332,   333,
     334,   338,   339,   340,   341,   342,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   366,
     367,   370,   371,   372,   373,   374,   375,   376,   379,   380,
     381,   382,   383,   386,   387,   388,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   403,   403,   404,   404,   408,
     409,   410,   411,   412,   416,   417,   421,   425,   426,   427,
     428,   429,   430,   432,   433,   436,   437,   438,   439,   440,
     441,   442,   443,   446,   447,   448,   449,   452,   453,   454,
     455,   458,   459,   460,   461,   464,   465,   466,   467,   470,
     471,   472,   473,   477,   478,   479,   480,   483,   484,   485,
     488,   491,   494,   495,   498,   499,   500,   501,   502,   505,
     506,   509,   509,   510,   510,   511,   511,   512,   512,   515,
     516,   519,   520,   527,   528,   529,   530,   531,   534,   535,
     538,   553,   554,   555,   556,   557,   558,   561,   564,   565,
     568,   569,   570,   573,   576,   587,   599,   601,   605,   606
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
  "\"'@' or 'at'\"", "\"->\"", "\"-|\"", "\"-o\"", "\"=>\"",
  "\"'compartment'\"", "\"name of a pre-defined constant\"",
  "\"'constraint'\"", "\"'const'\"", "\"--\"", "\"'delete'\"", "\"'DNA'\"",
  "\"...\"", "\"'end'\"", "\"an error\"", "\"'event'\"", "\"'formula'\"",
  "\"name of an existing function\"", "\"'function'\"", "\"'gene'\"",
  "\">=\"", "\"!=\"", "\"'has'\"", "\"'import'\"", "\"'in'\"", "\"'is'\"",
  "\"<=\"", "\"'maximize'\"", "\"'minimize'\"",
  "\"name of an existing module\"", "\"'model' or 'module'\"",
  "\"'operator'\"", "\"'reaction'\"", "\"'species'\"",
  "\"'substanceOnly'\"", "\"text string\"", "\"'unit'\"", "\"'var'\"",
  "'('", "')'", "','", "'='", "':'", "'\\''", "';'", "'{'", "'}'", "'!'",
  "'<'", "'>'", "'\\n'", "$accept", "input", "import", "module", "$@1",
  "$@2", "maybemain", "function", "$@3", "spacedformula",
  "variableexportlist", "variable", "variablein", "varmaybein",
  "varmaybeis", "maybein", "modulebody", "modulepart", "reaction",
  "reactantList", "reactionDivider", "formula", "commaformula",
  "mathThing", "inequality", "lineend", "assignment", "submodule", "$@4",
  "$@5", "variableimportlist", "submodifications", "varinitialize",
  "specinit", "formulainit", "reactioninit", "dnainit", "geneinit",
  "operatorinit", "compartmentinit", "varconstinit", "unitinit", "dnadef",
  "dnastrand", "dnamiddle", "event", "$@6", "$@7", "$@8", "$@9",
  "colonret", "eventmodifications", "assignmentlist", "deletion",
  "unitdef", "constraint", "objective", "maxormin", "stringlist", "cvterm",
  "toplevel_sbo", "modulename", "functionname", "modulecvterm",
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
     295,   296,   297,   298,   299,   300,    40,    41,    44,    61,
      58,    39,    59,   123,   125,    33,    60,    62,    10
};
# endif

#define YYPACT_NINF -312

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-312)))

#define YYTABLE_NINF -68

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -312,   621,  -312,  -312,    33,     8,  -312,    28,   200,  -312,
    -312,  -312,  -312,  -312,     8,   200,    66,   450,     8,     8,
       8,  -312,     8,   203,   139,     8,   -32,  -312,  -312,   205,
     110,     8,     8,     8,    34,     8,   486,  -312,  -312,  -312,
    -312,  -312,   560,   107,   153,  -312,    35,   369,   209,  -312,
      35,    35,    35,   -26,    24,    61,    81,    93,   117,   119,
     131,    35,    35,  -312,     8,    35,    40,    35,    35,  -312,
      35,  -312,  -312,  -312,  -312,  -312,   200,  -312,  -312,    45,
    -312,  -312,  -312,  -312,  -312,    45,  -312,  -312,   686,   152,
    -312,   225,  -312,  -312,  -312,    39,     8,     8,     8,     8,
       8,  -312,     8,   144,  -312,   111,     8,    45,  -312,  -312,
     198,   166,   174,  -312,  -312,  -312,  -312,  -312,   219,   166,
     187,  -312,  -312,  -312,  -312,   230,  -312,  -312,  -312,     8,
    -312,    37,     8,     8,     8,     8,     8,     8,     8,   191,
    -312,   233,   166,  -312,     8,     8,  -312,   105,  -312,   424,
     194,  -312,   201,   275,    26,     8,    45,    -5,  -312,  -312,
    -312,     8,     8,     8,     8,     8,     8,     8,     8,  -312,
    -312,   160,  -312,     8,  -312,  -312,  -312,   814,  -312,  -312,
     814,   814,   258,   264,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,   217,  -312,  -312,    45,
    -312,  -312,  -312,  -312,  -312,   240,   244,   814,   814,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,     8,   160,   265,  -312,
      42,    35,   208,   267,    42,    35,   276,   222,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,     8,  -312,   238,
      45,   128,   814,  -312,  -312,   169,   814,  -312,   278,  -312,
     111,   369,   209,  -312,  -312,  -312,     8,    45,  -312,     6,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
      45,   814,  -312,  -312,   814,   814,    56,  -312,   252,   -36,
    -312,   814,  -312,  -312,   814,  -312,   316,   -24,  -312,  -312,
       8,   320,  -312,  -312,  -312,    45,   224,   280,   974,   814,
    -312,     8,     8,   750,  -312,   814,   108,    29,   814,   814,
      45,   193,  -312,   193,  -312,  -312,  -312,  -312,   322,  -312,
      -3,   814,   814,  -312,  -312,   284,   237,    45,  -312,  -312,
     294,     8,   285,   870,  -312,    45,    45,  -312,  -312,   276,
    -312,    30,  -312,     8,  -312,   193,  -312,   -36,   814,   281,
    -312,   103,  -312,  -312,    35,     8,   -19,  -312,    45,   257,
    -312,  -312,   814,   -36,   260,   193,  -312,   193,    45,  -312,
      -3,  -312,  -312,    59,   814,    35,    45,   326,  -312,   974,
    -312,    -3,  -312,  -312,   193,  -312,  -312,   814,   125,  -312,
    -312,    35,   290,   922,   -36,  -312,   -19,  -312,    16,    18,
     310,  -312,    -3,  -312,     8,  -312,     8,  -312,  -312,    45,
    -312,  -312,  -312
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    12,     0,     0,   105,     0,    33,    76,
      71,    72,    74,    75,     0,     0,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,   208,   209,     0,
      21,     0,     0,     0,     0,     0,     0,   103,   104,     3,
       4,     6,    37,    57,     0,     5,     0,     0,     0,    60,
       0,     0,     0,   127,   128,   129,   130,   131,   132,   133,
     134,     0,     0,   172,   178,     0,     0,     0,     0,    76,
       0,    11,     7,     8,     9,    10,     0,    73,    33,    35,
     101,   102,    99,    98,   100,    68,    76,    76,   181,    37,
      38,    39,   163,    76,    76,     0,     0,     0,     0,     0,
       0,   149,     0,     0,   168,   174,   175,   198,   151,   143,
       0,     0,     0,    23,    26,    25,   155,    14,     0,     0,
       0,   117,    22,    20,    19,     0,   159,   147,   135,     0,
     139,   171,     0,     0,     0,     0,     0,     0,     0,     0,
     167,     0,     0,   179,     0,     0,    76,     0,    76,     0,
       0,    48,     0,     0,     0,     0,    67,     0,    49,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      52,   176,    53,     0,    55,    58,    59,   207,    56,    76,
     201,   204,     0,     0,    92,    91,    93,    94,    97,    95,
      79,    76,    80,    77,    81,    76,     0,    76,    96,    78,
      83,    84,   191,    76,    76,     0,     0,   203,   205,    76,
     165,   153,   145,   157,   161,   137,     0,   177,     0,   210,
       0,     0,     0,     0,     0,     0,   119,    17,   138,    76,
     164,   152,   144,   156,   160,   148,   136,     0,    34,   213,
      36,     0,   200,   114,   111,   108,   107,    76,     0,    76,
      67,     0,     0,   173,    76,    76,     0,    69,    76,     0,
      76,   142,   146,   150,   154,   158,   162,   166,   169,   180,
     199,   202,    86,    87,   183,    89,     0,    85,     0,     0,
      43,    40,    76,    76,   206,   141,     0,     0,   219,   217,
      30,     0,   218,   216,   122,   120,     0,     0,     0,   170,
     140,     0,     0,   185,   115,   112,     0,     0,   106,   113,
      70,    44,    76,    44,   191,    82,    76,    88,     0,   189,
       0,    41,    42,   215,   211,     0,     0,    31,   214,   124,
       0,    30,     0,     0,    46,   110,   109,    76,   191,   119,
      76,     0,    76,     0,    63,    44,    65,     0,    90,     0,
     190,     0,   182,   212,    76,     0,    44,   123,   121,     0,
      18,    47,   187,     0,     0,    44,    76,    44,    45,    62,
       0,    76,    76,     0,    27,    76,    32,     0,   118,     0,
     191,     0,   124,    64,    44,    66,   184,   192,   193,    24,
      29,    28,     0,     0,     0,   186,    44,    61,     0,     0,
       0,    16,     0,   116,     0,   196,     0,   194,   126,   125,
     188,   197,   195
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,   -25,
      20,    -1,    15,    25,   395,  -303,   -23,     0,  -312,   -43,
     -40,   259,  -312,  -312,     4,     9,  -312,  -312,  -312,  -312,
      21,   -27,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,   210,   339,  -312,  -312,  -312,  -312,  -312,
    -235,  -311,  -127,  -312,   -96,  -312,  -312,   213,  -111,  -312,
    -312,  -312,  -312,  -312,  -312
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    39,    40,   297,   298,   125,    41,   222,   373,
     326,    89,    90,    91,    92,   344,   333,   334,    46,    47,
      48,   242,   276,   200,   201,    49,    50,    51,   339,   226,
     296,   356,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   202,   314,   338,   380,
     320,   279,   352,    66,   243,    67,    68,    69,   220,    70,
      71,    72,    73,    74,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    45,   153,   347,    79,   157,    85,   154,   224,     5,
     346,    86,    87,   153,    78,    95,    43,   105,   107,    93,
       5,   117,   318,   343,   319,    78,    44,   363,     5,   324,
       5,   239,   161,    78,   131,    78,   153,   153,     5,   377,
       5,   155,   369,    78,   325,    78,     5,   156,    76,     6,
     141,    78,   141,   378,     6,   151,     6,   260,   141,   158,
     159,   160,   383,   171,   385,   350,    80,    81,   312,   394,
     169,   170,    82,     6,   172,   174,   175,   176,     5,   178,
     179,   397,   162,    78,   404,   129,   406,   199,   258,    77,
     389,   342,   366,   403,    83,    84,   229,    37,   173,   209,
     287,   278,    37,    38,    37,   217,   251,   280,    38,   252,
      38,   259,   370,   315,   316,   -38,   141,     5,   122,   163,
       5,    37,    78,   155,   141,    78,    94,    38,   381,   182,
     183,   184,   185,   186,   187,   188,   189,     5,   143,   164,
     190,   141,    78,   240,   241,   123,   245,   -38,   250,   192,
     -38,   165,   257,   156,    85,   193,   113,   124,   244,   402,
     194,   145,   372,    80,    81,   141,   -38,   -38,   -38,    82,
     340,   301,   270,   141,   114,   166,   199,   167,   302,   199,
     199,   195,   141,   398,   196,   399,   115,   269,   197,   168,
     198,    83,    84,   146,   144,   216,   147,   182,   183,   184,
     185,   186,   187,   188,   189,     5,   199,   199,   190,   307,
      78,   306,   148,   149,   150,   218,   110,   192,   118,   219,
     111,     5,   119,   193,   155,   295,    78,   221,   194,   288,
     289,    80,    81,   292,   293,   343,   223,    82,    80,    81,
     225,   199,   237,   386,    82,   199,   112,   227,   120,   195,
     238,   156,   196,   255,   395,   310,   197,    77,   198,    83,
      84,   121,   272,   341,   290,   203,    83,    84,    88,   273,
     199,   405,   407,   199,   199,   410,   277,   411,   -15,   412,
     199,   329,   330,   199,   204,   205,   206,     5,     5,   327,
     256,   294,    78,    78,   354,   355,   287,    42,   199,   282,
     335,   336,   199,   283,   199,   156,     5,   199,   199,   357,
     199,    78,   199,    43,   379,   355,   317,   382,   330,   351,
     199,   199,     5,    44,   286,   408,   291,    78,   177,   358,
     327,   323,    42,   361,   304,   328,   331,   353,   295,   349,
     371,   121,   368,   392,   199,   180,   181,   199,    43,   400,
     391,   359,   207,   208,   376,   396,   393,   106,    44,   253,
     364,   199,   254,   375,   199,     0,   199,     0,     0,   351,
       0,     0,     0,   199,     0,   152,   153,     0,    42,     0,
     351,     0,   390,   199,   375,     0,   199,   199,    10,    11,
      12,    13,    42,   361,    43,     0,     0,   351,   351,   409,
     390,   351,     0,   351,    44,   351,     0,   246,    43,     0,
       0,     0,   104,     0,     0,   108,     0,   109,    44,     0,
     116,     0,     0,     0,     0,     0,   126,   127,   128,   130,
     152,   140,     0,     0,     0,     0,     5,     0,   271,   155,
       0,    78,   247,    10,    11,    12,    13,     0,     0,     0,
     274,    18,     0,     0,   275,     0,     0,     0,     0,     0,
       0,     0,     5,   281,     0,     0,     0,    78,   284,    27,
      28,   248,     0,    96,     0,     0,     0,     0,     0,    97,
       0,     0,     0,   249,    98,     0,     0,    99,   299,     0,
       0,   210,   211,   212,   213,   214,     0,   215,     5,   100,
     101,   102,   103,    78,     0,     0,   303,     0,   305,   132,
       0,     0,     0,   308,   309,   133,     0,   311,     0,   313,
     134,     0,     0,   135,   228,     0,     0,   230,   231,   232,
     233,   234,   235,   236,     0,   136,   137,   138,   139,     0,
       0,   321,   322,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,   262,   263,   264,
     265,   266,   267,   268,     0,     0,   -67,   -67,     0,     0,
       0,   345,     0,   141,     0,   348,     0,   142,     0,   -67,
     -67,   -67,   -67,     0,     0,     0,     0,   143,     0,     0,
       0,     0,     0,     0,     0,     0,   362,     0,     0,   365,
       0,   367,   144,     0,     0,     0,     0,     0,     0,     0,
       0,   285,     0,   374,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     0,   384,     0,     4,     0,     0,
     387,   388,   300,     5,   374,     6,     7,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,    21,     0,    22,    23,    24,    25,     0,
       0,     0,    26,     0,     0,     0,    27,    28,    29,    30,
      31,    32,    33,    34,     0,    35,    36,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,    38,
     182,   183,   184,   185,   186,   187,   188,   189,     5,     0,
       0,   190,   191,    78,     0,     0,     0,     0,     0,     0,
     192,     0,     0,     0,     0,     0,   193,     0,     0,     0,
       0,   194,     0,     0,    80,    81,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   195,     0,     0,   196,     0,     0,     0,   197,
       0,   198,    83,    84,   182,   183,   184,   185,   186,   187,
     188,   189,     5,     0,     0,   190,   337,    78,     0,     0,
       0,     0,     0,     0,   192,     0,     0,     0,     0,     0,
     193,     0,     0,     0,     0,   194,     0,     0,    80,    81,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   195,     0,     0,   196,
       0,     0,     0,   197,     0,   198,    83,    84,   182,   183,
     184,   185,   186,   187,   188,   189,     5,     0,     0,   190,
       0,    78,     0,     0,     0,     0,     0,     0,   192,     0,
       0,     0,     0,     0,   193,     0,     0,     0,     0,   194,
       0,     0,    80,    81,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     195,     0,     0,   196,     0,     0,     4,   197,     0,   198,
      83,    84,     5,     0,     6,     7,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,   360,     0,     0,    22,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,    27,    28,   332,     0,    31,
      32,    33,    34,     0,    35,    36,     0,     0,     4,     0,
       0,     0,    37,     0,     5,     0,     6,     7,    38,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,   401,     0,     0,    22,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,    27,    28,   332,
       0,    31,    32,    33,    34,     0,    35,    36,     0,     0,
       4,     0,     0,     0,    37,     0,     5,     0,     6,     7,
      38,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,    22,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,    27,
      28,   332,     0,    31,    32,    33,    34,     0,    35,    36,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,    38
};

static const yytype_int16 yycheck[] =
{
       1,     1,     7,   314,     5,    48,     7,    47,   119,    12,
     313,     7,     8,     7,    17,    16,     1,    18,    19,    15,
      12,    53,    58,    42,    60,    17,     1,   338,    12,    53,
      12,   142,    58,    17,    35,    17,     7,     7,    12,    58,
      12,    15,   345,    17,    68,    17,    12,    48,    15,    14,
      13,    17,    13,   356,    14,    46,    14,    62,    13,    50,
      51,    52,   365,    64,   367,    68,    38,    39,    62,   380,
      61,    62,    44,    14,    65,    66,    67,    68,    12,    70,
      76,   384,    58,    17,    68,    51,    68,    88,    62,    56,
      31,    62,    62,   396,    66,    67,    59,    62,    58,    60,
      58,   197,    62,    68,    62,   106,   149,   203,    68,   149,
      68,   154,   347,    57,    58,     8,    13,    12,     8,    58,
      12,    62,    17,    15,    13,    17,    60,    68,   363,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    27,    58,
      15,    13,    17,   144,   145,    35,   147,    40,   149,    24,
      43,    58,   153,   154,   155,    30,    17,    47,    53,   394,
      35,     8,    59,    38,    39,    13,    59,    60,    61,    44,
      62,    43,   173,    13,    35,    58,   177,    58,     9,   180,
     181,    56,    13,    58,    59,    60,    47,    27,    63,    58,
      65,    66,    67,    40,    42,    51,    43,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   207,   208,    15,   252,
      17,   251,    59,    60,    61,    17,    13,    24,    13,    53,
      17,    12,    17,    30,    15,   226,    17,    53,    35,   220,
     221,    38,    39,   224,   225,    42,    17,    44,    38,    39,
      53,   242,    51,   370,    44,   246,    43,    17,    43,    56,
      17,   252,    59,    59,   381,   256,    63,    56,    65,    66,
      67,    56,     4,   306,    56,    40,    66,    67,     9,     5,
     271,   398,   399,   274,   275,   402,    59,   404,    56,   406,
     281,    57,    58,   284,    59,    60,    61,    12,    12,   290,
      15,    15,    17,    17,    57,    58,    58,   298,   299,    59,
     301,   302,   303,    59,   305,   306,    12,   308,   309,    15,
     311,    17,   313,   298,    57,    58,    64,    57,    58,   320,
     321,   322,    12,   298,    59,    15,    59,    17,    69,   330,
     331,    15,   333,   333,    56,    15,    56,    53,   339,    17,
      59,    56,   343,    17,   345,    86,    87,   348,   333,    59,
     375,   331,    93,    94,   355,   382,   379,    18,   333,   149,
     339,   362,   149,   354,   365,    -1,   367,    -1,    -1,   370,
      -1,    -1,    -1,   374,    -1,     6,     7,    -1,   379,    -1,
     381,    -1,   373,   384,   375,    -1,   387,   388,    19,    20,
      21,    22,   393,   393,   379,    -1,    -1,   398,   399,   400,
     391,   402,    -1,   404,   379,   406,    -1,   148,   393,    -1,
      -1,    -1,    17,    -1,    -1,    20,    -1,    22,   393,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
       6,    36,    -1,    -1,    -1,    -1,    12,    -1,   179,    15,
      -1,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
     191,    27,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,   204,    -1,    -1,    -1,    17,   209,    45,
      46,    47,    -1,    23,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    59,    34,    -1,    -1,    37,   229,    -1,
      -1,    96,    97,    98,    99,   100,    -1,   102,    12,    49,
      50,    51,    52,    17,    -1,    -1,   247,    -1,   249,    23,
      -1,    -1,    -1,   254,   255,    29,    -1,   258,    -1,   260,
      34,    -1,    -1,    37,   129,    -1,    -1,   132,   133,   134,
     135,   136,   137,   138,    -1,    49,    50,    51,    52,    -1,
      -1,   282,   283,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,     6,     7,    -1,    -1,
      -1,   312,    -1,    13,    -1,   316,    -1,    17,    -1,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   337,    -1,    -1,   340,
      -1,   342,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   216,    -1,   354,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,    -1,   366,    -1,     6,    -1,    -1,
     371,   372,   237,    12,   375,    14,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    -1,    34,    35,    36,    37,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    -1,    63,
      -1,    65,    66,    67,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,
      -1,    -1,    -1,    63,    -1,    65,    66,    67,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    15,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    59,    -1,    -1,     6,    63,    -1,    65,
      66,    67,    12,    -1,    14,    15,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    -1,    -1,    34,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      50,    51,    52,    -1,    54,    55,    -1,    -1,     6,    -1,
      -1,    -1,    62,    -1,    12,    -1,    14,    15,    68,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    -1,    -1,    34,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    50,    51,    52,    -1,    54,    55,    -1,    -1,
       6,    -1,    -1,    -1,    62,    -1,    12,    -1,    14,    15,
      68,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    50,    51,    52,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,     0,     1,     6,    12,    14,    15,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    32,    34,    35,    36,    37,    41,    45,    46,    47,
      48,    49,    50,    51,    52,    54,    55,    62,    68,    71,
      72,    76,    80,    81,    82,    86,    87,    88,    89,    94,
      95,    96,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   122,   124,   125,   126,
     128,   129,   130,   131,   132,   133,    15,    56,    17,    80,
      38,    39,    44,    66,    67,    80,    93,    93,    90,    80,
      81,    82,    83,    93,    60,    80,    23,    29,    34,    37,
      49,    50,    51,    52,    83,    80,   113,    80,    83,    83,
      13,    17,    43,    17,    35,    47,    83,    53,    13,    17,
      43,    56,     8,    35,    47,    75,    83,    83,    83,    51,
      83,    80,    23,    29,    34,    37,    49,    50,    51,    52,
      83,    13,    17,    27,    42,     8,    40,    43,    59,    60,
      61,    94,     6,     7,    89,    15,    80,    88,    94,    94,
      94,    58,    58,    58,    58,    58,    58,    58,    58,    94,
      94,    80,    94,    58,    94,    94,    94,    90,    94,    93,
      90,    90,     4,     5,     6,     7,     8,     9,    10,    11,
      15,    16,    24,    30,    35,    56,    59,    63,    65,    80,
      92,    93,   115,    40,    59,    60,    61,    90,    90,    60,
      83,    83,    83,    83,    83,    83,    51,    80,    17,    53,
     127,    53,    77,    17,   127,    53,    98,    17,    83,    59,
      83,    83,    83,    83,    83,    83,    83,    51,    17,   127,
      80,    80,    90,   123,    53,    80,    90,    18,    47,    59,
      80,    88,    89,   112,   126,    59,    15,    80,    62,    88,
      62,    83,    83,    83,    83,    83,    83,    83,    83,    27,
      80,    90,     4,     5,    90,    90,    91,    59,   123,   120,
     123,    90,    59,    59,    90,    83,    59,    58,    94,    94,
      56,    59,    94,    94,    15,    80,    99,    73,    74,    90,
      83,    43,     9,    90,    56,    90,    89,    88,    90,    90,
      80,    90,    62,    90,   116,    57,    58,    64,    58,    60,
     119,    90,    90,    15,    53,    68,    79,    80,    15,    57,
      58,    56,    47,    85,    86,    80,    80,    16,   117,    97,
      62,    88,    62,    42,    84,    90,    84,   120,    90,    17,
      68,    80,   121,    53,    57,    58,   100,    15,    80,    79,
      31,    86,    90,   120,    99,    90,    62,    90,    80,    84,
     119,    59,    59,    78,    90,    94,    80,    58,    84,    57,
     118,   119,    57,    84,    90,    84,   121,    90,    90,    31,
      94,    78,    17,    85,   120,   121,   100,    84,    58,    60,
      59,    31,   119,    84,    68,   121,    68,   121,    15,    80,
     121,   121,   121
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    71,    73,    72,    74,    72,    72,
      72,    75,    75,    77,    76,    76,    76,    78,    78,    78,
      79,    79,    79,    80,    80,    80,    81,    82,    82,    83,
      83,    83,    83,    83,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    87,    87,    87,    87,    87,    87,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    91,
      91,    92,    92,    92,    92,    92,    92,    92,    93,    93,
      93,    93,    93,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    97,    96,    98,    96,    99,
      99,    99,    99,    99,   100,   100,   100,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   103,   103,   103,   103,   104,   104,   104,
     104,   105,   105,   105,   105,   106,   106,   106,   106,   107,
     107,   107,   107,   108,   108,   108,   108,   109,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   112,   113,
     113,   115,   114,   116,   114,   117,   114,   118,   114,   119,
     119,   120,   120,   121,   121,   121,   121,   121,   122,   122,
     123,   124,   124,   124,   124,   124,   124,   125,   126,   126,
     127,   127,   127,   128,   129,   129,   130,   131,   132,   133
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
       1,     8,     6,     5,     7,     5,     7,     1,     2,     3,
       4,     1,     1,     2,     1,     1,     0,     2,     2,     2,
       2,     2,     4,     2,     2,     3,     3,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1,     3,     4,     3,     3,     3,     4,     2,     1,     1,
       1,     3,     4,     3,     5,     5,     4,     4,     4,     4
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
#line 1735 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 154 "antimony.ypp" /* yacc.c:1646  */
    { /*cout << endl << $2->ToString() << endl << endl;*/ }
#line 1741 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 155 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1747 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 156 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1753 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 157 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1759 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 158 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1765 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 159 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1771 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 160 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1777 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 161 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1783 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 162 "antimony.ypp" /* yacc.c:1646  */
    {YYABORT;}
#line 1789 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 163 "antimony.ypp" /* yacc.c:1646  */
    {YYABORT;}
#line 1795 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 166 "antimony.ypp" /* yacc.c:1646  */
    { if (g_registry.OpenFile(*((yyvsp[0].word)))==0) YYABORT;}
#line 1801 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 184 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.NewCurrentModule((yyvsp[0].word), NULL, (yyvsp[-1].maybemain));}
#line 1807 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 185 "antimony.ypp" /* yacc.c:1646  */
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 1817 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 190 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.NewCurrentModule((yyvsp[0].word), NULL, (yyvsp[-1].maybemain));}
#line 1823 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 191 "antimony.ypp" /* yacc.c:1646  */
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 1833 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 196 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("module '" + *((yyvsp[0].word)) + "' already defined."); YYABORT;}
#line 1839 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 197 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a module because it is already a defined function."); YYABORT;}
#line 1845 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 200 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.maybemain) = false;}
#line 1851 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 201 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.maybemain) = true;}
#line 1857 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 204 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.NewUserFunction((yyvsp[0].word));}
#line 1863 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 204 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetUserFunction((yyvsp[-1].formula))) YYABORT;}
#line 1869 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 205 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Cannot use '" + *((yyvsp[0].word)) +"' as a function name because it is already the name of a module."); YYABORT;}
#line 1875 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 206 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a new function because it is already a defined function."); YYABORT;}
#line 1881 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 209 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[0].formula);}
#line 1887 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 210 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[0].formula);}
#line 1893 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 211 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula);}
#line 1899 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 221 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 1905 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 222 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 1911 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 223 "antimony.ypp" /* yacc.c:1646  */
    { if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 1917 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 226 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[0].word)); }
#line 1923 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 227 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-2].variable)->GetSubVariable((yyvsp[0].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[0].word)) + "' is not a subvariable of '" + (yyvsp[-2].variable)->GetNameDelimitedBy(".") + "'.");
                    YYABORT;
                  }
                }
#line 1934 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 233 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;}
#line 1940 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 236 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetCompartment((yyvsp[0].variable))) YYABORT; (yyval.variable) = (yyvsp[-2].variable);}
#line 1946 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 239 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable);}
#line 1952 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 240 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable);}
#line 1958 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 243 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable);}
#line 1964 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 244 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 1970 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 245 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT; }
#line 1976 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 246 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT; }
#line 1982 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 247 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 1988 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 250 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = NULL;}
#line 1994 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 251 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.variable) = (yyvsp[0].variable);}
#line 2000 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 254 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2006 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 255 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2012 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 258 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2018 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 259 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2024 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 260 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2030 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 261 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2036 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 262 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2042 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 263 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2048 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 264 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2054 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 265 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2060 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 266 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2066 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 267 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2072 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 268 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2078 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 269 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2084 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 270 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2090 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 274 "antimony.ypp" /* yacc.c:1646  */
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-7].variable), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-7].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2102 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 282 "antimony.ypp" /* yacc.c:1646  */
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2114 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 290 "antimony.ypp" /* yacc.c:1646  */
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2126 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 298 "antimony.ypp" /* yacc.c:1646  */
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2138 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 306 "antimony.ypp" /* yacc.c:1646  */
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2150 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 314 "antimony.ypp" /* yacc.c:1646  */
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2162 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 331 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2168 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 332 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2174 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 333 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactantList) = (yyvsp[-2].reactantList); if((yyvsp[-2].reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2180 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 334 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2186 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 338 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdBecomes;}
#line 2192 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 339 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdInhibits;}
#line 2198 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 340 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdInfluences;}
#line 2204 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 341 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdInfluences;}
#line 2210 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 342 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.reactionDivider) = rdBecomesIrreversibly;}
#line 2216 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 346 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = g_registry.NewBlankFormula(); }
#line 2222 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 347 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddEllipses();}
#line 2228 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 348 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); if((yyvsp[-1].formula)->AddVariable((yyvsp[0].variable))) YYABORT; }
#line 2234 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 349 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddNum((yyvsp[0].num)); }
#line 2240 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 350 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2246 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 351 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2252 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 352 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2258 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 353 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddMathThing((yyvsp[0].character)); }
#line 2264 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 354 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddInequality((yyvsp[0].inequality)); }
#line 2270 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 355 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('='); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2276 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 356 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('&'); (yyvsp[-2].formula)->AddMathThing('&'); }
#line 2282 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 357 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('|'); (yyvsp[-2].formula)->AddMathThing('|'); }
#line 2288 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 359 "antimony.ypp" /* yacc.c:1646  */
    {
                  //Need to create a variable to be this unit definition, or find one that already has this unit definition, and then use that name.
                  (yyval.formula) = (yyvsp[-3].formula);
                  (yyval.formula)->AddVariable((yyvsp[-1].variable));
                }
#line 2298 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 366 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[0].formula);}
#line 2304 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 367 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.formula) = (yyvsp[-2].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[0].formula)); }
#line 2310 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 370 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '+';}
#line 2316 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 371 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '-';}
#line 2322 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 372 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '*';}
#line 2328 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 373 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '/';}
#line 2334 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 374 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '^';}
#line 2340 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 375 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '!';}
#line 2346 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 376 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.character) = '%';}
#line 2352 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 379 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constLT;}
#line 2358 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 380 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constLEQ;}
#line 2364 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 381 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constGT;}
#line 2370 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 382 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constGEQ;}
#line 2376 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 383 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.inequality) = constNEQ;}
#line 2382 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 386 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2388 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 387 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2394 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 388 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2400 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 391 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddObjective((yyvsp[-3].variable), (yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 2406 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 392 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2412 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 393 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->Synchronize((yyvsp[0].variable), NULL)) YYABORT;}
#line 2418 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 394 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[-2].variable), (yyvsp[0].variable))) YYABORT;}
#line 2424 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 395 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[0].variable), (yyvsp[-2].variable))) YYABORT;}
#line 2430 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 396 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetDisplayName(*((yyvsp[0].word)))) YYABORT;}
#line 2436 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 397 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT;}
#line 2442 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 398 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT;}
#line 2448 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 399 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2454 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 403 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-3].variable)->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2460 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 403 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[0].variable) != NULL) {if ((yyvsp[-8].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2466 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 404 "antimony.ypp" /* yacc.c:1646  */
    {if(g_registry.CurrentModule()->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2472 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 404 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[0].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2478 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 408 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2484 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 409 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2490 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 410 "antimony.ypp" /* yacc.c:1646  */
    { if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2496 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 411 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2502 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 412 "antimony.ypp" /* yacc.c:1646  */
    { if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2508 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 416 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2514 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 417 "antimony.ypp" /* yacc.c:1646  */
    {if (CaselessStrCmp(*(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].variable));}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2522 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 421 "antimony.ypp" /* yacc.c:1646  */
    {if (CaselessStrCmp(*(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].num));}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2530 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 425 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2536 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 426 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2542 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 427 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2548 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 428 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2554 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 429 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2560 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 430 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2566 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 432 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2572 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 433 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2578 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 436 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2584 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 437 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2590 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 438 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2596 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 439 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2602 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 440 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2608 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 441 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2614 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 442 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2620 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 443 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2626 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 446 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2632 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 447 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2638 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 448 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2644 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 449 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2650 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 452 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 2656 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 453 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 2662 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 454 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; }
#line 2668 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 455 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 2674 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 458 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 2680 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 459 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 2686 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 460 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 2692 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 461 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 2698 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 464 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 2704 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 465 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 2710 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 466 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetError("Genes may not be set 'const'."); YYABORT; }
#line 2716 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 467 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 2722 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 470 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 2728 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 471 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 2734 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 472 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 2740 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 473 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 2746 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 477 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 2752 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 478 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 2758 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 479 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 2764 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 480 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 2770 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 483 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst();}
#line 2776 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 484 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst();}
#line 2782 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 485 "antimony.ypp" /* yacc.c:1646  */
    {(yyvsp[0].variable)->SetRegConst();}
#line 2788 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 488 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[-2].variable)->SetType(varUnitDefinition)) YYABORT;
                                               if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                                               if ((yyvsp[-2].variable)->GetUnitDef()->SetFromFormula((yyvsp[0].formula))) YYABORT;}
#line 2796 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 491 "antimony.ypp" /* yacc.c:1646  */
    {if ((yyvsp[0].variable)->SetType(varUnitDefinition)) YYABORT;}
#line 2802 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 494 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SaveWorkingStrand()) YYABORT;}
#line 2808 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 495 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetStrandAs((yyvsp[-2].variable))) YYABORT;}
#line 2814 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 498 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewUpstreamOpen((yyvsp[0].variable))) YYABORT;}
#line 2820 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 499 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetOpenUpstream(); }
#line 2826 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 500 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 2832 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 501 "antimony.ypp" /* yacc.c:1646  */
    {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 2838 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 502 "antimony.ypp" /* yacc.c:1646  */
    { }
#line 2844 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 505 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 2850 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 506 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 2856 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 509 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula))) YYABORT;}
#line 2862 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 509 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2868 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 510 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula))) YYABORT;}
#line 2874 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 510 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2880 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 511 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula), (yyvsp[-3].variable))) YYABORT;}
#line 2886 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 511 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2892 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 512 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula), (yyvsp[-5].variable))) YYABORT;}
#line 2898 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 512 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2904 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 515 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2910 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 516 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2916 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 519 "antimony.ypp" /* yacc.c:1646  */
    {}
#line 2922 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 520 "antimony.ypp" /* yacc.c:1646  */
    {if (CaselessStrCmp(*(yyvsp[-2].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[0].formula));}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[-2].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[0].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;}}
#line 2932 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 527 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 2938 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 528 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 2944 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 529 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 2950 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 530 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 2956 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 531 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 2962 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 534 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 2968 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 535 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 2974 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 538 "antimony.ypp" /* yacc.c:1646  */
    {
                    if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                    if ((yyvsp[0].formula)->IsSingleVariable()) {
                      (yyval.variable) = g_registry.CurrentModule()->GetVariable(((yyvsp[0].formula)->GetVariables())[0]);
                      if ((yyval.variable)==NULL) YYABORT;
                    }
                    else {
                      UnitDef ud("", g_registry.CurrentModule()->GetModuleName());
                      if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                      if (ud.SetFromFormula((yyvsp[0].formula))) YYABORT;
                      (yyval.variable) = g_registry.CurrentModule()->AddOrFindUnitDef(ud);
                    }
                }
#line 2992 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 553 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 2998 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 554 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint(-(yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3004 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 555 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3010 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 556 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3016 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 557 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[0].formula))) YYABORT;}
#line 3022 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 558 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3028 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 561 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->AddObjective((yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 3034 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 564 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.maxormin) = true;}
#line 3040 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 565 "antimony.ypp" /* yacc.c:1646  */
    {(yyval.maxormin) = false;}
#line 3046 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 568 "antimony.ypp" /* yacc.c:1646  */
    { (yyval.stringlist) = new std::vector<std::string>(); (yyval.stringlist)->push_back(*((yyvsp[0].word))); }
#line 3052 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 569 "antimony.ypp" /* yacc.c:1646  */
    { (yyval.stringlist) = (yyvsp[-2].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3058 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 570 "antimony.ypp" /* yacc.c:1646  */
    { (yyval.stringlist) = (yyvsp[-3].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3064 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 573 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.CurrentModule()->ProcessCVTerm((yyvsp[-2].variable),(yyvsp[-1].word),(yyvsp[0].stringlist))) YYABORT;}
#line 3070 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 577 "antimony.ypp" /* yacc.c:1646  */
    { Module* module = g_registry.GetModule(*(yyvsp[-4].word));
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(*((yyvsp[-2].word)), "sboTerm")) {
                      module->SetSBOTerm((yyvsp[0].num));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3084 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 588 "antimony.ypp" /* yacc.c:1646  */
    { Module* function = g_registry.GetModule(*(yyvsp[-4].word));
                    if (function && (yyvsp[-2].word) &&  CaselessStrCmp(*((yyvsp[-2].word)), "sboTerm")) {
                      function->SetSBOTerm((yyvsp[0].num));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3098 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 600 "antimony.ypp" /* yacc.c:1646  */
    { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3104 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 602 "antimony.ypp" /* yacc.c:1646  */
    { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3110 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 605 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3116 "antimony.tab.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 606 "antimony.ypp" /* yacc.c:1646  */
    {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3122 "antimony.tab.cpp" /* yacc.c:1646  */
    break;


#line 3126 "antimony.tab.cpp" /* yacc.c:1646  */
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
#line 608 "antimony.ypp" /* yacc.c:1906  */



void antimony_yyerror(char const *s)
{
  if (g_registry.GetError()=="") {
    g_registry.SetError(s);
  }
}

int antimony_yylex(void)
{
  char cc = 0;
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

  //Parse LEQ ('<=') and BECOMESREV ('<==>')
  if (cc == '<') {
    g_registry.input->get(cc);
    if (cc == '=') {
      g_registry.input->get(cc);
      if (cc == '=') {
        g_registry.input->get(cc);
        if (cc == '>') {
          return BECOMESREV;
        }
        else {
          g_registry.input->unget();
        }
      }
      g_registry.input->unget();
      return LEQ;
    }
    g_registry.input->unget();
    cc = '<';
  }

  //Parse GEQ >=
  if (cc == '>') {
    g_registry.input->get(cc);
    if (cc == '=') {
      return GEQ;
    }
    g_registry.input->unget();
    cc = '>';
  }

  //Parse NEQ !=
  if (cc == '!') {
    g_registry.input->get(cc);
    if (cc == '=') {
      return NEQ;
    }
    g_registry.input->unget();
    cc = '!';
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
