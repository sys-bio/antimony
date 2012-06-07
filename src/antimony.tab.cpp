/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "antimony.ypp"

  //#define YYSTYPE double
#include <math.h>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <set>
#ifndef NSBML
#include <sbml/SBMLTypes.h>
#endif
#include "registry.h"
#include "module.h"
#include "unitdef.h"

  class Formula;
  class ReactantList;
  class AntimonyReaction;
  class Variable;

  using namespace std;
  int yylex(void);
  void yyerror(char const *);
  bool CaselessStrCmp(const string& lhs, const string& rhs);
  Registry g_registry;
  int yylloc_first_line = 1;
  int yylloc_last_line = 1;
  std::vector<int> yylloc_last_lines;


/* Line 189 of yacc.c  */
#line 104 "antimony.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     YYEOF = 0,
     NUM = 259,
     ANTWORD = 260,
     MODNAME = 261,
     TEXTSTRING = 262,
     MODULE = 263,
     END = 264,
     SPECIES = 265,
     REACTION = 266,
     FORMULA = 267,
     DNA = 268,
     GENE = 269,
     OPERATOR = 270,
     EVENT = 271,
     COMPARTMENT = 272,
     INWORD = 273,
     HASWORD = 274,
     IS = 275,
     VARWORD = 276,
     CONSTWORD = 277,
     DASHES = 278,
     BECOMESIRREV = 279,
     ELLIPSES = 280,
     FUNCTION = 281,
     IMPORT = 282,
     AT = 283,
     AFTER = 284,
     FUNCTIONWORD = 285,
     UNITWORD = 286
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 34 "antimony.ypp"

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
  UnitDef*  unitdef;
  bool maybemain;



