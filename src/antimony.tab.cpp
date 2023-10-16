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
#line 32 "antimony.ypp"

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
#line 67 "antimony.ypp"

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
  YYSYMBOL_moduleannotation = 86,          /* moduleannotation  */
  YYSYMBOL_modulepart = 87,                /* modulepart  */
  YYSYMBOL_reaction = 88,                  /* reaction  */
  YYSYMBOL_reactantList = 89,              /* reactantList  */
  YYSYMBOL_reactionDivider = 90,           /* reactionDivider  */
  YYSYMBOL_formula = 91,                   /* formula  */
  YYSYMBOL_commaformula = 92,              /* commaformula  */
  YYSYMBOL_mathThing = 93,                 /* mathThing  */
  YYSYMBOL_inequality = 94,                /* inequality  */
  YYSYMBOL_lineend = 95,                   /* lineend  */
  YYSYMBOL_assignment = 96,                /* assignment  */
  YYSYMBOL_submodule = 97,                 /* submodule  */
  YYSYMBOL_98_4 = 98,                      /* $@4  */
  YYSYMBOL_99_5 = 99,                      /* $@5  */
  YYSYMBOL_variableimportlist = 100,       /* variableimportlist  */
  YYSYMBOL_submodifications = 101,         /* submodifications  */
  YYSYMBOL_varinitialize = 102,            /* varinitialize  */
  YYSYMBOL_specinit = 103,                 /* specinit  */
  YYSYMBOL_formulainit = 104,              /* formulainit  */
  YYSYMBOL_reactioninit = 105,             /* reactioninit  */
  YYSYMBOL_dnainit = 106,                  /* dnainit  */
  YYSYMBOL_geneinit = 107,                 /* geneinit  */
  YYSYMBOL_operatorinit = 108,             /* operatorinit  */
  YYSYMBOL_compartmentinit = 109,          /* compartmentinit  */
  YYSYMBOL_varconstinit = 110,             /* varconstinit  */
  YYSYMBOL_unitinit = 111,                 /* unitinit  */
  YYSYMBOL_dnadef = 112,                   /* dnadef  */
  YYSYMBOL_dnastrand = 113,                /* dnastrand  */
  YYSYMBOL_dnamiddle = 114,                /* dnamiddle  */
  YYSYMBOL_event = 115,                    /* event  */
  YYSYMBOL_116_6 = 116,                    /* $@6  */
  YYSYMBOL_117_7 = 117,                    /* $@7  */
  YYSYMBOL_118_8 = 118,                    /* $@8  */
  YYSYMBOL_119_9 = 119,                    /* $@9  */
  YYSYMBOL_colonret = 120,                 /* colonret  */
  YYSYMBOL_eventmodifications = 121,       /* eventmodifications  */
  YYSYMBOL_assignmentlist = 122,           /* assignmentlist  */
  YYSYMBOL_deletion = 123,                 /* deletion  */
  YYSYMBOL_unitdef = 124,                  /* unitdef  */
  YYSYMBOL_constraint = 125,               /* constraint  */
  YYSYMBOL_objective = 126,                /* objective  */
  YYSYMBOL_maxormin = 127,                 /* maxormin  */
  YYSYMBOL_stringlist = 128,               /* stringlist  */
  YYSYMBOL_annotationBlock = 129,          /* annotationBlock  */
  YYSYMBOL_130_10 = 130,                   /* $@10  */
  YYSYMBOL_annotations = 131,              /* annotations  */
  YYSYMBOL_cvterm = 132,                   /* cvterm  */
  YYSYMBOL_toplevel_sbo = 133,             /* toplevel_sbo  */
  YYSYMBOL_modulename = 134,               /* modulename  */
  YYSYMBOL_functionname = 135,             /* functionname  */
  YYSYMBOL_modulecvterm = 136,             /* modulecvterm  */
  YYSYMBOL_functioncvterm = 137            /* functioncvterm  */
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
#define YYLAST   1137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  233
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  445

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
       0,   160,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   175,   178,   178,   184,   184,
     190,   191,   194,   195,   198,   198,   199,   200,   203,   204,
     205,   215,   216,   217,   220,   221,   227,   230,   233,   234,
     237,   238,   239,   240,   241,   244,   245,   248,   249,   250,
     251,   254,   255,   256,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   283,   291,   299,
     307,   315,   323,   333,   334,   335,   336,   337,   338,   342,
     343,   344,   345,   346,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   364,   365,   368,
     369,   370,   371,   372,   373,   374,   377,   378,   379,   380,
     381,   384,   385,   386,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   401,   401,   402,   402,   406,   407,   408,
     409,   410,   414,   415,   419,   423,   424,   425,   426,   427,
     428,   429,   430,   433,   434,   435,   436,   437,   438,   439,
     440,   443,   444,   445,   446,   449,   450,   451,   452,   455,
     456,   457,   458,   461,   462,   463,   464,   467,   468,   469,
     470,   474,   475,   476,   477,   480,   481,   482,   485,   488,
     491,   492,   495,   496,   497,   498,   499,   502,   503,   506,
     506,   507,   507,   508,   508,   509,   509,   512,   513,   516,
     517,   524,   525,   526,   527,   528,   531,   532,   535,   550,
     551,   552,   553,   554,   555,   558,   561,   562,   565,   566,
     567,   569,   569,   572,   573,   578,   579,   582,   593,   605,
     607,   611,   612,   613
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
  "varmaybeis", "maybein", "modulebody", "moduleannotation", "modulepart",
  "reaction", "reactantList", "reactionDivider", "formula", "commaformula",
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

