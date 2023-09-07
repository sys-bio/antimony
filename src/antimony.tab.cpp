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
  YYSYMBOL_annotationBlock = 128,          /* annotationBlock  */
  YYSYMBOL_129_10 = 129,                   /* $@10  */
  YYSYMBOL_annotations = 130,              /* annotations  */
  YYSYMBOL_cvterm = 131,                   /* cvterm  */
  YYSYMBOL_toplevel_sbo = 132,             /* toplevel_sbo  */
  YYSYMBOL_modulename = 133,               /* modulename  */
  YYSYMBOL_functionname = 134,             /* functionname  */
  YYSYMBOL_modulecvterm = 135,             /* modulecvterm  */
  YYSYMBOL_functioncvterm = 136            /* functioncvterm  */
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
#define YYLAST   1067

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  424

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
     164,   165,   166,   167,   168,   171,   189,   189,   195,   195,
     201,   202,   205,   206,   209,   209,   210,   211,   214,   215,
     216,   226,   227,   228,   231,   232,   238,   241,   244,   245,
     248,   249,   250,   251,   252,   255,   256,   259,   260,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   278,   286,   294,   302,   310,   318,   328,   329,
     330,   331,   332,   333,   337,   338,   339,   340,   341,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   359,   360,   363,   364,   365,   366,   367,   368,
     369,   372,   373,   374,   375,   376,   379,   380,   381,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   396,   396,
     397,   397,   401,   402,   403,   404,   405,   409,   410,   414,
     418,   419,   420,   421,   422,   423,   424,   425,   428,   429,
     430,   431,   432,   433,   434,   435,   438,   439,   440,   441,
     444,   445,   446,   447,   450,   451,   452,   453,   456,   457,
     458,   459,   462,   463,   464,   465,   469,   470,   471,   472,
     475,   476,   477,   480,   483,   486,   487,   490,   491,   492,
     493,   494,   497,   498,   501,   501,   502,   502,   503,   503,
     504,   504,   507,   508,   511,   512,   519,   520,   521,   522,
     523,   526,   527,   530,   545,   546,   547,   548,   549,   550,
     553,   556,   557,   560,   561,   562,   564,   564,   567,   568,
     573,   576,   587,   599,   601,   605,   606
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
  "unitdef", "constraint", "objective", "maxormin", "stringlist",
  "annotationBlock", "$@10", "annotations", "cvterm", "toplevel_sbo",
  "modulename", "functionname", "modulecvterm", "functioncvterm", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-313)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -313,   545,  -313,  -313,     1,    54,  -313,    56,   255,  -313,
    -313,  -313,  -313,  -313,    54,   296,    57,   419,    54,    54,
      54,  -313,    54,   189,   207,    54,   -23,  -313,  -313,   160,
       4,    54,    54,    54,   188,    54,  1015,  -313,  -313,  -313,
    -313,  -313,   849,    93,   129,  -313,    29,   349,   192,  -313,
      29,    29,    29,    -9,    48,    77,   103,   120,   123,   143,
     154,    29,    29,  -313,    54,    29,    40,    29,    29,  -313,
    -313,    29,  -313,  -313,  -313,  -313,  -313,   296,  -313,  -313,
      45,  -313,  -313,  -313,  -313,  -313,    45,  -313,  -313,  -313,
     627,    99,  -313,   286,  -313,  -313,  -313,    15,    54,    54,
      54,    54,    54,  -313,    54,   119,  -313,   112,    54,    45,
    -313,  -313,    63,   -11,   134,  -313,  -313,  -313,  -313,  -313,
     201,   -11,   173,  -313,  -313,  -313,  -313,   224,  -313,  -313,
    -313,    54,  -313,    22,    54,    54,    54,    54,    54,    54,
      54,   199,  -313,   235,   -11,  -313,    54,    45,    54,  -313,
     174,  -313,   216,   205,  -313,   210,   202,   159,    54,   234,
      16,  -313,  -313,  -313,    54,    54,    54,    54,    54,    54,
      54,    54,  -313,  -313,   133,  -313,    54,  -313,  -313,  -313,
     819,  -313,  -313,   819,   259,   819,   268,   278,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
     228,  -313,  -313,    45,  -313,  -313,  -313,  -313,  -313,   232,
     250,   819,   819,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
      54,   133,   257,  -313,    76,    29,   242,   261,    76,    29,
     208,   256,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,    54,  -313,   260,    45,    70,   819,  -313,  -313,   231,
     819,  -313,   281,  -313,   288,   349,   192,  -313,  -313,  -313,
      54,   234,  -313,    20,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,    45,   819,   284,   310,  -313,  -313,
     819,   819,    85,  -313,   -18,    90,  -313,   819,  -313,  -313,
     819,  -313,   334,   -16,  -313,  -313,    54,   335,  -313,  -313,
    -313,    45,   200,   301,   979,   819,  -313,    54,    54,   691,
    -313,   819,   168,    25,   819,   819,    45,    45,   755,  -313,
     755,   -11,  -313,  -313,  -313,  -313,  -313,   344,  -313,     2,
     819,   819,  -313,  -313,   314,   239,    45,  -313,  -313,   253,
      54,   296,   318,   875,  -313,    45,    45,  -313,  -313,   208,
    -313,    26,  -313,    54,  -313,   755,  -313,   260,    90,   819,
     320,  -313,    72,  -313,  -313,    29,    54,   -29,  -313,    45,
     266,  -313,  -313,   819,    90,   274,   755,  -313,   755,    45,
    -313,     2,  -313,  -313,    24,   819,    29,    45,   364,  -313,
     979,  -313,     2,  -313,  -313,   755,  -313,  -313,   819,   474,
    -313,  -313,    29,   323,   927,    90,  -313,   -29,  -313,     8,
       9,   361,  -313,     2,  -313,    54,  -313,    54,  -313,  -313,
      45,  -313,  -313,  -313
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    13,     0,     0,   108,     0,    34,    79,
      74,    75,    77,    78,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,   211,   212,     0,
      22,     0,     0,     0,     0,     0,     0,   106,   107,     3,
       4,     6,    38,    58,     0,     5,     0,     0,     0,    61,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,   175,   181,     0,     0,     0,     0,    79,
      12,     0,    11,     7,     8,     9,    10,     0,    76,    34,
      36,   104,   105,   102,   101,   103,    69,    79,   216,    79,
     184,    38,    39,    40,   166,    79,    79,     0,     0,     0,
       0,     0,     0,   152,     0,     0,   171,   177,   178,   201,
     154,   146,     0,     0,     0,    24,    27,    26,   158,    15,
       0,     0,     0,   120,    23,    21,    20,     0,   162,   150,
     138,     0,   142,   174,     0,     0,     0,     0,     0,     0,
       0,     0,   170,     0,    34,   182,     0,    70,     0,    79,
       0,    79,     0,     0,    49,     0,     0,     0,     0,    68,
       0,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,    55,    53,   179,    54,     0,    56,    59,    60,
     210,    57,    79,   204,   218,   207,     0,     0,    95,    94,
      96,    97,   100,    98,    82,    79,    83,    80,    84,    79,
       0,    79,    99,    81,    87,    88,   194,    79,    79,     0,
       0,   206,   208,    79,   168,   156,   148,   160,   164,   140,
       0,   180,     0,   213,     0,     0,     0,     0,     0,     0,
     122,    18,   141,    79,   167,   155,   147,   159,   163,   151,
     139,     0,    35,   220,    37,     0,   203,   117,   114,   111,
     110,    79,     0,    79,    68,     0,     0,   176,    79,    79,
       0,    71,    79,     0,    79,   145,   149,   153,   157,   161,
     165,   169,   172,   183,   202,   205,     0,     0,    90,    91,
     186,    92,     0,    89,     0,     0,    44,    41,    79,    79,
     209,   144,     0,     0,   226,   224,    31,     0,   225,   223,
     125,   123,     0,     0,     0,   173,   143,     0,     0,   188,
     118,   115,     0,     0,   109,   116,    72,    73,    45,    79,
      45,     0,   217,   194,    85,    79,    86,     0,   192,     0,
      42,    43,   222,   214,     0,     0,    32,   221,   127,     0,
      31,    34,     0,     0,    47,   113,   112,    79,   194,   122,
      79,     0,    79,     0,    64,    45,    66,   219,     0,    93,
       0,   193,     0,   185,   215,    79,     0,    45,   126,   124,
       0,    19,    48,   190,     0,     0,    45,    79,    45,    46,
      63,     0,    79,    79,     0,    28,    79,    33,     0,   121,
       0,   194,     0,   127,    65,    45,    67,   187,   195,   196,
      25,    30,    29,     0,     0,     0,   189,    45,    62,     0,
       0,     0,    17,     0,   119,     0,   199,     0,   197,   129,
     128,   191,   200,   198
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,    -3,
      46,    -1,    21,    23,    28,  -311,    -2,     0,  -313,   -41,
     -42,   264,   184,  -313,    -5,    53,  -313,  -313,  -313,  -313,
      38,     3,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,   238,   374,  -313,  -313,  -313,  -313,  -313,
    -265,  -312,  -125,  -313,   186,  -313,  -313,   243,  -113,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    39,    40,   303,   304,   127,    41,   226,   384,
     335,    91,    92,    93,    94,   354,   343,   344,    46,    47,
      48,   246,   282,   204,   205,    49,    50,    51,   349,   230,
     302,   367,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   206,   323,   348,   391,
     329,   285,   363,    66,   247,    67,    68,    69,   224,    70,
     184,   277,    71,    72,    73,    74,    75,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    45,    87,    89,    80,   157,    86,   160,   228,   356,
      95,   358,   124,   353,     5,    97,    77,   107,   109,    79,
       5,     5,    43,   156,    44,    79,    79,   156,   143,   388,
     119,   243,   156,   156,   133,   143,   374,   333,     6,   125,
     325,   147,   223,     6,   380,   106,   326,   159,   110,   164,
     111,   126,   334,   118,     6,   400,   389,    78,   143,   128,
     129,   130,   132,   174,   142,   394,     5,   396,     5,     5,
     361,    79,   182,    79,    79,   213,   415,   417,   264,   405,
     222,   233,   319,   143,   408,   143,    37,   352,   377,   203,
       6,    37,    38,   381,    81,    82,   414,    38,   176,   154,
      83,   -39,    37,   161,   162,   163,   165,   221,    38,   392,
     256,   255,   143,   307,   172,   173,   263,    96,   175,   177,
     178,   179,    84,    85,   181,   143,   214,   215,   216,   217,
     218,   383,   219,   -39,   293,   166,   -39,   148,    37,   145,
     413,   146,   324,   325,    38,   244,   143,   245,   327,   249,
     328,   254,   -39,   -39,   -39,   261,   159,    86,   147,   232,
     273,   167,   234,   235,   236,   237,   238,   239,   240,   149,
     220,     5,   150,   120,   158,   274,    79,   121,   168,   203,
       5,   169,   203,   158,   203,    79,     5,   225,   151,   152,
     153,    79,   265,   266,   267,   268,   269,   270,   271,   272,
       5,   170,   112,   122,     5,    79,   113,   158,   357,    79,
     203,   203,   171,   312,     5,   313,   123,   260,   227,    79,
       5,   262,   155,   300,   115,    79,   229,   248,     5,   301,
     350,   158,   114,    79,   251,    10,    11,    12,    13,   131,
     308,   231,   116,    18,   143,   203,     5,   143,   291,   203,
     241,    79,   242,   147,   117,   159,   397,   338,   339,   316,
     317,    27,    28,   252,   259,     5,    78,   406,   368,   306,
      79,   351,   278,    90,   203,   253,   276,   294,   295,   203,
     203,   298,   299,   279,   416,   418,   203,   283,   421,   203,
     422,   288,   423,    81,    82,   336,   365,   366,   296,    83,
       5,   143,    88,    42,   203,    79,   345,   346,   203,   289,
     203,   159,   -16,   203,   203,   145,   292,   203,   293,   203,
     297,    84,    85,   390,   366,    43,   207,    44,   362,   203,
     203,   393,   339,   180,    81,    82,    89,   310,   369,   336,
      83,   322,    42,   372,   321,   208,   209,   210,   301,   332,
     337,   183,   379,   185,   203,   155,   156,   340,   203,   211,
     212,   360,    84,    85,    43,   387,    44,   364,    10,    11,
      12,    13,   203,     5,   123,   203,   419,   203,    79,   382,
     362,   403,   411,   402,   203,   284,   370,   375,   404,    42,
     257,   362,   108,   286,   203,   258,   407,   203,   203,     0,
       0,     0,     0,    42,   372,     0,     0,     0,   362,   362,
     420,    43,   362,    44,   362,   250,   362,     0,   386,     0,
       0,     0,     0,     0,     0,    43,     0,    44,     0,     0,
       0,     5,     0,     0,     0,     0,    79,   401,     0,   386,
       0,     0,    98,     0,     0,     0,   275,     0,    99,     0,
       0,     0,     0,   100,     0,   401,   101,     0,     0,   280,
       0,     0,     0,   281,     0,   281,     0,     0,   102,   103,
     104,   105,   287,     0,     0,     0,     0,   290,   186,   187,
     188,   189,   190,   191,   192,   193,     5,     0,     0,   194,
       0,    79,     0,     0,     0,     0,     0,   305,   196,     0,
       0,     0,     0,     0,   197,     0,     0,     0,     0,   198,
       0,     0,    81,    82,     0,   309,     0,   311,    83,     0,
       0,     0,   314,   315,     0,     0,   318,     0,   320,     0,
     199,     0,   409,   200,   410,     0,     0,   201,     0,   202,
      84,    85,     0,     0,     0,     2,     3,     0,     0,     0,
       0,     4,   330,   331,     0,     0,     0,     5,     0,     6,
       7,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,    21,     0,    22,
      23,    24,    25,   355,     0,     0,    26,     0,     0,   359,
      27,    28,    29,    30,    31,    32,    33,    34,     0,    35,
      36,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,   373,     0,    38,   376,     0,   378,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   385,
       0,   186,   187,   188,   189,   190,   191,   192,   193,     5,
       0,   395,   194,   195,    79,     0,   398,   399,     0,     0,
     385,   196,     0,     0,     0,     0,     0,   197,     0,     0,
       0,     0,   198,     0,     0,    81,    82,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,     0,     0,   200,     0,     0,     0,
     201,     0,   202,    84,    85,   186,   187,   188,   189,   190,
     191,   192,   193,     5,     0,     0,   194,   347,    79,     0,
       0,     0,     0,     0,     0,   196,     0,     0,     0,     0,
       0,   197,     0,     0,     0,     0,   198,     0,     0,    81,
      82,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   199,     0,     0,
     200,     0,     0,     0,   201,     0,   202,    84,    85,   186,
     187,   188,   189,   190,   191,   192,   193,     5,     0,     0,
     194,     0,    79,     0,     0,     0,     0,     0,     0,   196,
       0,     0,     0,     0,     0,   197,     0,     0,     0,     0,
     198,     0,     0,    81,    82,     0,     0,   353,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,     0,     0,   200,     0,     0,     0,   201,     0,
     202,    84,    85,   186,   187,   188,   189,   190,   191,   192,
     193,     5,     0,     0,   194,     0,    79,     0,     0,     0,
       0,     0,     0,   196,     0,     0,     0,     0,     0,   197,
       0,     0,     0,     0,   198,   -68,   -68,    81,    82,     0,
       0,     5,   143,    83,     0,     0,   144,     0,   -68,   -68,
     -68,   -68,     0,     0,     0,   199,   145,     0,   200,     0,
       0,     4,   201,     0,   202,    84,    85,     5,     0,     6,
       7,   146,   341,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,   371,     0,     0,    22,
       0,     0,    25,     0,     0,     0,     0,     0,     0,     0,
      27,    28,   342,     0,    31,    32,    33,    34,     0,    35,
      36,     0,     0,     4,     0,     0,     0,    37,     0,     5,
       0,     6,     7,    38,   341,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,   412,     0,
       0,    22,     0,     0,    25,     0,     0,     0,     0,     0,
       0,     0,    27,    28,   342,     0,    31,    32,    33,    34,
       0,    35,    36,     0,     0,     4,     0,     0,     0,    37,
       0,     5,     0,     6,     7,    38,   341,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,    22,     0,     0,    25,     0,     0,     0,
       0,     0,     0,     0,    27,    28,   342,     5,    31,    32,
      33,    34,    79,    35,    36,     0,     0,     0,   134,     0,
       0,    37,     0,     0,   135,     0,     0,    38,     0,   136,
       0,     0,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   139,   140,   141
};

