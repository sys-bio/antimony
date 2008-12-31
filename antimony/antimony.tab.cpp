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
     NUM = 258,
     WORD = 259,
     MODNAME = 260,
     FILENAME = 261,
     MODULE = 262,
     END = 263,
     BECOMES = 264,
     INHIBITS = 265,
     ACTIVATES = 266,
     INFLUENCES = 267,
     SPECIES = 268,
     REACTION = 269,
     DNA = 270,
     GENE = 271,
     OPERATOR = 272,
     EVENT = 273,
     COMPARTMENT = 274,
     IN = 275,
     IS = 276,
     VAR = 277,
     CONST = 278,
     DASHES = 279,
     ELLIPSES = 280,
     FUNCTION = 281,
     IMPORT = 282
   };
#endif
/* Tokens.  */
#define NUM 258
#define WORD 259
#define MODNAME 260
#define FILENAME 261
#define MODULE 262
#define END 263
#define BECOMES 264
#define INHIBITS 265
#define ACTIVATES 266
#define INFLUENCES 267
#define SPECIES 268
#define REACTION 269
#define DNA 270
#define GENE 271
#define OPERATOR 272
#define EVENT 273
#define COMPARTMENT 274
#define IN 275
#define IS 276
#define VAR 277
#define CONST 278
#define DASHES 279
#define ELLIPSES 280
#define FUNCTION 281
#define IMPORT 282




/* Copy the first part of user declarations.  */
#line 2 "antimony.ypp"

  //#define YYSTYPE double
#include <math.h>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <set>
#include <sbml/SBMLTypes.h>

