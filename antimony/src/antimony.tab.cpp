
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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
     A_IN = 273,
     IS = 274,
     VAR = 275,
     A_CONST = 276,
     DASHES = 277,
     BECOMESIRREV = 278,
     ELLIPSES = 279,
     FUNCTION = 280,
     IMPORT = 281,
     AT = 282,
     AFTER = 283,
     FUNCTIONWORD = 284
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 33 "antimony.ypp"

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
  Variable* varmaybein;
  Variable* maybein;
  bool maybemain;



/* Line 214 of yacc.c  */
#line 188 "antimony.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 200 "antimony.tab.cpp"

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
# if YYENABLE_NLS
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
#define YYLAST   788

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  167
/* YYNRULES -- Number of states.  */
#define YYNSTATES  288

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,    39,     2,    47,    49,
       4,     5,     8,     6,    11,     7,    38,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    42,
      45,    40,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    10,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    44,     2,     2,     2,     2,     2,
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
      33,    34,    35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    19,    22,
      23,    33,    34,    41,    44,    47,    48,    50,    51,    60,
      63,    66,    68,    71,    74,    75,    77,    81,    83,    87,
      90,    94,    96,    98,   100,   104,   105,   108,   110,   113,
     116,   119,   122,   125,   128,   131,   133,   135,   144,   151,
     152,   154,   157,   161,   166,   169,   172,   175,   178,   180,
     183,   184,   186,   188,   190,   195,   197,   199,   203,   206,
     209,   212,   218,   221,   224,   229,   233,   237,   241,   245,
     249,   253,   255,   259,   261,   263,   265,   267,   269,   271,
     273,   275,   277,   279,   283,   287,   291,   296,   301,   302,
     311,   312,   319,   320,   322,   326,   328,   330,   332,   334,
     336,   338,   340,   342,   345,   349,   353,   357,   360,   364,
     368,   372,   375,   379,   382,   386,   389,   393,   397,   401,
     404,   408,   412,   416,   419,   423,   427,   431,   434,   438,
     442,   446,   449,   452,   456,   458,   462,   465,   468,   471,
     475,   477,   480,   484,   485,   491,   492,   500,   501,   509,
     510,   520,   521,   530,   534,   540,   547,   553
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    -1,    51,    52,    -1,    51,    53,    -1,
      51,    67,    -1,    51,    57,    -1,    51,     1,    -1,    34,
      15,    -1,    -1,    16,    56,    13,    54,     4,    60,     5,
      66,    17,    -1,    -1,    16,    56,    13,    55,    66,    17,
      -1,    16,    14,    -1,    16,    33,    -1,    -1,     8,    -1,
      -1,    37,    13,    58,     4,    60,     5,    59,    17,    -1,
      37,    14,    -1,    37,    33,    -1,    71,    -1,    74,    59,
      -1,    59,    74,    -1,    -1,    61,    -1,    60,    11,    61,
      -1,    13,    -1,    61,    38,    13,    -1,    39,    61,    -1,
      61,    26,    61,    -1,    61,    -1,    62,    -1,    63,    -1,
      63,    40,    71,    -1,    -1,    26,    61,    -1,    67,    -1,
      66,    67,    -1,    68,    74,    -1,    75,    74,    -1,    76,
      74,    -1,    80,    74,    -1,    89,    74,    -1,    92,    74,
      -1,    62,    -1,    74,    -1,    63,    41,    69,    70,    69,
      42,    71,    65,    -1,    69,    70,    69,    42,    71,    65,
      -1,    -1,    61,    -1,    12,    61,    -1,    69,     6,    61,
      -1,    69,     6,    12,    61,    -1,     7,    43,    -1,     7,
      44,    -1,     7,     4,    -1,     7,    13,    -1,    31,    -1,
      45,    31,    -1,    -1,    32,    -1,    61,    -1,    12,    -1,
      33,     4,    72,     5,    -1,    33,    -1,    73,    -1,     4,
      72,     5,    -1,    71,    32,    -1,    71,    61,    -1,    71,
      12,    -1,    71,    33,     4,    72,     5,    -1,    71,    33,
      -1,    71,    73,    -1,    71,     4,    72,     5,    -1,    71,
      45,    40,    -1,    71,    43,    40,    -1,    71,    40,    40,
      -1,    71,    46,    40,    -1,    71,    47,    47,    -1,    71,
      44,    44,    -1,    71,    -1,    72,    11,    71,    -1,     6,
      -1,     7,    -1,     8,    -1,     9,    -1,    10,    -1,    43,
      -1,    45,    -1,    46,    -1,    42,    -1,    48,    -1,    63,
      40,    71,    -1,    63,    27,    61,    -1,    63,    27,    15,
      -1,    63,    41,    40,    71,    -1,    63,    49,    40,    71,
      -1,    -1,    63,    41,    14,     4,    77,    79,     5,    65,
      -1,    -1,    14,     4,    78,    79,     5,    65,    -1,    -1,
      61,    -1,    79,    11,    61,    -1,    81,    -1,    82,    -1,
      83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,
      88,    -1,    18,    64,    -1,    28,    18,    64,    -1,    29,
      18,    64,    -1,    81,    11,    64,    -1,    20,    64,    -1,
      28,    20,    64,    -1,    29,    20,    64,    -1,    82,    11,
      64,    -1,    19,    64,    -1,    28,    19,    64,    -1,    29,
      19,    -1,    83,    11,    64,    -1,    21,    64,    -1,    28,
      21,    64,    -1,    29,    21,    64,    -1,    84,    11,    64,
      -1,    22,    64,    -1,    28,    22,    64,    -1,    29,    22,
      64,    -1,    85,    11,    64,    -1,    23,    64,    -1,    28,
      23,    64,    -1,    29,    23,    64,    -1,    86,    11,    64,
      -1,    25,    64,    -1,    28,    25,    64,    -1,    29,    25,
      64,    -1,    87,    11,    64,    -1,    28,    64,    -1,    29,
      64,    -1,    88,    11,    64,    -1,    90,    -1,    63,    41,
      90,    -1,    30,    61,    -1,    30,    91,    -1,    91,    61,
      -1,    30,    91,    61,    -1,    91,    -1,    61,    30,    -1,
      91,    61,    30,    -1,    -1,    35,    71,    41,    93,    98,
      -1,    -1,    35,    71,    36,    71,    41,    94,    98,    -1,
      -1,    63,    41,    35,    71,    41,    95,    98,    -1,    -1,
      63,    41,    35,    71,    36,    71,    41,    96,    98,    -1,
      -1,    63,    41,    35,    71,    41,    48,    97,    98,    -1,
      61,    40,    71,    -1,    61,    40,    71,    41,    98,    -1,
      61,    40,    71,    41,    48,    98,    -1,    61,    40,    71,
      11,    98,    -1,    61,    40,    71,    11,    48,    98,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    92,    92,    93,    94,    95,    96,    97,   100,   103,
     103,   109,   109,   115,   116,   119,   120,   123,   123,   124,
     125,   128,   129,   130,   134,   135,   136,   139,   140,   146,
     149,   152,   153,   156,   157,   160,   161,   164,   165,   168,
     169,   170,   171,   172,   173,   174,   175,   178,   186,   196,
     197,   198,   199,   200,   204,   205,   206,   207,   208,   209,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   235,   236,   239,   240,   241,   242,   243,   244,   245,
     246,   249,   250,   253,   254,   255,   256,   257,   260,   260,
     261,   261,   264,   265,   266,   269,   270,   271,   272,   273,
     274,   276,   277,   280,   281,   282,   283,   286,   287,   288,
     289,   292,   293,   294,   295,   298,   299,   300,   301,   304,
     305,   306,   307,   310,   311,   312,   313,   326,   327,   328,
     329,   332,   333,   334,   337,   338,   341,   342,   343,   344,
     345,   348,   349,   352,   352,   353,   353,   354,   354,   355,
     355,   356,   356,   359,   360,   361,   362,   363
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"mathematical symbol\"",
  "'('", "')'", "'+'", "'-'", "'*'", "'/'", "'^'", "','", "\"number\"",
  "\"element name\"", "\"name of an existing module\"", "\"text string\"",
  "\"'model' or 'module'\"", "\"'end'\"", "\"'species'\"",
  "\"'reaction'\"", "\"'formula'\"", "\"'DNA'\"", "\"'gene'\"",
  "\"'operator'\"", "\"'event'\"", "\"'compartment'\"", "\"'in'\"",
  "\"'is'\"", "\"'var'\"", "\"'const'\"", "\"--\"", "\"=>\"", "\"...\"",
  "\"name of an existing function\"", "\"'import'\"", "\"'@' or 'at'\"",
  "\"'after'\"", "\"'function'\"", "'.'", "'$'", "'='", "':'", "';'",
  "'>'", "'|'", "'<'", "'!'", "'&'", "'\\n'", "'\\''", "$accept", "input",
  "import", "module", "$@1", "$@2", "maybemain", "function", "$@3",
  "spacedformula", "variableexportlist", "variable", "variablein",
  "varmaybein", "varmaybeis", "maybein", "modulebody", "modulepart",
  "reaction", "reactantList", "reactionDivider", "formula", "commaformula",
  "mathThing", "lineend", "assignment", "submodule", "$@4", "$@5",
  "variableimportlist", "varinitialize", "specinit", "formulainit",
  "reactioninit", "dnainit", "geneinit", "operatorinit", "compartmentinit",
  "varconstinit", "dnadef", "dnastrand", "dnamiddle", "event", "$@6",
  "$@7", "$@8", "$@9", "$@10", "assignmentlist", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,    40,    41,    43,    45,    42,    47,
      94,    44,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,    46,    36,
      61,    58,    59,    62,   124,    60,    33,    38,    10,    39
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    51,    51,    51,    51,    52,    54,
      53,    55,    53,    53,    53,    56,    56,    58,    57,    57,
      57,    59,    59,    59,    60,    60,    60,    61,    61,    61,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    70,    70,    70,    70,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    75,    75,    75,    77,    76,
      78,    76,    79,    79,    79,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    81,    81,    81,    82,    82,    82,
      82,    83,    83,    83,    83,    84,    84,    84,    84,    85,
      85,    85,    85,    86,    86,    86,    86,    87,    87,    87,
      87,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    91,    91,    93,    92,    94,    92,    95,    92,    96,
      92,    97,    92,    98,    98,    98,    98,    98
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     0,
       9,     0,     6,     2,     2,     0,     1,     0,     8,     2,
       2,     1,     2,     2,     0,     1,     3,     1,     3,     2,
       3,     1,     1,     1,     3,     0,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     8,     6,     0,
       1,     2,     3,     4,     2,     2,     2,     2,     1,     2,
       0,     1,     1,     1,     4,     1,     1,     3,     2,     2,
       2,     5,     2,     2,     4,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     4,     4,     0,     8,
       0,     6,     0,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     3,     2,     3,     3,
       3,     2,     3,     2,     3,     2,     3,     3,     3,     2,
       3,     3,     3,     2,     3,     3,     3,     2,     3,     3,
       3,     2,     2,     3,     1,     3,     2,     2,     2,     3,
       1,     2,     3,     0,     5,     0,     7,     0,     7,     0,
       9,     0,     8,     3,     5,     6,     5,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     7,     0,    27,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
       0,     0,    91,    92,     3,     4,     6,    31,    45,     0,
       5,     0,     0,    46,     0,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   144,   150,     0,    51,
     100,    16,    13,    14,     0,    31,    32,    33,   113,   121,
     117,   125,   129,   133,   137,     0,     0,     0,     0,     0,
       0,     0,   141,     0,   123,     0,     0,     0,     0,     0,
     142,   146,   147,     8,    60,    83,    84,    85,    86,    87,
      63,    61,    65,    88,    89,    90,    62,     0,    66,    17,
      19,    20,    29,     0,   151,     0,     0,    60,    49,     0,
      39,     0,     0,    58,     0,    49,    40,    41,    42,     0,
       0,     0,     0,     0,     0,     0,     0,    43,   148,    44,
     102,    11,    60,   114,   122,   118,   126,   130,   134,   138,
     115,   119,   127,   131,   135,   139,   149,    81,     0,    60,
      60,    70,    68,    72,    60,     0,   153,    88,     0,    89,
      90,     0,    69,    73,     0,    30,    28,    95,    94,    93,
       0,    60,    60,    50,     0,   145,    60,     0,    52,    56,
      57,    54,    55,    59,    50,     0,   116,   120,   124,   128,
     132,   136,   140,   143,   152,   103,     0,     0,    49,    34,
      67,    60,     0,     0,    60,     0,    77,     0,    76,    80,
      75,    78,    79,    24,    98,     0,    96,    49,    97,    53,
      60,    35,     0,    24,    49,    37,    82,    64,    74,     0,
     155,     0,   154,     0,    25,   102,    60,   157,     0,    35,
       0,   101,   104,     0,    12,    38,    71,     0,    60,    60,
       0,     0,     0,   161,     0,    60,    48,    36,    49,   156,
     163,     0,    21,    60,    26,    35,   159,     0,   158,    35,
      49,     0,     0,    18,    23,    22,    99,     0,   162,    47,
      10,     0,   166,     0,   164,   160,   167,   165
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,    25,   197,   198,    54,    26,   164,   261,
     233,    55,    56,    57,    58,   241,   224,   225,    31,    32,
     115,   147,   148,    98,    33,    34,    35,   235,   130,   196,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,   207,   247,   254,   277,   267,   232
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -221
static const yytype_int16 yypact[] =
{
    -221,   418,  -221,  -221,    69,  -221,    20,    83,    69,    69,
      69,    69,    69,    69,    69,   115,   169,    69,    -2,    31,
       1,    69,  -221,  -221,  -221,  -221,  -221,    49,   118,   203,
    -221,    79,     5,  -221,    79,    79,    79,    17,    21,    37,
      58,    73,    75,    82,   101,    79,  -221,    69,    79,    94,
    -221,  -221,  -221,  -221,   126,    62,  -221,   110,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,    69,    69,    69,    69,    69,
      69,    69,  -221,    69,  -221,    69,    69,    69,    69,    69,
    -221,    85,    69,  -221,    31,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,   137,  -221,  -221,  -221,    94,   461,  -221,  -221,
    -221,  -221,    94,    69,  -221,   144,     8,    31,   112,   120,
    -221,    13,    18,  -221,   130,   105,  -221,  -221,  -221,    69,
      69,    69,    69,    69,    69,    69,    69,  -221,   125,  -221,
      69,   161,    31,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,   125,   641,   167,    31,
      31,  -221,  -221,   165,    31,   134,  -221,   141,   140,   170,
     171,   162,    94,  -221,   209,    94,  -221,  -221,    94,   641,
     216,    31,    31,    85,     5,  -221,    31,    69,    94,  -221,
    -221,  -221,  -221,  -221,    94,    11,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,    94,   172,   222,   740,   641,
    -221,    31,   174,   175,    31,   537,  -221,    69,  -221,  -221,
    -221,  -221,  -221,    69,  -221,   477,   641,   105,   641,    94,
      31,   202,    69,    69,   677,  -221,   641,  -221,  -221,   188,
    -221,   -11,  -221,   190,    94,    69,    31,   181,    24,   581,
      69,  -221,    94,   191,  -221,  -221,  -221,    69,    31,   339,
      69,   213,   625,  -221,    69,    31,  -221,    94,   740,  -221,
     521,    50,   641,   339,    94,   202,  -221,    69,  -221,   581,
     709,    -6,    65,  -221,  -221,    79,  -221,    69,  -221,  -221,
    -221,    69,  -221,    69,  -221,  -221,  -221,  -221
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,   -31,
      14,    -1,     7,     9,   291,  -220,   -22,     3,  -221,  -106,
      66,   143,  -144,   -96,    23,  -221,  -221,  -221,  -221,     6,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
     147,   225,  -221,  -221,  -221,  -221,  -221,  -221,  -182
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -51
static const yytype_int16 yytable[] =
{
      27,   163,   174,    49,    30,   202,   203,     5,    28,   185,
      29,   111,   112,    83,    99,   100,    81,   111,    96,   256,
     102,     5,   179,   167,    50,   177,     5,   105,   119,   248,
     111,   180,   120,    21,   101,    84,   113,    85,    86,    87,
      88,    89,   281,    90,     5,   276,   128,    21,   121,   279,
     114,   163,    21,   220,   110,   -50,   -50,   116,   117,   118,
     229,   181,   182,    91,    92,   259,   255,   273,   127,   122,
      21,   129,   268,   163,    93,   103,    94,    95,     5,   104,
     -50,   146,     5,    96,   123,   278,   124,   105,   103,   282,
     284,    51,    22,   125,   -50,   285,   162,    52,    23,   286,
     105,   287,   165,   163,    21,   168,    96,   173,    21,   163,
     178,   238,   126,   283,   184,   104,    53,     4,     5,   163,
     163,    22,   163,   105,     4,     5,   170,    23,     5,   195,
     163,    96,   105,    65,    66,    67,    68,    69,    70,   131,
      71,   149,    17,   163,    21,   -32,   162,   171,    96,    96,
     132,    21,   172,    96,    21,   194,   163,   166,   -32,   -32,
     176,   183,    97,   105,   163,    -9,   163,   -32,   162,   204,
      96,    96,   200,   163,   206,    96,   219,   221,   201,   227,
     228,   208,     5,   222,   209,   201,   201,    73,    74,    75,
      76,    77,    78,   246,    79,   249,   258,    27,   162,   201,
      96,   250,   250,    96,   162,    28,   231,    29,    21,   212,
     210,   211,   234,   213,   162,   162,   184,   162,   265,    96,
     214,   242,   234,    27,   222,   162,   223,   245,   240,   253,
     106,    28,   275,    29,   195,    96,   270,   243,   162,   257,
     217,   251,    82,   107,   108,     0,   231,    96,    96,   264,
     169,   162,   109,   231,    96,   175,     0,    27,     0,   162,
       0,   162,    96,     0,     0,    28,   231,    29,   162,    27,
     231,   231,   263,   245,     0,   199,   231,    28,     0,    29,
     231,     0,   231,     0,   274,     0,   263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   274,     0,
      59,    60,    61,    62,    63,    64,    72,    80,     0,     0,
       0,     0,     0,     0,   215,   216,     0,     0,     0,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,   226,    85,    86,    87,    88,    89,
       0,    90,     5,     0,     0,     0,   133,   134,   135,   136,
     137,   138,   139,   239,   140,     0,   141,   142,   143,   144,
     145,    91,    92,     0,     0,     0,     0,     0,    21,   252,
       0,    22,    93,     0,    94,    95,     0,    23,     0,     0,
       0,   260,   262,     0,     0,     0,     0,     0,   269,     0,
       0,     0,     0,     0,     0,     0,   262,     0,     0,     0,
     186,   187,   188,   189,   190,   191,   192,   193,     2,     3,
       0,     0,     0,     0,   -49,   -49,     0,     0,     0,     0,
       4,     5,     6,     0,     7,     0,     8,     9,    10,    11,
      12,    13,     0,    14,     0,     0,    15,    16,    17,   -49,
       0,     0,    18,    19,     0,    20,     0,    21,     0,     0,
      22,     0,     0,   -49,     0,   150,    23,    85,    86,    87,
      88,    89,     0,   151,     5,     0,     0,     0,     0,     0,
       0,   150,     0,    85,    86,    87,    88,    89,     0,   151,
       5,     0,     0,   152,   153,     0,     0,   154,     0,     0,
      21,   155,   156,     0,   157,   158,   159,   160,   161,   152,
     153,     0,     0,   236,     0,     0,    21,   155,   237,     0,
     157,   158,   159,   160,   161,   150,     0,    85,    86,    87,
      88,    89,   271,   151,     5,     0,     0,     0,     0,     0,
       0,   150,     0,    85,    86,    87,    88,    89,     0,   151,
       5,     0,     0,   152,   153,     0,     0,     0,     0,     0,
      21,   155,   272,     0,   157,   158,   159,   160,   161,   152,
     153,     0,     0,     0,     0,     0,    21,   155,   230,     0,
     157,   158,   159,   160,   161,   150,     0,    85,    86,    87,
      88,    89,     0,   151,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,     0,     0,
       0,     0,     0,   152,   153,     0,     0,     0,     0,     0,
      21,   155,     0,     0,   157,   158,   159,   160,   161,   150,
       0,    85,    86,    87,    88,    89,     0,   151,     5,     0,
       0,     0,     0,     0,     0,   150,     0,    85,    86,    87,
      88,    89,     0,   151,     5,     0,     0,   152,   153,     0,
       0,     0,     0,     0,    21,   155,   266,     0,   157,   158,
     159,   160,   161,   152,   153,     0,     0,     0,     0,     0,
      21,   155,     0,     0,   157,   158,   159,   160,   161,     4,
       5,     6,     0,     0,   244,     8,     9,    10,    11,    12,
      13,     0,    14,     0,     0,    15,    16,    17,     0,     0,
       0,     0,    19,     0,     0,     0,    21,     0,     0,    22,
       0,     4,     5,     6,     0,    23,   280,     8,     9,    10,
      11,    12,    13,     0,    14,     0,     0,    15,    16,    17,
       0,     0,     0,     0,    19,     0,     0,     0,    21,     0,
       0,    22,     4,     5,     6,     0,     0,    23,     8,     9,
      10,    11,    12,    13,     0,    14,     0,     0,    15,    16,
      17,     0,     0,     0,     0,    19,     0,     0,     0,    21,
       0,     0,    22,     0,     0,     0,     0,     0,    23
};

static const yytype_int16 yycheck[] =
{
       1,    97,   108,     4,     1,   149,   150,    13,     1,   115,
       1,     6,     7,    15,    13,    14,    17,     6,    19,   239,
      21,    13,     4,    15,     4,    12,    13,    38,    11,    40,
       6,    13,    11,    39,    33,     4,    31,     6,     7,     8,
       9,    10,    48,    12,    13,   265,    47,    39,    11,   269,
      45,   147,    39,    42,    31,     6,     7,    34,    35,    36,
     204,    43,    44,    32,    33,   247,    42,    17,    45,    11,
      39,    48,   254,   169,    43,    26,    45,    46,    13,    30,
      31,    82,    13,    84,    11,   267,    11,    38,    26,   271,
     272,     8,    42,    11,    45,   277,    97,    14,    48,   281,
      38,   283,   103,   199,    39,   106,   107,   108,    39,   205,
     111,   217,    11,    48,   115,    30,    33,    12,    13,   215,
     216,    42,   218,    38,    12,    13,    14,    48,    13,   130,
     226,   132,    38,    18,    19,    20,    21,    22,    23,    13,
      25,     4,    30,   239,    39,    27,   147,    35,   149,   150,
      40,    39,    40,   154,    39,    30,   252,    13,    40,    41,
      40,    31,    19,    38,   260,     4,   262,    49,   169,     4,
     171,   172,     5,   269,    40,   176,   177,     5,    11,     5,
       5,    40,    13,    11,    44,    11,    11,    18,    19,    20,
      21,    22,    23,     5,    25,     5,     5,   198,   199,    11,
     201,    11,    11,   204,   205,   198,   207,   198,    39,    47,
      40,    40,   213,     4,   215,   216,   217,   218,     5,   220,
       4,   222,   223,   224,    11,   226,     4,   224,    26,    48,
      27,   224,   263,   224,   235,   236,   258,   223,   239,   240,
     174,   235,    17,    40,    41,    -1,   247,   248,   249,   250,
     107,   252,    49,   254,   255,   108,    -1,   258,    -1,   260,
      -1,   262,   263,    -1,    -1,   258,   267,   258,   269,   270,
     271,   272,   249,   270,    -1,   132,   277,   270,    -1,   270,
     281,    -1,   283,    -1,   261,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,   275,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,    -1,    -1,    -1,   176,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,   201,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,   220,    73,    -1,    75,    76,    77,    78,
      79,    32,    33,    -1,    -1,    -1,    -1,    -1,    39,   236,
      -1,    42,    43,    -1,    45,    46,    -1,    48,    -1,    -1,
      -1,   248,   249,    -1,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,     0,     1,
      -1,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    16,    -1,    18,    19,    20,    21,
      22,    23,    -1,    25,    -1,    -1,    28,    29,    30,    31,
      -1,    -1,    34,    35,    -1,    37,    -1,    39,    -1,    -1,
      42,    -1,    -1,    45,    -1,     4,    48,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,     4,    -1,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    32,    33,    -1,    -1,    36,    -1,    -1,
      39,    40,    41,    -1,    43,    44,    45,    46,    47,    32,
      33,    -1,    -1,    36,    -1,    -1,    39,    40,    41,    -1,
      43,    44,    45,    46,    47,     4,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,     4,    -1,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    -1,    43,    44,    45,    46,    47,    32,
      33,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,
      43,    44,    45,    46,    47,     4,    -1,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,
      39,    40,    -1,    -1,    43,    44,    45,    46,    47,     4,
      -1,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,     4,    -1,     6,     7,     8,
       9,    10,    -1,    12,    13,    -1,    -1,    32,    33,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    -1,    43,    44,
      45,    46,    47,    32,    33,    -1,    -1,    -1,    -1,    -1,
      39,    40,    -1,    -1,    43,    44,    45,    46,    47,    12,
      13,    14,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    -1,    25,    -1,    -1,    28,    29,    30,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    39,    -1,    -1,    42,
      -1,    12,    13,    14,    -1,    48,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    -1,    -1,    28,    29,    30,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    39,    -1,
      -1,    42,    12,    13,    14,    -1,    -1,    48,    18,    19,
      20,    21,    22,    23,    -1,    25,    -1,    -1,    28,    29,
      30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,     0,     1,    12,    13,    14,    16,    18,    19,
      20,    21,    22,    23,    25,    28,    29,    30,    34,    35,
      37,    39,    42,    48,    52,    53,    57,    61,    62,    63,
      67,    68,    69,    74,    75,    76,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    61,
       4,     8,    14,    33,    56,    61,    62,    63,    64,    64,
      64,    64,    64,    64,    64,    18,    19,    20,    21,    22,
      23,    25,    64,    18,    19,    20,    21,    22,    23,    25,
      64,    61,    91,    15,     4,     6,     7,     8,     9,    10,
      12,    32,    33,    43,    45,    46,    61,    71,    73,    13,
      14,    33,    61,    26,    30,    38,    27,    40,    41,    49,
      74,     6,     7,    31,    45,    70,    74,    74,    74,    11,
      11,    11,    11,    11,    11,    11,    11,    74,    61,    74,
      78,    13,    40,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    61,    71,    72,     4,
       4,    12,    32,    33,    36,    40,    41,    43,    44,    45,
      46,    47,    61,    73,    58,    61,    13,    15,    61,    71,
      14,    35,    40,    61,    69,    90,    40,    12,    61,     4,
      13,    43,    44,    31,    61,    69,    64,    64,    64,    64,
      64,    64,    64,    64,    30,    61,    79,    54,    55,    71,
       5,    11,    72,    72,     4,    71,    40,    93,    40,    44,
      40,    40,    47,     4,     4,    71,    71,    70,    71,    61,
      42,     5,    11,     4,    66,    67,    71,     5,     5,    72,
      41,    61,    98,    60,    61,    77,    36,    41,    69,    71,
      26,    65,    61,    60,    17,    67,     5,    94,    40,     5,
      11,    79,    71,    48,    95,    42,    65,    61,     5,    98,
      71,    59,    71,    74,    61,     5,    41,    97,    98,    71,
      66,    11,    41,    17,    74,    59,    65,    96,    98,    65,
      17,    48,    98,    48,    98,    98,    98,    98
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
# if YYLTYPE_IS_TRIVIAL
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

/* Line 1455 of yacc.c  */
#line 93 "antimony.ypp"
    {;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 94 "antimony.ypp"
    { /*cout << endl << $2->ToString() << endl << endl;*/ ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 95 "antimony.ypp"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 96 "antimony.ypp"
    {;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 97 "antimony.ypp"
    {YYABORT;;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 100 "antimony.ypp"
    { if (g_registry.OpenFile(*((yyvsp[(2) - (2)].word)))==0) YYABORT;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 103 "antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(3) - (3)].word), (yyvsp[(2) - (3)].maybemain));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 104 "antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 109 "antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(3) - (3)].word), (yyvsp[(2) - (3)].maybemain));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 110 "antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 115 "antimony.ypp"
    {g_registry.SetError("module '" + *((yyvsp[(2) - (2)].word)) + "' already defined."); YYABORT;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 116 "antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a module because it is already a defined function."); YYABORT;;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 119 "antimony.ypp"
    {(yyval.maybemain) = false;;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 120 "antimony.ypp"
    {(yyval.maybemain) = true;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 123 "antimony.ypp"
    {g_registry.NewUserFunction((yyvsp[(2) - (2)].word));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 123 "antimony.ypp"
    {if (g_registry.SetUserFunction((yyvsp[(7) - (8)].formula))) YYABORT;;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 124 "antimony.ypp"
    {g_registry.SetError("Cannot use '" + *((yyvsp[(2) - (2)].word)) +"' as a function name because it is already the name of a module."); YYABORT;;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 125 "antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a new function because it is already a defined function."); YYABORT;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 128 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (1)].formula);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 129 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(2) - (2)].formula);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 130 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 134 "antimony.ypp"
    {;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 135 "antimony.ypp"
    {if (g_registry.AddVariableToCurrentExportList((yyvsp[(1) - (1)].variable))) YYABORT; ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 136 "antimony.ypp"
    { if (g_registry.AddVariableToCurrentExportList((yyvsp[(3) - (3)].variable))) YYABORT; ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 139 "antimony.ypp"
    {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[(1) - (1)].word)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 140 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable)->GetSubVariable((yyvsp[(3) - (3)].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[(3) - (3)].word)) + "' is not a subvariable of '" + (yyvsp[(1) - (3)].variable)->GetNameDelimitedBy('.') + "'.");
                    YYABORT;
                  }
                ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 146 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 149 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetCompartment((yyvsp[(3) - (3)].variable))) YYABORT; (yyval.variable) = (yyvsp[(1) - (3)].variable);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 152 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 153 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 156 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 157 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable); if ((yyvsp[(1) - (3)].variable)->SetFormula((yyvsp[(3) - (3)].formula))) YYABORT; ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 160 "antimony.ypp"
    {(yyval.variable) = NULL;;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 161 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 164 "antimony.ypp"
    {;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 165 "antimony.ypp"
    {;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 168 "antimony.ypp"
    {;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 169 "antimony.ypp"
    {;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 170 "antimony.ypp"
    {;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 171 "antimony.ypp"
    {;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 172 "antimony.ypp"
    {;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 173 "antimony.ypp"
    {;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 174 "antimony.ypp"
    {;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 175 "antimony.ypp"
    {;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 179 "antimony.ypp"
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[(4) - (8)].reactionDivider), (yyvsp[(7) - (8)].formula), (yyvsp[(1) - (8)].variable));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[(8) - (8)].variable) != NULL) {
                    if ((yyvsp[(1) - (8)].variable)->SetCompartment((yyvsp[(8) - (8)].variable))) YYABORT;
                  }
                ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 187 "antimony.ypp"
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[(2) - (6)].reactionDivider), (yyvsp[(5) - (6)].formula));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[(6) - (6)].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[(6) - (6)].variable))) YYABORT;
                  }
                ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 196 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 197 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(1) - (1)].variable)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 198 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(2) - (2)].variable), (yyvsp[(1) - (2)].num)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 199 "antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (3)].reactantList); (yyvsp[(1) - (3)].reactantList)->AddReactant((yyvsp[(3) - (3)].variable)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 200 "antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (4)].reactantList); (yyvsp[(1) - (4)].reactantList)->AddReactant((yyvsp[(4) - (4)].variable), (yyvsp[(3) - (4)].num)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 204 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 205 "antimony.ypp"
    {(yyval.reactionDivider) = rdInhibits;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 206 "antimony.ypp"
    {(yyval.reactionDivider) = rdInfluences;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 207 "antimony.ypp"
    {if (*(yyvsp[(2) - (2)].word) != "o") {g_registry.SetError("'-" + *(yyvsp[(2) - (2)].word) + "' is not a valid set of characters to demark reactions.  Try '->' for reactions, and '-|', '-o', and '-(' for interactions."); YYABORT;} (yyval.reactionDivider) = rdActivates;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 208 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomesIrreversibly;;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 209 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 212 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 213 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddEllipses();;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 214 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddVariable((yyvsp[(1) - (1)].variable)); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 215 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddNum((yyvsp[(1) - (1)].num)); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 216 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddText((yyvsp[(1) - (4)].word)); (yyval.formula)->AddMathThing('('); (yyval.formula)->AddFormula((yyvsp[(3) - (4)].formula)); (yyval.formula)->AddMathThing(')');;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 217 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddText((yyvsp[(1) - (1)].word)); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 218 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddMathThing((yyvsp[(1) - (1)].character)); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 219 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(2) - (3)].formula); (yyval.formula)->AddParentheses();;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 220 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddEllipses();;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 221 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddVariable((yyvsp[(2) - (2)].variable)); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 222 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddNum((yyvsp[(2) - (2)].num)); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 223 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (5)].formula); (yyvsp[(1) - (5)].formula)->AddText((yyvsp[(2) - (5)].word)); (yyvsp[(4) - (5)].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[(4) - (5)].formula)); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 224 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddText((yyvsp[(2) - (2)].word));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 225 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddMathThing((yyvsp[(2) - (2)].character)); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 226 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (4)].formula); (yyvsp[(3) - (4)].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[(3) - (4)].formula)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 227 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('<'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 228 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('>'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 229 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('='); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 230 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('!'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 231 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 232 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 235 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (1)].formula);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 236 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[(3) - (3)].formula)); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 239 "antimony.ypp"
    {(yyval.character) = '+';;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 240 "antimony.ypp"
    {(yyval.character) = '-';;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 241 "antimony.ypp"
    {(yyval.character) = '*';;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 242 "antimony.ypp"
    {(yyval.character) = '/';;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 243 "antimony.ypp"
    {(yyval.character) = '^';;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 244 "antimony.ypp"
    {(yyval.character) = '>';;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 245 "antimony.ypp"
    {(yyval.character) = '<';;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 246 "antimony.ypp"
    {(yyval.character) = '!';;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 249 "antimony.ypp"
    {;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 250 "antimony.ypp"
    {;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 253 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetFormula((yyvsp[(3) - (3)].formula))) YYABORT; ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 254 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->Synchronize((yyvsp[(3) - (3)].variable))) YYABORT;;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 255 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetDisplayName(*((yyvsp[(3) - (3)].word)))) YYABORT;;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 256 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetAssignmentRule((yyvsp[(4) - (4)].formula))) YYABORT;;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 257 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetRateRule((yyvsp[(4) - (4)].formula))) YYABORT;;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 260 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetModule((yyvsp[(3) - (4)].word))) YYABORT;;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 260 "antimony.ypp"
    {if ((yyvsp[(8) - (8)].variable) != NULL) {if ((yyvsp[(1) - (8)].variable)->SetCompartment((yyvsp[(8) - (8)].variable))) YYABORT;};}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 261 "antimony.ypp"
    {if(g_registry.CurrentModule()->SetModule((yyvsp[(1) - (2)].word))) YYABORT;;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 261 "antimony.ypp"
    {if ((yyvsp[(6) - (6)].variable) != NULL) {if (g_registry.SetCompartmentOfCurrentSubmod((yyvsp[(6) - (6)].variable))) YYABORT;};}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 264 "antimony.ypp"
    {;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 265 "antimony.ypp"
    {if (g_registry.AddVariableToCurrentImportList((yyvsp[(1) - (1)].variable))) YYABORT; ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 266 "antimony.ypp"
    { if (g_registry.AddVariableToCurrentImportList((yyvsp[(3) - (3)].variable))) YYABORT; ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 269 "antimony.ypp"
    { ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 270 "antimony.ypp"
    { ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 271 "antimony.ypp"
    { ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 272 "antimony.ypp"
    { ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 273 "antimony.ypp"
    { ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 274 "antimony.ypp"
    { ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 276 "antimony.ypp"
    { ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 277 "antimony.ypp"
    { ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 280 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 281 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 282 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 283 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 286 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 287 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 288 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 289 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 292 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 293 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 294 "antimony.ypp"
    {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 295 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 298 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 299 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 300 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 301 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 304 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 305 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 306 "antimony.ypp"
    {g_registry.SetError("Genes may not be set 'const'."); YYABORT; ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 307 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 310 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 311 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 312 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 313 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 326 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 327 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 328 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 329 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 332 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(2) - (2)].variable)->SetRegConst();;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 333 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(2) - (2)].variable)->SetRegConst();;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 334 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst();;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 337 "antimony.ypp"
    {if (g_registry.SaveWorkingStrand()) YYABORT;;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 338 "antimony.ypp"
    {if (g_registry.SetStrandAs((yyvsp[(1) - (3)].variable))) YYABORT;;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 341 "antimony.ypp"
    {if (g_registry.SetNewUpstreamOpen((yyvsp[(2) - (2)].variable))) YYABORT;;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 342 "antimony.ypp"
    {g_registry.SetOpenUpstream(); ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 343 "antimony.ypp"
    {if (g_registry.SetDownstreamEnd((yyvsp[(2) - (2)].variable))) YYABORT;;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 344 "antimony.ypp"
    {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[(3) - (3)].variable))) YYABORT;;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 345 "antimony.ypp"
    { ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 348 "antimony.ypp"
    {if (g_registry.SetNewDownstreamOpen((yyvsp[(1) - (2)].variable))) YYABORT;;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 349 "antimony.ypp"
    {if (g_registry.SetDownstreamOpen((yyvsp[(2) - (3)].variable))) YYABORT;;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 352 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(2) - (3)].formula))) YYABORT;;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 352 "antimony.ypp"
    {;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 353 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(2) - (5)].formula), (yyvsp[(4) - (5)].formula))) YYABORT;;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 353 "antimony.ypp"
    {;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 354 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (5)].formula), (yyvsp[(1) - (5)].variable))) YYABORT;;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 354 "antimony.ypp"
    {;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 355 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (7)].formula), (yyvsp[(6) - (7)].formula), (yyvsp[(1) - (7)].variable))) YYABORT;;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 355 "antimony.ypp"
    {;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 356 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (6)].formula), (yyvsp[(1) - (6)].variable))) YYABORT;;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 356 "antimony.ypp"
    {;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 359 "antimony.ypp"
    {if (g_registry.AddResultToCurrentEvent((yyvsp[(1) - (3)].variable), (yyvsp[(3) - (3)].formula))) YYABORT;;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 360 "antimony.ypp"
    {if (g_registry.AddResultToCurrentEvent((yyvsp[(1) - (5)].variable), (yyvsp[(3) - (5)].formula))) YYABORT;;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 361 "antimony.ypp"
    {if (g_registry.AddResultToCurrentEvent((yyvsp[(1) - (6)].variable), (yyvsp[(3) - (6)].formula))) YYABORT;;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 362 "antimony.ypp"
    {if (g_registry.AddResultToCurrentEvent((yyvsp[(1) - (5)].variable), (yyvsp[(3) - (5)].formula))) YYABORT;;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 363 "antimony.ypp"
    {if (g_registry.AddResultToCurrentEvent((yyvsp[(1) - (6)].variable), (yyvsp[(3) - (6)].formula))) YYABORT;;}
    break;



/* Line 1455 of yacc.c  */
#line 2948 "antimony.tab.cpp"
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



/* Line 1675 of yacc.c  */
#line 366 "antimony.ypp"



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
    if (CaselessStrCmp(word, "in")) {
      return A_IN;
    }
    if (CaselessStrCmp(word, "is")) {
      return IS;
    }
    if (CaselessStrCmp(word, "var")) {
      return VAR;
    }
    if (CaselessStrCmp(word, "const")) {
      return A_CONST;
    }
    if (CaselessStrCmp(word, "ext")) {
      return A_CONST;
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

