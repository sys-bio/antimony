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
#define YYLAST   1202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  236
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  450

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
     251,   254,   259,   264,   269,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   296,   304,
     312,   320,   328,   336,   346,   347,   348,   349,   350,   351,
     355,   356,   357,   358,   359,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   377,   378,
     381,   382,   383,   384,   385,   386,   387,   390,   391,   392,
     393,   394,   397,   398,   399,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   414,   414,   415,   415,   419,   420,
     421,   422,   423,   427,   428,   432,   436,   437,   438,   439,
     440,   441,   442,   443,   446,   447,   448,   449,   450,   451,
     452,   453,   456,   457,   458,   459,   462,   463,   464,   465,
     468,   469,   470,   471,   474,   475,   476,   477,   480,   481,
     482,   483,   487,   488,   489,   490,   493,   494,   495,   498,
     501,   504,   505,   508,   509,   510,   511,   512,   515,   516,
     519,   519,   520,   520,   521,   521,   522,   522,   525,   526,
     529,   530,   537,   538,   539,   540,   541,   544,   545,   548,
     563,   564,   565,   566,   567,   568,   571,   574,   575,   578,
     579,   580,   582,   582,   585,   586,   591,   592,   593,   596,
     607,   619,   621,   625,   626,   627,   628
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

#define YYPACT_NINF (-348)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-75)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -348,   653,  -348,  -348,    22,   209,  -348,    54,   334,  -348,
    -348,  -348,  -348,  -348,   209,   204,   102,   215,   209,   209,
     209,  -348,   209,   191,   172,   209,    -8,  -348,  -348,   116,
      49,   209,   209,   209,   173,   209,   445,  -348,  -348,  -348,
    -348,  -348,   471,   134,   140,  -348,    56,   273,   197,  -348,
      56,    56,    56,    -3,    17,    94,   112,   148,   155,   170,
     181,    56,    56,  -348,   209,    56,    44,    56,    56,  -348,
    -348,    56,  -348,  -348,  -348,  -348,  -348,   204,  -348,  -348,
      51,  -348,  -348,  -348,  -348,  -348,    51,  -348,  -348,  -348,
     782,    38,  -348,   176,  -348,  -348,  -348,    48,   209,   209,
     209,   209,   209,  -348,   209,   190,  -348,    40,   209,    51,
    -348,  -348,   186,   203,   230,  -348,  -348,  -348,  -348,  -348,
     256,    73,   237,  -348,  -348,  -348,  -348,   279,  -348,  -348,
    -348,   209,  -348,     3,   209,   209,   209,   209,   209,   209,
     209,   249,  -348,   285,    75,  -348,   209,    51,   209,  -348,
     110,  -348,   119,   254,  -348,   260,   257,    70,   209,   233,
      15,  -348,  -348,  -348,   209,   209,   209,   209,   209,   209,
     209,   209,  -348,  -348,   117,  -348,   209,  -348,  -348,  -348,
     974,  -348,  -348,   974,   312,   974,   326,   330,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
     277,  -348,  -348,    51,  -348,  -348,  -348,  -348,  -348,   282,
     283,   974,   974,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
     209,   117,   284,  -348,    55,    56,   275,   289,   336,    55,
      56,   272,   298,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,   209,  -348,   338,   299,    51,    25,   974,  -348,
    -348,   141,   974,  -348,   300,  -348,   241,   273,   197,  -348,
    -348,  -348,   209,   233,  -348,    19,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,  -348,  -348,    51,   974,   305,   328,
    -348,  -348,   974,   974,   139,  -348,    39,    -6,  -348,   974,
    -348,  -348,   974,  -348,   345,   108,  -348,  -348,   209,   351,
     128,  -348,  -348,  -348,    51,   220,   311,  1134,   974,  -348,
     145,   209,   209,   846,  -348,   974,   156,    28,   974,   974,
      51,    51,   910,  -348,   910,   203,  -348,  -348,  -348,  -348,
    -348,   352,  -348,     8,   974,   974,  -348,  -348,   321,   228,
      51,  -348,    56,    55,  -348,   286,   209,   204,   320,   246,
    1030,  -348,  -348,  -348,   299,    51,    51,  -348,  -348,   272,
    -348,    43,  -348,   209,  -348,   910,  -348,   299,    -6,   974,
     318,  -348,     6,  -348,  -348,    56,   209,  -348,  -348,   111,
    -348,    51,   268,   362,    82,  -348,  -348,  -348,   974,    -6,
     270,   910,  -348,   910,    51,  -348,     8,  -348,  -348,    42,
     974,    56,    51,   363,  -348,  1134,   324,   367,    55,  -348,
       8,  -348,  -348,   910,  -348,  -348,   974,   718,  -348,  -348,
      56,   327,  1082,   370,   152,  -348,    -6,  -348,   111,  -348,
      31,    32,   307,  -348,  -348,    56,    55,     8,  -348,   209,
    -348,   209,  -348,  -348,    51,  -348,  -348,  -348,  -348,  -348
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    13,     0,     0,   114,     0,    34,    85,
      80,    81,    83,    84,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,   217,   218,     0,
      22,     0,     0,     0,     0,     0,     0,   112,   113,     3,
       4,     6,    38,    64,     0,     5,     0,     0,     0,    67,
       0,     0,     0,   136,   137,   138,   139,   140,   141,   142,
     143,     0,     0,   181,   187,     0,     0,     0,     0,    85,
      12,     0,    11,     7,     8,     9,    10,     0,    82,    34,
      36,   110,   111,   108,   107,   109,    75,    85,   222,    85,
     190,    38,    39,    40,   172,    85,    85,     0,     0,     0,
       0,     0,     0,   158,     0,     0,   177,   183,   184,   207,
     160,   152,     0,     0,     0,    24,    27,    26,   164,    15,
       0,     0,     0,   126,    23,    21,    20,     0,   168,   156,
     144,     0,   148,   180,     0,     0,     0,     0,     0,     0,
       0,     0,   176,     0,    34,   188,     0,    76,     0,    85,
       0,    85,     0,     0,    55,     0,     0,     0,     0,    74,
       0,    56,    57,    58,     0,     0,     0,     0,     0,     0,
       0,     0,    61,    59,   185,    60,     0,    62,    65,    66,
     216,    63,    85,   210,   224,   213,     0,     0,   101,   100,
     102,   103,   106,   104,    88,    85,    89,    86,    90,    85,
       0,    85,   105,    87,    93,    94,   200,    85,    85,     0,
       0,   212,   214,    85,   174,   162,   154,   166,   170,   146,
       0,   186,     0,   219,     0,     0,     0,     0,     0,     0,
       0,   128,    18,   147,    85,   173,   161,   153,   165,   169,
     157,   145,     0,    35,     0,   226,    37,     0,   209,   123,
     120,   117,   116,    85,     0,    85,    74,     0,     0,   182,
      85,    85,     0,    77,    85,     0,    85,   151,   155,   159,
     163,   167,   171,   175,   178,   189,   208,   211,     0,     0,
      96,    97,   192,    98,     0,    95,     0,     0,    44,    41,
      85,    85,   215,   150,     0,     0,   236,   232,    31,     0,
       0,   233,   231,   131,   129,     0,     0,     0,   179,   149,
       0,     0,     0,   194,   124,   121,     0,     0,   115,   122,
      78,    79,    45,    85,    45,     0,   223,   200,    91,    85,
      92,     0,   198,     0,    42,    43,   230,   220,     0,     0,
      32,   229,     0,     0,   133,     0,    31,    34,     0,     0,
       0,    48,    47,   228,   227,   119,   118,    85,   200,   128,
      85,     0,    85,     0,    70,    45,    72,   225,     0,    99,
       0,   199,     0,   191,   221,    85,     0,   235,   234,    45,
     132,   130,     0,     0,     0,    19,    50,    49,   196,     0,
       0,    45,    85,    45,    46,    69,     0,    85,    85,     0,
      28,    85,    33,     0,   127,     0,     0,     0,     0,   200,
       0,   133,    71,    45,    73,   193,   201,   202,    25,    30,
      29,     0,     0,     0,     0,    51,     0,   195,    45,    68,
       0,     0,     0,    17,    54,     0,     0,     0,   125,     0,
     205,     0,   203,   135,   134,    53,    52,   197,   206,   204
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,   -13,
      45,    -1,     1,     2,   422,  -319,   -16,  -339,     0,  -348,
     -41,   -37,   251,   192,  -348,    24,   -38,  -348,  -348,  -348,
    -348,    35,   -15,  -348,  -348,  -348,  -348,  -348,  -348,  -348,
    -348,  -348,  -348,  -348,   253,   385,  -348,  -348,  -348,  -348,
    -348,  -347,  -318,  -208,  -348,   201,  -348,  -348,   258,   -85,
    -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348,  -348
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    39,    40,   306,   307,   127,    41,   226,   399,
     339,    91,    92,    93,    94,   364,   350,   351,   352,    46,
      47,    48,   248,   284,   204,   205,    49,    50,    51,   359,
     231,   305,   379,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   206,   327,   358,
     409,   333,   287,   373,    66,   249,    67,    68,    69,   224,
      70,   184,   279,    71,    72,    73,    74,    75,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    45,    43,    44,    80,   366,    86,   160,   154,   368,
     157,   386,   161,   162,   163,    97,   143,   107,   109,   143,
       5,   396,   156,   172,   173,    79,   156,   175,   177,   178,
     179,    87,    89,   181,   133,   156,   229,    77,   143,    95,
     389,   147,   410,     5,     5,   119,   395,   159,    79,    79,
     156,   143,   331,   143,   332,   164,     6,   124,     6,   245,
     404,   143,   234,   174,   143,   398,     5,   145,   311,     6,
       6,    79,   412,   418,   414,   165,   371,   266,    78,   437,
     146,   323,     5,   386,   125,   158,   228,    79,   244,   203,
     362,   426,    81,    82,   429,   407,   126,   329,    83,   439,
     441,   182,   176,   330,    37,   392,    37,   221,   213,   438,
      38,   257,    38,   295,     5,   258,   265,    37,    37,    79,
      84,    85,     5,    38,    38,   155,   223,    79,   223,   120,
     143,     5,   264,   121,   158,   223,    79,   253,    10,    11,
      12,    13,   -39,   342,   275,   246,    18,   247,   148,   251,
     312,   256,   166,   363,   143,   263,   159,    86,   147,   122,
     353,   337,    96,   250,    27,    28,   254,   435,     5,   403,
     167,   158,   123,    79,   -39,   276,   338,   -39,   255,   203,
     149,   223,   203,   150,   203,     5,   296,   297,   415,   115,
      79,   301,   302,   -39,   -39,   -39,   328,   329,   223,   151,
     152,   153,   427,   222,   112,   223,   168,   116,   113,     5,
     203,   203,   158,   169,    79,   343,   207,   317,   360,   117,
     316,     5,   440,   442,   131,   354,    79,     5,   170,   447,
     304,   448,    79,   449,   114,   208,   209,   210,    98,   171,
     367,   220,    81,    82,    99,     5,   143,   203,    83,   100,
      79,   203,   101,     5,   143,   147,   223,   159,    79,   383,
      90,   320,   321,   384,   102,   103,   104,   105,   145,     5,
      84,    85,   262,   227,    79,   361,   203,   344,   345,   155,
     156,   203,   203,   225,     5,   375,   376,   303,   203,    79,
     230,   203,    10,    11,    12,    13,   232,   340,     5,   408,
     242,   380,   243,    79,   377,   378,    42,   203,    43,    44,
     355,   356,   203,   261,   203,   159,    78,   203,   203,     5,
     180,   203,   443,   203,    79,   405,   376,   411,   345,   278,
     280,   298,   372,   203,   203,   281,   285,   401,   183,   436,
     185,   290,   291,   294,   381,   340,   211,   212,   299,    42,
     387,    43,    44,   300,   -16,   310,   314,   295,   304,   326,
     336,   419,   394,   401,   203,   325,   341,   346,   203,   370,
     425,    89,    81,    82,   374,   402,   123,   397,    83,   406,
     421,    88,   419,   423,   424,   434,   432,   203,   420,   422,
     203,   382,   203,   286,   390,   372,   428,   445,   446,   203,
      84,    85,   252,   108,    42,   259,    43,    44,   288,   372,
     260,     0,   203,     0,     0,   203,   203,     0,     0,     0,
       0,    42,   387,    43,    44,     0,     0,     0,     0,   372,
     372,   444,     0,   277,     0,     0,   372,     0,   372,   106,
     372,     0,   110,     0,   111,     0,   282,   118,     0,     0,
     283,     0,   283,   128,   129,   130,   132,     5,   142,   289,
       0,     0,    79,     0,   292,     0,     0,     0,   134,     0,
       0,     0,     0,     0,   135,     0,     0,   -74,   -74,   136,
       0,     0,   137,     5,   143,   308,     0,     0,   144,     0,
     -74,   -74,   -74,   -74,   138,   139,   140,   141,   145,     0,
       0,     0,     0,     0,   313,     0,   315,     0,     0,     0,
       0,   318,   319,   146,     0,   322,     0,   324,     0,     0,
     214,   215,   216,   217,   218,     0,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   334,   335,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,     0,     0,   235,   236,   237,   238,
     239,   240,   241,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
     369,     0,     0,     0,     0,     0,   267,   268,   269,   270,
     271,   272,   273,   274,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   388,     0,
       0,   391,     0,   393,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,   413,     0,     0,     0,     0,   416,   417,
       0,     0,   400,     2,     3,     0,     0,     0,     0,     4,
       0,     0,     0,     0,   309,     5,     0,     6,     7,     0,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,    21,     0,    22,    23,    24,
      25,     0,     0,     0,    26,     0,     0,     0,    27,    28,
      29,    30,    31,    32,    33,    34,     0,    35,    36,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,    38,   186,   187,   188,   189,   190,   191,   192,   193,
       5,     0,     0,   194,     0,    79,     0,     0,     0,     0,
       0,     0,   196,     0,     0,     0,     0,     0,   197,     0,
       0,     0,     0,   198,     0,     0,    81,    82,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,     0,   430,   200,   431,     0,
       0,   201,     0,   202,    84,    85,   186,   187,   188,   189,
     190,   191,   192,   193,     5,     0,     0,   194,   195,    79,
       0,     0,     0,     0,     0,     0,   196,     0,     0,     0,
       0,     0,   197,     0,     0,     0,     0,   198,     0,     0,
      81,    82,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,     0,
       0,   200,     0,     0,     0,   201,     0,   202,    84,    85,
     186,   187,   188,   189,   190,   191,   192,   193,     5,     0,
       0,   194,   357,    79,     0,     0,     0,     0,     0,     0,
     196,     0,     0,     0,     0,     0,   197,     0,     0,     0,
       0,   198,     0,     0,    81,    82,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,     0,     0,   200,     0,     0,     0,   201,
       0,   202,    84,    85,   186,   187,   188,   189,   190,   191,
     192,   193,     5,     0,     0,   194,     0,    79,     0,     0,
       0,     0,     0,     0,   196,     0,     0,     0,     0,     0,
     197,     0,     0,     0,     0,   198,     0,     0,    81,    82,
       0,     0,   363,     0,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,     0,     0,   200,
       0,     0,     0,   201,     0,   202,    84,    85,   186,   187,
     188,   189,   190,   191,   192,   193,     5,     0,     0,   194,
       0,    79,     0,     0,     0,     0,     0,     0,   196,     0,
       0,     0,     0,     0,   197,     0,     0,     0,     0,   198,
       0,     0,    81,    82,     0,     0,     0,     0,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     199,     0,     0,   200,     0,     0,     4,   201,     0,   202,
      84,    85,     5,     0,     6,     7,     0,   347,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,   385,     0,     0,    22,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,    27,    28,   348,   349,    31,
      32,    33,    34,     0,    35,    36,     0,     0,     4,     0,
       0,     0,    37,     0,     5,     0,     6,     7,    38,   347,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,   433,     0,     0,    22,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,    27,    28,   348,
     349,    31,    32,    33,    34,     0,    35,    36,     0,     0,
       4,     0,     0,     0,    37,     0,     5,     0,     6,     7,
      38,   347,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,     0,    22,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,    27,
      28,   348,   349,    31,    32,    33,    34,     0,    35,    36,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,    38
};

