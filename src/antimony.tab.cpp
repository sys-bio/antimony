/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

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
#define YYBISON_VERSION "2.7.12-4996"

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
#define yylval          antimony_yylval
#define yychar          antimony_yychar
#define yydebug         antimony_yydebug
#define yynerrs         antimony_yynerrs

/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 26 "antimony.ypp"

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

/* Line 371 of yacc.c  */
#line 107 "antimony.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int antimony_yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     YYEOF = 0,
     NUM = 259,
     AFTER = 260,
     ANTWORD = 261,
     AT = 262,
     BECOMESIRREV = 263,
     COMPARTMENT = 264,
     CONSTANT = 265,
     CONSTWORD = 266,
     DASHES = 267,
     DELETEWORD = 268,
     DNA = 269,
     ELLIPSES = 270,
     END = 271,
     EVENT = 272,
     FORMULA = 273,
     FUNCTION = 274,
     FUNCTIONWORD = 275,
     GENE = 276,
     HASWORD = 277,
     IMPORT = 278,
     INWORD = 279,
     IS = 280,
     MODNAME = 281,
     MODULE = 282,
     OPERATOR = 283,
     REACTION = 284,
     SPECIES = 285,
     TEXTSTRING = 286,
     UNITWORD = 287,
     VARWORD = 288,
     ERROR = 289
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 59 "antimony.ypp"

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


