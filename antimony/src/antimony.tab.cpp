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
#include "stringx.h"

  class Formula;
  class ReactantList;
  class AntimonyReaction;
  class Variable;

  using namespace std;
  int yylex(void);
  void yyerror(char const *);
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
     CONSTANT = 282,
     IMPORT = 283,
     AT = 284,
     AFTER = 285,
     FUNCTIONWORD = 286,
     UNITWORD = 287
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
  Variable* unitdef;
  bool maybemain;



/* Line 214 of yacc.c  */
#line 192 "antimony.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 204 "antimony.tab.cpp"

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
#define YYLAST   750

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  174
/* YYNRULES -- Number of states.  */
#define YYNSTATES  306

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      54,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,    45,    10,     4,    55,
      41,    42,     8,     7,    43,     6,    44,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    48,
      50,    46,    49,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    11,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     5,    53,     2,     2,     2,     2,
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
      33,    34,    35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    19,    22,
      23,    33,    34,    41,    44,    47,    48,    50,    51,    60,
      63,    66,    70,    71,    73,    74,    76,    80,    82,    86,
      89,    93,    95,    97,    99,   103,   107,   108,   111,   113,
     116,   119,   122,   125,   128,   131,   134,   137,   139,   141,
     150,   157,   158,   160,   163,   167,   172,   175,   178,   181,
     184,   186,   189,   190,   193,   196,   199,   202,   205,   210,
     213,   217,   221,   225,   229,   233,   237,   242,   244,   248,
     250,   252,   254,   256,   258,   260,   262,   264,   266,   268,
     272,   276,   282,   288,   292,   297,   302,   306,   307,   317,
     318,   326,   327,   329,   333,   334,   340,   346,   348,   350,
     352,   354,   356,   358,   360,   362,   365,   369,   373,   377,
     380,   384,   388,   392,   395,   399,   402,   406,   409,   413,
     417,   421,   424,   428,   432,   436,   439,   443,   447,   451,
     454,   458,   462,   466,   469,   472,   476,   481,   484,   486,
     490,   493,   496,   499,   503,   505,   508,   512,   513,   520,
     521,   530,   531,   540,   541,   552,   554,   557,   558,   564,
     568,   574,   581,   587,   594
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    -1,    57,    58,    -1,    57,    59,    -1,
      57,    74,    -1,    57,    63,    -1,    57,     1,    -1,    36,
      15,    -1,    -1,    16,    62,    13,    60,    41,    67,    42,
      73,    17,    -1,    -1,    16,    62,    13,    61,    73,    17,
      -1,    16,    14,    -1,    16,    34,    -1,    -1,     8,    -1,
      -1,    39,    13,    64,    41,    67,    42,    65,    17,    -1,
      39,    14,    -1,    39,    34,    -1,    66,    78,    66,    -1,
      -1,    81,    -1,    -1,    68,    -1,    67,    43,    68,    -1,
      13,    -1,    68,    44,    13,    -1,    45,    68,    -1,    68,
      26,    68,    -1,    68,    -1,    69,    -1,    70,    -1,    70,
      46,    78,    -1,    70,    27,   109,    -1,    -1,    26,    68,
      -1,    74,    -1,    73,    74,    -1,    75,    81,    -1,    82,
      81,    -1,    83,    81,    -1,    88,    81,    -1,    98,    81,
      -1,   101,    81,    -1,    97,    81,    -1,    69,    -1,    81,
      -1,    70,    47,    76,    77,    76,    48,    78,    72,    -1,
      76,    77,    76,    48,    78,    72,    -1,    -1,    68,    -1,
      12,    68,    -1,    76,     7,    68,    -1,    76,     7,    12,
      68,    -1,     6,    49,    -1,     6,     5,    -1,     6,    41,
      -1,     6,    13,    -1,    32,    -1,    50,    32,    -1,    -1,
      78,    33,    -1,    78,    68,    -1,    78,    12,    -1,    78,
      35,    -1,    78,    34,    -1,    78,    41,    79,    42,    -1,
      78,    80,    -1,    78,    50,    46,    -1,    78,    49,    46,
      -1,    78,    46,    46,    -1,    78,    51,    46,    -1,    78,
       4,     4,    -1,    78,     5,     5,    -1,    78,    52,   109,
      53,    -1,    78,    -1,    79,    43,    78,    -1,     7,    -1,
       6,    -1,     8,    -1,     9,    -1,    11,    -1,    49,    -1,
      50,    -1,    51,    -1,    48,    -1,    54,    -1,    70,    46,
      78,    -1,    70,    28,    68,    -1,    70,    28,    68,     9,
      68,    -1,    70,     8,    68,    28,    68,    -1,    70,    28,
      15,    -1,    70,    47,    46,    78,    -1,    70,    55,    46,
      78,    -1,    70,    27,   109,    -1,    -1,    70,    47,    14,
      41,    84,    86,    42,    87,    72,    -1,    -1,    14,    41,
      85,    86,    42,    87,    72,    -1,    -1,    68,    -1,    86,
      43,    68,    -1,    -1,    87,    43,    13,    46,    68,    -1,
      87,    43,    13,    46,    12,    -1,    89,    -1,    90,    -1,
      91,    -1,    92,    -1,    93,    -1,    94,    -1,    95,    -1,
      96,    -1,    18,    71,    -1,    29,    18,    71,    -1,    30,
      18,    71,    -1,    89,    43,    71,    -1,    20,    71,    -1,
      29,    20,    71,    -1,    30,    20,    71,    -1,    90,    43,
      71,    -1,    19,    71,    -1,    29,    19,    71,    -1,    30,
      19,    -1,    91,    43,    71,    -1,    21,    71,    -1,    29,
      21,    71,    -1,    30,    21,    71,    -1,    92,    43,    71,
      -1,    22,    71,    -1,    29,    22,    71,    -1,    30,    22,
      71,    -1,    93,    43,    71,    -1,    23,    71,    -1,    29,
      23,    71,    -1,    30,    23,    71,    -1,    94,    43,    71,
      -1,    25,    71,    -1,    29,    25,    71,    -1,    30,    25,
      71,    -1,    95,    43,    71,    -1,    29,    71,    -1,    30,
      71,    -1,    96,    43,    71,    -1,    40,    68,    46,    78,
      -1,    40,    68,    -1,    99,    -1,    70,    47,    99,    -1,
      31,    68,    -1,    31,   100,    -1,   100,    68,    -1,    31,
     100,    68,    -1,   100,    -1,    68,    31,    -1,   100,    68,
      31,    -1,    -1,    37,    78,   102,   107,   106,   108,    -1,
      -1,    37,    78,    38,    78,   103,   107,   106,   108,    -1,
      -1,    70,    47,    37,    78,   104,   107,   106,   108,    -1,
      -1,    70,    47,    37,    78,    38,    78,   105,   107,   106,
     108,    -1,    47,    -1,   106,    54,    -1,    -1,   107,    43,
      13,    46,    78,    -1,    68,    46,    78,    -1,    68,    46,
      78,    47,   108,    -1,    68,    46,    78,    47,    54,   108,
      -1,    68,    46,    78,    43,   108,    -1,    68,    46,    78,
      43,    54,   108,    -1,    78,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   108,   109,   110,   111,   112,   115,   118,
     118,   124,   124,   130,   131,   134,   135,   138,   138,   139,
     140,   143,   146,   147,   151,   152,   153,   156,   157,   163,
     166,   169,   170,   173,   174,   175,   178,   179,   182,   183,
     186,   187,   188,   189,   190,   191,   192,   194,   195,   198,
     206,   216,   217,   218,   219,   220,   224,   225,   226,   227,
     228,   229,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   254,   255,   258,
     259,   260,   261,   262,   263,   264,   265,   268,   269,   272,
     273,   274,   275,   276,   277,   278,   279,   282,   282,   283,
     283,   287,   288,   289,   293,   294,   298,   302,   303,   304,
     305,   306,   307,   309,   310,   313,   314,   315,   316,   319,
     320,   321,   322,   325,   326,   327,   328,   331,   332,   333,
     334,   337,   338,   339,   340,   343,   344,   345,   346,   350,
     351,   352,   353,   356,   357,   358,   361,   362,   365,   366,
     369,   370,   371,   372,   373,   376,   377,   380,   380,   381,
     381,   382,   382,   383,   383,   386,   387,   390,   391,   398,
     399,   400,   401,   402,   410
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"mathematical symbol\"",
  "'&'", "'|'", "'-'", "'+'", "'*'", "'/'", "'%'", "'^'", "\"number\"",
  "\"element name\"", "\"name of an existing module\"", "\"text string\"",
  "\"'model' or 'module'\"", "\"'end'\"", "\"'species'\"",
  "\"'reaction'\"", "\"'formula'\"", "\"'DNA'\"", "\"'gene'\"",
  "\"'operator'\"", "\"'event'\"", "\"'compartment'\"", "\"'in'\"",
  "\"'has'\"", "\"'is'\"", "\"'var'\"", "\"'const'\"", "\"--\"", "\"=>\"",
  "\"...\"", "\"name of an existing function\"",
  "\"name of a pre-defined constant\"", "\"'import'\"", "\"'@' or 'at'\"",
  "\"'after'\"", "\"'function'\"", "\"'unit'\"", "'('", "')'", "','",
  "'.'", "'$'", "'='", "':'", "';'", "'>'", "'<'", "'!'", "'{'", "'}'",
  "'\\n'", "'\\''", "$accept", "input", "import", "module", "$@1", "$@2",
  "maybemain", "function", "$@3", "spacedformula", "maybelineend",
  "variableexportlist", "variable", "variablein", "varmaybein",
  "varmaybeis", "maybein", "modulebody", "modulepart", "reaction",
  "reactantList", "reactionDivider", "formula", "commaformula",
  "mathThing", "lineend", "assignment", "submodule", "$@4", "$@5",
  "variableimportlist", "submodifications", "varinitialize", "specinit",
  "formulainit", "reactioninit", "dnainit", "geneinit", "operatorinit",
  "compartmentinit", "varconstinit", "unitinit", "dnadef", "dnastrand",
  "dnamiddle", "event", "$@6", "$@7", "$@8", "$@9", "colonret",
  "eventmodifications", "assignmentlist", "unitdef", 0
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
     287,    40,    41,    44,    46,    36,    61,    58,    59,    62,
      60,    33,   123,   125,    10,    39
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    57,    57,    57,    57,    58,    60,
      59,    61,    59,    59,    59,    62,    62,    64,    63,    63,
      63,    65,    66,    66,    67,    67,    67,    68,    68,    68,
      69,    70,    70,    71,    71,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    76,    76,    76,    76,    76,    77,    77,    77,    77,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    84,    83,    85,
      83,    86,    86,    86,    87,    87,    87,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    89,    89,    89,    90,
      90,    90,    90,    91,    91,    91,    91,    92,    92,    92,
      92,    93,    93,    93,    93,    94,    94,    94,    94,    95,
      95,    95,    95,    96,    96,    96,    97,    97,    98,    98,
      99,    99,    99,    99,    99,   100,   100,   102,   101,   103,
     101,   104,   101,   105,   101,   106,   106,   107,   107,   108,
     108,   108,   108,   108,   109
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     0,
       9,     0,     6,     2,     2,     0,     1,     0,     8,     2,
       2,     3,     0,     1,     0,     1,     3,     1,     3,     2,
       3,     1,     1,     1,     3,     3,     0,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     8,
       6,     0,     1,     2,     3,     4,     2,     2,     2,     2,
       1,     2,     0,     2,     2,     2,     2,     2,     4,     2,
       3,     3,     3,     3,     3,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     5,     5,     3,     4,     4,     3,     0,     9,     0,
       7,     0,     1,     3,     0,     5,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     3,     2,
       3,     3,     3,     2,     3,     2,     3,     2,     3,     3,
       3,     2,     3,     3,     3,     2,     3,     3,     3,     2,
       3,     3,     3,     2,     2,     3,     4,     2,     1,     3,
       2,     2,     2,     3,     1,     2,     3,     0,     6,     0,
       8,     0,     8,     0,    10,     1,     2,     0,     5,     3,
       5,     6,     5,     6,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     7,     0,    27,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,    87,    88,     3,     4,     6,    31,    47,
       0,     5,     0,     0,    48,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,   114,     0,     0,   148,   154,
       0,    53,    99,    16,    13,    14,     0,    31,    32,    33,
     115,   123,   119,   127,   131,   135,   139,     0,     0,     0,
       0,     0,     0,     0,   143,     0,   125,     0,     0,     0,
       0,     0,   144,   150,   151,     8,   157,    17,    19,    20,
     147,    29,     0,   155,     0,     0,    62,     0,    62,    51,
       0,    40,     0,     0,    60,     0,    51,    41,    42,    43,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    44,
     152,    45,   101,    11,    62,    62,   116,   124,   120,   128,
     132,   136,   140,   117,   121,   129,   133,   137,   141,   153,
       0,     0,    80,    79,    81,    82,    83,    65,    63,    67,
      66,    62,    62,     0,    84,    85,    86,    62,    64,    69,
     167,     0,    62,    30,    28,     0,   174,    96,    93,    90,
      89,     0,    62,    62,    52,     0,   149,    62,    57,    59,
      58,    56,     0,    54,    61,    52,     0,   118,   122,   126,
     130,   134,   138,   142,   145,   156,   102,     0,     0,    51,
      35,    34,    74,    75,   159,    77,     0,    72,    71,    70,
      73,     0,     0,    24,   146,     0,     0,    97,   161,    94,
      51,    95,    55,    62,   104,     0,    24,    51,    38,   167,
      68,    62,    76,     0,   165,     0,     0,    25,    92,    91,
     101,    62,   167,     0,    36,    36,   103,     0,    12,    39,
       0,    78,     0,   166,     0,   158,    22,     0,     0,   163,
       0,    62,     0,    50,     0,   100,    51,     0,    62,    62,
       0,    62,    23,    26,   104,   167,     0,    36,    37,     0,
      51,   160,   168,   169,    18,    22,    36,     0,   162,    49,
       0,    10,     0,     0,    21,    98,     0,   106,   105,     0,
     172,     0,   170,   164,   173,   171
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,    26,   198,   199,    56,    27,   161,   270,
     271,   236,    57,    58,    59,    60,   263,   227,   228,    32,
      33,   106,   166,   206,   159,    34,    35,    36,   240,   122,
     197,   245,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,   160,   229,   242,   275,
     235,   212,   255,   167
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -238
static const yytype_int16 yypact[] =
{
    -238,   321,  -238,  -238,    61,  -238,   -26,    19,    61,    61,
      61,    61,    61,    61,    61,   360,   430,    61,    15,  -238,
     165,    61,    61,  -238,  -238,  -238,  -238,  -238,     5,    -3,
      18,  -238,   129,    34,  -238,   129,   129,   129,    36,    39,
      46,    97,   100,   113,   123,   130,   129,   129,  -238,    61,
     129,    53,  -238,  -238,  -238,  -238,    77,    49,  -238,    54,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,    61,    61,    61,
      61,    61,    61,    61,  -238,    61,  -238,    61,    61,    61,
      61,    61,  -238,    57,    61,  -238,   433,  -238,  -238,  -238,
     -36,    53,    61,  -238,   172,    61,  -238,   126,  -238,   209,
     142,  -238,    29,    64,  -238,   169,    99,  -238,  -238,  -238,
      61,    61,    61,    61,    61,    61,    61,    61,  -238,  -238,
     111,  -238,    61,   156,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,   111,
     212,   226,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,   189,   190,   191,   195,  -238,    53,  -238,
    -238,   201,  -238,    53,  -238,    59,   580,  -238,  -238,    63,
     580,   203,  -238,  -238,    57,    34,  -238,  -238,  -238,  -238,
    -238,  -238,    61,    53,  -238,    53,    44,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,    53,    89,   204,   696,
    -238,   580,  -238,  -238,   580,   580,   164,  -238,  -238,  -238,
    -238,   179,   137,    61,   580,    61,    61,  -238,   482,   580,
      99,   580,    53,  -238,  -238,    61,    61,   621,  -238,  -238,
    -238,  -238,  -238,   234,  -238,    -7,   166,    53,    53,    53,
      61,  -238,  -238,    62,   531,   125,    53,   168,  -238,  -238,
     137,   580,   202,  -238,   150,  -238,   129,    61,   186,   580,
     137,  -238,    61,  -238,   236,  -238,   696,    -7,  -238,  -238,
     235,  -238,  -238,    53,  -238,  -238,    -7,   531,    53,   207,
     659,  -238,   580,   384,  -238,   141,   125,   137,  -238,  -238,
     122,  -238,    26,    41,  -238,  -238,    -7,  -238,    53,    61,
    -238,    61,  -238,  -238,  -238,  -238
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
     -28,    33,    -1,     3,     6,    47,  -178,    -6,     0,  -238,
     -97,    87,   153,  -238,  -238,   -18,  -238,  -238,  -238,  -238,
      23,   -10,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,   171,   251,  -238,  -238,  -238,  -238,  -238,
    -237,  -207,  -163,    13
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -53
static const yytype_int16 yytable[] =
{
      28,    31,   175,    51,    29,   -32,     5,    30,    94,   186,
     162,   -52,   -52,   267,   101,    52,    83,   107,   108,   109,
      90,    91,   250,   276,   -32,   -32,    95,    53,   118,   119,
      85,    92,   121,    54,   178,   260,    93,   -52,    22,     5,
     102,   103,   179,   -32,   -32,    96,    97,   253,   120,    94,
     296,   103,   -32,    55,     5,   -52,    61,    62,    63,    64,
      65,    66,    74,    82,    98,    99,   104,   265,   287,   103,
     180,    22,   216,   100,     5,    92,   182,     5,   181,   110,
     299,   124,   111,   139,   105,   158,    22,   215,    93,   112,
     123,   163,   223,    94,   165,   301,   169,    94,   174,   289,
     125,    94,   183,    94,   281,   185,    22,    94,   295,    22,
     261,     4,     5,   288,   126,   127,   128,   129,   130,   131,
     132,   196,   133,   243,   134,   135,   136,   137,   138,   300,
     302,   224,   225,   303,   297,     5,   304,   200,   305,     5,
     113,   168,   195,   114,    22,   140,   141,   142,   143,   144,
     145,   262,   146,   147,     5,    94,   115,   187,   188,   189,
     190,   191,   192,   193,   194,   158,   116,    22,   264,   158,
     211,    22,    86,   117,   148,   149,   150,    23,    87,    88,
     233,   222,   152,    24,   234,   164,    22,   153,   177,    23,
     154,   155,   156,   157,    94,    24,   269,    -9,    28,    89,
     158,   184,    29,   158,   158,    30,   230,   231,   256,   257,
     266,   257,   237,   158,   238,   239,   202,   158,   158,   185,
     158,     4,     5,   171,   246,   237,    28,   249,   274,   225,
      29,   203,   232,    30,   254,   207,   208,   209,   272,   196,
      17,   210,   213,   158,   217,   226,   172,   252,   268,   279,
     158,   170,   284,   290,    22,   173,   273,   294,   158,   247,
     280,   278,   220,   258,   286,    28,   254,   272,    84,    29,
     176,     0,    30,     0,     0,   254,   158,     0,   201,    28,
     249,   158,   158,    29,   158,     0,    30,     0,     0,   298,
       0,   254,   254,     0,     0,   254,     0,     0,   254,     0,
     254,     0,     0,     0,   204,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   214,     0,     0,     0,     0,
       0,     2,     3,     0,     0,   218,   219,   -51,   -51,     0,
     221,     0,     0,     4,     5,     6,     0,     7,     0,     8,
       9,    10,    11,    12,    13,     0,    14,     0,     0,     0,
      15,    16,    17,   -51,     0,     0,     0,    18,    19,     0,
      20,    21,     0,     0,     0,     0,    22,     0,     0,    23,
       0,   -51,     0,     5,     0,    24,   244,     0,    67,    68,
      69,    70,    71,    72,   251,    73,     0,     0,   140,   141,
     142,   143,   144,   145,   259,   146,   147,     5,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,   277,     0,     0,   148,   149,   150,
       0,   282,   283,     0,   285,   152,     0,   292,     0,    22,
     153,   293,     0,   154,   155,   156,   157,   140,   141,   142,
     143,   144,   145,     5,   146,   147,     5,     0,    75,    76,
      77,    78,    79,    80,     0,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,   150,     0,
       0,   151,     0,     0,   152,    22,     0,     0,    22,   153,
       0,     0,   154,   155,   156,   157,   140,   141,   142,   143,
     144,   145,     0,   146,   147,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   149,   150,     0,     0,
     241,     0,     0,   152,     0,     0,     0,    22,   153,     0,
       0,   154,   155,   156,   157,   140,   141,   142,   143,   144,
     145,     0,   146,   147,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,     0,
       0,     0,     0,     0,   148,   149,   150,     0,     0,     0,
       0,     0,   152,     0,     0,     0,    22,   153,     0,     0,
     154,   155,   156,   157,   140,   141,   142,   143,   144,   145,
       0,   146,   147,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,   149,   150,     0,     0,     0,     0,
       0,   152,     0,     0,     0,    22,   153,     0,     0,   154,
     155,   156,   157,     4,     5,     6,     0,     0,   248,     8,
       9,    10,    11,    12,    13,     0,    14,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,    19,     0,
       0,    21,     0,     0,     0,     0,    22,     0,     0,    23,
       0,     4,     5,     6,     0,    24,   291,     8,     9,    10,
      11,    12,    13,     0,    14,     0,     0,     0,    15,    16,
      17,     0,     0,     0,     0,     0,    19,     0,     0,    21,
       0,     0,     0,     0,    22,     0,     0,    23,     4,     5,
       6,     0,     0,    24,     8,     9,    10,    11,    12,    13,
       0,    14,     0,     0,     0,    15,    16,    17,     0,     0,
       0,     0,     0,    19,     0,     0,    21,     0,     0,     0,
       0,    22,     0,     0,    23,     0,     0,     0,     0,     0,
      24
};

static const yytype_int16 yycheck[] =
{
       1,     1,    99,     4,     1,     8,    13,     1,    44,   106,
      46,     6,     7,   250,    32,    41,    17,    35,    36,    37,
      21,    22,   229,   260,    27,    28,     8,     8,    46,    47,
      15,    26,    50,    14,     5,   242,    31,    32,    45,    13,
       6,     7,    13,    46,    47,    27,    28,    54,    49,    44,
     287,     7,    55,    34,    13,    50,     9,    10,    11,    12,
      13,    14,    15,    16,    46,    47,    32,   245,   275,     7,
      41,    45,     9,    55,    13,    26,    12,    13,    49,    43,
      54,    27,    43,    84,    50,    86,    45,    28,    31,    43,
      13,    92,    48,    44,    95,    54,    97,    44,    99,   277,
      46,    44,   103,    44,   267,   106,    45,    44,   286,    45,
      48,    12,    13,   276,    67,    68,    69,    70,    71,    72,
      73,   122,    75,   220,    77,    78,    79,    80,    81,   292,
     293,    42,    43,   296,    12,    13,   299,   124,   301,    13,
      43,    15,    31,    43,    45,     4,     5,     6,     7,     8,
       9,    26,    11,    12,    13,    44,    43,   110,   111,   112,
     113,   114,   115,   116,   117,   166,    43,    45,    43,   170,
     157,    45,    19,    43,    33,    34,    35,    48,    13,    14,
      43,   182,    41,    54,    47,    13,    45,    46,    46,    48,
      49,    50,    51,    52,    44,    54,    46,    41,   199,    34,
     201,    32,   199,   204,   205,   199,    42,    43,    42,    43,
      42,    43,   213,   214,   215,   216,     4,   218,   219,   220,
     221,    12,    13,    14,   225,   226,   227,   227,    42,    43,
     227,     5,    53,   227,   235,    46,    46,    46,   256,   240,
      31,    46,    41,   244,    41,    41,    37,    13,    46,    13,
     251,    98,    17,    46,    45,    46,   257,   285,   259,   226,
     266,   262,   175,   240,   274,   266,   267,   285,    17,   266,
      99,    -1,   266,    -1,    -1,   276,   277,    -1,   125,   280,
     280,   282,   283,   280,   285,    -1,   280,    -1,    -1,   290,
      -1,   292,   293,    -1,    -1,   296,    -1,    -1,   299,    -1,
     301,    -1,    -1,    -1,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,    -1,   172,   173,     6,     7,    -1,
     177,    -1,    -1,    12,    13,    14,    -1,    16,    -1,    18,
      19,    20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    36,    37,    -1,
      39,    40,    -1,    -1,    -1,    -1,    45,    -1,    -1,    48,
      -1,    50,    -1,    13,    -1,    54,   223,    -1,    18,    19,
      20,    21,    22,    23,   231,    25,    -1,    -1,     4,     5,
       6,     7,     8,     9,   241,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    33,    34,    35,
      -1,   268,   269,    -1,   271,    41,    -1,    43,    -1,    45,
      46,    47,    -1,    49,    50,    51,    52,     4,     5,     6,
       7,     8,     9,    13,    11,    12,    13,    -1,    18,    19,
      20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,
      -1,    38,    -1,    -1,    41,    45,    -1,    -1,    45,    46,
      -1,    -1,    49,    50,    51,    52,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,
      38,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,
      -1,    49,    50,    51,    52,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      49,    50,    51,    52,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,    49,
      50,    51,    52,    12,    13,    14,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    -1,    -1,    -1,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    45,    -1,    -1,    48,
      -1,    12,    13,    14,    -1,    54,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    -1,    -1,    -1,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    48,    12,    13,
      14,    -1,    -1,    54,    18,    19,    20,    21,    22,    23,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    57,     0,     1,    12,    13,    14,    16,    18,    19,
      20,    21,    22,    23,    25,    29,    30,    31,    36,    37,
      39,    40,    45,    48,    54,    58,    59,    63,    68,    69,
      70,    74,    75,    76,    81,    82,    83,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    68,    41,     8,    14,    34,    62,    68,    69,    70,
      71,    71,    71,    71,    71,    71,    71,    18,    19,    20,
      21,    22,    23,    25,    71,    18,    19,    20,    21,    22,
      23,    25,    71,    68,   100,    15,    78,    13,    14,    34,
      68,    68,    26,    31,    44,     8,    27,    28,    46,    47,
      55,    81,     6,     7,    32,    50,    77,    81,    81,    81,
      43,    43,    43,    43,    43,    43,    43,    43,    81,    81,
      68,    81,    85,    13,    27,    46,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    68,
       4,     5,     6,     7,     8,     9,    11,    12,    33,    34,
      35,    38,    41,    46,    49,    50,    51,    52,    68,    80,
     102,    64,    46,    68,    13,    68,    78,   109,    15,    68,
      78,    14,    37,    46,    68,    76,    99,    46,     5,    13,
      41,    49,    12,    68,    32,    68,    76,    71,    71,    71,
      71,    71,    71,    71,    71,    31,    68,    86,    60,    61,
     109,    78,     4,     5,    78,    78,    79,    46,    46,    46,
      46,   109,   107,    41,    78,    28,     9,    41,    78,    78,
      77,    78,    68,    48,    42,    43,    41,    73,    74,   103,
      42,    43,    53,    43,    47,   106,    67,    68,    68,    68,
      84,    38,   104,    76,    78,    87,    68,    67,    17,    74,
     107,    78,    13,    54,    68,   108,    42,    43,    86,    78,
     107,    48,    26,    72,    43,    72,    42,   106,    46,    46,
      65,    66,    81,    68,    42,   105,   106,    78,    68,    13,
      73,   108,    78,    78,    17,    78,    87,   107,   108,    72,
      46,    17,    43,    47,    66,    72,   106,    12,    68,    54,
     108,    54,   108,   108,   108,   108
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
#line 108 "antimony.ypp"
    {;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 109 "antimony.ypp"
    { /*cout << endl << $2->ToString() << endl << endl;*/ ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 110 "antimony.ypp"
    {;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 111 "antimony.ypp"
    {;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 112 "antimony.ypp"
    {YYABORT;;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 115 "antimony.ypp"
    { if (g_registry.OpenFile(*((yyvsp[(2) - (2)].word)))==0) YYABORT;;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 118 "antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(3) - (3)].word), (yyvsp[(2) - (3)].maybemain));;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 119 "antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 124 "antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(3) - (3)].word), (yyvsp[(2) - (3)].maybemain));;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 125 "antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 130 "antimony.ypp"
    {g_registry.SetError("module '" + *((yyvsp[(2) - (2)].word)) + "' already defined."); YYABORT;;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 131 "antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a module because it is already a defined function."); YYABORT;;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 134 "antimony.ypp"
    {(yyval.maybemain) = false;;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 135 "antimony.ypp"
    {(yyval.maybemain) = true;;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 138 "antimony.ypp"
    {g_registry.NewUserFunction((yyvsp[(2) - (2)].word));;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 138 "antimony.ypp"
    {if (g_registry.SetUserFunction((yyvsp[(7) - (8)].formula))) YYABORT;;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 139 "antimony.ypp"
    {g_registry.SetError("Cannot use '" + *((yyvsp[(2) - (2)].word)) +"' as a function name because it is already the name of a module."); YYABORT;;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 140 "antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a new function because it is already a defined function."); YYABORT;;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 143 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(2) - (3)].formula);;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 147 "antimony.ypp"
    {;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 151 "antimony.ypp"
    {;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 152 "antimony.ypp"
    {if (g_registry.AddVariableToCurrentExportList((yyvsp[(1) - (1)].variable))) YYABORT; ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 153 "antimony.ypp"
    { if (g_registry.AddVariableToCurrentExportList((yyvsp[(3) - (3)].variable))) YYABORT; ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 156 "antimony.ypp"
    {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[(1) - (1)].word)); ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 157 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable)->GetSubVariable((yyvsp[(3) - (3)].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[(3) - (3)].word)) + "' is not a subvariable of '" + (yyvsp[(1) - (3)].variable)->GetNameDelimitedBy('.') + "'.");
                    YYABORT;
                  }
                ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 163 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 166 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetCompartment((yyvsp[(3) - (3)].variable))) YYABORT; (yyval.variable) = (yyvsp[(1) - (3)].variable);;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 169 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 170 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 173 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 174 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable); if ((yyvsp[(1) - (3)].variable)->SetFormula((yyvsp[(3) - (3)].formula))) YYABORT; ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 175 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable); if ((yyvsp[(1) - (3)].variable)->SetUnit((yyvsp[(3) - (3)].variable))) YYABORT; ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 178 "antimony.ypp"
    {(yyval.variable) = NULL;;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 179 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable);;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 182 "antimony.ypp"
    {;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 183 "antimony.ypp"
    {;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 186 "antimony.ypp"
    {;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 187 "antimony.ypp"
    {;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 188 "antimony.ypp"
    {;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 189 "antimony.ypp"
    {;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 190 "antimony.ypp"
    {;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 191 "antimony.ypp"
    {;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 192 "antimony.ypp"
    {;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 194 "antimony.ypp"
    {;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 195 "antimony.ypp"
    {;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 199 "antimony.ypp"
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
#line 207 "antimony.ypp"
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
#line 216 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 217 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(1) - (1)].variable)); ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 218 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(2) - (2)].variable), (yyvsp[(1) - (2)].num)); ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 219 "antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (3)].reactantList); (yyvsp[(1) - (3)].reactantList)->AddReactant((yyvsp[(3) - (3)].variable)); ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 220 "antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (4)].reactantList); (yyvsp[(1) - (4)].reactantList)->AddReactant((yyvsp[(4) - (4)].variable), (yyvsp[(3) - (4)].num)); ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 224 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 225 "antimony.ypp"
    {(yyval.reactionDivider) = rdInhibits;;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 226 "antimony.ypp"
    {(yyval.reactionDivider) = rdInfluences;;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 227 "antimony.ypp"
    {if (*(yyvsp[(2) - (2)].word) != "o") {g_registry.SetError("'-" + *(yyvsp[(2) - (2)].word) + "' is not a valid set of characters to demark reactions.  Try '->' for reactions, and '-|', '-o', and '-(' for interactions."); YYABORT;} (yyval.reactionDivider) = rdActivates;;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 228 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomesIrreversibly;;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 229 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 232 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 233 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddEllipses();;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 234 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddVariable((yyvsp[(2) - (2)].variable)); ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 235 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddNum((yyvsp[(2) - (2)].num)); ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 236 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddText((yyvsp[(2) - (2)].word)); ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 237 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddText((yyvsp[(2) - (2)].word)); ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 238 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (4)].formula); (yyvsp[(3) - (4)].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[(3) - (4)].formula)); ;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 239 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddMathThing((yyvsp[(2) - (2)].character)); ;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 240 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('<'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 241 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('>'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 242 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('='); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 243 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('!'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 244 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 245 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 247 "antimony.ypp"
    {
                  //Need to create a variable to be this unit definition, or find one that already has this unit definition, and then use that name.
                  (yyval.formula) = (yyvsp[(1) - (4)].formula);
                  (yyval.formula)->AddVariable((yyvsp[(3) - (4)].variable));
                ;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 254 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (1)].formula);;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 255 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[(3) - (3)].formula)); ;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 258 "antimony.ypp"
    {(yyval.character) = '+';;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 259 "antimony.ypp"
    {(yyval.character) = '-';;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 260 "antimony.ypp"
    {(yyval.character) = '*';;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 261 "antimony.ypp"
    {(yyval.character) = '/';;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 262 "antimony.ypp"
    {(yyval.character) = '^';;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 263 "antimony.ypp"
    {(yyval.character) = '>';;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 264 "antimony.ypp"
    {(yyval.character) = '<';;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 265 "antimony.ypp"
    {(yyval.character) = '!';;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 268 "antimony.ypp"
    {;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 269 "antimony.ypp"
    {;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 272 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetFormula((yyvsp[(3) - (3)].formula))) YYABORT; ;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 273 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->Synchronize((yyvsp[(3) - (3)].variable), NULL)) YYABORT;;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 274 "antimony.ypp"
    {if ((yyvsp[(1) - (5)].variable)->Synchronize((yyvsp[(3) - (5)].variable), (yyvsp[(5) - (5)].variable))) YYABORT;;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 275 "antimony.ypp"
    {if ((yyvsp[(1) - (5)].variable)->Synchronize((yyvsp[(5) - (5)].variable), (yyvsp[(3) - (5)].variable))) YYABORT;;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 276 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetDisplayName(*((yyvsp[(3) - (3)].word)))) YYABORT;;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 277 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetAssignmentRule((yyvsp[(4) - (4)].formula))) YYABORT;;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 278 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetRateRule((yyvsp[(4) - (4)].formula))) YYABORT;;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 279 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetUnit((yyvsp[(3) - (3)].variable))) YYABORT; ;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 282 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetModule((yyvsp[(3) - (4)].word))) YYABORT;;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 282 "antimony.ypp"
    {if ((yyvsp[(9) - (9)].variable) != NULL) {if ((yyvsp[(1) - (9)].variable)->SetCompartment((yyvsp[(9) - (9)].variable))) YYABORT;};}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 283 "antimony.ypp"
    {if(g_registry.CurrentModule()->SetModule((yyvsp[(1) - (2)].word))) YYABORT;;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 283 "antimony.ypp"
    {if ((yyvsp[(7) - (7)].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[(7) - (7)].variable))) YYABORT;};}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 287 "antimony.ypp"
    {;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 288 "antimony.ypp"
    {if (g_registry.AddVariableToCurrentImportList((yyvsp[(1) - (1)].variable))) YYABORT; ;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 289 "antimony.ypp"
    { if (g_registry.AddVariableToCurrentImportList((yyvsp[(3) - (3)].variable))) YYABORT; ;}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 293 "antimony.ypp"
    {;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 294 "antimony.ypp"
    {if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[(5) - (5)].variable));}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[(5) - (5)].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[(3) - (5)].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;};}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 298 "antimony.ypp"
    {if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[(5) - (5)].num));}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[(5) - (5)].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[(3) - (5)].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;};}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 302 "antimony.ypp"
    { ;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 303 "antimony.ypp"
    { ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 304 "antimony.ypp"
    { ;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 305 "antimony.ypp"
    { ;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 306 "antimony.ypp"
    { ;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 307 "antimony.ypp"
    { ;}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 309 "antimony.ypp"
    { ;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 310 "antimony.ypp"
    { ;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 313 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 314 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 315 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 316 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 319 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 320 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 321 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 322 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 325 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 326 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 327 "antimony.ypp"
    {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; ;}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 328 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 331 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 332 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 333 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 334 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 337 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 338 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 339 "antimony.ypp"
    {g_registry.SetError("Genes may not be set 'const'."); YYABORT; ;}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 340 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 343 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 344 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 345 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 346 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 350 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 351 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 352 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 353 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 356 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(2) - (2)].variable)->SetRegConst();;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 357 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(2) - (2)].variable)->SetRegConst();;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 358 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst();;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 361 "antimony.ypp"
    {if ((yyvsp[(2) - (4)].variable)->SetType(varUnitDefinition)) YYABORT; if ((yyvsp[(2) - (4)].variable)->GetUnitDef()->SetFromFormula((yyvsp[(4) - (4)].formula))) YYABORT;;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 362 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varUnitDefinition)) YYABORT;;}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 365 "antimony.ypp"
    {if (g_registry.SaveWorkingStrand()) YYABORT;;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 366 "antimony.ypp"
    {if (g_registry.SetStrandAs((yyvsp[(1) - (3)].variable))) YYABORT;;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 369 "antimony.ypp"
    {if (g_registry.SetNewUpstreamOpen((yyvsp[(2) - (2)].variable))) YYABORT;;}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 370 "antimony.ypp"
    {g_registry.SetOpenUpstream(); ;}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 371 "antimony.ypp"
    {if (g_registry.SetDownstreamEnd((yyvsp[(2) - (2)].variable))) YYABORT;;}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 372 "antimony.ypp"
    {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[(3) - (3)].variable))) YYABORT;;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 373 "antimony.ypp"
    { ;}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 376 "antimony.ypp"
    {if (g_registry.SetNewDownstreamOpen((yyvsp[(1) - (2)].variable))) YYABORT;;}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 377 "antimony.ypp"
    {if (g_registry.SetDownstreamOpen((yyvsp[(2) - (3)].variable))) YYABORT;;}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 380 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(2) - (2)].formula))) YYABORT;;}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 380 "antimony.ypp"
    {;}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 381 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(2) - (4)].formula), (yyvsp[(4) - (4)].formula))) YYABORT;;}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 381 "antimony.ypp"
    {;}
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 382 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (4)].formula), (yyvsp[(1) - (4)].variable))) YYABORT;;}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 382 "antimony.ypp"
    {;}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 383 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (6)].formula), (yyvsp[(6) - (6)].formula), (yyvsp[(1) - (6)].variable))) YYABORT;;}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 383 "antimony.ypp"
    {;}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 386 "antimony.ypp"
    {;}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 387 "antimony.ypp"
    {;}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 390 "antimony.ypp"
    {;}
    break;

  case 168:

/* Line 1464 of yacc.c  */
#line 391 "antimony.ypp"
    {if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[(5) - (5)].formula));}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[(3) - (5)].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;};}
    break;

  case 169:

/* Line 1464 of yacc.c  */
#line 398 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (3)].variable), (yyvsp[(3) - (3)].formula))) YYABORT;;}
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 399 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (5)].variable), (yyvsp[(3) - (5)].formula))) YYABORT;;}
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 400 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (6)].variable), (yyvsp[(3) - (6)].formula))) YYABORT;;}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 401 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (5)].variable), (yyvsp[(3) - (5)].formula))) YYABORT;;}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 402 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (6)].variable), (yyvsp[(3) - (6)].formula))) YYABORT;;}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 410 "antimony.ypp"
    {
                    if ((yyvsp[(1) - (1)].formula)->MakeAllVariablesUnits()) YYABORT;
                    if ((yyvsp[(1) - (1)].formula)->IsSingleVariable()) {
                      (yyval.variable) = g_registry.CurrentModule()->GetVariable(((yyvsp[(1) - (1)].formula)->GetVariables())[0]);
                      if ((yyval.variable)==NULL) YYABORT;
                    }
                    else {
                      UnitDef* ud = new UnitDef("", g_registry.CurrentModule()->GetModuleName());
                      if (ud->SetFromFormula((yyvsp[(1) - (1)].formula))) YYABORT;
                      (yyval.variable) = g_registry.CurrentModule()->AddOrFindUnitDef(ud);
                    }
                ;}
    break;



/* Line 1464 of yacc.c  */
#line 3040 "antimony.tab.cpp"
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
#line 436 "antimony.ypp"



void yyerror(char const *s)
{
  if (g_registry.GetError()=="") {
    g_registry.SetError(s);
  }
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
    g_registry.SetError("Unparseable content in line " + DoubleToString(yylloc_last_line) + ".");
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
    if (g_registry.IsConstant(word) != NULL) {
      yylval.word = g_registry.IsConstant(word);
      return CONSTANT;
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
    streampos numend = g_registry.input->tellg();
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
    assert(g_registry.input->good());
    yylval.num = number;
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