#define YYPACT_NINF (-357)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-74)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -357,   652,  -357,  -357,     9,   210,  -357,    14,   292,  -357,
    -357,  -357,  -357,  -357,   210,   344,   102,   471,   210,   210,
     210,  -357,   210,   186,   207,   210,    15,  -357,  -357,   159,
     185,   210,   210,   210,    23,   210,   541,  -357,  -357,  -357,
    -357,  -357,   358,    61,   157,  -357,    35,   264,   197,  -357,
      35,    35,    35,    85,    94,   111,   143,   155,   168,   190,
     192,    35,    35,  -357,   210,    35,    -2,    35,    35,  -357,
    -357,    35,  -357,  -357,  -357,  -357,  -357,   344,  -357,  -357,
      48,  -357,  -357,  -357,  -357,  -357,    48,  -357,  -357,  -357,
     717,    57,  -357,   146,  -357,  -357,  -357,    42,   210,   210,
     210,   210,   210,  -357,   210,   153,  -357,    37,   210,    48,
    -357,  -357,   226,   117,   203,  -357,  -357,  -357,  -357,  -357,
     250,    19,   222,  -357,  -357,  -357,  -357,   263,  -357,  -357,
    -357,   210,  -357,     3,   210,   210,   210,   210,   210,   210,
     210,   212,  -357,   270,    32,  -357,   210,    48,   210,  -357,
     113,  -357,   219,   236,  -357,   249,   284,   112,   210,   277,
      22,  -357,  -357,  -357,   210,   210,   210,   210,   210,   210,
     210,   210,  -357,  -357,   150,  -357,   210,  -357,  -357,  -357,
     909,  -357,  -357,   909,   296,   909,   312,   319,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
     267,  -357,  -357,    48,  -357,  -357,  -357,  -357,  -357,   276,
     278,   909,   909,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
     210,   150,   282,  -357,    24,    35,   286,   294,   328,    24,
      35,   310,   298,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,   210,  -357,   338,   299,    48,   137,   909,  -357,
    -357,   119,   909,  -357,   305,  -357,   232,   264,   197,  -357,
    -357,  -357,   210,   277,  -357,    26,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,    48,   909,   303,   336,
    -357,  -357,   909,   909,   103,  -357,    -7,   175,  -357,   909,
    -357,  -357,   909,  -357,   353,   -14,  -357,  -357,   210,   361,
     117,  -357,  -357,  -357,    48,   133,   325,  1069,   909,  -357,
     117,   210,   210,   781,  -357,   909,   166,    29,   909,   909,
      48,    48,   845,  -357,   845,   117,  -357,  -357,  -357,  -357,
    -357,   374,  -357,     8,   909,   909,  -357,  -357,   341,   195,
      48,  -357,    24,  -357,   357,   210,   344,   342,    31,   965,
    -357,  -357,   299,    48,    48,  -357,  -357,   310,  -357,    36,
    -357,   210,  -357,   845,  -357,   299,   175,   909,   340,  -357,
      64,  -357,  -357,    35,   210,  -357,    84,  -357,    48,   246,
     380,   118,  -357,  -357,  -357,   909,   175,   271,   845,  -357,
     845,    48,  -357,     8,  -357,  -357,    86,   909,    35,    48,
     388,  -357,  1069,   348,   391,    24,  -357,     8,  -357,  -357,
     845,  -357,  -357,   909,   129,  -357,  -357,    35,   355,  1017,
     400,   117,  -357,   175,  -357,    84,  -357,    10,    11,   378,
    -357,  -357,    24,     8,  -357,   210,  -357,   210,  -357,  -357,
      48,  -357,  -357,  -357,  -357
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    13,     0,     0,   113,     0,    34,    84,
      79,    80,    82,    83,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,   216,   217,     0,
      22,     0,     0,     0,     0,     0,     0,   111,   112,     3,
       4,     6,    38,    63,     0,     5,     0,     0,     0,    66,
       0,     0,     0,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,   180,   186,     0,     0,     0,     0,    84,
      12,     0,    11,     7,     8,     9,    10,     0,    81,    34,
      36,   109,   110,   107,   106,   108,    74,    84,   221,    84,
     189,    38,    39,    40,   171,    84,    84,     0,     0,     0,
       0,     0,     0,   157,     0,     0,   176,   182,   183,   206,
     159,   151,     0,     0,     0,    24,    27,    26,   163,    15,
       0,     0,     0,   125,    23,    21,    20,     0,   167,   155,
     143,     0,   147,   179,     0,     0,     0,     0,     0,     0,
       0,     0,   175,     0,    34,   187,     0,    75,     0,    84,
       0,    84,     0,     0,    54,     0,     0,     0,     0,    73,
       0,    55,    56,    57,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    58,   184,    59,     0,    61,    64,    65,
     215,    62,    84,   209,   223,   212,     0,     0,   100,    99,
     101,   102,   105,   103,    87,    84,    88,    85,    89,    84,
       0,    84,   104,    86,    92,    93,   199,    84,    84,     0,
       0,   211,   213,    84,   173,   161,   153,   165,   169,   145,
       0,   185,     0,   218,     0,     0,     0,     0,     0,     0,
       0,   127,    18,   146,    84,   172,   160,   152,   164,   168,
     156,   144,     0,    35,     0,   225,    37,     0,   208,   122,
     119,   116,   115,    84,     0,    84,    73,     0,     0,   181,
      84,    84,     0,    76,    84,     0,    84,   150,   154,   158,
     162,   166,   170,   174,   177,   188,   207,   210,     0,     0,
      95,    96,   191,    97,     0,    94,     0,     0,    44,    41,
      84,    84,   214,   149,     0,     0,   233,   230,    31,     0,
       0,   231,   229,   130,   128,     0,     0,     0,   178,   148,
       0,     0,     0,   193,   123,   120,     0,     0,   114,   121,
      77,    78,    45,    84,    45,     0,   222,   199,    90,    84,
      91,     0,   197,     0,    42,    43,   228,   219,     0,     0,
      32,   227,     0,   132,     0,    31,    34,     0,     0,     0,
      48,    47,   226,   118,   117,    84,   199,   127,    84,     0,
      84,     0,    69,    45,    71,   224,     0,    98,     0,   198,
       0,   190,   220,    84,     0,   232,    45,   131,   129,     0,
       0,     0,    19,    50,    49,   195,     0,     0,    45,    84,
      45,    46,    68,     0,    84,    84,     0,    28,    84,    33,
       0,   126,     0,     0,     0,     0,   199,     0,   132,    70,
      45,    72,   192,   200,   201,    25,    30,    29,     0,     0,
       0,     0,    51,     0,   194,    45,    67,     0,     0,     0,
      17,    53,     0,     0,   124,     0,   204,     0,   202,   134,
     133,    52,   196,   205,   203
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,    18,
      77,    -1,     1,     2,   448,  -317,    21,  -344,     0,  -357,
     -39,   -36,   251,   223,  -357,     6,    44,  -357,  -357,  -357,
    -357,    68,    27,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,  -357,  -357,   279,   411,  -357,  -357,  -357,  -357,
    -357,  -356,  -319,  -135,  -357,   230,  -357,  -357,   287,  -102,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    39,    40,   306,   307,   127,    41,   226,   396,
     339,    91,    92,    93,    94,   362,   349,   350,   351,    46,
      47,    48,   248,   284,   204,   205,    49,    50,    51,   357,
     231,   305,   376,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   206,   327,   356,
     406,   333,   287,   371,    66,   249,    67,    68,    69,   224,
      70,   184,   279,    71,    72,    73,    74,    75,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    45,    43,    44,    80,   383,    86,   364,   366,   160,
     393,   157,     6,    87,    89,    97,   143,   107,   109,   229,
       5,    95,     5,     5,    77,    79,     5,    79,    79,   156,
     407,    79,   228,   156,   133,     5,   156,   386,     6,   337,
      79,   147,   245,   156,   380,   244,   392,   159,   381,     6,
     143,   329,    81,    82,   338,   143,   176,   330,    83,   401,
      37,   143,   234,   174,   145,    78,    38,   433,   119,   -39,
     143,   409,   223,   411,   131,   383,   369,   143,   435,   437,
      84,    85,   295,   182,   266,   223,    37,   423,   323,   203,
     154,   360,    38,   426,   161,   162,   163,    37,   389,   146,
       6,   -39,   213,    38,   -39,   172,   173,   221,   434,   175,
     177,   178,   179,   257,     5,   181,   258,   415,   265,    79,
     -39,   -39,   -39,   395,     5,     5,   361,   158,   312,    79,
      79,   404,   143,   186,   187,   188,   189,   190,   191,   192,
     193,     5,   400,   164,   194,   246,    79,   247,    37,   251,
     143,   256,   165,   196,    38,   263,   159,    86,   147,   197,
     328,   329,    96,   143,   198,   148,   250,    81,    82,   166,
     223,   223,   120,    83,   264,   276,   121,   275,     5,   203,
     311,   158,   203,    79,   203,   199,   207,   427,   200,   428,
     343,   344,   201,   124,   202,    84,    85,   149,   342,   112,
     150,   167,   122,   113,   220,   208,   209,   210,   352,     5,
     203,   203,   158,   168,    79,   123,   151,   152,   153,   317,
     125,   316,     5,   365,   115,   155,   169,    79,   358,   114,
     304,     5,   126,   331,   158,   332,    79,   253,    10,    11,
      12,    13,   116,   222,     5,   143,    18,   203,   170,    79,
     171,   203,   373,   374,   117,   147,   225,   159,   412,   145,
      90,   320,   321,   242,    27,    28,   254,   227,   296,   297,
     155,   156,   424,   301,   302,   230,   203,   359,   255,   405,
     232,   203,   203,    10,    11,    12,    13,   243,   203,     5,
     143,   203,   436,   438,    79,   261,     5,   340,   442,   262,
     443,    79,   444,   402,   374,    78,    42,   203,    43,    44,
     353,   354,   203,   278,   203,   159,   280,   203,   203,   432,
     180,   203,     5,   203,   281,   303,   285,    79,   408,   344,
      81,    82,   370,   203,   203,   290,    83,   291,   183,    88,
     185,   294,   298,   378,   340,   300,   211,   212,    42,   384,
      43,    44,    89,   299,   -16,   310,   304,   295,    84,    85,
     391,   314,   203,   325,   -73,   -73,   203,   326,   336,     5,
       5,   143,   377,   399,    79,   144,   341,   -73,   -73,   -73,
     -73,   345,    81,    82,   203,   145,   375,   203,    83,   203,
       5,   368,   370,   439,   372,    79,   203,   403,   123,   394,
     146,    42,   252,    43,    44,   418,   370,   420,   421,   203,
      84,    85,   203,   203,   429,   431,   417,   398,    42,   384,
      43,    44,   379,   419,   286,   387,   370,   370,   440,   108,
       0,   259,   370,   277,   370,   425,   370,   288,     0,   260,
     416,     0,   398,     0,     0,     0,   282,     0,     0,   422,
     283,     0,   283,     0,     0,     0,     0,     0,     0,   289,
       0,   416,     0,     0,   292,   106,     0,     0,   110,     0,
     111,     0,     0,   118,     0,     0,   441,     0,     0,   128,
     129,   130,   132,     5,   142,   308,     0,     0,    79,     0,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
      99,     0,     0,     0,   313,   100,   315,     0,   101,     0,
       0,   318,   319,     0,     0,   322,     0,   324,     0,     0,
     102,   103,   104,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   334,   335,     0,     0,     0,   214,   215,   216,   217,
     218,     0,   219,     5,     0,     0,     0,     0,    79,     0,
       0,     0,     0,     0,   134,     0,     0,     0,     0,     0,
     135,     0,     0,     0,   363,   136,     0,     0,   137,   233,
     367,     0,   235,   236,   237,   238,   239,   240,   241,     0,
     138,   139,   140,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   385,     0,     0,   388,
       0,   390,   267,   268,   269,   270,   271,   272,   273,   274,
       0,     0,     0,     0,   397,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     410,     0,     0,     0,     0,   413,   414,     0,     0,   397,
       0,     0,     2,     3,     0,     0,     0,     0,     4,     0,
       0,     0,     0,     0,     5,     0,     6,     7,   293,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,    21,     0,    22,    23,    24,    25,
     309,     0,     0,    26,     0,     0,     0,    27,    28,    29,
      30,    31,    32,    33,    34,     0,    35,    36,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
      38,   186,   187,   188,   189,   190,   191,   192,   193,     5,
       0,     0,   194,   195,    79,     0,     0,     0,     0,     0,
       0,   196,     0,     0,     0,     0,     0,   197,     0,     0,
       0,     0,   198,     0,     0,    81,    82,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,     0,     0,   200,     0,     0,     0,
     201,     0,   202,    84,    85,   186,   187,   188,   189,   190,
     191,   192,   193,     5,     0,     0,   194,   355,    79,     0,
       0,     0,     0,     0,     0,   196,     0,     0,     0,     0,
       0,   197,     0,     0,     0,     0,   198,     0,     0,    81,
      82,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   199,     0,     0,
     200,     0,     0,     0,   201,     0,   202,    84,    85,   186,
     187,   188,   189,   190,   191,   192,   193,     5,     0,     0,
     194,     0,    79,     0,     0,     0,     0,     0,     0,   196,
       0,     0,     0,     0,     0,   197,     0,     0,     0,     0,
     198,     0,     0,    81,    82,     0,     0,   361,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,     0,     0,   200,     0,     0,     0,   201,     0,
     202,    84,    85,   186,   187,   188,   189,   190,   191,   192,
     193,     5,     0,     0,   194,     0,    79,     0,     0,     0,
       0,     0,     0,   196,     0,     0,     0,     0,     0,   197,
       0,     0,     0,     0,   198,     0,     0,    81,    82,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,     0,     0,   200,     0,
       0,     4,   201,     0,   202,    84,    85,     5,     0,     6,
       7,     0,   346,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,   382,     0,     0,    22,
       0,     0,    25,     0,     0,     0,     0,     0,     0,     0,
      27,    28,   347,   348,    31,    32,    33,    34,     0,    35,
      36,     0,     0,     4,     0,     0,     0,    37,     0,     5,
       0,     6,     7,    38,   346,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,   430,     0,
       0,    22,     0,     0,    25,     0,     0,     0,     0,     0,
       0,     0,    27,    28,   347,   348,    31,    32,    33,    34,
       0,    35,    36,     0,     0,     4,     0,     0,     0,    37,
       0,     5,     0,     6,     7,    38,   346,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,    22,     0,     0,    25,     0,     0,     0,
       0,     0,     0,     0,    27,    28,   347,   348,    31,    32,
      33,    34,     0,    35,    36,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,    38
};

