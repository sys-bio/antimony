/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         ANTIMONY_YYSTYPE
/* Substitute the variable and function names.  */
#define yyparse         antimony_yyparse
#define yylex           antimony_yylex
#define yyerror         antimony_yyerror
#define yydebug         antimony_yydebug
#define yynerrs         antimony_yynerrs
#define yylval          antimony_yylval
#define yychar          antimony_yychar

/* First part of user prologue.  */
#line 28 "antimony.ypp"

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

using namespace libsbml;

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

#line 113 "antimony.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef ANTIMONY_YYDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define ANTIMONY_YYDEBUG 1
#  else
#   define ANTIMONY_YYDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define ANTIMONY_YYDEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined ANTIMONY_YYDEBUG */
#if ANTIMONY_YYDEBUG
extern int antimony_yydebug;
#endif

/* Token kinds.  */
#ifndef ANTIMONY_YYTOKENTYPE
# define ANTIMONY_YYTOKENTYPE
  enum antimony_yytokentype
  {
    ANTIMONY_YYEMPTY = -2,
    ANTIMONY_YYEOF = 0,            /* "end of file"  */
    ANTIMONY_YYerror = 256,        /* error  */
    ANTIMONY_YYUNDEF = 257,        /* "invalid token"  */
    EOL = 259,                     /* "end of line"  */
    NUM = 260,                     /* "number"  */
    AFTER = 261,                   /* "'after'"  */
    ANTWORD = 262,                 /* "element name"  */
    AT = 263,                      /* "'at'"  */
    BECOMESREV = 264,              /* "->"  */
    BECOMESINH = 265,              /* "-|"  */
    BECOMESMOD2 = 266,             /* "-o"  */
    BECOMESIRREV = 267,            /* "=>"  */
    COMPARTMENT = 268,             /* "'compartment'"  */
    CONSTANT = 269,                /* "name of a pre-defined constant"  */
    CONSTRAINTWORD = 270,          /* "'constraint'"  */
    CONSTWORD = 271,               /* "'const'"  */
    DASHES = 272,                  /* "--"  */
    DELETEWORD = 273,              /* "'delete'"  */
    DNA = 274,                     /* "'DNA'"  */
    ELLIPSES = 275,                /* "..."  */
    END = 276,                     /* "'end'"  */
    ERROR = 277,                   /* "an error"  */
    EVENT = 278,                   /* "'event'"  */
    FORMULA = 279,                 /* "'formula'"  */
    FUNCTION = 280,                /* "name of an existing function"  */
    FUNCTIONWORD = 281,            /* "'function'"  */
    GENE = 282,                    /* "'gene'"  */
    GEQ = 283,                     /* ">="  */
    NEQ = 284,                     /* "!="  */
    HASWORD = 285,                 /* "'has'"  */
    IMPORT = 286,                  /* "'import'"  */
    INWORD = 287,                  /* "'in'"  */
    IS = 288,                      /* "'is'"  */
    LEQ = 289,                     /* "<="  */
    MAXIMIZEWORD = 290,            /* "'maximize'"  */
    MINIMIZEWORD = 291,            /* "'minimize'"  */
    MODNAME = 292,                 /* "name of an existing module"  */
    MODULE = 293,                  /* "'model' or 'module'"  */
    OPERATOR = 294,                /* "'operator'"  */
    REACTION = 295,                /* "'reaction'"  */
    SPECIES = 296,                 /* "'species'"  */
    SUBSTONLY = 297,               /* "'substanceOnly'"  */
    TEXTSTRING = 298,              /* "text string"  */
    UNITWORD = 299,                /* "'unit'"  */
    VARWORD = 300                  /* "'var'"  */
  };
  typedef enum antimony_yytokentype antimony_yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined ANTIMONY_YYSTYPE && ! defined ANTIMONY_YYSTYPE_IS_DECLARED
union ANTIMONY_YYSTYPE
{
#line 63 "antimony.ypp"

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

#line 235 "antimony.tab.cpp"

};
typedef union ANTIMONY_YYSTYPE ANTIMONY_YYSTYPE;
# define ANTIMONY_YYSTYPE_IS_TRIVIAL 1
# define ANTIMONY_YYSTYPE_IS_DECLARED 1
#endif


extern ANTIMONY_YYSTYPE antimony_yylval;