static const yytype_int16 yycheck[] =
{
       1,     1,     1,     1,     5,   324,     7,    48,    46,   327,
      47,   350,    50,    51,    52,    16,    13,    18,    19,    13,
      12,   368,     7,    61,    62,    17,     7,    65,    66,    67,
      68,     7,     8,    71,    35,     7,   121,    15,    13,    15,
     358,    42,   389,    12,    12,    53,   365,    48,    17,    17,
       7,    13,    58,    13,    60,    58,    14,     8,    14,   144,
     379,    13,    59,    64,    13,    59,    12,    27,    43,    14,
      14,    17,   391,    31,   393,    58,    68,    62,    56,   426,
      42,    62,    12,   422,    35,    15,    13,    17,    13,    90,
      62,   409,    38,    39,   413,    13,    47,    58,    44,    68,
      68,    77,    58,    64,    62,    62,    62,   108,    60,   428,
      68,   152,    68,    58,    12,   152,   157,    62,    62,    17,
      66,    67,    12,    68,    68,     6,    53,    17,    53,    13,
      13,    12,    62,    17,    15,    53,    17,    18,    19,    20,
      21,    22,     8,    15,    27,   146,    27,   148,     8,   150,
       9,   152,    58,    42,    13,   156,   157,   158,   159,    43,
      15,    53,    60,    53,    45,    46,    47,    15,    12,    58,
      58,    15,    56,    17,    40,   176,    68,    43,    59,   180,
      40,    53,   183,    43,   185,    12,   224,   225,   396,    17,
      17,   229,   230,    59,    60,    61,    57,    58,    53,    59,
      60,    61,   410,    17,    13,    53,    58,    35,    17,    12,
     211,   212,    15,    58,    17,   300,    40,   258,    62,    47,
     257,    12,   430,   431,    51,   310,    17,    12,    58,   437,
     231,   439,    17,   441,    43,    59,    60,    61,    23,    58,
     325,    51,    38,    39,    29,    12,    13,   248,    44,    34,
      17,   252,    37,    12,    13,   256,    53,   258,    17,    13,
       9,   262,   263,    17,    49,    50,    51,    52,    27,    12,
      66,    67,    15,    17,    17,   316,   277,    57,    58,     6,
       7,   282,   283,    53,    12,    57,    58,    15,   289,    17,
      53,   292,    19,    20,    21,    22,    17,   298,    12,   384,
      51,    15,    17,    17,   342,   343,   307,   308,   307,   307,
     311,   312,   313,    59,   315,   316,    56,   318,   319,    12,
      69,   322,    15,   324,    17,    57,    58,    57,    58,    17,
       4,    56,   333,   334,   335,     5,    59,   375,    87,   424,
      89,    59,    59,    59,   345,   346,    95,    96,    59,   350,
     350,   350,   350,    17,    56,    17,    56,    58,   359,    31,
      15,   399,   363,   401,   365,    60,    15,    56,   369,    17,
     408,   347,    38,    39,    53,   376,    56,    59,    44,    17,
      17,    47,   420,    59,    17,    15,    59,   388,   401,   405,
     391,   346,   393,   201,   359,   396,   411,   435,   436,   400,
      66,    67,   151,    18,   405,   152,   405,   405,   207,   410,
     152,    -1,   413,    -1,    -1,   416,   417,    -1,    -1,    -1,
      -1,   422,   422,   422,   422,    -1,    -1,    -1,    -1,   430,
     431,   432,    -1,   182,    -1,    -1,   437,    -1,   439,    17,
     441,    -1,    20,    -1,    22,    -1,   195,    25,    -1,    -1,
     199,    -1,   201,    31,    32,    33,    34,    12,    36,   208,
      -1,    -1,    17,    -1,   213,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,     6,     7,    34,
      -1,    -1,    37,    12,    13,   234,    -1,    -1,    17,    -1,
      19,    20,    21,    22,    49,    50,    51,    52,    27,    -1,
      -1,    -1,    -1,    -1,   253,    -1,   255,    -1,    -1,    -1,
      -1,   260,   261,    42,    -1,   264,    -1,   266,    -1,    -1,
      98,    99,   100,   101,   102,    -1,   104,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   290,   291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   323,    -1,    -1,    -1,    -1,    -1,
     329,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,
      -1,   360,    -1,   362,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   375,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,   392,    -1,    -1,    -1,    -1,   397,   398,
      -1,    -1,   401,     0,     1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,   242,    12,    -1,    14,    15,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    -1,    34,    35,    36,
      37,    -1,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    15,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    58,    59,    60,    -1,
      -1,    63,    -1,    65,    66,    67,     4,     5,     6,     7,
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
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    -1,     6,    -1,
      -1,    -1,    62,    -1,    12,    -1,    14,    15,    68,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    -1,    -1,    34,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    -1,
       6,    -1,    -1,    -1,    62,    -1,    12,    -1,    14,    15,
      68,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
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
      80,    15,    15,   128,    57,    58,    56,    17,    47,    48,
      85,    86,    87,    15,   128,    80,    80,    16,   118,    98,
      62,    89,    62,    42,    84,    91,    84,   128,   121,    91,
      17,    68,    80,   122,    53,    57,    58,    95,    95,   101,
      15,    80,    79,    13,    17,    31,    86,    87,    91,   121,
     100,    91,    62,    91,    80,    84,   120,    59,    59,    78,
      91,    95,    80,    58,    84,    57,    17,    13,   128,   119,
     120,    57,    84,    91,    84,   122,    91,    91,    31,    95,
      78,    17,    85,    59,    17,    95,   121,   122,   101,    84,
      58,    60,    59,    31,    15,    15,   128,   120,    84,    68,
     122,    68,   122,    15,    80,    95,    95,   122,   122,   122
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    73,    72,    74,    72,
      72,    72,    75,    75,    77,    76,    76,    76,    78,    78,
      78,    79,    79,    79,    80,    80,    80,    81,    82,    82,
      83,    83,    83,    83,    83,    84,    84,    85,    85,    85,
      85,    86,    86,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    88,    88,
      88,    88,    88,    88,    89,    89,    89,    89,    89,    89,
      90,    90,    90,    90,    90,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      93,    93,    93,    93,    93,    93,    93,    94,    94,    94,
      94,    94,    95,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    98,    97,    99,    97,   100,   100,
     100,   100,   100,   101,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   103,   104,   104,   104,   104,   105,   105,   105,   105,
     106,   106,   106,   106,   107,   107,   107,   107,   108,   108,
     108,   108,   109,   109,   109,   109,   110,   110,   110,   111,
     111,   112,   112,   113,   113,   113,   113,   113,   114,   114,
     116,   115,   117,   115,   118,   115,   119,   115,   120,   120,
     121,   121,   122,   122,   122,   122,   122,   123,   123,   124,
     125,   125,   125,   125,   125,   125,   126,   127,   127,   128,
     128,   128,   130,   129,   131,   131,   132,   132,   132,   133,
     133,   134,   135,   136,   136,   136,   137
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     0,     9,     0,     6,
       2,     2,     0,     1,     0,     8,     2,     2,     1,     2,
       2,     0,     1,     3,     1,     3,     2,     3,     1,     1,
       1,     3,     4,     4,     3,     0,     2,     1,     1,     2,
       2,     4,     6,     6,     5,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     1,     8,     6,
       5,     7,     5,     7,     1,     2,     2,     3,     4,     4,
       1,     1,     2,     1,     1,     0,     2,     2,     2,     2,
       2,     4,     4,     2,     2,     3,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     5,     5,
       3,     4,     4,     3,     0,     9,     0,     7,     0,     1,
       3,     1,     3,     0,     5,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     3,     2,     4,
       4,     3,     2,     3,     3,     3,     2,     3,     2,     3,
       2,     3,     3,     3,     2,     3,     3,     3,     2,     3,
       3,     3,     2,     3,     3,     3,     2,     2,     3,     4,
       2,     1,     3,     2,     2,     2,     3,     1,     2,     3,
       0,     6,     0,     8,     0,     8,     0,    10,     1,     2,
       0,     5,     3,     5,     6,     5,     6,     2,     3,     1,
       3,     4,     3,     3,     3,     4,     2,     1,     1,     1,
       3,     4,     0,     5,     0,     3,     3,     5,     5,     5,
       5,     4,     4,     4,     6,     6,     4
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
#line 2092 "antimony.tab.cpp"
    break;

  case 4: /* input: input module  */
#line 162 "antimony.ypp"
                             { /*cout << endl << $2->ToString() << endl << endl;*/ }
#line 2098 "antimony.tab.cpp"
    break;

  case 5: /* input: input modulepart  */
#line 163 "antimony.ypp"
                                 {}
#line 2104 "antimony.tab.cpp"
    break;

  case 6: /* input: input function  */
#line 164 "antimony.ypp"
                               {}
#line 2110 "antimony.tab.cpp"
    break;

  case 7: /* input: input modulename  */
#line 165 "antimony.ypp"
                                 {}
#line 2116 "antimony.tab.cpp"
    break;

  case 8: /* input: input functionname  */
#line 166 "antimony.ypp"
                                   {}
#line 2122 "antimony.tab.cpp"
    break;

  case 9: /* input: input modulecvterm  */
#line 167 "antimony.ypp"
                                   {}
#line 2128 "antimony.tab.cpp"
    break;

  case 10: /* input: input functioncvterm  */
#line 168 "antimony.ypp"
                                     {}
#line 2134 "antimony.tab.cpp"
    break;

  case 11: /* input: input toplevel_sbo  */
#line 169 "antimony.ypp"
                                   {}
#line 2140 "antimony.tab.cpp"
    break;

  case 12: /* input: input annotationBlock  */
#line 170 "antimony.ypp"
                                      {}
#line 2146 "antimony.tab.cpp"
    break;

  case 13: /* input: input error  */
#line 171 "antimony.ypp"
                            {YYABORT;}
#line 2152 "antimony.tab.cpp"
    break;

  case 14: /* input: input "an error"  */
#line 172 "antimony.ypp"
                            {YYABORT;}
#line 2158 "antimony.tab.cpp"
    break;

  case 15: /* import: "'import'" "text string"  */
#line 175 "antimony.ypp"
                                  { if (g_registry.OpenFile(*((yyvsp[0].word)))==0) YYABORT;}
#line 2164 "antimony.tab.cpp"
    break;

  case 16: /* $@1: %empty  */
#line 178 "antimony.ypp"
                                         {g_registry.NewCurrentModule((yyvsp[0].word), NULL, (yyvsp[-1].maybemain));}
#line 2170 "antimony.tab.cpp"
    break;

  case 17: /* module: "'model' or 'module'" maybemain "element name" $@1 '(' variableexportlist ')' modulebody "'end'"  */
#line 179 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2180 "antimony.tab.cpp"
    break;

  case 18: /* $@2: %empty  */
#line 184 "antimony.ypp"
                                         {g_registry.NewCurrentModule((yyvsp[0].word), NULL, (yyvsp[-1].maybemain));}
#line 2186 "antimony.tab.cpp"
    break;

  case 19: /* module: "'model' or 'module'" maybemain "element name" $@2 modulebody "'end'"  */
#line 185 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2196 "antimony.tab.cpp"
    break;

  case 20: /* module: "'model' or 'module'" "name of an existing module"  */
#line 190 "antimony.ypp"
                               {g_registry.SetError("module '" + *((yyvsp[0].word)) + "' already defined."); YYABORT;}
#line 2202 "antimony.tab.cpp"
    break;

  case 21: /* module: "'model' or 'module'" "name of an existing function"  */
#line 191 "antimony.ypp"
                                {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a module because it is already a defined function."); YYABORT;}
#line 2208 "antimony.tab.cpp"
    break;

  case 22: /* maybemain: %empty  */
#line 194 "antimony.ypp"
                            {(yyval.maybemain) = false;}
#line 2214 "antimony.tab.cpp"
    break;

  case 23: /* maybemain: '*'  */
#line 195 "antimony.ypp"
                    {(yyval.maybemain) = true;}
#line 2220 "antimony.tab.cpp"
    break;

  case 24: /* $@3: %empty  */
#line 198 "antimony.ypp"
                                     {g_registry.NewUserFunction((yyvsp[0].word));}
#line 2226 "antimony.tab.cpp"
    break;

  case 25: /* function: "'function'" "element name" $@3 '(' variableexportlist ')' spacedformula "'end'"  */
#line 198 "antimony.ypp"
                                                                                                                    {if (g_registry.SetUserFunction((yyvsp[-1].formula))) YYABORT;}
#line 2232 "antimony.tab.cpp"
    break;

  case 26: /* function: "'function'" "name of an existing module"  */
#line 199 "antimony.ypp"
                                     {g_registry.SetError("Cannot use '" + *((yyvsp[0].word)) +"' as a function name because it is already the name of a module."); YYABORT;}
#line 2238 "antimony.tab.cpp"
    break;

  case 27: /* function: "'function'" "name of an existing function"  */
#line 200 "antimony.ypp"
                                      {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a new function because it is already a defined function."); YYABORT;}
#line 2244 "antimony.tab.cpp"
    break;

  case 28: /* spacedformula: formula  */
#line 203 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2250 "antimony.tab.cpp"
    break;

  case 29: /* spacedformula: lineend spacedformula  */
#line 204 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[0].formula);}
#line 2256 "antimony.tab.cpp"
    break;

  case 30: /* spacedformula: spacedformula lineend  */
#line 205 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[-1].formula);}
#line 2262 "antimony.tab.cpp"
    break;

  case 31: /* variableexportlist: %empty  */
#line 215 "antimony.ypp"
                            {}
#line 2268 "antimony.tab.cpp"
    break;

  case 32: /* variableexportlist: variable  */
#line 216 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2274 "antimony.tab.cpp"
    break;

  case 33: /* variableexportlist: variableexportlist ',' variable  */
#line 217 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2280 "antimony.tab.cpp"
    break;

  case 34: /* variable: "element name"  */
#line 220 "antimony.ypp"
                        {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[0].word)); }
#line 2286 "antimony.tab.cpp"
    break;

  case 35: /* variable: variable '.' "element name"  */
#line 221 "antimony.ypp"
                                     {(yyval.variable) = (yyvsp[-2].variable)->GetSubVariable((yyvsp[0].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[0].word)) + "' is not a subvariable of '" + (yyvsp[-2].variable)->GetNameDelimitedBy(".") + "'.");
                    YYABORT;
                  }
                }