static const yytype_int16 yycheck[] =
{
       1,     1,     1,     1,     5,   349,     7,   324,   327,    48,
     366,    47,    14,     7,     8,    16,    13,    18,    19,   121,
      12,    15,    12,    12,    15,    17,    12,    17,    17,     7,
     386,    17,    13,     7,    35,    12,     7,   356,    14,    53,
      17,    42,   144,     7,    13,    13,   363,    48,    17,    14,
      13,    58,    38,    39,    68,    13,    58,    64,    44,   376,
      62,    13,    59,    64,    27,    56,    68,   423,    53,     8,
      13,   388,    53,   390,    51,   419,    68,    13,    68,    68,
      66,    67,    58,    77,    62,    53,    62,   406,    62,    90,
      46,    62,    68,   410,    50,    51,    52,    62,    62,    42,
      14,    40,    60,    68,    43,    61,    62,   108,   425,    65,
      66,    67,    68,   152,    12,    71,   152,    31,   157,    17,
      59,    60,    61,    59,    12,    12,    42,    15,     9,    17,
      17,    13,    13,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    58,    58,    15,   146,    17,   148,    62,   150,
      13,   152,    58,    24,    68,   156,   157,   158,   159,    30,
      57,    58,    60,    13,    35,     8,    53,    38,    39,    58,
      53,    53,    13,    44,    62,   176,    17,    27,    12,   180,
      43,    15,   183,    17,   185,    56,    40,    58,    59,    60,
      57,    58,    63,     8,    65,    66,    67,    40,   300,    13,
      43,    58,    43,    17,    51,    59,    60,    61,   310,    12,
     211,   212,    15,    58,    17,    56,    59,    60,    61,   258,
      35,   257,    12,   325,    17,     6,    58,    17,    62,    43,
     231,    12,    47,    58,    15,    60,    17,    18,    19,    20,
      21,    22,    35,    17,    12,    13,    27,   248,    58,    17,
      58,   252,    57,    58,    47,   256,    53,   258,   393,    27,
       9,   262,   263,    51,    45,    46,    47,    17,   224,   225,
       6,     7,   407,   229,   230,    53,   277,   316,    59,   381,
      17,   282,   283,    19,    20,    21,    22,    17,   289,    12,
      13,   292,   427,   428,    17,    59,    12,   298,   433,    15,
     435,    17,   437,    57,    58,    56,   307,   308,   307,   307,
     311,   312,   313,    17,   315,   316,     4,   318,   319,   421,
      69,   322,    12,   324,     5,    15,    59,    17,    57,    58,
      38,    39,   333,   334,   335,    59,    44,    59,    87,    47,
      89,    59,    56,   344,   345,    17,    95,    96,   349,   349,
     349,   349,   346,    59,    56,    17,   357,    58,    66,    67,
     361,    56,   363,    60,     6,     7,   367,    31,    15,    12,
      12,    13,    15,   374,    17,    17,    15,    19,    20,    21,
      22,    56,    38,    39,   385,    27,   342,   388,    44,   390,
      12,    17,   393,    15,    53,    17,   397,    17,    56,    59,
      42,   402,   151,   402,   402,    17,   407,    59,    17,   410,
      66,    67,   413,   414,    59,    15,   398,   373,   419,   419,
     419,   419,   345,   402,   201,   357,   427,   428,   429,    18,
      -1,   152,   433,   182,   435,   408,   437,   207,    -1,   152,
     396,    -1,   398,    -1,    -1,    -1,   195,    -1,    -1,   405,
     199,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,
      -1,   417,    -1,    -1,   213,    17,    -1,    -1,    20,    -1,
      22,    -1,    -1,    25,    -1,    -1,   432,    -1,    -1,    31,
      32,    33,    34,    12,    36,   234,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,   253,    34,   255,    -1,    37,    -1,
      -1,   260,   261,    -1,    -1,   264,    -1,   266,    -1,    -1,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   290,   291,    -1,    -1,    -1,    98,    99,   100,   101,
     102,    -1,   104,    12,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,   323,    34,    -1,    -1,    37,   131,
     329,    -1,   134,   135,   136,   137,   138,   139,   140,    -1,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   355,    -1,    -1,   358,
      -1,   360,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     389,    -1,    -1,    -1,    -1,   394,   395,    -1,    -1,   398,
      -1,    -1,     0,     1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    14,    15,   220,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    -1,    34,    35,    36,    37,
     242,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
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
      -1,    -1,    -1,    -1,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,
      -1,     6,    63,    -1,    65,    66,    67,    12,    -1,    14,
      15,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    -1,    -1,    34,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    -1,    -1,     6,    -1,    -1,    -1,    62,    -1,    12,
      -1,    14,    15,    68,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    -1,
      -1,    34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    -1,     6,    -1,    -1,    -1,    62,
      -1,    12,    -1,    14,    15,    68,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    68
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,     0,     1,     6,    12,    14,    15,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    32,    34,    35,    36,    37,    41,    45,    46,    47,
      48,    49,    50,    51,    52,    54,    55,    62,    68,    71,
      72,    76,    80,    81,    82,    87,    88,    89,    90,    95,
      96,    97,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   123,   125,   126,   127,
     129,   132,   133,   134,   135,   136,   137,    15,    56,    17,
      80,    38,    39,    44,    66,    67,    80,    94,    47,    94,
      91,    80,    81,    82,    83,    94,    60,    80,    23,    29,
      34,    37,    49,    50,    51,    52,    83,    80,   114,    80,
      83,    83,    13,    17,    43,    17,    35,    47,    83,    53,
      13,    17,    43,    56,     8,    35,    47,    75,    83,    83,
      83,    51,    83,    80,    23,    29,    34,    37,    49,    50,
      51,    52,    83,    13,    17,    27,    42,    80,     8,    40,
      43,    59,    60,    61,    95,     6,     7,    90,    15,    80,
      89,    95,    95,    95,    58,    58,    58,    58,    58,    58,
      58,    58,    95,    95,    80,    95,    58,    95,    95,    95,
      91,    95,    94,    91,   130,    91,     4,     5,     6,     7,
       8,     9,    10,    11,    15,    16,    24,    30,    35,    56,
      59,    63,    65,    80,    93,    94,   116,    40,    59,    60,
      61,    91,    91,    60,    83,    83,    83,    83,    83,    83,
      51,    80,    17,    53,   128,    53,    77,    17,    13,   128,
      53,    99,    17,    83,    59,    83,    83,    83,    83,    83,
      83,    83,    51,    17,    13,   128,    80,    80,    91,   124,
      53,    80,    91,    18,    47,    59,    80,    89,    90,   113,
     127,    59,    15,    80,    62,    89,    62,    83,    83,    83,
      83,    83,    83,    83,    83,    27,    80,    91,    17,   131,
       4,     5,    91,    91,    92,    59,    92,   121,   124,    91,
      59,    59,    91,    83,    59,    58,    95,    95,    56,    59,
      17,    95,    95,    15,    80,   100,    73,    74,    91,    83,
      17,    43,     9,    91,    56,    91,    90,    89,    91,    91,
      80,    80,    91,    62,    91,    60,    31,   117,    57,    58,
      64,    58,    60,   120,    91,    91,    15,    53,    68,    79,
      80,    15,   128,    57,    58,    56,    17,    47,    48,    85,
      86,    87,   128,    80,    80,    16,   118,    98,    62,    89,
      62,    42,    84,    91,    84,   128,   121,    91,    17,    68,
      80,   122,    53,    57,    58,    95,   101,    15,    80,    79,
      13,    17,    31,    86,    87,    91,   121,   100,    91,    62,
      91,    80,    84,   120,    59,    59,    78,    91,    95,    80,
      58,    84,    57,    17,    13,   128,   119,   120,    57,    84,
      91,    84,   122,    91,    91,    31,    95,    78,    17,    85,
      59,    17,    95,   121,   122,   101,    84,    58,    60,    59,
      31,    15,   128,   120,    84,    68,   122,    68,   122,    15,
      80,    95,   122,   122,   122
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    73,    72,    74,    72,
      72,    72,    75,    75,    77,    76,    76,    76,    78,    78,
      78,    79,    79,    79,    80,    80,    80,    81,    82,    82,
      83,    83,    83,    83,    83,    84,    84,    85,    85,    85,
      85,    86,    86,    86,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    88,    88,
      88,    88,    88,    89,    89,    89,    89,    89,    89,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    94,    94,    94,    94,
      94,    95,    95,    95,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    98,    97,    99,    97,   100,   100,   100,
     100,   100,   101,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   103,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   104,   104,   105,   105,   105,   105,   106,
     106,   106,   106,   107,   107,   107,   107,   108,   108,   108,
     108,   109,   109,   109,   109,   110,   110,   110,   111,   111,
     112,   112,   113,   113,   113,   113,   113,   114,   114,   116,
     115,   117,   115,   118,   115,   119,   115,   120,   120,   121,
     121,   122,   122,   122,   122,   122,   123,   123,   124,   125,
     125,   125,   125,   125,   125,   126,   127,   127,   128,   128,
     128,   130,   129,   131,   131,   132,   132,   133,   133,   134,
     135,   136,   136,   137
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     0,     9,     0,     6,
       2,     2,     0,     1,     0,     8,     2,     2,     1,     2,
       2,     0,     1,     3,     1,     3,     2,     3,     1,     1,
       1,     3,     4,     4,     3,     0,     2,     1,     1,     2,
       2,     4,     6,     5,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     2,     1,     8,     6,     5,
       7,     5,     7,     1,     2,     2,     3,     4,     4,     1,
       1,     2,     1,     1,     0,     2,     2,     2,     2,     2,
       4,     4,     2,     2,     3,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     3,     5,     5,     3,
       4,     4,     3,     0,     9,     0,     7,     0,     1,     3,
       1,     3,     0,     5,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     3,     2,     4,     4,
       3,     2,     3,     3,     3,     2,     3,     2,     3,     2,
       3,     3,     3,     2,     3,     3,     3,     2,     3,     3,
       3,     2,     3,     3,     3,     2,     2,     3,     4,     2,
       1,     3,     2,     2,     2,     3,     1,     2,     3,     0,
       6,     0,     8,     0,     8,     0,    10,     1,     2,     0,
       5,     3,     5,     6,     5,     6,     2,     3,     1,     3,
       4,     3,     3,     3,     4,     2,     1,     1,     1,     3,
       4,     0,     5,     0,     3,     3,     5,     5,     5,     4,
       4,     4,     6,     4
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
#line 161 "antimony.ypp"
                             {}
#line 2078 "antimony.tab.cpp"
    break;

  case 4: /* input: input module  */
#line 162 "antimony.ypp"
                             { /*cout << endl << $2->ToString() << endl << endl;*/ }
#line 2084 "antimony.tab.cpp"
    break;

  case 5: /* input: input modulepart  */
#line 163 "antimony.ypp"
                                 {}
#line 2090 "antimony.tab.cpp"
    break;

  case 6: /* input: input function  */
#line 164 "antimony.ypp"
                               {}
#line 2096 "antimony.tab.cpp"
    break;

  case 7: /* input: input modulename  */
#line 165 "antimony.ypp"
                                 {}
#line 2102 "antimony.tab.cpp"
    break;

  case 8: /* input: input functionname  */
#line 166 "antimony.ypp"
                                   {}
#line 2108 "antimony.tab.cpp"
    break;

  case 9: /* input: input modulecvterm  */
#line 167 "antimony.ypp"
                                   {}
#line 2114 "antimony.tab.cpp"
    break;

  case 10: /* input: input functioncvterm  */
#line 168 "antimony.ypp"
                                     {}
#line 2120 "antimony.tab.cpp"
    break;

  case 11: /* input: input toplevel_sbo  */
#line 169 "antimony.ypp"
                                   {}
#line 2126 "antimony.tab.cpp"
    break;

  case 12: /* input: input annotationBlock  */
#line 170 "antimony.ypp"
                                      {}
#line 2132 "antimony.tab.cpp"
    break;

  case 13: /* input: input error  */
#line 171 "antimony.ypp"
                            {YYABORT;}
#line 2138 "antimony.tab.cpp"
    break;

  case 14: /* input: input "an error"  */
#line 172 "antimony.ypp"
                            {YYABORT;}
#line 2144 "antimony.tab.cpp"
    break;

  case 15: /* import: "'import'" "text string"  */
#line 175 "antimony.ypp"
                                  { if (g_registry.OpenFile(*((yyvsp[0].word)))==0) YYABORT;}
#line 2150 "antimony.tab.cpp"
    break;

  case 16: /* $@1: %empty  */
#line 178 "antimony.ypp"
                                         {g_registry.NewCurrentModule((yyvsp[0].word), NULL, (yyvsp[-1].maybemain));}
#line 2156 "antimony.tab.cpp"
    break;

  case 17: /* module: "'model' or 'module'" maybemain "element name" $@1 '(' variableexportlist ')' modulebody "'end'"  */
#line 179 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2166 "antimony.tab.cpp"
    break;

  case 18: /* $@2: %empty  */
#line 184 "antimony.ypp"
                                         {g_registry.NewCurrentModule((yyvsp[0].word), NULL, (yyvsp[-1].maybemain));}
#line 2172 "antimony.tab.cpp"
    break;

  case 19: /* module: "'model' or 'module'" maybemain "element name" $@2 modulebody "'end'"  */
#line 185 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2182 "antimony.tab.cpp"
    break;

  case 20: /* module: "'model' or 'module'" "name of an existing module"  */
#line 190 "antimony.ypp"
                               {g_registry.SetError("module '" + *((yyvsp[0].word)) + "' already defined."); YYABORT;}
#line 2188 "antimony.tab.cpp"
    break;

  case 21: /* module: "'model' or 'module'" "name of an existing function"  */
#line 191 "antimony.ypp"
                                {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a module because it is already a defined function."); YYABORT;}
#line 2194 "antimony.tab.cpp"
    break;

  case 22: /* maybemain: %empty  */
#line 194 "antimony.ypp"
                            {(yyval.maybemain) = false;}
#line 2200 "antimony.tab.cpp"
    break;

  case 23: /* maybemain: '*'  */
#line 195 "antimony.ypp"
                    {(yyval.maybemain) = true;}
#line 2206 "antimony.tab.cpp"
    break;

  case 24: /* $@3: %empty  */
#line 198 "antimony.ypp"
                                     {g_registry.NewUserFunction((yyvsp[0].word));}
#line 2212 "antimony.tab.cpp"
    break;

  case 25: /* function: "'function'" "element name" $@3 '(' variableexportlist ')' spacedformula "'end'"  */
#line 198 "antimony.ypp"
                                                                                                                    {if (g_registry.SetUserFunction((yyvsp[-1].formula))) YYABORT;}
#line 2218 "antimony.tab.cpp"
    break;

  case 26: /* function: "'function'" "name of an existing module"  */
#line 199 "antimony.ypp"
                                     {g_registry.SetError("Cannot use '" + *((yyvsp[0].word)) +"' as a function name because it is already the name of a module."); YYABORT;}
#line 2224 "antimony.tab.cpp"
    break;

  case 27: /* function: "'function'" "name of an existing function"  */
#line 200 "antimony.ypp"
                                      {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a new function because it is already a defined function."); YYABORT;}
#line 2230 "antimony.tab.cpp"
    break;

  case 28: /* spacedformula: formula  */
#line 203 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2236 "antimony.tab.cpp"
    break;

  case 29: /* spacedformula: lineend spacedformula  */
#line 204 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[0].formula);}
#line 2242 "antimony.tab.cpp"
    break;

  case 30: /* spacedformula: spacedformula lineend  */
#line 205 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[-1].formula);}
#line 2248 "antimony.tab.cpp"
    break;

  case 31: /* variableexportlist: %empty  */
#line 215 "antimony.ypp"
                            {}
#line 2254 "antimony.tab.cpp"
    break;

  case 32: /* variableexportlist: variable  */
#line 216 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2260 "antimony.tab.cpp"
    break;

  case 33: /* variableexportlist: variableexportlist ',' variable  */
#line 217 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2266 "antimony.tab.cpp"
    break;

  case 34: /* variable: "element name"  */
#line 220 "antimony.ypp"
                        {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[0].word)); }
#line 2272 "antimony.tab.cpp"
    break;

  case 35: /* variable: variable '.' "element name"  */
#line 221 "antimony.ypp"
                                     {(yyval.variable) = (yyvsp[-2].variable)->GetSubVariable((yyvsp[0].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[0].word)) + "' is not a subvariable of '" + (yyvsp[-2].variable)->GetNameDelimitedBy(".") + "'.");
                    YYABORT;
                  }
                }
