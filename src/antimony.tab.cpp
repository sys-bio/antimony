/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Substitute the variable and function names.  */
#define yyparse         antimony_yyparse
#define yylex           antimony_yylex
#define yyerror         antimony_yyerror
#define yylval          antimony_yylval
#define yychar          antimony_yychar
#define yydebug         antimony_yydebug
#define yynerrs         antimony_yynerrs


/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 2 "src/antimony.ypp"

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


/* Line 268 of yacc.c  */
#line 112 "src/antimony.tab.cpp"

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
     VARWORD = 288
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 35 "src/antimony.ypp"

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



/* Line 293 of yacc.c  */
#line 201 "src/antimony.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 213 "src/antimony.tab.cpp"

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   728

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  178
/* YYNRULES -- Number of states.  */
#define YYNSTATES  313

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      55,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,     2,    46,    10,     4,    56,
      42,    43,     8,     7,    44,     6,    45,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    49,
      51,    47,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    11,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     5,    54,     2,     2,     2,     2,
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
      33,    34,    35,    36,    37,    38,    39,    40,    41
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
     117,   120,   123,   126,   129,   132,   135,   138,   141,   143,
     145,   154,   161,   162,   164,   167,   171,   176,   179,   182,
     185,   188,   190,   193,   194,   197,   200,   203,   206,   209,
     214,   217,   221,   225,   229,   233,   237,   241,   246,   248,
     252,   254,   256,   258,   260,   262,   264,   266,   268,   270,
     272,   274,   278,   282,   288,   294,   298,   303,   308,   312,
     313,   323,   324,   332,   333,   335,   339,   340,   346,   352,
     354,   356,   358,   360,   362,   364,   366,   368,   371,   375,
     379,   383,   386,   390,   394,   398,   401,   405,   408,   412,
     415,   419,   423,   427,   430,   434,   438,   442,   445,   449,
     453,   457,   460,   464,   468,   472,   475,   478,   482,   487,
     490,   492,   496,   499,   502,   505,   509,   511,   514,   518,
     519,   526,   527,   536,   537,   546,   547,   558,   560,   563,
     564,   570,   574,   580,   587,   593,   600,   603,   607
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    -1,    58,    59,    -1,    58,    60,    -1,
      58,    74,    -1,    58,    64,    -1,    58,     1,    -1,    31,
      39,    -1,    -1,    35,    63,    14,    61,    42,    67,    43,
      73,    24,    -1,    -1,    35,    63,    14,    62,    73,    24,
      -1,    35,    34,    -1,    35,    27,    -1,    -1,     8,    -1,
      -1,    28,    14,    65,    42,    67,    43,    66,    24,    -1,
      28,    34,    -1,    28,    27,    -1,    78,    -1,    81,    66,
      -1,    66,    81,    -1,    -1,    68,    -1,    67,    44,    68,
      -1,    14,    -1,    68,    45,    14,    -1,    46,    68,    -1,
      68,    32,    68,    -1,    68,    -1,    69,    -1,    70,    -1,
      70,    47,    78,    -1,    70,    30,   110,    -1,    -1,    32,
      68,    -1,    74,    -1,    73,    74,    -1,    75,    81,    -1,
      82,    81,    -1,    83,    81,    -1,    88,    81,    -1,    98,
      81,    -1,   101,    81,    -1,    97,    81,    -1,   109,    81,
      -1,    69,    -1,    81,    -1,    70,    48,    76,    77,    76,
      49,    78,    72,    -1,    76,    77,    76,    49,    78,    72,
      -1,    -1,    68,    -1,    12,    68,    -1,    76,     7,    68,
      -1,    76,     7,    12,    68,    -1,     6,    50,    -1,     6,
       5,    -1,     6,    42,    -1,     6,    14,    -1,    16,    -1,
      51,    16,    -1,    -1,    78,    23,    -1,    78,    68,    -1,
      78,    12,    -1,    78,    18,    -1,    78,    27,    -1,    78,
      42,    79,    43,    -1,    78,    80,    -1,    78,    51,    47,
      -1,    78,    50,    47,    -1,    78,    47,    47,    -1,    78,
      52,    47,    -1,    78,     4,     4,    -1,    78,     5,     5,
      -1,    78,    53,   110,    54,    -1,    78,    -1,    79,    44,
      78,    -1,     7,    -1,     6,    -1,     8,    -1,     9,    -1,
      11,    -1,    50,    -1,    51,    -1,    52,    -1,    10,    -1,
      49,    -1,    55,    -1,    70,    47,    78,    -1,    70,    33,
      68,    -1,    70,    33,    68,     9,    68,    -1,    70,     8,
      68,    33,    68,    -1,    70,    33,    39,    -1,    70,    48,
      47,    78,    -1,    70,    56,    47,    78,    -1,    70,    30,
     110,    -1,    -1,    70,    48,    34,    42,    84,    86,    43,
      87,    72,    -1,    -1,    34,    42,    85,    86,    43,    87,
      72,    -1,    -1,    68,    -1,    86,    44,    68,    -1,    -1,
      87,    44,    14,    47,    68,    -1,    87,    44,    14,    47,
      12,    -1,    89,    -1,    90,    -1,    91,    -1,    92,    -1,
      93,    -1,    94,    -1,    95,    -1,    96,    -1,    38,    71,
      -1,    41,    38,    71,    -1,    19,    38,    71,    -1,    89,
      44,    71,    -1,    26,    71,    -1,    41,    26,    71,    -1,
      19,    26,    71,    -1,    90,    44,    71,    -1,    37,    71,
      -1,    41,    37,    71,    -1,    19,    37,    -1,    91,    44,
      71,    -1,    22,    71,    -1,    41,    22,    71,    -1,    19,
      22,    71,    -1,    92,    44,    71,    -1,    29,    71,    -1,
      41,    29,    71,    -1,    19,    29,    71,    -1,    93,    44,
      71,    -1,    36,    71,    -1,    41,    36,    71,    -1,    19,
      36,    71,    -1,    94,    44,    71,    -1,    17,    71,    -1,
      41,    17,    71,    -1,    19,    17,    71,    -1,    95,    44,
      71,    -1,    41,    71,    -1,    19,    71,    -1,    96,    44,
      71,    -1,    40,    68,    47,    78,    -1,    40,    68,    -1,
      99,    -1,    70,    48,    99,    -1,    20,    68,    -1,    20,
     100,    -1,   100,    68,    -1,    20,   100,    68,    -1,   100,
      -1,    68,    20,    -1,   100,    68,    20,    -1,    -1,    15,
      78,   102,   107,   106,   108,    -1,    -1,    15,    78,    13,
      78,   103,   107,   106,   108,    -1,    -1,    70,    48,    15,
      78,   104,   107,   106,   108,    -1,    -1,    70,    48,    15,
      78,    13,    78,   105,   107,   106,   108,    -1,    48,    -1,
     106,    55,    -1,    -1,   107,    44,    14,    47,    78,    -1,
      68,    47,    78,    -1,    68,    47,    78,    48,   108,    -1,
      68,    47,    78,    48,    55,   108,    -1,    68,    47,    78,
      44,   108,    -1,    68,    47,    78,    44,    55,   108,    -1,
      21,    68,    -1,   109,    44,    68,    -1,    78,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   105,   106,   107,   108,   109,   112,   115,
     115,   121,   121,   127,   128,   131,   132,   135,   135,   136,
     137,   140,   141,   142,   152,   153,   154,   157,   158,   164,
     167,   170,   171,   174,   175,   176,   179,   180,   183,   184,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     199,   207,   217,   218,   219,   220,   221,   225,   226,   227,
     228,   229,   230,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   255,   256,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   270,
     271,   274,   275,   276,   277,   278,   279,   280,   281,   284,
     284,   285,   285,   289,   290,   291,   295,   296,   300,   304,
     305,   306,   307,   308,   309,   311,   312,   315,   316,   317,
     318,   321,   322,   323,   324,   327,   328,   329,   330,   333,
     334,   335,   336,   339,   340,   341,   342,   345,   346,   347,
     348,   352,   353,   354,   355,   358,   359,   360,   363,   366,
     369,   370,   373,   374,   375,   376,   377,   380,   381,   384,
     384,   385,   385,   386,   386,   387,   387,   390,   391,   394,
     395,   402,   403,   404,   405,   406,   409,   410,   413
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "\"'unit'\"", "\"'var'\"", "'('", "')'", "','", "'.'", "'$'", "'='",
  "':'", "';'", "'>'", "'<'", "'!'", "'{'", "'}'", "'\\n'", "'\\''",
  "$accept", "input", "import", "module", "$@1", "$@2", "maybemain",
  "function", "$@3", "spacedformula", "variableexportlist", "variable",
  "variablein", "varmaybein", "varmaybeis", "maybein", "modulebody",
  "modulepart", "reaction", "reactantList", "reactionDivider", "formula",
  "commaformula", "mathThing", "lineend", "assignment", "submodule", "$@4",
  "$@5", "variableimportlist", "submodifications", "varinitialize",
  "specinit", "formulainit", "reactioninit", "dnainit", "geneinit",
  "operatorinit", "compartmentinit", "varconstinit", "unitinit", "dnadef",
  "dnastrand", "dnamiddle", "event", "$@6", "$@7", "$@8", "$@9",
  "colonret", "eventmodifications", "assignmentlist", "deletion",
  "unitdef", 0
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
     287,   288,    40,    41,    44,    46,    36,    61,    58,    59,
      62,    60,    33,   123,   125,    10,    39
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    58,    58,    59,    61,
      60,    62,    60,    60,    60,    63,    63,    65,    64,    64,
      64,    66,    66,    66,    67,    67,    67,    68,    68,    68,
      69,    70,    70,    71,    71,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    75,    76,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    84,
      83,    85,    83,    86,    86,    86,    87,    87,    87,    88,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    89,
      89,    90,    90,    90,    90,    91,    91,    91,    91,    92,
      92,    92,    92,    93,    93,    93,    93,    94,    94,    94,
      94,    95,    95,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,    99,    99,    99,   100,   100,   102,
     101,   103,   101,   104,   101,   105,   101,   106,   106,   107,
     107,   108,   108,   108,   108,   108,   109,   109,   110
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     0,
       9,     0,     6,     2,     2,     0,     1,     0,     8,     2,
       2,     1,     2,     2,     0,     1,     3,     1,     3,     2,
       3,     1,     1,     1,     3,     3,     0,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       8,     6,     0,     1,     2,     3,     4,     2,     2,     2,
       2,     1,     2,     0,     2,     2,     2,     2,     2,     4,
       2,     3,     3,     3,     3,     3,     3,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     5,     5,     3,     4,     4,     3,     0,
       9,     0,     7,     0,     1,     3,     0,     5,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       3,     2,     3,     3,     3,     2,     3,     2,     3,     2,
       3,     3,     3,     2,     3,     3,     3,     2,     3,     3,
       3,     2,     3,     3,     3,     2,     2,     3,     4,     2,
       1,     3,     2,     2,     2,     3,     1,     2,     3,     0,
       6,     0,     8,     0,     8,     0,    10,     1,     2,     0,
       5,     3,     5,     6,     5,     6,     2,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     7,     0,    27,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,    89,    90,     3,     4,     6,    31,
      48,     0,     5,     0,     0,    49,     0,     0,     0,   109,
     110,   111,   112,   113,   114,   115,   116,     0,     0,   150,
     156,     0,     0,    54,   159,    31,    32,    33,   141,     0,
       0,     0,     0,     0,   127,     0,   146,   152,   153,   176,
     129,   121,    17,    20,    19,   133,     8,   101,    16,    14,
      13,     0,   137,   125,   117,   149,     0,     0,     0,     0,
       0,     0,     0,   145,    29,   157,     0,     0,     0,    63,
       0,    63,    52,     0,    40,     0,     0,    61,     0,    52,
      41,    42,    43,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    44,   154,    45,     0,    47,     0,     0,    81,
      80,    82,    83,    88,    84,    66,    63,    67,    64,    68,
      63,     0,    85,    86,    87,    63,    65,    70,   169,    63,
      63,   143,   131,   123,   135,   139,   119,   155,     0,   103,
      11,    63,   142,   130,   122,   134,   138,   126,   118,    30,
      28,     0,   178,    98,    95,    92,    91,    63,     0,    63,
      53,     0,   151,    63,    58,    60,    59,    57,     0,    55,
      62,    53,     0,   120,   124,   128,   132,   136,   140,   144,
     147,   158,   177,    75,    76,   161,    78,     0,    73,    72,
      71,    74,     0,     0,    35,    34,    24,   104,     0,     0,
      52,   148,     0,     0,   163,    99,    96,    52,    97,    56,
      63,   169,    69,    63,    77,     0,   167,     0,     0,    25,
     106,     0,    24,    52,    38,    94,    93,    63,   169,   103,
       0,    36,     0,    79,     0,   168,     0,   160,    63,     0,
      36,   105,     0,    12,    39,   165,     0,     0,    63,     0,
      51,     0,    63,    63,     0,    21,    63,    26,     0,   102,
      52,   169,     0,   106,    36,    37,   162,   170,   171,    18,
      23,    22,     0,    52,     0,   164,    36,    50,     0,     0,
       0,    10,     0,   100,     0,   174,     0,   172,   108,   107,
     166,   175,   173
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,    27,   219,   220,    81,    28,   158,   274,
     238,    55,    56,    57,    58,   270,   243,   244,    33,    34,
     109,   172,   207,   147,    35,    36,    37,   249,   159,   218,
     260,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,   148,   231,   248,   281,   237,
     213,   257,    52,   173
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -248
static const yytype_int16 yypact[] =
{
    -248,   351,  -248,  -248,    30,  -248,  -248,    30,   405,    30,
      30,    30,    30,   119,    30,   -18,   -10,     2,    30,    30,
      30,    30,   455,    30,  -248,  -248,  -248,  -248,  -248,   100,
      -2,   126,  -248,   142,     9,  -248,   142,   142,   142,     6,
      33,    87,   113,   139,   144,   156,   164,   142,   142,  -248,
      30,   142,   146,   168,   403,    59,  -248,    43,  -248,    30,
      30,    30,    30,    30,  -248,    30,  -248,    -7,    30,   168,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,   204,  -248,  -248,  -248,   131,    30,    30,    30,    30,
      30,    30,    30,  -248,   168,  -248,    30,   215,    30,  -248,
     104,  -248,   165,   183,  -248,    21,   135,  -248,   216,   140,
    -248,  -248,  -248,    30,    30,    30,    30,    30,    30,    30,
      30,  -248,  -248,     3,  -248,    30,  -248,   230,   232,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,   188,   192,   196,   198,  -248,   168,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,     3,   205,    30,
     209,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,   168,
    -248,   -15,   553,  -248,  -248,    69,   553,  -248,   211,  -248,
      -7,     9,  -248,  -248,  -248,  -248,  -248,  -248,    30,   168,
    -248,   168,    -6,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,   168,  -248,  -248,   553,   553,   149,  -248,  -248,
    -248,  -248,   201,    44,  -248,   553,    30,   168,   159,   217,
     673,   553,    30,    30,   453,  -248,   553,   140,   553,   168,
    -248,  -248,  -248,  -248,  -248,   243,  -248,    19,   163,   168,
    -248,    30,    30,   595,  -248,   168,   168,  -248,  -248,    30,
      10,   503,    44,   553,   199,  -248,   151,  -248,   142,    30,
      -5,   168,   166,  -248,  -248,   553,    44,   173,  -248,    30,
    -248,    19,  -248,  -248,   106,   553,   142,   168,   246,  -248,
     673,  -248,    19,  -248,   503,   168,  -248,   553,    75,  -248,
    -248,   142,   214,   634,    44,  -248,    -5,  -248,    20,    89,
     148,  -248,    19,  -248,    30,  -248,    30,  -248,  -248,   168,
    -248,  -248,  -248
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,   -13,
      24,    -1,    11,    13,    50,  -112,   -11,     1,  -248,   -98,
      91,    88,  -248,  -248,     4,  -248,  -248,  -248,  -248,    26,
       5,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,   171,   267,  -248,  -248,  -248,  -248,  -248,  -247,
    -224,    18,  -248,   -49
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -54
static const yytype_int16 yytable[] =
{
      29,   106,    32,    53,   181,   271,   -32,   252,    67,    69,
      78,   192,    30,    95,    31,   105,   106,   106,   222,   282,
      85,    76,    94,   201,   266,   107,   184,   269,   -32,    79,
      97,   -32,    77,     5,     5,   185,    80,   104,    97,   278,
     110,   111,   112,   230,     5,   -32,   -32,   302,    97,   123,
     113,   121,   122,   146,   -32,   124,   126,   294,    66,   268,
     108,    70,    71,   186,    75,    23,    23,   157,    82,    83,
      84,   187,    93,   149,   255,   304,    23,   114,   223,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   235,     5,
     150,    96,   236,   137,    54,   169,   212,   171,   138,   175,
     214,   180,   139,     5,    97,   189,   -53,   -53,   191,   151,
     152,   153,   154,   155,    97,   156,   -53,   140,     5,   298,
      95,    23,   141,   299,   202,   142,   143,   144,   145,   250,
     289,   115,    96,    72,    98,    23,   162,   163,   164,   165,
     166,   167,   168,   174,   306,    97,    73,   188,   279,     5,
      23,   -53,     4,    74,     5,    24,    99,   116,   217,   100,
     308,    25,     5,   193,   194,   195,   196,   197,   198,   199,
     200,   146,   297,   101,   102,   146,    97,     4,   161,     5,
     177,    23,   103,   117,   303,     9,    23,   229,   118,   176,
     125,    24,   232,   233,    23,    24,    97,    25,   273,   178,
     119,    25,   240,   241,   146,   146,   258,   259,   120,   280,
     259,    23,   179,    97,   146,   239,   283,   241,   160,    29,
     146,   245,   246,   146,   205,   146,   191,   146,   206,   170,
     183,    30,   190,    31,   203,   208,   256,   204,   215,   209,
     261,   239,    29,   210,   264,   211,   272,   216,   217,   221,
     146,    -9,   146,   225,    30,   234,    31,   254,   277,   242,
     292,   300,   276,   291,   146,   224,   262,   226,   285,   293,
     256,   228,   227,   182,   146,   267,    68,     0,   290,    29,
     276,   256,     0,   146,     0,     0,   146,   146,   296,   286,
       0,    30,    29,    31,   264,   290,     0,   256,   256,   309,
     295,   256,     0,   256,    30,   256,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   305,   307,   251,     0,
     310,   253,   311,     0,   312,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,     0,     0,     0,
       0,     2,     3,     0,     0,     0,   284,   -52,   -52,     0,
     287,   288,     0,     4,   275,     5,     6,   -52,     7,     0,
       8,     9,    10,    11,     0,     0,     0,    12,     0,    13,
      14,     0,    15,     0,     0,    16,    17,    18,    19,    20,
       0,    21,    22,     0,     0,     0,     0,    23,     0,     0,
      24,     0,   -52,     0,     0,     0,    25,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,     5,     0,     5,
       0,   137,    59,     0,     0,     0,   138,    60,     0,     0,
     139,    61,     0,     0,    62,     0,     0,     0,     0,     0,
       0,    63,    64,    65,     0,   140,     0,     0,     0,    23,
     141,    23,     0,   142,   143,   144,   145,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   247,     5,     0,     5,
       0,   137,    86,     0,     0,     0,   138,    87,     0,     0,
     139,    88,     0,     0,    89,     0,     0,     0,     0,     0,
       0,    90,    91,    92,     0,   140,     0,     0,     0,    23,
     141,    23,     0,   142,   143,   144,   145,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     5,     0,     0,
       0,   137,     0,     0,     0,     0,   138,     0,     0,     0,
     139,     0,     0,     0,     0,   269,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   140,     0,     0,     0,    23,
     141,     0,     0,   142,   143,   144,   145,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     5,     0,     0,
       0,   137,     0,     0,     0,     0,   138,     0,     0,     0,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   140,     0,     0,     0,    23,
     141,     0,     0,   142,   143,   144,   145,     4,     0,     5,
       6,     0,     7,     0,     8,     9,    10,    11,     0,   263,
       0,    12,     0,     0,    14,     0,     0,     0,     0,    16,
       0,    18,    19,    20,     0,    21,    22,     0,     0,     0,
       0,    23,     0,     0,    24,     0,     4,     0,     5,     6,
      25,     7,     0,     8,     9,    10,    11,     0,   301,     0,
      12,     0,     0,    14,     0,     0,     0,     0,    16,     0,
      18,    19,    20,     0,    21,    22,     0,     0,     0,     0,
      23,     0,     0,    24,     0,     4,     0,     5,     6,    25,
       7,     0,     8,     9,    10,    11,     0,     0,     0,    12,
       0,     0,    14,     0,     0,     0,     0,    16,     0,    18,
      19,    20,     0,    21,    22,     0,     0,     0,     0,    23,
       0,     0,    24,     0,     0,     0,     0,     0,    25
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-248))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,     7,     1,     4,   102,   252,     8,   231,     9,    10,
       8,   109,     1,    20,     1,     6,     7,     7,    33,   266,
      21,    39,    23,    20,   248,    16,     5,    32,    30,    27,
      45,    33,    42,    14,    14,    14,    34,    33,    45,    44,
      36,    37,    38,    49,    14,    47,    48,   294,    45,    50,
      44,    47,    48,    54,    56,    51,    52,   281,     8,    49,
      51,    11,    12,    42,    14,    46,    46,    68,    18,    19,
      20,    50,    22,    30,    55,    55,    46,    44,     9,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    44,    14,
      47,    32,    48,    18,     6,    96,   145,    98,    23,   100,
     149,   102,    27,    14,    45,   106,     6,     7,   109,    59,
      60,    61,    62,    63,    45,    65,    16,    42,    14,    44,
      20,    46,    47,    48,   125,    50,    51,    52,    53,   227,
      24,    44,    32,    14,     8,    46,    86,    87,    88,    89,
      90,    91,    92,    39,    55,    45,    27,    12,   260,    14,
      46,    51,    12,    34,    14,    49,    30,    44,   159,    33,
      12,    55,    14,   113,   114,   115,   116,   117,   118,   119,
     120,   172,   284,    47,    48,   176,    45,    12,    47,    14,
      15,    46,    56,    44,   296,    20,    46,   188,    44,   101,
      44,    49,    43,    44,    46,    49,    45,    55,    47,    34,
      44,    55,    43,    44,   205,   206,    43,    44,    44,    43,
      44,    46,    47,    45,   215,   216,    43,    44,    14,   220,
     221,   222,   223,   224,   136,   226,   227,   228,   140,    14,
      47,   220,    16,   220,     4,    47,   237,     5,   150,    47,
     241,   242,   243,    47,   243,    47,    47,    42,   249,   161,
     251,    42,   253,    42,   243,    54,   243,    14,   259,    42,
      14,    47,   258,   276,   265,   177,   242,   179,   269,   280,
     271,   183,   181,   102,   275,   249,     9,    -1,   274,   280,
     276,   282,    -1,   284,    -1,    -1,   287,   288,   283,   271,
      -1,   280,   293,   280,   293,   291,    -1,   298,   299,   300,
     282,   302,    -1,   304,   293,   306,   293,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   298,   299,   230,    -1,
     302,   233,   304,    -1,   306,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,     0,     1,    -1,    -1,    -1,   268,     6,     7,    -1,
     272,   273,    -1,    12,   276,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    -1,    -1,    -1,    26,    -1,    28,
      29,    -1,    31,    -1,    -1,    34,    35,    36,    37,    38,
      -1,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      49,    -1,    51,    -1,    -1,    -1,    55,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    14,
      -1,    18,    17,    -1,    -1,    -1,    23,    22,    -1,    -1,
      27,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    42,    -1,    -1,    -1,    46,
      47,    46,    -1,    50,    51,    52,    53,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    14,
      -1,    18,    17,    -1,    -1,    -1,    23,    22,    -1,    -1,
      27,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    42,    -1,    -1,    -1,    46,
      47,    46,    -1,    50,    51,    52,    53,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      47,    -1,    -1,    50,    51,    52,    53,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      47,    -1,    -1,    50,    51,    52,    53,    12,    -1,    14,
      15,    -1,    17,    -1,    19,    20,    21,    22,    -1,    24,
      -1,    26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
      -1,    36,    37,    38,    -1,    40,    41,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    -1,    12,    -1,    14,    15,
      55,    17,    -1,    19,    20,    21,    22,    -1,    24,    -1,
      26,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,
      36,    37,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    49,    -1,    12,    -1,    14,    15,    55,
      17,    -1,    19,    20,    21,    22,    -1,    -1,    -1,    26,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    55
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,     0,     1,    12,    14,    15,    17,    19,    20,
      21,    22,    26,    28,    29,    31,    34,    35,    36,    37,
      38,    40,    41,    46,    49,    55,    59,    60,    64,    68,
      69,    70,    74,    75,    76,    81,    82,    83,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   109,    68,    78,    68,    69,    70,    71,    17,
      22,    26,    29,    36,    37,    38,    71,    68,   100,    68,
      71,    71,    14,    27,    34,    71,    39,    42,     8,    27,
      34,    63,    71,    71,    71,    68,    17,    22,    26,    29,
      36,    37,    38,    71,    68,    20,    32,    45,     8,    30,
      33,    47,    48,    56,    81,     6,     7,    16,    51,    77,
      81,    81,    81,    44,    44,    44,    44,    44,    44,    44,
      44,    81,    81,    68,    81,    44,    81,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    18,    23,    27,
      42,    47,    50,    51,    52,    53,    68,    80,   102,    30,
      47,    71,    71,    71,    71,    71,    71,    68,    65,    85,
      14,    47,    71,    71,    71,    71,    71,    71,    71,    68,
      14,    68,    78,   110,    39,    68,    78,    15,    34,    47,
      68,    76,    99,    47,     5,    14,    42,    50,    12,    68,
      16,    68,    76,    71,    71,    71,    71,    71,    71,    71,
      71,    20,    68,     4,     5,    78,    78,    79,    47,    47,
      47,    47,   110,   107,   110,    78,    42,    68,    86,    61,
      62,    78,    33,     9,    78,    42,    78,    77,    78,    68,
      49,   103,    43,    44,    54,    44,    48,   106,    67,    68,
      43,    44,    42,    73,    74,    68,    68,    13,   104,    84,
      76,    78,   107,    78,    14,    55,    68,   108,    43,    44,
      87,    68,    67,    24,    74,    78,   107,    86,    49,    32,
      72,   106,    47,    47,    66,    78,    81,    68,    44,    72,
      43,   105,   106,    43,    78,    68,   108,    78,    78,    24,
      81,    66,    14,    73,   107,   108,    87,    72,    44,    48,
      47,    24,   106,    72,    55,   108,    55,   108,    12,    68,
     108,   108,   108
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/* Line 1806 of yacc.c  */
#line 105 "src/antimony.ypp"
    {}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 106 "src/antimony.ypp"
    { /*cout << endl << $2->ToString() << endl << endl;*/ }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 107 "src/antimony.ypp"
    {}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 108 "src/antimony.ypp"
    {}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 109 "src/antimony.ypp"
    {YYABORT;}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 112 "src/antimony.ypp"
    { if (g_registry.OpenFile(*((yyvsp[(2) - (2)].word)))==0) YYABORT;}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 115 "src/antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(3) - (3)].word), (yyvsp[(2) - (3)].maybemain));}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 116 "src/antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 121 "src/antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(3) - (3)].word), (yyvsp[(2) - (3)].maybemain));}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 122 "src/antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 127 "src/antimony.ypp"
    {g_registry.SetError("module '" + *((yyvsp[(2) - (2)].word)) + "' already defined."); YYABORT;}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 128 "src/antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a module because it is already a defined function."); YYABORT;}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 131 "src/antimony.ypp"
    {(yyval.maybemain) = false;}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 132 "src/antimony.ypp"
    {(yyval.maybemain) = true;}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 135 "src/antimony.ypp"
    {g_registry.NewUserFunction((yyvsp[(2) - (2)].word));}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 135 "src/antimony.ypp"
    {if (g_registry.SetUserFunction((yyvsp[(7) - (8)].formula))) YYABORT;}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 136 "src/antimony.ypp"
    {g_registry.SetError("Cannot use '" + *((yyvsp[(2) - (2)].word)) +"' as a function name because it is already the name of a module."); YYABORT;}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 137 "src/antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a new function because it is already a defined function."); YYABORT;}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 140 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (1)].formula);}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 141 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(2) - (2)].formula);}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 142 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula);}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 152 "src/antimony.ypp"
    {}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 153 "src/antimony.ypp"
    {if (g_registry.AddVariableToCurrentExportList((yyvsp[(1) - (1)].variable))) YYABORT; }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 154 "src/antimony.ypp"
    { if (g_registry.AddVariableToCurrentExportList((yyvsp[(3) - (3)].variable))) YYABORT; }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 157 "src/antimony.ypp"
    {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[(1) - (1)].word)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 158 "src/antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable)->GetSubVariable((yyvsp[(3) - (3)].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[(3) - (3)].word)) + "' is not a subvariable of '" + (yyvsp[(1) - (3)].variable)->GetNameDelimitedBy('.') + "'.");
                    YYABORT;
                  }
                }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 164 "src/antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 167 "src/antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetCompartment((yyvsp[(3) - (3)].variable))) YYABORT; (yyval.variable) = (yyvsp[(1) - (3)].variable);}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 170 "src/antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 171 "src/antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 174 "src/antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 175 "src/antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable); if ((yyvsp[(1) - (3)].variable)->SetFormula((yyvsp[(3) - (3)].formula))) YYABORT; }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 176 "src/antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable); if ((yyvsp[(1) - (3)].variable)->SetUnit((yyvsp[(3) - (3)].variable))) YYABORT; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 179 "src/antimony.ypp"
    {(yyval.variable) = NULL;}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 180 "src/antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable);}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 183 "src/antimony.ypp"
    {}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 184 "src/antimony.ypp"
    {}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 187 "src/antimony.ypp"
    {}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 188 "src/antimony.ypp"
    {}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 189 "src/antimony.ypp"
    {}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 190 "src/antimony.ypp"
    {}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 191 "src/antimony.ypp"
    {}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 192 "src/antimony.ypp"
    {}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 193 "src/antimony.ypp"
    {}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 194 "src/antimony.ypp"
    {}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 195 "src/antimony.ypp"
    {}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 196 "src/antimony.ypp"
    {}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 200 "src/antimony.ypp"
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[(4) - (8)].reactionDivider), (yyvsp[(7) - (8)].formula), (yyvsp[(1) - (8)].variable));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[(8) - (8)].variable) != NULL) {
                    if ((yyvsp[(1) - (8)].variable)->SetCompartment((yyvsp[(8) - (8)].variable))) YYABORT;
                  }
                }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 208 "src/antimony.ypp"
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[(2) - (6)].reactionDivider), (yyvsp[(5) - (6)].formula));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[(6) - (6)].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[(6) - (6)].variable))) YYABORT;
                  }
                }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 217 "src/antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 218 "src/antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(1) - (1)].variable)); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 219 "src/antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(2) - (2)].variable), (yyvsp[(1) - (2)].num)); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 220 "src/antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (3)].reactantList); (yyvsp[(1) - (3)].reactantList)->AddReactant((yyvsp[(3) - (3)].variable)); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 221 "src/antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (4)].reactantList); (yyvsp[(1) - (4)].reactantList)->AddReactant((yyvsp[(4) - (4)].variable), (yyvsp[(3) - (4)].num)); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 225 "src/antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 226 "src/antimony.ypp"
    {(yyval.reactionDivider) = rdInhibits;}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 227 "src/antimony.ypp"
    {(yyval.reactionDivider) = rdInfluences;}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 228 "src/antimony.ypp"
    {if (*(yyvsp[(2) - (2)].word) != "o") {g_registry.SetError("'-" + *(yyvsp[(2) - (2)].word) + "' is not a valid set of characters to demark reactions.  Try '->' for reactions, and '-|', '-o', and '-(' for interactions."); YYABORT;} (yyval.reactionDivider) = rdActivates;}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 229 "src/antimony.ypp"
    {(yyval.reactionDivider) = rdBecomesIrreversibly;}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 230 "src/antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 233 "src/antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 234 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddEllipses();}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 235 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddVariable((yyvsp[(2) - (2)].variable)); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 236 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddNum((yyvsp[(2) - (2)].num)); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 237 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddText((yyvsp[(2) - (2)].word)); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 238 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddText((yyvsp[(2) - (2)].word)); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 239 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (4)].formula); (yyvsp[(3) - (4)].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[(3) - (4)].formula)); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 240 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddMathThing((yyvsp[(2) - (2)].character)); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 241 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('<'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 242 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('>'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 243 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('='); (yyvsp[(1) - (3)].formula)->AddMathThing('='); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 244 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('!'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 245 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 246 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 248 "src/antimony.ypp"
    {
                  //Need to create a variable to be this unit definition, or find one that already has this unit definition, and then use that name.
                  (yyval.formula) = (yyvsp[(1) - (4)].formula);
                  (yyval.formula)->AddVariable((yyvsp[(3) - (4)].variable));
                }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 255 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (1)].formula);}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 256 "src/antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[(3) - (3)].formula)); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 259 "src/antimony.ypp"
    {(yyval.character) = '+';}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 260 "src/antimony.ypp"
    {(yyval.character) = '-';}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 261 "src/antimony.ypp"
    {(yyval.character) = '*';}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 262 "src/antimony.ypp"
    {(yyval.character) = '/';}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 263 "src/antimony.ypp"
    {(yyval.character) = '^';}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 264 "src/antimony.ypp"
    {(yyval.character) = '>';}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 265 "src/antimony.ypp"
    {(yyval.character) = '<';}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 266 "src/antimony.ypp"
    {(yyval.character) = '!';}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 267 "src/antimony.ypp"
    {(yyval.character) = '%';}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 270 "src/antimony.ypp"
    {}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 271 "src/antimony.ypp"
    {}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 274 "src/antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetFormula((yyvsp[(3) - (3)].formula))) YYABORT; }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 275 "src/antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->Synchronize((yyvsp[(3) - (3)].variable), NULL)) YYABORT;}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 276 "src/antimony.ypp"
    {if ((yyvsp[(1) - (5)].variable)->Synchronize((yyvsp[(3) - (5)].variable), (yyvsp[(5) - (5)].variable))) YYABORT;}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 277 "src/antimony.ypp"
    {if ((yyvsp[(1) - (5)].variable)->Synchronize((yyvsp[(5) - (5)].variable), (yyvsp[(3) - (5)].variable))) YYABORT;}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 278 "src/antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetDisplayName(*((yyvsp[(3) - (3)].word)))) YYABORT;}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 279 "src/antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetAssignmentRule((yyvsp[(4) - (4)].formula))) YYABORT;}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 280 "src/antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetRateRule((yyvsp[(4) - (4)].formula))) YYABORT;}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 281 "src/antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetUnit((yyvsp[(3) - (3)].variable))) YYABORT; }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 284 "src/antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetModule((yyvsp[(3) - (4)].word))) YYABORT;}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 284 "src/antimony.ypp"
    {if ((yyvsp[(9) - (9)].variable) != NULL) {if ((yyvsp[(1) - (9)].variable)->SetCompartment((yyvsp[(9) - (9)].variable))) YYABORT;}}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 285 "src/antimony.ypp"
    {if(g_registry.CurrentModule()->SetModule((yyvsp[(1) - (2)].word))) YYABORT;}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 285 "src/antimony.ypp"
    {if ((yyvsp[(7) - (7)].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[(7) - (7)].variable))) YYABORT;}}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 289 "src/antimony.ypp"
    {}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 290 "src/antimony.ypp"
    {if (g_registry.AddVariableToCurrentImportList((yyvsp[(1) - (1)].variable))) YYABORT; }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 291 "src/antimony.ypp"
    { if (g_registry.AddVariableToCurrentImportList((yyvsp[(3) - (3)].variable))) YYABORT; }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 295 "src/antimony.ypp"
    {}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 296 "src/antimony.ypp"
    {if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[(5) - (5)].variable));}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[(5) - (5)].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[(3) - (5)].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 300 "src/antimony.ypp"
    {if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[(5) - (5)].num));}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[(5) - (5)].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[(3) - (5)].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 304 "src/antimony.ypp"
    { }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 305 "src/antimony.ypp"
    { }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 306 "src/antimony.ypp"
    { }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 307 "src/antimony.ypp"
    { }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 308 "src/antimony.ypp"
    { }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 309 "src/antimony.ypp"
    { }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 311 "src/antimony.ypp"
    { }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 312 "src/antimony.ypp"
    { }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 315 "src/antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varSpeciesUndef)) YYABORT; }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 316 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 317 "src/antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 318 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 321 "src/antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaUndef)) YYABORT; }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 322 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 323 "src/antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 324 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 327 "src/antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varReactionUndef)) YYABORT; }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 328 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 329 "src/antimony.ypp"
    {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 330 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 333 "src/antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varDNA)) YYABORT; }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 334 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 335 "src/antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 336 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 339 "src/antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varReactionGene)) YYABORT; }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 340 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 341 "src/antimony.ypp"
    {g_registry.SetError("Genes may not be set 'const'."); YYABORT; }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 342 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 345 "src/antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaOperator)) YYABORT; }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 346 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 347 "src/antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 348 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 352 "src/antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varCompartment)) YYABORT; }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 353 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 354 "src/antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 355 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 358 "src/antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(2) - (2)].variable)->SetRegConst();}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 359 "src/antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(2) - (2)].variable)->SetRegConst();}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 360 "src/antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst();}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 363 "src/antimony.ypp"
    {if ((yyvsp[(2) - (4)].variable)->SetType(varUnitDefinition)) YYABORT;
                                               if ((yyvsp[(4) - (4)].formula)->MakeAllVariablesUnits()) YYABORT;
                                               if ((yyvsp[(2) - (4)].variable)->GetUnitDef()->SetFromFormula((yyvsp[(4) - (4)].formula))) YYABORT;}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 366 "src/antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varUnitDefinition)) YYABORT;}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 369 "src/antimony.ypp"
    {if (g_registry.SaveWorkingStrand()) YYABORT;}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 370 "src/antimony.ypp"
    {if (g_registry.SetStrandAs((yyvsp[(1) - (3)].variable))) YYABORT;}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 373 "src/antimony.ypp"
    {if (g_registry.SetNewUpstreamOpen((yyvsp[(2) - (2)].variable))) YYABORT;}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 374 "src/antimony.ypp"
    {g_registry.SetOpenUpstream(); }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 375 "src/antimony.ypp"
    {if (g_registry.SetDownstreamEnd((yyvsp[(2) - (2)].variable))) YYABORT;}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 376 "src/antimony.ypp"
    {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[(3) - (3)].variable))) YYABORT;}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 377 "src/antimony.ypp"
    { }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 380 "src/antimony.ypp"
    {if (g_registry.SetNewDownstreamOpen((yyvsp[(1) - (2)].variable))) YYABORT;}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 381 "src/antimony.ypp"
    {if (g_registry.SetDownstreamOpen((yyvsp[(2) - (3)].variable))) YYABORT;}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 384 "src/antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(2) - (2)].formula))) YYABORT;}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 384 "src/antimony.ypp"
    {}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 385 "src/antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(2) - (4)].formula), (yyvsp[(4) - (4)].formula))) YYABORT;}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 385 "src/antimony.ypp"
    {}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 386 "src/antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (4)].formula), (yyvsp[(1) - (4)].variable))) YYABORT;}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 386 "src/antimony.ypp"
    {}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 387 "src/antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (6)].formula), (yyvsp[(6) - (6)].formula), (yyvsp[(1) - (6)].variable))) YYABORT;}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 387 "src/antimony.ypp"
    {}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 390 "src/antimony.ypp"
    {}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 391 "src/antimony.ypp"
    {}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 394 "src/antimony.ypp"
    {}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 395 "src/antimony.ypp"
    {if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[(5) - (5)].formula));}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[(3) - (5)].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;}}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 402 "src/antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (3)].variable), (yyvsp[(3) - (3)].formula))) YYABORT;}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 403 "src/antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (5)].variable), (yyvsp[(3) - (5)].formula))) YYABORT;}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 404 "src/antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (6)].variable), (yyvsp[(3) - (6)].formula))) YYABORT;}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 405 "src/antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (5)].variable), (yyvsp[(3) - (5)].formula))) YYABORT;}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 406 "src/antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (6)].variable), (yyvsp[(3) - (6)].formula))) YYABORT;}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 409 "src/antimony.ypp"
    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[(2) - (2)].variable))) YYABORT;}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 410 "src/antimony.ypp"
    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[(3) - (3)].variable))) YYABORT;}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 413 "src/antimony.ypp"
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



/* Line 1806 of yacc.c  */
#line 3108 "src/antimony.tab.cpp"
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



/* Line 2067 of yacc.c  */
#line 427 "src/antimony.ypp"



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
      g_registry.CurrentModule()->Finalize();
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
    return -1;
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
    if (cc == '\r' || cc == '\n') {
      while ((cc == '\r' || cc == '\n') && !g_registry.input->eof()) {
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