#line 2297 "antimony.tab.cpp"
    break;

  case 36: /* variable: '$' variable  */
#line 227 "antimony.ypp"
                             {(yyval.variable) = (yyvsp[0].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;}
#line 2303 "antimony.tab.cpp"
    break;

  case 37: /* variablein: variable "'in'" variable  */
#line 230 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetCompartment((yyvsp[0].variable))) YYABORT; (yyval.variable) = (yyvsp[-2].variable);}
#line 2309 "antimony.tab.cpp"
    break;

  case 38: /* varmaybein: variable  */
#line 233 "antimony.ypp"
                         {(yyval.variable) = (yyvsp[0].variable);}
#line 2315 "antimony.tab.cpp"
    break;

  case 39: /* varmaybein: variablein  */
#line 234 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2321 "antimony.tab.cpp"
    break;

  case 40: /* varmaybeis: varmaybein  */
#line 237 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2327 "antimony.tab.cpp"
    break;

  case 41: /* varmaybeis: varmaybein '=' formula  */
#line 238 "antimony.ypp"
                                       {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2333 "antimony.tab.cpp"
    break;

  case 42: /* varmaybeis: varmaybein ':' '=' formula  */
#line 239 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT; }
#line 2339 "antimony.tab.cpp"
    break;

  case 43: /* varmaybeis: varmaybein '\'' '=' formula  */
#line 240 "antimony.ypp"
                                            {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT; }
#line 2345 "antimony.tab.cpp"
    break;

  case 44: /* varmaybeis: varmaybein "'has'" unitdef  */
#line 241 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2351 "antimony.tab.cpp"
    break;

  case 45: /* maybein: %empty  */
#line 244 "antimony.ypp"
                            {(yyval.variable) = NULL;}
#line 2357 "antimony.tab.cpp"
    break;

  case 46: /* maybein: "'in'" variable  */
#line 245 "antimony.ypp"
                                {(yyval.variable) = (yyvsp[0].variable);}
#line 2363 "antimony.tab.cpp"
    break;

  case 47: /* modulebody: modulepart  */
#line 248 "antimony.ypp"
                           {}
#line 2369 "antimony.tab.cpp"
    break;

  case 48: /* modulebody: moduleannotation  */
#line 249 "antimony.ypp"
                                 {}
#line 2375 "antimony.tab.cpp"
    break;

  case 49: /* modulebody: modulebody modulepart  */
#line 250 "antimony.ypp"
                                      {}
#line 2381 "antimony.tab.cpp"
    break;

  case 50: /* modulebody: modulebody moduleannotation  */
#line 251 "antimony.ypp"
                                           {}
#line 2387 "antimony.tab.cpp"
    break;

  case 51: /* moduleannotation: "'model' or 'module'" "element name" stringlist lineend  */
#line 255 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCVTerm(&modname,(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;
                }
#line 2396 "antimony.tab.cpp"
    break;

  case 52: /* moduleannotation: "'model' or 'module'" "element name" '.' "element name" stringlist lineend  */
#line 260 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCreatorTerm(&modname, (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].stringlist))) YYABORT;
                }