#line 2283 "antimony.tab.cpp"
    break;

  case 36: /* variable: '$' variable  */
#line 227 "antimony.ypp"
                             {(yyval.variable) = (yyvsp[0].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;}
#line 2289 "antimony.tab.cpp"
    break;

  case 37: /* variablein: variable "'in'" variable  */
#line 230 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetCompartment((yyvsp[0].variable))) YYABORT; (yyval.variable) = (yyvsp[-2].variable);}
#line 2295 "antimony.tab.cpp"
    break;

  case 38: /* varmaybein: variable  */
#line 233 "antimony.ypp"
                         {(yyval.variable) = (yyvsp[0].variable);}
#line 2301 "antimony.tab.cpp"
    break;

  case 39: /* varmaybein: variablein  */
#line 234 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2307 "antimony.tab.cpp"
    break;

  case 40: /* varmaybeis: varmaybein  */
#line 237 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2313 "antimony.tab.cpp"
    break;

  case 41: /* varmaybeis: varmaybein '=' formula  */
#line 238 "antimony.ypp"
                                       {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2319 "antimony.tab.cpp"
    break;

  case 42: /* varmaybeis: varmaybein ':' '=' formula  */
#line 239 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT; }
#line 2325 "antimony.tab.cpp"
    break;

  case 43: /* varmaybeis: varmaybein '\'' '=' formula  */
#line 240 "antimony.ypp"
                                            {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT; }
#line 2331 "antimony.tab.cpp"
    break;

  case 44: /* varmaybeis: varmaybein "'has'" unitdef  */
#line 241 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2337 "antimony.tab.cpp"
    break;

  case 45: /* maybein: %empty  */
#line 244 "antimony.ypp"
                            {(yyval.variable) = NULL;}
#line 2343 "antimony.tab.cpp"
    break;

  case 46: /* maybein: "'in'" variable  */
#line 245 "antimony.ypp"
                                {(yyval.variable) = (yyvsp[0].variable);}
#line 2349 "antimony.tab.cpp"
    break;

  case 47: /* modulebody: modulepart  */
#line 248 "antimony.ypp"
                           {}
#line 2355 "antimony.tab.cpp"
    break;

  case 48: /* modulebody: moduleannotation  */
#line 249 "antimony.ypp"
                                 {}
#line 2361 "antimony.tab.cpp"
    break;

  case 49: /* modulebody: modulebody modulepart  */
#line 250 "antimony.ypp"
                                      {}
#line 2367 "antimony.tab.cpp"
    break;

  case 50: /* modulebody: modulebody moduleannotation  */
#line 251 "antimony.ypp"
                                           {}
#line 2373 "antimony.tab.cpp"
    break;

  case 51: /* moduleannotation: "'model' or 'module'" "element name" stringlist lineend  */
#line 254 "antimony.ypp"
                                                    {if (g_registry.ProcessGlobalCVTerm(&g_registry.CurrentModuleName(),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 2379 "antimony.tab.cpp"
    break;

  case 52: /* moduleannotation: "'model' or 'module'" "element name" '.' "element name" stringlist lineend  */
#line 255 "antimony.ypp"
                                                              {if (g_registry.ProcessGlobalCreatorTerm(&g_registry.CurrentModuleName(),(yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].stringlist))) YYABORT;}
#line 2385 "antimony.tab.cpp"
    break;

  case 53: /* moduleannotation: "'model' or 'module'" '.' "element name" '=' "number"  */
#line 257 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      module->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-2].word)) + "'. The only thing that can be set on the model this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 2399 "antimony.tab.cpp"
    break;

  case 54: /* modulepart: reaction lineend  */
#line 268 "antimony.ypp"
                                 {}
#line 2405 "antimony.tab.cpp"
    break;

  case 55: /* modulepart: assignment lineend  */
#line 269 "antimony.ypp"
                                   {}
#line 2411 "antimony.tab.cpp"
    break;

  case 56: /* modulepart: submodule lineend  */
#line 270 "antimony.ypp"
                                  {}
#line 2417 "antimony.tab.cpp"
    break;

  case 57: /* modulepart: varinitialize lineend  */
#line 271 "antimony.ypp"
                                      {}
#line 2423 "antimony.tab.cpp"
    break;

  case 58: /* modulepart: dnadef lineend  */
#line 272 "antimony.ypp"
                               {}
#line 2429 "antimony.tab.cpp"
    break;

  case 59: /* modulepart: event lineend  */
#line 273 "antimony.ypp"
                              {}
#line 2435 "antimony.tab.cpp"
    break;

  case 60: /* modulepart: unitinit lineend  */
#line 274 "antimony.ypp"
                                 {}
#line 2441 "antimony.tab.cpp"
    break;

  case 61: /* modulepart: deletion lineend  */
#line 275 "antimony.ypp"
                                 {}
#line 2447 "antimony.tab.cpp"
    break;

  case 62: /* modulepart: cvterm lineend  */
#line 276 "antimony.ypp"
                               {}
#line 2453 "antimony.tab.cpp"
    break;

  case 63: /* modulepart: variablein  */
#line 277 "antimony.ypp"
                           {}
#line 2459 "antimony.tab.cpp"
    break;

  case 64: /* modulepart: constraint lineend  */
#line 278 "antimony.ypp"
                                   {}
#line 2465 "antimony.tab.cpp"
    break;

  case 65: /* modulepart: objective lineend  */
#line 279 "antimony.ypp"
                                  {}
#line 2471 "antimony.tab.cpp"
    break;

  case 66: /* modulepart: lineend  */
#line 280 "antimony.ypp"
                        {}
#line 2477 "antimony.tab.cpp"
    break;

  case 67: /* reaction: varmaybein ':' reactantList reactionDivider reactantList ';' formula maybein  */
#line 284 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-7].variable), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-7].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2489 "antimony.tab.cpp"
    break;

  case 68: /* reaction: reactantList reactionDivider reactantList ';' formula maybein  */
#line 292 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2501 "antimony.tab.cpp"
    break;

  case 69: /* reaction: reactantList reactionDivider ';' formula maybein  */
#line 300 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2513 "antimony.tab.cpp"
    break;

  case 70: /* reaction: varmaybein ':' reactantList reactionDivider ';' formula maybein  */
#line 308 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2525 "antimony.tab.cpp"
    break;

  case 71: /* reaction: reactionDivider reactantList ';' formula maybein  */
#line 316 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2537 "antimony.tab.cpp"
    break;

  case 72: /* reaction: varmaybein ':' reactionDivider reactantList ';' formula maybein  */
#line 324 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2549 "antimony.tab.cpp"
    break;

  case 73: /* reactantList: variable  */
#line 333 "antimony.ypp"
                         {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2555 "antimony.tab.cpp"
    break;

  case 74: /* reactantList: "number" variable  */
#line 334 "antimony.ypp"
                             {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2561 "antimony.tab.cpp"
    break;

  case 75: /* reactantList: variable variable  */
#line 335 "antimony.ypp"
                                  {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2567 "antimony.tab.cpp"
    break;

  case 76: /* reactantList: reactantList '+' variable  */
#line 336 "antimony.ypp"
                                          {(yyval.reactantList) = (yyvsp[-2].reactantList); if((yyvsp[-2].reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2573 "antimony.tab.cpp"
    break;

  case 77: /* reactantList: reactantList '+' "number" variable  */
#line 337 "antimony.ypp"
                                              {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2579 "antimony.tab.cpp"
    break;

  case 78: /* reactantList: reactantList '+' variable variable  */
#line 338 "antimony.ypp"
                                                   {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2585 "antimony.tab.cpp"
    break;

  case 79: /* reactionDivider: "->"  */
#line 342 "antimony.ypp"
                           {(yyval.reactionDivider) = rdBecomes;}
#line 2591 "antimony.tab.cpp"
    break;

  case 80: /* reactionDivider: "-|"  */
#line 343 "antimony.ypp"
                           {(yyval.reactionDivider) = rdInhibits;}
#line 2597 "antimony.tab.cpp"
    break;

  case 81: /* reactionDivider: '-' '('  */
#line 344 "antimony.ypp"
                        {(yyval.reactionDivider) = rdInfluences;}
#line 2603 "antimony.tab.cpp"
    break;

  case 82: /* reactionDivider: "-o"  */
#line 345 "antimony.ypp"
                            {(yyval.reactionDivider) = rdInfluences;}
#line 2609 "antimony.tab.cpp"
    break;

  case 83: /* reactionDivider: "=>"  */
#line 346 "antimony.ypp"
                             {(yyval.reactionDivider) = rdBecomesIrreversibly;}
#line 2615 "antimony.tab.cpp"
    break;

  case 84: /* formula: %empty  */
#line 349 "antimony.ypp"
                            {(yyval.formula) = g_registry.NewBlankFormula(); }
#line 2621 "antimony.tab.cpp"
    break;

  case 85: /* formula: formula "..."  */
#line 350 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddEllipses();}
#line 2627 "antimony.tab.cpp"
    break;

  case 86: /* formula: formula variable  */
#line 351 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); if((yyvsp[-1].formula)->AddVariable((yyvsp[0].variable))) YYABORT; }
#line 2633 "antimony.tab.cpp"
    break;

  case 87: /* formula: formula "number"  */
#line 352 "antimony.ypp"
                             {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddNum((yyvsp[0].num)); }
#line 2639 "antimony.tab.cpp"
    break;

  case 88: /* formula: formula "name of a pre-defined constant"  */
#line 353 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2645 "antimony.tab.cpp"
    break;

  case 89: /* formula: formula "name of an existing function"  */
#line 354 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2651 "antimony.tab.cpp"
    break;

  case 90: /* formula: formula '(' commaformula ')'  */
#line 355 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2657 "antimony.tab.cpp"
    break;

  case 91: /* formula: formula '{' commaformula '}'  */
#line 356 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddCurlyBrackets(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2663 "antimony.tab.cpp"
    break;

  case 92: /* formula: formula mathThing  */
#line 357 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddMathThing((yyvsp[0].character)); }
#line 2669 "antimony.tab.cpp"
    break;

  case 93: /* formula: formula inequality  */
#line 358 "antimony.ypp"
                                   {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddInequality((yyvsp[0].inequality)); }
#line 2675 "antimony.tab.cpp"
    break;

  case 94: /* formula: formula '=' '='  */
#line 359 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('='); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2681 "antimony.tab.cpp"
    break;

  case 95: /* formula: formula '&' '&'  */
#line 360 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('&'); (yyvsp[-2].formula)->AddMathThing('&'); }
#line 2687 "antimony.tab.cpp"
    break;

  case 96: /* formula: formula '|' '|'  */
#line 361 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('|'); (yyvsp[-2].formula)->AddMathThing('|'); }
#line 2693 "antimony.tab.cpp"
    break;

  case 97: /* commaformula: formula  */
#line 364 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2699 "antimony.tab.cpp"
    break;

  case 98: /* commaformula: commaformula ',' formula  */
#line 365 "antimony.ypp"
                                         {(yyval.formula) = (yyvsp[-2].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[0].formula)); }
#line 2705 "antimony.tab.cpp"
    break;

  case 99: /* mathThing: '+'  */
#line 368 "antimony.ypp"
                    {(yyval.character) = '+';}
#line 2711 "antimony.tab.cpp"
    break;

  case 100: /* mathThing: '-'  */
#line 369 "antimony.ypp"
                    {(yyval.character) = '-';}
#line 2717 "antimony.tab.cpp"
    break;

  case 101: /* mathThing: '*'  */
#line 370 "antimony.ypp"
                    {(yyval.character) = '*';}
#line 2723 "antimony.tab.cpp"
    break;

  case 102: /* mathThing: '/'  */
#line 371 "antimony.ypp"
                    {(yyval.character) = '/';}
#line 2729 "antimony.tab.cpp"
    break;

  case 103: /* mathThing: '^'  */
#line 372 "antimony.ypp"
                    {(yyval.character) = '^';}
#line 2735 "antimony.tab.cpp"
    break;

  case 104: /* mathThing: '!'  */
#line 373 "antimony.ypp"
                    {(yyval.character) = '!';}
#line 2741 "antimony.tab.cpp"
    break;

  case 105: /* mathThing: '%'  */
#line 374 "antimony.ypp"
                    {(yyval.character) = '%';}
#line 2747 "antimony.tab.cpp"
    break;

  case 106: /* inequality: '<'  */
#line 377 "antimony.ypp"
                    {(yyval.inequality) = constLT;}
#line 2753 "antimony.tab.cpp"
    break;

  case 107: /* inequality: "<="  */
#line 378 "antimony.ypp"
                    {(yyval.inequality) = constLEQ;}
#line 2759 "antimony.tab.cpp"
    break;

  case 108: /* inequality: '>'  */
#line 379 "antimony.ypp"
                    {(yyval.inequality) = constGT;}
#line 2765 "antimony.tab.cpp"
    break;

  case 109: /* inequality: ">="  */
#line 380 "antimony.ypp"
                    {(yyval.inequality) = constGEQ;}
#line 2771 "antimony.tab.cpp"
    break;

  case 110: /* inequality: "!="  */
#line 381 "antimony.ypp"
                    {(yyval.inequality) = constNEQ;}
#line 2777 "antimony.tab.cpp"
    break;

  case 111: /* lineend: ';'  */
#line 384 "antimony.ypp"
                    {}
#line 2783 "antimony.tab.cpp"
    break;

  case 112: /* lineend: '\n'  */
#line 385 "antimony.ypp"
                     {}
#line 2789 "antimony.tab.cpp"
    break;

  case 113: /* lineend: "end of line"  */
#line 386 "antimony.ypp"
                    {}
#line 2795 "antimony.tab.cpp"
    break;

  case 114: /* assignment: varmaybein ':' maxormin formula  */
#line 389 "antimony.ypp"
                                                {if (g_registry.CurrentModule()->AddObjective((yyvsp[-3].variable), (yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 2801 "antimony.tab.cpp"
    break;

  case 115: /* assignment: varmaybein '=' formula  */
#line 390 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2807 "antimony.tab.cpp"
    break;

  case 116: /* assignment: varmaybein "'is'" variable  */
#line 391 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->Synchronize((yyvsp[0].variable), NULL)) YYABORT;}
#line 2813 "antimony.tab.cpp"
    break;

  case 117: /* assignment: varmaybein "'is'" variable '/' variable  */
#line 392 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[-2].variable), (yyvsp[0].variable))) YYABORT;}
#line 2819 "antimony.tab.cpp"
    break;

  case 118: /* assignment: varmaybein '*' variable "'is'" variable  */
#line 393 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[0].variable), (yyvsp[-2].variable))) YYABORT;}
#line 2825 "antimony.tab.cpp"
    break;

  case 119: /* assignment: varmaybein "'is'" "text string"  */
#line 394 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetDisplayName(*((yyvsp[0].word)))) YYABORT;}
#line 2831 "antimony.tab.cpp"
    break;

  case 120: /* assignment: varmaybein ':' '=' formula  */
#line 395 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT;}
#line 2837 "antimony.tab.cpp"
    break;

  case 121: /* assignment: varmaybein '\'' '=' formula  */
#line 396 "antimony.ypp"
                                            {if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT;}
#line 2843 "antimony.tab.cpp"
    break;

  case 122: /* assignment: varmaybein "'has'" unitdef  */
#line 397 "antimony.ypp"
                                           {if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2849 "antimony.tab.cpp"
    break;

  case 123: /* $@4: %empty  */
#line 401 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2855 "antimony.tab.cpp"
    break;

  case 124: /* submodule: varmaybein ':' "name of an existing module" '(' $@4 variableimportlist ')' submodifications maybein  */
#line 401 "antimony.ypp"
                                                                                                                             {if ((yyvsp[0].variable) != NULL) {if ((yyvsp[-8].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2861 "antimony.tab.cpp"
    break;

  case 125: /* $@5: %empty  */
#line 402 "antimony.ypp"
                            {if(g_registry.CurrentModule()->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2867 "antimony.tab.cpp"
    break;

  case 126: /* submodule: "name of an existing module" '(' $@5 variableimportlist ')' submodifications maybein  */
#line 402 "antimony.ypp"
                                                                                                                                     {if ((yyvsp[0].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2873 "antimony.tab.cpp"
    break;

  case 127: /* variableimportlist: %empty  */
#line 406 "antimony.ypp"
                            {}
#line 2879 "antimony.tab.cpp"
    break;

  case 128: /* variableimportlist: variable  */
#line 407 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2885 "antimony.tab.cpp"
    break;

  case 129: /* variableimportlist: variableimportlist ',' variable  */
#line 408 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2891 "antimony.tab.cpp"
    break;

  case 130: /* variableimportlist: "number"  */
#line 409 "antimony.ypp"
                    {if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2897 "antimony.tab.cpp"
    break;

  case 131: /* variableimportlist: variableimportlist ',' "number"  */
#line 410 "antimony.ypp"
                                           { if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2903 "antimony.tab.cpp"
    break;

  case 132: /* submodifications: %empty  */
#line 414 "antimony.ypp"
                            {}
#line 2909 "antimony.tab.cpp"
    break;

  case 133: /* submodifications: submodifications ',' "element name" '=' variable  */
#line 415 "antimony.ypp"
                                                          {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].variable));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2917 "antimony.tab.cpp"
    break;

  case 134: /* submodifications: submodifications ',' "element name" '=' "number"  */
#line 419 "antimony.ypp"
                                                     {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].num));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2925 "antimony.tab.cpp"
    break;

  case 135: /* varinitialize: specinit  */
#line 423 "antimony.ypp"
                         { }
#line 2931 "antimony.tab.cpp"
    break;

  case 136: /* varinitialize: formulainit  */
#line 424 "antimony.ypp"
                            { }
#line 2937 "antimony.tab.cpp"
    break;

  case 137: /* varinitialize: reactioninit  */
#line 425 "antimony.ypp"
                             { }
#line 2943 "antimony.tab.cpp"
    break;

  case 138: /* varinitialize: dnainit  */
#line 426 "antimony.ypp"
                        { }
#line 2949 "antimony.tab.cpp"
    break;

  case 139: /* varinitialize: geneinit  */
#line 427 "antimony.ypp"
                         { }
#line 2955 "antimony.tab.cpp"
    break;

  case 140: /* varinitialize: operatorinit  */
#line 428 "antimony.ypp"
                             { }
#line 2961 "antimony.tab.cpp"
    break;

  case 141: /* varinitialize: compartmentinit  */
#line 429 "antimony.ypp"
                                { }
#line 2967 "antimony.tab.cpp"
    break;

  case 142: /* varinitialize: varconstinit  */
#line 430 "antimony.ypp"
                             { }
#line 2973 "antimony.tab.cpp"
    break;

  case 143: /* specinit: "'species'" varmaybeis  */
#line 433 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2979 "antimony.tab.cpp"
    break;

  case 144: /* specinit: "'var'" "'species'" varmaybeis  */
#line 434 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2985 "antimony.tab.cpp"
    break;

  case 145: /* specinit: "'const'" "'species'" varmaybeis  */
#line 435 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2991 "antimony.tab.cpp"
    break;

  case 146: /* specinit: "'substanceOnly'" "'species'" varmaybeis  */
#line 436 "antimony.ypp"
                                             {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 2997 "antimony.tab.cpp"
    break;

  case 147: /* specinit: "'substanceOnly'" varmaybeis  */
#line 437 "antimony.ypp"
                                     {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3003 "antimony.tab.cpp"
    break;

  case 148: /* specinit: "'var'" "'substanceOnly'" "'species'" varmaybeis  */
#line 438 "antimony.ypp"
                                                     {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3009 "antimony.tab.cpp"
    break;

  case 149: /* specinit: "'const'" "'substanceOnly'" "'species'" varmaybeis  */
#line 439 "antimony.ypp"
                                                       {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3015 "antimony.tab.cpp"
    break;

  case 150: /* specinit: specinit ',' varmaybeis  */
#line 440 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3021 "antimony.tab.cpp"
    break;

  case 151: /* formulainit: "'formula'" varmaybeis  */
#line 443 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3027 "antimony.tab.cpp"
    break;

  case 152: /* formulainit: "'var'" "'formula'" varmaybeis  */
#line 444 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3033 "antimony.tab.cpp"
    break;

  case 153: /* formulainit: "'const'" "'formula'" varmaybeis  */
#line 445 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3039 "antimony.tab.cpp"
    break;

  case 154: /* formulainit: formulainit ',' varmaybeis  */
#line 446 "antimony.ypp"
                                           {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3045 "antimony.tab.cpp"
    break;

  case 155: /* reactioninit: "'reaction'" varmaybeis  */
#line 449 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3051 "antimony.tab.cpp"
    break;

  case 156: /* reactioninit: "'var'" "'reaction'" varmaybeis  */
#line 450 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3057 "antimony.tab.cpp"
    break;

  case 157: /* reactioninit: "'const'" "'reaction'"  */
#line 451 "antimony.ypp"
                                   {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; }
#line 3063 "antimony.tab.cpp"
    break;

  case 158: /* reactioninit: reactioninit ',' varmaybeis  */
#line 452 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3069 "antimony.tab.cpp"
    break;

  case 159: /* dnainit: "'DNA'" varmaybeis  */
#line 455 "antimony.ypp"
                               {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3075 "antimony.tab.cpp"
    break;

  case 160: /* dnainit: "'var'" "'DNA'" varmaybeis  */
#line 456 "antimony.ypp"
                                       {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3081 "antimony.tab.cpp"
    break;

  case 161: /* dnainit: "'const'" "'DNA'" varmaybeis  */
#line 457 "antimony.ypp"
                                         {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3087 "antimony.tab.cpp"
    break;

  case 162: /* dnainit: dnainit ',' varmaybeis  */
#line 458 "antimony.ypp"
                                       {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3093 "antimony.tab.cpp"
    break;

  case 163: /* geneinit: "'gene'" varmaybeis  */
#line 461 "antimony.ypp"
                                {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3099 "antimony.tab.cpp"
    break;

  case 164: /* geneinit: "'var'" "'gene'" varmaybeis  */
#line 462 "antimony.ypp"
                                        {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3105 "antimony.tab.cpp"
    break;

  case 165: /* geneinit: "'const'" "'gene'" varmaybeis  */
#line 463 "antimony.ypp"
                                          {g_registry.SetError("Genes may not be set 'const'."); YYABORT; }
#line 3111 "antimony.tab.cpp"
    break;

  case 166: /* geneinit: geneinit ',' varmaybeis  */
#line 464 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3117 "antimony.tab.cpp"
    break;

  case 167: /* operatorinit: "'operator'" varmaybeis  */
#line 467 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3123 "antimony.tab.cpp"
    break;

  case 168: /* operatorinit: "'var'" "'operator'" varmaybeis  */
#line 468 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3129 "antimony.tab.cpp"
    break;

  case 169: /* operatorinit: "'const'" "'operator'" varmaybeis  */
#line 469 "antimony.ypp"
                                              {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3135 "antimony.tab.cpp"
    break;

  case 170: /* operatorinit: operatorinit ',' varmaybeis  */
#line 470 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3141 "antimony.tab.cpp"
    break;

  case 171: /* compartmentinit: "'compartment'" varmaybeis  */
#line 474 "antimony.ypp"
                                       {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3147 "antimony.tab.cpp"
    break;

  case 172: /* compartmentinit: "'var'" "'compartment'" varmaybeis  */
#line 475 "antimony.ypp"
                                               {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3153 "antimony.tab.cpp"
    break;

  case 173: /* compartmentinit: "'const'" "'compartment'" varmaybeis  */
#line 476 "antimony.ypp"
                                                 {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3159 "antimony.tab.cpp"
    break;

  case 174: /* compartmentinit: compartmentinit ',' varmaybeis  */
#line 477 "antimony.ypp"
                                               {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3165 "antimony.tab.cpp"
    break;

  case 175: /* varconstinit: "'var'" varmaybeis  */
#line 480 "antimony.ypp"
                                   {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst();}
#line 3171 "antimony.tab.cpp"
    break;

  case 176: /* varconstinit: "'const'" varmaybeis  */
#line 481 "antimony.ypp"
                                     {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst();}
#line 3177 "antimony.tab.cpp"
    break;

  case 177: /* varconstinit: varconstinit ',' varmaybeis  */
#line 482 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst();}
#line 3183 "antimony.tab.cpp"
    break;

  case 178: /* unitinit: "'unit'" variable '=' formula  */
#line 485 "antimony.ypp"
                                              {if ((yyvsp[-2].variable)->SetType(varUnitDefinition)) YYABORT;
                                               if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                                               if ((yyvsp[-2].variable)->GetUnitDef()->SetFromFormula((yyvsp[0].formula))) YYABORT;}
#line 3191 "antimony.tab.cpp"
    break;

  case 179: /* unitinit: "'unit'" variable  */
#line 488 "antimony.ypp"
                                  {if ((yyvsp[0].variable)->SetType(varUnitDefinition)) YYABORT;}
#line 3197 "antimony.tab.cpp"
    break;

  case 180: /* dnadef: dnastrand  */
#line 491 "antimony.ypp"
                          {if (g_registry.SaveWorkingStrand()) YYABORT;}
#line 3203 "antimony.tab.cpp"
    break;

  case 181: /* dnadef: varmaybein ':' dnastrand  */
#line 492 "antimony.ypp"
                                         {if (g_registry.SetStrandAs((yyvsp[-2].variable))) YYABORT;}
#line 3209 "antimony.tab.cpp"
    break;

  case 182: /* dnastrand: "--" variable  */
#line 495 "antimony.ypp"
                                {if (g_registry.SetNewUpstreamOpen((yyvsp[0].variable))) YYABORT;}
#line 3215 "antimony.tab.cpp"
    break;

  case 183: /* dnastrand: "--" dnamiddle  */
#line 496 "antimony.ypp"
                                 {g_registry.SetOpenUpstream(); }
#line 3221 "antimony.tab.cpp"
    break;

  case 184: /* dnastrand: dnamiddle variable  */
#line 497 "antimony.ypp"
                                   {if (g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3227 "antimony.tab.cpp"
    break;

  case 185: /* dnastrand: "--" dnamiddle variable  */
#line 498 "antimony.ypp"
                                          {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3233 "antimony.tab.cpp"
    break;

  case 186: /* dnastrand: dnamiddle  */
#line 499 "antimony.ypp"
                          { }
#line 3239 "antimony.tab.cpp"
    break;

  case 187: /* dnamiddle: variable "--"  */
#line 502 "antimony.ypp"
                                {if (g_registry.SetNewDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3245 "antimony.tab.cpp"
    break;

  case 188: /* dnamiddle: dnamiddle variable "--"  */
#line 503 "antimony.ypp"
                                          {if (g_registry.SetDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3251 "antimony.tab.cpp"
    break;

  case 189: /* $@6: %empty  */
#line 506 "antimony.ypp"
                           {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula))) YYABORT;}
#line 3257 "antimony.tab.cpp"
    break;

  case 190: /* event: "'at'" formula $@6 eventmodifications colonret assignmentlist  */
#line 506 "antimony.ypp"
                                                                                                                        {}
#line 3263 "antimony.tab.cpp"
    break;

  case 191: /* $@7: %empty  */
#line 507 "antimony.ypp"
                                         {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula))) YYABORT;}
#line 3269 "antimony.tab.cpp"
    break;

  case 192: /* event: "'at'" formula "'after'" formula $@7 eventmodifications colonret assignmentlist  */
#line 507 "antimony.ypp"
                                                                                                                                          {}
#line 3275 "antimony.tab.cpp"
    break;

  case 193: /* $@8: %empty  */
#line 508 "antimony.ypp"
                                          {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula), (yyvsp[-3].variable))) YYABORT;}
#line 3281 "antimony.tab.cpp"
    break;

  case 194: /* event: varmaybein ':' "'at'" formula $@8 eventmodifications colonret assignmentlist  */
#line 508 "antimony.ypp"
                                                                                                                                            {}
#line 3287 "antimony.tab.cpp"
    break;

  case 195: /* $@9: %empty  */
#line 509 "antimony.ypp"
                                                        {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula), (yyvsp[-5].variable))) YYABORT;}
#line 3293 "antimony.tab.cpp"
    break;

  case 196: /* event: varmaybein ':' "'at'" formula "'after'" formula $@9 eventmodifications colonret assignmentlist  */
#line 509 "antimony.ypp"
                                                                                                                                                             {}
#line 3299 "antimony.tab.cpp"
    break;

  case 197: /* colonret: ':'  */
#line 512 "antimony.ypp"
                    {}
#line 3305 "antimony.tab.cpp"
    break;

  case 198: /* colonret: colonret '\n'  */
#line 513 "antimony.ypp"
                              {}
#line 3311 "antimony.tab.cpp"
    break;

  case 199: /* eventmodifications: %empty  */
#line 516 "antimony.ypp"
                                 {}
#line 3317 "antimony.tab.cpp"
    break;

  case 200: /* eventmodifications: eventmodifications ',' "element name" '=' formula  */
#line 517 "antimony.ypp"
                                                           {if (CaselessStrCmp(false, *(yyvsp[-2].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[0].formula));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[0].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;}}
#line 3327 "antimony.tab.cpp"
    break;

  case 201: /* assignmentlist: variable '=' formula  */
#line 524 "antimony.ypp"
                                     {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3333 "antimony.tab.cpp"
    break;

  case 202: /* assignmentlist: variable '=' formula ':' assignmentlist  */
#line 525 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3339 "antimony.tab.cpp"
    break;

  case 203: /* assignmentlist: variable '=' formula ':' '\n' assignmentlist  */
#line 526 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3345 "antimony.tab.cpp"
    break;

  case 204: /* assignmentlist: variable '=' formula ',' assignmentlist  */
#line 527 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3351 "antimony.tab.cpp"
    break;

  case 205: /* assignmentlist: variable '=' formula ',' '\n' assignmentlist  */
#line 528 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3357 "antimony.tab.cpp"
    break;

  case 206: /* deletion: "'delete'" variable  */
#line 531 "antimony.ypp"
                                    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3363 "antimony.tab.cpp"
    break;

  case 207: /* deletion: deletion ',' variable  */
#line 532 "antimony.ypp"
                                      {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3369 "antimony.tab.cpp"
    break;

  case 208: /* unitdef: formula  */
#line 535 "antimony.ypp"
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
#line 3387 "antimony.tab.cpp"
    break;

  case 209: /* constraint: "number" inequality formula  */
#line 550 "antimony.ypp"
                                       {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3393 "antimony.tab.cpp"
    break;

  case 210: /* constraint: '-' "number" inequality formula  */
#line 551 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint(-(yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3399 "antimony.tab.cpp"
    break;

  case 211: /* constraint: "name of a pre-defined constant" inequality formula  */
#line 552 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3405 "antimony.tab.cpp"
    break;

  case 212: /* constraint: "element name" inequality formula  */
#line 553 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3411 "antimony.tab.cpp"
    break;

  case 213: /* constraint: "'constraint'" ':' formula  */
#line 554 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[0].formula))) YYABORT;}
#line 3417 "antimony.tab.cpp"
    break;

  case 214: /* constraint: "'constraint'" variable ':' formula  */
#line 555 "antimony.ypp"
                                                    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3423 "antimony.tab.cpp"
    break;

  case 215: /* objective: maxormin formula  */
#line 558 "antimony.ypp"
                                              {if (g_registry.CurrentModule()->AddObjective((yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 3429 "antimony.tab.cpp"
    break;

  case 216: /* maxormin: "'maximize'"  */
#line 561 "antimony.ypp"
                             {(yyval.maxormin) = true;}
#line 3435 "antimony.tab.cpp"
    break;

  case 217: /* maxormin: "'minimize'"  */
#line 562 "antimony.ypp"
                             {(yyval.maxormin) = false;}
#line 3441 "antimony.tab.cpp"
    break;

  case 218: /* stringlist: "text string"  */
#line 565 "antimony.ypp"
                           { (yyval.stringlist) = new std::vector<std::string>(); (yyval.stringlist)->push_back(*((yyvsp[0].word))); }
#line 3447 "antimony.tab.cpp"
    break;

  case 219: /* stringlist: stringlist ',' "text string"  */
#line 566 "antimony.ypp"
                                          { (yyval.stringlist) = (yyvsp[-2].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3453 "antimony.tab.cpp"
    break;

  case 220: /* stringlist: stringlist ',' '\n' "text string"  */
#line 567 "antimony.ypp"
                                               { (yyval.stringlist) = (yyvsp[-3].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3459 "antimony.tab.cpp"
    break;

  case 221: /* $@10: %empty  */
#line 569 "antimony.ypp"
                                    {if (g_registry.SetCurrentModuleIf((yyvsp[0].word), (yyvsp[-1].word))) YYABORT;}
#line 3465 "antimony.tab.cpp"
    break;

  case 222: /* annotationBlock: "element name" "name of an existing module" $@10 annotations "'end'"  */
#line 569 "antimony.ypp"
                                                                                                          {g_registry.RevertToPreviousModule();}
#line 3471 "antimony.tab.cpp"
    break;

  case 223: /* annotations: %empty  */
#line 572 "antimony.ypp"
                            {}
#line 3477 "antimony.tab.cpp"
    break;

  case 224: /* annotations: "element name" ':' stringlist  */
#line 573 "antimony.ypp"
                                       {string modname = g_registry.CurrentModuleName(); g_registry.ProcessGlobalCVTerm(&modname, (yyvsp[-2].word), (yyvsp[0].stringlist));}
#line 3483 "antimony.tab.cpp"
    break;

  case 225: /* cvterm: variable "element name" stringlist  */
#line 578 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->ProcessCVTerm((yyvsp[-2].variable),(yyvsp[-1].word),(yyvsp[0].stringlist))) YYABORT;}
#line 3489 "antimony.tab.cpp"
    break;

  case 226: /* cvterm: variable "element name" '.' "element name" stringlist  */
#line 579 "antimony.ypp"
                                                        {if (g_registry.ProcessCreatorTerm((yyvsp[-4].variable), (yyvsp[-3].word), (yyvsp[-1].word), (yyvsp[0].stringlist))) YYABORT;}
#line 3495 "antimony.tab.cpp"
    break;

  case 227: /* toplevel_sbo: "name of an existing module" '.' "element name" '=' "number"  */
#line 583 "antimony.ypp"
                  { Module* module = g_registry.GetModule(*(yyvsp[-4].word));
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      module->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3509 "antimony.tab.cpp"
    break;

  case 228: /* toplevel_sbo: "name of an existing function" '.' "element name" '=' "number"  */
#line 594 "antimony.ypp"
                  { Module* function = g_registry.GetModule(*(yyvsp[-4].word));
                    if (function && (yyvsp[-2].word) &&  CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      function->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3523 "antimony.tab.cpp"
    break;

  case 229: /* modulename: "name of an existing module" "'is'" "text string" lineend  */
#line 606 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3529 "antimony.tab.cpp"
    break;

  case 230: /* functionname: "name of an existing function" "'is'" "text string" lineend  */
#line 608 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3535 "antimony.tab.cpp"
    break;

  case 231: /* modulecvterm: "name of an existing module" "element name" stringlist lineend  */
#line 611 "antimony.ypp"
                                                   {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3541 "antimony.tab.cpp"
    break;

  case 232: /* modulecvterm: "name of an existing module" "element name" '.' "element name" stringlist lineend  */
#line 612 "antimony.ypp"
                                                               {if (g_registry.ProcessGlobalCreatorTerm((yyvsp[-5].word), (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].stringlist))) YYABORT;}
#line 3547 "antimony.tab.cpp"
    break;

  case 233: /* functioncvterm: "name of an existing function" "element name" stringlist lineend  */
#line 613 "antimony.ypp"
                                                    {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3553 "antimony.tab.cpp"
    break;


#line 3557 "antimony.tab.cpp"

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
  if (cc > 0 && (isalpha(cc) || cc == '_') && cc != '`') {
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
  if (cc == '`') {
    string textstring;
    // Check if we're a three-tick block.
    if (g_registry.input->peek() == '`') {
      g_registry.input->get(cc);
      if (g_registry.input->peek() == '`') {
        g_registry.input->get(cc);
        g_registry.input->get(cc);
        while (cc != '`' && !g_registry.input->eof()) {
          textstring += cc;
          g_registry.input->get(cc);
          if (cc=='`') {
            g_registry.input->get(cc);
            if (cc=='`') {
              g_registry.input->get(cc);
              if (cc=='`') {
                antimony_yylval.word = g_registry.AddWord(textstring);
                return TEXTSTRING;
              }
              else {
                textstring += '`';
                textstring += '`';
              }
            }
            else {
              textstring += '`';
            }
          }
        }
      }
      else {
        // Just two ticks (i.e. empty string)
        antimony_yylval.word = g_registry.AddWord("");
        return TEXTSTRING;
      }
    }
    else return '`';
  }
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