static const yytype_int16 yycheck[] =
{
       1,     1,     7,     8,     5,    47,     7,    48,   121,   320,
      15,   323,     8,    42,    12,    16,    15,    18,    19,    17,
      12,    12,     1,     7,     1,    17,    17,     7,    13,    58,
      53,   144,     7,     7,    35,    13,   348,    53,    14,    35,
      58,    42,    53,    14,   355,    17,    64,    48,    20,    58,
      22,    47,    68,    25,    14,    31,   367,    56,    13,    31,
      32,    33,    34,    64,    36,   376,    12,   378,    12,    12,
      68,    17,    77,    17,    17,    60,    68,    68,    62,   391,
      17,    59,    62,    13,   395,    13,    62,    62,    62,    90,
      14,    62,    68,   358,    38,    39,   407,    68,    58,    46,
      44,     8,    62,    50,    51,    52,    58,   108,    68,   374,
     152,   152,    13,    43,    61,    62,   157,    60,    65,    66,
      67,    68,    66,    67,    71,    13,    98,    99,   100,   101,
     102,    59,   104,    40,    58,    58,    43,     8,    62,    27,
     405,    42,    57,    58,    68,   146,    13,   148,    58,   150,
      60,   152,    59,    60,    61,   156,   157,   158,   159,   131,
      27,    58,   134,   135,   136,   137,   138,   139,   140,    40,
      51,    12,    43,    13,    15,   176,    17,    17,    58,   180,
      12,    58,   183,    15,   185,    17,    12,    53,    59,    60,
      61,    17,   164,   165,   166,   167,   168,   169,   170,   171,
      12,    58,    13,    43,    12,    17,    17,    15,   321,    17,
     211,   212,    58,   255,    12,   256,    56,    15,    17,    17,
      12,    62,     6,    15,    17,    17,    53,    53,    12,   230,
      62,    15,    43,    17,    18,    19,    20,    21,    22,    51,
       9,    17,    35,    27,    13,   246,    12,    13,   220,   250,
      51,    17,    17,   254,    47,   256,   381,    57,    58,   260,
     261,    45,    46,    47,    59,    12,    56,   392,    15,   241,
      17,   312,     4,     9,   275,    59,    17,   224,   225,   280,
     281,   228,   229,     5,   409,   410,   287,    59,   413,   290,
     415,    59,   417,    38,    39,   296,    57,    58,    56,    44,
      12,    13,    47,   304,   305,    17,   307,   308,   309,    59,
     311,   312,    56,   314,   315,    27,    59,   318,    58,   320,
      59,    66,    67,    57,    58,   304,    40,   304,   329,   330,
     331,    57,    58,    69,    38,    39,   341,    56,   339,   340,
      44,    31,   343,   343,    60,    59,    60,    61,   349,    15,
      15,    87,   353,    89,   355,     6,     7,    56,   359,    95,
      96,    17,    66,    67,   343,   366,   343,    53,    19,    20,
      21,    22,   373,    12,    56,   376,    15,   378,    17,    59,
     381,    17,    59,   386,   385,   201,   340,   349,   390,   390,
     152,   392,    18,   207,   395,   152,   393,   398,   399,    -1,
      -1,    -1,    -1,   404,   404,    -1,    -1,    -1,   409,   410,
     411,   390,   413,   390,   415,   151,   417,    -1,   365,    -1,
      -1,    -1,    -1,    -1,    -1,   404,    -1,   404,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    17,   384,    -1,   386,
      -1,    -1,    23,    -1,    -1,    -1,   182,    -1,    29,    -1,
      -1,    -1,    -1,    34,    -1,   402,    37,    -1,    -1,   195,
      -1,    -1,    -1,   199,    -1,   201,    -1,    -1,    49,    50,
      51,    52,   208,    -1,    -1,    -1,    -1,   213,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    15,
      -1,    17,    -1,    -1,    -1,    -1,    -1,   233,    24,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    38,    39,    -1,   251,    -1,   253,    44,    -1,
      -1,    -1,   258,   259,    -1,    -1,   262,    -1,   264,    -1,
      56,    -1,    58,    59,    60,    -1,    -1,    63,    -1,    65,
      66,    67,    -1,    -1,    -1,     0,     1,    -1,    -1,    -1,
      -1,     6,   288,   289,    -1,    -1,    -1,    12,    -1,    14,
      15,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    -1,    34,
      35,    36,    37,   319,    -1,    -1,    41,    -1,    -1,   325,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,   347,    -1,    68,   350,    -1,   352,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   365,
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,   377,    15,    16,    17,    -1,   382,   383,    -1,    -1,
     386,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    -1,
      63,    -1,    65,    66,    67,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    -1,    63,    -1,    65,    66,    67,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
      15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    38,    39,    -1,    -1,    42,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    -1,    -1,    63,    -1,
      65,    66,    67,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    15,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    35,     6,     7,    38,    39,    -1,
      -1,    12,    13,    44,    -1,    -1,    17,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    56,    27,    -1,    59,    -1,
      -1,     6,    63,    -1,    65,    66,    67,    12,    -1,    14,
      15,    42,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    -1,    -1,    34,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    50,    51,    52,    -1,    54,
      55,    -1,    -1,     6,    -1,    -1,    -1,    62,    -1,    12,
      -1,    14,    15,    68,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    -1,
      -1,    34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    50,    51,    52,
      -1,    54,    55,    -1,    -1,     6,    -1,    -1,    -1,    62,
      -1,    12,    -1,    14,    15,    68,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    12,    49,    50,
      51,    52,    17,    54,    55,    -1,    -1,    -1,    23,    -1,
      -1,    62,    -1,    -1,    29,    -1,    -1,    68,    -1,    34,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52
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
     128,   131,   132,   133,   134,   135,   136,    15,    56,    17,
      80,    38,    39,    44,    66,    67,    80,    93,    47,    93,
      90,    80,    81,    82,    83,    93,    60,    80,    23,    29,
      34,    37,    49,    50,    51,    52,    83,    80,   113,    80,
      83,    83,    13,    17,    43,    17,    35,    47,    83,    53,
      13,    17,    43,    56,     8,    35,    47,    75,    83,    83,
      83,    51,    83,    80,    23,    29,    34,    37,    49,    50,
      51,    52,    83,    13,    17,    27,    42,    80,     8,    40,
      43,    59,    60,    61,    94,     6,     7,    89,    15,    80,
      88,    94,    94,    94,    58,    58,    58,    58,    58,    58,
      58,    58,    94,    94,    80,    94,    58,    94,    94,    94,
      90,    94,    93,    90,   129,    90,     4,     5,     6,     7,
       8,     9,    10,    11,    15,    16,    24,    30,    35,    56,
      59,    63,    65,    80,    92,    93,   115,    40,    59,    60,
      61,    90,    90,    60,    83,    83,    83,    83,    83,    83,
      51,    80,    17,    53,   127,    53,    77,    17,   127,    53,
      98,    17,    83,    59,    83,    83,    83,    83,    83,    83,
      83,    51,    17,   127,    80,    80,    90,   123,    53,    80,
      90,    18,    47,    59,    80,    88,    89,   112,   126,    59,
      15,    80,    62,    88,    62,    83,    83,    83,    83,    83,
      83,    83,    83,    27,    80,    90,    17,   130,     4,     5,
      90,    90,    91,    59,    91,   120,   123,    90,    59,    59,
      90,    83,    59,    58,    94,    94,    56,    59,    94,    94,
      15,    80,    99,    73,    74,    90,    83,    43,     9,    90,
      56,    90,    89,    88,    90,    90,    80,    80,    90,    62,
      90,    60,    31,   116,    57,    58,    64,    58,    60,   119,
      90,    90,    15,    53,    68,    79,    80,    15,    57,    58,
      56,    17,    47,    85,    86,    80,    80,    16,   117,    97,
      62,    88,    62,    42,    84,    90,    84,   127,   120,    90,
      17,    68,    80,   121,    53,    57,    58,   100,    15,    80,
      79,    31,    86,    90,   120,    99,    90,    62,    90,    80,
      84,   119,    59,    59,    78,    90,    94,    80,    58,    84,
      57,   118,   119,    57,    84,    90,    84,   121,    90,    90,
      31,    94,    78,    17,    85,   120,   121,   100,    84,    58,
      60,    59,    31,   119,    84,    68,   121,    68,   121,    15,
      80,   121,   121,   121
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    73,    72,    74,    72,
      72,    72,    75,    75,    77,    76,    76,    76,    78,    78,
      78,    79,    79,    79,    80,    80,    80,    81,    82,    82,
      83,    83,    83,    83,    83,    84,    84,    85,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    87,    87,    87,    87,    87,    88,    88,
      88,    88,    88,    88,    89,    89,    89,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    93,    94,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    97,    96,
      98,    96,    99,    99,    99,    99,    99,   100,   100,   100,
     101,   101,   101,   101,   101,   101,   101,   101,   102,   102,
     102,   102,   102,   102,   102,   102,   103,   103,   103,   103,
     104,   104,   104,   104,   105,   105,   105,   105,   106,   106,
     106,   106,   107,   107,   107,   107,   108,   108,   108,   108,
     109,   109,   109,   110,   110,   111,   111,   112,   112,   112,
     112,   112,   113,   113,   115,   114,   116,   114,   117,   114,
     118,   114,   119,   119,   120,   120,   121,   121,   121,   121,
     121,   122,   122,   123,   124,   124,   124,   124,   124,   124,
     125,   126,   126,   127,   127,   127,   129,   128,   130,   130,
     131,   132,   132,   133,   134,   135,   136
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     0,     9,     0,     6,
       2,     2,     0,     1,     0,     8,     2,     2,     1,     2,
       2,     0,     1,     3,     1,     3,     2,     3,     1,     1,
       1,     3,     4,     4,     3,     0,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     1,     8,     6,     5,     7,     5,     7,     1,     2,
       2,     3,     4,     4,     1,     1,     2,     1,     1,     0,
       2,     2,     2,     2,     2,     4,     4,     2,     2,     3,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     3,     5,     5,     3,     4,     4,     3,     0,     9,
       0,     7,     0,     1,     3,     1,     3,     0,     5,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     3,     2,     4,     4,     3,     2,     3,     3,     3,
       2,     3,     2,     3,     2,     3,     3,     3,     2,     3,
       3,     3,     2,     3,     3,     3,     2,     3,     3,     3,
       2,     2,     3,     4,     2,     1,     3,     2,     2,     2,
       3,     1,     2,     3,     0,     6,     0,     8,     0,     8,
       0,    10,     1,     2,     0,     5,     3,     5,     6,     5,
       6,     2,     3,     1,     3,     4,     3,     3,     3,     4,
       2,     1,     1,     1,     3,     4,     0,     5,     0,     3,
       3,     5,     5,     4,     4,     4,     4
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
#line 2054 "antimony.tab.cpp"
    break;

  case 4: /* input: input module  */
#line 158 "antimony.ypp"
                             { /*cout << endl << $2->ToString() << endl << endl;*/ }
#line 2060 "antimony.tab.cpp"
    break;

  case 5: /* input: input modulepart  */
#line 159 "antimony.ypp"
                                 {}
#line 2066 "antimony.tab.cpp"
    break;

  case 6: /* input: input function  */
#line 160 "antimony.ypp"
                               {}
#line 2072 "antimony.tab.cpp"
    break;

  case 7: /* input: input modulename  */
#line 161 "antimony.ypp"
                                 {}
#line 2078 "antimony.tab.cpp"
    break;

  case 8: /* input: input functionname  */
#line 162 "antimony.ypp"
                                   {}
#line 2084 "antimony.tab.cpp"
    break;

  case 9: /* input: input modulecvterm  */
#line 163 "antimony.ypp"
                                   {}
#line 2090 "antimony.tab.cpp"
    break;

  case 10: /* input: input functioncvterm  */
#line 164 "antimony.ypp"
                                     {}
#line 2096 "antimony.tab.cpp"
    break;

  case 11: /* input: input toplevel_sbo  */
#line 165 "antimony.ypp"
                                   {}
#line 2102 "antimony.tab.cpp"
    break;

  case 12: /* input: input annotationBlock  */
#line 166 "antimony.ypp"
                                      {}
#line 2108 "antimony.tab.cpp"
    break;

  case 13: /* input: input error  */
#line 167 "antimony.ypp"
                            {YYABORT;}
#line 2114 "antimony.tab.cpp"
    break;

  case 14: /* input: input "an error"  */
#line 168 "antimony.ypp"
                            {YYABORT;}
#line 2120 "antimony.tab.cpp"
    break;

  case 15: /* import: "'import'" "text string"  */
#line 171 "antimony.ypp"
                                  { if (g_registry.OpenFile(*((yyvsp[0].word)))==0) YYABORT;}
#line 2126 "antimony.tab.cpp"
    break;

  case 16: /* $@1: %empty  */
#line 189 "antimony.ypp"
                                         {g_registry.NewCurrentModule((yyvsp[0].word), NULL, (yyvsp[-1].maybemain));}
#line 2132 "antimony.tab.cpp"
    break;

  case 17: /* module: "'model' or 'module'" maybemain "element name" $@1 '(' variableexportlist ')' modulebody "'end'"  */
#line 190 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2142 "antimony.tab.cpp"
    break;

  case 18: /* $@2: %empty  */
#line 195 "antimony.ypp"
                                         {g_registry.NewCurrentModule((yyvsp[0].word), NULL, (yyvsp[-1].maybemain));}
#line 2148 "antimony.tab.cpp"
    break;

  case 19: /* module: "'model' or 'module'" maybemain "element name" $@2 modulebody "'end'"  */
#line 196 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2158 "antimony.tab.cpp"
    break;

  case 20: /* module: "'model' or 'module'" "name of an existing module"  */
#line 201 "antimony.ypp"
                               {g_registry.SetError("module '" + *((yyvsp[0].word)) + "' already defined."); YYABORT;}
#line 2164 "antimony.tab.cpp"
    break;

  case 21: /* module: "'model' or 'module'" "name of an existing function"  */
#line 202 "antimony.ypp"
                                {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a module because it is already a defined function."); YYABORT;}
#line 2170 "antimony.tab.cpp"
    break;

  case 22: /* maybemain: %empty  */
#line 205 "antimony.ypp"
                            {(yyval.maybemain) = false;}
#line 2176 "antimony.tab.cpp"
    break;

  case 23: /* maybemain: '*'  */
#line 206 "antimony.ypp"
                    {(yyval.maybemain) = true;}
#line 2182 "antimony.tab.cpp"
    break;

  case 24: /* $@3: %empty  */
#line 209 "antimony.ypp"
                                     {g_registry.NewUserFunction((yyvsp[0].word));}
#line 2188 "antimony.tab.cpp"
    break;

  case 25: /* function: "'function'" "element name" $@3 '(' variableexportlist ')' spacedformula "'end'"  */
#line 209 "antimony.ypp"
                                                                                                                    {if (g_registry.SetUserFunction((yyvsp[-1].formula))) YYABORT;}
#line 2194 "antimony.tab.cpp"
    break;

  case 26: /* function: "'function'" "name of an existing module"  */
#line 210 "antimony.ypp"
                                     {g_registry.SetError("Cannot use '" + *((yyvsp[0].word)) +"' as a function name because it is already the name of a module."); YYABORT;}
#line 2200 "antimony.tab.cpp"
    break;

  case 27: /* function: "'function'" "name of an existing function"  */
#line 211 "antimony.ypp"
                                      {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a new function because it is already a defined function."); YYABORT;}
#line 2206 "antimony.tab.cpp"
    break;

  case 28: /* spacedformula: formula  */
#line 214 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2212 "antimony.tab.cpp"
    break;

  case 29: /* spacedformula: lineend spacedformula  */
#line 215 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[0].formula);}
#line 2218 "antimony.tab.cpp"
    break;

  case 30: /* spacedformula: spacedformula lineend  */
#line 216 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[-1].formula);}
#line 2224 "antimony.tab.cpp"
    break;

  case 31: /* variableexportlist: %empty  */
#line 226 "antimony.ypp"
                            {}
#line 2230 "antimony.tab.cpp"
    break;

  case 32: /* variableexportlist: variable  */
#line 227 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2236 "antimony.tab.cpp"
    break;

  case 33: /* variableexportlist: variableexportlist ',' variable  */
#line 228 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2242 "antimony.tab.cpp"
    break;

  case 34: /* variable: "element name"  */
#line 231 "antimony.ypp"
                        {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[0].word)); }
#line 2248 "antimony.tab.cpp"
    break;

  case 35: /* variable: variable '.' "element name"  */
#line 232 "antimony.ypp"
                                     {(yyval.variable) = (yyvsp[-2].variable)->GetSubVariable((yyvsp[0].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[0].word)) + "' is not a subvariable of '" + (yyvsp[-2].variable)->GetNameDelimitedBy(".") + "'.");
                    YYABORT;
                  }
                }