#line 2405 "antimony.tab.cpp"
    break;

  case 53: /* moduleannotation: "'model' or 'module'" "element name" '.' "element name" "number" lineend  */
#line 265 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCreatorTerm(&modname, (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].num))) YYABORT;
                }
#line 2414 "antimony.tab.cpp"
    break;

  case 54: /* moduleannotation: "'model' or 'module'" '.' "element name" '=' "number"  */
#line 270 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      module->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-2].word)) + "'. The only thing that can be set on the model this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 2428 "antimony.tab.cpp"
    break;

  case 55: /* modulepart: reaction lineend  */
#line 281 "antimony.ypp"
                                 {}
#line 2434 "antimony.tab.cpp"
    break;

  case 56: /* modulepart: assignment lineend  */
#line 282 "antimony.ypp"
                                   {}
#line 2440 "antimony.tab.cpp"
    break;

  case 57: /* modulepart: submodule lineend  */
#line 283 "antimony.ypp"
                                  {}
#line 2446 "antimony.tab.cpp"
    break;

  case 58: /* modulepart: varinitialize lineend  */
#line 284 "antimony.ypp"
                                      {}
#line 2452 "antimony.tab.cpp"
    break;

  case 59: /* modulepart: dnadef lineend  */
#line 285 "antimony.ypp"
                               {}