int antimony_yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_mathematical_symbol_ = 3,     /* "mathematical symbol"  */
  YYSYMBOL_4_ = 4,                         /* '&'  */
  YYSYMBOL_5_ = 5,                         /* '|'  */
  YYSYMBOL_6_ = 6,                         /* '-'  */
  YYSYMBOL_7_ = 7,                         /* '+'  */
  YYSYMBOL_8_ = 8,                         /* '*'  */
  YYSYMBOL_9_ = 9,                         /* '/'  */
  YYSYMBOL_10_ = 10,                       /* '%'  */
  YYSYMBOL_11_ = 11,                       /* '^'  */
  YYSYMBOL_12_ = 12,                       /* '$'  */
  YYSYMBOL_13_ = 13,                       /* '.'  */
  YYSYMBOL_EOL = 14,                       /* "end of line"  */
  YYSYMBOL_NUM = 15,                       /* "number"  */
  YYSYMBOL_AFTER = 16,                     /* "'after'"  */
  YYSYMBOL_ANTWORD = 17,                   /* "element name"  */
  YYSYMBOL_AT = 18,                        /* "'at'"  */
  YYSYMBOL_BECOMESREV = 19,                /* "->"  */
  YYSYMBOL_BECOMESINH = 20,                /* "-|"  */
  YYSYMBOL_BECOMESMOD2 = 21,               /* "-o"  */
  YYSYMBOL_BECOMESIRREV = 22,              /* "=>"  */
  YYSYMBOL_COMPARTMENT = 23,               /* "'compartment'"  */
  YYSYMBOL_CONSTANT = 24,                  /* "name of a pre-defined constant"  */
  YYSYMBOL_CONSTRAINTWORD = 25,            /* "'constraint'"  */
  YYSYMBOL_CONSTWORD = 26,                 /* "'const'"  */
  YYSYMBOL_DASHES = 27,                    /* "--"  */
  YYSYMBOL_DELETEWORD = 28,                /* "'delete'"  */
  YYSYMBOL_DNA = 29,                       /* "'DNA'"  */
  YYSYMBOL_ELLIPSES = 30,                  /* "..."  */
  YYSYMBOL_END = 31,                       /* "'end'"  */
  YYSYMBOL_ERROR = 32,                     /* "an error"  */
  YYSYMBOL_EVENT = 33,                     /* "'event'"  */
  YYSYMBOL_FORMULA = 34,                   /* "'formula'"  */
  YYSYMBOL_FUNCTION = 35,                  /* "name of an existing function"  */
  YYSYMBOL_FUNCTIONWORD = 36,              /* "'function'"  */
  YYSYMBOL_GENE = 37,                      /* "'gene'"  */
  YYSYMBOL_GEQ = 38,                       /* ">="  */
  YYSYMBOL_NEQ = 39,                       /* "!="  */
  YYSYMBOL_HASWORD = 40,                   /* "'has'"  */
  YYSYMBOL_IMPORT = 41,                    /* "'import'"  */
  YYSYMBOL_INWORD = 42,                    /* "'in'"  */
  YYSYMBOL_IS = 43,                        /* "'is'"  */
  YYSYMBOL_LEQ = 44,                       /* "<="  */
  YYSYMBOL_MAXIMIZEWORD = 45,              /* "'maximize'"  */
  YYSYMBOL_MINIMIZEWORD = 46,              /* "'minimize'"  */
  YYSYMBOL_MODNAME = 47,                   /* "name of an existing module"  */
  YYSYMBOL_MODULE = 48,                    /* "'model' or 'module'"  */
  YYSYMBOL_OPERATOR = 49,                  /* "'operator'"  */
  YYSYMBOL_REACTION = 50,                  /* "'reaction'"  */
  YYSYMBOL_SPECIES = 51,                   /* "'species'"  */
  YYSYMBOL_SUBSTONLY = 52,                 /* "'substanceOnly'"  */
  YYSYMBOL_TEXTSTRING = 53,                /* "text string"  */
  YYSYMBOL_UNITWORD = 54,                  /* "'unit'"  */
  YYSYMBOL_VARWORD = 55,                   /* "'var'"  */
  YYSYMBOL_56_ = 56,                       /* '('  */
  YYSYMBOL_57_ = 57,                       /* ')'  */
  YYSYMBOL_58_ = 58,                       /* ','  */
  YYSYMBOL_59_ = 59,                       /* '='  */
  YYSYMBOL_60_ = 60,                       /* ':'  */
  YYSYMBOL_61_ = 61,                       /* '\''  */
  YYSYMBOL_62_ = 62,                       /* ';'  */
  YYSYMBOL_63_ = 63,                       /* '{'  */
  YYSYMBOL_64_ = 64,                       /* '}'  */
  YYSYMBOL_65_ = 65,                       /* '!'  */
  YYSYMBOL_66_ = 66,                       /* '<'  */
  YYSYMBOL_67_ = 67,                       /* '>'  */
  YYSYMBOL_68_n_ = 68,                     /* '\n'  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_input = 70,                     /* input  */
  YYSYMBOL_import = 71,                    /* import  */
  YYSYMBOL_module = 72,                    /* module  */
  YYSYMBOL_73_1 = 73,                      /* $@1  */
  YYSYMBOL_74_2 = 74,                      /* $@2  */
  YYSYMBOL_maybemain = 75,                 /* maybemain  */
  YYSYMBOL_function = 76,                  /* function  */
  YYSYMBOL_77_3 = 77,                      /* $@3  */
  YYSYMBOL_spacedformula = 78,             /* spacedformula  */
  YYSYMBOL_variableexportlist = 79,        /* variableexportlist  */
  YYSYMBOL_variable = 80,                  /* variable  */
  YYSYMBOL_variablein = 81,                /* variablein  */
  YYSYMBOL_varmaybein = 82,                /* varmaybein  */
  YYSYMBOL_varmaybeis = 83,                /* varmaybeis  */
  YYSYMBOL_maybein = 84,                   /* maybein  */
  YYSYMBOL_modulebody = 85,                /* modulebody  */
  YYSYMBOL_modulepart = 86,                /* modulepart  */
  YYSYMBOL_reaction = 87,                  /* reaction  */
  YYSYMBOL_reactantList = 88,              /* reactantList  */
  YYSYMBOL_reactionDivider = 89,           /* reactionDivider  */
  YYSYMBOL_formula = 90,                   /* formula  */
  YYSYMBOL_commaformula = 91,              /* commaformula  */
  YYSYMBOL_mathThing = 92,                 /* mathThing  */
  YYSYMBOL_inequality = 93,                /* inequality  */
  YYSYMBOL_lineend = 94,                   /* lineend  */
  YYSYMBOL_assignment = 95,                /* assignment  */
  YYSYMBOL_submodule = 96,                 /* submodule  */
  YYSYMBOL_97_4 = 97,                      /* $@4  */
  YYSYMBOL_98_5 = 98,                      /* $@5  */
  YYSYMBOL_variableimportlist = 99,        /* variableimportlist  */
  YYSYMBOL_submodifications = 100,         /* submodifications  */
  YYSYMBOL_varinitialize = 101,            /* varinitialize  */
  YYSYMBOL_specinit = 102,                 /* specinit  */
  YYSYMBOL_formulainit = 103,              /* formulainit  */
  YYSYMBOL_reactioninit = 104,             /* reactioninit  */
  YYSYMBOL_dnainit = 105,                  /* dnainit  */
  YYSYMBOL_geneinit = 106,                 /* geneinit  */
  YYSYMBOL_operatorinit = 107,             /* operatorinit  */
  YYSYMBOL_compartmentinit = 108,          /* compartmentinit  */
  YYSYMBOL_varconstinit = 109,             /* varconstinit  */
  YYSYMBOL_unitinit = 110,                 /* unitinit  */
  YYSYMBOL_dnadef = 111,                   /* dnadef  */
  YYSYMBOL_dnastrand = 112,                /* dnastrand  */
  YYSYMBOL_dnamiddle = 113,                /* dnamiddle  */
  YYSYMBOL_event = 114,                    /* event  */
  YYSYMBOL_115_6 = 115,                    /* $@6  */
  YYSYMBOL_116_7 = 116,                    /* $@7  */
  YYSYMBOL_117_8 = 117,                    /* $@8  */
  YYSYMBOL_118_9 = 118,                    /* $@9  */
  YYSYMBOL_colonret = 119,                 /* colonret  */
  YYSYMBOL_eventmodifications = 120,       /* eventmodifications  */
  YYSYMBOL_assignmentlist = 121,           /* assignmentlist  */
  YYSYMBOL_deletion = 122,                 /* deletion  */
  YYSYMBOL_unitdef = 123,                  /* unitdef  */
  YYSYMBOL_constraint = 124,               /* constraint  */
  YYSYMBOL_objective = 125,                /* objective  */
  YYSYMBOL_maxormin = 126,                 /* maxormin  */
  YYSYMBOL_stringlist = 127,               /* stringlist  */
  YYSYMBOL_cvterm = 128,                   /* cvterm  */
  YYSYMBOL_toplevel_sbo = 129,             /* toplevel_sbo  */
  YYSYMBOL_modulename = 130,               /* modulename  */
  YYSYMBOL_functionname = 131,             /* functionname  */
  YYSYMBOL_modulecvterm = 132,             /* modulecvterm  */
  YYSYMBOL_functioncvterm = 133            /* functioncvterm  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined ANTIMONY_YYSTYPE_IS_TRIVIAL && ANTIMONY_YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   1112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  415

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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

#if ANTIMONY_YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   156,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   170,   188,   188,   194,   194,   200,
     201,   204,   205,   208,   208,   209,   210,   213,   214,   215,
     225,   226,   227,   230,   231,   237,   240,   243,   244,   247,
     248,   249,   250,   251,   254,   255,   258,   259,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   277,   285,   293,   301,   309,   317,   335,   336,   337,
     338,   339,   340,   344,   345,   346,   347,   348,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   373,   374,   377,   378,   379,   380,   381,   382,   383,
     386,   387,   388,   389,   390,   393,   394,   395,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   410,   410,   411,
     411,   415,   416,   417,   418,   419,   423,   424,   428,   432,
     433,   434,   435,   436,   437,   439,   440,   443,   444,   445,
     446,   447,   448,   449,   450,   453,   454,   455,   456,   459,
     460,   461,   462,   465,   466,   467,   468,   471,   472,   473,
     474,   477,   478,   479,   480,   484,   485,   486,   487,   490,
     491,   492,   495,   498,   501,   502,   505,   506,   507,   508,
     509,   512,   513,   516,   516,   517,   517,   518,   518,   519,
     519,   522,   523,   526,   527,   534,   535,   536,   537,   538,
     541,   542,   545,   560,   561,   562,   563,   564,   565,   568,
     571,   572,   575,   576,   577,   580,   583,   594,   606,   608,
     612,   613
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"",
  "\"mathematical symbol\"", "'&'", "'|'", "'-'", "'+'", "'*'", "'/'",
  "'%'", "'^'", "'$'", "'.'", "\"end of line\"", "\"number\"",
  "\"'after'\"", "\"element name\"", "\"'at'\"", "\"->\"", "\"-|\"",
  "\"-o\"", "\"=>\"", "\"'compartment'\"",
  "\"name of a pre-defined constant\"", "\"'constraint'\"", "\"'const'\"",
  "\"--\"", "\"'delete'\"", "\"'DNA'\"", "\"...\"", "\"'end'\"",
  "\"an error\"", "\"'event'\"", "\"'formula'\"",
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

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-314)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-68)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -314,   627,  -314,  -314,    74,    96,  -314,    28,   244,  -314,
    -314,  -314,  -314,  -314,    96,   244,    99,   188,    96,    96,
      96,  -314,    96,     3,   141,    96,   -28,  -314,  -314,   105,
     162,    96,    96,    96,    89,    96,   243,  -314,  -314,  -314,
    -314,  -314,   564,   155,   159,  -314,    29,   331,   157,  -314,
      29,    29,    29,    83,   110,   120,   126,   133,   145,   163,
     171,    29,    29,  -314,    96,    29,    34,    29,    29,  -314,
      29,  -314,  -314,  -314,  -314,  -314,   244,  -314,  -314,    45,
    -314,  -314,  -314,  -314,  -314,    45,  -314,  -314,   692,   147,
    -314,   256,  -314,  -314,  -314,    69,    96,    96,    96,    96,
      96,  -314,    96,   176,  -314,    87,    96,    45,  -314,  -314,
     196,   179,   183,  -314,  -314,  -314,  -314,  -314,   224,   179,
     190,  -314,  -314,  -314,  -314,   228,  -314,  -314,  -314,    96,
    -314,    26,    96,    96,    96,    96,    96,    96,    96,   200,
    -314,   230,   179,  -314,    96,    45,    96,  -314,   111,  -314,
     428,   195,  -314,   212,   189,    21,    96,   211,    -5,  -314,
    -314,  -314,    96,    96,    96,    96,    96,    96,    96,    96,
    -314,  -314,   169,  -314,    96,  -314,  -314,  -314,   884,  -314,
    -314,   884,   884,   269,   271,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,   226,  -314,  -314,
      45,  -314,  -314,  -314,  -314,  -314,   238,   241,   884,   884,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,    96,   169,   245,
    -314,    59,    29,   231,   248,    59,    29,   274,   257,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,    96,  -314,
     260,    45,     8,   884,  -314,  -314,   166,   884,  -314,   273,
    -314,   236,   331,   157,  -314,  -314,  -314,    96,   211,  -314,
       6,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,    45,   884,  -314,  -314,   884,   884,    68,  -314,    -8,
     -36,  -314,   884,  -314,  -314,   884,  -314,   310,    56,  -314,
    -314,    96,   318,  -314,  -314,  -314,    45,   201,   286,  1044,
     884,  -314,    96,    96,   756,  -314,   884,    37,    16,   884,
     884,    45,    45,   820,  -314,   820,  -314,  -314,  -314,  -314,
     326,  -314,    -3,   884,   884,  -314,  -314,   292,   221,    45,
    -314,  -314,   324,    96,   301,   940,  -314,    45,    45,  -314,
    -314,   274,  -314,    22,  -314,    96,  -314,   820,  -314,   -36,
     884,   299,  -314,    31,  -314,  -314,    29,    96,    62,  -314,
      45,   262,  -314,  -314,   884,   -36,   270,   820,  -314,   820,
      45,  -314,    -3,  -314,  -314,    84,   884,    29,    45,   342,
    -314,  1044,  -314,    -3,  -314,  -314,   820,  -314,  -314,   884,
     127,  -314,  -314,    29,   302,   992,   -36,  -314,    62,  -314,
      18,    20,   352,  -314,    -3,  -314,    96,  -314,    96,  -314,
    -314,    45,  -314,  -314,  -314
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    12,     0,     0,   107,     0,    33,    78,
      73,    74,    76,    77,     0,     0,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,   210,   211,     0,
      21,     0,     0,     0,     0,     0,     0,   105,   106,     3,
       4,     6,    37,    57,     0,     5,     0,     0,     0,    60,
       0,     0,     0,   129,   130,   131,   132,   133,   134,   135,
     136,     0,     0,   174,   180,     0,     0,     0,     0,    78,
       0,    11,     7,     8,     9,    10,     0,    75,    33,    35,
     103,   104,   101,   100,   102,    68,    78,    78,   183,    37,
      38,    39,   165,    78,    78,     0,     0,     0,     0,     0,
       0,   151,     0,     0,   170,   176,   177,   200,   153,   145,
       0,     0,     0,    23,    26,    25,   157,    14,     0,     0,
       0,   119,    22,    20,    19,     0,   161,   149,   137,     0,
     141,   173,     0,     0,     0,     0,     0,     0,     0,     0,
     169,     0,    33,   181,     0,    69,     0,    78,     0,    78,
       0,     0,    48,     0,     0,     0,     0,    67,     0,    49,
      50,    51,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    52,   178,    53,     0,    55,    58,    59,   209,    56,
      78,   203,   206,     0,     0,    94,    93,    95,    96,    99,
      97,    81,    78,    82,    79,    83,    78,     0,    78,    98,
      80,    86,    87,   193,    78,    78,     0,     0,   205,   207,
      78,   167,   155,   147,   159,   163,   139,     0,   179,     0,
     212,     0,     0,     0,     0,     0,     0,   121,    17,   140,
      78,   166,   154,   146,   158,   162,   150,   138,     0,    34,
     215,    36,     0,   202,   116,   113,   110,   109,    78,     0,
      78,    67,     0,     0,   175,    78,    78,     0,    70,    78,
       0,    78,   144,   148,   152,   156,   160,   164,   168,   171,
     182,   201,   204,    89,    90,   185,    91,     0,    88,     0,
       0,    43,    40,    78,    78,   208,   143,     0,     0,   221,
     219,    30,     0,   220,   218,   124,   122,     0,     0,     0,
     172,   142,     0,     0,   187,   117,   114,     0,     0,   108,
     115,    71,    72,    44,    78,    44,   193,    84,    78,    85,
       0,   191,     0,    41,    42,   217,   213,     0,     0,    31,
     216,   126,     0,    30,     0,     0,    46,   112,   111,    78,
     193,   121,    78,     0,    78,     0,    63,    44,    65,     0,
      92,     0,   192,     0,   184,   214,    78,     0,    44,   125,
     123,     0,    18,    47,   189,     0,     0,    44,    78,    44,
      45,    62,     0,    78,    78,     0,    27,    78,    32,     0,
     120,     0,   193,     0,   126,    64,    44,    66,   186,   194,
     195,    24,    29,    28,     0,     0,     0,   188,    44,    61,
       0,     0,     0,    16,     0,   118,     0,   198,     0,   196,
     128,   127,   190,   199,   197
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,    -7,
      39,    -1,    25,    27,   399,  -305,    -4,     0,  -314,   -43,
     -40,   261,   175,  -314,     4,     9,  -314,  -314,  -314,  -314,
      33,    -6,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,   229,   358,  -314,  -314,  -314,  -314,  -314,
    -246,  -313,  -139,  -314,   177,  -314,  -314,   233,  -111,  -314,
    -314,  -314,  -314,  -314,  -314
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    39,    40,   298,   299,   125,    41,   223,   375,
     328,    89,    90,    91,    92,   346,   335,   336,    46,    47,
      48,   243,   277,   201,   202,    49,    50,    51,   341,   227,
     297,   358,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   203,   316,   340,   382,
     322,   280,   354,    66,   244,    67,    68,    69,   221,    70,
      71,    72,    73,    74,    75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    45,   154,   349,    79,   158,    85,   155,   225,     5,
     348,    86,    87,   154,    78,    95,   110,   105,   107,    93,
     111,   141,   320,   154,   321,   117,    43,   365,    44,   154,
       5,   240,     5,     5,   131,    78,   156,    78,    78,   141,
       5,   145,   371,     6,   141,    78,   112,   157,     6,     5,
     318,   302,   156,   380,    78,   152,   319,   261,   141,   159,
     160,   161,   385,   172,   387,   352,    80,    81,   314,   396,
     170,   171,    82,     6,   173,   175,   176,   177,   344,   179,
     180,   399,   141,   259,   368,   230,   406,   200,   408,    76,
     374,    37,   174,   405,    83,    84,    37,    38,     6,   342,
     141,     5,    38,   372,   345,   218,    78,   252,     5,   326,
     253,     5,   260,    78,   143,   391,    78,   288,   118,   383,
     379,    37,   119,     5,   327,   317,   318,    38,    78,   210,
      77,   183,   184,   185,   186,   187,   188,   189,   190,     5,
     129,   162,   191,   241,    78,   242,    37,   246,   120,   251,
     404,   193,    38,   258,   157,    85,   145,   194,   113,    94,
     141,   121,   195,   -38,   245,    80,    81,   146,   163,     5,
     122,    82,   156,   271,    78,   303,   114,   200,   164,   141,
     200,   200,   141,   196,   165,   400,   197,   401,   115,   144,
     198,   166,   199,    83,    84,   -38,   270,   123,   -38,   147,
       5,     5,   148,   167,   257,    78,    78,   200,   200,   124,
     308,    96,   307,   219,   -38,   -38,   -38,    97,   149,   150,
     151,   168,    98,     5,   141,    99,   296,   217,    78,   169,
     289,   290,   220,   388,   293,   294,   222,   100,   101,   102,
     103,   224,   200,   226,   397,   228,   200,   239,     5,   141,
     145,   238,   157,    78,   256,     5,   311,   312,   331,   332,
      78,   407,   409,   143,   343,   412,   132,   413,    77,   414,
      88,   200,   133,   273,   200,   200,   274,   134,   356,   357,
     135,   200,    80,    81,   200,   278,     5,   291,    82,   295,
     329,    78,   136,   137,   138,   139,   204,   283,    42,   200,
     284,   337,   338,   200,   287,   200,   157,   292,   200,   200,
      83,    84,   200,   -15,   200,   205,   206,   207,   288,   381,
     357,   353,   200,   200,    43,   325,    44,   384,   332,   305,
     178,   360,   329,   330,    42,   363,     5,   153,   154,   359,
     296,    78,   333,   351,   370,   355,   200,   181,   182,   200,
      10,    11,    12,    13,   208,   209,   378,   121,   373,   394,
      43,   402,    44,   200,     5,   377,   200,   410,   200,    78,
     393,   353,   361,   279,   366,   200,   106,   395,   398,   254,
      42,   281,   353,   255,   392,   200,   377,     0,   200,   200,
       0,     0,     0,     0,    42,   363,     0,     0,     0,   353,
     353,   411,   392,   353,     0,   353,    43,   353,    44,     0,
     247,     0,     0,     0,     0,     0,   104,     0,     0,   108,
      43,   109,    44,     0,   116,     0,     0,     0,     0,     0,
     126,   127,   128,   130,   153,   140,     0,     0,     0,     0,
       5,   272,     0,   156,     0,    78,   248,    10,    11,    12,
      13,     0,     0,   275,     0,    18,     0,   276,     0,   276,
       0,     0,     0,     0,     0,     0,   282,     0,     0,     0,
       0,   285,     0,    27,    28,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   250,     0,     0,
       0,   300,     0,     0,     0,   211,   212,   213,   214,   215,
       0,   216,     0,     0,     0,     0,     0,     0,     0,   304,
       0,   306,     0,     0,     0,     0,   309,   310,     0,     0,
     313,     0,   315,     0,     0,     0,     0,     0,   229,     0,
       0,   231,   232,   233,   234,   235,   236,   237,     0,     0,
       0,     0,     0,     0,   323,   324,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,   263,   264,   265,   266,   267,   268,   269,     0,
     -67,   -67,     0,     0,     0,   347,     5,   141,     0,   350,
       0,   142,     0,   -67,   -67,   -67,   -67,     0,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,     0,     0,
     364,     0,     0,   367,     0,   369,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   286,   376,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     3,   386,
       0,     0,     0,     4,   389,   390,     0,   301,   376,     5,
       0,     6,     7,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,    21,
       0,    22,    23,    24,    25,     0,     0,     0,    26,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
       0,    35,    36,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,    38,   183,   184,   185,   186,
     187,   188,   189,   190,     5,     0,     0,   191,   192,    78,
       0,     0,     0,     0,     0,     0,   193,     0,     0,     0,
       0,     0,   194,     0,     0,     0,     0,   195,     0,     0,
      80,    81,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   196,     0,
       0,   197,     0,     0,     0,   198,     0,   199,    83,    84,
     183,   184,   185,   186,   187,   188,   189,   190,     5,     0,
       0,   191,   339,    78,     0,     0,     0,     0,     0,     0,
     193,     0,     0,     0,     0,     0,   194,     0,     0,     0,
       0,   195,     0,     0,    80,    81,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   196,     0,     0,   197,     0,     0,     0,   198,
       0,   199,    83,    84,   183,   184,   185,   186,   187,   188,
     189,   190,     5,     0,     0,   191,     0,    78,     0,     0,
       0,     0,     0,     0,   193,     0,     0,     0,     0,     0,
     194,     0,     0,     0,     0,   195,     0,     0,    80,    81,
       0,     0,   345,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   196,     0,     0,   197,
       0,     0,     0,   198,     0,   199,    83,    84,   183,   184,
     185,   186,   187,   188,   189,   190,     5,     0,     0,   191,
       0,    78,     0,     0,     0,     0,     0,     0,   193,     0,
       0,     0,     0,     0,   194,     0,     0,     0,     0,   195,
       0,     0,    80,    81,     0,     0,     0,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     196,     0,     0,   197,     0,     0,     4,   198,     0,   199,
      83,    84,     5,     0,     6,     7,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,   362,     0,     0,    22,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,    27,    28,   334,     0,    31,
      32,    33,    34,     0,    35,    36,     0,     0,     4,     0,
       0,     0,    37,     0,     5,     0,     6,     7,    38,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,   403,     0,     0,    22,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,    27,    28,   334,
       0,    31,    32,    33,    34,     0,    35,    36,     0,     0,
       4,     0,     0,     0,    37,     0,     5,     0,     6,     7,
      38,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,    22,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,    27,
      28,   334,     0,    31,    32,    33,    34,     0,    35,    36,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,    38
};

static const yytype_int16 yycheck[] =
{
       1,     1,     7,   316,     5,    48,     7,    47,   119,    12,
     315,     7,     8,     7,    17,    16,    13,    18,    19,    15,
      17,    13,    58,     7,    60,    53,     1,   340,     1,     7,
      12,   142,    12,    12,    35,    17,    15,    17,    17,    13,
      12,    42,   347,    14,    13,    17,    43,    48,    14,    12,
      58,    43,    15,   358,    17,    46,    64,    62,    13,    50,
      51,    52,   367,    64,   369,    68,    38,    39,    62,   382,
      61,    62,    44,    14,    65,    66,    67,    68,    62,    70,
      76,   386,    13,    62,    62,    59,    68,    88,    68,    15,
      59,    62,    58,   398,    66,    67,    62,    68,    14,    62,
      13,    12,    68,   349,    42,   106,    17,   150,    12,    53,
     150,    12,   155,    17,    27,    31,    17,    58,    13,   365,
      58,    62,    17,    12,    68,    57,    58,    68,    17,    60,
      56,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      51,    58,    15,   144,    17,   146,    62,   148,    43,   150,
     396,    24,    68,   154,   155,   156,   157,    30,    17,    60,
      13,    56,    35,     8,    53,    38,    39,     8,    58,    12,
       8,    44,    15,   174,    17,     9,    35,   178,    58,    13,
     181,   182,    13,    56,    58,    58,    59,    60,    47,    42,
      63,    58,    65,    66,    67,    40,    27,    35,    43,    40,
      12,    12,    43,    58,    15,    17,    17,   208,   209,    47,
     253,    23,   252,    17,    59,    60,    61,    29,    59,    60,
      61,    58,    34,    12,    13,    37,   227,    51,    17,    58,
     221,   222,    53,   372,   225,   226,    53,    49,    50,    51,
      52,    17,   243,    53,   383,    17,   247,    17,    12,    13,
     251,    51,   253,    17,    59,    12,   257,   258,    57,    58,
      17,   400,   401,    27,   307,   404,    23,   406,    56,   408,
       9,   272,    29,     4,   275,   276,     5,    34,    57,    58,
      37,   282,    38,    39,   285,    59,    12,    56,    44,    15,
     291,    17,    49,    50,    51,    52,    40,    59,   299,   300,
      59,   302,   303,   304,    59,   306,   307,    59,   309,   310,
      66,    67,   313,    56,   315,    59,    60,    61,    58,    57,
      58,   322,   323,   324,   299,    15,   299,    57,    58,    56,
      69,   332,   333,    15,   335,   335,    12,     6,     7,    15,
     341,    17,    56,    17,   345,    53,   347,    86,    87,   350,
      19,    20,    21,    22,    93,    94,   357,    56,    59,    17,
     335,    59,   335,   364,    12,   356,   367,    15,   369,    17,
     377,   372,   333,   198,   341,   376,    18,   381,   384,   150,
     381,   204,   383,   150,   375,   386,   377,    -1,   389,   390,
      -1,    -1,    -1,    -1,   395,   395,    -1,    -1,    -1,   400,
     401,   402,   393,   404,    -1,   406,   381,   408,   381,    -1,
     149,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,
     395,    22,   395,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,     6,    36,    -1,    -1,    -1,    -1,
      12,   180,    -1,    15,    -1,    17,    18,    19,    20,    21,
      22,    -1,    -1,   192,    -1,    27,    -1,   196,    -1,   198,
      -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,   210,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    96,    97,    98,    99,   100,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
      -1,   250,    -1,    -1,    -1,    -1,   255,   256,    -1,    -1,
     259,    -1,   261,    -1,    -1,    -1,    -1,    -1,   129,    -1,
      -1,   132,   133,   134,   135,   136,   137,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   283,   284,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
       6,     7,    -1,    -1,    -1,   314,    12,    13,    -1,   318,
      -1,    17,    -1,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     339,    -1,    -1,   342,    -1,   344,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   356,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,   368,
      -1,    -1,    -1,     6,   373,   374,    -1,   238,   377,    12,
      -1,    14,    15,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      -1,    34,    35,    36,    37,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    -1,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    59,    -1,    -1,    -1,    63,    -1,    65,    66,    67,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    -1,    63,
      -1,    65,    66,    67,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    15,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    38,    39,
      -1,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
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
      83,    13,    17,    27,    42,    80,     8,    40,    43,    59,
      60,    61,    94,     6,     7,    89,    15,    80,    88,    94,
      94,    94,    58,    58,    58,    58,    58,    58,    58,    58,
      94,    94,    80,    94,    58,    94,    94,    94,    90,    94,
      93,    90,    90,     4,     5,     6,     7,     8,     9,    10,
      11,    15,    16,    24,    30,    35,    56,    59,    63,    65,
      80,    92,    93,   115,    40,    59,    60,    61,    90,    90,
      60,    83,    83,    83,    83,    83,    83,    51,    80,    17,
      53,   127,    53,    77,    17,   127,    53,    98,    17,    83,
      59,    83,    83,    83,    83,    83,    83,    83,    51,    17,
     127,    80,    80,    90,   123,    53,    80,    90,    18,    47,
      59,    80,    88,    89,   112,   126,    59,    15,    80,    62,
      88,    62,    83,    83,    83,    83,    83,    83,    83,    83,
      27,    80,    90,     4,     5,    90,    90,    91,    59,    91,
     120,   123,    90,    59,    59,    90,    83,    59,    58,    94,
      94,    56,    59,    94,    94,    15,    80,    99,    73,    74,
      90,    83,    43,     9,    90,    56,    90,    89,    88,    90,
      90,    80,    80,    90,    62,    90,   116,    57,    58,    64,
      58,    60,   119,    90,    90,    15,    53,    68,    79,    80,
      15,    57,    58,    56,    47,    85,    86,    80,    80,    16,
     117,    97,    62,    88,    62,    42,    84,    90,    84,   120,
      90,    17,    68,    80,   121,    53,    57,    58,   100,    15,
      80,    79,    31,    86,    90,   120,    99,    90,    62,    90,
      80,    84,   119,    59,    59,    78,    90,    94,    80,    58,
      84,    57,   118,   119,    57,    84,    90,    84,   121,    90,
      90,    31,    94,    78,    17,    85,   120,   121,   100,    84,
      58,    60,    59,    31,   119,    84,    68,   121,    68,   121,
      15,    80,   121,   121,   121
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    71,    73,    72,    74,    72,    72,
      72,    75,    75,    77,    76,    76,    76,    78,    78,    78,
      79,    79,    79,    80,    80,    80,    81,    82,    82,    83,
      83,    83,    83,    83,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    87,    87,    87,    87,    87,    87,    88,    88,    88,
      88,    88,    88,    89,    89,    89,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    91,    91,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    93,    93,    93,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    97,    96,    98,
      96,    99,    99,    99,    99,    99,   100,   100,   100,   101,
     101,   101,   101,   101,   101,   101,   101,   102,   102,   102,
     102,   102,   102,   102,   102,   103,   103,   103,   103,   104,
     104,   104,   104,   105,   105,   105,   105,   106,   106,   106,
     106,   107,   107,   107,   107,   108,   108,   108,   108,   109,
     109,   109,   110,   110,   111,   111,   112,   112,   112,   112,
     112,   113,   113,   115,   114,   116,   114,   117,   114,   118,
     114,   119,   119,   120,   120,   121,   121,   121,   121,   121,
     122,   122,   123,   124,   124,   124,   124,   124,   124,   125,
     126,   126,   127,   127,   127,   128,   129,   129,   130,   131,
     132,   133
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     0,     9,     0,     6,     2,
       2,     0,     1,     0,     8,     2,     2,     1,     2,     2,
       0,     1,     3,     1,     3,     2,     3,     1,     1,     1,
       3,     4,     4,     3,     0,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     2,
       1,     8,     6,     5,     7,     5,     7,     1,     2,     2,
       3,     4,     4,     1,     1,     2,     1,     1,     0,     2,
       2,     2,     2,     2,     4,     4,     2,     2,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       3,     5,     5,     3,     4,     4,     3,     0,     9,     0,
       7,     0,     1,     3,     1,     3,     0,     5,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       3,     2,     4,     4,     3,     2,     3,     3,     3,     2,
       3,     2,     3,     2,     3,     3,     3,     2,     3,     3,
       3,     2,     3,     3,     3,     2,     3,     3,     3,     2,
       2,     3,     4,     2,     1,     3,     2,     2,     2,     3,
       1,     2,     3,     0,     6,     0,     8,     0,     8,     0,
      10,     1,     2,     0,     5,     3,     5,     6,     5,     6,
       2,     3,     1,     3,     4,     3,     3,     3,     4,     2,
       1,     1,     1,     3,     4,     3,     5,     5,     4,     4,
       4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = ANTIMONY_YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == ANTIMONY_YYEMPTY)                                        \
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

/* Backward compatibility with an undocumented macro.
   Use ANTIMONY_YYerror or ANTIMONY_YYUNDEF. */
