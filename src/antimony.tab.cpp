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
     FORMULA = 270,
     DNA = 271,
     GENE = 272,
     OPERATOR = 273,
     EVENT = 274,
     COMPARTMENT = 275,
     IN = 276,
     IS = 277,
     VAR = 278,
     CONST = 279,
     DASHES = 280,
     ELLIPSES = 281,
     FUNCTION = 282,
     IMPORT = 283,
     AT = 284,
     FUNCTIONWORD = 285
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
#define FORMULA 270
#define DNA 271
#define GENE 272
#define OPERATOR 273
#define EVENT 274
#define COMPARTMENT 275
#define IN 276
#define IS 277
#define VAR 278
#define CONST 279
#define DASHES 280
#define ELLIPSES 281
#define FUNCTION 282
#define IMPORT 283
#define AT 284
#define FUNCTIONWORD 285




/* Copy the first part of user declarations.  */
#line 2 "src/antimony.ypp"

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
#line 33 "src/antimony.ypp"
{
  char character;
  const string* word;
  double num;
  rd_type reactionDivider;
  Formula* formula;
  Formula* spacedformula;
  Module* module;
  ReactantList* reactantList;
  Variable* variable;
  Variable* variablein;
  Variable* varmaybein;
  Variable* maybein;
}
/* Line 187 of yacc.c.  */
#line 201 "src/antimony.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 214 "src/antimony.tab.cpp"

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
#define YYLAST   564

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNRULES -- Number of states.  */
#define YYNSTATES  245

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,     2,     2,     2,    46,     2,
       3,     4,     7,     5,    10,     6,    39,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    41,
      42,    43,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     9,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    47,     2,     2,     2,     2,     2,
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
      33,    34,    35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    19,    22,
      23,    32,    33,    39,    42,    45,    46,    55,    58,    61,
      63,    66,    69,    70,    72,    76,    78,    82,    86,    88,
      90,    91,    94,    96,    99,   102,   105,   108,   111,   114,
     117,   119,   121,   130,   137,   138,   140,   143,   147,   152,
     154,   156,   158,   160,   161,   163,   165,   167,   169,   171,
     174,   177,   180,   183,   186,   190,   194,   198,   202,   206,
     210,   212,   214,   216,   218,   220,   222,   224,   226,   228,
     230,   232,   234,   236,   240,   244,   245,   254,   255,   262,
     263,   265,   269,   271,   273,   275,   277,   279,   281,   283,
     285,   288,   292,   296,   300,   303,   307,   311,   315,   318,
     322,   325,   329,   332,   336,   340,   344,   347,   351,   355,
     359,   362,   366,   370,   374,   377,   381,   385,   389,   392,
     395,   399,   401,   405,   408,   411,   414,   418,   420,   423,
     427,   428,   434,   435,   443,   444,   453,   457,   463
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    -1,    50,    51,    -1,    50,    52,    -1,
      50,    64,    -1,    50,    55,    -1,    50,     1,    -1,    36,
      14,    -1,    -1,    15,    12,    53,     3,    58,     4,    63,
      16,    -1,    -1,    15,    12,    54,    63,    16,    -1,    15,
      13,    -1,    15,    35,    -1,    -1,    38,    12,    56,     3,
      58,     4,    57,    16,    -1,    38,    13,    -1,    38,    35,
      -1,    68,    -1,    70,    57,    -1,    57,    70,    -1,    -1,
      59,    -1,    58,    10,    59,    -1,    12,    -1,    59,    39,
      12,    -1,    59,    29,    59,    -1,    59,    -1,    60,    -1,
      -1,    29,    59,    -1,    64,    -1,    63,    64,    -1,    65,
      70,    -1,    71,    70,    -1,    72,    70,    -1,    76,    70,
      -1,    85,    70,    -1,    88,    70,    -1,    60,    -1,    70,
      -1,    61,    40,    66,    67,    66,    41,    68,    62,    -1,
      66,    67,    66,    41,    68,    62,    -1,    -1,    59,    -1,
      11,    59,    -1,    66,     5,    59,    -1,    66,     5,    11,
      59,    -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,
      -1,    34,    -1,    59,    -1,    11,    -1,    35,    -1,    69,
      -1,    68,    34,    -1,    68,    59,    -1,    68,    11,    -1,
      68,    35,    -1,    68,    69,    -1,    68,    42,    43,    -1,
      68,    44,    43,    -1,    68,    43,    43,    -1,    68,    45,
      43,    -1,    68,    46,    46,    -1,    68,    47,    47,    -1,
       5,    -1,     6,    -1,     7,    -1,     8,    -1,     3,    -1,
       4,    -1,     9,    -1,    10,    -1,    44,    -1,    42,    -1,
      45,    -1,    41,    -1,    48,    -1,    61,    43,    68,    -1,
      61,    30,    59,    -1,    -1,    61,    40,    13,     3,    73,
      75,     4,    62,    -1,    -1,    13,     3,    74,    75,     4,
      62,    -1,    -1,    59,    -1,    75,    10,    59,    -1,    77,
      -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,    82,
      -1,    83,    -1,    84,    -1,    21,    61,    -1,    31,    21,
      61,    -1,    32,    21,    61,    -1,    77,    10,    61,    -1,
      23,    61,    -1,    31,    23,    61,    -1,    32,    23,    61,
      -1,    78,    10,    61,    -1,    22,    61,    -1,    31,    22,
      61,    -1,    32,    22,    -1,    79,    10,    61,    -1,    24,
      61,    -1,    31,    24,    61,    -1,    32,    24,    61,    -1,
      80,    10,    61,    -1,    25,    61,    -1,    31,    25,    61,
      -1,    32,    25,    61,    -1,    81,    10,    61,    -1,    26,
      61,    -1,    31,    26,    61,    -1,    32,    26,    61,    -1,
      82,    10,    61,    -1,    28,    61,    -1,    31,    28,    61,
      -1,    32,    28,    61,    -1,    83,    10,    61,    -1,    31,
      61,    -1,    32,    61,    -1,    84,    10,    61,    -1,    86,
      -1,    61,    40,    86,    -1,    33,    59,    -1,    33,    87,
      -1,    87,    59,    -1,    33,    87,    59,    -1,    87,    -1,
      59,    33,    -1,    87,    59,    33,    -1,    -1,    37,    68,
      40,    89,    92,    -1,    -1,    61,    40,    37,    68,    40,
      90,    92,    -1,    -1,    61,    40,    37,    68,    40,    48,
      91,    92,    -1,    59,    43,    68,    -1,    59,    43,    68,
      40,    92,    -1,    59,    43,    68,    40,    48,    92,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    68,    69,    70,    71,    72,    75,    78,
      78,    84,    84,    90,    91,    94,    94,    95,    96,    99,
     100,   101,   105,   106,   107,   110,   111,   120,   123,   124,
     127,   128,   131,   132,   135,   136,   137,   138,   139,   140,
     141,   142,   145,   153,   163,   164,   165,   166,   167,   171,
     172,   173,   174,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   209,   210,   213,   214,   217,   217,   218,   218,   221,
     222,   223,   226,   227,   228,   229,   230,   231,   233,   234,
     237,   238,   239,   240,   243,   244,   245,   246,   249,   250,
     251,   252,   255,   256,   257,   258,   261,   262,   263,   264,
     267,   268,   269,   270,   283,   284,   285,   286,   289,   290,
     291,   294,   295,   298,   299,   300,   301,   302,   305,   306,
     309,   309,   310,   310,   311,   311,   314,   315,   316
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
  "FORMULA", "DNA", "GENE", "OPERATOR", "EVENT", "COMPARTMENT", "IN", "IS",
  "VAR", "CONST", "DASHES", "ELLIPSES", "FUNCTION", "IMPORT", "AT",
  "FUNCTIONWORD", "'.'", "':'", "';'", "'<'", "'='", "'>'", "'!'", "'&'",
  "'|'", "'\\n'", "$accept", "input", "import", "module", "@1", "@2",
  "function", "@3", "spacedformula", "variableexportlist", "variable",
  "variablein", "varmaybein", "maybein", "modulebody", "modulepart",
  "reaction", "reactantList", "reactionDivider", "formula", "mathThing",
  "lineend", "assignment", "submodule", "@4", "@5", "variableimportlist",
  "varinitialize", "specinit", "formulainit", "reactioninit", "dnainit",
  "geneinit", "operatorinit", "compartmentinit", "varconstinit", "dnadef",
  "dnastrand", "dnamiddle", "event", "@6", "@7", "@8", "assignmentlist", 0
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
     277,   278,   279,   280,   281,   282,   283,   284,   285,    46,
      58,    59,    60,    61,    62,    33,    38,   124,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    50,    50,    50,    50,    51,    53,
      52,    54,    52,    52,    52,    56,    55,    55,    55,    57,
      57,    57,    58,    58,    58,    59,    59,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    65,    65,    66,    66,    66,    66,    66,    67,
      67,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    71,    71,    73,    72,    74,    72,    75,
      75,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    77,    78,    78,    78,    78,    79,    79,
      79,    79,    80,    80,    80,    80,    81,    81,    81,    81,
      82,    82,    82,    82,    83,    83,    83,    83,    84,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    87,    87,
      89,    88,    90,    88,    91,    88,    92,    92,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     0,
       8,     0,     5,     2,     2,     0,     8,     2,     2,     1,
       2,     2,     0,     1,     3,     1,     3,     3,     1,     1,
       0,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     8,     6,     0,     1,     2,     3,     4,     1,
       1,     1,     1,     0,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     0,     8,     0,     6,     0,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     3,     3,     2,     3,     3,     3,     2,     3,
       2,     3,     2,     3,     3,     3,     2,     3,     3,     3,
       2,     3,     3,     3,     2,     3,     3,     3,     2,     2,
       3,     1,     3,     2,     2,     2,     3,     1,     2,     3,
       0,     5,     0,     7,     0,     8,     3,     5,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     7,     0,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,    81,    82,     3,     4,     6,    45,    40,     0,     5,
       0,     0,    41,     0,     0,     0,    92,    93,    94,    95,
      96,    97,    98,    99,     0,   131,   137,     0,    46,    87,
      11,    13,    14,    28,    29,   100,   108,   104,   112,   116,
     120,   124,     0,     0,     0,     0,     0,     0,     0,   128,
       0,   110,     0,     0,     0,     0,     0,   129,   133,   134,
       8,    74,    75,    70,    71,    72,    73,    76,    77,    56,
      54,    57,    79,    78,    80,    55,     0,    58,    15,    17,
      18,     0,   138,     0,     0,    44,    53,    34,     0,    49,
      50,    51,    52,    44,    35,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     0,    38,   135,    39,    89,     0,
      44,   101,   109,   105,   113,   117,   121,   125,   102,   106,
     114,   118,   122,   126,   136,    61,    59,    62,   140,    79,
       0,    78,    80,     0,     0,    60,    63,     0,    27,    26,
      84,     0,    53,    45,     0,   132,    83,     0,    47,    45,
       0,   103,   107,   111,   115,   119,   123,   127,   130,   139,
      90,     0,    22,    44,    32,     0,    64,    66,    65,    67,
      68,    69,    22,    85,     0,    44,    48,    53,    30,     0,
       0,    23,    12,    33,     0,   141,     0,    89,   142,     0,
      30,     0,    88,    91,    44,     0,    53,    53,     0,   144,
       0,    53,    43,    31,    44,    24,   146,     0,    19,    53,
      30,     0,   143,    30,    10,     0,    16,    21,    20,    86,
     145,    42,     0,   147,   148
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    23,    24,   129,   130,    25,   157,   227,   200,
      53,    54,    28,   212,   183,   184,    30,    31,   113,   228,
      97,    32,    33,    34,   207,   128,   181,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
     185,   220,   231,   205
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -196
static const yytype_int16 yypact[] =
{
    -196,   365,  -196,  -196,    17,  -196,    31,    19,    17,    17,
      17,    17,    17,    17,    17,   146,   255,    17,    -2,   143,
      24,  -196,  -196,  -196,  -196,  -196,   312,    37,    76,  -196,
      -8,   105,  -196,    -8,    -8,    -8,    38,    39,    42,    53,
      65,    69,    77,    89,    -8,  -196,    17,    -8,    75,  -196,
     125,  -196,  -196,   -22,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,    17,    17,    17,    17,    17,    17,    17,  -196,
      17,  -196,    17,    17,    17,    17,    17,  -196,    78,    17,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,    75,   254,  -196,  -196,  -196,
    -196,    17,  -196,   123,    17,    57,   143,  -196,    54,  -196,
    -196,  -196,  -196,   119,  -196,  -196,  -196,    17,    17,    17,
      17,    17,    17,    17,    17,  -196,    82,  -196,    17,   137,
     516,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,    82,  -196,  -196,  -196,  -196,    99,
     100,   114,   116,   117,   113,    75,  -196,   161,    75,  -196,
      75,   170,   143,    78,   105,  -196,   489,    17,    75,    75,
       5,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
      75,   122,    17,    60,  -196,    17,  -196,  -196,  -196,  -196,
    -196,  -196,    17,  -196,   411,   119,    75,   143,   147,    17,
     129,    75,  -196,  -196,   -30,  -196,   134,    17,   127,     6,
     430,    17,  -196,    75,   516,    17,   143,    16,   152,  -196,
      17,   143,  -196,    75,   306,    75,   475,    14,   489,    16,
     147,    17,  -196,   430,  -196,    -7,  -196,  -196,    -8,  -196,
    -196,  -196,    17,  -196,  -196
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   -50,    -6,
      -1,     7,   240,  -195,   -25,     0,  -196,   -99,    28,   -17,
     -92,     9,  -196,  -196,  -196,  -196,   -12,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,    92,   183,  -196,
    -196,  -196,  -196,  -122
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -45
static const yytype_int16 yytable[] =
{
      26,    29,    96,    48,   156,     5,   164,   101,    27,   103,
     108,   108,    80,   216,   170,   222,    78,   103,    95,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     5,     5,
     236,    50,    51,    21,    49,   239,    98,    99,   241,   107,
      22,   242,   114,   115,   116,   126,   197,   221,   117,   118,
      90,    91,   119,   125,    52,    21,   127,    21,    92,   100,
      93,    94,    22,   120,    22,   167,     5,   -29,     4,     5,
     161,     4,     5,     6,   156,   121,   202,   -29,   144,   122,
     -29,     8,     9,    10,    11,    12,    13,   123,    14,   166,
      17,    15,    16,    17,   162,   155,   209,    19,   232,   124,
     158,    21,   156,   160,   163,    95,   104,   168,    22,   240,
     108,   102,   169,   243,   103,   179,   105,   103,   156,   106,
     244,   103,   109,   110,   111,   112,   198,   180,    -9,    26,
       4,     5,   199,   214,   156,   159,   156,    27,   217,   215,
     182,   156,   186,   187,   215,   194,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     5,   230,   188,     5,   189,
     191,    95,   199,   190,   192,   155,   196,    62,    63,    64,
      65,    66,    67,   193,    68,   219,   211,    90,    91,   238,
     210,   201,    26,   203,   204,    92,   206,    93,    94,   224,
      27,   201,   195,   155,   169,   218,    95,   165,   213,   226,
      79,     0,     0,     0,   233,     0,   180,     0,     0,   155,
     223,     0,     0,    26,   225,    95,    95,     0,     0,   204,
      95,    27,     0,    26,   203,   155,   229,   155,    95,     0,
     204,    27,   155,     0,   204,     0,   237,     0,   229,     0,
       0,   204,     0,     0,     0,     0,     0,   237,    55,    56,
      57,    58,    59,    60,    61,    69,    77,    81,    82,    83,
      84,    85,    86,    87,    88,   145,     5,     5,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,    72,    73,
      74,    75,     0,    76,     0,     0,     0,     0,   146,   147,
       0,     0,     0,     0,   148,     0,   149,   150,   151,   152,
     153,   154,   131,   132,   133,   134,   135,   136,   137,     0,
     138,     0,   139,   140,   141,   142,   143,     4,     5,     6,
       0,     0,   234,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,     0,    14,     0,     0,    15,    16,    17,
       0,   101,   -28,    19,     0,   102,     0,    21,     0,     0,
       0,   103,   -28,     0,    22,   -28,     0,   171,   172,   173,
     174,   175,   176,   177,   178,     2,     3,     0,     0,     0,
     -44,     0,     0,     0,     0,     0,     4,     5,     6,     0,
       7,     0,   -44,   -44,   -44,   -44,     8,     9,    10,    11,
      12,    13,     0,    14,     0,     0,    15,    16,    17,     0,
       0,    18,    19,    20,     0,     0,    21,     0,     0,     0,
       0,     0,     0,    22,    81,    82,    83,    84,    85,    86,
      87,    88,   145,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,   145,     5,     0,     0,   146,   147,     0,     0,     0,
       0,   208,     0,   149,   150,   151,   152,   153,   154,   211,
       0,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,   149,   150,   151,   152,   153,   154,    81,    82,
      83,    84,    85,    86,    87,    88,   145,     5,     0,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
     145,     5,     0,     0,     0,     0,     0,     0,     0,   146,
     147,     0,     0,     0,     0,   235,     0,   149,   150,   151,
     152,   153,   154,   146,   147,     0,     0,     4,     5,     6,
       0,   149,   150,   151,   152,   153,   154,     8,     9,    10,
      11,    12,    13,     0,    14,     0,     0,    15,    16,    17,
       0,     0,     0,    19,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,    22
};

static const yytype_int16 yycheck[] =
{
       1,     1,    19,     4,    96,    12,   105,    29,     1,    39,
       5,     5,    14,    43,   113,   210,    17,    39,    19,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    12,
      16,    12,    13,    41,     3,   230,    12,    13,   233,    30,
      48,    48,    33,    34,    35,    46,    41,    41,    10,    10,
      34,    35,    10,    44,    35,    41,    47,    41,    42,    35,
      44,    45,    48,    10,    48,    11,    12,    30,    11,    12,
      13,    11,    12,    13,   166,    10,    16,    40,    79,    10,
      43,    21,    22,    23,    24,    25,    26,    10,    28,   106,
      33,    31,    32,    33,    37,    96,   195,    37,   220,    10,
     101,    41,   194,   104,   105,   106,    30,   108,    48,   231,
       5,    33,   113,   235,    39,    33,    40,    39,   210,    43,
     242,    39,    17,    18,    19,    20,     4,   128,     3,   130,
      11,    12,    10,     4,   226,    12,   228,   130,     4,    10,
       3,   233,    43,    43,    10,   162,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     4,    43,    12,    43,
      47,   162,    10,    46,     3,   166,   167,    21,    22,    23,
      24,    25,    26,     3,    28,    48,    29,    34,    35,   229,
     197,   182,   183,   183,   185,    42,   192,    44,    45,   214,
     183,   192,   164,   194,   195,   207,   197,   105,   199,   216,
      17,    -1,    -1,    -1,   221,    -1,   207,    -1,    -1,   210,
     211,    -1,    -1,   214,   215,   216,   217,    -1,    -1,   220,
     221,   214,    -1,   224,   224,   226,   217,   228,   229,    -1,
     231,   224,   233,    -1,   235,    -1,   227,    -1,   229,    -1,
      -1,   242,    -1,    -1,    -1,    -1,    -1,   238,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    -1,    28,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    40,    -1,    42,    43,    44,    45,
      46,    47,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    -1,    72,    73,    74,    75,    76,    11,    12,    13,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    -1,    28,    -1,    -1,    31,    32,    33,
      -1,    29,    30,    37,    -1,    33,    -1,    41,    -1,    -1,
      -1,    39,    40,    -1,    48,    43,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,     0,     1,    -1,    -1,    -1,
       5,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,    -1,
      15,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    28,    -1,    -1,    31,    32,    33,    -1,
      -1,    36,    37,    38,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    48,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    40,    -1,    42,    43,    44,    45,    46,    47,    29,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    40,    -1,    42,    43,    44,
      45,    46,    47,    34,    35,    -1,    -1,    11,    12,    13,
      -1,    42,    43,    44,    45,    46,    47,    21,    22,    23,
      24,    25,    26,    -1,    28,    -1,    -1,    31,    32,    33,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,     0,     1,    11,    12,    13,    15,    21,    22,
      23,    24,    25,    26,    28,    31,    32,    33,    36,    37,
      38,    41,    48,    51,    52,    55,    59,    60,    61,    64,
      65,    66,    70,    71,    72,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    59,     3,
      12,    13,    35,    59,    60,    61,    61,    61,    61,    61,
      61,    61,    21,    22,    23,    24,    25,    26,    28,    61,
      21,    22,    23,    24,    25,    26,    28,    61,    59,    87,
      14,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      34,    35,    42,    44,    45,    59,    68,    69,    12,    13,
      35,    29,    33,    39,    30,    40,    43,    70,     5,    17,
      18,    19,    20,    67,    70,    70,    70,    10,    10,    10,
      10,    10,    10,    10,    10,    70,    59,    70,    74,    53,
      54,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    59,    11,    34,    35,    40,    42,
      43,    44,    45,    46,    47,    59,    69,    56,    59,    12,
      59,    13,    37,    59,    66,    86,    68,    11,    59,    59,
      66,    61,    61,    61,    61,    61,    61,    61,    61,    33,
      59,    75,     3,    63,    64,    89,    43,    43,    43,    43,
      46,    47,     3,     3,    68,    67,    59,    41,     4,    10,
      58,    59,    16,    64,    59,    92,    58,    73,    40,    66,
      68,    29,    62,    59,     4,    10,    43,     4,    75,    48,
      90,    41,    62,    59,    63,    59,    68,    57,    68,    70,
       4,    91,    92,    68,    16,    40,    16,    70,    57,    62,
      92,    62,    48,    92,    92
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
#line 68 "src/antimony.ypp"
    {;}
    break;

  case 4:
#line 69 "src/antimony.ypp"
    { /*cout << endl << $2->ToString() << endl << endl;*/ ;}
    break;

  case 5:
#line 70 "src/antimony.ypp"
    {;}
    break;

  case 6:
#line 71 "src/antimony.ypp"
    {;}
    break;

  case 7:
#line 72 "src/antimony.ypp"
    {YYABORT;;}
    break;

  case 8:
#line 75 "src/antimony.ypp"
    { if (g_registry.OpenFile(*((yyvsp[(2) - (2)].word)))==0) YYABORT;;}
    break;

  case 9:
#line 78 "src/antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(2) - (2)].word));;}
    break;

  case 10:
#line 79 "src/antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                ;}
    break;

  case 11:
#line 84 "src/antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(2) - (2)].word));;}
    break;

  case 12:
#line 85 "src/antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                ;}
    break;

  case 13:
#line 90 "src/antimony.ypp"
    {g_registry.SetError("module '" + *((yyvsp[(2) - (2)].word)) + "' already defined."); YYABORT;;}
    break;

  case 14:
#line 91 "src/antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a module because it is already a defined function."); YYABORT;;}
    break;

  case 15:
#line 94 "src/antimony.ypp"
    {g_registry.NewUserFunction((yyvsp[(2) - (2)].word));;}
    break;

  case 16:
#line 94 "src/antimony.ypp"
    {if (g_registry.SetUserFunction((yyvsp[(7) - (8)].formula))) YYABORT;;}
    break;

  case 17:
#line 95 "src/antimony.ypp"
    {g_registry.SetError("Cannot use '" + *((yyvsp[(2) - (2)].word)) +"' as a function name because it is already the name of a module."); YYABORT;;}
    break;

  case 18:
#line 96 "src/antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a new function because it is already a defined function."); YYABORT;;}
    break;

  case 19:
#line 99 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (1)].formula);;}
    break;

  case 20:
#line 100 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(2) - (2)].formula);;}
    break;

  case 21:
#line 101 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula);;}
    break;

  case 22:
#line 105 "src/antimony.ypp"
    {;}
    break;

  case 23:
#line 106 "src/antimony.ypp"
    {g_registry.AddVariableToCurrentExportList((yyvsp[(1) - (1)].variable)); ;}
    break;

  case 24:
#line 107 "src/antimony.ypp"
    { g_registry.AddVariableToCurrentExportList((yyvsp[(3) - (3)].variable)); ;}
    break;

  case 25:
#line 110 "src/antimony.ypp"
    {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[(1) - (1)].word)); ;}
    break;

  case 26:
#line 111 "src/antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable)->GetSubVariable((yyvsp[(3) - (3)].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[(3) - (3)].word)) + "' is not a subvariable of '" + (yyvsp[(1) - (3)].variable)->GetNameDelimitedBy('.') + "'.");
                    YYABORT;
                  }
                ;}
    break;

  case 27:
#line 120 "src/antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetCompartment((yyvsp[(3) - (3)].variable))) YYABORT; (yyval.variable) = (yyvsp[(1) - (3)].variable);;}
    break;

  case 28:
#line 123 "src/antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);;}
    break;

  case 29:
#line 124 "src/antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);;}
    break;

  case 30:
#line 127 "src/antimony.ypp"
    {(yyval.variable) = NULL;;}
    break;

  case 31:
#line 128 "src/antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable);;}
    break;

  case 32:
#line 131 "src/antimony.ypp"
    {;}
    break;

  case 33:
#line 132 "src/antimony.ypp"
    {;}
    break;

  case 34:
#line 135 "src/antimony.ypp"
    {;}
    break;

  case 35:
#line 136 "src/antimony.ypp"
    {;}
    break;

  case 36:
#line 137 "src/antimony.ypp"
    {;}
    break;

  case 37:
#line 138 "src/antimony.ypp"
    {;}
    break;

  case 38:
#line 139 "src/antimony.ypp"
    {;}
    break;

  case 39:
#line 140 "src/antimony.ypp"
    {;}
    break;

  case 40:
#line 141 "src/antimony.ypp"
    {;}
    break;

  case 41:
#line 142 "src/antimony.ypp"
    {;}
    break;

  case 42:
#line 146 "src/antimony.ypp"
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[(4) - (8)].reactionDivider), (yyvsp[(7) - (8)].formula), (yyvsp[(1) - (8)].variable));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[(8) - (8)].variable) != NULL) {
                    if ((yyvsp[(1) - (8)].variable)->SetCompartment((yyvsp[(8) - (8)].variable))) YYABORT;
                  }
                ;}
    break;

  case 43:
#line 154 "src/antimony.ypp"
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[(2) - (6)].reactionDivider), (yyvsp[(5) - (6)].formula));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[(6) - (6)].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[(6) - (6)].variable))) YYABORT;
                  }
                ;}
    break;

  case 44:
#line 163 "src/antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); ;}
    break;

  case 45:
#line 164 "src/antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(1) - (1)].variable)); ;}
    break;

  case 46:
#line 165 "src/antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(2) - (2)].variable), (yyvsp[(1) - (2)].num)); ;}
    break;

  case 47:
#line 166 "src/antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (3)].reactantList); (yyvsp[(1) - (3)].reactantList)->AddReactant((yyvsp[(3) - (3)].variable)); ;}
    break;

  case 48:
#line 167 "src/antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (4)].reactantList); (yyvsp[(1) - (4)].reactantList)->AddReactant((yyvsp[(4) - (4)].variable), (yyvsp[(3) - (4)].num)); ;}
    break;

  case 49:
#line 171 "src/antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;;}
    break;

  case 50:
#line 172 "src/antimony.ypp"
    {(yyval.reactionDivider) = rdInhibits;;}
    break;

  case 51:
#line 173 "src/antimony.ypp"
    {(yyval.reactionDivider) = rdActivates;;}
    break;

  case 52:
#line 174 "src/antimony.ypp"
    {(yyval.reactionDivider) = rdInfluences;;}
    break;

  case 53:
#line 177 "src/antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); ;}
    break;

  case 54:
#line 178 "src/antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddEllipses();;}
    break;

  case 55:
#line 179 "src/antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddVariable((yyvsp[(1) - (1)].variable)); ;}
    break;

  case 56:
#line 180 "src/antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddNum((yyvsp[(1) - (1)].num)); ;}
    break;

  case 57:
#line 181 "src/antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddText((yyvsp[(1) - (1)].word));;}
    break;

  case 58:
#line 182 "src/antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); (yyval.formula)->AddMathThing((yyvsp[(1) - (1)].character)); ;}
    break;

  case 59:
#line 183 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddEllipses();;}
    break;

  case 60:
#line 184 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddVariable((yyvsp[(2) - (2)].variable)); ;}
    break;

  case 61:
#line 185 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddNum((yyvsp[(2) - (2)].num)); ;}
    break;

  case 62:
#line 186 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddText((yyvsp[(2) - (2)].word));;}
    break;

  case 63:
#line 187 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddMathThing((yyvsp[(2) - (2)].character)); ;}
    break;

  case 64:
#line 188 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('<'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 65:
#line 189 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('>'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 66:
#line 190 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('='); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 67:
#line 191 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('!'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); ;}
    break;

  case 68:
#line 192 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); ;}
    break;

  case 69:
#line 193 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); ;}
    break;

  case 70:
#line 196 "src/antimony.ypp"
    {(yyval.character) = '+';;}
    break;

  case 71:
#line 197 "src/antimony.ypp"
    {(yyval.character) = '-';;}
    break;

  case 72:
#line 198 "src/antimony.ypp"
    {(yyval.character) = '*';;}
    break;

  case 73:
#line 199 "src/antimony.ypp"
    {(yyval.character) = '/';;}
    break;

  case 74:
#line 200 "src/antimony.ypp"
    {(yyval.character) = '(';;}
    break;

  case 75:
#line 201 "src/antimony.ypp"
    {(yyval.character) = ')';;}
    break;

  case 76:
#line 202 "src/antimony.ypp"
    {(yyval.character) = '^';;}
    break;

  case 77:
#line 203 "src/antimony.ypp"
    {(yyval.character) = ',';;}
    break;

  case 78:
#line 204 "src/antimony.ypp"
    {(yyval.character) = '>';;}
    break;

  case 79:
#line 205 "src/antimony.ypp"
    {(yyval.character) = '<';;}
    break;

  case 80:
#line 206 "src/antimony.ypp"
    {(yyval.character) = '!';;}
    break;

  case 81:
#line 209 "src/antimony.ypp"
    {;}
    break;

  case 82:
#line 210 "src/antimony.ypp"
    {;}
    break;

  case 83:
#line 213 "src/antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetFormula((yyvsp[(3) - (3)].formula))) YYABORT; ;}
    break;

  case 84:
#line 214 "src/antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->Synchronize((yyvsp[(3) - (3)].variable))) YYABORT;;}
    break;

  case 85:
#line 217 "src/antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetModule((yyvsp[(3) - (4)].word))) YYABORT;;}
    break;

  case 86:
#line 217 "src/antimony.ypp"
    {if ((yyvsp[(8) - (8)].variable) != NULL) {if ((yyvsp[(1) - (8)].variable)->SetCompartment((yyvsp[(8) - (8)].variable))) YYABORT;};}
    break;

  case 87:
#line 218 "src/antimony.ypp"
    {if(g_registry.CurrentModule()->SetModule((yyvsp[(1) - (2)].word))) YYABORT;;}
    break;

  case 88:
#line 218 "src/antimony.ypp"
    {if ((yyvsp[(6) - (6)].variable) != NULL) {if (g_registry.SetCompartmentOfCurrentSubmod((yyvsp[(6) - (6)].variable))) YYABORT;};}
    break;

  case 89:
#line 221 "src/antimony.ypp"
    {;}
    break;

  case 90:
#line 222 "src/antimony.ypp"
    {if (g_registry.AddVariableToCurrentImportList((yyvsp[(1) - (1)].variable))) YYABORT; ;}
    break;

  case 91:
#line 223 "src/antimony.ypp"
    { if (g_registry.AddVariableToCurrentImportList((yyvsp[(3) - (3)].variable))) YYABORT; ;}
    break;

  case 92:
#line 226 "src/antimony.ypp"
    { ;}
    break;

  case 93:
#line 227 "src/antimony.ypp"
    { ;}
    break;

  case 94:
#line 228 "src/antimony.ypp"
    { ;}
    break;

  case 95:
#line 229 "src/antimony.ypp"
    { ;}
    break;

  case 96:
#line 230 "src/antimony.ypp"
    { ;}
    break;

  case 97:
#line 231 "src/antimony.ypp"
    { ;}
    break;

  case 98:
#line 233 "src/antimony.ypp"
    { ;}
    break;

  case 99:
#line 234 "src/antimony.ypp"
    { ;}
    break;

  case 100:
#line 237 "src/antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 101:
#line 238 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 102:
#line 239 "src/antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 103:
#line 240 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; ;}
    break;

  case 104:
#line 243 "src/antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 105:
#line 244 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 106:
#line 245 "src/antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 107:
#line 246 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; ;}
    break;

  case 108:
#line 249 "src/antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 109:
#line 250 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 110:
#line 251 "src/antimony.ypp"
    {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; ;}
    break;

  case 111:
#line 252 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; ;}
    break;

  case 112:
#line 255 "src/antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 113:
#line 256 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 114:
#line 257 "src/antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 115:
#line 258 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; ;}
    break;

  case 116:
#line 261 "src/antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 117:
#line 262 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 118:
#line 263 "src/antimony.ypp"
    {g_registry.SetError("Genes may not be set 'const'."); YYABORT; ;}
    break;

  case 119:
#line 264 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; ;}
    break;

  case 120:
#line 267 "src/antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 121:
#line 268 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 122:
#line 269 "src/antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 123:
#line 270 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; ;}
    break;

  case 124:
#line 283 "src/antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 125:
#line 284 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 126:
#line 285 "src/antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 127:
#line 286 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; ;}
    break;

  case 128:
#line 289 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(2) - (2)].variable)->SetRegConst();;}
    break;

  case 129:
#line 290 "src/antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(2) - (2)].variable)->SetRegConst();;}
    break;

  case 130:
#line 291 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst();;}
    break;

  case 131:
#line 294 "src/antimony.ypp"
    {if (g_registry.SaveWorkingStrand()) YYABORT;;}
    break;

  case 132:
#line 295 "src/antimony.ypp"
    {if (g_registry.SetStrandAs((yyvsp[(1) - (3)].variable))) YYABORT;;}
    break;

  case 133:
#line 298 "src/antimony.ypp"
    {if (g_registry.SetNewUpstreamOpen((yyvsp[(2) - (2)].variable))) YYABORT;;}
    break;

  case 134:
#line 299 "src/antimony.ypp"
    {g_registry.SetOpenUpstream(); ;}
    break;

  case 135:
#line 300 "src/antimony.ypp"
    {if (g_registry.SetDownstreamEnd((yyvsp[(2) - (2)].variable))) YYABORT;;}
    break;

  case 136:
#line 301 "src/antimony.ypp"
    {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[(3) - (3)].variable))) YYABORT;;}
    break;

  case 137:
#line 302 "src/antimony.ypp"
    { ;}
    break;

  case 138:
#line 305 "src/antimony.ypp"
    {if (g_registry.SetNewDownstreamOpen((yyvsp[(1) - (2)].variable))) YYABORT;;}
    break;

  case 139:
#line 306 "src/antimony.ypp"
    {if (g_registry.SetDownstreamOpen((yyvsp[(2) - (3)].variable))) YYABORT;;}
    break;

  case 140:
#line 309 "src/antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(2) - (3)].formula))) YYABORT;;}
    break;

  case 141:
#line 309 "src/antimony.ypp"
    {;}
    break;

  case 142:
#line 310 "src/antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (5)].formula), (yyvsp[(1) - (5)].variable))) YYABORT;;}
    break;

  case 143:
#line 310 "src/antimony.ypp"
    {;}
    break;

  case 144:
#line 311 "src/antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (6)].formula), (yyvsp[(1) - (6)].variable))) YYABORT;;}
    break;

  case 145:
#line 311 "src/antimony.ypp"
    {;}
    break;

  case 146:
#line 314 "src/antimony.ypp"
    {if (g_registry.AddResultToCurrentEvent((yyvsp[(1) - (3)].variable), (yyvsp[(3) - (3)].formula))) YYABORT;;}
    break;

  case 147:
#line 315 "src/antimony.ypp"
    {if (g_registry.AddResultToCurrentEvent((yyvsp[(1) - (5)].variable), (yyvsp[(3) - (5)].formula))) YYABORT;;}
    break;

  case 148:
#line 316 "src/antimony.ypp"
    {if (g_registry.AddResultToCurrentEvent((yyvsp[(1) - (6)].variable), (yyvsp[(3) - (6)].formula))) YYABORT;;}
    break;


/* Line 1267 of yacc.c.  */
#line 2461 "src/antimony.tab.cpp"
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


#line 319 "src/antimony.ypp"



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
  // Skip carriage returns after '\':
  if (cc == '\\') {
    g_registry.input->get(cc);
    if (cc == '\r' || cc == '\n') {
      while (cc == '\r' || cc == '\n') {
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
    if (CaselessStrCmp(word, "at")) {
      return AT;
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