#include "antimony_api.h"
#include "registry.h"
#include "rd_type.h"
#include "stringx.h"
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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 35 "antimony.ypp"
{
  char character;
  const string* word;
  double num;
  rd_type reactionDivider;
  Formula* formula;
  Module* module;
  ReactantList* reactantList;
  Variable* variable;
  Variable* variablein;
  Variable* varmaybein;
  Variable* maybein;
}
/* Line 187 of yacc.c.  */
#line 196 "antimony.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 209 "antimony.tab.cpp"

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   487

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
/* YYNRULES -- Number of states.  */
#define YYNSTATES  230

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,     2,     2,     2,    43,     2,
       3,     4,     7,     5,    10,     6,    36,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    38,
      39,    40,    41,     2,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     9,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    19,    20,
      29,    30,    36,    39,    40,    42,    46,    48,    52,    54,
      56,    60,    61,    64,    66,    69,    72,    75,    78,    81,
      84,    87,    89,    91,   100,   107,   108,   110,   113,   117,
     122,   124,   126,   128,   130,   131,   133,   135,   137,   139,
     141,   144,   147,   150,   153,   156,   160,   164,   168,   172,
     176,   180,   182,   184,   186,   188,   190,   192,   194,   196,
     198,   200,   202,   204,   206,   210,   214,   215,   224,   225,
     232,   233,   235,   239,   241,   243,   245,   247,   249,   251,
     253,   255,   257,   259,   261,   263,   266,   270,   274,   277,
     281,   285,   288,   292,   296,   299,   303,   307,   310,   314,
     318,   321,   325,   329,   332,   336,   340,   344,   348,   352,
     356,   360,   364,   368,   372,   375,   379,   381,   385,   388,
     391,   394,   398,   400,   403,   407,   408,   414,   415,   423,
     427
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    -1,    48,    49,    -1,    48,    50,    -1,
      48,    59,    -1,    48,     1,    -1,    35,    14,    -1,    -1,
      15,    12,    51,     3,    53,     4,    58,    16,    -1,    -1,
      15,    12,    52,    58,    16,    -1,    15,    13,    -1,    -1,
      54,    -1,    53,    10,    54,    -1,    12,    -1,    54,    36,
      12,    -1,    54,    -1,    56,    -1,    54,    28,    54,    -1,
      -1,    28,    54,    -1,    59,    -1,    58,    59,    -1,    60,
      65,    -1,    66,    65,    -1,    67,    65,    -1,    71,    65,
      -1,    84,    65,    -1,    87,    65,    -1,    56,    -1,    65,
      -1,    55,    37,    61,    62,    61,    38,    63,    57,    -1,
      61,    62,    61,    38,    63,    57,    -1,    -1,    54,    -1,
      11,    54,    -1,    61,     5,    54,    -1,    61,     5,    11,
      54,    -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,
      -1,    33,    -1,    54,    -1,    11,    -1,    34,    -1,    64,
      -1,    63,    33,    -1,    63,    54,    -1,    63,    11,    -1,
      63,    34,    -1,    63,    64,    -1,    63,    39,    40,    -1,
      63,    41,    40,    -1,    63,    40,    40,    -1,    63,    42,
      40,    -1,    63,    43,    43,    -1,    63,    44,    44,    -1,
       5,    -1,     6,    -1,     7,    -1,     8,    -1,     3,    -1,
       4,    -1,     9,    -1,    10,    -1,    41,    -1,    39,    -1,
      42,    -1,    38,    -1,    45,    -1,    55,    40,    63,    -1,
      55,    29,    54,    -1,    -1,    55,    37,    13,     3,    68,
      70,     4,    57,    -1,    -1,    13,     3,    69,    70,     4,
      57,    -1,    -1,    54,    -1,    70,    10,    54,    -1,    72,
      -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,    77,
      -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,    83,
      -1,    82,    -1,    21,    55,    -1,    30,    21,    55,    -1,
      72,    10,    55,    -1,    22,    55,    -1,    30,    22,    55,
      -1,    73,    10,    55,    -1,    23,    55,    -1,    30,    23,
      55,    -1,    74,    10,    55,    -1,    24,    55,    -1,    30,
      24,    55,    -1,    75,    10,    55,    -1,    25,    55,    -1,
      30,    25,    55,    -1,    76,    10,    55,    -1,    26,    55,
      -1,    30,    26,    55,    -1,    77,    10,    55,    -1,    27,
      55,    -1,    30,    27,    55,    -1,    78,    10,    55,    -1,
      31,    21,    55,    -1,    79,    10,    55,    -1,    31,    23,
      55,    -1,    80,    10,    55,    -1,    31,    25,    55,    -1,
      81,    10,    55,    -1,    31,    27,    55,    -1,    82,    10,
      55,    -1,    31,    55,    -1,    83,    10,    55,    -1,    85,
      -1,    55,    37,    85,    -1,    32,    54,    -1,    32,    86,
      -1,    86,    54,    -1,    32,    86,    54,    -1,    86,    -1,
      54,    32,    -1,    86,    54,    32,    -1,    -1,    46,    63,
      37,    88,    90,    -1,    -1,    55,    37,    46,    63,    37,
      89,    90,    -1,    54,    40,    63,    -1,    54,    40,    63,
      37,    90,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    68,    69,    70,    71,    74,    77,    77,
      83,    83,    89,    93,    94,    95,    98,    99,   108,   109,
     112,   115,   116,   119,   120,   123,   124,   125,   126,   127,
     128,   129,   130,   133,   141,   151,   152,   153,   154,   155,
     159,   160,   161,   162,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   197,   198,   201,   202,   205,   205,   206,   206,
     209,   210,   211,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   228,   229,   230,   233,   234,
     235,   238,   239,   240,   243,   244,   245,   248,   249,   250,
     253,   254,   255,   259,   260,   261,   264,   266,   271,   273,
     278,   280,   285,   287,   291,   292,   295,   296,   299,   300,
     301,   302,   303,   306,   307,   310,   310,   311,   311,   314,
     315
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'('", "')'", "'+'", "'-'", "'*'", "'/'",
  "'^'", "','", "NUM", "WORD", "MODNAME", "FILENAME", "MODULE", "END",
  "BECOMES", "INHIBITS", "ACTIVATES", "INFLUENCES", "SPECIES", "REACTION",
  "DNA", "GENE", "OPERATOR", "EVENT", "COMPARTMENT", "IN", "IS", "VAR",
  "CONST", "DASHES", "ELLIPSES", "FUNCTION", "IMPORT", "'.'", "':'", "';'",
  "'<'", "'='", "'>'", "'!'", "'&'", "'|'", "'\\n'", "'@'", "$accept",
  "input", "import", "module", "@1", "@2", "variableexportlist",
  "variable", "varmaybein", "variablein", "maybein", "modulebody",
  "modulepart", "reaction", "reactantList", "reactionDivider", "formula",
  "mathThing", "lineend", "assignment", "submodule", "@3", "@4",
  "variableimportlist", "varinitialize", "specinit", "reactioninit",
  "dnainit", "geneinit", "operatorinit", "eventinit", "compartmentinit",
  "constspecinit", "constdnainit", "constoperatorinit",
  "constcompartmentinit", "constinit", "dnadef", "dnastrand", "dnamiddle",
  "event", "@5", "@6", "assignmentlist", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    40,    41,    43,    45,    42,    47,    94,
      44,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,    46,    58,    59,    60,
      61,    62,    33,    38,   124,    10,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    48,    48,    48,    49,    51,    50,
      52,    50,    50,    53,    53,    53,    54,    54,    55,    55,
      56,    57,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    65,    65,    66,    66,    68,    67,    69,    67,
      70,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    72,    73,    73,
      73,    74,    74,    74,    75,    75,    75,    76,    76,    76,
      77,    77,    77,    78,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      85,    85,    85,    86,    86,    88,    87,    89,    87,    90,
      90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     0,     8,
       0,     5,     2,     0,     1,     3,     1,     3,     1,     1,
       3,     0,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     8,     6,     0,     1,     2,     3,     4,
       1,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     0,     8,     0,     6,
       0,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     2,     3,
       3,     2,     3,     3,     2,     3,     3,     2,     3,     3,
       2,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     1,     3,     2,     2,
       2,     3,     1,     2,     3,     0,     5,     0,     7,     3,
       5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     6,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,    44,     3,     4,    36,     0,    31,     5,     0,     0,
      32,     0,     0,     0,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    94,    93,     0,   126,   132,     0,
      37,    78,    10,    12,    18,    95,    19,    98,   101,   104,
     107,   110,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,   128,   129,     7,    65,    66,
      61,    62,    63,    64,    67,    68,    47,    45,    48,    70,
      69,    71,    46,     0,    49,     0,   133,     0,     0,    35,
      44,    25,     0,    40,    41,    42,    43,    35,    26,    27,
      28,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,   130,    30,    80,     0,    35,    96,
      99,   102,   105,   108,   111,   114,   116,   118,   120,   122,
     131,    52,    50,    53,   135,    70,     0,    69,    71,     0,
       0,    51,    54,    20,    17,    75,     0,    44,    36,     0,
     127,    74,     0,    38,    36,     0,    97,   100,   103,   106,
     109,   112,   115,   117,   119,   121,   123,   125,   134,    81,
       0,    13,    35,    23,     0,    55,    57,    56,    58,    59,
      60,    76,     0,    35,    39,    44,    21,     0,     0,    14,
      11,    24,     0,   136,    80,   137,     0,    21,     0,    79,
      82,    35,     0,    44,     0,     0,    44,    34,    22,    35,
      15,   139,    21,   138,    21,     9,     0,    77,    33,   140
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    22,    23,   127,   128,   198,    54,    25,    56,
     209,   182,   183,    28,    29,   107,    93,    94,    30,    31,
      32,   204,   126,   180,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,   184,   215,   203
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -196
static const yytype_int16 yypact[] =
{
    -196,    13,  -196,  -196,    76,  -196,    87,    49,    76,    76,
      76,    76,    76,    76,    76,   142,    53,    76,     1,  -196,
    -196,   361,  -196,  -196,   122,    26,    31,  -196,    41,    64,
    -196,    41,    41,    41,    95,   107,   109,   114,   116,   120,
     121,   124,   126,   129,   130,   132,    41,  -196,    76,    41,
     113,  -196,   149,  -196,   -17,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,  -196,   -27,    76,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,   113,   104,  -196,    76,  -196,   141,    76,    10,
     361,  -196,   110,  -196,  -196,  -196,  -196,   117,  -196,  -196,
    -196,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,  -196,    68,  -196,    76,   152,   441,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
      68,  -196,  -196,  -196,  -196,   138,   144,   145,   146,   127,
     151,   113,  -196,   113,  -196,   113,   154,   361,   -27,    64,
    -196,   349,    76,   113,   113,     3,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   113,
      81,    76,   385,  -196,    76,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,   253,   117,   113,   361,   160,    76,    83,   113,
    -196,  -196,    37,  -196,    76,  -196,    12,   295,    76,  -196,
     113,   441,    76,   361,    85,    76,   361,  -196,   113,   413,
     113,   307,   160,  -196,   295,  -196,    76,  -196,  -196,  -196
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,  -196,  -196,  -196,  -196,  -196,    -1,   163,     5,
    -195,   -22,     0,  -196,   -97,    34,   -93,   -89,    21,  -196,
    -196,  -196,  -196,   -14,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,    98,   181,
    -196,  -196,  -196,  -169
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -36
static const yytype_int16 yytable[] =
{
      24,    27,   159,    50,   152,    96,    26,   161,   102,    97,
     165,    95,   217,     2,     3,    77,    75,   102,   -35,    97,
      92,     4,     5,   156,     4,     5,     6,   227,     7,   228,
     -35,   -35,   -35,   -35,     8,     9,    10,    11,    12,    13,
      14,   195,    17,    15,    16,    17,   223,   124,    18,   101,
     216,    19,   108,   109,   110,    98,   157,   229,    20,    21,
     -19,    52,    53,    99,   192,     5,   100,   123,   -19,   102,
     125,   -19,   152,    97,    70,   140,    71,   213,    72,    19,
      73,   103,   104,   105,   106,   196,    20,   211,     5,   222,
      51,   197,   151,   212,   153,   197,   206,   155,   158,    92,
     178,   163,   207,   152,    97,   111,   164,    78,    79,    80,
      81,    82,    83,    84,    85,   141,     5,   112,   152,   113,
     221,   162,     5,   224,   114,   179,   115,    24,     4,     5,
     116,   117,   152,    26,   118,   152,   119,   142,   143,   120,
     121,   144,   122,   145,   146,   147,   148,   149,   150,    97,
      95,   -18,    -8,   154,    96,   181,    92,   191,    97,   -18,
     151,   194,   -18,    63,    64,    65,    66,    67,    68,    69,
     189,    55,    57,    58,    59,    60,    61,    62,   185,    74,
     199,    24,   201,   202,   186,   187,   188,    26,   208,   219,
     214,   151,   164,   193,    92,   190,   210,   160,    76,     0,
       0,     0,     0,   179,     0,     0,   151,   218,     0,     0,
      24,   220,    92,     0,   202,    92,    26,     0,    24,   201,
     151,     0,     0,   151,    26,   202,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,   141,     5,     0,     0,     0,     0,
       0,     0,     0,     0,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   142,   143,     0,     0,
     205,     0,   145,   146,   147,   148,   149,   150,    78,    79,
      80,    81,    82,    83,    84,    85,   141,     5,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,   141,     5,
       0,     0,     0,   208,     0,     0,     0,     0,   142,   143,
       0,     0,     0,     0,   145,   146,   147,   148,   149,   150,
     142,   143,     0,     0,   226,     0,   145,   146,   147,   148,
     149,   150,    78,    79,    80,    81,    82,    83,    84,    85,
     141,     5,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     5,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,     0,     0,     0,     0,   145,   146,
     147,   148,   149,   150,    87,    88,     4,     5,     6,     0,
      89,   200,    90,    91,     0,     0,     8,     9,    10,    11,
      12,    13,    14,     0,     0,    15,    16,    17,     0,     0,
       0,     0,     0,    19,     4,     5,     6,     0,     0,   225,
      20,    21,     0,     0,     8,     9,    10,    11,    12,    13,
      14,     0,     0,    15,    16,    17,     0,     0,     0,     0,
       0,    19,     4,     5,     6,     0,     0,     0,    20,    21,
       0,     0,     8,     9,    10,    11,    12,    13,    14,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,    20,    21
};

static const yytype_int16 yycheck[] =
{
       1,     1,    99,     4,    93,    32,     1,   100,     5,    36,
     107,    28,   207,     0,     1,    14,    17,     5,     5,    36,
      21,    11,    12,    13,    11,    12,    13,   222,    15,   224,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    38,    32,    30,    31,    32,   215,    48,    35,    28,
      38,    38,    31,    32,    33,    29,    46,   226,    45,    46,
      29,    12,    13,    37,   157,    12,    40,    46,    37,     5,
      49,    40,   161,    36,    21,    76,    23,    40,    25,    38,
      27,    17,    18,    19,    20,     4,    45,     4,    12,     4,
       3,    10,    93,    10,    95,    10,   193,    98,    99,   100,
      32,   102,   195,   192,    36,    10,   107,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    10,   207,    10,
     213,    11,    12,   216,    10,   126,    10,   128,    11,    12,
      10,    10,   221,   128,    10,   224,    10,    33,    34,    10,
      10,    37,    10,    39,    40,    41,    42,    43,    44,    36,
      28,    29,     3,    12,    32,     3,   157,     3,    36,    37,
     161,   162,    40,    21,    22,    23,    24,    25,    26,    27,
      43,     8,     9,    10,    11,    12,    13,    14,    40,    16,
     181,   182,   182,   184,    40,    40,    40,   182,    28,   211,
     204,   192,   193,   159,   195,    44,   197,    99,    17,    -1,
      -1,    -1,    -1,   204,    -1,    -1,   207,   208,    -1,    -1,
     211,   212,   213,    -1,   215,   216,   211,    -1,   219,   219,
     221,    -1,    -1,   224,   219,   226,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    33,    34,    -1,    -1,
      37,    -1,    39,    40,    41,    42,    43,    44,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      33,    34,    -1,    -1,    37,    -1,    39,    40,    41,    42,
      43,    44,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    33,    34,    11,    12,    13,    -1,
      39,    16,    41,    42,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    38,    11,    12,    13,    -1,    -1,    16,
      45,    46,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    38,    11,    12,    13,    -1,    -1,    -1,    45,    46,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,     0,     1,    11,    12,    13,    15,    21,    22,
      23,    24,    25,    26,    27,    30,    31,    32,    35,    38,
      45,    46,    49,    50,    54,    55,    56,    59,    60,    61,
      65,    66,    67,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      54,     3,    12,    13,    54,    55,    56,    55,    55,    55,
      55,    55,    55,    21,    22,    23,    24,    25,    26,    27,
      21,    23,    25,    27,    55,    54,    86,    14,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    33,    34,    39,
      41,    42,    54,    63,    64,    28,    32,    36,    29,    37,
      40,    65,     5,    17,    18,    19,    20,    62,    65,    65,
      65,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    65,    54,    65,    69,    51,    52,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      54,    11,    33,    34,    37,    39,    40,    41,    42,    43,
      44,    54,    64,    54,    12,    54,    13,    46,    54,    61,
      85,    63,    11,    54,    54,    61,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    32,    54,
      70,     3,    58,    59,    88,    40,    40,    40,    40,    43,
      44,     3,    63,    62,    54,    38,     4,    10,    53,    54,
      16,    59,    54,    90,    68,    37,    61,    63,    28,    57,
      54,     4,    10,    40,    70,    89,    38,    57,    54,    58,
      54,    63,     4,    90,    63,    16,    37,    57,    57,    90
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
        case 3:
#line 68 "antimony.ypp"
    {;}
    break;

  case 4:
#line 69 "antimony.ypp"
    { /*cout << endl << $2->ToString() << endl << endl;*/ ;}
    break;

  case 5:
#line 70 "antimony.ypp"
    {;}
    break;

  case 6:
#line 71 "antimony.ypp"
    {YYABORT;;}
    break;

  case 7:
#line 74 "antimony.ypp"
    { if (g_registry.OpenFile(*((yyvsp[(2) - (2)].word)))==0) YYABORT;;}
    break;

  case 8:
#line 77 "antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(2) - (2)].word));;}
    break;

  case 9:
#line 78 "antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                ;}
    break;

  case 10:
#line 83 "antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(2) - (2)].word));;}
    break;

  case 11:
#line 84 "antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                ;}
    break;

  case 12:
#line 89 "antimony.ypp"
    {g_registry.SetError("module '" + *((yyvsp[(2) - (2)].word)) + "' already defined."); YYABORT;;}
    break;

  case 13:
#line 93 "antimony.ypp"
    {;}
    break;

  case 14:
#line 94 "antimony.ypp"
    {g_registry.AddVariableToCurrentExportList((yyvsp[(1) - (1)].variable)); ;}
    break;

  case 15:
#line 95 "antimony.ypp"
    { g_registry.AddVariableToCurrentExportList((yyvsp[(3) - (3)].variable)); ;}
    break;

  case 16:
#line 98 "antimony.ypp"
    {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[(1) - (1)].word)); ;}
    break;

  case 17:
#line 99 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable)->GetSubVariable((yyvsp[(3) - (3)].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[(3) - (3)].word)) + "' is not a subvariable of '" + (yyvsp[(1) - (3)].variable)->GetNameDelimitedBy('.') + "'.");
                    YYABORT;
                  }
                ;}
    break;

  case 18:
#line 108 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);;}
    break;

  case 19:
#line 109 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);;}
    break;

  case 20:
#line 112 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetCompartment((yyvsp[(3) - (3)].variable))) YYABORT; (yyval.variable) = (yyvsp[(1) - (3)].variable);;}
    break;

  case 21:
#line 115 "antimony.ypp"
    {(yyval.variable) = NULL;;}
    break;

  case 22:
#line 116 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable);;}
    break;

  case 23:
#line 119 "antimony.ypp"
    {;}
    break;

  case 24:
#line 120 "antimony.ypp"
    {;}
    break;

  case 25:
#line 123 "antimony.ypp"
    {;}
    break;

  case 26:
#line 124 "antimony.ypp"
    {;}
    break;

  case 27:
#line 125 "antimony.ypp"
    {;}
    break;

  case 28:
#line 126 "antimony.ypp"
    {;}
    break;

  case 29:
#line 127 "antimony.ypp"
    {;}
    break;

  case 30:
#line 128 "antimony.ypp"
    {;}
    break;

  case 31:
#line 129 "antimony.ypp"
    {;}
    break;

  case 32:
#line 130 "antimony.ypp"
    {;}
    break;

  case 33:
#line 134 "antimony.ypp"
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[(3) - (8)].reactantList), (yyvsp[(4) - (8)].reactionDivider), (yyvsp[(5) - (8)].reactantList), (yyvsp[(7) - (8)].formula), (yyvsp[(1) - (8)].variable));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[(8) - (8)].variable) != NULL) {
                    if ((yyvsp[(1) - (8)].variable)->SetCompartment((yyvsp[(8) - (8)].variable))) YYABORT;
                  }
                ;}
    break;

  case 34:
#line 142 "antimony.ypp"
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[(1) - (6)].reactantList), (yyvsp[(2) - (6)].reactionDivider), (yyvsp[(3) - (6)].reactantList), (yyvsp[(5) - (6)].formula));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[(6) - (6)].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[(6) - (6)].variable))) YYABORT;
                  }
                ;}
    break;

  case 35:
#line 151 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); ;}
    break;

  case 36:
#line 152 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(1) - (1)].variable)); ;}
    break;

  case 37:
#line 153 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(2) - (2)].variable), (yyvsp[(1) - (2)].num)); ;}
    break;

  case 38:
#line 154 "antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (3)].reactantList); (yyvsp[(1) - (3)].reactantList)->AddReactant((yyvsp[(3) - (3)].variable)); ;}
    break;

  case 39:
#line 155 "antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (4)].reactantList); (yyvsp[(1) - (4)].reactantList)->AddReactant((yyvsp[(4) - (4)].variable), (yyvsp[(3) - (4)].num)); ;}
    break;

  case 40:
#line 159 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;;}
    break;

  case 41:
#line 160 "antimony.ypp"
    {(yyval.reactionDivider) = rdInhibits;;}
    break;

  case 42:
#line 161 "antimony.ypp"
    {(yyval.reactionDivider) = rdActivates;;}
    break;

  case 43:
#line 162 "antimony.ypp"
    {(yyval.reactionDivider) = rdInfluences;;}
    break;

  case 44:
#line 165 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); ;}
    break;

  case 45:
#line 166 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddEllipses();;}
    break;

  case 46:
#line 167 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddVariable((yyvsp[(1) - (1)].variable)); ;}
    break;

  case 47:
#line 168 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddNum((yyvsp[(1) - (1)].num)); ;}
    break;

  case 48:
#line 169 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddText((yyvsp[(1) - (1)].word));;}
    break;

  case 49:
#line 170 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddMathThing((yyvsp[(1) - (1)].character)); ;}
    break;

  case 50:
#line 171 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddEllipses();;}
    break;

  case 51:
#line 172 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddVariable((yyvsp[(2) - (2)].variable)); ;}
    break;

  case 52:
#line 173 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddNum((yyvsp[(2) - (2)].num)); ;}
    break;

  case 53:
#line 174 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddText((yyvsp[(2) - (2)].word));;}
    break;

  case 54:
#line 175 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddMathThing((yyvsp[(2) - (2)].character)); ;}
    break;

  case 55:
#line 176 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('<'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 56:
#line 177 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('>'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 57:
#line 178 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('='); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 58:
#line 179 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('!'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 59:
#line 180 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); ;}
    break;

  case 60:
#line 181 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); ;}
    break;

  case 61:
#line 184 "antimony.ypp"
    {(yyval.character) = '+';;}
    break;

  case 62:
#line 185 "antimony.ypp"
    {(yyval.character) = '-';;}
    break;

  case 63:
#line 186 "antimony.ypp"
    {(yyval.character) = '*';;}
    break;

  case 64:
#line 187 "antimony.ypp"
    {(yyval.character) = '/';;}
    break;

  case 65:
#line 188 "antimony.ypp"
    {(yyval.character) = '(';;}
    break;

  case 66:
#line 189 "antimony.ypp"
    {(yyval.character) = ')';;}
    break;

  case 67:
#line 190 "antimony.ypp"
    {(yyval.character) = '^';;}
    break;

  case 68:
#line 191 "antimony.ypp"
    {(yyval.character) = ',';;}
    break;

  case 69:
#line 192 "antimony.ypp"
    {(yyval.character) = '>';;}
    break;

  case 70:
#line 193 "antimony.ypp"
    {(yyval.character) = '<';;}
    break;

  case 71:
#line 194 "antimony.ypp"
    {(yyval.character) = '!';;}
    break;

  case 72:
#line 197 "antimony.ypp"
    {;}
    break;

  case 73:
#line 198 "antimony.ypp"
    {;}
    break;

  case 74:
#line 201 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetFormula((yyvsp[(3) - (3)].formula))) YYABORT; ;}
    break;

  case 75:
#line 202 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->Synchronize((yyvsp[(3) - (3)].variable))) YYABORT;;}
    break;

  case 76:
#line 205 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetModule((yyvsp[(3) - (4)].word))) YYABORT;;}
    break;

  case 77:
#line 205 "antimony.ypp"
    {if ((yyvsp[(8) - (8)].variable) != NULL) {if ((yyvsp[(1) - (8)].variable)->SetCompartment((yyvsp[(8) - (8)].variable))) YYABORT;};}
    break;

  case 78:
#line 206 "antimony.ypp"
    {if(g_registry.CurrentModule()->SetModule((yyvsp[(1) - (2)].word))) YYABORT;;}
    break;

  case 79:
#line 206 "antimony.ypp"
    {if ((yyvsp[(6) - (6)].variable) != NULL) {if (g_registry.SetCompartmentOfCurrentSubmod((yyvsp[(6) - (6)].variable))) YYABORT;};}
    break;

  case 80:
#line 209 "antimony.ypp"
    {;}
    break;

  case 81:
#line 210 "antimony.ypp"
    {if (g_registry.AddVariableToCurrentImportList((yyvsp[(1) - (1)].variable))) YYABORT; ;}
    break;

  case 82:
#line 211 "antimony.ypp"
    { if (g_registry.AddVariableToCurrentImportList((yyvsp[(3) - (3)].variable))) YYABORT; ;}
    break;

  case 83:
#line 214 "antimony.ypp"
    { ;}
    break;

  case 84:
#line 215 "antimony.ypp"
    { ;}
    break;

  case 85:
#line 216 "antimony.ypp"
    { ;}
    break;

  case 86:
#line 217 "antimony.ypp"
    { ;}
    break;

  case 87:
#line 218 "antimony.ypp"
    { ;}
    break;

  case 88:
#line 219 "antimony.ypp"
    { ;}
    break;

  case 89:
#line 220 "antimony.ypp"
    { ;}
    break;

  case 90:
#line 221 "antimony.ypp"
    { ;}
    break;

  case 91:
#line 222 "antimony.ypp"
    { ;}
    break;

  case 92:
#line 223 "antimony.ypp"
    { ;}
    break;

  case 93:
#line 224 "antimony.ypp"
    { ;}
    break;

  case 94:
#line 225 "antimony.ypp"
    { ;}
    break;

  case 95:
#line 228 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 96:
#line 229 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 97:
#line 230 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 98:
#line 233 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 99:
#line 234 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 100:
#line 235 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 101:
#line 238 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 102:
#line 239 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 103:
#line 240 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 104:
#line 243 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 105:
#line 244 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 106:
#line 245 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 107:
#line 248 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 108:
#line 249 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 109:
#line 250 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 110:
#line 253 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varEvent)) YYABORT; ;}
    break;

  case 111:
#line 254 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varEvent)) YYABORT; ;}
    break;

  case 112:
#line 255 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varEvent)) YYABORT; ;}
    break;

  case 113:
#line 259 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 114:
#line 260 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 115:
#line 261 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 116:
#line 264 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; 
                                        if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 117:
#line 266 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; 
                                               if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 118:
#line 271 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; 
                                    if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 119:
#line 273 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; 
                                           if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 120:
#line 278 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; 
                                         if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 121:
#line 280 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; 
                                                if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 122:
#line 285 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; 
                                            if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 123:
#line 287 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; 
                                                   if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 124:
#line 291 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 125:
#line 292 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 126:
#line 295 "antimony.ypp"
    {if (g_registry.SaveWorkingStrand()) YYABORT;;}
    break;

  case 127:
#line 296 "antimony.ypp"
    {if (g_registry.SetStrandAs((yyvsp[(1) - (3)].variable))) YYABORT;;}
    break;

  case 128:
#line 299 "antimony.ypp"
    {if (g_registry.SetNewUpstreamOpen((yyvsp[(2) - (2)].variable))) YYABORT;;}
    break;

  case 129:
#line 300 "antimony.ypp"
    {g_registry.SetOpenUpstream(); ;}
    break;

  case 130:
#line 301 "antimony.ypp"
    {if (g_registry.SetDownstreamEnd((yyvsp[(2) - (2)].variable))) YYABORT;;}
    break;

  case 131:
#line 302 "antimony.ypp"
    {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[(3) - (3)].variable))) YYABORT;;}
    break;

  case 132:
#line 303 "antimony.ypp"
    { ;}
    break;

  case 133:
#line 306 "antimony.ypp"
    {if (g_registry.SetNewDownstreamOpen((yyvsp[(1) - (2)].variable))) YYABORT;;}
    break;

  case 134:
#line 307 "antimony.ypp"
    {if (g_registry.SetDownstreamOpen((yyvsp[(2) - (3)].variable))) YYABORT;;}
    break;

  case 135:
#line 310 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(2) - (3)].formula))) YYABORT;;}
    break;

  case 136:
#line 310 "antimony.ypp"
    {;}
    break;

  case 137:
#line 311 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (5)].formula), (yyvsp[(1) - (5)].variable))) YYABORT;;}
    break;

  case 138:
#line 311 "antimony.ypp"
    {;}
    break;

  case 139:
#line 314 "antimony.ypp"
    {if (g_registry.AddResultToCurrentEvent((yyvsp[(1) - (3)].variable), (yyvsp[(3) - (3)].formula))) YYABORT;;}
    break;

  case 140:
#line 315 "antimony.ypp"
    {if (g_registry.AddResultToCurrentEvent((yyvsp[(1) - (5)].variable), (yyvsp[(3) - (5)].formula))) YYABORT;;}
    break;


/* Line 1267 of yacc.c.  */
#line 2400 "antimony.tab.cpp"
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


