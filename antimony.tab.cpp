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
#define YYLSP_NEEDED 1



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
     PROTEIN = 269,
     DNA = 270,
     GENE = 271,
     PROMOTER = 272,
     OPERATOR = 273,
     VAR = 274,
     CONST = 275,
     DASHES = 276,
     ELLIPSES = 277,
     FUNCTION = 278,
     INCLUDE = 279
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
#define PROTEIN 269
#define DNA 270
#define GENE 271
#define PROMOTER 272
#define OPERATOR 273
#define VAR 274
#define CONST 275
#define DASHES 276
#define ELLIPSES 277
#define FUNCTION 278
#define INCLUDE 279




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
#line 34 "antimony.ypp"
{
  char character;
  const string* word;
  double num;
  rd_type reactionDivider;
  Formula* formula;
  Module* module;
  ReactantList* reactantList;
  AntimonyReaction* reaction;
  Variable* variable;
  Variable* localvariable;
}
/* Line 187 of yacc.c.  */
#line 188 "antimony.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 213 "antimony.tab.cpp"

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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   280

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNRULES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    32,     2,     2,     2,     2,
       3,     4,     7,     5,    33,     6,    34,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    38,
      35,    40,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     9,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    20,    21,
      30,    31,    37,    40,    41,    43,    47,    49,    53,    57,
      59,    62,    65,    68,    71,    74,    77,    79,    80,    89,
      95,    96,    98,   101,   105,   110,   112,   114,   116,   118,
     119,   121,   123,   125,   127,   129,   132,   135,   138,   141,
     143,   145,   147,   149,   151,   153,   155,   157,   159,   161,
     162,   167,   168,   176,   177,   183,   184,   186,   190,   196,
     198,   202,   204,   206,   208,   210,   212,   214,   216,   218,
     220,   222,   224,   227,   231,   235,   238,   242,   246,   249,
     253,   257,   260,   264,   268,   271,   275,   279,   282,   286,
     290,   294,   298,   302,   306,   310,   314,   318,   322,   325,
     329,   332,   335,   338,   342,   344,   347
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    -1,    42,    43,    -1,    42,    44,    -1,
      42,    50,    -1,    42,     1,    -1,    32,    31,    13,    -1,
      -1,    14,    11,    45,     3,    47,     4,    49,    15,    -1,
      -1,    14,    11,    46,    49,    15,    -1,    14,    12,    -1,
      -1,    48,    -1,    47,    33,    48,    -1,    11,    -1,    48,
      34,    11,    -1,    35,    48,    36,    -1,    50,    -1,    49,
      50,    -1,    51,    57,    -1,    58,    57,    -1,    60,    57,
      -1,    65,    57,    -1,    77,    57,    -1,    57,    -1,    -1,
      48,    37,    52,    53,    54,    53,    38,    55,    -1,    53,
      54,    53,    38,    55,    -1,    -1,    48,    -1,    10,    48,
      -1,    53,     5,    48,    -1,    53,     5,    10,    48,    -1,
      16,    -1,    17,    -1,    18,    -1,    19,    -1,    -1,    29,
      -1,    48,    -1,    10,    -1,    30,    -1,    56,    -1,    55,
      48,    -1,    55,    10,    -1,    55,    30,    -1,    55,    56,
      -1,     5,    -1,     6,    -1,     7,    -1,     8,    -1,     3,
      -1,     4,    -1,     9,    -1,    33,    -1,    38,    -1,    39,
      -1,    -1,    48,    40,    59,    55,    -1,    -1,    48,    37,
      12,     3,    61,    63,     4,    -1,    -1,    12,     3,    62,
      63,     4,    -1,    -1,    48,    -1,    63,    33,    48,    -1,
      63,    33,    48,    40,    64,    -1,    11,    -1,    64,    34,
      11,    -1,    66,    -1,    67,    -1,    68,    -1,    69,    -1,
      70,    -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,
      75,    -1,    76,    -1,    20,    48,    -1,    26,    20,    48,
      -1,    66,    33,    48,    -1,    21,    48,    -1,    26,    21,
      48,    -1,    67,    33,    48,    -1,    22,    48,    -1,    26,
      22,    48,    -1,    68,    33,    48,    -1,    23,    48,    -1,
      26,    23,    48,    -1,    69,    33,    48,    -1,    24,    48,
      -1,    26,    24,    48,    -1,    70,    33,    48,    -1,    25,
      48,    -1,    26,    25,    48,    -1,    71,    33,    48,    -1,
      27,    21,    48,    -1,    72,    33,    48,    -1,    27,    23,
      48,    -1,    73,    33,    48,    -1,    27,    24,    48,    -1,
      74,    33,    48,    -1,    27,    25,    48,    -1,    75,    33,
      48,    -1,    27,    48,    -1,    76,    33,    48,    -1,    28,
      48,    -1,    28,    78,    -1,    78,    48,    -1,    28,    78,
      48,    -1,    78,    -1,    48,    28,    -1,    78,    48,    28,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    67,    68,    69,    70,    73,    76,    76,
      82,    82,    88,    92,    93,    94,    97,    98,   104,   109,
     110,   113,   114,   115,   116,   117,   118,   121,   121,   126,
     133,   134,   135,   136,   137,   141,   142,   143,   144,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   159,
     160,   161,   162,   163,   164,   165,   166,   169,   170,   173,
     173,   176,   176,   177,   177,   180,   181,   182,   183,   186,
     187,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   203,   204,   205,   208,   209,   210,   213,   214,
     215,   218,   219,   220,   223,   224,   225,   228,   229,   230,
     233,   235,   239,   241,   246,   248,   253,   255,   259,   260,
     263,   264,   265,   266,   267,   270,   271
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'('", "')'", "'+'", "'-'", "'*'", "'/'",
  "'^'", "NUM", "WORD", "MODNAME", "FILENAME", "MODULE", "END", "BECOMES",
  "INHIBITS", "ACTIVATES", "INFLUENCES", "SPECIES", "PROTEIN", "DNA",
  "GENE", "PROMOTER", "OPERATOR", "VAR", "CONST", "DASHES", "ELLIPSES",
  "FUNCTION", "INCLUDE", "'#'", "','", "'.'", "'<'", "'>'", "':'", "';'",
  "'\\n'", "'='", "$accept", "input", "include", "module", "@1", "@2",
  "variableexportlist", "variable", "modulebody", "modulepart", "reaction",
  "@3", "reactantList", "reactionDivider", "formula", "mathThing",
  "lineend", "assignment", "@4", "submodule", "@5", "@6",
  "variableimportlist", "localvariable", "varinitialize", "specinit",
  "protinit", "dnainit", "geneinit", "promoterinit", "operatorinit",
  "constprotinit", "constgeneinit", "constpromoterinit",
  "constoperatorinit", "constinit", "dnastrand", "dnamiddle", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    40,    41,    43,    45,    42,    47,    94,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,    35,    44,    46,    60,    62,    58,    59,    10,
      61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    42,    42,    42,    43,    45,    44,
      46,    44,    44,    47,    47,    47,    48,    48,    48,    49,
      49,    50,    50,    50,    50,    50,    50,    52,    51,    51,
      53,    53,    53,    53,    53,    54,    54,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    59,
      58,    61,    60,    62,    60,    63,    63,    63,    63,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    66,    67,    67,    67,    68,    68,
      68,    69,    69,    69,    70,    70,    70,    71,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    77,    77,    77,    78,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     3,     0,     8,
       0,     5,     2,     0,     1,     3,     1,     3,     3,     1,
       2,     2,     2,     2,     2,     2,     1,     0,     8,     5,
       0,     1,     2,     3,     4,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     0,     7,     0,     5,     0,     1,     3,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     3,     2,     3,     3,     2,     3,
       3,     2,     3,     3,     2,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       2,     2,     2,     3,     1,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     6,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      58,     3,     4,    31,     5,     0,     0,    26,     0,     0,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,   114,    32,    63,    10,    12,    82,    85,
      88,    91,    94,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   110,   111,     0,     0,   115,
       0,    27,    59,    21,     0,    35,    36,    37,    38,    30,
      22,    23,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,   112,    65,     0,    30,    83,
      86,    89,    92,    95,    98,   100,   102,   104,   106,   113,
       7,    18,    17,     0,    30,    39,     0,    33,    31,     0,
      84,    87,    90,    93,    96,    99,   101,   103,   105,   107,
     109,   116,    66,     0,    13,    30,    19,    61,     0,    53,
      54,    49,    50,    51,    52,    55,    42,    40,    43,    56,
      41,    60,    44,    34,    39,    64,     0,     0,    14,    11,
      20,    65,    30,    46,    47,    45,    48,    29,    67,    30,
       0,     0,     0,     0,    30,    15,    62,    39,    69,    68,
       9,    28,     0,    70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    21,    22,    97,    98,   157,    23,   135,   136,
      25,   114,    26,    79,   151,   152,    27,    28,   115,    29,
     161,    96,   133,   179,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -121