/* Line 214 of yacc.c  */
#line 191 "antimony.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 203 "antimony.tab.cpp"

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   828

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNRULES -- Number of states.  */
#define YYNSTATES  324

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      52,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,     2,    41,     2,    49,    53,
      38,    39,     6,     4,     9,     5,    40,     7,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    44,
      47,    42,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     8,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,    46,    51,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    19,    22,
      23,    33,    34,    41,    44,    47,    48,    50,    51,    60,
      63,    66,    68,    71,    74,    75,    77,    81,    83,    87,
      90,    94,    96,    98,   100,   104,   108,   109,   112,   114,
     117,   120,   123,   126,   129,   132,   135,   138,   140,   142,
     151,   158,   159,   161,   164,   168,   173,   176,   179,   182,
     185,   187,   190,   191,   193,   195,   197,   202,   204,   206,
     210,   213,   216,   219,   225,   228,   231,   236,   240,   244,
     248,   252,   256,   260,   265,   267,   271,   273,   275,   277,
     279,   281,   283,   285,   287,   289,   291,   295,   299,   303,
     308,   313,   314,   323,   324,   331,   332,   334,   338,   340,
     342,   344,   346,   348,   350,   352,   354,   357,   361,   365,
     369,   372,   376,   380,   384,   387,   391,   394,   398,   401,
     405,   409,   413,   416,   420,   424,   428,   431,   435,   439,
     443,   446,   450,   454,   458,   461,   464,   468,   473,   476,
     478,   482,   485,   488,   491,   495,   497,   500,   504,   505,
     512,   513,   522,   523,   532,   533,   544,   546,   549,   550,
     555,   561,   565,   571,   578,   584,   591,   593,   597,   601,
     605,   609,   613
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    -1,    55,    56,    -1,    55,    57,    -1,
      55,    71,    -1,    55,    61,    -1,    55,     1,    -1,    33,
      13,    -1,    -1,    14,    60,    11,    58,    38,    64,    39,
      70,    15,    -1,    -1,    14,    60,    11,    59,    70,    15,
      -1,    14,    12,    -1,    14,    32,    -1,    -1,     6,    -1,
      -1,    36,    11,    62,    38,    64,    39,    63,    15,    -1,
      36,    12,    -1,    36,    32,    -1,    75,    -1,    78,    63,
      -1,    63,    78,    -1,    -1,    65,    -1,    64,     9,    65,
      -1,    11,    -1,    65,    40,    11,    -1,    41,    65,    -1,
      65,    24,    65,    -1,    65,    -1,    66,    -1,    67,    -1,
      67,    42,    75,    -1,    68,    25,   105,    -1,    -1,    24,
      65,    -1,    71,    -1,    70,    71,    -1,    72,    78,    -1,
      79,    78,    -1,    80,    78,    -1,    84,    78,    -1,    94,
      78,    -1,    97,    78,    -1,    93,    78,    -1,    66,    -1,
      78,    -1,    67,    43,    73,    74,    73,    44,    75,    69,
      -1,    73,    74,    73,    44,    75,    69,    -1,    -1,    65,
      -1,    10,    65,    -1,    73,     4,    65,    -1,    73,     4,
      10,    65,    -1,     5,    45,    -1,     5,    46,    -1,     5,
      38,    -1,     5,    11,    -1,    30,    -1,    47,    30,    -1,
      -1,    31,    -1,    65,    -1,    10,    -1,    32,    38,    76,
      39,    -1,    32,    -1,    77,    -1,    38,    76,    39,    -1,
      75,    31,    -1,    75,    65,    -1,    75,    10,    -1,    75,
      32,    38,    76,    39,    -1,    75,    32,    -1,    75,    77,
      -1,    75,    38,    76,    39,    -1,    75,    47,    42,    -1,
      75,    45,    42,    -1,    75,    42,    42,    -1,    75,    48,
      42,    -1,    75,    49,    49,    -1,    75,    46,    46,    -1,
      75,    50,   105,    51,    -1,    75,    -1,    76,     9,    75,
      -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,     8,
      -1,    45,    -1,    47,    -1,    48,    -1,    44,    -1,    52,
      -1,    67,    42,    75,    -1,    67,    26,    65,    -1,    67,
      26,    13,    -1,    67,    43,    42,    75,    -1,    67,    53,
      42,    75,    -1,    -1,    67,    43,    12,    38,    81,    83,
      39,    69,    -1,    -1,    12,    38,    82,    83,    39,    69,
      -1,    -1,    65,    -1,    83,     9,    65,    -1,    85,    -1,
      86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,
      91,    -1,    92,    -1,    16,    68,    -1,    27,    16,    68,
      -1,    28,    16,    68,    -1,    85,     9,    68,    -1,    18,
      68,    -1,    27,    18,    68,    -1,    28,    18,    68,    -1,
      86,     9,    68,    -1,    17,    68,    -1,    27,    17,    68,
      -1,    28,    17,    -1,    87,     9,    68,    -1,    19,    68,
      -1,    27,    19,    68,    -1,    28,    19,    68,    -1,    88,
       9,    68,    -1,    20,    68,    -1,    27,    20,    68,    -1,
      28,    20,    68,    -1,    89,     9,    68,    -1,    21,    68,
      -1,    27,    21,    68,    -1,    28,    21,    68,    -1,    90,
       9,    68,    -1,    23,    68,    -1,    27,    23,    68,    -1,
      28,    23,    68,    -1,    91,     9,    68,    -1,    27,    68,
      -1,    28,    68,    -1,    92,     9,    68,    -1,    37,    11,
      42,   105,    -1,    37,    11,    -1,    95,    -1,    67,    43,
      95,    -1,    29,    65,    -1,    29,    96,    -1,    96,    65,
      -1,    29,    96,    65,    -1,    96,    -1,    65,    29,    -1,
      96,    65,    29,    -1,    -1,    34,    75,    98,   103,   102,
     104,    -1,    -1,    34,    75,    35,    75,    99,   103,   102,
     104,    -1,    -1,    67,    43,    34,    75,   100,   103,   102,
     104,    -1,    -1,    67,    43,    34,    75,    35,    75,   101,
     103,   102,   104,    -1,    43,    -1,   102,    52,    -1,    -1,
       9,    11,    42,    75,    -1,   103,     9,    11,    42,    75,
      -1,    65,    42,    75,    -1,    65,    42,    75,    43,   104,
      -1,    65,    42,    75,    43,    52,   104,    -1,    65,    42,
      75,     9,   104,    -1,    65,    42,    75,     9,    52,   104,
      -1,    11,    -1,    38,   105,    39,    -1,   105,     6,   105,
      -1,   105,     7,   105,    -1,   105,     8,    10,    -1,    10,
       7,   105,    -1,    10,   105,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,    99,   100,   101,   102,   103,   106,   109,
     109,   115,   115,   121,   122,   125,   126,   129,   129,   130,
     131,   134,   135,   136,   140,   141,   142,   145,   146,   152,
     155,   158,   159,   162,   163,   164,   167,   168,   171,   172,
     175,   176,   177,   178,   179,   180,   181,   183,   184,   187,
     195,   205,   206,   207,   208,   209,   213,   214,   215,   216,
     217,   218,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   245,   246,   249,   250,   251,   252,
     253,   254,   255,   256,   259,   260,   263,   264,   265,   266,
     267,   270,   270,   271,   271,   274,   275,   276,   279,   280,
     281,   282,   283,   284,   286,   287,   290,   291,   292,   293,
     296,   297,   298,   299,   302,   303,   304,   305,   308,   309,
     310,   311,   314,   315,   316,   317,   320,   321,   322,   323,
     327,   328,   329,   330,   333,   334,   335,   338,   339,   342,
     343,   346,   347,   348,   349,   350,   353,   354,   357,   357,
     358,   358,   359,   359,   360,   360,   363,   364,   367,   368,
     373,   380,   381,   382,   383,   384,   392,   393,   394,   395,
     396,   397,   398
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"mathematical symbol\"",
  "'+'", "'-'", "'*'", "'/'", "'^'", "','", "\"number\"",
  "\"element name\"", "\"name of an existing module\"", "\"text string\"",
  "\"'model' or 'module'\"", "\"'end'\"", "\"'species'\"",
  "\"'reaction'\"", "\"'formula'\"", "\"'DNA'\"", "\"'gene'\"",
  "\"'operator'\"", "\"'event'\"", "\"'compartment'\"", "\"'in'\"",
  "\"'has'\"", "\"'is'\"", "\"'var'\"", "\"'const'\"", "\"--\"", "\"=>\"",
  "\"...\"", "\"name of an existing function\"", "\"'import'\"",
  "\"'@' or 'at'\"", "\"'after'\"", "\"'function'\"", "\"'unit'\"", "'('",
  "')'", "'.'", "'$'", "'='", "':'", "';'", "'>'", "'|'", "'<'", "'!'",
  "'&'", "'{'", "'}'", "'\\n'", "'\\''", "$accept", "input", "import",
  "module", "$@1", "$@2", "maybemain", "function", "$@3", "spacedformula",
  "variableexportlist", "variable", "variablein", "varmaybein",
  "varmaybeis", "maybein", "modulebody", "modulepart", "reaction",
  "reactantList", "reactionDivider", "formula", "commaformula",
  "mathThing", "lineend", "assignment", "submodule", "$@4", "$@5",
  "variableimportlist", "varinitialize", "specinit", "formulainit",
  "reactioninit", "dnainit", "geneinit", "operatorinit", "compartmentinit",
  "varconstinit", "unitinit", "dnadef", "dnastrand", "dnamiddle", "event",
  "$@6", "$@7", "$@8", "$@9", "colonret", "eventmodifications",
  "assignmentlist", "unitdef", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,    43,    45,    42,    47,    94,    44,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,    40,    41,
      46,    36,    61,    58,    59,    62,   124,    60,    33,    38,
     123,   125,    10,    39
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    55,    55,    56,    58,
      57,    59,    57,    57,    57,    60,    60,    62,    61,    61,
      61,    63,    63,    63,    64,    64,    64,    65,    65,    65,
      66,    67,    67,    68,    68,    68,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    73,    73,    73,    73,    73,    74,    74,    74,    74,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    79,    79,    79,    79,
      79,    81,    80,    82,    80,    83,    83,    83,    84,    84,
      84,    84,    84,    84,    84,    84,    85,    85,    85,    85,
      86,    86,    86,    86,    87,    87,    87,    87,    88,    88,
      88,    88,    89,    89,    89,    89,    90,    90,    90,    90,
      91,    91,    91,    91,    92,    92,    92,    93,    93,    94,
      94,    95,    95,    95,    95,    95,    96,    96,    98,    97,
      99,    97,   100,    97,   101,    97,   102,   102,   103,   103,
     103,   104,   104,   104,   104,   104,   105,   105,   105,   105,
     105,   105,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     0,
       9,     0,     6,     2,     2,     0,     1,     0,     8,     2,
       2,     1,     2,     2,     0,     1,     3,     1,     3,     2,
       3,     1,     1,     1,     3,     3,     0,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     8,
       6,     0,     1,     2,     3,     4,     2,     2,     2,     2,
       1,     2,     0,     1,     1,     1,     4,     1,     1,     3,
       2,     2,     2,     5,     2,     2,     4,     3,     3,     3,
       3,     3,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     4,
       4,     0,     8,     0,     6,     0,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     3,
       2,     3,     3,     3,     2,     3,     2,     3,     2,     3,
       3,     3,     2,     3,     3,     3,     2,     3,     3,     3,
       2,     3,     3,     3,     2,     2,     3,     4,     2,     1,
       3,     2,     2,     2,     3,     1,     2,     3,     0,     6,
       0,     8,     0,     8,     0,    10,     1,     2,     0,     4,
       5,     3,     5,     6,     5,     6,     1,     3,     3,     3,
       3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     7,     0,    27,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,    94,    95,     3,     4,     6,    31,    47,
       0,     5,     0,     0,    48,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,     0,     0,   149,   155,
       0,    53,   103,    16,    13,    14,     0,    31,    32,    33,
     116,   124,   120,   128,   132,   136,   140,     0,     0,     0,
       0,     0,     0,     0,   144,     0,   126,     0,     0,     0,
       0,     0,   145,   151,   152,     8,    86,    87,    88,    89,
      90,    65,    63,    67,    62,    91,    92,    93,    64,   158,
      68,    17,    19,    20,   148,    29,     0,   156,     0,     0,
      62,    51,     0,    40,     0,     0,    60,     0,    51,    41,
      42,    43,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    44,   153,    45,   105,    11,    62,     0,   117,   125,
     121,   129,   133,   137,   141,   118,   122,   130,   134,   138,
     142,   154,    62,    84,     0,    72,    70,    74,    62,    62,
       0,    91,     0,    92,    93,     0,     0,    71,    75,   168,
       0,     0,    30,    28,    98,    97,    96,     0,    62,    62,
      52,     0,   150,    62,     0,    54,    59,    58,    56,    57,
      61,    52,     0,   119,   123,   127,   131,   135,   139,   143,
     146,   157,   106,     0,     0,    51,    34,     0,   176,     0,
      35,     0,    62,    69,    62,   160,     0,    79,    78,    82,
      77,    80,    81,     0,     0,     0,    24,   147,   101,   162,
      99,    51,   100,    55,    62,     0,    36,    24,    51,    38,
       0,   182,     0,     0,     0,     0,    66,    85,     0,   168,
      76,    83,     0,     0,   166,     0,     0,    25,   105,    62,
     168,     0,    36,   107,     0,   104,     0,    12,    39,   181,
     177,   178,   179,   180,    73,     0,    62,     0,   167,     0,
     159,     0,    62,     0,   164,     0,    62,    50,    37,    51,
       0,   169,    62,    62,    26,     0,    21,    62,    36,   168,
       0,    36,    51,   161,   170,   171,    18,    23,    22,   102,
       0,   163,    49,    10,     0,     0,     0,     0,   174,     0,
     172,   165,   175,   173
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,    26,   204,   205,    56,    27,   170,   295,
     256,    57,    58,    59,    60,   265,   238,   239,    32,    33,
     118,   153,   154,   100,    34,    35,    36,   258,   134,   203,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,   169,   249,   260,   299,   255,   225,
     280,   210
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -253
static const yytype_int16 yypact[] =
{
    -253,   535,  -253,  -253,    19,  -253,    30,   247,    19,    19,
      19,    19,    19,    19,    19,   320,   347,    19,    65,   155,
       2,    81,    19,  -253,  -253,  -253,  -253,  -253,   144,   224,
     279,  -253,   -19,    24,  -253,   -19,   -19,   -19,   102,   105,
     106,   116,   123,   141,   147,   163,   -19,   -19,  -253,    19,
     -19,    59,  -253,  -253,  -253,  -253,   142,    57,  -253,   122,
     170,   170,   170,   170,   170,   170,   170,    19,    19,    19,
      19,    19,    19,    19,   170,    19,  -253,    19,    19,    19,
      19,    19,   170,    -9,    19,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,   159,   155,  -253,  -253,  -253,    59,    96,
    -253,  -253,  -253,  -253,   146,    59,    19,  -253,   196,   179,
     155,   206,   190,  -253,    85,   109,  -253,   178,   160,  -253,
    -253,  -253,    19,    19,    19,    19,    19,    19,    19,    19,
    -253,  -253,    90,  -253,    19,   189,   155,   188,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,    90,   155,   660,     6,  -253,  -253,   211,   155,   155,
     202,   209,   210,   220,   222,   203,   188,    59,  -253,   259,
     235,   188,    59,  -253,  -253,    59,   660,   238,   155,   155,
      -9,    24,  -253,   155,    19,    59,  -253,  -253,  -253,  -253,
    -253,    59,    28,   170,   170,   170,   170,   170,   170,   170,
     170,  -253,    59,    17,   240,   776,   660,   129,  -253,   188,
     215,    18,   155,  -253,   155,   660,    82,  -253,  -253,  -253,
    -253,  -253,  -253,    16,   271,    -2,    19,   215,  -253,   584,
     660,   160,   660,    59,   155,    19,   260,    19,   701,  -253,
     188,   215,   173,   188,   188,   277,  -253,   660,   167,   259,
    -253,  -253,   256,   298,  -253,    33,   176,    59,    19,   155,
     259,    31,   631,    59,    19,  -253,   180,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,    -2,   155,   269,  -253,   199,
    -253,    19,    32,   185,   660,    -2,   155,  -253,    59,   776,
      33,   660,   155,   155,    59,    72,   660,    32,   260,   259,
      33,   631,   739,  -253,   660,   344,  -253,  -253,   -19,  -253,
      -2,  -253,  -253,  -253,    71,    77,    33,    19,  -253,    19,
    -253,  -253,  -253,  -253
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,    20,
      83,    -1,     4,     5,   405,  -252,    35,     0,  -253,  -109,
     145,   150,  -148,   166,    15,  -253,  -253,  -253,  -253,    67,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,   216,   313,  -253,  -253,  -253,  -253,  -253,  -216,  -241,
     -45,  -154
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -53
static const yytype_int16 yytable[] =
{
      28,    31,   181,    51,   211,    29,    30,   253,   275,   192,
     287,   216,   223,   101,   102,   212,    83,   227,    98,   285,
     107,   105,   243,   244,   245,    23,   235,   212,   114,   115,
       5,   108,   114,    24,   103,   114,    86,    87,    88,    89,
      90,   254,    91,     5,     5,   213,   309,   113,   132,   312,
     119,   120,   121,   241,   116,   242,   236,   246,   310,   290,
      22,   130,   131,    92,    93,   133,   248,   251,    52,   300,
      94,   117,   234,    22,    22,   286,    23,    95,    85,    96,
      97,   106,     5,   151,    24,   278,   269,   306,     5,   271,
     272,   212,   104,    98,   316,   184,     5,   108,   167,   108,
      86,    87,    88,    89,    90,   172,   155,     5,   175,    98,
     180,   122,    22,   185,   123,   124,    23,   191,    22,   201,
     186,   250,   261,   317,    24,   125,    22,   156,   157,   319,
     108,   158,   126,   202,   159,    98,   240,    22,   160,   207,
     208,   161,   162,   163,   164,   165,   166,   187,   -52,   -52,
     127,    98,   167,   135,   188,   189,   128,    98,    98,    86,
      87,    88,    89,    90,   136,    91,     5,   209,   106,    99,
       4,     5,   129,   107,   -52,   167,   212,    98,    98,   243,
     244,   245,    98,   233,   108,   281,    92,    93,   171,   281,
       5,   -52,   174,    94,   235,   137,    22,   152,   207,   208,
      95,    22,    96,    97,    28,   167,   274,   173,   190,    29,
      30,    98,   270,    98,   167,   282,     4,     5,   177,   289,
      22,   243,   244,   245,   298,   257,   209,    -9,   167,   167,
     191,   167,   183,    98,   263,    17,   257,    28,   268,   108,
     178,   293,    29,    30,   217,   303,   167,    22,   179,   214,
     -32,   218,   222,    53,   279,   311,   219,   202,    98,    54,
     176,   167,   220,   288,   221,   168,   -32,   -32,   224,   318,
     320,   321,   322,   226,   323,    98,   228,   -32,   237,    55,
     294,    98,   252,   167,   264,    98,   206,   273,    28,   279,
     167,    98,    98,    29,    30,   167,    98,   297,   276,   279,
     167,    28,   268,   167,   167,   109,    29,    30,   215,   277,
     307,   292,   297,   279,   279,   279,   279,   308,   279,   168,
     266,   110,   111,   307,   302,   283,   231,   182,   229,   230,
      84,     5,   112,   232,     0,     0,    67,    68,    69,    70,
      71,    72,   168,    73,     0,     0,     0,     0,    86,    87,
      88,    89,    90,   314,   155,     5,     0,     0,     5,     0,
       0,    22,   247,    75,    76,    77,    78,    79,    80,     0,
      81,     0,   168,     0,     0,   156,   157,     0,     0,     0,
       0,   168,   159,     0,   262,    22,   160,   315,    22,   161,
     162,   163,   164,   165,   166,   168,   168,     0,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
       0,     0,     0,   168,    61,    62,    63,    64,    65,    66,
      74,    82,     0,     0,     0,     0,   291,     0,   168,     0,
       0,     0,   296,     0,     0,     0,   301,     0,     0,     0,
       0,     0,   304,   305,     0,     0,     0,   296,     0,     0,
     168,     0,     0,     0,     0,     0,     0,   168,     0,     0,
       0,     0,   168,     0,     0,     0,     0,   168,     0,     0,
     168,   168,   138,   139,   140,   141,   142,   143,   144,     0,
     145,     0,   146,   147,   148,   149,   150,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,     2,     3,     0,     0,   -51,
     -51,     0,     0,     0,     0,     4,     5,     6,     0,     7,
       0,     8,     9,    10,    11,    12,    13,     0,    14,     0,
       0,     0,    15,    16,    17,   -51,     0,     0,    18,    19,
       0,    20,    21,     0,     0,     0,    22,     0,     0,    23,
       0,     0,   -51,     0,     0,     0,     0,    24,    86,    87,
      88,    89,    90,     0,   155,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,   157,     0,     0,   259,
       0,     0,   159,     0,     0,    22,   160,     0,     0,   161,
     162,   163,   164,   165,   166,    86,    87,    88,    89,    90,
       0,   155,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,     0,     0,     0,     0,
       0,     0,   156,   157,    86,    87,    88,    89,    90,   159,
     155,     5,    22,   160,     0,     0,   161,   162,   163,   164,
     165,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,   157,     0,     0,     0,     0,     0,   159,     0,
       0,    22,   160,     0,     0,   161,   162,   163,   164,   165,
     166,     4,     5,     6,     0,     0,   267,     8,     9,    10,
      11,    12,    13,     0,    14,     0,     0,     0,    15,    16,
      17,     0,     0,     0,     0,    19,     0,     0,    21,     0,
       0,     0,    22,     0,     0,    23,     0,     0,     0,     4,
       5,     6,     0,    24,   313,     8,     9,    10,    11,    12,
      13,     0,    14,     0,     0,     0,    15,    16,    17,     0,
       0,     0,     0,    19,     0,     0,    21,     0,     0,     0,
      22,     0,     0,    23,     0,     0,     4,     5,     6,     0,
       0,    24,     8,     9,    10,    11,    12,    13,     0,    14,
       0,     0,     0,    15,    16,    17,     0,     0,     0,     0,
      19,     0,     0,    21,     0,     0,     0,    22,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,    24
};

static const yytype_int16 yycheck[] =
{
       1,     1,   111,     4,   152,     1,     1,     9,   249,   118,
     262,   159,   166,    11,    12,     9,    17,   171,    19,   260,
      29,    22,     6,     7,     8,    44,     9,     9,     4,     5,
      11,    40,     4,    52,    32,     4,     4,     5,     6,     7,
       8,    43,    10,    11,    11,    39,   298,    32,    49,   301,
      35,    36,    37,   207,    30,   209,    39,    39,   299,   275,
      41,    46,    47,    31,    32,    50,   214,    51,    38,   285,
      38,    47,    44,    41,    41,    44,    44,    45,    13,    47,
      48,    24,    11,    84,    52,    52,   240,    15,    11,   243,
     244,     9,    11,    94,   310,    10,    11,    40,    99,    40,
       4,     5,     6,     7,     8,   106,    10,    11,   109,   110,
     111,     9,    41,   114,     9,     9,    44,   118,    41,    29,
      11,    39,   231,    52,    52,     9,    41,    31,    32,    52,
      40,    35,     9,   134,    38,   136,     7,    41,    42,    10,
      11,    45,    46,    47,    48,    49,    50,    38,     4,     5,
       9,   152,   153,    11,    45,    46,     9,   158,   159,     4,
       5,     6,     7,     8,    42,    10,    11,    38,    24,    19,
      10,    11,     9,    29,    30,   176,     9,   178,   179,     6,
       7,     8,   183,   184,    40,     9,    31,    32,    42,     9,
      11,    47,    13,    38,     9,    25,    41,    38,    10,    11,
      45,    41,    47,    48,   205,   206,    39,    11,    30,   205,
     205,   212,    39,   214,   215,    39,    10,    11,    12,    39,
      41,     6,     7,     8,    39,   226,    38,    38,   229,   230,
     231,   232,    42,   234,   235,    29,   237,   238,   238,    40,
      34,    42,   238,   238,    42,   290,   247,    41,    42,    38,
      26,    42,    49,     6,   255,   300,    46,   258,   259,    12,
     110,   262,    42,   264,    42,    99,    42,    43,     9,   314,
     315,   316,   317,    38,   319,   276,    38,    53,    38,    32,
     281,   282,    11,   284,    24,   286,   136,    10,   289,   290,
     291,   292,   293,   289,   289,   296,   297,   282,    42,   300,
     301,   302,   302,   304,   305,    26,   302,   302,   158,    11,
     295,    42,   297,   314,   315,   316,   317,   297,   319,   153,
     237,    42,    43,   308,   289,   258,   181,   111,   178,   179,
      17,    11,    53,   183,    -1,    -1,    16,    17,    18,    19,
      20,    21,   176,    23,    -1,    -1,    -1,    -1,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    11,    -1,
      -1,    41,   212,    16,    17,    18,    19,    20,    21,    -1,
      23,    -1,   206,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,   215,    38,    -1,   234,    41,    42,    43,    41,    45,
      46,    47,    48,    49,    50,   229,   230,    -1,   232,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,   247,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,   276,    -1,   262,    -1,
      -1,    -1,   282,    -1,    -1,    -1,   286,    -1,    -1,    -1,
      -1,    -1,   292,   293,    -1,    -1,    -1,   297,    -1,    -1,
     284,    -1,    -1,    -1,    -1,    -1,    -1,   291,    -1,    -1,
      -1,    -1,   296,    -1,    -1,    -1,    -1,   301,    -1,    -1,
     304,   305,    67,    68,    69,    70,    71,    72,    73,    -1,
      75,    -1,    77,    78,    79,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,     0,     1,    -1,    -1,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    14,
      -1,    16,    17,    18,    19,    20,    21,    -1,    23,    -1,
      -1,    -1,    27,    28,    29,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    -1,    -1,    -1,    41,    -1,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    52,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      -1,    -1,    38,    -1,    -1,    41,    42,    -1,    -1,    45,
      46,    47,    48,    49,    50,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,     4,     5,     6,     7,     8,    38,
      10,    11,    41,    42,    -1,    -1,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    -1,    -1,    45,    46,    47,    48,    49,
      50,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    -1,    -1,    -1,    27,    28,
      29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    37,    -1,
      -1,    -1,    41,    -1,    -1,    44,    -1,    -1,    -1,    10,
      11,    12,    -1,    52,    15,    16,    17,    18,    19,    20,
      21,    -1,    23,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    -1,
      41,    -1,    -1,    44,    -1,    -1,    10,    11,    12,    -1,
      -1,    52,    16,    17,    18,    19,    20,    21,    -1,    23,
      -1,    -1,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    37,    -1,    -1,    -1,    41,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,     0,     1,    10,    11,    12,    14,    16,    17,
      18,    19,    20,    21,    23,    27,    28,    29,    33,    34,
      36,    37,    41,    44,    52,    56,    57,    61,    65,    66,
      67,    71,    72,    73,    78,    79,    80,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    65,    38,     6,    12,    32,    60,    65,    66,    67,
      68,    68,    68,    68,    68,    68,    68,    16,    17,    18,
      19,    20,    21,    23,    68,    16,    17,    18,    19,    20,
      21,    23,    68,    65,    96,    13,     4,     5,     6,     7,
       8,    10,    31,    32,    38,    45,    47,    48,    65,    75,
      77,    11,    12,    32,    11,    65,    24,    29,    40,    26,
      42,    43,    53,    78,     4,     5,    30,    47,    74,    78,
      78,    78,     9,     9,     9,     9,     9,     9,     9,     9,
      78,    78,    65,    78,    82,    11,    42,    25,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    65,    38,    75,    76,    10,    31,    32,    35,    38,
      42,    45,    46,    47,    48,    49,    50,    65,    77,    98,
      62,    42,    65,    11,    13,    65,    75,    12,    34,    42,
      65,    73,    95,    42,    10,    65,    11,    38,    45,    46,
      30,    65,    73,    68,    68,    68,    68,    68,    68,    68,
      68,    29,    65,    83,    58,    59,    75,    10,    11,    38,
     105,    76,     9,    39,    38,    75,    76,    42,    42,    46,
      42,    42,    49,   105,     9,   103,    38,   105,    38,    75,
      75,    74,    75,    65,    44,     9,    39,    38,    70,    71,
       7,   105,   105,     6,     7,     8,    39,    75,    76,    99,
      39,    51,    11,     9,    43,   102,    64,    65,    81,    35,
     100,    73,    75,    65,    24,    69,    64,    15,    71,   105,
      39,   105,   105,    10,    39,   103,    42,    11,    52,    65,
     104,     9,    39,    83,    75,   103,    44,    69,    65,    39,
     102,    75,    42,    42,    65,    63,    75,    78,    39,   101,
     102,    75,    70,   104,    75,    75,    15,    78,    63,    69,
     103,   104,    69,    15,     9,    43,   102,    52,   104,    52,
     104,   104,   104,   104
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
        case 3:

/* Line 1464 of yacc.c  */
#line 99 "antimony.ypp"
    {;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 100 "antimony.ypp"
    { /*cout << endl << $2->ToString() << endl << endl;*/ ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 101 "antimony.ypp"
    {;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 102 "antimony.ypp"
    {;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 103 "antimony.ypp"
    {YYABORT;;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 106 "antimony.ypp"
    { if (g_registry.OpenFile(*((yyvsp[(2) - (2)].word)))==0) YYABORT;;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 109 "antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(3) - (3)].word), (yyvsp[(2) - (3)].maybemain));;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 110 "antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 115 "antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(3) - (3)].word), (yyvsp[(2) - (3)].maybemain));;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 116 "antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 121 "antimony.ypp"
    {g_registry.SetError("module '" + *((yyvsp[(2) - (2)].word)) + "' already defined."); YYABORT;;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 122 "antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a module because it is already a defined function."); YYABORT;;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 125 "antimony.ypp"
    {(yyval.maybemain) = false;;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 126 "antimony.ypp"
    {(yyval.maybemain) = true;;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 129 "antimony.ypp"
    {g_registry.NewUserFunction((yyvsp[(2) - (2)].word));;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 129 "antimony.ypp"
    {if (g_registry.SetUserFunction((yyvsp[(7) - (8)].formula))) YYABORT;;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 130 "antimony.ypp"
    {g_registry.SetError("Cannot use '" + *((yyvsp[(2) - (2)].word)) +"' as a function name because it is already the name of a module."); YYABORT;;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 131 "antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a new function because it is already a defined function."); YYABORT;;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 134 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (1)].formula);;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 135 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(2) - (2)].formula);;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 136 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula);;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 140 "antimony.ypp"
    {;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 141 "antimony.ypp"
    {if (g_registry.AddVariableToCurrentExportList((yyvsp[(1) - (1)].variable))) YYABORT; ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 142 "antimony.ypp"
    { if (g_registry.AddVariableToCurrentExportList((yyvsp[(3) - (3)].variable))) YYABORT; ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 145 "antimony.ypp"
    {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[(1) - (1)].word)); ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 146 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable)->GetSubVariable((yyvsp[(3) - (3)].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[(3) - (3)].word)) + "' is not a subvariable of '" + (yyvsp[(1) - (3)].variable)->GetNameDelimitedBy('.') + "'.");
                    YYABORT;
                  }
                ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 152 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 155 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetCompartment((yyvsp[(3) - (3)].variable))) YYABORT; (yyval.variable) = (yyvsp[(1) - (3)].variable);;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 158 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 159 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 162 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 163 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable); if ((yyvsp[(1) - (3)].variable)->SetFormula((yyvsp[(3) - (3)].formula))) YYABORT; ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 164 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable); if ((yyvsp[(1) - (3)].variable)->SetUnitDef((yyvsp[(3) - (3)].unitdef))) YYABORT; ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 167 "antimony.ypp"
    {(yyval.variable) = NULL;;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 168 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable);;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 171 "antimony.ypp"
    {;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 172 "antimony.ypp"
    {;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 175 "antimony.ypp"
    {;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 176 "antimony.ypp"
    {;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 177 "antimony.ypp"
    {;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 178 "antimony.ypp"
    {;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 179 "antimony.ypp"
    {;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 180 "antimony.ypp"
    {;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 181 "antimony.ypp"
    {;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 183 "antimony.ypp"
    {;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 184 "antimony.ypp"
    {;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 188 "antimony.ypp"
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[(4) - (8)].reactionDivider), (yyvsp[(7) - (8)].formula), (yyvsp[(1) - (8)].variable));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[(8) - (8)].variable) != NULL) {
                    if ((yyvsp[(1) - (8)].variable)->SetCompartment((yyvsp[(8) - (8)].variable))) YYABORT;
                  }
                ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 196 "antimony.ypp"
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[(2) - (6)].reactionDivider), (yyvsp[(5) - (6)].formula));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[(6) - (6)].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[(6) - (6)].variable))) YYABORT;
                  }
                ;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 205 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 206 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(1) - (1)].variable)); ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 207 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(2) - (2)].variable), (yyvsp[(1) - (2)].num)); ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 208 "antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (3)].reactantList); (yyvsp[(1) - (3)].reactantList)->AddReactant((yyvsp[(3) - (3)].variable)); ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 209 "antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (4)].reactantList); (yyvsp[(1) - (4)].reactantList)->AddReactant((yyvsp[(4) - (4)].variable), (yyvsp[(3) - (4)].num)); ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 213 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 214 "antimony.ypp"
    {(yyval.reactionDivider) = rdInhibits;;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 215 "antimony.ypp"
    {(yyval.reactionDivider) = rdInfluences;;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 216 "antimony.ypp"
    {if (*(yyvsp[(2) - (2)].word) != "o") {g_registry.SetError("'-" + *(yyvsp[(2) - (2)].word) + "' is not a valid set of characters to demark reactions.  Try '->' for reactions, and '-|', '-o', and '-(' for interactions."); YYABORT;} (yyval.reactionDivider) = rdActivates;;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 217 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomesIrreversibly;;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 218 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 221 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 222 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddEllipses();;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 223 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddVariable((yyvsp[(1) - (1)].variable)); ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 224 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddNum((yyvsp[(1) - (1)].num)); ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 225 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddText((yyvsp[(1) - (4)].word)); (yyval.formula)->AddMathThing('('); (yyval.formula)->AddFormula((yyvsp[(3) - (4)].formula)); (yyval.formula)->AddMathThing(')');;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 226 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddText((yyvsp[(1) - (1)].word)); ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 227 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddMathThing((yyvsp[(1) - (1)].character)); ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 228 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(2) - (3)].formula); (yyval.formula)->AddParentheses();;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 229 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddEllipses();;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 230 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddVariable((yyvsp[(2) - (2)].variable)); ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 231 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddNum((yyvsp[(2) - (2)].num)); ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 232 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (5)].formula); (yyvsp[(1) - (5)].formula)->AddText((yyvsp[(2) - (5)].word)); (yyvsp[(4) - (5)].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[(4) - (5)].formula)); ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 233 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddText((yyvsp[(2) - (2)].word));;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 234 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddMathThing((yyvsp[(2) - (2)].character)); ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 235 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (4)].formula); (yyvsp[(3) - (4)].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[(3) - (4)].formula)); ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 236 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('<'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 237 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('>'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 238 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('='); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 239 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('!'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 240 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 241 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); ;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 242 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (4)].formula); string name = (yyvsp[(3) - (4)].unitdef)->GetName(); (yyvsp[(1) - (4)].formula)->AddText(&name); ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 245 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (1)].formula);;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 246 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[(3) - (3)].formula)); ;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 249 "antimony.ypp"
    {(yyval.character) = '+';;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 250 "antimony.ypp"
    {(yyval.character) = '-';;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 251 "antimony.ypp"
    {(yyval.character) = '*';;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 252 "antimony.ypp"
    {(yyval.character) = '/';;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 253 "antimony.ypp"
    {(yyval.character) = '^';;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 254 "antimony.ypp"
    {(yyval.character) = '>';;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 255 "antimony.ypp"
    {(yyval.character) = '<';;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 256 "antimony.ypp"
    {(yyval.character) = '!';;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 259 "antimony.ypp"
    {;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 260 "antimony.ypp"
    {;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 263 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetFormula((yyvsp[(3) - (3)].formula))) YYABORT; ;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 264 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->Synchronize((yyvsp[(3) - (3)].variable))) YYABORT;;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 265 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetDisplayName(*((yyvsp[(3) - (3)].word)))) YYABORT;;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 266 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetAssignmentRule((yyvsp[(4) - (4)].formula))) YYABORT;;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 267 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetRateRule((yyvsp[(4) - (4)].formula))) YYABORT;;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 270 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetModule((yyvsp[(3) - (4)].word))) YYABORT;;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 270 "antimony.ypp"
    {if ((yyvsp[(8) - (8)].variable) != NULL) {if ((yyvsp[(1) - (8)].variable)->SetCompartment((yyvsp[(8) - (8)].variable))) YYABORT;};}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 271 "antimony.ypp"
    {if(g_registry.CurrentModule()->SetModule((yyvsp[(1) - (2)].word))) YYABORT;;}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 271 "antimony.ypp"
    {if ((yyvsp[(6) - (6)].variable) != NULL) {if (g_registry.SetCompartmentOfCurrentSubmod((yyvsp[(6) - (6)].variable))) YYABORT;};}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 274 "antimony.ypp"
    {;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 275 "antimony.ypp"
    {if (g_registry.AddVariableToCurrentImportList((yyvsp[(1) - (1)].variable))) YYABORT; ;}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 276 "antimony.ypp"
    { if (g_registry.AddVariableToCurrentImportList((yyvsp[(3) - (3)].variable))) YYABORT; ;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 279 "antimony.ypp"
    { ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 280 "antimony.ypp"
    { ;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 281 "antimony.ypp"
    { ;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 282 "antimony.ypp"
    { ;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 283 "antimony.ypp"
    { ;}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 284 "antimony.ypp"
    { ;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 286 "antimony.ypp"
    { ;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 287 "antimony.ypp"
    { ;}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 290 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 291 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 292 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 293 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 296 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 297 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 298 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 299 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 302 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 303 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 304 "antimony.ypp"
    {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; ;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 305 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 308 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 309 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 310 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 311 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 314 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 315 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 316 "antimony.ypp"
    {g_registry.SetError("Genes may not be set 'const'."); YYABORT; ;}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 317 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 320 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 321 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 322 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 323 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 327 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 328 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 329 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 330 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 333 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(2) - (2)].variable)->SetRegConst();;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 334 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(2) - (2)].variable)->SetRegConst();;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 335 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst();;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 338 "antimony.ypp"
    {(yyvsp[(4) - (4)].unitdef)->SetName(*(yyvsp[(2) - (4)].word)); if (g_registry.CurrentModule()->AddUnitDef((yyvsp[(4) - (4)].unitdef))) YYABORT; ;}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 339 "antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a unit with only 'unit " + *((yyvsp[(2) - (2)].word)) + "'--you have to add ' = [definition]' afterwards."); YYABORT;;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 342 "antimony.ypp"
    {if (g_registry.SaveWorkingStrand()) YYABORT;;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 343 "antimony.ypp"
    {if (g_registry.SetStrandAs((yyvsp[(1) - (3)].variable))) YYABORT;;}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 346 "antimony.ypp"
    {if (g_registry.SetNewUpstreamOpen((yyvsp[(2) - (2)].variable))) YYABORT;;}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 347 "antimony.ypp"
    {g_registry.SetOpenUpstream(); ;}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 348 "antimony.ypp"
    {if (g_registry.SetDownstreamEnd((yyvsp[(2) - (2)].variable))) YYABORT;;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 349 "antimony.ypp"
    {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[(3) - (3)].variable))) YYABORT;;}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 350 "antimony.ypp"
    { ;}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 353 "antimony.ypp"
    {if (g_registry.SetNewDownstreamOpen((yyvsp[(1) - (2)].variable))) YYABORT;;}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 354 "antimony.ypp"
    {if (g_registry.SetDownstreamOpen((yyvsp[(2) - (3)].variable))) YYABORT;;}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 357 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(2) - (2)].formula))) YYABORT;;}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 357 "antimony.ypp"
    {;}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 358 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(2) - (4)].formula), (yyvsp[(4) - (4)].formula))) YYABORT;;}
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 358 "antimony.ypp"
    {;}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 359 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (4)].formula), (yyvsp[(1) - (4)].variable))) YYABORT;;}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 359 "antimony.ypp"
    {;}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 360 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (6)].formula), (yyvsp[(6) - (6)].formula), (yyvsp[(1) - (6)].variable))) YYABORT;;}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 360 "antimony.ypp"
    {;}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 363 "antimony.ypp"
    {;}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 364 "antimony.ypp"
    {;}
    break;

  case 168:

/* Line 1464 of yacc.c  */
#line 367 "antimony.ypp"
    {;}
    break;

  case 169:

/* Line 1464 of yacc.c  */
#line 368 "antimony.ypp"
    {if (CaselessStrCmp(*(yyvsp[(2) - (4)].word), "priority")) {if (g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[(4) - (4)].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[(2) - (4)].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[(4) - (4)].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[(2) - (4)].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[(4) - (4)].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[(2) - (4)].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[(4) - (4)].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[(2) - (4)].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;};}
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 373 "antimony.ypp"
    {if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[(5) - (5)].formula));}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[(3) - (5)].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;};}
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 380 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (3)].variable), (yyvsp[(3) - (3)].formula))) YYABORT;;}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 381 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (5)].variable), (yyvsp[(3) - (5)].formula))) YYABORT;;}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 382 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (6)].variable), (yyvsp[(3) - (6)].formula))) YYABORT;;}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 383 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (5)].variable), (yyvsp[(3) - (5)].formula))) YYABORT;;}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 384 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (6)].variable), (yyvsp[(3) - (6)].formula))) YYABORT;;}
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 392 "antimony.ypp"
    {(yyval.unitdef) = new UnitDef(*(yyvsp[(1) - (1)].word));;}
    break;

  case 177:

/* Line 1464 of yacc.c  */
#line 393 "antimony.ypp"
    { (yyval.unitdef) = (yyvsp[(2) - (3)].unitdef);;}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 394 "antimony.ypp"
    {(yyval.unitdef) = (yyvsp[(1) - (3)].unitdef); (yyval.unitdef)->MultiplyUnitDef((yyvsp[(3) - (3)].unitdef)); delete (yyvsp[(3) - (3)].unitdef);;}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 395 "antimony.ypp"
    {(yyval.unitdef) = (yyvsp[(1) - (3)].unitdef); (yyvsp[(3) - (3)].unitdef)->Invert(); (yyval.unitdef)->MultiplyUnitDef((yyvsp[(3) - (3)].unitdef)); delete (yyvsp[(3) - (3)].unitdef);;}
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 396 "antimony.ypp"
    {(yyval.unitdef) = (yyvsp[(1) - (3)].unitdef); (yyval.unitdef)->RaiseTo((yyvsp[(3) - (3)].num));;}
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 397 "antimony.ypp"
    {(yyval.unitdef) = (yyvsp[(3) - (3)].unitdef); (yyval.unitdef)->Invert(); (yyval.unitdef)->MultiplyBy((yyvsp[(1) - (3)].num));}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 398 "antimony.ypp"
    {(yyval.unitdef) = (yyvsp[(2) - (2)].unitdef); (yyval.unitdef)->MultiplyBy((yyvsp[(1) - (2)].num));;}
    break;