#line 318 "antimony.ypp"



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
  while (cc == ' ' ||
         cc == '\t') {
    g_registry.input->get(cc);
  }

  // Parse words
  if (isalpha(cc) || cc == '_') {
    string word;
    while (isalpha(cc) || isdigit(cc) || cc == '_') {
      word += cc;
      g_registry.input->get(cc);
    }
    g_registry.input->unget();
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
      return IN;
    }
    if (CaselessStrCmp(word, "is")) {
      return IS;
    }
    if (CaselessStrCmp(word, "var")) {
      return VAR;
    }
    if (CaselessStrCmp(word, "const")) {
      return CONST;
    }
    if (CaselessStrCmp(word, "ext")) {
      return CONST;
    }
    if (CaselessStrCmp(word, "import")) {
      return IMPORT;
    }
    if (CaselessStrCmp(word, "event")) {
      return EVENT;
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
    return WORD;
  }

  // Parse numbers
  if (isdigit(cc)) {
    double number;
    g_registry.input->unget();
    *g_registry.input >> number;
    yylval.num = number;
    //Now check to see if the last thing read was an 'E'/'e'
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
    if (cc == '>') {
      return BECOMES;
    }
    if (cc == '|') {
      return INHIBITS;
    }
    if (cc == 'o') {
      return ACTIVATES;
    }
    if (cc == '(') {
      return INFLUENCES;
    }
    if (cc == '-') {
      while (cc == '-') {
        g_registry.input->get(cc);
      }
      g_registry.input->unget();
      return DASHES;
    }
    g_registry.input->unget();
    cc = '-';
    return cc;
  }

  //Skip comments:
  if (cc == '/') {
    g_registry.input->get(cc);
    if (cc == '/') {
      while (cc != '\n' && cc != '\r') {
        g_registry.input->get(cc);
      }
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

  //Parse filenames
  if (cc == '"') {
    string filename;
    long ccount = 0;
    g_registry.input->get(cc);
    while (cc != '"' && cc != '\r' && cc != '\n' && !g_registry.input->eof()) {
      filename += cc;
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
      yylval.word = g_registry.AddWord(filename);
      return FILENAME;
    }
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

int main(int argc, char** argv)
{
  //yydebug = 1;
  int retval = 0;
  for (long file=1; file<argc; file++) {
    if (strstr(argv[file], ".xml") != NULL) {
      retval = loadSBMLFile(argv[file]);
    }
    else {
      retval=loadFile(argv[file]);
    }
    if (retval == -1) {
      cout << getLastError() << endl;
    }
    else {
      cout << argv[file] << " read successfully with file handle " << SizeTToString(retval) << "." << endl;
    }
  }
  for (size_t file=0; file<getNumFiles(); file++) {
    revertTo(file+1);
    size_t nummods = getNumModules();
    char** modnames = getModuleNames();
    string filename(argv[file+1]);
    size_t slash = filename.find("/");
    while (slash != string::npos) {
      filename.erase(0, slash+1);
      slash = filename.find("/");
    }
    
    if (filename.find(".txt") != string::npos) {
      filename.erase(filename.find(".txt"), 4);
    }
    if (filename.find(".xml") != string::npos) {
      filename.erase(filename.find(".xml"), 4);
    }
    for (size_t mod=0; mod<nummods; mod++) {
      cout << "Information for file " << SizeTToString(file+1) <<", module '" << modnames[mod] << "'" << endl;
      cout << "***ToString (" << modnames[mod] << ") ***" << endl;
      cout << g_registry.GetModule(modnames[mod])->ToString().c_str() << endl << endl;
      cout << "***Jarnac (" << modnames[mod] << ") ***" << endl;
      cout << getJarnacString(modnames[mod]) << endl;
      cout << endl << "***printAllDataFor (" << modnames[mod] << ") (from the API):***" << endl;
      printAllDataFor(modnames[mod]);
      cout << endl << "***Antimony (" << modnames[mod] << ")" << endl;
      cout << getAntimonyString(modnames[mod]) << endl;
      cout << endl;
      cout << endl;
      string antname = "output/" + filename + "_" + modnames[mod] + "_ant.txt";
      string sbmlname = "output/" + filename + "_" + modnames[mod] + "_sbml.xml";
      string jarname = "output/" + filename + "_" + modnames[mod] + "_jar.txt";
      if (writeAntimonyFile(antname.c_str(), modnames[mod])) {
        cout << "Successfully wrote file " << antname.c_str() << endl;
      }
      else {
        cout << "Problem writing file " << antname.c_str() << endl;
      }
      if (writeSBMLFile(sbmlname.c_str(), modnames[mod])) {
        cout << "Successfully wrote file " << sbmlname.c_str() << endl;
      }
      else {
        cout << "Problem writing file " << sbmlname.c_str() << endl;
      }
      if (writeJarnacFile(jarname.c_str(), modnames[mod])) {
        cout << "Successfully wrote file " << jarname.c_str() << endl;
      }
      else {
        cout << "Problem writing file " << jarname.c_str() << endl;
      }
        
    }
    freeAll();
  }
  /* Just for testing: */
  clearPreviousLoads();
  if (argc>1) {
    int ret2 = loadFile(argv[1]);
    if (ret2 == -1) {
      cout << "Error when re-reading file " << argv[1] << ":  " << getLastError() << endl;
    }
    else {
      cout << argv[1] << " re-read successfully ." << endl;
    }
  }
  else {
    cout << "No files specified." << endl;
  }
  if (retval == -1) return 1;
  return 0;
}