#line 2458 "antimony.tab.cpp"
    break;

  case 60: /* modulepart: event lineend  */
#line 286 "antimony.ypp"
                              {}
#line 2464 "antimony.tab.cpp"
    break;

  case 61: /* modulepart: unitinit lineend  */
#line 287 "antimony.ypp"
                                 {}
#line 2470 "antimony.tab.cpp"
    break;

  case 62: /* modulepart: deletion lineend  */
#line 288 "antimony.ypp"
                                 {}
#line 2476 "antimony.tab.cpp"
    break;

  case 63: /* modulepart: cvterm lineend  */
#line 289 "antimony.ypp"
                               {}
#line 2482 "antimony.tab.cpp"
    break;

  case 64: /* modulepart: variablein  */
#line 290 "antimony.ypp"
                           {}
#line 2488 "antimony.tab.cpp"
    break;

  case 65: /* modulepart: constraint lineend  */
#line 291 "antimony.ypp"
                                   {}
#line 2494 "antimony.tab.cpp"
    break;

  case 66: /* modulepart: objective lineend  */
#line 292 "antimony.ypp"
                                  {}
#line 2500 "antimony.tab.cpp"
    break;

  case 67: /* modulepart: lineend  */
#line 293 "antimony.ypp"
                        {}
#line 2506 "antimony.tab.cpp"
    break;

  case 68: /* reaction: varmaybein ':' reactantList reactionDivider reactantList ';' formula maybein  */
#line 297 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-7].variable), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-7].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2518 "antimony.tab.cpp"
    break;

  case 69: /* reaction: reactantList reactionDivider reactantList ';' formula maybein  */
#line 305 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2530 "antimony.tab.cpp"
    break;

  case 70: /* reaction: reactantList reactionDivider ';' formula maybein  */
#line 313 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2542 "antimony.tab.cpp"
    break;

  case 71: /* reaction: varmaybein ':' reactantList reactionDivider ';' formula maybein  */
#line 321 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2554 "antimony.tab.cpp"
    break;

  case 72: /* reaction: reactionDivider reactantList ';' formula maybein  */
#line 329 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2566 "antimony.tab.cpp"
    break;

  case 73: /* reaction: varmaybein ':' reactionDivider reactantList ';' formula maybein  */
#line 337 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2578 "antimony.tab.cpp"
    break;

  case 74: /* reactantList: variable  */