#line 2259 "antimony.tab.cpp"
    break;

  case 36: /* variable: '$' variable  */
#line 238 "antimony.ypp"
                             {(yyval.variable) = (yyvsp[0].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;}
#line 2265 "antimony.tab.cpp"
    break;

  case 37: /* variablein: variable "'in'" variable  */
#line 241 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetCompartment((yyvsp[0].variable))) YYABORT; (yyval.variable) = (yyvsp[-2].variable);}
#line 2271 "antimony.tab.cpp"
    break;

  case 38: /* varmaybein: variable  */
#line 244 "antimony.ypp"
                         {(yyval.variable) = (yyvsp[0].variable);}
#line 2277 "antimony.tab.cpp"
    break;

  case 39: /* varmaybein: variablein  */
#line 245 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2283 "antimony.tab.cpp"
    break;

  case 40: /* varmaybeis: varmaybein  */
#line 248 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2289 "antimony.tab.cpp"
    break;

  case 41: /* varmaybeis: varmaybein '=' formula  */
#line 249 "antimony.ypp"
                                       {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2295 "antimony.tab.cpp"
    break;

  case 42: /* varmaybeis: varmaybein ':' '=' formula  */
#line 250 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT; }
#line 2301 "antimony.tab.cpp"
    break;

  case 43: /* varmaybeis: varmaybein '\'' '=' formula  */
#line 251 "antimony.ypp"
                                            {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT; }
#line 2307 "antimony.tab.cpp"
    break;

  case 44: /* varmaybeis: varmaybein "'has'" unitdef  */
#line 252 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2313 "antimony.tab.cpp"
    break;

  case 45: /* maybein: %empty  */
#line 255 "antimony.ypp"
                            {(yyval.variable) = NULL;}
#line 2319 "antimony.tab.cpp"
    break;

  case 46: /* maybein: "'in'" variable  */
#line 256 "antimony.ypp"
                                {(yyval.variable) = (yyvsp[0].variable);}
#line 2325 "antimony.tab.cpp"
    break;

  case 47: /* modulebody: modulepart  */
#line 259 "antimony.ypp"
                           {}
#line 2331 "antimony.tab.cpp"
    break;

  case 48: /* modulebody: modulebody modulepart  */
#line 260 "antimony.ypp"
                                      {}
#line 2337 "antimony.tab.cpp"
    break;

  case 49: /* modulepart: reaction lineend  */
#line 263 "antimony.ypp"
                                 {}
#line 2343 "antimony.tab.cpp"
    break;

  case 50: /* modulepart: assignment lineend  */
#line 264 "antimony.ypp"
                                   {}
#line 2349 "antimony.tab.cpp"
    break;

  case 51: /* modulepart: submodule lineend  */
#line 265 "antimony.ypp"
                                  {}
#line 2355 "antimony.tab.cpp"
    break;

  case 52: /* modulepart: varinitialize lineend  */
#line 266 "antimony.ypp"
                                      {}
#line 2361 "antimony.tab.cpp"
    break;

  case 53: /* modulepart: dnadef lineend  */
#line 267 "antimony.ypp"
                               {}
#line 2367 "antimony.tab.cpp"
    break;

  case 54: /* modulepart: event lineend  */
#line 268 "antimony.ypp"
                              {}
#line 2373 "antimony.tab.cpp"
    break;

  case 55: /* modulepart: unitinit lineend  */
#line 269 "antimony.ypp"
                                 {}
#line 2379 "antimony.tab.cpp"
    break;

  case 56: /* modulepart: deletion lineend  */
#line 270 "antimony.ypp"
                                 {}
#line 2385 "antimony.tab.cpp"
    break;

  case 57: /* modulepart: cvterm lineend  */
#line 271 "antimony.ypp"
                               {}
#line 2391 "antimony.tab.cpp"
    break;

  case 58: /* modulepart: variablein  */
#line 272 "antimony.ypp"
                           {}
#line 2397 "antimony.tab.cpp"
    break;

  case 59: /* modulepart: constraint lineend  */
#line 273 "antimony.ypp"
                                   {}
#line 2403 "antimony.tab.cpp"
    break;

  case 60: /* modulepart: objective lineend  */
#line 274 "antimony.ypp"
                                  {}
#line 2409 "antimony.tab.cpp"
    break;

  case 61: /* modulepart: lineend  */
#line 275 "antimony.ypp"
                        {}
#line 2415 "antimony.tab.cpp"
    break;

  case 62: /* reaction: varmaybein ':' reactantList reactionDivider reactantList ';' formula maybein  */
#line 279 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-7].variable), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-7].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2427 "antimony.tab.cpp"
    break;

  case 63: /* reaction: reactantList reactionDivider reactantList ';' formula maybein  */
#line 287 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2439 "antimony.tab.cpp"
    break;

  case 64: /* reaction: reactantList reactionDivider ';' formula maybein  */
#line 295 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2451 "antimony.tab.cpp"
    break;

  case 65: /* reaction: varmaybein ':' reactantList reactionDivider ';' formula maybein  */
#line 303 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2463 "antimony.tab.cpp"
    break;

  case 66: /* reaction: reactionDivider reactantList ';' formula maybein  */
#line 311 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2475 "antimony.tab.cpp"
    break;

  case 67: /* reaction: varmaybein ':' reactionDivider reactantList ';' formula maybein  */
#line 319 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2487 "antimony.tab.cpp"
    break;

  case 68: /* reactantList: variable  */
#line 328 "antimony.ypp"
                         {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2493 "antimony.tab.cpp"
    break;

  case 69: /* reactantList: "number" variable  */
#line 329 "antimony.ypp"
                             {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2499 "antimony.tab.cpp"
    break;

  case 70: /* reactantList: variable variable  */
#line 330 "antimony.ypp"
                                  {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2505 "antimony.tab.cpp"
    break;

  case 71: /* reactantList: reactantList '+' variable  */
#line 331 "antimony.ypp"
                                          {(yyval.reactantList) = (yyvsp[-2].reactantList); if((yyvsp[-2].reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2511 "antimony.tab.cpp"
    break;

  case 72: /* reactantList: reactantList '+' "number" variable  */
#line 332 "antimony.ypp"
                                              {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2517 "antimony.tab.cpp"
    break;

  case 73: /* reactantList: reactantList '+' variable variable  */
#line 333 "antimony.ypp"
                                                   {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2523 "antimony.tab.cpp"
    break;

  case 74: /* reactionDivider: "->"  */
#line 337 "antimony.ypp"
                           {(yyval.reactionDivider) = rdBecomes;}
#line 2529 "antimony.tab.cpp"
    break;

  case 75: /* reactionDivider: "-|"  */
#line 338 "antimony.ypp"
                           {(yyval.reactionDivider) = rdInhibits;}
#line 2535 "antimony.tab.cpp"
    break;

  case 76: /* reactionDivider: '-' '('  */
#line 339 "antimony.ypp"
                        {(yyval.reactionDivider) = rdInfluences;}
#line 2541 "antimony.tab.cpp"
    break;

  case 77: /* reactionDivider: "-o"  */
#line 340 "antimony.ypp"
                            {(yyval.reactionDivider) = rdInfluences;}
#line 2547 "antimony.tab.cpp"
    break;

  case 78: /* reactionDivider: "=>"  */
#line 341 "antimony.ypp"
                             {(yyval.reactionDivider) = rdBecomesIrreversibly;}
#line 2553 "antimony.tab.cpp"
    break;

  case 79: /* formula: %empty  */
#line 344 "antimony.ypp"
                            {(yyval.formula) = g_registry.NewBlankFormula(); }
#line 2559 "antimony.tab.cpp"
    break;

  case 80: /* formula: formula "..."  */
#line 345 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddEllipses();}
#line 2565 "antimony.tab.cpp"
    break;

  case 81: /* formula: formula variable  */
#line 346 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); if((yyvsp[-1].formula)->AddVariable((yyvsp[0].variable))) YYABORT; }
#line 2571 "antimony.tab.cpp"
    break;

  case 82: /* formula: formula "number"  */
#line 347 "antimony.ypp"
                             {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddNum((yyvsp[0].num)); }
#line 2577 "antimony.tab.cpp"
    break;

  case 83: /* formula: formula "name of a pre-defined constant"  */
#line 348 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2583 "antimony.tab.cpp"
    break;

  case 84: /* formula: formula "name of an existing function"  */
#line 349 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2589 "antimony.tab.cpp"
    break;

  case 85: /* formula: formula '(' commaformula ')'  */
#line 350 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2595 "antimony.tab.cpp"
    break;

  case 86: /* formula: formula '{' commaformula '}'  */
#line 351 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddCurlyBrackets(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2601 "antimony.tab.cpp"
    break;

  case 87: /* formula: formula mathThing  */
#line 352 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddMathThing((yyvsp[0].character)); }
#line 2607 "antimony.tab.cpp"
    break;

  case 88: /* formula: formula inequality  */
#line 353 "antimony.ypp"
                                   {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddInequality((yyvsp[0].inequality)); }
#line 2613 "antimony.tab.cpp"
    break;

  case 89: /* formula: formula '=' '='  */
#line 354 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('='); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2619 "antimony.tab.cpp"
    break;

  case 90: /* formula: formula '&' '&'  */
#line 355 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('&'); (yyvsp[-2].formula)->AddMathThing('&'); }
#line 2625 "antimony.tab.cpp"
    break;

  case 91: /* formula: formula '|' '|'  */
#line 356 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('|'); (yyvsp[-2].formula)->AddMathThing('|'); }
#line 2631 "antimony.tab.cpp"
    break;

  case 92: /* commaformula: formula  */
#line 359 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2637 "antimony.tab.cpp"
    break;

  case 93: /* commaformula: commaformula ',' formula  */
#line 360 "antimony.ypp"
                                         {(yyval.formula) = (yyvsp[-2].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[0].formula)); }
#line 2643 "antimony.tab.cpp"
    break;

  case 94: /* mathThing: '+'  */
#line 363 "antimony.ypp"
                    {(yyval.character) = '+';}
#line 2649 "antimony.tab.cpp"
    break;

  case 95: /* mathThing: '-'  */
#line 364 "antimony.ypp"
                    {(yyval.character) = '-';}
#line 2655 "antimony.tab.cpp"
    break;

  case 96: /* mathThing: '*'  */
#line 365 "antimony.ypp"
                    {(yyval.character) = '*';}
#line 2661 "antimony.tab.cpp"
    break;

  case 97: /* mathThing: '/'  */
#line 366 "antimony.ypp"
                    {(yyval.character) = '/';}
#line 2667 "antimony.tab.cpp"
    break;

  case 98: /* mathThing: '^'  */
#line 367 "antimony.ypp"
                    {(yyval.character) = '^';}
#line 2673 "antimony.tab.cpp"
    break;

  case 99: /* mathThing: '!'  */
#line 368 "antimony.ypp"
                    {(yyval.character) = '!';}
#line 2679 "antimony.tab.cpp"
    break;

  case 100: /* mathThing: '%'  */
#line 369 "antimony.ypp"
                    {(yyval.character) = '%';}
#line 2685 "antimony.tab.cpp"
    break;

  case 101: /* inequality: '<'  */
#line 372 "antimony.ypp"
                    {(yyval.inequality) = constLT;}
#line 2691 "antimony.tab.cpp"
    break;

  case 102: /* inequality: "<="  */
#line 373 "antimony.ypp"
                    {(yyval.inequality) = constLEQ;}
#line 2697 "antimony.tab.cpp"
    break;

  case 103: /* inequality: '>'  */
#line 374 "antimony.ypp"
                    {(yyval.inequality) = constGT;}
#line 2703 "antimony.tab.cpp"
    break;

  case 104: /* inequality: ">="  */
#line 375 "antimony.ypp"
                    {(yyval.inequality) = constGEQ;}
#line 2709 "antimony.tab.cpp"
    break;

  case 105: /* inequality: "!="  */
#line 376 "antimony.ypp"
                    {(yyval.inequality) = constNEQ;}
#line 2715 "antimony.tab.cpp"
    break;

  case 106: /* lineend: ';'  */
#line 379 "antimony.ypp"
                    {}
#line 2721 "antimony.tab.cpp"
    break;

  case 107: /* lineend: '\n'  */
#line 380 "antimony.ypp"
                     {}
#line 2727 "antimony.tab.cpp"
    break;

  case 108: /* lineend: "end of line"  */
#line 381 "antimony.ypp"
                    {}
#line 2733 "antimony.tab.cpp"
    break;

  case 109: /* assignment: varmaybein ':' maxormin formula  */
#line 384 "antimony.ypp"
                                                {if (g_registry.CurrentModule()->AddObjective((yyvsp[-3].variable), (yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 2739 "antimony.tab.cpp"
    break;

  case 110: /* assignment: varmaybein '=' formula  */
#line 385 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2745 "antimony.tab.cpp"
    break;

  case 111: /* assignment: varmaybein "'is'" variable  */
#line 386 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->Synchronize((yyvsp[0].variable), NULL)) YYABORT;}
#line 2751 "antimony.tab.cpp"
    break;

  case 112: /* assignment: varmaybein "'is'" variable '/' variable  */
#line 387 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[-2].variable), (yyvsp[0].variable))) YYABORT;}
#line 2757 "antimony.tab.cpp"
    break;

  case 113: /* assignment: varmaybein '*' variable "'is'" variable  */
#line 388 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[0].variable), (yyvsp[-2].variable))) YYABORT;}
#line 2763 "antimony.tab.cpp"
    break;

  case 114: /* assignment: varmaybein "'is'" "text string"  */
#line 389 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetDisplayName(*((yyvsp[0].word)))) YYABORT;}
#line 2769 "antimony.tab.cpp"
    break;

  case 115: /* assignment: varmaybein ':' '=' formula  */
#line 390 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT;}
#line 2775 "antimony.tab.cpp"
    break;

  case 116: /* assignment: varmaybein '\'' '=' formula  */
#line 391 "antimony.ypp"
                                            {if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT;}
#line 2781 "antimony.tab.cpp"
    break;

  case 117: /* assignment: varmaybein "'has'" unitdef  */
#line 392 "antimony.ypp"
                                           {if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2787 "antimony.tab.cpp"
    break;

  case 118: /* $@4: %empty  */
#line 396 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2793 "antimony.tab.cpp"
    break;

  case 119: /* submodule: varmaybein ':' "name of an existing module" '(' $@4 variableimportlist ')' submodifications maybein  */
#line 396 "antimony.ypp"
                                                                                                                             {if ((yyvsp[0].variable) != NULL) {if ((yyvsp[-8].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2799 "antimony.tab.cpp"
    break;

  case 120: /* $@5: %empty  */
#line 397 "antimony.ypp"
                            {if(g_registry.CurrentModule()->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2805 "antimony.tab.cpp"
    break;

  case 121: /* submodule: "name of an existing module" '(' $@5 variableimportlist ')' submodifications maybein  */
#line 397 "antimony.ypp"
                                                                                                                                     {if ((yyvsp[0].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2811 "antimony.tab.cpp"
    break;

  case 122: /* variableimportlist: %empty  */
#line 401 "antimony.ypp"
                            {}
#line 2817 "antimony.tab.cpp"
    break;

  case 123: /* variableimportlist: variable  */
#line 402 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2823 "antimony.tab.cpp"
    break;

  case 124: /* variableimportlist: variableimportlist ',' variable  */
#line 403 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2829 "antimony.tab.cpp"
    break;

  case 125: /* variableimportlist: "number"  */
#line 404 "antimony.ypp"
                    {if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2835 "antimony.tab.cpp"
    break;

  case 126: /* variableimportlist: variableimportlist ',' "number"  */
#line 405 "antimony.ypp"
                                           { if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2841 "antimony.tab.cpp"
    break;

  case 127: /* submodifications: %empty  */
#line 409 "antimony.ypp"
                            {}
#line 2847 "antimony.tab.cpp"
    break;

  case 128: /* submodifications: submodifications ',' "element name" '=' variable  */
#line 410 "antimony.ypp"
                                                          {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].variable));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2855 "antimony.tab.cpp"
    break;

  case 129: /* submodifications: submodifications ',' "element name" '=' "number"  */
#line 414 "antimony.ypp"
                                                     {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].num));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2863 "antimony.tab.cpp"
    break;

  case 130: /* varinitialize: specinit  */
#line 418 "antimony.ypp"
                         { }
#line 2869 "antimony.tab.cpp"
    break;

  case 131: /* varinitialize: formulainit  */
#line 419 "antimony.ypp"
                            { }
#line 2875 "antimony.tab.cpp"
    break;

  case 132: /* varinitialize: reactioninit  */
#line 420 "antimony.ypp"
                             { }
#line 2881 "antimony.tab.cpp"
    break;

  case 133: /* varinitialize: dnainit  */
#line 421 "antimony.ypp"
                        { }
#line 2887 "antimony.tab.cpp"
    break;

  case 134: /* varinitialize: geneinit  */
#line 422 "antimony.ypp"
                         { }
#line 2893 "antimony.tab.cpp"
    break;

  case 135: /* varinitialize: operatorinit  */
#line 423 "antimony.ypp"
                             { }
#line 2899 "antimony.tab.cpp"
    break;

  case 136: /* varinitialize: compartmentinit  */
#line 424 "antimony.ypp"
                                { }
#line 2905 "antimony.tab.cpp"
    break;

  case 137: /* varinitialize: varconstinit  */
#line 425 "antimony.ypp"
                             { }
#line 2911 "antimony.tab.cpp"
    break;

  case 138: /* specinit: "'species'" varmaybeis  */
#line 428 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2917 "antimony.tab.cpp"
    break;

  case 139: /* specinit: "'var'" "'species'" varmaybeis  */
#line 429 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2923 "antimony.tab.cpp"
    break;

  case 140: /* specinit: "'const'" "'species'" varmaybeis  */
#line 430 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2929 "antimony.tab.cpp"
    break;

  case 141: /* specinit: "'substanceOnly'" "'species'" varmaybeis  */
#line 431 "antimony.ypp"
                                             {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2935 "antimony.tab.cpp"
    break;

  case 142: /* specinit: "'substanceOnly'" varmaybeis  */
#line 432 "antimony.ypp"
                                     {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2941 "antimony.tab.cpp"
    break;

  case 143: /* specinit: "'var'" "'substanceOnly'" "'species'" varmaybeis  */
#line 433 "antimony.ypp"
                                                     {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2947 "antimony.tab.cpp"
    break;

  case 144: /* specinit: "'const'" "'substanceOnly'" "'species'" varmaybeis  */
#line 434 "antimony.ypp"
                                                       {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2953 "antimony.tab.cpp"
    break;

  case 145: /* specinit: specinit ',' varmaybeis  */
#line 435 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2959 "antimony.tab.cpp"
    break;

  case 146: /* formulainit: "'formula'" varmaybeis  */
#line 438 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2965 "antimony.tab.cpp"
    break;

  case 147: /* formulainit: "'var'" "'formula'" varmaybeis  */
#line 439 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2971 "antimony.tab.cpp"
    break;

  case 148: /* formulainit: "'const'" "'formula'" varmaybeis  */
#line 440 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2977 "antimony.tab.cpp"
    break;

  case 149: /* formulainit: formulainit ',' varmaybeis  */
#line 441 "antimony.ypp"
                                           {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 2983 "antimony.tab.cpp"
    break;

  case 150: /* reactioninit: "'reaction'" varmaybeis  */
#line 444 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 2989 "antimony.tab.cpp"
    break;

  case 151: /* reactioninit: "'var'" "'reaction'" varmaybeis  */
#line 445 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 2995 "antimony.tab.cpp"
    break;

  case 152: /* reactioninit: "'const'" "'reaction'"  */
#line 446 "antimony.ypp"
                                   {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; }
#line 3001 "antimony.tab.cpp"
    break;

  case 153: /* reactioninit: reactioninit ',' varmaybeis  */
#line 447 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3007 "antimony.tab.cpp"
    break;

  case 154: /* dnainit: "'DNA'" varmaybeis  */
#line 450 "antimony.ypp"
                               {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3013 "antimony.tab.cpp"
    break;

  case 155: /* dnainit: "'var'" "'DNA'" varmaybeis  */
#line 451 "antimony.ypp"
                                       {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3019 "antimony.tab.cpp"
    break;

  case 156: /* dnainit: "'const'" "'DNA'" varmaybeis  */
#line 452 "antimony.ypp"
                                         {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3025 "antimony.tab.cpp"
    break;

  case 157: /* dnainit: dnainit ',' varmaybeis  */
#line 453 "antimony.ypp"
                                       {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3031 "antimony.tab.cpp"
    break;

  case 158: /* geneinit: "'gene'" varmaybeis  */
#line 456 "antimony.ypp"
                                {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3037 "antimony.tab.cpp"
    break;

  case 159: /* geneinit: "'var'" "'gene'" varmaybeis  */
#line 457 "antimony.ypp"
                                        {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3043 "antimony.tab.cpp"
    break;

  case 160: /* geneinit: "'const'" "'gene'" varmaybeis  */
#line 458 "antimony.ypp"
                                          {g_registry.SetError("Genes may not be set 'const'."); YYABORT; }
#line 3049 "antimony.tab.cpp"
    break;

  case 161: /* geneinit: geneinit ',' varmaybeis  */
#line 459 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3055 "antimony.tab.cpp"
    break;

  case 162: /* operatorinit: "'operator'" varmaybeis  */
#line 462 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3061 "antimony.tab.cpp"
    break;

  case 163: /* operatorinit: "'var'" "'operator'" varmaybeis  */
#line 463 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3067 "antimony.tab.cpp"
    break;

  case 164: /* operatorinit: "'const'" "'operator'" varmaybeis  */
#line 464 "antimony.ypp"
                                              {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3073 "antimony.tab.cpp"
    break;

  case 165: /* operatorinit: operatorinit ',' varmaybeis  */
#line 465 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3079 "antimony.tab.cpp"
    break;

  case 166: /* compartmentinit: "'compartment'" varmaybeis  */
#line 469 "antimony.ypp"
                                       {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3085 "antimony.tab.cpp"
    break;

  case 167: /* compartmentinit: "'var'" "'compartment'" varmaybeis  */
#line 470 "antimony.ypp"
                                               {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3091 "antimony.tab.cpp"
    break;

  case 168: /* compartmentinit: "'const'" "'compartment'" varmaybeis  */
#line 471 "antimony.ypp"
                                                 {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3097 "antimony.tab.cpp"
    break;

  case 169: /* compartmentinit: compartmentinit ',' varmaybeis  */
#line 472 "antimony.ypp"
                                               {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3103 "antimony.tab.cpp"
    break;

  case 170: /* varconstinit: "'var'" varmaybeis  */
#line 475 "antimony.ypp"
                                   {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst();}
#line 3109 "antimony.tab.cpp"
    break;

  case 171: /* varconstinit: "'const'" varmaybeis  */
#line 476 "antimony.ypp"
                                     {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst();}
#line 3115 "antimony.tab.cpp"
    break;

  case 172: /* varconstinit: varconstinit ',' varmaybeis  */
#line 477 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst();}
#line 3121 "antimony.tab.cpp"
    break;

  case 173: /* unitinit: "'unit'" variable '=' formula  */
#line 480 "antimony.ypp"
                                              {if ((yyvsp[-2].variable)->SetType(varUnitDefinition)) YYABORT;
                                               if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                                               if ((yyvsp[-2].variable)->GetUnitDef()->SetFromFormula((yyvsp[0].formula))) YYABORT;}
#line 3129 "antimony.tab.cpp"
    break;

  case 174: /* unitinit: "'unit'" variable  */
#line 483 "antimony.ypp"
                                  {if ((yyvsp[0].variable)->SetType(varUnitDefinition)) YYABORT;}
#line 3135 "antimony.tab.cpp"
    break;

  case 175: /* dnadef: dnastrand  */
#line 486 "antimony.ypp"
                          {if (g_registry.SaveWorkingStrand()) YYABORT;}
#line 3141 "antimony.tab.cpp"
    break;

  case 176: /* dnadef: varmaybein ':' dnastrand  */
#line 487 "antimony.ypp"
                                         {if (g_registry.SetStrandAs((yyvsp[-2].variable))) YYABORT;}
#line 3147 "antimony.tab.cpp"
    break;

  case 177: /* dnastrand: "--" variable  */
#line 490 "antimony.ypp"
                                {if (g_registry.SetNewUpstreamOpen((yyvsp[0].variable))) YYABORT;}
#line 3153 "antimony.tab.cpp"
    break;

  case 178: /* dnastrand: "--" dnamiddle  */
#line 491 "antimony.ypp"
                                 {g_registry.SetOpenUpstream(); }
#line 3159 "antimony.tab.cpp"
    break;

  case 179: /* dnastrand: dnamiddle variable  */
#line 492 "antimony.ypp"
                                   {if (g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3165 "antimony.tab.cpp"
    break;

  case 180: /* dnastrand: "--" dnamiddle variable  */
#line 493 "antimony.ypp"
                                          {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3171 "antimony.tab.cpp"
    break;

  case 181: /* dnastrand: dnamiddle  */
#line 494 "antimony.ypp"
                          { }
#line 3177 "antimony.tab.cpp"
    break;

  case 182: /* dnamiddle: variable "--"  */
#line 497 "antimony.ypp"
                                {if (g_registry.SetNewDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3183 "antimony.tab.cpp"
    break;

  case 183: /* dnamiddle: dnamiddle variable "--"  */
#line 498 "antimony.ypp"
                                          {if (g_registry.SetDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3189 "antimony.tab.cpp"
    break;

  case 184: /* $@6: %empty  */
#line 501 "antimony.ypp"
                           {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula))) YYABORT;}
#line 3195 "antimony.tab.cpp"
    break;

  case 185: /* event: "'at'" formula $@6 eventmodifications colonret assignmentlist  */
#line 501 "antimony.ypp"
                                                                                                                        {}
#line 3201 "antimony.tab.cpp"
    break;

  case 186: /* $@7: %empty  */
#line 502 "antimony.ypp"
                                         {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula))) YYABORT;}
#line 3207 "antimony.tab.cpp"
    break;

  case 187: /* event: "'at'" formula "'after'" formula $@7 eventmodifications colonret assignmentlist  */
#line 502 "antimony.ypp"
                                                                                                                                          {}
#line 3213 "antimony.tab.cpp"
    break;

  case 188: /* $@8: %empty  */
#line 503 "antimony.ypp"
                                          {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula), (yyvsp[-3].variable))) YYABORT;}
#line 3219 "antimony.tab.cpp"
    break;

  case 189: /* event: varmaybein ':' "'at'" formula $@8 eventmodifications colonret assignmentlist  */
#line 503 "antimony.ypp"
                                                                                                                                            {}
#line 3225 "antimony.tab.cpp"
    break;

  case 190: /* $@9: %empty  */
#line 504 "antimony.ypp"
                                                        {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula), (yyvsp[-5].variable))) YYABORT;}
#line 3231 "antimony.tab.cpp"
    break;

  case 191: /* event: varmaybein ':' "'at'" formula "'after'" formula $@9 eventmodifications colonret assignmentlist  */
#line 504 "antimony.ypp"
                                                                                                                                                             {}
#line 3237 "antimony.tab.cpp"
    break;

  case 192: /* colonret: ':'  */
#line 507 "antimony.ypp"
                    {}
#line 3243 "antimony.tab.cpp"
    break;

  case 193: /* colonret: colonret '\n'  */
#line 508 "antimony.ypp"
                              {}
#line 3249 "antimony.tab.cpp"
    break;

  case 194: /* eventmodifications: %empty  */
#line 511 "antimony.ypp"
                                 {}
#line 3255 "antimony.tab.cpp"
    break;

  case 195: /* eventmodifications: eventmodifications ',' "element name" '=' formula  */
#line 512 "antimony.ypp"
                                                           {if (CaselessStrCmp(false, *(yyvsp[-2].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[0].formula));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[0].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;}}
#line 3265 "antimony.tab.cpp"
    break;

  case 196: /* assignmentlist: variable '=' formula  */
#line 519 "antimony.ypp"
                                     {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3271 "antimony.tab.cpp"
    break;

  case 197: /* assignmentlist: variable '=' formula ':' assignmentlist  */
#line 520 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3277 "antimony.tab.cpp"
    break;

  case 198: /* assignmentlist: variable '=' formula ':' '\n' assignmentlist  */
#line 521 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3283 "antimony.tab.cpp"
    break;

  case 199: /* assignmentlist: variable '=' formula ',' assignmentlist  */
#line 522 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3289 "antimony.tab.cpp"
    break;

  case 200: /* assignmentlist: variable '=' formula ',' '\n' assignmentlist  */
#line 523 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3295 "antimony.tab.cpp"
    break;

  case 201: /* deletion: "'delete'" variable  */
#line 526 "antimony.ypp"
                                    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3301 "antimony.tab.cpp"
    break;

  case 202: /* deletion: deletion ',' variable  */
#line 527 "antimony.ypp"
                                      {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3307 "antimony.tab.cpp"
    break;

  case 203: /* unitdef: formula  */
#line 530 "antimony.ypp"
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
#line 3325 "antimony.tab.cpp"
    break;

  case 204: /* constraint: "number" inequality formula  */
#line 545 "antimony.ypp"
                                       {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3331 "antimony.tab.cpp"
    break;

  case 205: /* constraint: '-' "number" inequality formula  */
#line 546 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint(-(yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3337 "antimony.tab.cpp"
    break;

  case 206: /* constraint: "name of a pre-defined constant" inequality formula  */
#line 547 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3343 "antimony.tab.cpp"
    break;

  case 207: /* constraint: "element name" inequality formula  */
#line 548 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3349 "antimony.tab.cpp"
    break;

  case 208: /* constraint: "'constraint'" ':' formula  */
#line 549 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[0].formula))) YYABORT;}
#line 3355 "antimony.tab.cpp"
    break;

  case 209: /* constraint: "'constraint'" variable ':' formula  */
#line 550 "antimony.ypp"
                                                    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3361 "antimony.tab.cpp"
    break;

  case 210: /* objective: maxormin formula  */
#line 553 "antimony.ypp"
                                              {if (g_registry.CurrentModule()->AddObjective((yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 3367 "antimony.tab.cpp"
    break;

  case 211: /* maxormin: "'maximize'"  */
#line 556 "antimony.ypp"
                             {(yyval.maxormin) = true;}
#line 3373 "antimony.tab.cpp"
    break;

  case 212: /* maxormin: "'minimize'"  */
#line 557 "antimony.ypp"
                             {(yyval.maxormin) = false;}
#line 3379 "antimony.tab.cpp"
    break;

  case 213: /* stringlist: "text string"  */
#line 560 "antimony.ypp"
                           { (yyval.stringlist) = new std::vector<std::string>(); (yyval.stringlist)->push_back(*((yyvsp[0].word))); }
#line 3385 "antimony.tab.cpp"
    break;

  case 214: /* stringlist: stringlist ',' "text string"  */
#line 561 "antimony.ypp"
                                          { (yyval.stringlist) = (yyvsp[-2].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3391 "antimony.tab.cpp"
    break;

  case 215: /* stringlist: stringlist ',' '\n' "text string"  */
#line 562 "antimony.ypp"
                                               { (yyval.stringlist) = (yyvsp[-3].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3397 "antimony.tab.cpp"
    break;

  case 216: /* $@10: %empty  */
#line 564 "antimony.ypp"
                                    {if (g_registry.SetCurrentModuleIf((yyvsp[0].word), (yyvsp[-1].word))) YYABORT;}
#line 3403 "antimony.tab.cpp"
    break;

  case 217: /* annotationBlock: "element name" "name of an existing module" $@10 annotations "'end'"  */
#line 564 "antimony.ypp"
                                                                                                          {g_registry.RevertToPreviousModule();}
#line 3409 "antimony.tab.cpp"
    break;

  case 218: /* annotations: %empty  */
#line 567 "antimony.ypp"
                            {}
#line 3415 "antimony.tab.cpp"
    break;

  case 219: /* annotations: "element name" ':' stringlist  */
#line 568 "antimony.ypp"
                                       {g_registry.ProcessGlobalCVTerm(&(g_registry.CurrentModuleName()), (yyvsp[-2].word), (yyvsp[0].stringlist));}
#line 3421 "antimony.tab.cpp"
    break;

  case 220: /* cvterm: variable "element name" stringlist  */
#line 573 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->ProcessCVTerm((yyvsp[-2].variable),(yyvsp[-1].word),(yyvsp[0].stringlist))) YYABORT;}
#line 3427 "antimony.tab.cpp"
    break;

  case 221: /* toplevel_sbo: "name of an existing module" '.' "element name" '=' "number"  */
#line 577 "antimony.ypp"
                  { Module* module = g_registry.GetModule(*(yyvsp[-4].word));
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      module->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3441 "antimony.tab.cpp"
    break;

  case 222: /* toplevel_sbo: "name of an existing function" '.' "element name" '=' "number"  */
#line 588 "antimony.ypp"
                  { Module* function = g_registry.GetModule(*(yyvsp[-4].word));
                    if (function && (yyvsp[-2].word) &&  CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      function->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3455 "antimony.tab.cpp"
    break;

  case 223: /* modulename: "name of an existing module" "'is'" "text string" lineend  */
#line 600 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3461 "antimony.tab.cpp"
    break;

  case 224: /* functionname: "name of an existing function" "'is'" "text string" lineend  */
#line 602 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3467 "antimony.tab.cpp"
    break;

  case 225: /* modulecvterm: "name of an existing module" "element name" stringlist lineend  */
#line 605 "antimony.ypp"
                                                   {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3473 "antimony.tab.cpp"
    break;

  case 226: /* functioncvterm: "name of an existing function" "element name" stringlist lineend  */
#line 606 "antimony.ypp"
                                                    {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3479 "antimony.tab.cpp"
    break;


#line 3483 "antimony.tab.cpp"

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

#line 608 "antimony.ypp"



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
    // First check if we're a three-quote block.
    if (g_registry.input->peek() == '"') {
      g_registry.input->get(cc);
      if (g_registry.input->peek() == '"') {
        g_registry.input->get(cc);
        g_registry.input->get(cc);
        while (cc != '"' && !g_registry.input->eof()) {
          textstring += cc;
          g_registry.input->get(cc);
          if (cc=='"') {
            g_registry.input->get(cc);
            if (cc=='"') {
              g_registry.input->get(cc);
              if (cc=='"') {
                antimony_yylval.word = g_registry.AddWord(textstring);
                return TEXTSTRING;
              }
              else {
                textstring += '"';
                textstring += '"';
              }
            }
            else {
              textstring += '"';
            }
          }
        }
      }
    }
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
