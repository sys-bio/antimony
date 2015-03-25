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
     CONSTRAINTWORD = 267,
     DASHES = 268,
     DELETEWORD = 269,
     DNA = 270,
     ELLIPSES = 271,
     END = 272,
     EVENT = 273,
     FORMULA = 274,
     FUNCTION = 275,
     FUNCTIONWORD = 276,
     GENE = 277,
     HASWORD = 278,
     IMPORT = 279,
     INWORD = 280,
     IS = 281,
     MODNAME = 282,
     MODULE = 283,
     OPERATOR = 284,
     REACTION = 285,
     SPECIES = 286,
     TEXTSTRING = 287,
     UNITWORD = 288,
     VARWORD = 289,
     ERROR = 290
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
  constraint_type inequality;


/* Line 387 of yacc.c  */
#line 202 "antimony.tab.cpp"
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
#line 230 "antimony.tab.cpp"

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
#define YYLAST   853

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  195
/* YYNRULES -- Number of states.  */
#define YYNSTATES  349

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      58,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,     2,    48,    10,     4,    51,
      44,    45,     8,     7,    46,     6,    47,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    52,
      54,    49,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    11,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     5,    57,     2,     2,     2,     2,
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
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    19,    22,
      25,    26,    36,    37,    44,    47,    50,    51,    53,    54,
      63,    66,    69,    71,    74,    77,    78,    80,    84,    86,
      90,    93,    97,    99,   101,   103,   107,   112,   117,   121,
     122,   125,   127,   130,   133,   136,   139,   142,   145,   148,
     151,   154,   156,   159,   161,   170,   177,   178,   180,   183,
     187,   192,   195,   198,   201,   204,   206,   209,   210,   213,
     216,   219,   222,   225,   230,   233,   237,   241,   245,   249,
     253,   257,   262,   264,   268,   270,   272,   274,   276,   278,
     280,   282,   284,   286,   288,   290,   294,   298,   304,   310,
     314,   319,   324,   328,   329,   339,   340,   348,   349,   351,
     355,   357,   361,   362,   368,   374,   376,   378,   380,   382,
     384,   386,   388,   390,   393,   397,   401,   405,   408,   412,
     416,   420,   423,   427,   430,   434,   437,   441,   445,   449,
     452,   456,   460,   464,   467,   471,   475,   479,   482,   486,
     490,   494,   497,   500,   504,   509,   512,   514,   518,   521,
     524,   527,   531,   533,   536,   540,   541,   548,   549,   558,
     559,   568,   569,   580,   582,   585,   586,   592,   596,   602,
     609,   615,   622,   625,   629,   631,   635,   640,   644,   648,
     652,   657,   659,   662,   664,   667
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    -1,    60,    61,    -1,    60,    62,    -1,
      60,    76,    -1,    60,    66,    -1,    60,     1,    -1,    60,
      43,    -1,    32,    40,    -1,    -1,    36,    65,    14,    63,
      44,    69,    45,    75,    25,    -1,    -1,    36,    65,    14,
      64,    75,    25,    -1,    36,    35,    -1,    36,    28,    -1,
      -1,     8,    -1,    -1,    29,    14,    67,    44,    69,    45,
      68,    25,    -1,    29,    35,    -1,    29,    28,    -1,    80,
      -1,    83,    68,    -1,    68,    83,    -1,    -1,    70,    -1,
      69,    46,    70,    -1,    14,    -1,    70,    47,    14,    -1,
      48,    70,    -1,    70,    33,    70,    -1,    70,    -1,    71,
      -1,    72,    -1,    72,    49,    80,    -1,    72,    50,    49,
      80,    -1,    72,    51,    49,    80,    -1,    72,    31,   112,
      -1,    -1,    33,    70,    -1,    76,    -1,    75,    76,    -1,
      77,    83,    -1,    84,    83,    -1,    85,    83,    -1,    90,
      83,    -1,   100,    83,    -1,   103,    83,    -1,    99,    83,
      -1,   111,    83,    -1,    71,    -1,   113,    83,    -1,    83,
      -1,    72,    50,    78,    79,    78,    52,    80,    74,    -1,
      78,    79,    78,    52,    80,    74,    -1,    -1,    70,    -1,
      12,    70,    -1,    78,     7,    70,    -1,    78,     7,    12,
      70,    -1,     6,    53,    -1,     6,     5,    -1,     6,    44,
      -1,     6,    14,    -1,    16,    -1,    54,    16,    -1,    -1,
      80,    24,    -1,    80,    70,    -1,    80,    12,    -1,    80,
      18,    -1,    80,    28,    -1,    80,    44,    81,    45,    -1,
      80,    82,    -1,    80,    54,    49,    -1,    80,    53,    49,
      -1,    80,    49,    49,    -1,    80,    55,    49,    -1,    80,
       4,     4,    -1,    80,     5,     5,    -1,    80,    56,   112,
      57,    -1,    80,    -1,    81,    46,    80,    -1,     7,    -1,
       6,    -1,     8,    -1,     9,    -1,    11,    -1,    53,    -1,
      54,    -1,    55,    -1,    10,    -1,    52,    -1,    58,    -1,
      72,    49,    80,    -1,    72,    34,    70,    -1,    72,    34,
      70,     9,    70,    -1,    72,     8,    70,    34,    70,    -1,
      72,    34,    40,    -1,    72,    50,    49,    80,    -1,    72,
      51,    49,    80,    -1,    72,    31,   112,    -1,    -1,    72,
      50,    35,    44,    86,    88,    45,    89,    74,    -1,    -1,
      35,    44,    87,    88,    45,    89,    74,    -1,    -1,    70,
      -1,    88,    46,    70,    -1,    12,    -1,    88,    46,    12,
      -1,    -1,    89,    46,    14,    49,    70,    -1,    89,    46,
      14,    49,    12,    -1,    91,    -1,    92,    -1,    93,    -1,
      94,    -1,    95,    -1,    96,    -1,    97,    -1,    98,    -1,
      39,    73,    -1,    42,    39,    73,    -1,    19,    39,    73,
      -1,    91,    46,    73,    -1,    27,    73,    -1,    42,    27,
      73,    -1,    19,    27,    73,    -1,    92,    46,    73,    -1,
      38,    73,    -1,    42,    38,    73,    -1,    19,    38,    -1,
      93,    46,    73,    -1,    23,    73,    -1,    42,    23,    73,
      -1,    19,    23,    73,    -1,    94,    46,    73,    -1,    30,
      73,    -1,    42,    30,    73,    -1,    19,    30,    73,    -1,
      95,    46,    73,    -1,    37,    73,    -1,    42,    37,    73,
      -1,    19,    37,    73,    -1,    96,    46,    73,    -1,    17,
      73,    -1,    42,    17,    73,    -1,    19,    17,    73,    -1,
      97,    46,    73,    -1,    42,    73,    -1,    19,    73,    -1,
      98,    46,    73,    -1,    41,    70,    49,    80,    -1,    41,
      70,    -1,   101,    -1,    72,    50,   101,    -1,    21,    70,
      -1,    21,   102,    -1,   102,    70,    -1,    21,   102,    70,
      -1,   102,    -1,    70,    21,    -1,   102,    70,    21,    -1,
      -1,    15,    80,   104,   109,   108,   110,    -1,    -1,    15,
      80,    13,    80,   105,   109,   108,   110,    -1,    -1,    72,
      50,    15,    80,   106,   109,   108,   110,    -1,    -1,    72,
      50,    15,    80,    13,    80,   107,   109,   108,   110,    -1,
      50,    -1,   108,    58,    -1,    -1,   109,    46,    14,    49,
      80,    -1,    70,    49,    80,    -1,    70,    49,    80,    50,
     110,    -1,    70,    49,    80,    50,    58,   110,    -1,    70,
      49,    80,    46,   110,    -1,    70,    49,    80,    46,    58,
     110,    -1,    22,    70,    -1,   111,    46,    70,    -1,    80,
      -1,    12,   114,    80,    -1,     6,    12,   114,    80,    -1,
      18,   114,    80,    -1,    14,   114,    80,    -1,    20,    50,
      80,    -1,    20,    70,    50,    80,    -1,    54,    -1,    54,
      49,    -1,    53,    -1,    53,    49,    -1,    55,    49,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   133,   134,   135,   136,   137,   138,   141,
     144,   144,   150,   150,   156,   157,   160,   161,   164,   164,
     165,   166,   169,   170,   171,   181,   182,   183,   186,   187,
     193,   196,   199,   200,   203,   204,   205,   206,   207,   210,
     211,   214,   215,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   231,   239,   249,   250,   251,   252,
     253,   257,   258,   259,   260,   261,   262,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   287,   288,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   302,   303,   306,   307,   308,   309,   310,
     311,   312,   313,   317,   317,   318,   318,   322,   323,   324,
     325,   326,   330,   331,   335,   339,   340,   341,   342,   343,
     344,   346,   347,   350,   351,   352,   353,   356,   357,   358,
     359,   362,   363,   364,   365,   368,   369,   370,   371,   374,
     375,   376,   377,   380,   381,   382,   383,   387,   388,   389,
     390,   393,   394,   395,   398,   401,   404,   405,   408,   409,
     410,   411,   412,   415,   416,   419,   419,   420,   420,   421,
     421,   422,   422,   425,   426,   429,   430,   437,   438,   439,
     440,   441,   444,   445,   448,   463,   464,   465,   466,   467,
     468,   471,   472,   473,   474,   475
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
  "\"'constraint'\"", "\"--\"", "\"'delete'\"", "\"'DNA'\"", "\"...\"",
  "\"'end'\"", "\"'event'\"", "\"'formula'\"",
  "\"name of an existing function\"", "\"'function'\"", "\"'gene'\"",
  "\"'has'\"", "\"'import'\"", "\"'in'\"", "\"'is'\"",
  "\"name of an existing module\"", "\"'model' or 'module'\"",
  "\"'operator'\"", "\"'reaction'\"", "\"'species'\"", "\"text string\"",
  "\"'unit'\"", "\"'var'\"", "\"an error\"", "'('", "')'", "','", "'.'",
  "'$'", "'='", "':'", "'\\''", "';'", "'>'", "'<'", "'!'", "'{'", "'}'",
  "'\\n'", "$accept", "input", "import", "module", "$@1", "$@2",
  "maybemain", "function", "$@3", "spacedformula", "variableexportlist",
  "variable", "variablein", "varmaybein", "varmaybeis", "maybein",
  "modulebody", "modulepart", "reaction", "reactantList",
  "reactionDivider", "formula", "commaformula", "mathThing", "lineend",
  "assignment", "submodule", "$@4", "$@5", "variableimportlist",
  "submodifications", "varinitialize", "specinit", "formulainit",
  "reactioninit", "dnainit", "geneinit", "operatorinit", "compartmentinit",
  "varconstinit", "unitinit", "dnadef", "dnastrand", "dnamiddle", "event",
  "$@6", "$@7", "$@8", "$@9", "colonret", "eventmodifications",
  "assignmentlist", "deletion", "unitdef", "constraint", "inequality", YY_NULL
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
     287,   288,   289,   290,    40,    41,    44,    46,    36,    61,
      58,    39,    59,    62,    60,    33,   123,   125,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    60,    60,    60,    60,    60,    61,
      63,    62,    64,    62,    62,    62,    65,    65,    67,    66,
      66,    66,    68,    68,    68,    69,    69,    69,    70,    70,
      70,    71,    72,    72,    73,    73,    73,    73,    73,    74,
      74,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    77,    78,    78,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    86,    85,    87,    85,    88,    88,    88,
      88,    88,    89,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    91,    92,    92,    92,
      92,    93,    93,    93,    93,    94,    94,    94,    94,    95,
      95,    95,    95,    96,    96,    96,    96,    97,    97,    97,
      97,    98,    98,    98,    99,    99,   100,   100,   101,   101,
     101,   101,   101,   102,   102,   104,   103,   105,   103,   106,
     103,   107,   103,   108,   108,   109,   109,   110,   110,   110,
     110,   110,   111,   111,   112,   113,   113,   113,   113,   113,
     113,   114,   114,   114,   114,   114
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       0,     9,     0,     6,     2,     2,     0,     1,     0,     8,
       2,     2,     1,     2,     2,     0,     1,     3,     1,     3,
       2,     3,     1,     1,     1,     3,     4,     4,     3,     0,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     2,     1,     8,     6,     0,     1,     2,     3,
       4,     2,     2,     2,     2,     1,     2,     0,     2,     2,
       2,     2,     2,     4,     2,     3,     3,     3,     3,     3,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     5,     5,     3,
       4,     4,     3,     0,     9,     0,     7,     0,     1,     3,
       1,     3,     0,     5,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     3,     2,     3,     3,
       3,     2,     3,     2,     3,     2,     3,     3,     3,     2,
       3,     3,     3,     2,     3,     3,     3,     2,     3,     3,
       3,     2,     2,     3,     4,     2,     1,     3,     2,     2,
       2,     3,     1,     2,     3,     0,     6,     0,     8,     0,
       8,     0,    10,     1,     2,     0,     5,     3,     5,     6,
       5,     6,     2,     3,     1,     3,     4,     3,     3,     3,
       4,     1,     2,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     7,     0,     0,    28,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,     8,     0,    93,    94,
       3,     4,     6,    32,    51,     0,     5,     0,     0,    53,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,   156,   162,     0,     0,     0,     0,    28,
     193,   191,     0,    58,    67,    67,   165,    32,    33,    34,
     147,    67,     0,     0,     0,     0,     0,   133,     0,   152,
      67,     0,   158,   159,   182,   135,   127,    18,    21,    20,
     139,     9,   105,    17,    15,    14,     0,   143,   131,   123,
     155,     0,     0,     0,     0,     0,     0,     0,   151,    30,
     163,     0,     0,     0,    67,     0,    67,    56,     0,    43,
       0,     0,    65,     0,    56,    44,    45,    46,     0,     0,
       0,     0,     0,     0,     0,     0,    49,    47,   160,    48,
       0,    50,    52,    67,   194,   192,   195,   185,   188,     0,
       0,    85,    84,    86,    87,    92,    88,    70,    67,    71,
      68,    72,    67,     0,    89,    90,    91,    67,    69,    74,
     175,    67,    67,     0,     0,   187,   149,   137,   129,   141,
     145,   125,   189,    67,   161,     0,   107,    12,    67,   148,
     136,   128,   140,   144,   132,   124,    31,    29,     0,   184,
     102,    99,    96,    95,     0,    67,     0,    67,    57,     0,
     157,    67,    62,    64,    63,    61,     0,    59,    66,    57,
       0,   126,   130,   134,   138,   142,   146,   150,   153,   164,
     183,   186,    79,    80,   167,    82,     0,    77,    76,    75,
      78,     0,     0,    38,    35,    67,    67,   190,    25,   110,
     108,     0,     0,    56,   154,     0,     0,   169,   103,   100,
      56,   101,    60,    67,   175,    73,    67,    81,     0,   173,
       0,    36,    37,     0,    26,   112,     0,    25,    56,    41,
      98,    97,    67,   175,   107,     0,    39,     0,    83,     0,
     174,     0,   166,    67,     0,    39,   111,   109,     0,    13,
      42,   171,     0,     0,    67,     0,    55,     0,    67,    67,
       0,    22,    67,    27,     0,   106,    56,   175,     0,   112,
      39,    40,   168,   176,   177,    19,    24,    23,     0,    56,
       0,   170,    39,    54,     0,     0,     0,    11,     0,   104,
       0,   180,     0,   178,   114,   113,   172,   181,   179
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    30,    31,   252,   253,    96,    32,   185,   310,
     273,    67,    68,    69,    70,   306,   278,   279,    37,    38,
     124,   199,   236,   169,    39,    40,    41,   284,   186,   251,
     295,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,   170,   264,   283,   317,   270,
     242,   292,    56,   200,    57,    64
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -263
static const yytype_int16 yypact[] =
{
    -263,   530,  -263,  -263,     4,    52,    99,  -263,    60,    99,
     251,    46,    60,    60,    60,    60,   169,    60,   -13,     5,
     114,    60,    60,    60,    60,   367,  -263,    60,  -263,  -263,
    -263,  -263,  -263,    23,    68,   107,  -263,   148,    34,  -263,
     148,   148,   148,   -11,    38,    51,    94,   121,   124,   170,
     174,   148,   148,  -263,    60,   148,   120,   148,    99,  -263,
     177,   179,   187,    57,  -263,  -263,   638,   -28,  -263,   168,
    -263,  -263,    60,    60,    60,    60,    60,  -263,    60,  -263,
    -263,    39,    66,    60,    57,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,    22,  -263,  -263,  -263,
     164,    60,    60,    60,    60,    60,    60,    60,  -263,    57,
    -263,    60,   221,    60,  -263,   129,  -263,   161,   188,  -263,
       8,    55,  -263,   223,    78,  -263,  -263,  -263,    60,    60,
      60,    60,    60,    60,    60,    60,  -263,  -263,    77,  -263,
      60,  -263,  -263,  -263,  -263,  -263,  -263,   797,   797,   236,
     237,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,   192,   195,   196,   199,  -263,    57,  -263,
    -263,  -263,  -263,   200,   201,   797,  -263,  -263,  -263,  -263,
    -263,  -263,   797,  -263,    77,   207,    97,   213,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,    57,  -263,   -10,   797,
    -263,  -263,    -2,   797,    60,  -263,   217,  -263,    66,    34,
    -263,  -263,  -263,  -263,  -263,  -263,    60,    57,  -263,    57,
      10,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
      57,   797,  -263,  -263,   797,   797,    82,  -263,  -263,  -263,
    -263,   205,    79,  -263,   797,  -263,  -263,   797,    60,  -263,
      57,   134,   219,   468,   797,    60,    60,   691,  -263,   797,
      78,   797,    57,  -263,  -263,  -263,  -263,  -263,   250,  -263,
       6,   797,   797,   162,    57,  -263,   123,    60,   334,  -263,
      57,    57,  -263,  -263,    97,    11,   744,    79,   797,   224,
    -263,   165,  -263,   148,    60,    -8,  -263,    57,   178,  -263,
    -263,   797,    79,   186,  -263,    60,  -263,     6,  -263,  -263,
     143,   797,   148,    57,   258,  -263,   468,  -263,     6,  -263,
     744,    57,  -263,   797,   585,  -263,  -263,   148,   230,   410,
      79,  -263,    -8,  -263,    37,    43,   136,  -263,     6,  -263,
      60,  -263,    60,  -263,  -263,    57,  -263,  -263,  -263
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,   -30,
       9,    -1,    13,    14,    58,  -261,   -22,     2,  -263,  -116,
      88,   231,  -263,  -263,    -9,  -263,  -263,  -263,  -263,    21,
     -21,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,   190,   296,  -263,  -263,  -263,  -263,  -263,  -209,
    -262,  -113,  -263,   -16,  -263,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -58
static const yytype_int16 yytable[] =
{
      33,   209,   287,    36,    63,   111,    65,   256,   220,    71,
      81,    82,    84,   212,    34,    35,    58,   121,   121,   112,
      59,   302,   213,   100,   255,   305,   109,    91,   119,   -57,
     -57,   125,   126,   127,   315,   128,   187,   112,   314,   -57,
     120,   121,   136,   137,   110,   112,   139,   141,   142,    92,
     122,    59,   214,   138,    27,   330,   111,    59,   143,   333,
      59,   215,   263,   304,   290,   168,    59,   216,    79,    59,
     112,   339,    85,    86,    59,    90,   -33,   -57,   307,    97,
      98,    99,   184,   108,   129,    27,   112,   110,   123,   183,
     204,    27,    59,   318,    27,   340,    80,   130,   229,   -33,
      27,   342,   -33,    27,   112,    60,    61,    62,    27,   249,
     196,    59,   198,   112,   202,   113,   208,   -33,   -33,   -33,
     217,   338,    93,   219,   112,   268,    27,   265,   266,   269,
     176,   177,   178,   179,   180,   296,   181,    59,   114,   230,
     131,   115,    94,    59,   285,    27,   168,   168,   344,    95,
      59,   241,    60,    61,    62,   243,   116,   117,   118,   189,
     190,   191,   192,   193,   194,   195,   140,   132,   325,   201,
     133,    27,    28,   204,   168,    59,   205,    27,    29,   275,
     276,   168,    12,    87,    27,   250,   221,   222,   223,   224,
     225,   226,   227,   228,   322,    28,   206,    88,   168,   171,
      28,    29,   168,    63,    89,   331,    29,   293,   294,    27,
     207,   112,   112,   188,   309,   262,   134,   172,   173,   174,
     135,   341,   343,   316,   294,   346,   144,   347,   145,   348,
     168,   319,   276,   168,   168,   197,   146,   211,    66,   218,
     232,   237,   233,   168,   238,   239,   168,   274,   240,   245,
     246,   248,    33,   168,   280,   281,   168,   -10,   168,   219,
     168,   258,   267,   277,   289,    59,    34,    35,    72,   291,
     168,   168,   328,   308,    73,   297,   274,    33,    74,   336,
     300,    75,   327,   250,   312,   168,   298,   168,    76,    77,
      78,    34,    35,   313,   329,   147,   148,   260,   332,    27,
     168,   326,   175,   312,   321,   303,   291,   210,    83,     0,
     168,   182,     0,     0,     0,    33,     0,   291,   326,   168,
       0,     0,   168,   168,     0,     0,     0,     0,    33,    34,
      35,   300,     0,   291,   291,   345,     0,   291,     0,   291,
       4,   291,    34,    35,     0,     0,     5,   203,     6,     7,
       0,     8,     9,    10,    11,    12,    13,    14,     0,   299,
       0,    15,     0,     0,    17,     0,     0,     0,     0,    19,
       0,    21,    22,    23,   231,    24,    25,     0,     0,     0,
       0,    59,    27,     0,   101,     0,    28,     0,     0,   234,
     102,     0,    29,   235,   103,     0,     0,   104,     0,     0,
       0,     0,     0,   244,   105,   106,   107,     0,     0,     0,
       0,     0,     0,     0,   247,    27,     4,     0,     0,   254,
       0,     0,     5,     0,     6,     7,     0,     8,     9,    10,
      11,    12,    13,    14,     0,   337,   257,    15,   259,     0,
      17,     0,   261,     0,     0,    19,     0,    21,    22,    23,
       0,    24,    25,     0,     0,     0,     0,     0,    27,     0,
       0,     0,    28,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     4,     0,   271,   272,     0,     0,
       5,     0,     6,     7,     0,     8,     9,    10,    11,    12,
      13,    14,     0,     0,   286,    15,     0,   288,    17,     0,
       0,     0,     0,    19,     0,    21,    22,    23,     0,    24,
      25,     0,     0,   301,     0,     0,    27,     0,     0,     0,
      28,     0,     0,     0,   311,     0,    29,     0,     0,     0,
       2,     3,     0,     0,     0,   320,     4,   -56,     0,   323,
     324,     0,     5,   311,     6,     7,   -56,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,    15,     0,    16,
      17,     0,    18,     0,     0,    19,    20,    21,    22,    23,
       0,    24,    25,    26,     0,     0,     0,     0,    27,     0,
       0,     0,    28,     0,   -56,     0,     0,     0,    29,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,    59,
       0,     0,     0,   159,     0,     0,     0,     0,     0,   160,
       0,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   162,
       0,   334,     0,    27,   163,   335,     0,     0,   164,   165,
     166,   167,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    59,     0,     0,     0,   159,     0,     0,     0,
       0,     0,   160,     0,     0,     0,   161,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,     0,     0,     0,    27,   163,     0,     0,
       0,   164,   165,   166,   167,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   282,    59,     0,     0,     0,   159,
       0,     0,     0,     0,     0,   160,     0,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   162,     0,     0,     0,    27,
     163,     0,     0,     0,   164,   165,   166,   167,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,    59,     0,
       0,     0,   159,     0,     0,     0,     0,     0,   160,     0,
       0,     0,   161,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   162,     0,
       0,     0,    27,   163,     0,     0,     0,   164,   165,   166,
     167,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,    59,     0,     0,     0,   159,     0,     0,     0,     0,
       0,   160,     0,     0,     0,   161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   162,     0,     0,     0,    27,   163,     0,     0,     0,
     164,   165,   166,   167
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-263)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       1,   117,   264,     1,     5,    33,     6,     9,   124,     9,
      11,    12,    13,     5,     1,     1,    12,     7,     7,    47,
      14,   283,    14,    24,    34,    33,    27,    40,    37,     6,
       7,    40,    41,    42,   295,    46,    14,    47,    46,    16,
       6,     7,    51,    52,    21,    47,    55,    56,    57,    44,
      16,    14,    44,    54,    48,   317,    33,    14,    58,   320,
      14,    53,    52,    52,    58,    66,    14,    12,    10,    14,
      47,   332,    14,    15,    14,    17,     8,    54,   287,    21,
      22,    23,    83,    25,    46,    48,    47,    21,    54,    50,
      12,    48,    14,   302,    48,    58,    50,    46,    21,    31,
      48,    58,    34,    48,    47,    53,    54,    55,    48,    12,
     111,    14,   113,    47,   115,     8,   117,    49,    50,    51,
     121,   330,     8,   124,    47,    46,    48,    45,    46,    50,
      72,    73,    74,    75,    76,    12,    78,    14,    31,   140,
      46,    34,    28,    14,   260,    48,   147,   148,    12,    35,
      14,   167,    53,    54,    55,   171,    49,    50,    51,   101,
     102,   103,   104,   105,   106,   107,    46,    46,    25,    40,
      46,    48,    52,    12,   175,    14,    15,    48,    58,    45,
      46,   182,    21,    14,    48,   186,   128,   129,   130,   131,
     132,   133,   134,   135,   307,    52,    35,    28,   199,    31,
      52,    58,   203,   204,    35,   318,    58,    45,    46,    48,
      49,    47,    47,    49,    49,   216,    46,    49,    50,    51,
      46,   334,   335,    45,    46,   338,    49,   340,    49,   342,
     231,    45,    46,   234,   235,    14,    49,    49,     7,    16,
       4,    49,     5,   244,    49,    49,   247,   248,    49,    49,
      49,    44,   253,   254,   255,   256,   257,    44,   259,   260,
     261,    44,    57,    44,    14,    14,   253,   253,    17,   270,
     271,   272,    14,    49,    23,   276,   277,   278,    27,    49,
     278,    30,   312,   284,   293,   286,   277,   288,    37,    38,
      39,   278,   278,   294,   316,    64,    65,   209,   319,    48,
     301,   310,    71,   312,   305,   284,   307,   117,    12,    -1,
     311,    80,    -1,    -1,    -1,   316,    -1,   318,   327,   320,
      -1,    -1,   323,   324,    -1,    -1,    -1,    -1,   329,   316,
     316,   329,    -1,   334,   335,   336,    -1,   338,    -1,   340,
       6,   342,   329,   329,    -1,    -1,    12,   116,    14,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,
      -1,    37,    38,    39,   143,    41,    42,    -1,    -1,    -1,
      -1,    14,    48,    -1,    17,    -1,    52,    -1,    -1,   158,
      23,    -1,    58,   162,    27,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,   172,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   183,    48,     6,    -1,    -1,   188,
      -1,    -1,    12,    -1,    14,    15,    -1,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,   205,    27,   207,    -1,
      30,    -1,   211,    -1,    -1,    35,    -1,    37,    38,    39,
      -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,     6,    -1,   245,   246,    -1,    -1,
      12,    -1,    14,    15,    -1,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,   263,    27,    -1,   266,    30,    -1,
      -1,    -1,    -1,    35,    -1,    37,    38,    39,    -1,    41,
      42,    -1,    -1,   282,    -1,    -1,    48,    -1,    -1,    -1,
      52,    -1,    -1,    -1,   293,    -1,    58,    -1,    -1,    -1,
       0,     1,    -1,    -1,    -1,   304,     6,     7,    -1,   308,
     309,    -1,    12,   312,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    -1,    32,    -1,    -1,    35,    36,    37,    38,    39,
      -1,    41,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    52,    -1,    54,    -1,    -1,    -1,    58,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    46,    -1,    48,    49,    50,    -1,    -1,    53,    54,
      55,    56,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    53,    54,    55,    56,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,
      49,    -1,    -1,    -1,    53,    54,    55,    56,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    49,    -1,    -1,    -1,    53,    54,    55,
      56,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,
      53,    54,    55,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,     0,     1,     6,    12,    14,    15,    17,    18,
      19,    20,    21,    22,    23,    27,    29,    30,    32,    35,
      36,    37,    38,    39,    41,    42,    43,    48,    52,    58,
      61,    62,    66,    70,    71,    72,    76,    77,    78,    83,
      84,    85,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   111,   113,    12,    14,
      53,    54,    55,    70,   114,   114,    80,    70,    71,    72,
      73,   114,    17,    23,    27,    30,    37,    38,    39,    73,
      50,    70,    70,   102,    70,    73,    73,    14,    28,    35,
      73,    40,    44,     8,    28,    35,    65,    73,    73,    73,
      70,    17,    23,    27,    30,    37,    38,    39,    73,    70,
      21,    33,    47,     8,    31,    34,    49,    50,    51,    83,
       6,     7,    16,    54,    79,    83,    83,    83,    46,    46,
      46,    46,    46,    46,    46,    46,    83,    83,    70,    83,
      46,    83,    83,   114,    49,    49,    49,    80,    80,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    18,
      24,    28,    44,    49,    53,    54,    55,    56,    70,    82,
     104,    31,    49,    50,    51,    80,    73,    73,    73,    73,
      73,    73,    80,    50,    70,    67,    87,    14,    49,    73,
      73,    73,    73,    73,    73,    73,    70,    14,    70,    80,
     112,    40,    70,    80,    12,    15,    35,    49,    70,    78,
     101,    49,     5,    14,    44,    53,    12,    70,    16,    70,
      78,    73,    73,    73,    73,    73,    73,    73,    73,    21,
      70,    80,     4,     5,    80,    80,    81,    49,    49,    49,
      49,   112,   109,   112,    80,    49,    49,    80,    44,    12,
      70,    88,    63,    64,    80,    34,     9,    80,    44,    80,
      79,    80,    70,    52,   105,    45,    46,    57,    46,    50,
     108,    80,    80,    69,    70,    45,    46,    44,    75,    76,
      70,    70,    13,   106,    86,    78,    80,   109,    80,    14,
      58,    70,   110,    45,    46,    89,    12,    70,    69,    25,
      76,    80,   109,    88,    52,    33,    74,   108,    49,    49,
      68,    80,    83,    70,    46,    74,    45,   107,   108,    45,
      80,    70,   110,    80,    80,    25,    83,    68,    14,    75,
     109,   110,    89,    74,    46,    50,    49,    25,   108,    74,
      58,   110,    58,   110,    12,    70,   110,   110,   110
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
#line 133 "antimony.ypp"
    {}
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 134 "antimony.ypp"
    { /*cout << endl << $2->ToString() << endl << endl;*/ }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 135 "antimony.ypp"
    {}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 136 "antimony.ypp"
    {}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 137 "antimony.ypp"
    {YYABORT;}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 138 "antimony.ypp"
    {YYABORT;}
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 141 "antimony.ypp"
    { if (g_registry.OpenFile(*((yyvsp[(2) - (2)].word)))==0) YYABORT;}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 144 "antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(3) - (3)].word), (yyvsp[(2) - (3)].maybemain));}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 145 "antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 150 "antimony.ypp"
    {g_registry.NewCurrentModule((yyvsp[(3) - (3)].word), (yyvsp[(2) - (3)].maybemain));}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 151 "antimony.ypp"
    {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 156 "antimony.ypp"
    {g_registry.SetError("module '" + *((yyvsp[(2) - (2)].word)) + "' already defined."); YYABORT;}
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 157 "antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a module because it is already a defined function."); YYABORT;}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 160 "antimony.ypp"
    {(yyval.maybemain) = false;}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 161 "antimony.ypp"
    {(yyval.maybemain) = true;}
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 164 "antimony.ypp"
    {g_registry.NewUserFunction((yyvsp[(2) - (2)].word));}
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 164 "antimony.ypp"
    {if (g_registry.SetUserFunction((yyvsp[(7) - (8)].formula))) YYABORT;}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 165 "antimony.ypp"
    {g_registry.SetError("Cannot use '" + *((yyvsp[(2) - (2)].word)) +"' as a function name because it is already the name of a module."); YYABORT;}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 166 "antimony.ypp"
    {g_registry.SetError("Cannot define '" + *((yyvsp[(2) - (2)].word)) + "' as a new function because it is already a defined function."); YYABORT;}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 169 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (1)].formula);}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 170 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(2) - (2)].formula);}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 171 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula);}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 181 "antimony.ypp"
    {}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 182 "antimony.ypp"
    {if (g_registry.AddVariableToCurrentExportList((yyvsp[(1) - (1)].variable))) YYABORT; }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 183 "antimony.ypp"
    { if (g_registry.AddVariableToCurrentExportList((yyvsp[(3) - (3)].variable))) YYABORT; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 186 "antimony.ypp"
    {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[(1) - (1)].word)); }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 187 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable)->GetSubVariable((yyvsp[(3) - (3)].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[(3) - (3)].word)) + "' is not a subvariable of '" + (yyvsp[(1) - (3)].variable)->GetNameDelimitedBy(".") + "'.");
                    YYABORT;
                  }
                }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 193 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 196 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetCompartment((yyvsp[(3) - (3)].variable))) YYABORT; (yyval.variable) = (yyvsp[(1) - (3)].variable);}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 199 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 200 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 203 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (1)].variable);}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 204 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable); if ((yyvsp[(1) - (3)].variable)->SetFormula((yyvsp[(3) - (3)].formula))) YYABORT; }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 205 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (4)].variable); if ((yyvsp[(1) - (4)].variable)->SetAssignmentRule((yyvsp[(4) - (4)].formula))) YYABORT; }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 206 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (4)].variable); if ((yyvsp[(1) - (4)].variable)->SetRateRule((yyvsp[(4) - (4)].formula))) YYABORT; }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 207 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(1) - (3)].variable); if ((yyvsp[(1) - (3)].variable)->SetUnit((yyvsp[(3) - (3)].variable))) YYABORT; }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 210 "antimony.ypp"
    {(yyval.variable) = NULL;}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 211 "antimony.ypp"
    {(yyval.variable) = (yyvsp[(2) - (2)].variable);}
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 214 "antimony.ypp"
    {}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 215 "antimony.ypp"
    {}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 218 "antimony.ypp"
    {}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 219 "antimony.ypp"
    {}
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 220 "antimony.ypp"
    {}
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 221 "antimony.ypp"
    {}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 222 "antimony.ypp"
    {}
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 223 "antimony.ypp"
    {}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 224 "antimony.ypp"
    {}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 225 "antimony.ypp"
    {}
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 226 "antimony.ypp"
    {}
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 227 "antimony.ypp"
    {}
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 228 "antimony.ypp"
    {}
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 232 "antimony.ypp"
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[(4) - (8)].reactionDivider), (yyvsp[(7) - (8)].formula), (yyvsp[(1) - (8)].variable));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[(8) - (8)].variable) != NULL) {
                    if ((yyvsp[(1) - (8)].variable)->SetCompartment((yyvsp[(8) - (8)].variable))) YYABORT;
                  }
                }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 240 "antimony.ypp"
    {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[(2) - (6)].reactionDivider), (yyvsp[(5) - (6)].formula));
                  if (var == NULL) YYABORT;
                  if ((yyvsp[(6) - (6)].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[(6) - (6)].variable))) YYABORT;
                  }
                }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 249 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 250 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(1) - (1)].variable)); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 251 "antimony.ypp"
    {(yyval.reactantList) = g_registry.NewBlankReactantList(); (yyval.reactantList)->AddReactant((yyvsp[(2) - (2)].variable), (yyvsp[(1) - (2)].num)); }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 252 "antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (3)].reactantList); (yyvsp[(1) - (3)].reactantList)->AddReactant((yyvsp[(3) - (3)].variable)); }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 253 "antimony.ypp"
    {(yyval.reactantList) = (yyvsp[(1) - (4)].reactantList); (yyvsp[(1) - (4)].reactantList)->AddReactant((yyvsp[(4) - (4)].variable), (yyvsp[(3) - (4)].num)); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 257 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 258 "antimony.ypp"
    {(yyval.reactionDivider) = rdInhibits;}
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 259 "antimony.ypp"
    {(yyval.reactionDivider) = rdInfluences;}
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 260 "antimony.ypp"
    {if (*(yyvsp[(2) - (2)].word) != "o") {g_registry.SetError("'-" + *(yyvsp[(2) - (2)].word) + "' is not a valid set of characters to demark reactions.  Try '->' for reactions, and '-|', '-o', and '-(' for interactions."); YYABORT;} (yyval.reactionDivider) = rdActivates;}
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 261 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomesIrreversibly;}
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 262 "antimony.ypp"
    {(yyval.reactionDivider) = rdBecomes;}
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 265 "antimony.ypp"
    {(yyval.formula) = g_registry.NewBlankFormula(); }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 266 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddEllipses();}
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 267 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddVariable((yyvsp[(2) - (2)].variable)); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 268 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddNum((yyvsp[(2) - (2)].num)); }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 269 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddText((yyvsp[(2) - (2)].word)); }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 270 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddText((yyvsp[(2) - (2)].word)); }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 271 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (4)].formula); (yyvsp[(3) - (4)].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[(3) - (4)].formula)); }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 272 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (2)].formula); (yyvsp[(1) - (2)].formula)->AddMathThing((yyvsp[(2) - (2)].character)); }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 273 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('<'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 274 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('>'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 275 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('='); (yyvsp[(1) - (3)].formula)->AddMathThing('='); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 276 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('!'); (yyvsp[(1) - (3)].formula)->AddMathThing('='); }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 277 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); (yyvsp[(1) - (3)].formula)->AddMathThing('&'); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 278 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); (yyvsp[(1) - (3)].formula)->AddMathThing('|'); }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 280 "antimony.ypp"
    {
                  //Need to create a variable to be this unit definition, or find one that already has this unit definition, and then use that name.
                  (yyval.formula) = (yyvsp[(1) - (4)].formula);
                  (yyval.formula)->AddVariable((yyvsp[(3) - (4)].variable));
                }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 287 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (1)].formula);}
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 288 "antimony.ypp"
    {(yyval.formula) = (yyvsp[(1) - (3)].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[(3) - (3)].formula)); }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 291 "antimony.ypp"
    {(yyval.character) = '+';}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 292 "antimony.ypp"
    {(yyval.character) = '-';}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 293 "antimony.ypp"
    {(yyval.character) = '*';}
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 294 "antimony.ypp"
    {(yyval.character) = '/';}
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 295 "antimony.ypp"
    {(yyval.character) = '^';}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 296 "antimony.ypp"
    {(yyval.character) = '>';}
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 297 "antimony.ypp"
    {(yyval.character) = '<';}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 298 "antimony.ypp"
    {(yyval.character) = '!';}
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 299 "antimony.ypp"
    {(yyval.character) = '%';}
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 302 "antimony.ypp"
    {}
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 303 "antimony.ypp"
    {}
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 306 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetFormula((yyvsp[(3) - (3)].formula))) YYABORT; }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 307 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->Synchronize((yyvsp[(3) - (3)].variable), NULL)) YYABORT;}
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 308 "antimony.ypp"
    {if ((yyvsp[(1) - (5)].variable)->Synchronize((yyvsp[(3) - (5)].variable), (yyvsp[(5) - (5)].variable))) YYABORT;}
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 309 "antimony.ypp"
    {if ((yyvsp[(1) - (5)].variable)->Synchronize((yyvsp[(5) - (5)].variable), (yyvsp[(3) - (5)].variable))) YYABORT;}
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 310 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetDisplayName(*((yyvsp[(3) - (3)].word)))) YYABORT;}
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 311 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetAssignmentRule((yyvsp[(4) - (4)].formula))) YYABORT;}
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 312 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetRateRule((yyvsp[(4) - (4)].formula))) YYABORT;}
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 313 "antimony.ypp"
    {if ((yyvsp[(1) - (3)].variable)->SetUnit((yyvsp[(3) - (3)].variable))) YYABORT; }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 317 "antimony.ypp"
    {if ((yyvsp[(1) - (4)].variable)->SetModule((yyvsp[(3) - (4)].word))) YYABORT;}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 317 "antimony.ypp"
    {if ((yyvsp[(9) - (9)].variable) != NULL) {if ((yyvsp[(1) - (9)].variable)->SetCompartment((yyvsp[(9) - (9)].variable))) YYABORT;}}
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 318 "antimony.ypp"
    {if(g_registry.CurrentModule()->SetModule((yyvsp[(1) - (2)].word))) YYABORT;}
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 318 "antimony.ypp"
    {if ((yyvsp[(7) - (7)].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[(7) - (7)].variable))) YYABORT;}}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 322 "antimony.ypp"
    {}
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 323 "antimony.ypp"
    {if (g_registry.AddVariableToCurrentImportList((yyvsp[(1) - (1)].variable))) YYABORT; }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 324 "antimony.ypp"
    { if (g_registry.AddVariableToCurrentImportList((yyvsp[(3) - (3)].variable))) YYABORT; }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 325 "antimony.ypp"
    {if (g_registry.AddNumberToCurrentImportList((yyvsp[(1) - (1)].num))) YYABORT; }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 326 "antimony.ypp"
    { if (g_registry.AddNumberToCurrentImportList((yyvsp[(3) - (3)].num))) YYABORT; }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 330 "antimony.ypp"
    {}
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 331 "antimony.ypp"
    {if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[(5) - (5)].variable));}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[(5) - (5)].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[(3) - (5)].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 335 "antimony.ypp"
    {if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[(5) - (5)].num));}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[(5) - (5)].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[(3) - (5)].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 339 "antimony.ypp"
    { }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 340 "antimony.ypp"
    { }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 341 "antimony.ypp"
    { }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 342 "antimony.ypp"
    { }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 343 "antimony.ypp"
    { }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 344 "antimony.ypp"
    { }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 346 "antimony.ypp"
    { }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 347 "antimony.ypp"
    { }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 350 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varSpeciesUndef)) YYABORT; }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 351 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 352 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 353 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varSpeciesUndef)) YYABORT; }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 356 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaUndef)) YYABORT; }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 357 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 358 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 359 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaUndef)) YYABORT; }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 362 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varReactionUndef)) YYABORT; }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 363 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 364 "antimony.ypp"
    {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 365 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionUndef)) YYABORT; }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 368 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varDNA)) YYABORT; }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 369 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 370 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 371 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varDNA)) YYABORT; }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 374 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varReactionGene)) YYABORT; }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 375 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 376 "antimony.ypp"
    {g_registry.SetError("Genes may not be set 'const'."); YYABORT; }
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 377 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varReactionGene)) YYABORT; }
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 380 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varFormulaOperator)) YYABORT; }
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 381 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 382 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; }
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 383 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varFormulaOperator)) YYABORT; }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 387 "antimony.ypp"
    {g_registry.SetConstness(constDEFAULT); (yyvsp[(2) - (2)].variable)->SetRegConst(); if ((yyvsp[(2) - (2)].variable)->SetType(varCompartment)) YYABORT; }
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 388 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; }
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 389 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; }
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 390 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst(); if ((yyvsp[(3) - (3)].variable)->SetType(varCompartment)) YYABORT; }
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 393 "antimony.ypp"
    {g_registry.SetConstness(constVAR); (yyvsp[(2) - (2)].variable)->SetRegConst();}
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 394 "antimony.ypp"
    {g_registry.SetConstness(constCONST); (yyvsp[(2) - (2)].variable)->SetRegConst();}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 395 "antimony.ypp"
    {(yyvsp[(3) - (3)].variable)->SetRegConst();}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 398 "antimony.ypp"
    {if ((yyvsp[(2) - (4)].variable)->SetType(varUnitDefinition)) YYABORT;
                                               if ((yyvsp[(4) - (4)].formula)->MakeAllVariablesUnits()) YYABORT;
                                               if ((yyvsp[(2) - (4)].variable)->GetUnitDef()->SetFromFormula((yyvsp[(4) - (4)].formula))) YYABORT;}
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 401 "antimony.ypp"
    {if ((yyvsp[(2) - (2)].variable)->SetType(varUnitDefinition)) YYABORT;}
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 404 "antimony.ypp"
    {if (g_registry.SaveWorkingStrand()) YYABORT;}
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 405 "antimony.ypp"
    {if (g_registry.SetStrandAs((yyvsp[(1) - (3)].variable))) YYABORT;}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 408 "antimony.ypp"
    {if (g_registry.SetNewUpstreamOpen((yyvsp[(2) - (2)].variable))) YYABORT;}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 409 "antimony.ypp"
    {g_registry.SetOpenUpstream(); }
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 410 "antimony.ypp"
    {if (g_registry.SetDownstreamEnd((yyvsp[(2) - (2)].variable))) YYABORT;}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 411 "antimony.ypp"
    {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[(3) - (3)].variable))) YYABORT;}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 412 "antimony.ypp"
    { }
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 415 "antimony.ypp"
    {if (g_registry.SetNewDownstreamOpen((yyvsp[(1) - (2)].variable))) YYABORT;}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 416 "antimony.ypp"
    {if (g_registry.SetDownstreamOpen((yyvsp[(2) - (3)].variable))) YYABORT;}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 419 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(2) - (2)].formula))) YYABORT;}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 419 "antimony.ypp"
    {}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 420 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(2) - (4)].formula), (yyvsp[(4) - (4)].formula))) YYABORT;}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 420 "antimony.ypp"
    {}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 421 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (4)].formula), (yyvsp[(1) - (4)].variable))) YYABORT;}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 421 "antimony.ypp"
    {}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 422 "antimony.ypp"
    {if (g_registry.SetNewCurrentEvent((yyvsp[(4) - (6)].formula), (yyvsp[(6) - (6)].formula), (yyvsp[(1) - (6)].variable))) YYABORT;}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 422 "antimony.ypp"
    {}
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 425 "antimony.ypp"
    {}
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 426 "antimony.ypp"
    {}
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 429 "antimony.ypp"
    {}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 430 "antimony.ypp"
    {if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[(5) - (5)].formula));}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else if (CaselessStrCmp(*(yyvsp[(3) - (5)].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[(5) - (5)].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[(3) - (5)].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;}}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 437 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (3)].variable), (yyvsp[(3) - (3)].formula))) YYABORT;}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 438 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (5)].variable), (yyvsp[(3) - (5)].formula))) YYABORT;}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 439 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (6)].variable), (yyvsp[(3) - (6)].formula))) YYABORT;}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 440 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (5)].variable), (yyvsp[(3) - (5)].formula))) YYABORT;}
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 441 "antimony.ypp"
    {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[(1) - (6)].variable), (yyvsp[(3) - (6)].formula))) YYABORT;}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 444 "antimony.ypp"
    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[(2) - (2)].variable))) YYABORT;}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 445 "antimony.ypp"
    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[(3) - (3)].variable))) YYABORT;}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 448 "antimony.ypp"
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

  case 185:
/* Line 1787 of yacc.c  */
#line 463 "antimony.ypp"
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[(1) - (3)].num), (yyvsp[(3) - (3)].formula), (yyvsp[(2) - (3)].inequality))) YYABORT;}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 464 "antimony.ypp"
    {if (g_registry.CurrentModule()->AddConstraint(-(yyvsp[(2) - (4)].num), (yyvsp[(4) - (4)].formula), (yyvsp[(3) - (4)].inequality))) YYABORT;}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 465 "antimony.ypp"
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[(1) - (3)].word), (yyvsp[(3) - (3)].formula), (yyvsp[(2) - (3)].inequality))) YYABORT;}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 466 "antimony.ypp"
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[(1) - (3)].word), (yyvsp[(3) - (3)].formula), (yyvsp[(2) - (3)].inequality))) YYABORT;}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 467 "antimony.ypp"
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[(3) - (3)].formula))) YYABORT;}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 468 "antimony.ypp"
    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[(2) - (4)].variable), (yyvsp[(4) - (4)].formula))) YYABORT;}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 471 "antimony.ypp"
    {(yyval.inequality) = constLT;}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 472 "antimony.ypp"
    {(yyval.inequality) = constLEQ;}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 473 "antimony.ypp"
    {(yyval.inequality) = constGT;}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 474 "antimony.ypp"
    {(yyval.inequality) = constGEQ;}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 475 "antimony.ypp"
    {(yyval.inequality) = constNEQ;}
    break;


/* Line 1787 of yacc.c  */
#line 3068 "antimony.tab.cpp"
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
#line 477 "antimony.ypp"



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
    if (CaselessStrCmp(word, "constraint")) {
      return CONSTRAINTWORD;
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