#line 346 "antimony.ypp"
                         {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2584 "antimony.tab.cpp"
    break;

  case 75: /* reactantList: "number" variable  */
#line 347 "antimony.ypp"
                             {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2590 "antimony.tab.cpp"
    break;

  case 76: /* reactantList: variable variable  */
#line 348 "antimony.ypp"
                                  {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2596 "antimony.tab.cpp"
    break;

  case 77: /* reactantList: reactantList '+' variable  */
#line 349 "antimony.ypp"
                                          {(yyval.reactantList) = (yyvsp[-2].reactantList); if((yyvsp[-2].reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2602 "antimony.tab.cpp"
    break;

  case 78: /* reactantList: reactantList '+' "number" variable  */
#line 350 "antimony.ypp"
                                              {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2608 "antimony.tab.cpp"
    break;

  case 79: /* reactantList: reactantList '+' variable variable  */
#line 351 "antimony.ypp"
                                                   {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2614 "antimony.tab.cpp"
    break;

  case 80: /* reactionDivider: "->"  */
#line 355 "antimony.ypp"
                           {(yyval.reactionDivider) = rdBecomes;}
#line 2620 "antimony.tab.cpp"
    break;

  case 81: /* reactionDivider: "-|"  */
#line 356 "antimony.ypp"
                           {(yyval.reactionDivider) = rdInhibits;}
#line 2626 "antimony.tab.cpp"
    break;

  case 82: /* reactionDivider: '-' '('  */
#line 357 "antimony.ypp"
                        {(yyval.reactionDivider) = rdInfluences;}
#line 2632 "antimony.tab.cpp"
    break;

  case 83: /* reactionDivider: "-o"  */
#line 358 "antimony.ypp"
                            {(yyval.reactionDivider) = rdInfluences;}
#line 2638 "antimony.tab.cpp"
    break;

  case 84: /* reactionDivider: "=>"  */
#line 359 "antimony.ypp"
                             {(yyval.reactionDivider) = rdBecomesIrreversibly;}
#line 2644 "antimony.tab.cpp"
    break;

  case 85: /* formula: %empty  */
#line 362 "antimony.ypp"
                            {(yyval.formula) = g_registry.NewBlankFormula(); }
#line 2650 "antimony.tab.cpp"
    break;

  case 86: /* formula: formula "..."  */
#line 363 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddEllipses();}
#line 2656 "antimony.tab.cpp"
    break;

  case 87: /* formula: formula variable  */
#line 364 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); if((yyvsp[-1].formula)->AddVariable((yyvsp[0].variable))) YYABORT; }
#line 2662 "antimony.tab.cpp"
    break;

  case 88: /* formula: formula "number"  */
#line 365 "antimony.ypp"
                             {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddNum((yyvsp[0].num)); }
#line 2668 "antimony.tab.cpp"
    break;

  case 89: /* formula: formula "name of a pre-defined constant"  */
#line 366 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2674 "antimony.tab.cpp"
    break;

  case 90: /* formula: formula "name of an existing function"  */
#line 367 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2680 "antimony.tab.cpp"
    break;

  case 91: /* formula: formula '(' commaformula ')'  */
#line 368 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2686 "antimony.tab.cpp"
    break;

  case 92: /* formula: formula '{' commaformula '}'  */
#line 369 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddCurlyBrackets(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2692 "antimony.tab.cpp"
    break;

  case 93: /* formula: formula mathThing  */
#line 370 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddMathThing((yyvsp[0].character)); }
#line 2698 "antimony.tab.cpp"
    break;

  case 94: /* formula: formula inequality  */
#line 371 "antimony.ypp"
                                   {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddInequality((yyvsp[0].inequality)); }
#line 2704 "antimony.tab.cpp"
    break;

  case 95: /* formula: formula '=' '='  */
#line 372 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('='); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2710 "antimony.tab.cpp"
    break;

  case 96: /* formula: formula '&' '&'  */
#line 373 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('&'); (yyvsp[-2].formula)->AddMathThing('&'); }
#line 2716 "antimony.tab.cpp"
    break;

  case 97: /* formula: formula '|' '|'  */
#line 374 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('|'); (yyvsp[-2].formula)->AddMathThing('|'); }
#line 2722 "antimony.tab.cpp"
    break;

  case 98: /* commaformula: formula  */
#line 377 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2728 "antimony.tab.cpp"
    break;

  case 99: /* commaformula: commaformula ',' formula  */
#line 378 "antimony.ypp"
                                         {(yyval.formula) = (yyvsp[-2].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[0].formula)); }
#line 2734 "antimony.tab.cpp"
    break;

  case 100: /* mathThing: '+'  */
#line 381 "antimony.ypp"
                    {(yyval.character) = '+';}
#line 2740 "antimony.tab.cpp"
    break;

  case 101: /* mathThing: '-'  */
#line 382 "antimony.ypp"
                    {(yyval.character) = '-';}
#line 2746 "antimony.tab.cpp"
    break;

  case 102: /* mathThing: '*'  */
#line 383 "antimony.ypp"
                    {(yyval.character) = '*';}
#line 2752 "antimony.tab.cpp"
    break;

  case 103: /* mathThing: '/'  */
#line 384 "antimony.ypp"
                    {(yyval.character) = '/';}
#line 2758 "antimony.tab.cpp"
    break;

  case 104: /* mathThing: '^'  */
#line 385 "antimony.ypp"
                    {(yyval.character) = '^';}
#line 2764 "antimony.tab.cpp"
    break;

  case 105: /* mathThing: '!'  */
#line 386 "antimony.ypp"
                    {(yyval.character) = '!';}
#line 2770 "antimony.tab.cpp"
    break;

  case 106: /* mathThing: '%'  */
#line 387 "antimony.ypp"
                    {(yyval.character) = '%';}
#line 2776 "antimony.tab.cpp"
    break;

  case 107: /* inequality: '<'  */
#line 390 "antimony.ypp"
                    {(yyval.inequality) = constLT;}
#line 2782 "antimony.tab.cpp"
    break;

  case 108: /* inequality: "<="  */
#line 391 "antimony.ypp"
                    {(yyval.inequality) = constLEQ;}
#line 2788 "antimony.tab.cpp"
    break;

  case 109: /* inequality: '>'  */
#line 392 "antimony.ypp"
                    {(yyval.inequality) = constGT;}
#line 2794 "antimony.tab.cpp"
    break;

  case 110: /* inequality: ">="  */
#line 393 "antimony.ypp"
                    {(yyval.inequality) = constGEQ;}
#line 2800 "antimony.tab.cpp"
    break;

  case 111: /* inequality: "!="  */
#line 394 "antimony.ypp"
                    {(yyval.inequality) = constNEQ;}
#line 2806 "antimony.tab.cpp"
    break;

  case 112: /* lineend: ';'  */
#line 397 "antimony.ypp"
                    {}
#line 2812 "antimony.tab.cpp"
    break;

  case 113: /* lineend: '\n'  */
#line 398 "antimony.ypp"
                     {}
#line 2818 "antimony.tab.cpp"
    break;

  case 114: /* lineend: "end of line"  */
#line 399 "antimony.ypp"
                    {}
#line 2824 "antimony.tab.cpp"
    break;

  case 115: /* assignment: varmaybein ':' maxormin formula  */
#line 402 "antimony.ypp"
                                                {if (g_registry.CurrentModule()->AddObjective((yyvsp[-3].variable), (yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 2830 "antimony.tab.cpp"
    break;

  case 116: /* assignment: varmaybein '=' formula  */
#line 403 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2836 "antimony.tab.cpp"
    break;

  case 117: /* assignment: varmaybein "'is'" variable  */
#line 404 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->Synchronize((yyvsp[0].variable), NULL)) YYABORT;}
#line 2842 "antimony.tab.cpp"
    break;

  case 118: /* assignment: varmaybein "'is'" variable '/' variable  */
#line 405 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[-2].variable), (yyvsp[0].variable))) YYABORT;}
#line 2848 "antimony.tab.cpp"
    break;

  case 119: /* assignment: varmaybein '*' variable "'is'" variable  */
#line 406 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[0].variable), (yyvsp[-2].variable))) YYABORT;}
#line 2854 "antimony.tab.cpp"
    break;

  case 120: /* assignment: varmaybein "'is'" "text string"  */
#line 407 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetDisplayName(*((yyvsp[0].word)))) YYABORT;}
#line 2860 "antimony.tab.cpp"
    break;

  case 121: /* assignment: varmaybein ':' '=' formula  */
#line 408 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT;}
#line 2866 "antimony.tab.cpp"
    break;

  case 122: /* assignment: varmaybein '\'' '=' formula  */
#line 409 "antimony.ypp"
                                            {if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT;}
#line 2872 "antimony.tab.cpp"
    break;

  case 123: /* assignment: varmaybein "'has'" unitdef  */
#line 410 "antimony.ypp"
                                           {if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2878 "antimony.tab.cpp"
    break;

  case 124: /* $@4: %empty  */
#line 414 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2884 "antimony.tab.cpp"
    break;

  case 125: /* submodule: varmaybein ':' "name of an existing module" '(' $@4 variableimportlist ')' submodifications maybein  */
#line 414 "antimony.ypp"
                                                                                                                             {if ((yyvsp[0].variable) != NULL) {if ((yyvsp[-8].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2890 "antimony.tab.cpp"
    break;

  case 126: /* $@5: %empty  */
#line 415 "antimony.ypp"
                            {if(g_registry.CurrentModule()->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2896 "antimony.tab.cpp"
    break;

  case 127: /* submodule: "name of an existing module" '(' $@5 variableimportlist ')' submodifications maybein  */
#line 415 "antimony.ypp"
                                                                                                                                     {if ((yyvsp[0].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2902 "antimony.tab.cpp"
    break;

  case 128: /* variableimportlist: %empty  */
#line 419 "antimony.ypp"
                            {}
#line 2908 "antimony.tab.cpp"
    break;

  case 129: /* variableimportlist: variable  */
#line 420 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2914 "antimony.tab.cpp"
    break;

  case 130: /* variableimportlist: variableimportlist ',' variable  */
#line 421 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2920 "antimony.tab.cpp"
    break;

  case 131: /* variableimportlist: "number"  */
#line 422 "antimony.ypp"
                    {if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2926 "antimony.tab.cpp"
    break;

  case 132: /* variableimportlist: variableimportlist ',' "number"  */
#line 423 "antimony.ypp"
                                           { if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2932 "antimony.tab.cpp"
    break;

  case 133: /* submodifications: %empty  */
#line 427 "antimony.ypp"
                            {}
#line 2938 "antimony.tab.cpp"
    break;

  case 134: /* submodifications: submodifications ',' "element name" '=' variable  */
#line 428 "antimony.ypp"
                                                          {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].variable));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2946 "antimony.tab.cpp"
    break;

  case 135: /* submodifications: submodifications ',' "element name" '=' "number"  */
#line 432 "antimony.ypp"
                                                     {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].num));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2954 "antimony.tab.cpp"
    break;

  case 136: /* varinitialize: specinit  */
#line 436 "antimony.ypp"
                         { }
#line 2960 "antimony.tab.cpp"
    break;

  case 137: /* varinitialize: formulainit  */
#line 437 "antimony.ypp"
                            { }
#line 2966 "antimony.tab.cpp"
    break;

  case 138: /* varinitialize: reactioninit  */
#line 438 "antimony.ypp"
                             { }
#line 2972 "antimony.tab.cpp"
    break;

  case 139: /* varinitialize: dnainit  */
#line 439 "antimony.ypp"
                        { }
#line 2978 "antimony.tab.cpp"
    break;

  case 140: /* varinitialize: geneinit  */
#line 440 "antimony.ypp"
                         { }
#line 2984 "antimony.tab.cpp"
    break;

  case 141: /* varinitialize: operatorinit  */
#line 441 "antimony.ypp"
                             { }
#line 2990 "antimony.tab.cpp"
    break;

  case 142: /* varinitialize: compartmentinit  */
#line 442 "antimony.ypp"
                                { }
#line 2996 "antimony.tab.cpp"
    break;

  case 143: /* varinitialize: varconstinit  */
#line 443 "antimony.ypp"
                             { }
#line 3002 "antimony.tab.cpp"
    break;

  case 144: /* specinit: "'species'" varmaybeis  */
#line 446 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3008 "antimony.tab.cpp"
    break;

  case 145: /* specinit: "'var'" "'species'" varmaybeis  */
#line 447 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3014 "antimony.tab.cpp"
    break;

  case 146: /* specinit: "'const'" "'species'" varmaybeis  */
#line 448 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3020 "antimony.tab.cpp"
    break;

  case 147: /* specinit: "'substanceOnly'" "'species'" varmaybeis  */
#line 449 "antimony.ypp"
                                             {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3026 "antimony.tab.cpp"
    break;

  case 148: /* specinit: "'substanceOnly'" varmaybeis  */
#line 450 "antimony.ypp"
                                     {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3032 "antimony.tab.cpp"
    break;

  case 149: /* specinit: "'var'" "'substanceOnly'" "'species'" varmaybeis  */
#line 451 "antimony.ypp"
                                                     {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3038 "antimony.tab.cpp"
    break;

  case 150: /* specinit: "'const'" "'substanceOnly'" "'species'" varmaybeis  */
#line 452 "antimony.ypp"
                                                       {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3044 "antimony.tab.cpp"
    break;

  case 151: /* specinit: specinit ',' varmaybeis  */
#line 453 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3050 "antimony.tab.cpp"
    break;

  case 152: /* formulainit: "'formula'" varmaybeis  */
#line 456 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3056 "antimony.tab.cpp"
    break;

  case 153: /* formulainit: "'var'" "'formula'" varmaybeis  */
#line 457 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3062 "antimony.tab.cpp"
    break;

  case 154: /* formulainit: "'const'" "'formula'" varmaybeis  */
#line 458 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3068 "antimony.tab.cpp"
    break;

  case 155: /* formulainit: formulainit ',' varmaybeis  */
#line 459 "antimony.ypp"
                                           {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3074 "antimony.tab.cpp"
    break;

  case 156: /* reactioninit: "'reaction'" varmaybeis  */
#line 462 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3080 "antimony.tab.cpp"
    break;

  case 157: /* reactioninit: "'var'" "'reaction'" varmaybeis  */
#line 463 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3086 "antimony.tab.cpp"
    break;

  case 158: /* reactioninit: "'const'" "'reaction'"  */
#line 464 "antimony.ypp"
                                   {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; }
#line 3092 "antimony.tab.cpp"
    break;

  case 159: /* reactioninit: reactioninit ',' varmaybeis  */
#line 465 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3098 "antimony.tab.cpp"
    break;

  case 160: /* dnainit: "'DNA'" varmaybeis  */
#line 468 "antimony.ypp"
                               {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3104 "antimony.tab.cpp"
    break;

  case 161: /* dnainit: "'var'" "'DNA'" varmaybeis  */
#line 469 "antimony.ypp"
                                       {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3110 "antimony.tab.cpp"
    break;

  case 162: /* dnainit: "'const'" "'DNA'" varmaybeis  */
#line 470 "antimony.ypp"
                                         {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3116 "antimony.tab.cpp"
    break;

  case 163: /* dnainit: dnainit ',' varmaybeis  */
#line 471 "antimony.ypp"
                                       {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3122 "antimony.tab.cpp"
    break;

  case 164: /* geneinit: "'gene'" varmaybeis  */
#line 474 "antimony.ypp"
                                {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3128 "antimony.tab.cpp"
    break;

  case 165: /* geneinit: "'var'" "'gene'" varmaybeis  */
#line 475 "antimony.ypp"
                                        {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3134 "antimony.tab.cpp"
    break;

  case 166: /* geneinit: "'const'" "'gene'" varmaybeis  */
#line 476 "antimony.ypp"
                                          {g_registry.SetError("Genes may not be set 'const'."); YYABORT; }
#line 3140 "antimony.tab.cpp"
    break;

  case 167: /* geneinit: geneinit ',' varmaybeis  */
#line 477 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3146 "antimony.tab.cpp"
    break;

  case 168: /* operatorinit: "'operator'" varmaybeis  */
#line 480 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3152 "antimony.tab.cpp"
    break;

  case 169: /* operatorinit: "'var'" "'operator'" varmaybeis  */
#line 481 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3158 "antimony.tab.cpp"
    break;

  case 170: /* operatorinit: "'const'" "'operator'" varmaybeis  */
#line 482 "antimony.ypp"
                                              {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3164 "antimony.tab.cpp"
    break;

  case 171: /* operatorinit: operatorinit ',' varmaybeis  */
#line 483 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3170 "antimony.tab.cpp"
    break;

  case 172: /* compartmentinit: "'compartment'" varmaybeis  */
#line 487 "antimony.ypp"
                                       {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3176 "antimony.tab.cpp"
    break;

  case 173: /* compartmentinit: "'var'" "'compartment'" varmaybeis  */
#line 488 "antimony.ypp"
                                               {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3182 "antimony.tab.cpp"
    break;

  case 174: /* compartmentinit: "'const'" "'compartment'" varmaybeis  */
#line 489 "antimony.ypp"
                                                 {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3188 "antimony.tab.cpp"
    break;

  case 175: /* compartmentinit: compartmentinit ',' varmaybeis  */
#line 490 "antimony.ypp"
                                               {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3194 "antimony.tab.cpp"
    break;

  case 176: /* varconstinit: "'var'" varmaybeis  */
#line 493 "antimony.ypp"
                                   {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst();}
#line 3200 "antimony.tab.cpp"
    break;

  case 177: /* varconstinit: "'const'" varmaybeis  */
#line 494 "antimony.ypp"
                                     {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst();}
#line 3206 "antimony.tab.cpp"
    break;

  case 178: /* varconstinit: varconstinit ',' varmaybeis  */
#line 495 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst();}
#line 3212 "antimony.tab.cpp"
    break;

  case 179: /* unitinit: "'unit'" variable '=' formula  */
#line 498 "antimony.ypp"
                                              {if ((yyvsp[-2].variable)->SetType(varUnitDefinition)) YYABORT;
                                               if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                                               if ((yyvsp[-2].variable)->GetUnitDef()->SetFromFormula((yyvsp[0].formula))) YYABORT;}
#line 3220 "antimony.tab.cpp"
    break;

  case 180: /* unitinit: "'unit'" variable  */
#line 501 "antimony.ypp"
                                  {if ((yyvsp[0].variable)->SetType(varUnitDefinition)) YYABORT;}
#line 3226 "antimony.tab.cpp"
    break;

  case 181: /* dnadef: dnastrand  */
#line 504 "antimony.ypp"
                          {if (g_registry.SaveWorkingStrand()) YYABORT;}
#line 3232 "antimony.tab.cpp"
    break;

  case 182: /* dnadef: varmaybein ':' dnastrand  */
#line 505 "antimony.ypp"
                                         {if (g_registry.SetStrandAs((yyvsp[-2].variable))) YYABORT;}
#line 3238 "antimony.tab.cpp"
    break;

  case 183: /* dnastrand: "--" variable  */
#line 508 "antimony.ypp"
                                {if (g_registry.SetNewUpstreamOpen((yyvsp[0].variable))) YYABORT;}
#line 3244 "antimony.tab.cpp"
    break;

  case 184: /* dnastrand: "--" dnamiddle  */
#line 509 "antimony.ypp"
                                 {g_registry.SetOpenUpstream(); }
#line 3250 "antimony.tab.cpp"
    break;

  case 185: /* dnastrand: dnamiddle variable  */
#line 510 "antimony.ypp"
                                   {if (g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3256 "antimony.tab.cpp"
    break;

  case 186: /* dnastrand: "--" dnamiddle variable  */
#line 511 "antimony.ypp"
                                          {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3262 "antimony.tab.cpp"
    break;

  case 187: /* dnastrand: dnamiddle  */
#line 512 "antimony.ypp"
                          { }
#line 3268 "antimony.tab.cpp"
    break;

  case 188: /* dnamiddle: variable "--"  */
#line 515 "antimony.ypp"
                                {if (g_registry.SetNewDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3274 "antimony.tab.cpp"
    break;

  case 189: /* dnamiddle: dnamiddle variable "--"  */
#line 516 "antimony.ypp"
                                          {if (g_registry.SetDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3280 "antimony.tab.cpp"
    break;

  case 190: /* $@6: %empty  */
#line 519 "antimony.ypp"
                           {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula))) YYABORT;}
#line 3286 "antimony.tab.cpp"
    break;

  case 191: /* event: "'at'" formula $@6 eventmodifications colonret assignmentlist  */
#line 519 "antimony.ypp"
                                                                                                                        {}
#line 3292 "antimony.tab.cpp"
    break;

  case 192: /* $@7: %empty  */
#line 520 "antimony.ypp"
                                         {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula))) YYABORT;}
#line 3298 "antimony.tab.cpp"
    break;

  case 193: /* event: "'at'" formula "'after'" formula $@7 eventmodifications colonret assignmentlist  */
#line 520 "antimony.ypp"
                                                                                                                                          {}
#line 3304 "antimony.tab.cpp"
    break;

  case 194: /* $@8: %empty  */
#line 521 "antimony.ypp"
                                          {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula), (yyvsp[-3].variable))) YYABORT;}
#line 3310 "antimony.tab.cpp"
    break;

  case 195: /* event: varmaybein ':' "'at'" formula $@8 eventmodifications colonret assignmentlist  */
#line 521 "antimony.ypp"
                                                                                                                                            {}
#line 3316 "antimony.tab.cpp"
    break;

  case 196: /* $@9: %empty  */
#line 522 "antimony.ypp"
                                                        {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula), (yyvsp[-5].variable))) YYABORT;}
#line 3322 "antimony.tab.cpp"
    break;

  case 197: /* event: varmaybein ':' "'at'" formula "'after'" formula $@9 eventmodifications colonret assignmentlist  */
#line 522 "antimony.ypp"
                                                                                                                                                             {}
#line 3328 "antimony.tab.cpp"
    break;

  case 198: /* colonret: ':'  */
#line 525 "antimony.ypp"
                    {}
#line 3334 "antimony.tab.cpp"
    break;

  case 199: /* colonret: colonret '\n'  */
#line 526 "antimony.ypp"
                              {}
#line 3340 "antimony.tab.cpp"
    break;

  case 200: /* eventmodifications: %empty  */
#line 529 "antimony.ypp"
                                 {}
#line 3346 "antimony.tab.cpp"
    break;

  case 201: /* eventmodifications: eventmodifications ',' "element name" '=' formula  */
#line 530 "antimony.ypp"
                                                           {if (CaselessStrCmp(false, *(yyvsp[-2].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[0].formula));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[0].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;}}
#line 3356 "antimony.tab.cpp"
    break;

  case 202: /* assignmentlist: variable '=' formula  */
#line 537 "antimony.ypp"
                                     {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3362 "antimony.tab.cpp"
    break;

  case 203: /* assignmentlist: variable '=' formula ':' assignmentlist  */
#line 538 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3368 "antimony.tab.cpp"
    break;

  case 204: /* assignmentlist: variable '=' formula ':' '\n' assignmentlist  */
#line 539 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3374 "antimony.tab.cpp"
    break;

  case 205: /* assignmentlist: variable '=' formula ',' assignmentlist  */
#line 540 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3380 "antimony.tab.cpp"
    break;

  case 206: /* assignmentlist: variable '=' formula ',' '\n' assignmentlist  */
#line 541 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3386 "antimony.tab.cpp"
    break;

  case 207: /* deletion: "'delete'" variable  */
#line 544 "antimony.ypp"
                                    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3392 "antimony.tab.cpp"
    break;

  case 208: /* deletion: deletion ',' variable  */
#line 545 "antimony.ypp"
                                      {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3398 "antimony.tab.cpp"
    break;

  case 209: /* unitdef: formula  */
#line 548 "antimony.ypp"
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
#line 3416 "antimony.tab.cpp"
    break;

  case 210: /* constraint: "number" inequality formula  */
#line 563 "antimony.ypp"
                                       {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3422 "antimony.tab.cpp"
    break;

  case 211: /* constraint: '-' "number" inequality formula  */
#line 564 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint(-(yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3428 "antimony.tab.cpp"
    break;

  case 212: /* constraint: "name of a pre-defined constant" inequality formula  */
#line 565 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3434 "antimony.tab.cpp"
    break;

  case 213: /* constraint: "element name" inequality formula  */
#line 566 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3440 "antimony.tab.cpp"
    break;

  case 214: /* constraint: "'constraint'" ':' formula  */
#line 567 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[0].formula))) YYABORT;}
#line 3446 "antimony.tab.cpp"
    break;

  case 215: /* constraint: "'constraint'" variable ':' formula  */
#line 568 "antimony.ypp"
                                                    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3452 "antimony.tab.cpp"
    break;

  case 216: /* objective: maxormin formula  */
#line 571 "antimony.ypp"
                                              {if (g_registry.CurrentModule()->AddObjective((yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 3458 "antimony.tab.cpp"
    break;

  case 217: /* maxormin: "'maximize'"  */
#line 574 "antimony.ypp"
                             {(yyval.maxormin) = true;}
#line 3464 "antimony.tab.cpp"
    break;

  case 218: /* maxormin: "'minimize'"  */
#line 575 "antimony.ypp"
                             {(yyval.maxormin) = false;}
#line 3470 "antimony.tab.cpp"
    break;

  case 219: /* stringlist: "text string"  */
#line 578 "antimony.ypp"
                           { (yyval.stringlist) = new std::vector<std::string>(); (yyval.stringlist)->push_back(*((yyvsp[0].word))); }
#line 3476 "antimony.tab.cpp"
    break;

  case 220: /* stringlist: stringlist ',' "text string"  */
#line 579 "antimony.ypp"
                                          { (yyval.stringlist) = (yyvsp[-2].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3482 "antimony.tab.cpp"
    break;

  case 221: /* stringlist: stringlist ',' '\n' "text string"  */
#line 580 "antimony.ypp"
                                               { (yyval.stringlist) = (yyvsp[-3].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3488 "antimony.tab.cpp"
    break;

  case 222: /* $@10: %empty  */
#line 582 "antimony.ypp"
                                    {if (g_registry.SetCurrentModuleIf((yyvsp[0].word), (yyvsp[-1].word))) YYABORT;}
#line 3494 "antimony.tab.cpp"
    break;

  case 223: /* annotationBlock: "element name" "name of an existing module" $@10 annotations "'end'"  */
#line 582 "antimony.ypp"
                                                                                                          {g_registry.RevertToPreviousModule();}
#line 3500 "antimony.tab.cpp"
    break;

  case 224: /* annotations: %empty  */
#line 585 "antimony.ypp"
                            {}
#line 3506 "antimony.tab.cpp"
    break;

  case 225: /* annotations: "element name" ':' stringlist  */
#line 586 "antimony.ypp"
                                       {string modname = g_registry.CurrentModuleName(); g_registry.ProcessGlobalCVTerm(&modname, (yyvsp[-2].word), (yyvsp[0].stringlist));}
#line 3512 "antimony.tab.cpp"
    break;

  case 226: /* cvterm: variable "element name" stringlist  */
#line 591 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->ProcessCVTerm((yyvsp[-2].variable),(yyvsp[-1].word),(yyvsp[0].stringlist))) YYABORT;}
#line 3518 "antimony.tab.cpp"
    break;

  case 227: /* cvterm: variable "element name" '.' "element name" stringlist  */
#line 592 "antimony.ypp"
                                                        {if (g_registry.ProcessCreatorTerm((yyvsp[-4].variable), (yyvsp[-3].word), (yyvsp[-1].word), (yyvsp[0].stringlist))) YYABORT;}
#line 3524 "antimony.tab.cpp"
    break;

  case 228: /* cvterm: variable "element name" '.' "element name" "number"  */
#line 593 "antimony.ypp"
                                                 {if (g_registry.ProcessCreatorTerm((yyvsp[-4].variable), (yyvsp[-3].word), (yyvsp[-1].word), (yyvsp[0].num))) YYABORT;}
#line 3530 "antimony.tab.cpp"
    break;

  case 229: /* toplevel_sbo: "name of an existing module" '.' "element name" '=' "number"  */
#line 597 "antimony.ypp"
                  { Module* module = g_registry.GetModule(*(yyvsp[-4].word));
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      module->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3544 "antimony.tab.cpp"
    break;

  case 230: /* toplevel_sbo: "name of an existing function" '.' "element name" '=' "number"  */
#line 608 "antimony.ypp"
                  { Module* function = g_registry.GetModule(*(yyvsp[-4].word));
                    if (function && (yyvsp[-2].word) &&  CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      function->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3558 "antimony.tab.cpp"
    break;

  case 231: /* modulename: "name of an existing module" "'is'" "text string" lineend  */
#line 620 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3564 "antimony.tab.cpp"
    break;

  case 232: /* functionname: "name of an existing function" "'is'" "text string" lineend  */
#line 622 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3570 "antimony.tab.cpp"
    break;

  case 233: /* modulecvterm: "name of an existing module" "element name" stringlist lineend  */
#line 625 "antimony.ypp"
                                                   {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3576 "antimony.tab.cpp"
    break;

  case 234: /* modulecvterm: "name of an existing module" "element name" '.' "element name" stringlist lineend  */
#line 626 "antimony.ypp"
                                                               {if (g_registry.ProcessGlobalCreatorTerm((yyvsp[-5].word), (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].stringlist))) YYABORT;}
#line 3582 "antimony.tab.cpp"
    break;

  case 235: /* modulecvterm: "name of an existing module" "element name" '.' "element name" "number" lineend  */
#line 627 "antimony.ypp"
                                                        {if (g_registry.ProcessGlobalCreatorTerm((yyvsp[-5].word), (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].num))) YYABORT;}
#line 3588 "antimony.tab.cpp"
    break;

  case 236: /* functioncvterm: "name of an existing function" "element name" stringlist lineend  */
#line 628 "antimony.ypp"
                                                    {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3594 "antimony.tab.cpp"
    break;


#line 3598 "antimony.tab.cpp"

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

#line 630 "antimony.ypp"



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