static const yytype_int16 yypact[] =
{
    -121,   170,  -121,  -121,    14,  -121,    10,    18,    14,    14,
      14,    14,    14,    14,   250,   108,    14,     9,    14,  -121,
    -121,  -121,  -121,   125,  -121,    29,    55,  -121,    29,    29,
      29,    32,    36,    43,    44,    45,    72,    75,    76,    81,
      83,    84,    29,    14,    86,  -121,   103,  -121,    86,    86,
      86,    86,    86,    86,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    86,    -1,    14,   105,    -8,  -121,
     111,   113,  -121,  -121,    80,  -121,  -121,  -121,  -121,    93,
    -121,  -121,  -121,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,  -121,     4,    14,   120,   241,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,     4,
    -121,  -121,  -121,   124,    93,    13,    14,    86,    86,    -3,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,  -121,    86,    11,    14,   200,  -121,  -121,    55,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
      86,    91,  -121,    86,    13,  -121,    14,    30,    86,  -121,
    -121,    14,    93,  -121,  -121,    86,  -121,    91,    73,   241,
      14,    33,    -2,   129,   221,    86,  -121,    13,  -121,   102,
    -121,    91,   130,  -121
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,  -121,  -121,  -121,  -121,    -4,   -27,     0,
    -121,  -121,   -69,     6,  -113,  -120,   109,  -121,  -121,  -121,
    -121,  -121,   -16,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,   132
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -31
static const yytype_int16 yytable[] =
{
      44,    24,    74,    74,    48,    49,    50,    51,    52,    53,
     119,    64,    65,    45,    68,   155,   139,   140,   141,   142,
     143,   144,   145,   146,     5,     5,    70,    69,   111,    46,
      47,   166,   131,    70,   169,   154,   177,   176,    70,    95,
      67,   167,   147,   148,   156,   138,   149,   166,    18,    18,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      74,   166,   109,   170,   181,    83,   156,    19,    20,    84,
     117,    75,    76,    77,    78,   118,    85,    86,    87,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     116,     5,   132,   172,   139,   140,   141,   142,   143,   144,
     145,   163,     5,     4,     5,    88,    -8,    70,    89,    90,
     118,   150,   153,   173,    91,    18,    92,    93,   110,     5,
      70,   164,   112,   134,   149,   113,    18,   137,    18,    60,
     158,    61,    62,    63,    73,   160,   182,    80,    81,    82,
     178,   183,   174,    18,   162,   171,     0,   165,    66,     0,
     150,    94,   168,    69,     0,     0,     0,   132,   118,    70,
       0,     0,    71,   165,     0,    72,   175,     0,     0,     0,
       2,     3,     0,   150,   160,   -30,     0,   165,     0,     0,
       4,     5,     6,     0,     7,     0,   -30,   -30,   -30,   -30,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
       0,     0,    17,     0,     0,    18,     0,     0,    19,    20,
       4,     5,     6,     0,     0,   159,     0,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
       0,     4,     5,     6,     0,    18,   180,     0,    19,    20,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,     4,     5,     6,     0,     0,    18,     0,     0,    19,
      20,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      54,    55,    56,    57,    58,    59,    18,     0,     0,    19,
      20
};

static const yytype_int16 yycheck[] =
{
       4,     1,     5,     5,     8,     9,    10,    11,    12,    13,
      79,    15,    16,     3,    18,     4,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    11,    34,    28,    36,    11,
      12,   151,    28,    34,     4,    38,    38,     4,    34,    43,
      31,   154,    29,    30,    33,   114,    33,   167,    35,    35,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       5,   181,    66,    33,   177,    33,    33,    38,    39,    33,
      74,    16,    17,    18,    19,    79,    33,    33,    33,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      10,    11,    96,   162,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    10,    11,    33,     3,    34,    33,    33,
     114,   115,   116,    40,    33,    35,    33,    33,    13,    11,
      34,    30,    11,     3,    33,    12,    35,     3,    35,    21,
     134,    23,    24,    25,    25,   135,    34,    28,    29,    30,
      11,    11,   169,    35,   138,   161,    -1,   151,    16,    -1,
     154,    42,   156,    28,    -1,    -1,    -1,   161,   162,    34,
      -1,    -1,    37,   167,    -1,    40,   170,    -1,    -1,    -1,
       0,     1,    -1,   177,   174,     5,    -1,   181,    -1,    -1,
      10,    11,    12,    -1,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    32,    -1,    -1,    35,    -1,    -1,    38,    39,
      10,    11,    12,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    10,    11,    12,    -1,    35,    15,    -1,    38,    39,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    10,    11,    12,    -1,    -1,    35,    -1,    -1,    38,
      39,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      20,    21,    22,    23,    24,    25,    35,    -1,    -1,    38,
      39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,     0,     1,    10,    11,    12,    14,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    32,    35,    38,
      39,    43,    44,    48,    50,    51,    53,    57,    58,    60,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    48,     3,    11,    12,    48,    48,
      48,    48,    48,    48,    20,    21,    22,    23,    24,    25,
      21,    23,    24,    25,    48,    48,    78,    31,    48,    28,
      34,    37,    40,    57,     5,    16,    17,    18,    19,    54,
      57,    57,    57,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    57,    48,    62,    45,    46,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      13,    36,    11,    12,    52,    59,    10,    48,    48,    53,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    28,    48,    63,     3,    49,    50,     3,    53,     3,
       4,     5,     6,     7,     8,     9,    10,    29,    30,    33,
      48,    55,    56,    48,    38,     4,    33,    47,    48,    15,
      50,    61,    54,    10,    30,    48,    56,    55,    48,     4,
      33,    63,    53,    40,    49,    48,     4,    38,    11,    64,
      15,    55,    34,    11
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

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
  yylsp = yyls;
#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 67 "antimony.ypp"
    {;}
    break;

  case 4:
#line 68 "antimony.ypp"
    { /*cout << endl << $2->ToString() << endl << endl;*/ ;}
    break;

  case 5:
#line 69 "antimony.ypp"
    {;}
    break;

  case 6:
#line 70 "antimony.ypp"
    {YYABORT;;}
    break;

  case 7:
#line 73 "antimony.ypp"
    { if (g_registry.OpenFile(*((yyvsp[(3) - (3)].word)))==0) YYABORT;;}
    break;

  case 8:
#line 76 "antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(2) - (2)].word));;}
    break;

  case 9:
#line 77 "antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  (yyval.module)->CompileExportLists();
                  g_registry.RevertToPreviousModule();
                ;}
    break;

  case 10:
#line 82 "antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(2) - (2)].word));;}
    break;

  case 11:
#line 83 "antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  (yyval.module)->CompileExportLists();
                  g_registry.RevertToPreviousModule();
                ;}
    break;

  case 12:
#line 88 "antimony.ypp"
    {g_registry.SetError("line " + ToString((yylsp[(2) - (2)]).last_line) + ":  module '" + *((yyvsp[(2) - (2)].word)) + "' already defined."); YYABORT;;}
    break;

  case 13:
#line 92 "antimony.ypp"
    {;}
    break;

  case 14:
#line 93 "antimony.ypp"
    {g_registry.AddVariableToCurrentExportList((yyvsp[(1) - (1)].variable)); ;}
    break;

  case 15:
#line 94 "antimony.ypp"
    { g_registry.AddVariableToCurrentExportList((yyvsp[(3) - (3)].variable)); ;}
    break;

  case 16:
#line 97 "antimony.ypp"
    {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[(1) - (1)].word)); ;}
    break;

  case 17:
#line 98 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable)->GetSubVariable((yyvsp[(3) - (3)].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[(3) - (3)].word)) + "' is not a subvariable of '" + (yyvsp[(1) - (3)].variable)->GetNameDelimitedBy('.') + "'.");
                    YYABORT;
                  }
                ;}
    break;

  case 18:
#line 104 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (3)].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 19:
#line 109 "antimony.ypp"
    {;}
    break;

  case 20:
#line 110 "antimony.ypp"
    {;}
    break;

  case 21:
#line 113 "antimony.ypp"
    {;}
    break;

  case 22:
#line 114 "antimony.ypp"
    {;}
    break;

  case 23:
#line 115 "antimony.ypp"
    {;}
    break;

  case 24:
#line 116 "antimony.ypp"
    {;}
    break;

  case 25:
#line 117 "antimony.ypp"
    {;}
    break;

  case 26:
#line 118 "antimony.ypp"
    {;}
    break;

  case 27:
#line 121 "antimony.ypp"
    { g_registry.CurrentModule()->SetReactionVariable((yyvsp[(1) - (2)].variable)); ;}
    break;

  case 28:
#line 122 "antimony.ypp"
    {
                  (yyval.reaction) = g_registry.AddNewReactionToCurrent((yyvsp[(4) - (8)].reactantList), (yyvsp[(5) - (8)].reactionDivider), (yyvsp[(6) - (8)].reactantList), (yyvsp[(8) - (8)].formula), g_registry.CurrentModule()->GetReactionVariable());
                  if ((yyval.reaction) == NULL) YYABORT;
                ;}
    break;

  case 29:
#line 127 "antimony.ypp"
    {
                  (yyval.reaction) = g_registry.AddNewReactionToCurrent((yyvsp[(1) - (5)].reactantList), (yyvsp[(2) - (5)].reactionDivider), (yyvsp[(3) - (5)].reactantList), (yyvsp[(5) - (5)].formula));
                  if ((yyval.reaction) == NULL) YYABORT;
                ;}
    break;

  case 30:
#line 133 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); ;}
    break;

  case 31:
#line 134 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(1) - (1)].variable)); ;}
    break;

  case 32:
#line 135 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(2) - (2)].variable), (yyvsp[(1) - (2)].num)); ;}
    break;

  case 33:
#line 136 "antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (3)].reactantList); (yyvsp[(1) - (3)].reactantList)->AddReactant((yyvsp[(3) - (3)].variable)); ;}
    break;

  case 34:
#line 137 "antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (4)].reactantList); (yyvsp[(1) - (4)].reactantList)->AddReactant((yyvsp[(4) - (4)].variable), (yyvsp[(3) - (4)].num)); ;}
    break;

  case 35:
#line 141 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;;}
    break;

  case 36:
#line 142 "antimony.ypp"
    {(yyval.reactionDivider) = rdInhibits;;}
    break;

  case 37:
#line 143 "antimony.ypp"
    {(yyval.reactionDivider) = rdActivates;;}
    break;

  case 38:
#line 144 "antimony.ypp"
    {(yyval.reactionDivider) = rdInfluences;;}
    break;

  case 39:
#line 147 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); ;}
    break;

  case 40:
#line 148 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddEllipses();;}
    break;

  case 41:
#line 149 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddVariable((yyvsp[(1) - (1)].variable)); ;}
    break;

  case 42:
#line 150 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddNum((yyvsp[(1) - (1)].num)); ;}
    break;

  case 43:
#line 151 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddText((yyvsp[(1) - (1)].word));;}
    break;

  case 44:
#line 152 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddMathThing((yyvsp[(1) - (1)].character)); ;}
    break;

  case 45:
#line 153 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddVariable((yyvsp[(2) - (2)].variable)); ;}
    break;

  case 46:
#line 154 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddNum((yyvsp[(2) - (2)].num)); ;}
    break;

  case 47:
#line 155 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddText((yyvsp[(2) - (2)].word));;}
    break;

  case 48:
#line 156 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddMathThing((yyvsp[(2) - (2)].character)); ;}
    break;

  case 49:
#line 159 "antimony.ypp"
    {(yyval.character) = '+';;}
    break;

  case 50:
#line 160 "antimony.ypp"
    {(yyval.character) = '-';;}
    break;

  case 51:
#line 161 "antimony.ypp"
    {(yyval.character) = '*';;}
    break;

  case 52:
#line 162 "antimony.ypp"
    {(yyval.character) = '/';;}
    break;

  case 53:
#line 163 "antimony.ypp"
    {(yyval.character) = '(';;}
    break;

  case 54:
#line 164 "antimony.ypp"
    {(yyval.character) = ')';;}
    break;

  case 55:
#line 165 "antimony.ypp"
    {(yyval.character) = '^';;}
    break;

  case 56:
#line 166 "antimony.ypp"
    {(yyval.character) = ',';;}
    break;

  case 57:
#line 169 "antimony.ypp"
    {;}
    break;

  case 58:
#line 170 "antimony.ypp"
    {;}
    break;

  case 59:
#line 173 "antimony.ypp"
    { g_registry.SetAssignmentVariable((yyvsp[(1) - (2)].variable)); ;}
    break;

  case 60:
#line 173 "antimony.ypp"
    {if (g_registry.GetAssignmentVariable()->SetFormula((yyvsp[(4) - (4)].formula))) YYABORT; ;}
    break;

  case 61:
#line 176 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->ImportModule((yyvsp[(3) - (4)].word))) YYABORT;;}
    break;

  case 63:
#line 177 "antimony.ypp"
    {if(g_registry.CurrentModule()->ImportModule((yyvsp[(1) - (2)].word))) YYABORT;;}
    break;

  case 65:
#line 180 "antimony.ypp"
    {;}
    break;

  case 66:
#line 181 "antimony.ypp"
    {if (g_registry.AddVariableToCurrentImportList((yyvsp[(1) - (1)].variable))) YYABORT; ;}
    break;

  case 67:
#line 182 "antimony.ypp"
    { if (g_registry.AddVariableToCurrentImportList((yyvsp[(3) - (3)].variable))) YYABORT; ;}
    break;

  case 68:
#line 183 "antimony.ypp"
    {if ((yyvsp[(3) - (5)].variable)->Synchronize((yyvsp[(5) - (5)].variable))) YYABORT; ;}
    break;

  case 69:
#line 186 "antimony.ypp"
    {(yyval.variable) = g_registry.GetImportedModuleSubVariable((yyvsp[(1) - (1)].word)); ;}
    break;

  case 70:
#line 187 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable)->GetSubVariable((yyvsp[(3) - (3)].word)); ;}
    break;

  case 71:
#line 190 "antimony.ypp"
    { ;}
    break;

  case 72:
#line 191 "antimony.ypp"
    { ;}
    break;

  case 73:
#line 192 "antimony.ypp"
    { ;}
    break;

  case 74:
#line 193 "antimony.ypp"
    { ;}
    break;

  case 75:
#line 194 "antimony.ypp"
    { ;}
    break;

  case 76:
#line 195 "antimony.ypp"
    { ;}
    break;

  case 77:
#line 196 "antimony.ypp"
    { ;}
    break;

  case 78:
#line 197 "antimony.ypp"
    { ;}
    break;

  case 79:
#line 198 "antimony.ypp"
    { ;}
    break;

  case 80:
#line 199 "antimony.ypp"
    { ;}
    break;

  case 81:
#line 200 "antimony.ypp"
    { ;}
    break;

  case 82:
#line 203 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 83:
#line 204 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 84:
#line 205 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 85:
#line 208 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varSpeciesProtein)) YYABORT; ;}
    break;

  case 86:
#line 209 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesProtein)) YYABORT; ;}
    break;

  case 87:
#line 210 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesProtein)) YYABORT; ;}
    break;

  case 88:
#line 213 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 89:
#line 214 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 90:
#line 215 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 91:
#line 218 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 92:
#line 219 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 93:
#line 220 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 94:
#line 223 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaPromoter)) YYABORT; ;}
    break;

  case 95:
#line 224 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaPromoter)) YYABORT; ;}
    break;

  case 96:
#line 225 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaPromoter)) YYABORT; ;}
    break;

  case 97:
#line 228 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 98:
#line 229 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 99:
#line 230 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 100:
#line 233 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesProtein)) YYABORT;
                                        if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 101:
#line 235 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesProtein)) YYABORT; 
                                            if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 102:
#line 239 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; 
                                     if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 103:
#line 241 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; 
                                            if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 104:
#line 246 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaPromoter)) YYABORT; 
                                         if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 105:
#line 248 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaPromoter)) YYABORT; 
                                                if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 106:
#line 253 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; 
                                         if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 107:
#line 255 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; 
                                                if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 108:
#line 259 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 109:
#line 260 "antimony.ypp"
    {if ((yyvsp[(3) - (3)].variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 110:
#line 263 "antimony.ypp"
    {if (g_registry.SetNewUpstreamOpen((yyvsp[(2) - (2)].variable))) YYABORT;;}
    break;

  case 111:
#line 264 "antimony.ypp"
    {g_registry.GetWorkingStrand()->SetOpenUpstream(); ;}
    break;

  case 112:
#line 265 "antimony.ypp"
    {if (g_registry.SetDownstreamEnd((yyvsp[(2) - (2)].variable))) YYABORT;;}
    break;

  case 113:
#line 266 "antimony.ypp"
    {g_registry.GetWorkingStrand()->SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[(3) - (3)].variable))) YYABORT;;}
    break;

  case 114:
#line 267 "antimony.ypp"
    { ;}
    break;

  case 115:
#line 270 "antimony.ypp"
    {g_registry.SetNewDownstreamOpen((yyvsp[(1) - (2)].variable));;}
    break;

  case 116:
#line 271 "antimony.ypp"
    {g_registry.SetDownstreamOpen((yyvsp[(2) - (3)].variable));;}
    break;


/* Line 1267 of yacc.c.  */
#line 2215 "antimony.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


#line 274 "antimony.ypp"



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
      int firstl  = yylloc_first_line;
      int lastl  = yylloc_last_line;
      return yylex();
      yylloc_first_line  = firstl;
      yylloc_last_line  = lastl;
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
    if (CaselessStrCmp(word, "protein")) {
      return PROTEIN;
    }
    if (CaselessStrCmp(word, "DNA")) {
      return DNA;
    }
    if (CaselessStrCmp(word, "gene")) {
      return GENE;
    }
    if (CaselessStrCmp(word, "promoter")) {
      return PROMOTER;
    }
    if (CaselessStrCmp(word, "operator")) {
      return OPERATOR;
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
    if (CaselessStrCmp(word, "include")) {
      return INCLUDE;
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

int main(long argc, char** argv)
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
      cout << argv[file] << " read successfully with file handle " << ToString(retval) << "." << endl;
    }
  }
  for (size_t file=0; file<getNumFiles(); file++) {
    revertTo(file+1);
    size_t nummods = getNumModules();
    char** modnames = getModuleNames();
    for (size_t mod=0; mod<nummods; mod++) {
      cout << "Information for file " << ToString(file+1) <<", module '" << modnames[mod] << "'" << endl;
      cout << "***ToString (" << modnames[mod] << ") ***" << endl;
      cout << g_registry.GetModule(modnames[mod])->ToString().c_str() << endl << endl;
      cout << "***Jarnac (" << modnames[mod] << ") ***" << endl;
      cout << getJarnac(modnames[mod]) << endl;
      cout << endl << "***printAllDataFor (" << modnames[mod] << ") (from the API):***" << endl;
      printAllDataFor(modnames[mod]);
      cout << endl;
      cout << endl;
    }
    freeAll();
  }
  if (retval == -1) return 1;
  return 0;
}