#define YYERRCODE ANTIMONY_YYUNDEF


/* Enable debugging if requested.  */
#if ANTIMONY_YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
#else /* !ANTIMONY_YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !ANTIMONY_YYDEBUG */


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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = ANTIMONY_YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == ANTIMONY_YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= ANTIMONY_YYEOF)
    {
      yychar = ANTIMONY_YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == ANTIMONY_YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = ANTIMONY_YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = ANTIMONY_YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 3: /* input: input import  */
#line 157 "antimony.ypp"
                             {}
#line 2058 "antimony.tab.cpp"
    break;

  case 4: /* input: input module  */
#line 158 "antimony.ypp"
                             { /*cout << endl << $2->ToString() << endl << endl;*/ }
#line 2064 "antimony.tab.cpp"
    break;

  case 5: /* input: input modulepart  */
#line 159 "antimony.ypp"
                                 {}
#line 2070 "antimony.tab.cpp"
    break;

  case 6: /* input: input function  */
#line 160 "antimony.ypp"
                               {}
#line 2076 "antimony.tab.cpp"
    break;

  case 7: /* input: input modulename  */
#line 161 "antimony.ypp"
                                 {}
#line 2082 "antimony.tab.cpp"
    break;

  case 8: /* input: input functionname  */
#line 162 "antimony.ypp"
                                   {}
#line 2088 "antimony.tab.cpp"
    break;

  case 9: /* input: input modulecvterm  */
#line 163 "antimony.ypp"
                                   {}
#line 2094 "antimony.tab.cpp"
    break;

  case 10: /* input: input functioncvterm  */
#line 164 "antimony.ypp"
                                     {}
#line 2100 "antimony.tab.cpp"
    break;

  case 11: /* input: input toplevel_sbo  */
#line 165 "antimony.ypp"
                                   {}
#line 2106 "antimony.tab.cpp"
    break;

  case 12: /* input: input error  */
#line 166 "antimony.ypp"
                            {YYABORT;}
#line 2112 "antimony.tab.cpp"
    break;

  case 13: /* input: input "an error"  */
#line 167 "antimony.ypp"
                            {YYABORT;}
#line 2118 "antimony.tab.cpp"
    break;

  case 14: /* import: "'import'" "text string"  */
#line 170 "antimony.ypp"
                                  { if (g_registry.OpenFile(*((yyvsp[0].word)))==0) YYABORT;}
#line 2124 "antimony.tab.cpp"
    break;

  case 15: /* $@1: %empty  */
#line 188 "antimony.ypp"
                                         {g_registry.NewCurrentModule((yyvsp[0].word), NULL, (yyvsp[-1].maybemain));}
#line 2130 "antimony.tab.cpp"
    break;

  case 16: /* module: "'model' or 'module'" maybemain "element name" $@1 '(' variableexportlist ')' modulebody "'end'"  */
#line 189 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2140 "antimony.tab.cpp"
    break;

  case 17: /* $@2: %empty  */
#line 194 "antimony.ypp"
                                         {g_registry.NewCurrentModule((yyvsp[0].word), NULL, (yyvsp[-1].maybemain));}
#line 2146 "antimony.tab.cpp"
    break;

  case 18: /* module: "'model' or 'module'" maybemain "element name" $@2 modulebody "'end'"  */
#line 195 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2156 "antimony.tab.cpp"
    break;

  case 19: /* module: "'model' or 'module'" "name of an existing module"  */
#line 200 "antimony.ypp"
                               {g_registry.SetError("module '" + *((yyvsp[0].word)) + "' already defined."); YYABORT;}
#line 2162 "antimony.tab.cpp"
    break;

  case 20: /* module: "'model' or 'module'" "name of an existing function"  */
#line 201 "antimony.ypp"
                                {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a module because it is already a defined function."); YYABORT;}
#line 2168 "antimony.tab.cpp"
    break;

  case 21: /* maybemain: %empty  */
#line 204 "antimony.ypp"
                            {(yyval.maybemain) = false;}
#line 2174 "antimony.tab.cpp"
    break;

  case 22: /* maybemain: '*'  */
#line 205 "antimony.ypp"
                    {(yyval.maybemain) = true;}
#line 2180 "antimony.tab.cpp"
    break;

  case 23: /* $@3: %empty  */
#line 208 "antimony.ypp"
                                     {g_registry.NewUserFunction((yyvsp[0].word));}
#line 2186 "antimony.tab.cpp"
    break;

  case 24: /* function: "'function'" "element name" $@3 '(' variableexportlist ')' spacedformula "'end'"  */
#line 208 "antimony.ypp"
                                                                                                                    {if (g_registry.SetUserFunction((yyvsp[-1].formula))) YYABORT;}
#line 2192 "antimony.tab.cpp"
    break;

  case 25: /* function: "'function'" "name of an existing module"  */
#line 209 "antimony.ypp"
                                     {g_registry.SetError("Cannot use '" + *((yyvsp[0].word)) +"' as a function name because it is already the name of a module."); YYABORT;}
#line 2198 "antimony.tab.cpp"
    break;

  case 26: /* function: "'function'" "name of an existing function"  */
#line 210 "antimony.ypp"
                                      {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a new function because it is already a defined function."); YYABORT;}
#line 2204 "antimony.tab.cpp"
    break;

  case 27: /* spacedformula: formula  */
#line 213 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2210 "antimony.tab.cpp"
    break;

  case 28: /* spacedformula: lineend spacedformula  */
#line 214 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[0].formula);}
#line 2216 "antimony.tab.cpp"
    break;

  case 29: /* spacedformula: spacedformula lineend  */
#line 215 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[-1].formula);}
#line 2222 "antimony.tab.cpp"
    break;

  case 30: /* variableexportlist: %empty  */
#line 225 "antimony.ypp"
                            {}
#line 2228 "antimony.tab.cpp"
    break;

  case 31: /* variableexportlist: variable  */
#line 226 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2234 "antimony.tab.cpp"
    break;

  case 32: /* variableexportlist: variableexportlist ',' variable  */
#line 227 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2240 "antimony.tab.cpp"
    break;

  case 33: /* variable: "element name"  */
#line 230 "antimony.ypp"
                        {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[0].word)); }
#line 2246 "antimony.tab.cpp"
    break;

  case 34: /* variable: variable '.' "element name"  */
#line 231 "antimony.ypp"
                                     {(yyval.variable) = (yyvsp[-2].variable)->GetSubVariable((yyvsp[0].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[0].word)) + "' is not a subvariable of '" + (yyvsp[-2].variable)->GetNameDelimitedBy(".") + "'.");
                    YYABORT;
                  }
                }