/* Line 1464 of yacc.c  */
#line 3112 "antimony.tab.cpp"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1684 of yacc.c  */
#line 401 "antimony.ypp"



void yyerror(char const *s)
{
  g_registry.SetError(s);
}

int yylex(void)
{
  char cc = 0;
  g_registry.input->get(cc);

  //If we're done with the file:
  if (g_registry.input->eof()) {
    if (g_registry.SwitchToPreviousFile()) {
      return 0;
    }
    else {
      yylloc_first_line = yylloc_last_lines.back();
      yylloc_last_line = yylloc_last_lines.back();
      yylloc_last_lines.pop_back();
      return yylex();
    }
  }
  if (!g_registry.input->good()) {
    //Something else went wrong!
    g_registry.SetError("The input file is no longer good, for an unknown reason.");
    return -1;
  }

  yylloc_first_line = yylloc_last_line;

  // Skip white space.
  while ((cc == ' ' ||
         cc == '\t') &&
         !g_registry.input->eof()) {
    g_registry.input->get(cc);
  }
  if (g_registry.input->eof()) return yylex();
  // Skip carriage returns after '\':
  if (cc == '\\') {
    g_registry.input->get(cc);
    if (cc == '\r' || cc == '\n') {
      while ((cc == '\r' || cc == '\n') && !g_registry.input->eof()) {
	g_registry.input->get(cc);
      }
      ++yylloc_last_line;
      g_registry.input->unget();
      return yylex();
    }
    else {
      g_registry.input->unget();
      cc = '\\';
    }
  }

  // Parse words
  if (isalpha(cc) || cc == '_') {
    string word;
    while ((isalpha(cc) || isdigit(cc) || cc == '_') && !g_registry.input->eof()) {
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
    /*
    if (CaselessStrCmp(word, "delete")) {
      return DELETEWORD;
    }
    */
    
    if (g_registry.IsFunction(word) != NULL) {
      yylval.word = g_registry.IsFunction(word);
      return FUNCTION;
    }
    //Otherwise, it's a user-defined variable:
    yylval.word = g_registry.AddWord(word);
    //cout << "\tRead word '" << word << "'." << endl;
    if (g_registry.IsModuleName(word)) {
      return MODNAME;
    }
    return ANTWORD;
  }

  // Parse numbers
  if (isdigit(cc) || (cc=='.' && isdigit(g_registry.input->peek()))) {
    double number;
    g_registry.input->unget();
    streampos numbegin = g_registry.input->tellg();
    *g_registry.input >> number;
    if (g_registry.input->fail()) {
      //The gcc 4.4.3 parser fails if there's an 'e' after a number with no exponent.
      g_registry.input->clear();
      g_registry.input->seekg(numbegin);
      int numint;
      *g_registry.input >> numint;
      yylval.num = numint;
      if (g_registry.input->peek() == '.') {
        g_registry.input->get();
        *g_registry.input >> numint;
        double fraction = numint;
        while (fraction >= 1.0) {
          fraction = fraction/10;
        }
        yylval.num += fraction;
      }
      return NUM;
    }
    yylval.num = number;
    //However, pre-4.4.3 parsers would read the 'e' anyway, and we don't want it to, so unget the 'e'.
    g_registry.input->unget();
    g_registry.input->get(cc);
    if (cc == 'e' || cc == 'E') {
      g_registry.input->unget();
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
      return yylex();
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
      return yylex();
    }
    else {
      g_registry.input->unget();
      cc = '/';
    }
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
      yylval.word = g_registry.AddWord(textstring);
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
    ++yylloc_last_line;
  }
  return cc;
}

bool CaselessStrCmp(const string& lhs, const string& rhs)
{

  if (lhs.size() != rhs.size()) return false;

  for (size_t i = 0; i < lhs.size(); ++i) {
    if (toupper(lhs[i]) != toupper(rhs[i])) return false;
  }
  return true;

} /* CaselessStrCmp */