/* Line 387 of yacc.c  */
#line 200 "antimony.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE antimony_yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int antimony_yyparse (void *YYPARSE_PARAM);
#else
int antimony_yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int antimony_yyparse (void);
#else
int antimony_yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 228 "antimony.tab.cpp"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   708

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNRULES -- Number of states.  */
#define YYNSTATES  316

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      56,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,     2,    47,    10,     4,    57,
      43,    44,     8,     7,    45,     6,    46,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    50,
      52,    48,    51,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    11,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     5,    55,     2,     2,     2,     2,
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
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    19,    22,
      25,    26,    36,    37,    44,    47,    50,    51,    53,    54,
      63,    66,    69,    71,    74,    77,    78,    80,    84,    86,
      90,    93,    97,    99,   101,   103,   107,   111,   112,   115,
     117,   120,   123,   126,   129,   132,   135,   138,   141,   144,
     146,   148,   157,   164,   165,   167,   170,   174,   179,   182,
     185,   188,   191,   193,   196,   197,   200,   203,   206,   209,
     212,   217,   220,   224,   228,   232,   236,   240,   244,   249,
     251,   255,   257,   259,   261,   263,   265,   267,   269,   271,
     273,   275,   277,   281,   285,   291,   297,   301,   306,   311,
     315,   316,   326,   327,   335,   336,   338,   342,   344,   348,
     349,   355,   361,   363,   365,   367,   369,   371,   373,   375,
     377,   380,   384,   388,   392,   395,   399,   403,   407,   410,
     414,   417,   421,   424,   428,   432,   436,   439,   443,   447,
     451,   454,   458,   462,   466,   469,   473,   477,   481,   484,
     487,   491,   496,   499,   501,   505,   508,   511,   514,   518,
     520,   523,   527,   528,   535,   536,   545,   546,   555,   556,
     567,   569,   572,   573,   579,   583,   589,   596,   602,   609,
     612,   616
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    -1,    59,    60,    -1,    59,    61,    -1,
      59,    75,    -1,    59,    65,    -1,    59,     1,    -1,    59,
      42,    -1,    31,    39,    -1,    -1,    35,    64,    14,    62,
      43,    68,    44,    74,    24,    -1,    -1,    35,    64,    14,
      63,    74,    24,    -1,    35,    34,    -1,    35,    27,    -1,
      -1,     8,    -1,    -1,    28,    14,    66,    43,    68,    44,
      67,    24,    -1,    28,    34,    -1,    28,    27,    -1,    79,
      -1,    82,    67,    -1,    67,    82,    -1,    -1,    69,    -1,
      68,    45,    69,    -1,    14,    -1,    69,    46,    14,    -1,
      47,    69,    -1,    69,    32,    69,    -1,    69,    -1,    70,
      -1,    71,    -1,    71,    48,    79,    -1,    71,    30,   111,
      -1,    -1,    32,    69,    -1,    75,    -1,    74,    75,    -1,
      76,    82,    -1,    83,    82,    -1,    84,    82,    -1,    89,
      82,    -1,    99,    82,    -1,   102,    82,    -1,    98,    82,
      -1,   110,    82,    -1,    70,    -1,    82,    -1,    71,    49,
      77,    78,    77,    50,    79,    73,    -1,    77,    78,    77,
      50,    79,    73,    -1,    -1,    69,    -1,    12,    69,    -1,
      77,     7,    69,    -1,    77,     7,    12,    69,    -1,     6,
      51,    -1,     6,     5,    -1,     6,    43,    -1,     6,    14,
      -1,    16,    -1,    52,    16,    -1,    -1,    79,    23,    -1,
      79,    69,    -1,    79,    12,    -1,    79,    18,    -1,    79,
      27,    -1,    79,    43,    80,    44,    -1,    79,    81,    -1,
      79,    52,    48,    -1,    79,    51,    48,    -1,    79,    48,
      48,    -1,    79,    53,    48,    -1,    79,     4,     4,    -1,
      79,     5,     5,    -1,    79,    54,   111,    55,    -1,    79,
      -1,    80,    45,    79,    -1,     7,    -1,     6,    -1,     8,
      -1,     9,    -1,    11,    -1,    51,    -1,    52,    -1,    53,
      -1,    10,    -1,    50,    -1,    56,    -1,    71,    48,    79,
      -1,    71,    33,    69,    -1,    71,    33,    69,     9,    69,
      -1,    71,     8,    69,    33,    69,    -1,    71,    33,    39,
      -1,    71,    49,    48,    79,    -1,    71,    57,    48,    79,
      -1,    71,    30,   111,    -1,    -1,    71,    49,    34,    43,
      85,    87,    44,    88,    73,    -1,    -1,    34,    43,    86,
      87,    44,    88,    73,    -1,    -1,    69,    -1,    87,    45,
      69,    -1,    12,    -1,    87,    45,    12,    -1,    -1,    88,
      45,    14,    48,    69,    -1,    88,    45,    14,    48,    12,
      -1,    90,    -1,    91,    -1,    92,    -1,    93,    -1,    94,
      -1,    95,    -1,    96,    -1,    97,    -1,    38,    72,    -1,
      41,    38,    72,    -1,    19,    38,    72,    -1,    90,    45,
      72,    -1,    26,    72,    -1,    41,    26,    72,    -1,    19,
      26,    72,    -1,    91,    45,    72,    -1,    37,    72,    -1,
      41,    37,    72,    -1,    19,    37,    -1,    92,    45,    72,
      -1,    22,    72,    -1,    41,    22,    72,    -1,    19,    22,
      72,    -1,    93,    45,    72,    -1,    29,    72,    -1,    41,
      29,    72,    -1,    19,    29,    72,    -1,    94,    45,    72,
      -1,    36,    72,    -1,    41,    36,    72,    -1,    19,    36,
      72,    -1,    95,    45,    72,    -1,    17,    72,    -1,    41,
      17,    72,    -1,    19,    17,    72,    -1,    96,    45,    72,
      -1,    41,    72,    -1,    19,    72,    -1,    97,    45,    72,
      -1,    40,    69,    48,    79,    -1,    40,    69,    -1,   100,
      -1,    71,    49,   100,    -1,    20,    69,    -1,    20,   101,
      -1,   101,    69,    -1,    20,   101,    69,    -1,   101,    -1,
      69,    20,    -1,   101,    69,    20,    -1,    -1,    15,    79,
     103,   108,   107,   109,    -1,    -1,    15,    79,    13,    79,
     104,   108,   107,   109,    -1,    -1,    71,    49,    15,    79,
     105,   108,   107,   109,    -1,    -1,    71,    49,    15,    79,
      13,    79,   106,   108,   107,   109,    -1,    49,    -1,   107,
      56,    -1,    -1,   108,    45,    14,    48,    79,    -1,    69,
      48,    79,    -1,    69,    48,    79,    49,   109,    -1,    69,
      48,    79,    49,    56,   109,    -1,    69,    48,    79,    45,
     109,    -1,    69,    48,    79,    45,    56,   109,    -1,    21,
      69,    -1,   110,    45,    69,    -1,    79,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   130,   131,   132,   133,   134,   135,   138,
     141,   141,   147,   147,   153,   154,   157,   158,   161,   161,
     162,   163,   166,   167,   168,   178,   179,   180,   183,   184,
     190,   193,   196,   197,   200,   201,   202,   205,   206,   209,
     210,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   225,   233,   243,   244,   245,   246,   247,   251,   252,
     253,   254,   255,   256,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   281,
     282,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     296,   297,   300,   301,   302,   303,   304,   305,   306,   307,
     311,   311,   312,   312,   316,   317,   318,   319,   320,   324,
     325,   329,   333,   334,   335,   336,   337,   338,   340,   341,
     344,   345,   346,   347,   350,   351,   352,   353,   356,   357,
     358,   359,   362,   363,   364,   365,   368,   369,   370,   371,
     374,   375,   376,   377,   381,   382,   383,   384,   387,   388,
     389,   392,   395,   398,   399,   402,   403,   404,   405,   406,
     409,   410,   413,   413,   414,   414,   415,   415,   416,   416,
     419,   420,   423,   424,   431,   432,   433,   434,   435,   438,
     439,   442
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
  "\"'compartment'\"", "\"name of a pre-defined constant\"", "\"'const'\"",
  "\"--\"", "\"'delete'\"", "\"'DNA'\"", "\"...\"", "\"'end'\"",
  "\"'event'\"", "\"'formula'\"", "\"name of an existing function\"",
  "\"'function'\"", "\"'gene'\"", "\"'has'\"", "\"'import'\"", "\"'in'\"",
  "\"'is'\"", "\"name of an existing module\"", "\"'model' or 'module'\"",
  "\"'operator'\"", "\"'reaction'\"", "\"'species'\"", "\"text string\"",
  "\"'unit'\"", "\"'var'\"", "\"an error\"", "'('", "')'", "','", "'.'",
  "'$'", "'='", "':'", "';'", "'>'", "'<'", "'!'", "'{'", "'}'", "'\\n'",
  "'\\''", "$accept", "input", "import", "module", "$@1", "$@2",
  "maybemain", "function", "$@3", "spacedformula", "variableexportlist",
  "variable", "variablein", "varmaybein", "varmaybeis", "maybein",
  "modulebody", "modulepart", "reaction", "reactantList",
  "reactionDivider", "formula", "commaformula", "mathThing", "lineend",
  "assignment", "submodule", "$@4", "$@5", "variableimportlist",
  "submodifications", "varinitialize", "specinit", "formulainit",
  "reactioninit", "dnainit", "geneinit", "operatorinit", "compartmentinit",
  "varconstinit", "unitinit", "dnadef", "dnastrand", "dnamiddle", "event",
  "$@6", "$@7", "$@8", "$@9", "colonret", "eventmodifications",
  "assignmentlist", "deletion", "unitdef", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,    38,   124,    45,    43,    42,    47,
      37,    94,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,    40,    41,    44,    46,    36,    61,    58,
      59,    62,    60,    33,   123,   125,    10,    39
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    59,    59,    59,    59,    59,    60,
      62,    61,    63,    61,    61,    61,    64,    64,    66,    65,
      65,    65,    67,    67,    67,    68,    68,    68,    69,    69,
      69,    70,    71,    71,    72,    72,    72,    73,    73,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    76,    76,    77,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    78,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      85,    84,    86,    84,    87,    87,    87,    87,    87,    88,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    89,
      90,    90,    90,    90,    91,    91,    91,    91,    92,    92,
      92,    92,    93,    93,    93,    93,    94,    94,    94,    94,
      95,    95,    95,    95,    96,    96,    96,    96,    97,    97,
      97,    98,    98,    99,    99,   100,   100,   100,   100,   100,
     101,   101,   103,   102,   104,   102,   105,   102,   106,   102,
     107,   107,   108,   108,   109,   109,   109,   109,   109,   110,
     110,   111
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       0,     9,     0,     6,     2,     2,     0,     1,     0,     8,
       2,     2,     1,     2,     2,     0,     1,     3,     1,     3,
       2,     3,     1,     1,     1,     3,     3,     0,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     8,     6,     0,     1,     2,     3,     4,     2,     2,
       2,     2,     1,     2,     0,     2,     2,     2,     2,     2,
       4,     2,     3,     3,     3,     3,     3,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     5,     5,     3,     4,     4,     3,
       0,     9,     0,     7,     0,     1,     3,     1,     3,     0,
       5,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     3,     3,     2,     3,     3,     3,     2,     3,
       2,     3,     2,     3,     3,     3,     2,     3,     3,     3,
       2,     3,     3,     3,     2,     3,     3,     3,     2,     2,
       3,     4,     2,     1,     3,     2,     2,     2,     3,     1,
       2,     3,     0,     6,     0,     8,     0,     8,     0,    10,
       1,     2,     0,     5,     3,     5,     6,     5,     6,     2,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     7,     0,    28,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,     8,     0,    90,    91,     3,     4,     6,
      32,    49,     0,     5,     0,     0,    50,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
     153,   159,     0,     0,    55,   162,    32,    33,    34,   144,
       0,     0,     0,     0,     0,   130,     0,   149,   155,   156,
     179,   132,   124,    18,    21,    20,   136,     9,   102,    17,
      15,    14,     0,   140,   128,   120,   152,     0,     0,     0,
       0,     0,     0,     0,   148,    30,   160,     0,     0,     0,
      64,     0,    64,    53,     0,    41,     0,     0,    62,     0,
      53,    42,    43,    44,     0,     0,     0,     0,     0,     0,
       0,     0,    47,    45,   157,    46,     0,    48,     0,     0,
      82,    81,    83,    84,    89,    85,    67,    64,    68,    65,
      69,    64,     0,    86,    87,    88,    64,    66,    71,   172,
      64,    64,   146,   134,   126,   138,   142,   122,   158,     0,
     104,    12,    64,   145,   133,   125,   137,   141,   129,   121,
      31,    29,     0,   181,    99,    96,    93,    92,    64,     0,
      64,    54,     0,   154,    64,    59,    61,    60,    58,     0,
      56,    63,    54,     0,   123,   127,   131,   135,   139,   143,
     147,   150,   161,   180,    76,    77,   164,    79,     0,    74,
      73,    72,    75,     0,     0,    36,    35,    25,   107,   105,
       0,     0,    53,   151,     0,     0,   166,   100,    97,    53,
      98,    57,    64,   172,    70,    64,    78,     0,   170,     0,
       0,    26,   109,     0,    25,    53,    39,    95,    94,    64,
     172,   104,     0,    37,     0,    80,     0,   171,     0,   163,
      64,     0,    37,   108,   106,     0,    13,    40,   168,     0,
       0,    64,     0,    52,     0,    64,    64,     0,    22,    64,
      27,     0,   103,    53,   172,     0,   109,    37,    38,   165,
     173,   174,    19,    24,    23,     0,    53,     0,   167,    37,
      51,     0,     0,     0,    11,     0,   101,     0,   177,     0,
     175,   111,   110,   169,   178,   176
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    27,    28,   221,   222,    82,    29,   159,   277,
     240,    56,    57,    58,    59,   273,   245,   246,    34,    35,
     110,   173,   208,   148,    36,    37,    38,   251,   160,   220,
     262,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,   149,   233,   250,   284,   239,
     214,   259,    53,   174
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -240
static const yytype_int16 yypact[] =
{
    -240,   425,  -240,  -240,    47,  -240,  -240,    47,   477,    47,
      47,    47,    47,   164,    47,   -22,   -10,   147,    47,    47,
      47,    47,   528,  -240,    47,  -240,  -240,  -240,  -240,  -240,
     134,    26,    96,  -240,   -43,    21,  -240,   -43,   -43,   -43,
      25,    27,    32,    83,    94,   101,   120,   126,   -43,   -43,
    -240,    47,   -43,    92,    46,   109,   150,  -240,    49,  -240,
      47,    47,    47,    47,    47,  -240,    47,  -240,   -15,    47,
      46,  -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,
    -240,  -240,   178,  -240,  -240,  -240,    62,    47,    47,    47,
      47,    47,    47,    47,  -240,    46,  -240,    47,   181,    47,
    -240,    24,  -240,   155,   135,  -240,    52,    64,  -240,   192,
     121,  -240,  -240,  -240,    47,    47,    47,    47,    47,    47,
      47,    47,  -240,  -240,    61,  -240,    47,  -240,   205,   212,
    -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,
    -240,  -240,   171,   184,   189,   191,  -240,    46,  -240,  -240,
    -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,    61,   183,
     137,   198,  -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,
      46,  -240,   -27,   529,  -240,  -240,    23,   529,  -240,   202,
    -240,   -15,    21,  -240,  -240,  -240,  -240,  -240,  -240,    47,
      46,  -240,    46,     3,  -240,  -240,  -240,  -240,  -240,  -240,
    -240,  -240,  -240,    46,  -240,  -240,   529,   529,   166,  -240,
    -240,  -240,  -240,   196,   145,  -240,   529,    47,  -240,    46,
     169,   210,   652,   529,    47,    47,   332,  -240,   529,   121,
     529,    46,  -240,  -240,  -240,  -240,  -240,   241,  -240,    87,
     186,    46,  -240,   165,    47,   572,  -240,    46,    46,  -240,
    -240,   137,    15,   478,   145,   529,   209,  -240,   153,  -240,
     -43,    47,   -16,  -240,    46,   204,  -240,  -240,   529,   145,
     217,  -240,    47,  -240,    87,  -240,  -240,    43,   529,   -43,
      46,   245,  -240,   652,  -240,    87,  -240,   478,    46,  -240,
     529,    37,  -240,  -240,   -43,   215,   612,   145,  -240,   -16,
    -240,    91,   117,   173,  -240,    87,  -240,    47,  -240,    47,
    -240,  -240,    46,  -240,  -240,  -240
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,   -14,
      28,    -1,    11,    13,   303,  -175,    -9,     1,  -240,   -99,
      86,    56,  -240,  -240,   -13,  -240,  -240,  -240,  -240,    18,
     -11,  -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,
    -240,  -240,   167,   267,  -240,  -240,  -240,  -240,  -240,  -239,
    -232,    97,  -240,    54
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -55
static const yytype_int16 yytable[] =
{
      30,   254,    33,    54,   182,    96,   224,    25,    68,    70,
     107,   193,    31,    26,    32,   274,   272,    77,   269,    98,
      86,   105,   107,    95,   111,   112,   113,   106,   107,   281,
     285,    98,   225,    78,   -33,   122,   123,   108,     5,   125,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     124,     5,   297,   232,   147,   138,   -33,   185,   305,   -33,
     139,     5,    55,   175,   140,   271,   186,   292,   158,    98,
     114,    24,   115,   109,   -33,   -33,   189,   116,     5,   150,
     141,   202,   301,   -33,    24,   142,   302,   282,   143,   144,
     145,   146,    98,    25,    24,   187,   170,   151,   172,    26,
     176,     5,   181,   188,    99,     5,   190,    98,    98,   192,
     162,    24,   300,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     5,   306,   203,   100,   138,   117,   101,
     252,     5,   139,     4,    24,     5,   140,   126,    24,   118,
     -54,   -54,    25,   257,   102,   103,   119,   307,    26,   218,
     -54,     5,   141,   104,    96,    79,    24,   142,   177,   219,
     143,   144,   145,   146,    24,   120,    97,     4,    24,     5,
     178,   121,   147,   309,    80,     9,   147,   263,    73,     5,
      98,    81,    97,   184,    24,   311,   -54,     5,   231,   179,
     237,    74,   161,   206,   238,   171,    98,   207,    75,    98,
     213,   276,    24,   180,   215,   147,   147,   216,   191,   204,
     234,   235,    24,   242,   243,   147,   241,   205,   223,   209,
      24,    30,   147,   247,   248,   147,   217,   147,   192,   147,
     260,   261,   210,    31,   226,    32,   228,   211,   258,   212,
     230,   -10,   264,   241,    30,   227,   267,   279,   283,   261,
     219,   236,   147,   244,   147,   256,    31,   275,    32,   295,
     280,   286,   243,   303,   293,   294,   279,   147,   229,   270,
     183,   288,   265,   258,   296,   299,    69,   147,     0,     0,
       0,   293,    30,     0,   258,     0,   147,     0,   253,   147,
     147,   255,     0,     0,    31,    30,    32,   267,     0,     0,
     258,   258,   312,     0,   258,   268,   258,    31,   258,    32,
       0,    67,     0,     0,    71,    72,   278,    76,     0,     0,
       0,    83,    84,    85,     0,    94,     0,   287,     0,     0,
       0,   290,   291,     0,     0,   278,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   249,     5,     0,     0,     0,
     138,     0,     0,     0,     0,   139,     0,     0,     0,   140,
       0,     0,     0,   152,   153,   154,   155,   156,     0,   157,
       0,   289,     0,     0,     0,   141,     0,     0,     0,    24,
     142,     0,   298,   143,   144,   145,   146,     0,     0,     0,
     163,   164,   165,   166,   167,   168,   169,     0,   308,   310,
       0,     0,   313,     0,   314,     0,   315,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   194,   195,   196,
     197,   198,   199,   200,   201,     2,     3,     0,     0,     0,
       0,   -53,   -53,     0,     0,     0,     0,     4,     0,     5,
       6,   -53,     7,     0,     8,     9,    10,    11,     0,     0,
       0,    12,     0,    13,    14,     0,    15,     0,     0,    16,
      17,    18,    19,    20,     0,    21,    22,    23,     0,     0,
       0,     0,    24,     0,     0,    25,     0,   -53,     0,     0,
       0,    26,   128,   129,   130,   131,   132,   133,   134,   135,
     136,     5,     5,     0,    60,     0,   138,     0,     0,    61,
       0,   139,     0,    62,     0,   140,    63,     0,     0,     0,
     272,     0,     0,    64,    65,    66,     0,     0,     0,     0,
       0,   141,     0,     0,    24,    24,   142,     0,     0,   143,
     144,   145,   146,   128,   129,   130,   131,   132,   133,   134,
     135,   136,     5,     5,     0,    87,     0,   138,     0,     0,
      88,     0,   139,     0,    89,     0,   140,    90,     0,     0,
       0,     0,     0,     0,    91,    92,    93,     0,     0,     0,
       0,     0,   141,     0,     0,    24,    24,   142,     0,     0,
     143,   144,   145,   146,     4,     0,     5,     6,     0,     7,
       0,     8,     9,    10,    11,     0,   266,     0,    12,     0,
       0,    14,     0,     0,     0,     0,    16,     0,    18,    19,
      20,     0,    21,    22,     0,     0,     0,     0,     0,    24,
       0,     0,    25,     0,     4,     0,     5,     6,    26,     7,
       0,     8,     9,    10,    11,     0,   304,     0,    12,     0,
       0,    14,     0,     0,     0,     0,    16,     0,    18,    19,
      20,     0,    21,    22,     0,     0,     0,     0,     0,    24,
       0,     0,    25,     0,     4,     0,     5,     6,    26,     7,
       0,     8,     9,    10,    11,     0,     0,     0,    12,     0,
       0,    14,     0,     0,     0,     0,    16,     0,    18,    19,
      20,     0,    21,    22,     0,     0,     0,     0,     0,    24,
       0,     0,    25,     0,     0,     0,     0,     0,    26
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-240)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,   233,     1,     4,   103,    20,    33,    50,     9,    10,
       7,   110,     1,    56,     1,   254,    32,    39,   250,    46,
      21,    34,     7,    24,    37,    38,    39,     6,     7,    45,
     269,    46,     9,    43,     8,    48,    49,    16,    14,    52,
      53,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      51,    14,   284,    50,    55,    18,    30,     5,   297,    33,
      23,    14,     6,    39,    27,    50,    14,    24,    69,    46,
      45,    47,    45,    52,    48,    49,    12,    45,    14,    30,
      43,    20,    45,    57,    47,    48,    49,   262,    51,    52,
      53,    54,    46,    50,    47,    43,    97,    48,    99,    56,
     101,    14,   103,    51,     8,    14,   107,    46,    46,   110,
      48,    47,   287,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,   299,   126,    30,    18,    45,    33,
     229,    14,    23,    12,    47,    14,    27,    45,    47,    45,
       6,     7,    50,    56,    48,    49,    45,    56,    56,    12,
      16,    14,    43,    57,    20,     8,    47,    48,   102,   160,
      51,    52,    53,    54,    47,    45,    32,    12,    47,    14,
      15,    45,   173,    56,    27,    20,   177,    12,    14,    14,
      46,    34,    32,    48,    47,    12,    52,    14,   189,    34,
      45,    27,    14,   137,    49,    14,    46,   141,    34,    46,
     146,    48,    47,    48,   150,   206,   207,   151,    16,     4,
      44,    45,    47,    44,    45,   216,   217,     5,   162,    48,
      47,   222,   223,   224,   225,   226,    43,   228,   229,   230,
      44,    45,    48,   222,   178,   222,   180,    48,   239,    48,
     184,    43,   243,   244,   245,    43,   245,   260,    44,    45,
     251,    55,   253,    43,   255,    14,   245,    48,   245,    14,
     261,    44,    45,    48,   277,   279,   279,   268,   182,   251,
     103,   272,   244,   274,   283,   286,     9,   278,    -1,    -1,
      -1,   294,   283,    -1,   285,    -1,   287,    -1,   232,   290,
     291,   235,    -1,    -1,   283,   296,   283,   296,    -1,    -1,
     301,   302,   303,    -1,   305,   249,   307,   296,   309,   296,
      -1,     8,    -1,    -1,    11,    12,   260,    14,    -1,    -1,
      -1,    18,    19,    20,    -1,    22,    -1,   271,    -1,    -1,
      -1,   275,   276,    -1,    -1,   279,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    -1,    66,
      -1,   274,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,
      48,    -1,   285,    51,    52,    53,    54,    -1,    -1,    -1,
      87,    88,    89,    90,    91,    92,    93,    -1,   301,   302,
      -1,    -1,   305,    -1,   307,    -1,   309,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,
     117,   118,   119,   120,   121,     0,     1,    -1,    -1,    -1,
      -1,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    -1,    28,    29,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    38,    -1,    40,    41,    42,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    -1,    52,    -1,    -1,
      -1,    56,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    14,    14,    -1,    17,    -1,    18,    -1,    -1,    22,
      -1,    23,    -1,    26,    -1,    27,    29,    -1,    -1,    -1,
      32,    -1,    -1,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    47,    47,    48,    -1,    -1,    51,
      52,    53,    54,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    14,    14,    -1,    17,    -1,    18,    -1,    -1,
      22,    -1,    23,    -1,    26,    -1,    27,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    47,    47,    48,    -1,    -1,
      51,    52,    53,    54,    12,    -1,    14,    15,    -1,    17,
      -1,    19,    20,    21,    22,    -1,    24,    -1,    26,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    -1,    12,    -1,    14,    15,    56,    17,
      -1,    19,    20,    21,    22,    -1,    24,    -1,    26,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    -1,    12,    -1,    14,    15,    56,    17,
      -1,    19,    20,    21,    22,    -1,    -1,    -1,    26,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    59,     0,     1,    12,    14,    15,    17,    19,    20,
      21,    22,    26,    28,    29,    31,    34,    35,    36,    37,
      38,    40,    41,    42,    47,    50,    56,    60,    61,    65,
      69,    70,    71,    75,    76,    77,    82,    83,    84,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   110,    69,    79,    69,    70,    71,    72,
      17,    22,    26,    29,    36,    37,    38,    72,    69,   101,
      69,    72,    72,    14,    27,    34,    72,    39,    43,     8,
      27,    34,    64,    72,    72,    72,    69,    17,    22,    26,
      29,    36,    37,    38,    72,    69,    20,    32,    46,     8,
      30,    33,    48,    49,    57,    82,     6,     7,    16,    52,
      78,    82,    82,    82,    45,    45,    45,    45,    45,    45,
      45,    45,    82,    82,    69,    82,    45,    82,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    18,    23,
      27,    43,    48,    51,    52,    53,    54,    69,    81,   103,
      30,    48,    72,    72,    72,    72,    72,    72,    69,    66,
      86,    14,    48,    72,    72,    72,    72,    72,    72,    72,
      69,    14,    69,    79,   111,    39,    69,    79,    15,    34,
      48,    69,    77,   100,    48,     5,    14,    43,    51,    12,
      69,    16,    69,    77,    72,    72,    72,    72,    72,    72,
      72,    72,    20,    69,     4,     5,    79,    79,    80,    48,
      48,    48,    48,   111,   108,   111,    79,    43,    12,    69,
      87,    62,    63,    79,    33,     9,    79,    43,    79,    78,
      79,    69,    50,   104,    44,    45,    55,    45,    49,   107,
      68,    69,    44,    45,    43,    74,    75,    69,    69,    13,
     105,    85,    77,    79,   108,    79,    14,    56,    69,   109,
      44,    45,    88,    12,    69,    68,    24,    75,    79,   108,
      87,    50,    32,    73,   107,    48,    48,    67,    79,    82,
      69,    45,    73,    44,   106,   107,    44,    79,    69,   109,
      79,    79,    24,    82,    67,    14,    74,   108,   109,    88,
      73,    45,    49,    48,    24,   107,    73,    56,   109,    56,
     109,    12,    69,   109,   109,   109
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
        case 3:
/* Line 1787 of yacc.c  */
#line 130 "antimony.ypp"
    {}
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 131 "antimony.ypp"
    { /*cout << endl << $2->ToString() << endl << endl;*/ }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 132 "antimony.ypp"
    {}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 133 "antimony.ypp"
    {}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 134 "antimony.ypp"
    {YYABORT;}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 135 "antimony.ypp"
    {YYABORT;}
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 138 "antimony.ypp"
    { if (g_registry.OpenFile(*((yyvsp[(2) - (2)].word)))==0) YYABORT;}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 141 "antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(3) - (3)].word), (yyvsp[(2) - (3)].maybemain));}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 142 "antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 147 "antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(3) - (3)].word), (yyvsp[(2) - (3)].maybemain));}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 148 "antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 153 "antimony.ypp"
    {g_registry.SetError("module '" + *((yyvsp[(2) - (2)].word)) + "' already defined."); YYABORT;}
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 154 "antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a module because it is already a defined function."); YYABORT;}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 157 "antimony.ypp"
    {(yyval.maybemain) = false;}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 158 "antimony.ypp"
    {(yyval.maybemain) = true;}
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 161 "antimony.ypp"
    {g_registry.NewUserFunction((yyvsp[(2) - (2)].word));}
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 161 "antimony.ypp"
    {if (g_registry.SetUserFunction((yyvsp[(7) - (8)].formula))) YYABORT;}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 162 "antimony.ypp"
    {g_registry.SetError("Cannot use '" + *((yyvsp[(2) - (2)].word)) +"' as a function name because it is already the name of a module."); YYABORT;}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 163 "antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a new function because it is already a defined function."); YYABORT;}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 166 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (1)].formula);}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 167 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(2) - (2)].formula);}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 168 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula);}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 178 "antimony.ypp"
    {}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 179 "antimony.ypp"
    {if (g_registry.AddVariableToCurrentExportList((yyvsp[(1) - (1)].variable))) YYABORT; }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 180 "antimony.ypp"
    { if (g_registry.AddVariableToCurrentExportList((yyvsp[(3) - (3)].variable))) YYABORT; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 183 "antimony.ypp"
    {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[(1) - (1)].word)); }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 184 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable)->GetSubVariable((yyvsp[(3) - (3)].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[(3) - (3)].word)) + "' is not a subvariable of '" + (yyvsp[(1) - (3)].variable)->GetNameDelimitedBy(".") + "'.");
                    YYABORT;
                  }
                }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 190 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 193 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetCompartment((yyvsp[(3) - (3)].variable))) YYABORT; (yyval.variable) = (yyvsp[(1) - (3)].variable);}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 196 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 197 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 200 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 201 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable); if ((yyvsp[(1) - (3)].variable)->SetFormula((yyvsp[(3) - (3)].formula))) YYABORT; }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 202 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable); if ((yyvsp[(1) - (3)].variable)->SetUnit((yyvsp[(3) - (3)].variable))) YYABORT; }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 205 "antimony.ypp"
    {(yyval.variable) = NULL;}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 206 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable);}
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 209 "antimony.ypp"
    {}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 210 "antimony.ypp"
    {}
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 213 "antimony.ypp"
    {}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 214 "antimony.ypp"
    {}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 215 "antimony.ypp"
    {}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 216 "antimony.ypp"
    {}
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 217 "antimony.ypp"
    {}
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 218 "antimony.ypp"
    {}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 219 "antimony.ypp"
    {}
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 220 "antimony.ypp"
    {}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 221 "antimony.ypp"
    {}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 222 "antimony.ypp"
    {}
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 226 "antimony.ypp"
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[(4) - (8)].reactionDivider), (yyvsp[(7) - (8)].formula), (yyvsp[(1) - (8)].variable));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[(8) - (8)].variable) != NULL) {
                    if ((yyvsp[(1) - (8)].variable)->SetCompartment((yyvsp[(8) - (8)].variable))) YYABORT;
                  }
                }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 234 "antimony.ypp"
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[(2) - (6)].reactionDivider), (yyvsp[(5) - (6)].formula));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[(6) - (6)].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[(6) - (6)].variable))) YYABORT;
                  }
                }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 243 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 244 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(1) - (1)].variable)); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 245 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(2) - (2)].variable), (yyvsp[(1) - (2)].num)); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 246 "antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (3)].reactantList); (yyvsp[(1) - (3)].reactantList)->AddReactant((yyvsp[(3) - (3)].variable)); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 247 "antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (4)].reactantList); (yyvsp[(1) - (4)].reactantList)->AddReactant((yyvsp[(4) - (4)].variable), (yyvsp[(3) - (4)].num)); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 251 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 252 "antimony.ypp"
    {(yyval.reactionDivider) = rdInhibits;}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 253 "antimony.ypp"
    {(yyval.reactionDivider) = rdInfluences;}
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 254 "antimony.ypp"
    {if (*(yyvsp[(2) - (2)].word) != "o") {g_registry.SetError("'-" + *(yyvsp[(2) - (2)].word) + "' is not a valid set of characters to demark reactions.  Try '->' for reactions, and '-|', '-o', and '-(' for interactions."); YYABORT;} (yyval.reactionDivider) = rdActivates;}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 255 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomesIrreversibly;}
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 256 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;}
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 259 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 260 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddEllipses();}
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 261 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddVariable((yyvsp[(2) - (2)].variable)); }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 262 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddNum((yyvsp[(2) - (2)].num)); }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 263 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddText((yyvsp[(2) - (2)].word)); }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 264 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddText((yyvsp[(2) - (2)].word)); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 265 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (4)].formula); (yyvsp[(3) - (4)].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[(3) - (4)].formula)); }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 266 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddMathThing((yyvsp[(2) - (2)].character)); }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 267 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('<'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 268 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('>'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 269 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('='); (yyvsp[(1) - (3)].formula)->AddMathThing('='); }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 270 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('!'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 271 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 272 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 274 "antimony.ypp"
    {
                  //Need to create a variable to be this unit definition, or find one that already has this unit definition, and then use that name.
                  (yyval.formula) = (yyvsp[(1) - (4)].formula);
                  (yyval.formula)->AddVariable((yyvsp[(3) - (4)].variable));
                }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 281 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (1)].formula);}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 282 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[(3) - (3)].formula)); }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 285 "antimony.ypp"
    {(yyval.character) = '+';}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 286 "antimony.ypp"
    {(yyval.character) = '-';}
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 287 "antimony.ypp"
    {(yyval.character) = '*';}
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 288 "antimony.ypp"
    {(yyval.character) = '/';}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 289 "antimony.ypp"
    {(yyval.character) = '^';}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 290 "antimony.ypp"
    {(yyval.character) = '>';}
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 291 "antimony.ypp"
    {(yyval.character) = '<';}
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 292 "antimony.ypp"
    {(yyval.character) = '!';}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 293 "antimony.ypp"
    {(yyval.character) = '%';}
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 296 "antimony.ypp"
    {}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 297 "antimony.ypp"
    {}
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 300 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetFormula((yyvsp[(3) - (3)].formula))) YYABORT; }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 301 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->Synchronize((yyvsp[(3) - (3)].variable), NULL)) YYABORT;}
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 302 "antimony.ypp"
    {if ((yyvsp[(1) - (5)].variable)->Synchronize((yyvsp[(3) - (5)].variable), (yyvsp[(5) - (5)].variable))) YYABORT;}
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 303 "antimony.ypp"
    {if ((yyvsp[(1) - (5)].variable)->Synchronize((yyvsp[(5) - (5)].variable), (yyvsp[(3) - (5)].variable))) YYABORT;}
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 304 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetDisplayName(*((yyvsp[(3) - (3)].word)))) YYABORT;}
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 305 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetAssignmentRule((yyvsp[(4) - (4)].formula))) YYABORT;}
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 306 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetRateRule((yyvsp[(4) - (4)].formula))) YYABORT;}
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 307 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetUnit((yyvsp[(3) - (3)].variable))) YYABORT; }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 311 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetModule((yyvsp[(3) - (4)].word))) YYABORT;}
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 311 "antimony.ypp"
    {if ((yyvsp[(9) - (9)].variable) != NULL) {if ((yyvsp[(1) - (9)].variable)->SetCompartment((yyvsp[(9) - (9)].variable))) YYABORT;}}
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 312 "antimony.ypp"
    {if(g_registry.CurrentModule()->SetModule((yyvsp[(1) - (2)].word))) YYABORT;}
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 312 "antimony.ypp"
    {if ((yyvsp[(7) - (7)].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[(7) - (7)].variable))) YYABORT;}}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 316 "antimony.ypp"
    {}
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 317 "antimony.ypp"
    {if (g_registry.AddVariableToCurrentImportList((yyvsp[(1) - (1)].variable))) YYABORT; }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 318 "antimony.ypp"
    { if (g_registry.AddVariableToCurrentImportList((yyvsp[(3) - (3)].variable))) YYABORT; }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 319 "antimony.ypp"
    {if (g_registry.AddNumberToCurrentImportList((yyvsp[(1) - (1)].num))) YYABORT; }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 320 "antimony.ypp"
    { if (g_registry.AddNumberToCurrentImportList((yyvsp[(3) - (3)].num))) YYABORT; }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 324 "antimony.ypp"
    {}
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 325 "antimony.ypp"
    {if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[(5) - (5)].variable));}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[(5) - (5)].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[(3) - (5)].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 329 "antimony.ypp"
    {if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[(5) - (5)].num));}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[(5) - (5)].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[(3) - (5)].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 333 "antimony.ypp"
    { }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 334 "antimony.ypp"
    { }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 335 "antimony.ypp"
    { }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 336 "antimony.ypp"
    { }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 337 "antimony.ypp"
    { }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 338 "antimony.ypp"
    { }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 340 "antimony.ypp"
    { }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 341 "antimony.ypp"
    { }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 344 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varSpeciesUndef)) YYABORT; }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 345 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 346 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 347 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 350 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaUndef)) YYABORT; }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 351 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 352 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 353 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 356 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varReactionUndef)) YYABORT; }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 357 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 358 "antimony.ypp"
    {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 359 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 362 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varDNA)) YYABORT; }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 363 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 364 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 365 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 368 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varReactionGene)) YYABORT; }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 369 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 370 "antimony.ypp"
    {g_registry.SetError("Genes may not be set 'const'."); YYABORT; }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 371 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 374 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaOperator)) YYABORT; }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 375 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; }
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 376 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; }
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 377 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; }
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 381 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varCompartment)) YYABORT; }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 382 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; }
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 383 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 384 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; }
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 387 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(2) - (2)].variable)->SetRegConst();}
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 388 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(2) - (2)].variable)->SetRegConst();}
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 389 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst();}
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 392 "antimony.ypp"
    {if ((yyvsp[(2) - (4)].variable)->SetType(varUnitDefinition)) YYABORT;
                                               if ((yyvsp[(4) - (4)].formula)->MakeAllVariablesUnits()) YYABORT;
                                               if ((yyvsp[(2) - (4)].variable)->GetUnitDef()->SetFromFormula((yyvsp[(4) - (4)].formula))) YYABORT;}
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 395 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varUnitDefinition)) YYABORT;}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 398 "antimony.ypp"
    {if (g_registry.SaveWorkingStrand()) YYABORT;}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 399 "antimony.ypp"
    {if (g_registry.SetStrandAs((yyvsp[(1) - (3)].variable))) YYABORT;}
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 402 "antimony.ypp"
    {if (g_registry.SetNewUpstreamOpen((yyvsp[(2) - (2)].variable))) YYABORT;}
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 403 "antimony.ypp"
    {g_registry.SetOpenUpstream(); }
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 404 "antimony.ypp"
    {if (g_registry.SetDownstreamEnd((yyvsp[(2) - (2)].variable))) YYABORT;}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 405 "antimony.ypp"
    {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[(3) - (3)].variable))) YYABORT;}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 406 "antimony.ypp"
    { }
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 409 "antimony.ypp"
    {if (g_registry.SetNewDownstreamOpen((yyvsp[(1) - (2)].variable))) YYABORT;}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 410 "antimony.ypp"
    {if (g_registry.SetDownstreamOpen((yyvsp[(2) - (3)].variable))) YYABORT;}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 413 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(2) - (2)].formula))) YYABORT;}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 413 "antimony.ypp"
    {}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 414 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(2) - (4)].formula), (yyvsp[(4) - (4)].formula))) YYABORT;}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 414 "antimony.ypp"
    {}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 415 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (4)].formula), (yyvsp[(1) - (4)].variable))) YYABORT;}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 415 "antimony.ypp"
    {}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 416 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (6)].formula), (yyvsp[(6) - (6)].formula), (yyvsp[(1) - (6)].variable))) YYABORT;}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 416 "antimony.ypp"
    {}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 419 "antimony.ypp"
    {}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 420 "antimony.ypp"
    {}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 423 "antimony.ypp"
    {}
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 424 "antimony.ypp"
    {if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[(5) - (5)].formula));}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[(3) - (5)].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;}}
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 431 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (3)].variable), (yyvsp[(3) - (3)].formula))) YYABORT;}
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 432 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (5)].variable), (yyvsp[(3) - (5)].formula))) YYABORT;}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 433 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (6)].variable), (yyvsp[(3) - (6)].formula))) YYABORT;}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 434 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (5)].variable), (yyvsp[(3) - (5)].formula))) YYABORT;}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 435 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (6)].variable), (yyvsp[(3) - (6)].formula))) YYABORT;}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 438 "antimony.ypp"
    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[(2) - (2)].variable))) YYABORT;}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 439 "antimony.ypp"
    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[(3) - (3)].variable))) YYABORT;}
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 442 "antimony.ypp"
    {
                    if ((yyvsp[(1) - (1)].formula)->MakeAllVariablesUnits()) YYABORT;
                    if ((yyvsp[(1) - (1)].formula)->IsSingleVariable()) {
                      (yyval.variable) = g_registry.CurrentModule()->GetVariable(((yyvsp[(1) - (1)].formula)->GetVariables())[0]);
                      if ((yyval.variable)==NULL) YYABORT;
                    }
                    else {
                      UnitDef* ud = new UnitDef("", g_registry.CurrentModule()->GetModuleName());
                      if ((yyvsp[(1) - (1)].formula)->MakeAllVariablesUnits()) YYABORT;
                      if (ud->SetFromFormula((yyvsp[(1) - (1)].formula))) YYABORT;
                      (yyval.variable) = g_registry.CurrentModule()->AddOrFindUnitDef(ud);
                    }
                }
    break;


/* Line 1787 of yacc.c  */
#line 2932 "antimony.tab.cpp"
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


/* Line 2050 of yacc.c  */
#line 456 "antimony.ypp"



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