#line 2257 "antimony.tab.cpp"
    break;

  case 35: /* variable: '$' variable  */
#line 237 "antimony.ypp"
                             {(yyval.variable) = (yyvsp[0].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;}
#line 2263 "antimony.tab.cpp"
    break;

  case 36: /* variablein: variable "'in'" variable  */
#line 240 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetCompartment((yyvsp[0].variable))) YYABORT; (yyval.variable) = (yyvsp[-2].variable);}
#line 2269 "antimony.tab.cpp"
    break;

  case 37: /* varmaybein: variable  */
#line 243 "antimony.ypp"
                         {(yyval.variable) = (yyvsp[0].variable);}
#line 2275 "antimony.tab.cpp"
    break;

  case 38: /* varmaybein: variablein  */
#line 244 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2281 "antimony.tab.cpp"
    break;

  case 39: /* varmaybeis: varmaybein  */
#line 247 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2287 "antimony.tab.cpp"
    break;

  case 40: /* varmaybeis: varmaybein '=' formula  */
#line 248 "antimony.ypp"
                                       {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2293 "antimony.tab.cpp"
    break;

  case 41: /* varmaybeis: varmaybein ':' '=' formula  */
#line 249 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT; }
#line 2299 "antimony.tab.cpp"
    break;

  case 42: /* varmaybeis: varmaybein '\'' '=' formula  */
#line 250 "antimony.ypp"
                                            {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT; }
#line 2305 "antimony.tab.cpp"
    break;

  case 43: /* varmaybeis: varmaybein "'has'" unitdef  */
#line 251 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2311 "antimony.tab.cpp"
    break;

  case 44: /* maybein: %empty  */
#line 254 "antimony.ypp"
                            {(yyval.variable) = NULL;}
#line 2317 "antimony.tab.cpp"
    break;

  case 45: /* maybein: "'in'" variable  */
#line 255 "antimony.ypp"
                                {(yyval.variable) = (yyvsp[0].variable);}
#line 2323 "antimony.tab.cpp"
    break;

  case 46: /* modulebody: modulepart  */
#line 258 "antimony.ypp"
                           {}
#line 2329 "antimony.tab.cpp"
    break;

  case 47: /* modulebody: modulebody modulepart  */
#line 259 "antimony.ypp"
                                      {}
#line 2335 "antimony.tab.cpp"
    break;

  case 48: /* modulepart: reaction lineend  */
#line 262 "antimony.ypp"
                                 {}
#line 2341 "antimony.tab.cpp"
    break;

  case 49: /* modulepart: assignment lineend  */
#line 263 "antimony.ypp"
                                   {}
#line 2347 "antimony.tab.cpp"
    break;

  case 50: /* modulepart: submodule lineend  */
#line 264 "antimony.ypp"
                                  {}
#line 2353 "antimony.tab.cpp"
    break;

  case 51: /* modulepart: varinitialize lineend  */
#line 265 "antimony.ypp"
                                      {}
#line 2359 "antimony.tab.cpp"
    break;

  case 52: /* modulepart: dnadef lineend  */
#line 266 "antimony.ypp"
                               {}
#line 2365 "antimony.tab.cpp"
    break;

  case 53: /* modulepart: event lineend  */
#line 267 "antimony.ypp"
                              {}
#line 2371 "antimony.tab.cpp"
    break;

  case 54: /* modulepart: unitinit lineend  */
#line 268 "antimony.ypp"
                                 {}
#line 2377 "antimony.tab.cpp"
    break;

  case 55: /* modulepart: deletion lineend  */
#line 269 "antimony.ypp"
                                 {}
#line 2383 "antimony.tab.cpp"
    break;

  case 56: /* modulepart: cvterm lineend  */
#line 270 "antimony.ypp"
                               {}
#line 2389 "antimony.tab.cpp"
    break;

  case 57: /* modulepart: variablein  */
#line 271 "antimony.ypp"
                           {}
#line 2395 "antimony.tab.cpp"
    break;

  case 58: /* modulepart: constraint lineend  */
#line 272 "antimony.ypp"
                                   {}
#line 2401 "antimony.tab.cpp"
    break;

  case 59: /* modulepart: objective lineend  */
#line 273 "antimony.ypp"
                                  {}
#line 2407 "antimony.tab.cpp"
    break;

  case 60: /* modulepart: lineend  */
#line 274 "antimony.ypp"
                        {}
#line 2413 "antimony.tab.cpp"
    break;

  case 61: /* reaction: varmaybein ':' reactantList reactionDivider reactantList ';' formula maybein  */
#line 278 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-7].variable), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-7].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2425 "antimony.tab.cpp"
    break;

  case 62: /* reaction: reactantList reactionDivider reactantList ';' formula maybein  */
#line 286 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2437 "antimony.tab.cpp"
    break;

  case 63: /* reaction: reactantList reactionDivider ';' formula maybein  */
#line 294 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2449 "antimony.tab.cpp"
    break;

  case 64: /* reaction: varmaybein ':' reactantList reactionDivider ';' formula maybein  */
#line 302 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2461 "antimony.tab.cpp"
    break;

  case 65: /* reaction: reactionDivider reactantList ';' formula maybein  */
#line 310 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2473 "antimony.tab.cpp"
    break;

  case 66: /* reaction: varmaybein ':' reactionDivider reactantList ';' formula maybein  */
#line 318 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2485 "antimony.tab.cpp"
    break;

  case 67: /* reactantList: variable  */
#line 335 "antimony.ypp"
                         {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2491 "antimony.tab.cpp"
    break;

  case 68: /* reactantList: "number" variable  */
#line 336 "antimony.ypp"
                             {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2497 "antimony.tab.cpp"
    break;

  case 69: /* reactantList: variable variable  */
#line 337 "antimony.ypp"
                                  {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2503 "antimony.tab.cpp"
    break;

  case 70: /* reactantList: reactantList '+' variable  */
#line 338 "antimony.ypp"
                                          {(yyval.reactantList) = (yyvsp[-2].reactantList); if((yyvsp[-2].reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2509 "antimony.tab.cpp"
    break;

  case 71: /* reactantList: reactantList '+' "number" variable  */
#line 339 "antimony.ypp"
                                              {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2515 "antimony.tab.cpp"
    break;

  case 72: /* reactantList: reactantList '+' variable variable  */
#line 340 "antimony.ypp"
                                                   {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2521 "antimony.tab.cpp"
    break;

  case 73: /* reactionDivider: "->"  */
#line 344 "antimony.ypp"
                           {(yyval.reactionDivider) = rdBecomes;}
#line 2527 "antimony.tab.cpp"
    break;

  case 74: /* reactionDivider: "-|"  */
#line 345 "antimony.ypp"
                           {(yyval.reactionDivider) = rdInhibits;}
#line 2533 "antimony.tab.cpp"
    break;

  case 75: /* reactionDivider: '-' '('  */
#line 346 "antimony.ypp"
                        {(yyval.reactionDivider) = rdInfluences;}
#line 2539 "antimony.tab.cpp"
    break;

  case 76: /* reactionDivider: "-o"  */
#line 347 "antimony.ypp"
                            {(yyval.reactionDivider) = rdInfluences;}
#line 2545 "antimony.tab.cpp"
    break;

  case 77: /* reactionDivider: "=>"  */
#line 348 "antimony.ypp"
                             {(yyval.reactionDivider) = rdBecomesIrreversibly;}
#line 2551 "antimony.tab.cpp"
    break;

  case 78: /* formula: %empty  */
#line 352 "antimony.ypp"
                            {(yyval.formula) = g_registry.NewBlankFormula(); }
#line 2557 "antimony.tab.cpp"
    break;

  case 79: /* formula: formula "..."  */
#line 353 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddEllipses();}
#line 2563 "antimony.tab.cpp"
    break;

  case 80: /* formula: formula variable  */
#line 354 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); if((yyvsp[-1].formula)->AddVariable((yyvsp[0].variable))) YYABORT; }
#line 2569 "antimony.tab.cpp"
    break;

  case 81: /* formula: formula "number"  */
#line 355 "antimony.ypp"
                             {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddNum((yyvsp[0].num)); }
#line 2575 "antimony.tab.cpp"
    break;

  case 82: /* formula: formula "name of a pre-defined constant"  */
#line 356 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2581 "antimony.tab.cpp"
    break;

  case 83: /* formula: formula "name of an existing function"  */
#line 357 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2587 "antimony.tab.cpp"
    break;

  case 84: /* formula: formula '(' commaformula ')'  */
#line 358 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2593 "antimony.tab.cpp"
    break;

  case 85: /* formula: formula '{' commaformula '}'  */
#line 359 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddCurlyBrackets(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2599 "antimony.tab.cpp"
    break;

  case 86: /* formula: formula mathThing  */
#line 360 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddMathThing((yyvsp[0].character)); }
#line 2605 "antimony.tab.cpp"
    break;

  case 87: /* formula: formula inequality  */
#line 361 "antimony.ypp"
                                   {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddInequality((yyvsp[0].inequality)); }
#line 2611 "antimony.tab.cpp"
    break;

  case 88: /* formula: formula '=' '='  */
#line 362 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('='); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2617 "antimony.tab.cpp"
    break;

  case 89: /* formula: formula '&' '&'  */
#line 363 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('&'); (yyvsp[-2].formula)->AddMathThing('&'); }
#line 2623 "antimony.tab.cpp"
    break;

  case 90: /* formula: formula '|' '|'  */
#line 364 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('|'); (yyvsp[-2].formula)->AddMathThing('|'); }
#line 2629 "antimony.tab.cpp"
    break;

  case 91: /* commaformula: formula  */
#line 373 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2635 "antimony.tab.cpp"
    break;

  case 92: /* commaformula: commaformula ',' formula  */
#line 374 "antimony.ypp"
                                         {(yyval.formula) = (yyvsp[-2].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[0].formula)); }
#line 2641 "antimony.tab.cpp"
    break;

  case 93: /* mathThing: '+'  */
#line 377 "antimony.ypp"
                    {(yyval.character) = '+';}
#line 2647 "antimony.tab.cpp"
    break;

  case 94: /* mathThing: '-'  */
#line 378 "antimony.ypp"
                    {(yyval.character) = '-';}
#line 2653 "antimony.tab.cpp"
    break;

  case 95: /* mathThing: '*'  */
#line 379 "antimony.ypp"
                    {(yyval.character) = '*';}
#line 2659 "antimony.tab.cpp"
    break;

  case 96: /* mathThing: '/'  */
#line 380 "antimony.ypp"
                    {(yyval.character) = '/';}
#line 2665 "antimony.tab.cpp"
    break;

  case 97: /* mathThing: '^'  */
#line 381 "antimony.ypp"
                    {(yyval.character) = '^';}
#line 2671 "antimony.tab.cpp"
    break;

  case 98: /* mathThing: '!'  */
#line 382 "antimony.ypp"
                    {(yyval.character) = '!';}
#line 2677 "antimony.tab.cpp"
    break;

  case 99: /* mathThing: '%'  */
#line 383 "antimony.ypp"
                    {(yyval.character) = '%';}
#line 2683 "antimony.tab.cpp"
    break;

  case 100: /* inequality: '<'  */
#line 386 "antimony.ypp"
                    {(yyval.inequality) = constLT;}
#line 2689 "antimony.tab.cpp"
    break;

  case 101: /* inequality: "<="  */
#line 387 "antimony.ypp"
                    {(yyval.inequality) = constLEQ;}
#line 2695 "antimony.tab.cpp"
    break;

  case 102: /* inequality: '>'  */
#line 388 "antimony.ypp"
                    {(yyval.inequality) = constGT;}
#line 2701 "antimony.tab.cpp"
    break;

  case 103: /* inequality: ">="  */
#line 389 "antimony.ypp"
                    {(yyval.inequality) = constGEQ;}
#line 2707 "antimony.tab.cpp"
    break;

  case 104: /* inequality: "!="  */
#line 390 "antimony.ypp"
                    {(yyval.inequality) = constNEQ;}
#line 2713 "antimony.tab.cpp"
    break;

  case 105: /* lineend: ';'  */
#line 393 "antimony.ypp"
                    {}
#line 2719 "antimony.tab.cpp"
    break;

  case 106: /* lineend: '\n'  */
#line 394 "antimony.ypp"
                     {}
#line 2725 "antimony.tab.cpp"
    break;

  case 107: /* lineend: "end of line"  */
#line 395 "antimony.ypp"
                    {}
#line 2731 "antimony.tab.cpp"
    break;

  case 108: /* assignment: varmaybein ':' maxormin formula  */
#line 398 "antimony.ypp"
                                                {if (g_registry.CurrentModule()->AddObjective((yyvsp[-3].variable), (yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 2737 "antimony.tab.cpp"
    break;

  case 109: /* assignment: varmaybein '=' formula  */
#line 399 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2743 "antimony.tab.cpp"
    break;

  case 110: /* assignment: varmaybein "'is'" variable  */
#line 400 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->Synchronize((yyvsp[0].variable), NULL)) YYABORT;}
#line 2749 "antimony.tab.cpp"
    break;

  case 111: /* assignment: varmaybein "'is'" variable '/' variable  */
#line 401 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[-2].variable), (yyvsp[0].variable))) YYABORT;}
#line 2755 "antimony.tab.cpp"
    break;

  case 112: /* assignment: varmaybein '*' variable "'is'" variable  */
#line 402 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[0].variable), (yyvsp[-2].variable))) YYABORT;}
#line 2761 "antimony.tab.cpp"
    break;

  case 113: /* assignment: varmaybein "'is'" "text string"  */
#line 403 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetDisplayName(*((yyvsp[0].word)))) YYABORT;}
#line 2767 "antimony.tab.cpp"
    break;

  case 114: /* assignment: varmaybein ':' '=' formula  */
#line 404 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT;}
#line 2773 "antimony.tab.cpp"
    break;

  case 115: /* assignment: varmaybein '\'' '=' formula  */
#line 405 "antimony.ypp"
                                            {if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT;}
#line 2779 "antimony.tab.cpp"
    break;

  case 116: /* assignment: varmaybein "'has'" unitdef  */
#line 406 "antimony.ypp"
                                           {if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2785 "antimony.tab.cpp"
    break;

  case 117: /* $@4: %empty  */
#line 410 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2791 "antimony.tab.cpp"
    break;

  case 118: /* submodule: varmaybein ':' "name of an existing module" '(' $@4 variableimportlist ')' submodifications maybein  */
#line 410 "antimony.ypp"
                                                                                                                             {if ((yyvsp[0].variable) != NULL) {if ((yyvsp[-8].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2797 "antimony.tab.cpp"
    break;

  case 119: /* $@5: %empty  */
#line 411 "antimony.ypp"
                            {if(g_registry.CurrentModule()->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2803 "antimony.tab.cpp"
    break;

  case 120: /* submodule: "name of an existing module" '(' $@5 variableimportlist ')' submodifications maybein  */
#line 411 "antimony.ypp"
                                                                                                                                     {if ((yyvsp[0].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2809 "antimony.tab.cpp"
    break;

  case 121: /* variableimportlist: %empty  */
#line 415 "antimony.ypp"
                            {}
#line 2815 "antimony.tab.cpp"
    break;

  case 122: /* variableimportlist: variable  */
#line 416 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2821 "antimony.tab.cpp"
    break;

  case 123: /* variableimportlist: variableimportlist ',' variable  */
#line 417 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2827 "antimony.tab.cpp"
    break;

  case 124: /* variableimportlist: "number"  */
#line 418 "antimony.ypp"
                    {if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2833 "antimony.tab.cpp"
    break;

  case 125: /* variableimportlist: variableimportlist ',' "number"  */
#line 419 "antimony.ypp"
                                           { if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2839 "antimony.tab.cpp"
    break;

  case 126: /* submodifications: %empty  */
#line 423 "antimony.ypp"
                            {}
#line 2845 "antimony.tab.cpp"
    break;

  case 127: /* submodifications: submodifications ',' "element name" '=' variable  */
#line 424 "antimony.ypp"
                                                          {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].variable));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2853 "antimony.tab.cpp"
    break;

  case 128: /* submodifications: submodifications ',' "element name" '=' "number"  */
#line 428 "antimony.ypp"
                                                     {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].num));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2861 "antimony.tab.cpp"
    break;

  case 129: /* varinitialize: specinit  */
#line 432 "antimony.ypp"
                         { }
#line 2867 "antimony.tab.cpp"
    break;

  case 130: /* varinitialize: formulainit  */
#line 433 "antimony.ypp"
                            { }
#line 2873 "antimony.tab.cpp"
    break;

  case 131: /* varinitialize: reactioninit  */
#line 434 "antimony.ypp"
                             { }
#line 2879 "antimony.tab.cpp"
    break;

  case 132: /* varinitialize: dnainit  */
#line 435 "antimony.ypp"
                        { }
#line 2885 "antimony.tab.cpp"
    break;

  case 133: /* varinitialize: geneinit  */
#line 436 "antimony.ypp"
                         { }
#line 2891 "antimony.tab.cpp"
    break;

  case 134: /* varinitialize: operatorinit  */
#line 437 "antimony.ypp"
                             { }
#line 2897 "antimony.tab.cpp"
    break;

  case 135: /* varinitialize: compartmentinit  */
#line 439 "antimony.ypp"
                                { }
#line 2903 "antimony.tab.cpp"
    break;

  case 136: /* varinitialize: varconstinit  */
#line 440 "antimony.ypp"
                             { }
#line 2909 "antimony.tab.cpp"
    break;

  case 137: /* specinit: "'species'" varmaybeis  */
#line 443 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2915 "antimony.tab.cpp"
    break;

  case 138: /* specinit: "'var'" "'species'" varmaybeis  */
#line 444 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2921 "antimony.tab.cpp"
    break;

  case 139: /* specinit: "'const'" "'species'" varmaybeis  */
#line 445 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2927 "antimony.tab.cpp"
    break;

  case 140: /* specinit: "'substanceOnly'" "'species'" varmaybeis  */
#line 446 "antimony.ypp"
                                             {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2933 "antimony.tab.cpp"
    break;

  case 141: /* specinit: "'substanceOnly'" varmaybeis  */
#line 447 "antimony.ypp"
                                     {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2939 "antimony.tab.cpp"
    break;

  case 142: /* specinit: "'var'" "'substanceOnly'" "'species'" varmaybeis  */
#line 448 "antimony.ypp"
                                                     {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2945 "antimony.tab.cpp"
    break;

  case 143: /* specinit: "'const'" "'substanceOnly'" "'species'" varmaybeis  */
#line 449 "antimony.ypp"
                                                       {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2951 "antimony.tab.cpp"
    break;

  case 144: /* specinit: specinit ',' varmaybeis  */
#line 450 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2957 "antimony.tab.cpp"
    break;

  case 145: /* formulainit: "'formula'" varmaybeis  */
#line 453 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2963 "antimony.tab.cpp"
    break;

  case 146: /* formulainit: "'var'" "'formula'" varmaybeis  */
#line 454 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2969 "antimony.tab.cpp"
    break;

  case 147: /* formulainit: "'const'" "'formula'" varmaybeis  */
#line 455 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2975 "antimony.tab.cpp"
    break;

  case 148: /* formulainit: formulainit ',' varmaybeis  */
#line 456 "antimony.ypp"
                                           {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2981 "antimony.tab.cpp"
    break;

  case 149: /* reactioninit: "'reaction'" varmaybeis  */
#line 459 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 2987 "antimony.tab.cpp"
    break;

  case 150: /* reactioninit: "'var'" "'reaction'" varmaybeis  */
#line 460 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 2993 "antimony.tab.cpp"
    break;

  case 151: /* reactioninit: "'const'" "'reaction'"  */
#line 461 "antimony.ypp"
                                   {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; }
#line 2999 "antimony.tab.cpp"
    break;

  case 152: /* reactioninit: reactioninit ',' varmaybeis  */
#line 462 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3005 "antimony.tab.cpp"
    break;

  case 153: /* dnainit: "'DNA'" varmaybeis  */
#line 465 "antimony.ypp"
                               {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3011 "antimony.tab.cpp"
    break;

  case 154: /* dnainit: "'var'" "'DNA'" varmaybeis  */
#line 466 "antimony.ypp"
                                       {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3017 "antimony.tab.cpp"
    break;

  case 155: /* dnainit: "'const'" "'DNA'" varmaybeis  */
#line 467 "antimony.ypp"
                                         {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3023 "antimony.tab.cpp"
    break;

  case 156: /* dnainit: dnainit ',' varmaybeis  */
#line 468 "antimony.ypp"
                                       {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3029 "antimony.tab.cpp"
    break;

  case 157: /* geneinit: "'gene'" varmaybeis  */
#line 471 "antimony.ypp"
                                {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3035 "antimony.tab.cpp"
    break;

  case 158: /* geneinit: "'var'" "'gene'" varmaybeis  */
#line 472 "antimony.ypp"
                                        {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3041 "antimony.tab.cpp"
    break;

  case 159: /* geneinit: "'const'" "'gene'" varmaybeis  */
#line 473 "antimony.ypp"
                                          {g_registry.SetError("Genes may not be set 'const'."); YYABORT; }
#line 3047 "antimony.tab.cpp"
    break;

  case 160: /* geneinit: geneinit ',' varmaybeis  */
#line 474 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3053 "antimony.tab.cpp"
    break;

  case 161: /* operatorinit: "'operator'" varmaybeis  */
#line 477 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3059 "antimony.tab.cpp"
    break;

  case 162: /* operatorinit: "'var'" "'operator'" varmaybeis  */
#line 478 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3065 "antimony.tab.cpp"
    break;

  case 163: /* operatorinit: "'const'" "'operator'" varmaybeis  */
#line 479 "antimony.ypp"
                                              {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3071 "antimony.tab.cpp"
    break;

  case 164: /* operatorinit: operatorinit ',' varmaybeis  */
#line 480 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3077 "antimony.tab.cpp"
    break;

  case 165: /* compartmentinit: "'compartment'" varmaybeis  */
#line 484 "antimony.ypp"
                                       {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3083 "antimony.tab.cpp"
    break;

  case 166: /* compartmentinit: "'var'" "'compartment'" varmaybeis  */
#line 485 "antimony.ypp"
                                               {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3089 "antimony.tab.cpp"
    break;

  case 167: /* compartmentinit: "'const'" "'compartment'" varmaybeis  */
#line 486 "antimony.ypp"
                                                 {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3095 "antimony.tab.cpp"
    break;

  case 168: /* compartmentinit: compartmentinit ',' varmaybeis  */
#line 487 "antimony.ypp"
                                               {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3101 "antimony.tab.cpp"
    break;

  case 169: /* varconstinit: "'var'" varmaybeis  */
#line 490 "antimony.ypp"
                                   {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst();}
#line 3107 "antimony.tab.cpp"
    break;

  case 170: /* varconstinit: "'const'" varmaybeis  */
#line 491 "antimony.ypp"
                                     {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst();}
#line 3113 "antimony.tab.cpp"
    break;

  case 171: /* varconstinit: varconstinit ',' varmaybeis  */
#line 492 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst();}
#line 3119 "antimony.tab.cpp"
    break;

  case 172: /* unitinit: "'unit'" variable '=' formula  */
#line 495 "antimony.ypp"
                                              {if ((yyvsp[-2].variable)->SetType(varUnitDefinition)) YYABORT;
                                               if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                                               if ((yyvsp[-2].variable)->GetUnitDef()->SetFromFormula((yyvsp[0].formula))) YYABORT;}
#line 3127 "antimony.tab.cpp"
    break;

  case 173: /* unitinit: "'unit'" variable  */
#line 498 "antimony.ypp"
                                  {if ((yyvsp[0].variable)->SetType(varUnitDefinition)) YYABORT;}
#line 3133 "antimony.tab.cpp"
    break;

  case 174: /* dnadef: dnastrand  */
#line 501 "antimony.ypp"
                          {if (g_registry.SaveWorkingStrand()) YYABORT;}
#line 3139 "antimony.tab.cpp"
    break;

  case 175: /* dnadef: varmaybein ':' dnastrand  */
#line 502 "antimony.ypp"
                                         {if (g_registry.SetStrandAs((yyvsp[-2].variable))) YYABORT;}
#line 3145 "antimony.tab.cpp"
    break;

  case 176: /* dnastrand: "--" variable  */
#line 505 "antimony.ypp"
                                {if (g_registry.SetNewUpstreamOpen((yyvsp[0].variable))) YYABORT;}
#line 3151 "antimony.tab.cpp"
    break;

  case 177: /* dnastrand: "--" dnamiddle  */
#line 506 "antimony.ypp"
                                 {g_registry.SetOpenUpstream(); }
#line 3157 "antimony.tab.cpp"
    break;

  case 178: /* dnastrand: dnamiddle variable  */
#line 507 "antimony.ypp"
                                   {if (g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3163 "antimony.tab.cpp"
    break;

  case 179: /* dnastrand: "--" dnamiddle variable  */
#line 508 "antimony.ypp"
                                          {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3169 "antimony.tab.cpp"
    break;

  case 180: /* dnastrand: dnamiddle  */
#line 509 "antimony.ypp"
                          { }
#line 3175 "antimony.tab.cpp"
    break;

  case 181: /* dnamiddle: variable "--"  */
#line 512 "antimony.ypp"
                                {if (g_registry.SetNewDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3181 "antimony.tab.cpp"
    break;

  case 182: /* dnamiddle: dnamiddle variable "--"  */
#line 513 "antimony.ypp"
                                          {if (g_registry.SetDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3187 "antimony.tab.cpp"
    break;

  case 183: /* $@6: %empty  */
#line 516 "antimony.ypp"
                           {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula))) YYABORT;}
#line 3193 "antimony.tab.cpp"
    break;

  case 184: /* event: "'at'" formula $@6 eventmodifications colonret assignmentlist  */
#line 516 "antimony.ypp"
                                                                                                                        {}
#line 3199 "antimony.tab.cpp"
    break;

  case 185: /* $@7: %empty  */
#line 517 "antimony.ypp"
                                         {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula))) YYABORT;}
#line 3205 "antimony.tab.cpp"
    break;

  case 186: /* event: "'at'" formula "'after'" formula $@7 eventmodifications colonret assignmentlist  */
#line 517 "antimony.ypp"
                                                                                                                                          {}
#line 3211 "antimony.tab.cpp"
    break;

  case 187: /* $@8: %empty  */
#line 518 "antimony.ypp"
                                          {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula), (yyvsp[-3].variable))) YYABORT;}
#line 3217 "antimony.tab.cpp"
    break;

  case 188: /* event: varmaybein ':' "'at'" formula $@8 eventmodifications colonret assignmentlist  */
#line 518 "antimony.ypp"
                                                                                                                                            {}
#line 3223 "antimony.tab.cpp"
    break;

  case 189: /* $@9: %empty  */
#line 519 "antimony.ypp"
                                                        {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula), (yyvsp[-5].variable))) YYABORT;}
#line 3229 "antimony.tab.cpp"
    break;

  case 190: /* event: varmaybein ':' "'at'" formula "'after'" formula $@9 eventmodifications colonret assignmentlist  */
#line 519 "antimony.ypp"
                                                                                                                                                             {}
#line 3235 "antimony.tab.cpp"
    break;

  case 191: /* colonret: ':'  */
#line 522 "antimony.ypp"
                    {}
#line 3241 "antimony.tab.cpp"
    break;

  case 192: /* colonret: colonret '\n'  */
#line 523 "antimony.ypp"
                              {}
#line 3247 "antimony.tab.cpp"
    break;

  case 193: /* eventmodifications: %empty  */
#line 526 "antimony.ypp"
                                 {}
#line 3253 "antimony.tab.cpp"
    break;

  case 194: /* eventmodifications: eventmodifications ',' "element name" '=' formula  */
#line 527 "antimony.ypp"
                                                           {if (CaselessStrCmp(false, *(yyvsp[-2].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[0].formula));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[0].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;}}
#line 3263 "antimony.tab.cpp"
    break;

  case 195: /* assignmentlist: variable '=' formula  */
#line 534 "antimony.ypp"
                                     {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3269 "antimony.tab.cpp"
    break;

  case 196: /* assignmentlist: variable '=' formula ':' assignmentlist  */
#line 535 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3275 "antimony.tab.cpp"
    break;

  case 197: /* assignmentlist: variable '=' formula ':' '\n' assignmentlist  */
#line 536 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3281 "antimony.tab.cpp"
    break;

  case 198: /* assignmentlist: variable '=' formula ',' assignmentlist  */
#line 537 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3287 "antimony.tab.cpp"
    break;

  case 199: /* assignmentlist: variable '=' formula ',' '\n' assignmentlist  */
#line 538 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3293 "antimony.tab.cpp"
    break;

  case 200: /* deletion: "'delete'" variable  */
#line 541 "antimony.ypp"
                                    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3299 "antimony.tab.cpp"
    break;

  case 201: /* deletion: deletion ',' variable  */
#line 542 "antimony.ypp"
                                      {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3305 "antimony.tab.cpp"
    break;

  case 202: /* unitdef: formula  */
#line 545 "antimony.ypp"
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
#line 3323 "antimony.tab.cpp"
    break;

  case 203: /* constraint: "number" inequality formula  */
#line 560 "antimony.ypp"
                                       {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3329 "antimony.tab.cpp"
    break;

  case 204: /* constraint: '-' "number" inequality formula  */
#line 561 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint(-(yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3335 "antimony.tab.cpp"
    break;

  case 205: /* constraint: "name of a pre-defined constant" inequality formula  */
#line 562 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3341 "antimony.tab.cpp"
    break;

  case 206: /* constraint: "element name" inequality formula  */
#line 563 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3347 "antimony.tab.cpp"
    break;

  case 207: /* constraint: "'constraint'" ':' formula  */
#line 564 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[0].formula))) YYABORT;}
#line 3353 "antimony.tab.cpp"
    break;

  case 208: /* constraint: "'constraint'" variable ':' formula  */
#line 565 "antimony.ypp"
                                                    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3359 "antimony.tab.cpp"
    break;

  case 209: /* objective: maxormin formula  */
#line 568 "antimony.ypp"
                                              {if (g_registry.CurrentModule()->AddObjective((yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 3365 "antimony.tab.cpp"
    break;

  case 210: /* maxormin: "'maximize'"  */
#line 571 "antimony.ypp"
                             {(yyval.maxormin) = true;}
#line 3371 "antimony.tab.cpp"
    break;

  case 211: /* maxormin: "'minimize'"  */
#line 572 "antimony.ypp"
                             {(yyval.maxormin) = false;}
#line 3377 "antimony.tab.cpp"
    break;

  case 212: /* stringlist: "text string"  */
#line 575 "antimony.ypp"
                           { (yyval.stringlist) = new std::vector<std::string>(); (yyval.stringlist)->push_back(*((yyvsp[0].word))); }
#line 3383 "antimony.tab.cpp"
    break;

  case 213: /* stringlist: stringlist ',' "text string"  */
#line 576 "antimony.ypp"
                                          { (yyval.stringlist) = (yyvsp[-2].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3389 "antimony.tab.cpp"
    break;

  case 214: /* stringlist: stringlist ',' '\n' "text string"  */
#line 577 "antimony.ypp"
                                               { (yyval.stringlist) = (yyvsp[-3].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3395 "antimony.tab.cpp"
    break;

  case 215: /* cvterm: variable "element name" stringlist  */
#line 580 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->ProcessCVTerm((yyvsp[-2].variable),(yyvsp[-1].word),(yyvsp[0].stringlist))) YYABORT;}
#line 3401 "antimony.tab.cpp"
    break;

  case 216: /* toplevel_sbo: "name of an existing module" '.' "element name" '=' "number"  */
#line 584 "antimony.ypp"
                  { Module* module = g_registry.GetModule(*(yyvsp[-4].word));
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      module->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3415 "antimony.tab.cpp"
    break;

  case 217: /* toplevel_sbo: "name of an existing function" '.' "element name" '=' "number"  */
#line 595 "antimony.ypp"
                  { Module* function = g_registry.GetModule(*(yyvsp[-4].word));
                    if (function && (yyvsp[-2].word) &&  CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      function->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3429 "antimony.tab.cpp"
    break;

  case 218: /* modulename: "name of an existing module" "'is'" "text string" lineend  */
#line 607 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3435 "antimony.tab.cpp"
    break;

  case 219: /* functionname: "name of an existing function" "'is'" "text string" lineend  */
#line 609 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3441 "antimony.tab.cpp"
    break;

  case 220: /* modulecvterm: "name of an existing module" "element name" stringlist lineend  */
#line 612 "antimony.ypp"
                                                   {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3447 "antimony.tab.cpp"
    break;

  case 221: /* functioncvterm: "name of an existing function" "element name" stringlist lineend  */
#line 613 "antimony.ypp"
                                                    {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3453 "antimony.tab.cpp"
    break;


#line 3457 "antimony.tab.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == ANTIMONY_YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= ANTIMONY_YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == ANTIMONY_YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = ANTIMONY_YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != ANTIMONY_YYEMPTY)
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 615 "antimony.ypp"



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
  if (cc > 0 && (isalpha(cc) || cc == '_')) {
    string word;
    while (cc > 0 && (isalpha(cc) || isdigit(cc) || cc == '_') && !g_registry.input->eof()) {
      word += cc;
      g_registry.input->get(cc);
    }
    if (!g_registry.input->eof()) {
      g_registry.input->unget();
    }
    if (CaselessStrCmp(false, word, "module")) {
      return MODULE;
    }
    if (CaselessStrCmp(false, word, "model")) {
      return MODULE;
    }
    if (CaselessStrCmp(false, word, "end")) {
      return END;
    }
    if (CaselessStrCmp(false, word, "species")) {
      return SPECIES;
    }
    if (CaselessStrCmp(false, word, "formula")) {
      return FORMULA;
    }
    if (CaselessStrCmp(false, word, "reaction")) {
      return REACTION;
    }
    if (CaselessStrCmp(false, word, "DNA")) {
      return DNA;
    }
    if (CaselessStrCmp(false, word, "gene")) {
      return GENE;
    }
    if (CaselessStrCmp(false, word, "operator")) {
      return OPERATOR;
    }
    if (CaselessStrCmp(false, word, "compartment")) {
      return COMPARTMENT;
    }
    if (CaselessStrCmp(false, word, "has")) {
      return HASWORD;
    }
    if (CaselessStrCmp(false, word, "in")) {
      return INWORD;
    }
    if (CaselessStrCmp(false, word, "is")) {
      return IS;
    }
    if (CaselessStrCmp(false, word, "var")) {
      return VARWORD;
    }
    if (CaselessStrCmp(false, word, "const")) {
      return CONSTWORD;
    }
    if (CaselessStrCmp(false, word, "substanceOnly")) {
      return SUBSTONLY;
    }
    if (CaselessStrCmp(false, word, "ext")) {
      return CONSTWORD;
    }
    if (CaselessStrCmp(false, word, "import")) {
      return IMPORT;
    }
    if (CaselessStrCmp(false, word, "event")) {
      return EVENT;
    }
    if (CaselessStrCmp(false, word, "at")) {
      return AT;
    }
    if (CaselessStrCmp(false, word, "after")) {
      return AFTER;
    }
    if (CaselessStrCmp(false, word, "function")) {
      return FUNCTIONWORD;
    }
    if (CaselessStrCmp(false, word, "unit")) {
      return UNITWORD;
    }
    if (CaselessStrCmp(false, word, "delete")) {
      return DELETEWORD;
    }
    if (CaselessStrCmp(false, word, "constraint")) {
      return CONSTRAINTWORD;
    }
    if (CaselessStrCmp(false, word, "maximize")) {
      return MAXIMIZEWORD;
    }
    if (CaselessStrCmp(false, word, "minimize")) {
      return MINIMIZEWORD;
    }
    if (CaselessStrCmp(true, word, "sbo") && (g_registry.input->peek() == ':')) {
      // try to parse an SBO term
      g_registry.input->get();
      cc = g_registry.input->peek();
      if (cc > 0 && (isdigit(cc))) {
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
  if (cc > 0 && (isdigit(cc) || (cc=='.' && isdigit(g_registry.input->peek())))) {
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
      char nextchar;
      g_registry.input->get(nextchar);
      g_registry.input->unget();
      if (nextchar == ' ' || nextchar == ';') {
        return BECOMESMOD2;
      }
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
//  if (cc == '@') {
//    return AT;
//  }

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
  if ((cc<32 && cc != 9 && cc != 10 && cc != 13) || cc > 126) {
    stringstream err;
    err << "Unparseable content in line " << antimony_yylloc_last_line;
    err << ": unknown character '" << cc << "' (an integer value of ";
    err << (int) cc << ".)";
    g_registry.SetError(err.str());
    return ERROR;
  }
  return cc;
}
