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
  YYSYMBOL_algrule = 97,                   /* algrule  */
  YYSYMBOL_submodule = 98,                 /* submodule  */
  YYSYMBOL_99_4 = 99,                      /* $@4  */
  YYSYMBOL_100_5 = 100,                    /* $@5  */
  YYSYMBOL_variableimportlist = 101,       /* variableimportlist  */
  YYSYMBOL_submodifications = 102,         /* submodifications  */
  YYSYMBOL_varinitialize = 103,            /* varinitialize  */
  YYSYMBOL_specinit = 104,                 /* specinit  */
  YYSYMBOL_formulainit = 105,              /* formulainit  */
  YYSYMBOL_reactioninit = 106,             /* reactioninit  */
  YYSYMBOL_dnainit = 107,                  /* dnainit  */
  YYSYMBOL_geneinit = 108,                 /* geneinit  */
  YYSYMBOL_operatorinit = 109,             /* operatorinit  */
  YYSYMBOL_compartmentinit = 110,          /* compartmentinit  */
  YYSYMBOL_varconstinit = 111,             /* varconstinit  */
  YYSYMBOL_unitinit = 112,                 /* unitinit  */
  YYSYMBOL_dnadef = 113,                   /* dnadef  */
  YYSYMBOL_dnastrand = 114,                /* dnastrand  */
  YYSYMBOL_dnamiddle = 115,                /* dnamiddle  */
  YYSYMBOL_event = 116,                    /* event  */
  YYSYMBOL_117_6 = 117,                    /* $@6  */
  YYSYMBOL_118_7 = 118,                    /* $@7  */
  YYSYMBOL_119_8 = 119,                    /* $@8  */
  YYSYMBOL_120_9 = 120,                    /* $@9  */
  YYSYMBOL_colonret = 121,                 /* colonret  */
  YYSYMBOL_eventmodifications = 122,       /* eventmodifications  */
  YYSYMBOL_assignmentlist = 123,           /* assignmentlist  */
  YYSYMBOL_deletion = 124,                 /* deletion  */
  YYSYMBOL_unitdef = 125,                  /* unitdef  */
  YYSYMBOL_constraint = 126,               /* constraint  */
  YYSYMBOL_objective = 127,                /* objective  */
  YYSYMBOL_maxormin = 128,                 /* maxormin  */
  YYSYMBOL_stringlist = 129,               /* stringlist  */
  YYSYMBOL_annotationBlock = 130,          /* annotationBlock  */
  YYSYMBOL_131_10 = 131,                   /* $@10  */
  YYSYMBOL_annotations = 132,              /* annotations  */
  YYSYMBOL_cvterm = 133,                   /* cvterm  */
  YYSYMBOL_toplevel_sbo = 134,             /* toplevel_sbo  */
  YYSYMBOL_modulename = 135,               /* modulename  */
  YYSYMBOL_functionname = 136,             /* functionname  */
  YYSYMBOL_modulecvterm = 137,             /* modulecvterm  */
  YYSYMBOL_functioncvterm = 138            /* functioncvterm  */
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
#define YYLAST   1141

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  239
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  457

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
     286,   287,   288,   289,   290,   291,   292,   293,   294,   297,
     305,   313,   321,   329,   337,   347,   348,   349,   350,   351,
     352,   356,   357,   358,   359,   360,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   378,
     379,   382,   383,   384,   385,   386,   387,   388,   391,   392,
     393,   394,   395,   398,   399,   400,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   415,   416,   419,   419,   420,
     420,   424,   425,   426,   427,   428,   432,   433,   437,   441,
     442,   443,   444,   445,   446,   447,   448,   451,   452,   453,
     454,   455,   456,   457,   458,   461,   462,   463,   464,   467,
     468,   469,   470,   473,   474,   475,   476,   479,   480,   481,
     482,   485,   486,   487,   488,   492,   493,   494,   495,   498,
     499,   500,   503,   506,   509,   510,   513,   514,   515,   516,
     517,   520,   521,   524,   524,   525,   525,   526,   526,   527,
     527,   530,   531,   534,   535,   542,   543,   544,   545,   546,
     549,   550,   553,   568,   569,   570,   571,   572,   573,   576,
     579,   580,   583,   584,   585,   587,   587,   590,   591,   596,
     597,   598,   601,   612,   624,   626,   630,   631,   632,   633
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
  "mathThing", "inequality", "lineend", "assignment", "algrule",
  "submodule", "$@4", "$@5", "variableimportlist", "submodifications",
  "varinitialize", "specinit", "formulainit", "reactioninit", "dnainit",
  "geneinit", "operatorinit", "compartmentinit", "varconstinit",
  "unitinit", "dnadef", "dnastrand", "dnamiddle", "event", "$@6", "$@7",
  "$@8", "$@9", "colonret", "eventmodifications", "assignmentlist",
  "deletion", "unitdef", "constraint", "objective", "maxormin",
  "stringlist", "annotationBlock", "$@10", "annotations", "cvterm",
  "toplevel_sbo", "modulename", "functionname", "modulecvterm",
  "functioncvterm", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-364)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -364,   656,  -364,  -364,    12,   162,  -364,    23,   351,  -364,
    -364,  -364,  -364,  -364,   162,   209,    38,   437,   162,   162,
     162,  -364,   162,   218,   115,   162,   -17,  -364,  -364,   215,
     222,   162,   162,   162,   188,   162,   511,  -364,  -364,  -364,
    -364,  -364,   366,    64,   181,  -364,    35,   456,   268,  -364,
      35,    35,    35,    35,   -14,    -2,     5,    62,   138,   144,
     149,   175,    35,    35,  -364,   162,    35,    25,    35,    35,
    -364,  -364,    35,  -364,  -364,  -364,  -364,  -364,   209,  -364,
    -364,    44,  -364,  -364,  -364,  -364,  -364,  -364,    44,  -364,
    -364,  -364,   160,    16,  -364,   238,  -364,  -364,  -364,    13,
     162,   162,   162,   162,   162,  -364,   162,   122,  -364,   127,
     162,    44,  -364,  -364,   229,   199,   220,  -364,  -364,  -364,
    -364,  -364,   265,    32,   231,  -364,  -364,  -364,  -364,   271,
    -364,  -364,  -364,   162,  -364,    29,   162,   162,   162,   162,
     162,   162,   162,   284,  -364,   290,    99,  -364,   162,    44,
     162,  -364,    57,  -364,   191,   260,  -364,   266,   277,   118,
     162,   278,     9,  -364,  -364,  -364,  -364,   162,   162,   162,
     162,   162,   162,   162,   162,  -364,  -364,   241,  -364,   162,
    -364,  -364,  -364,   913,  -364,  -364,   913,   913,   320,   913,
     340,   341,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,
    -364,  -364,  -364,  -364,   289,  -364,  -364,    44,  -364,  -364,
    -364,  -364,  -364,   293,   307,   913,   913,  -364,  -364,  -364,
    -364,  -364,  -364,  -364,   162,   241,   308,  -364,    37,    35,
     312,   311,   332,    37,    35,   291,   318,  -364,  -364,  -364,
    -364,  -364,  -364,  -364,  -364,  -364,   162,  -364,   359,   322,
      44,   150,   913,  -364,  -364,   128,   913,    42,  -364,   321,
    -364,   232,   456,   268,  -364,  -364,  -364,   162,   278,  -364,
      15,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,
    -364,    44,   913,   324,   350,  -364,  -364,   913,   913,   243,
    -364,    55,   134,  -364,   913,  -364,  -364,   913,  -364,   376,
     -15,  -364,  -364,   162,   377,    93,  -364,  -364,  -364,    44,
     275,   344,  1073,   913,  -364,   102,   162,   162,  -364,   785,
    -364,   913,   119,    24,   913,   913,    44,    44,   849,  -364,
     849,   199,  -364,  -364,  -364,  -364,  -364,   379,  -364,     7,
     913,   913,  -364,  -364,   348,   285,    44,  -364,    35,    37,
    -364,   313,   162,   209,   347,   170,   969,  -364,  -364,  -364,
     322,    44,    44,   913,  -364,  -364,   291,  -364,    30,  -364,
     162,  -364,   849,  -364,   322,   134,   913,   345,  -364,    47,
    -364,  -364,    35,   162,  -364,  -364,   -12,  -364,    44,   303,
     388,   108,  -364,  -364,  -364,   913,   134,   306,   849,  -364,
     849,    44,  -364,     7,  -364,  -364,    34,   913,    35,    44,
     390,  -364,  1073,   353,   393,    37,  -364,     7,  -364,  -364,
     849,  -364,  -364,   913,   721,  -364,  -364,    35,   356,  1021,
     405,   103,  -364,   134,  -364,   -12,  -364,     8,    11,   319,
    -364,  -364,    35,    37,     7,  -364,   162,  -364,   162,  -364,
    -364,    44,  -364,  -364,  -364,  -364,  -364
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    13,     0,     0,   115,     0,    34,    86,
      81,    82,    84,    85,     0,     0,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,   220,   221,     0,
      22,     0,     0,     0,     0,     0,     0,   113,   114,     3,
       4,     6,    38,    64,     0,     5,     0,     0,     0,    68,
       0,     0,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   184,   190,     0,     0,     0,     0,
      86,    12,     0,    11,     7,     8,     9,    10,     0,    83,
      34,    36,   111,   112,   109,    86,   108,   110,    76,    86,
     225,    86,   193,    38,    39,    40,   175,    86,    86,     0,
       0,     0,     0,     0,     0,   161,     0,     0,   180,   186,
     187,   210,   163,   155,     0,     0,     0,    24,    27,    26,
     167,    15,     0,     0,     0,   129,    23,    21,    20,     0,
     171,   159,   147,     0,   151,   183,     0,     0,     0,     0,
       0,     0,     0,     0,   179,     0,    34,   191,     0,    77,
       0,    86,     0,    86,     0,     0,    55,     0,     0,     0,
       0,    75,     0,    56,    67,    57,    58,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    59,   188,    60,     0,
      62,    65,    66,   219,    63,    86,   125,   213,   227,   216,
       0,     0,   102,   101,   103,   104,   107,   105,    89,    86,
      90,    87,    91,    86,     0,    86,   106,    88,    94,    95,
     203,    86,    86,     0,     0,   215,   217,    86,   177,   165,
     157,   169,   173,   149,     0,   189,     0,   222,     0,     0,
       0,     0,     0,     0,     0,   131,    18,   150,    86,   176,
     164,   156,   168,   172,   160,   148,     0,    35,     0,   229,
      37,     0,   212,   124,   121,   118,   117,     0,    86,     0,
      86,    75,     0,     0,   185,    86,    86,     0,    78,    86,
       0,    86,   154,   158,   162,   166,   170,   174,   178,   181,
     192,   211,   214,     0,     0,    97,    98,   195,    99,     0,
      96,     0,     0,    44,    41,    86,    86,   218,   153,     0,
       0,   239,   235,    31,     0,     0,   236,   234,   134,   132,
       0,     0,     0,   182,   152,     0,     0,     0,    86,   197,
     127,   122,     0,     0,   116,   123,    79,    80,    45,    86,
      45,     0,   226,   203,    92,    86,    93,     0,   201,     0,
      42,    43,   233,   223,     0,     0,    32,   232,     0,     0,
     136,     0,    31,    34,     0,     0,     0,    48,    47,   231,
     230,   120,   119,   126,    86,   203,   131,    86,     0,    86,
       0,    71,    45,    73,   228,     0,   100,     0,   202,     0,
     194,   224,    86,     0,   238,   237,    45,   135,   133,     0,
       0,     0,    19,    50,    49,   199,     0,     0,    45,    86,
      45,    46,    70,     0,    86,    86,     0,    28,    86,    33,
       0,   130,     0,     0,     0,     0,   203,     0,   136,    72,
      45,    74,   196,   204,   205,    25,    30,    29,     0,     0,
       0,     0,    51,     0,   198,    45,    69,     0,     0,     0,
      17,    54,     0,     0,     0,   128,     0,   208,     0,   206,
     138,   137,    53,    52,   200,   209,   207
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,    18,
      69,    -1,     1,     2,   475,  -320,    20,  -348,     0,  -364,
     -43,   -40,   256,   228,  -364,     6,    76,  -364,  -364,  -364,
    -364,  -364,    61,    17,  -364,  -364,  -364,  -364,  -364,  -364,
    -364,  -364,  -364,  -364,  -364,   280,   421,  -364,  -364,  -364,
    -364,  -364,  -363,  -322,  -174,  -364,   233,  -364,  -364,   286,
    -114,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    39,    40,   311,   312,   129,    41,   230,   406,
     345,    93,    94,    95,    96,   371,   356,   357,   358,    46,
      47,    48,   252,   289,   208,   209,    49,    50,    51,    52,
     366,   235,   310,   386,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,   210,   333,
     365,   416,   339,   292,   380,    67,   253,    68,    69,    70,
     228,    71,   188,   284,    72,    73,    74,    75,    76,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    45,    43,    44,    81,   162,    88,   159,   393,   233,
     373,   375,   403,    89,    91,    99,   158,   109,   111,     5,
       5,    97,   158,     5,    80,    80,   145,    78,    80,   145,
     370,   158,   249,   417,   135,     5,   121,   158,   343,     6,
      80,   149,   145,   396,   167,   232,   410,   161,     6,     6,
       5,     6,   402,   344,     5,    80,   168,   145,   148,    80,
     145,    82,    83,   169,   177,   425,   411,    84,    79,     5,
     444,   271,   -39,   217,    80,   378,   446,   329,   419,   448,
     421,   393,    85,   179,   185,   227,   369,    37,   238,    86,
      87,   207,   399,    38,   433,   300,    37,    37,    98,    37,
     436,   318,    38,    38,   -39,    38,   405,   -39,   348,   225,
     254,   262,   248,   335,   263,   445,   270,   359,   442,   336,
     170,   414,   156,   -39,   -39,   -39,   163,   164,   165,   166,
       5,     5,   117,   160,   160,    80,    80,   317,   175,   176,
     145,   145,   178,   180,   181,   182,   227,   250,   184,   251,
     118,   255,   227,   261,   147,   227,   227,   268,   161,    88,
     149,   227,   119,   145,   190,   191,   192,   193,   194,   195,
     196,   197,     5,   224,     5,   198,   199,    80,   281,    80,
     269,   367,   207,   390,   200,   207,   207,   391,   207,   150,
     201,   349,   337,   316,   338,   202,   171,   157,    82,    83,
       5,   360,   172,     5,    84,    80,   257,   173,    80,   258,
      10,    11,    12,    13,   207,   207,   203,   374,    18,   204,
     323,   151,   322,   205,   152,   206,    86,    87,   122,   422,
     126,   114,   123,   174,   309,   115,    27,    28,   259,   133,
     153,   154,   155,   434,     5,   145,   226,    82,    83,    80,
     260,   207,   227,    84,   145,   207,    88,   127,   124,   147,
     149,   116,   161,   447,   449,    92,   326,   327,   280,   128,
     454,   125,   455,   229,   456,    86,    87,   415,   211,   368,
       5,   207,   231,   160,   234,    80,   207,   207,   236,     5,
       5,   145,   267,   207,    80,    80,   207,   212,   213,   214,
     334,   335,   346,     5,   301,   302,   308,   247,    80,   306,
     307,    42,   207,    43,    44,   361,   362,   443,   207,   266,
     207,   161,    79,   207,   207,     5,   183,   207,   387,   207,
      80,     5,   350,   351,   450,   246,    80,   283,   379,   207,
     207,   186,   382,   383,   285,   187,   286,   189,   290,   305,
     388,   346,   295,   215,   216,    42,   394,    43,    44,    91,
     412,   383,   207,   418,   351,   309,   296,   299,   303,   401,
     304,   207,   -75,   -75,   -16,   207,   315,   320,     5,   145,
     300,   332,   409,   146,   331,   -75,   -75,   -75,   -75,    82,
      83,   342,   347,   147,   207,    84,   377,   207,    90,   207,
     352,   381,   379,   125,   404,   413,   207,   428,   148,   256,
     431,    42,   430,    43,    44,   439,   379,    86,    87,   207,
     441,   389,   207,   207,   384,   385,   427,   397,    42,   394,
      43,    44,   429,   291,   264,   435,   379,   379,   451,   110,
     265,   282,     0,   379,   293,   379,     0,   379,     0,     5,
       0,     0,     0,     0,    80,   287,     0,     0,   408,   288,
     100,   288,   157,   158,     0,     0,   101,     0,   294,     0,
       0,   102,     0,   297,   103,    10,    11,    12,    13,     0,
       0,     0,   426,     0,   408,     0,   104,   105,   106,   107,
       0,   432,   108,     0,   313,   112,     0,   113,     0,     0,
     120,     0,     0,   426,     0,     0,   130,   131,   132,   134,
       0,   144,     0,     0,   319,     0,   321,     0,   452,   453,
       0,   324,   325,     5,     0,   328,     0,   330,    80,     0,
       0,     0,     0,     0,   136,     0,     0,     0,     0,     0,
     137,     0,     0,     0,     0,   138,     0,     0,   139,     0,
       0,   340,   341,     0,     0,     0,     0,     0,     0,     0,
     140,   141,   142,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   363,   218,   219,   220,   221,   222,
       0,   223,     0,     0,     0,   372,     0,     0,     0,     0,
       0,   376,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,     0,
       0,   239,   240,   241,   242,   243,   244,   245,     0,     0,
     395,     0,     0,   398,     0,   400,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   407,     0,
       0,     0,   272,   273,   274,   275,   276,   277,   278,   279,
       0,     0,     0,     0,     0,   420,     2,     3,     0,     0,
     423,   424,     4,     0,   407,     0,     0,     0,     5,     0,
       6,     7,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,    21,     0,
      22,    23,    24,    25,     0,     0,     0,    26,     0,   298,
       0,    27,    28,    29,    30,    31,    32,    33,    34,     0,
      35,    36,     0,     0,     0,     0,     0,     0,    37,     0,
       0,   314,     0,     0,    38,   190,   191,   192,   193,   194,
     195,   196,   197,     5,     0,     0,   198,     0,    80,     0,
       0,     0,     0,     0,     0,   200,     0,     0,     0,     0,
       0,   201,     0,     0,     0,     0,   202,     0,     0,    82,
      83,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   203,     0,   437,
     204,   438,     0,     0,   205,     0,   206,    86,    87,   190,
     191,   192,   193,   194,   195,   196,   197,     5,     0,     0,
     198,   364,    80,     0,     0,     0,     0,     0,     0,   200,
       0,     0,     0,     0,     0,   201,     0,     0,     0,     0,
     202,     0,     0,    82,    83,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   204,     0,     0,     0,   205,     0,
     206,    86,    87,   190,   191,   192,   193,   194,   195,   196,
     197,     5,     0,     0,   198,     0,    80,     0,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,   201,
       0,     0,     0,     0,   202,     0,     0,    82,    83,     0,
       0,   370,     0,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   203,     0,     0,   204,     0,
       0,     0,   205,     0,   206,    86,    87,   190,   191,   192,
     193,   194,   195,   196,   197,     5,     0,     0,   198,     0,
      80,     0,     0,     0,     0,     0,     0,   200,     0,     0,
       0,     0,     0,   201,     0,     0,     0,     0,   202,     0,
       0,    82,    83,     0,     0,     0,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   203,
       0,     0,   204,     0,     0,     4,   205,     0,   206,    86,
      87,     5,     0,     6,     7,     0,   353,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
     392,     0,     0,    22,     0,     0,    25,     0,     0,     0,
       0,     0,     0,     0,    27,    28,   354,   355,    31,    32,
      33,    34,     0,    35,    36,     0,     0,     4,     0,     0,
       0,    37,     0,     5,     0,     6,     7,    38,   353,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,   440,     0,     0,    22,     0,     0,    25,     0,
       0,     0,     0,     0,     0,     0,    27,    28,   354,   355,
      31,    32,    33,    34,     0,    35,    36,     0,     0,     4,
       0,     0,     0,    37,     0,     5,     0,     6,     7,    38,
     353,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,    22,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,    27,    28,
     354,   355,    31,    32,    33,    34,     0,    35,    36,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,    38
};

static const yytype_int16 yycheck[] =
{
       1,     1,     1,     1,     5,    48,     7,    47,   356,   123,
     330,   333,   375,     7,     8,    16,     7,    18,    19,    12,
      12,    15,     7,    12,    17,    17,    13,    15,    17,    13,
      42,     7,   146,   396,    35,    12,    53,     7,    53,    14,
      17,    42,    13,   365,    58,    13,    58,    48,    14,    14,
      12,    14,   372,    68,    12,    17,    58,    13,    42,    17,
      13,    38,    39,    58,    65,    31,   386,    44,    56,    12,
     433,    62,     8,    60,    17,    68,    68,    62,   398,    68,
     400,   429,    59,    58,    78,    53,    62,    62,    59,    66,
      67,    92,    62,    68,   416,    58,    62,    62,    60,    62,
     420,    59,    68,    68,    40,    68,    59,    43,    15,   110,
      53,   154,    13,    58,   154,   435,   159,    15,    15,    64,
      58,    13,    46,    59,    60,    61,    50,    51,    52,    53,
      12,    12,    17,    15,    15,    17,    17,     9,    62,    63,
      13,    13,    66,    67,    68,    69,    53,   148,    72,   150,
      35,   152,    53,   154,    27,    53,    53,   158,   159,   160,
     161,    53,    47,    13,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    51,    12,    15,    16,    17,   179,    17,
      62,    62,   183,    13,    24,   186,   187,    17,   189,     8,
      30,   305,    58,    43,    60,    35,    58,     6,    38,    39,
      12,   315,    58,    12,    44,    17,    15,    58,    17,    18,
      19,    20,    21,    22,   215,   216,    56,   331,    27,    59,
     263,    40,   262,    63,    43,    65,    66,    67,    13,   403,
       8,    13,    17,    58,   235,    17,    45,    46,    47,    51,
      59,    60,    61,   417,    12,    13,    17,    38,    39,    17,
      59,   252,    53,    44,    13,   256,   257,    35,    43,    27,
     261,    43,   263,   437,   438,     9,   267,   268,    27,    47,
     444,    56,   446,    53,   448,    66,    67,   391,    40,   322,
      12,   282,    17,    15,    53,    17,   287,   288,    17,    12,
      12,    13,    15,   294,    17,    17,   297,    59,    60,    61,
      57,    58,   303,    12,   228,   229,    15,    17,    17,   233,
     234,   312,   313,   312,   312,   316,   317,   431,   319,    59,
     321,   322,    56,   324,   325,    12,    70,   328,    15,   330,
      17,    12,    57,    58,    15,    51,    17,    17,   339,   340,
     341,    85,    57,    58,     4,    89,     5,    91,    59,    17,
     351,   352,    59,    97,    98,   356,   356,   356,   356,   353,
      57,    58,   363,    57,    58,   366,    59,    59,    56,   370,
      59,   372,     6,     7,    56,   376,    17,    56,    12,    13,
      58,    31,   383,    17,    60,    19,    20,    21,    22,    38,
      39,    15,    15,    27,   395,    44,    17,   398,    47,   400,
      56,    53,   403,    56,    59,    17,   407,    17,    42,   153,
      17,   412,    59,   412,   412,    59,   417,    66,    67,   420,
      15,   352,   423,   424,   348,   349,   408,   366,   429,   429,
     429,   429,   412,   205,   154,   418,   437,   438,   439,    18,
     154,   185,    -1,   444,   211,   446,    -1,   448,    -1,    12,
      -1,    -1,    -1,    -1,    17,   199,    -1,    -1,   382,   203,
      23,   205,     6,     7,    -1,    -1,    29,    -1,   212,    -1,
      -1,    34,    -1,   217,    37,    19,    20,    21,    22,    -1,
      -1,    -1,   406,    -1,   408,    -1,    49,    50,    51,    52,
      -1,   415,    17,    -1,   238,    20,    -1,    22,    -1,    -1,
      25,    -1,    -1,   427,    -1,    -1,    31,    32,    33,    34,
      -1,    36,    -1,    -1,   258,    -1,   260,    -1,   442,   443,
      -1,   265,   266,    12,    -1,   269,    -1,   271,    17,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    37,    -1,
      -1,   295,   296,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   318,   100,   101,   102,   103,   104,
      -1,   106,    -1,    -1,    -1,   329,    -1,    -1,    -1,    -1,
      -1,   335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,
      -1,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
     364,    -1,    -1,   367,    -1,   369,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   382,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,    -1,   399,     0,     1,    -1,    -1,
     404,   405,     6,    -1,   408,    -1,    -1,    -1,    12,    -1,
      14,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    -1,
      34,    35,    36,    37,    -1,    -1,    -1,    41,    -1,   224,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,   246,    -1,    -1,    68,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    15,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,
      59,    60,    -1,    -1,    63,    -1,    65,    66,    67,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    -1,    -1,    63,    -1,
      65,    66,    67,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    15,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    38,    39,    -1,
      -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,
      -1,    -1,    63,    -1,    65,    66,    67,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    15,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    59,    -1,    -1,     6,    63,    -1,    65,    66,
      67,    12,    -1,    14,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    -1,    -1,     6,    -1,    -1,
      -1,    62,    -1,    12,    -1,    14,    15,    68,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    -1,    -1,    34,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    -1,    -1,     6,
      -1,    -1,    -1,    62,    -1,    12,    -1,    14,    15,    68,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68
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
      96,    97,    98,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   124,   126,   127,
     128,   130,   133,   134,   135,   136,   137,   138,    15,    56,
      17,    80,    38,    39,    44,    59,    66,    67,    80,    94,
      47,    94,    91,    80,    81,    82,    83,    94,    60,    80,
      23,    29,    34,    37,    49,    50,    51,    52,    83,    80,
     115,    80,    83,    83,    13,    17,    43,    17,    35,    47,
      83,    53,    13,    17,    43,    56,     8,    35,    47,    75,
      83,    83,    83,    51,    83,    80,    23,    29,    34,    37,
      49,    50,    51,    52,    83,    13,    17,    27,    42,    80,
       8,    40,    43,    59,    60,    61,    95,     6,     7,    90,
      15,    80,    89,    95,    95,    95,    95,    58,    58,    58,
      58,    58,    58,    58,    58,    95,    95,    80,    95,    58,
      95,    95,    95,    91,    95,    94,    91,    91,   131,    91,
       4,     5,     6,     7,     8,     9,    10,    11,    15,    16,
      24,    30,    35,    56,    59,    63,    65,    80,    93,    94,
     117,    40,    59,    60,    61,    91,    91,    60,    83,    83,
      83,    83,    83,    83,    51,    80,    17,    53,   129,    53,
      77,    17,    13,   129,    53,   100,    17,    83,    59,    83,
      83,    83,    83,    83,    83,    83,    51,    17,    13,   129,
      80,    80,    91,   125,    53,    80,    91,    15,    18,    47,
      59,    80,    89,    90,   114,   128,    59,    15,    80,    62,
      89,    62,    83,    83,    83,    83,    83,    83,    83,    83,
      27,    80,    91,    17,   132,     4,     5,    91,    91,    92,
      59,    92,   122,   125,    91,    59,    59,    91,    83,    59,
      58,    95,    95,    56,    59,    17,    95,    95,    15,    80,
     101,    73,    74,    91,    83,    17,    43,     9,    59,    91,
      56,    91,    90,    89,    91,    91,    80,    80,    91,    62,
      91,    60,    31,   118,    57,    58,    64,    58,    60,   121,
      91,    91,    15,    53,    68,    79,    80,    15,    15,   129,
      57,    58,    56,    17,    47,    48,    85,    86,    87,    15,
     129,    80,    80,    91,    16,   119,    99,    62,    89,    62,
      42,    84,    91,    84,   129,   122,    91,    17,    68,    80,
     123,    53,    57,    58,    95,    95,   102,    15,    80,    79,
      13,    17,    31,    86,    87,    91,   122,   101,    91,    62,
      91,    80,    84,   121,    59,    59,    78,    91,    95,    80,
      58,    84,    57,    17,    13,   129,   120,   121,    57,    84,
      91,    84,   123,    91,    91,    31,    95,    78,    17,    85,
      59,    17,    95,   122,   123,   102,    84,    58,    60,    59,
      31,    15,    15,   129,   121,    84,    68,   123,    68,   123,
      15,    80,    95,    95,   123,   123,   123
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
      87,    87,    87,    87,    87,    87,    87,    87,    87,    88,
      88,    88,    88,    88,    88,    89,    89,    89,    89,    89,
      89,    90,    90,    90,    90,    90,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      94,    94,    94,    95,    95,    95,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    99,    98,   100,
      98,   101,   101,   101,   101,   101,   102,   102,   102,   103,
     103,   103,   103,   103,   103,   103,   103,   104,   104,   104,
     104,   104,   104,   104,   104,   105,   105,   105,   105,   106,
     106,   106,   106,   107,   107,   107,   107,   108,   108,   108,
     108,   109,   109,   109,   109,   110,   110,   110,   110,   111,
     111,   111,   112,   112,   113,   113,   114,   114,   114,   114,
     114,   115,   115,   117,   116,   118,   116,   119,   116,   120,
     116,   121,   121,   122,   122,   123,   123,   123,   123,   123,
     124,   124,   125,   126,   126,   126,   126,   126,   126,   127,
     128,   128,   129,   129,   129,   131,   130,   132,   132,   133,
     133,   133,   134,   134,   135,   136,   137,   137,   137,   138
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
       2,     2,     2,     2,     1,     2,     2,     2,     1,     8,
       6,     5,     7,     5,     7,     1,     2,     2,     3,     4,
       4,     1,     1,     2,     1,     1,     0,     2,     2,     2,
       2,     2,     4,     4,     2,     2,     3,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     3,     5,
       5,     3,     4,     4,     3,     3,     5,     0,     9,     0,
       7,     0,     1,     3,     1,     3,     0,     5,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       3,     2,     4,     4,     3,     2,     3,     3,     3,     2,
       3,     2,     3,     2,     3,     3,     3,     2,     3,     3,
       3,     2,     3,     3,     3,     2,     3,     3,     3,     2,
       2,     3,     4,     2,     1,     3,     2,     2,     2,     3,
       1,     2,     3,     0,     6,     0,     8,     0,     8,     0,
      10,     1,     2,     0,     5,     3,     5,     6,     5,     6,
       2,     3,     1,     3,     4,     3,     3,     3,     4,     2,
       1,     1,     1,     3,     4,     0,     5,     0,     3,     3,
       5,     5,     5,     5,     4,     4,     4,     6,     6,     4
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
#line 2085 "antimony.tab.cpp"
    break;

  case 4: /* input: input module  */
#line 162 "antimony.ypp"
                             { /*cout << endl << $2->ToString() << endl << endl;*/ }
#line 2091 "antimony.tab.cpp"
    break;

  case 5: /* input: input modulepart  */
#line 163 "antimony.ypp"
                                 {}
#line 2097 "antimony.tab.cpp"
    break;

  case 6: /* input: input function  */
#line 164 "antimony.ypp"
                               {}
#line 2103 "antimony.tab.cpp"
    break;

  case 7: /* input: input modulename  */
#line 165 "antimony.ypp"
                                 {}
#line 2109 "antimony.tab.cpp"
    break;

  case 8: /* input: input functionname  */
#line 166 "antimony.ypp"
                                   {}
#line 2115 "antimony.tab.cpp"
    break;

  case 9: /* input: input modulecvterm  */
#line 167 "antimony.ypp"
                                   {}
#line 2121 "antimony.tab.cpp"
    break;

  case 10: /* input: input functioncvterm  */
#line 168 "antimony.ypp"
                                     {}
#line 2127 "antimony.tab.cpp"
    break;

  case 11: /* input: input toplevel_sbo  */
#line 169 "antimony.ypp"
                                   {}
#line 2133 "antimony.tab.cpp"
    break;

  case 12: /* input: input annotationBlock  */
#line 170 "antimony.ypp"
                                      {}
#line 2139 "antimony.tab.cpp"
    break;

  case 13: /* input: input error  */
#line 171 "antimony.ypp"
                            {YYABORT;}
#line 2145 "antimony.tab.cpp"
    break;

  case 14: /* input: input "an error"  */
#line 172 "antimony.ypp"
                            {YYABORT;}
#line 2151 "antimony.tab.cpp"
    break;

  case 15: /* import: "'import'" "text string"  */
#line 175 "antimony.ypp"
                                  { if (g_registry.OpenFile(*((yyvsp[0].word)))==0) YYABORT;}
#line 2157 "antimony.tab.cpp"
    break;

  case 16: /* $@1: %empty  */
#line 178 "antimony.ypp"
                                         {g_registry.NewCurrentModule((yyvsp[0].word), NULL, (yyvsp[-1].maybemain));}
#line 2163 "antimony.tab.cpp"
    break;

  case 17: /* module: "'model' or 'module'" maybemain "element name" $@1 '(' variableexportlist ')' modulebody "'end'"  */
#line 179 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2173 "antimony.tab.cpp"
    break;

  case 18: /* $@2: %empty  */
#line 184 "antimony.ypp"
                                         {g_registry.NewCurrentModule((yyvsp[0].word), NULL, (yyvsp[-1].maybemain));}
#line 2179 "antimony.tab.cpp"
    break;

  case 19: /* module: "'model' or 'module'" maybemain "element name" $@2 modulebody "'end'"  */
#line 185 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2189 "antimony.tab.cpp"
    break;

  case 20: /* module: "'model' or 'module'" "name of an existing module"  */
#line 190 "antimony.ypp"
                               {g_registry.SetError("module '" + *((yyvsp[0].word)) + "' already defined."); YYABORT;}
#line 2195 "antimony.tab.cpp"
    break;

  case 21: /* module: "'model' or 'module'" "name of an existing function"  */
#line 191 "antimony.ypp"
                                {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a module because it is already a defined function."); YYABORT;}
#line 2201 "antimony.tab.cpp"
    break;

  case 22: /* maybemain: %empty  */
#line 194 "antimony.ypp"
                            {(yyval.maybemain) = false;}
#line 2207 "antimony.tab.cpp"
    break;

  case 23: /* maybemain: '*'  */
#line 195 "antimony.ypp"
                    {(yyval.maybemain) = true;}
#line 2213 "antimony.tab.cpp"
    break;

  case 24: /* $@3: %empty  */
#line 198 "antimony.ypp"
                                     {g_registry.NewUserFunction((yyvsp[0].word));}
#line 2219 "antimony.tab.cpp"
    break;

  case 25: /* function: "'function'" "element name" $@3 '(' variableexportlist ')' spacedformula "'end'"  */
#line 198 "antimony.ypp"
                                                                                                                    {if (g_registry.SetUserFunction((yyvsp[-1].formula))) YYABORT;}
#line 2225 "antimony.tab.cpp"
    break;

  case 26: /* function: "'function'" "name of an existing module"  */
#line 199 "antimony.ypp"
                                     {g_registry.SetError("Cannot use '" + *((yyvsp[0].word)) +"' as a function name because it is already the name of a module."); YYABORT;}
#line 2231 "antimony.tab.cpp"
    break;

  case 27: /* function: "'function'" "name of an existing function"  */
#line 200 "antimony.ypp"
                                      {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a new function because it is already a defined function."); YYABORT;}
#line 2237 "antimony.tab.cpp"
    break;

  case 28: /* spacedformula: formula  */
#line 203 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2243 "antimony.tab.cpp"
    break;

  case 29: /* spacedformula: lineend spacedformula  */
#line 204 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[0].formula);}
#line 2249 "antimony.tab.cpp"
    break;

  case 30: /* spacedformula: spacedformula lineend  */
#line 205 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[-1].formula);}
#line 2255 "antimony.tab.cpp"
    break;

  case 31: /* variableexportlist: %empty  */
#line 215 "antimony.ypp"
                            {}
#line 2261 "antimony.tab.cpp"
    break;

  case 32: /* variableexportlist: variable  */
#line 216 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2267 "antimony.tab.cpp"
    break;

  case 33: /* variableexportlist: variableexportlist ',' variable  */
#line 217 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2273 "antimony.tab.cpp"
    break;

  case 34: /* variable: "element name"  */
#line 220 "antimony.ypp"
                        {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[0].word)); }
#line 2279 "antimony.tab.cpp"
    break;

  case 35: /* variable: variable '.' "element name"  */
#line 221 "antimony.ypp"
                                     {(yyval.variable) = (yyvsp[-2].variable)->GetSubVariable((yyvsp[0].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[0].word)) + "' is not a subvariable of '" + (yyvsp[-2].variable)->GetNameDelimitedBy(".") + "'.");
                    YYABORT;
                  }
                }
#line 2290 "antimony.tab.cpp"
    break;

  case 36: /* variable: '$' variable  */
#line 227 "antimony.ypp"
                             {(yyval.variable) = (yyvsp[0].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;}
#line 2296 "antimony.tab.cpp"
    break;

  case 37: /* variablein: variable "'in'" variable  */
#line 230 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetCompartment((yyvsp[0].variable))) YYABORT; (yyval.variable) = (yyvsp[-2].variable);}
#line 2302 "antimony.tab.cpp"
    break;

  case 38: /* varmaybein: variable  */
#line 233 "antimony.ypp"
                         {(yyval.variable) = (yyvsp[0].variable);}
#line 2308 "antimony.tab.cpp"
    break;

  case 39: /* varmaybein: variablein  */
#line 234 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2314 "antimony.tab.cpp"
    break;

  case 40: /* varmaybeis: varmaybein  */
#line 237 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2320 "antimony.tab.cpp"
    break;

  case 41: /* varmaybeis: varmaybein '=' formula  */
#line 238 "antimony.ypp"
                                       {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2326 "antimony.tab.cpp"
    break;

  case 42: /* varmaybeis: varmaybein ':' '=' formula  */
#line 239 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT; }
#line 2332 "antimony.tab.cpp"
    break;

  case 43: /* varmaybeis: varmaybein '\'' '=' formula  */
#line 240 "antimony.ypp"
                                            {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT; }
#line 2338 "antimony.tab.cpp"
    break;

  case 44: /* varmaybeis: varmaybein "'has'" unitdef  */
#line 241 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2344 "antimony.tab.cpp"
    break;

  case 45: /* maybein: %empty  */
#line 244 "antimony.ypp"
                            {(yyval.variable) = NULL;}
#line 2350 "antimony.tab.cpp"
    break;

  case 46: /* maybein: "'in'" variable  */
#line 245 "antimony.ypp"
                                {(yyval.variable) = (yyvsp[0].variable);}
#line 2356 "antimony.tab.cpp"
    break;

  case 47: /* modulebody: modulepart  */
#line 248 "antimony.ypp"
                           {}
#line 2362 "antimony.tab.cpp"
    break;

  case 48: /* modulebody: moduleannotation  */
#line 249 "antimony.ypp"
                                 {}
#line 2368 "antimony.tab.cpp"
    break;

  case 49: /* modulebody: modulebody modulepart  */
#line 250 "antimony.ypp"
                                      {}
#line 2374 "antimony.tab.cpp"
    break;

  case 50: /* modulebody: modulebody moduleannotation  */
#line 251 "antimony.ypp"
                                           {}
#line 2380 "antimony.tab.cpp"
    break;

  case 51: /* moduleannotation: "'model' or 'module'" "element name" stringlist lineend  */
#line 255 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCVTerm(&modname,(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;
                }
#line 2389 "antimony.tab.cpp"
    break;

  case 52: /* moduleannotation: "'model' or 'module'" "element name" '.' "element name" stringlist lineend  */
#line 260 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCreatorTerm(&modname, (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].stringlist))) YYABORT;
                }
#line 2398 "antimony.tab.cpp"
    break;

  case 53: /* moduleannotation: "'model' or 'module'" "element name" '.' "element name" "number" lineend  */
#line 265 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCreatorTerm(&modname, (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].num))) YYABORT;
                }
#line 2407 "antimony.tab.cpp"
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
#line 2421 "antimony.tab.cpp"
    break;

  case 55: /* modulepart: reaction lineend  */
#line 281 "antimony.ypp"
                                 {}
#line 2427 "antimony.tab.cpp"
    break;

  case 56: /* modulepart: assignment lineend  */
#line 282 "antimony.ypp"
                                   {}
#line 2433 "antimony.tab.cpp"
    break;

  case 57: /* modulepart: submodule lineend  */
#line 283 "antimony.ypp"
                                  {}
#line 2439 "antimony.tab.cpp"
    break;

  case 58: /* modulepart: varinitialize lineend  */
#line 284 "antimony.ypp"
                                      {}
#line 2445 "antimony.tab.cpp"
    break;

  case 59: /* modulepart: dnadef lineend  */
#line 285 "antimony.ypp"
                               {}
#line 2451 "antimony.tab.cpp"
    break;

  case 60: /* modulepart: event lineend  */
#line 286 "antimony.ypp"
                              {}
#line 2457 "antimony.tab.cpp"
    break;

  case 61: /* modulepart: unitinit lineend  */
#line 287 "antimony.ypp"
                                 {}
#line 2463 "antimony.tab.cpp"
    break;

  case 62: /* modulepart: deletion lineend  */
#line 288 "antimony.ypp"
                                 {}
#line 2469 "antimony.tab.cpp"
    break;

  case 63: /* modulepart: cvterm lineend  */
#line 289 "antimony.ypp"
                               {}
#line 2475 "antimony.tab.cpp"
    break;

  case 64: /* modulepart: variablein  */
#line 290 "antimony.ypp"
                           {}
#line 2481 "antimony.tab.cpp"
    break;

  case 65: /* modulepart: constraint lineend  */
#line 291 "antimony.ypp"
                                   {}
#line 2487 "antimony.tab.cpp"
    break;

  case 66: /* modulepart: objective lineend  */
#line 292 "antimony.ypp"
                                  {}
#line 2493 "antimony.tab.cpp"
    break;

  case 67: /* modulepart: algrule lineend  */
#line 293 "antimony.ypp"
                                {}
#line 2499 "antimony.tab.cpp"
    break;

  case 68: /* modulepart: lineend  */
#line 294 "antimony.ypp"
                        {}
#line 2505 "antimony.tab.cpp"
    break;

  case 69: /* reaction: varmaybein ':' reactantList reactionDivider reactantList ';' formula maybein  */
#line 298 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-7].variable), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-7].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2517 "antimony.tab.cpp"
    break;

  case 70: /* reaction: reactantList reactionDivider reactantList ';' formula maybein  */
#line 306 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2529 "antimony.tab.cpp"
    break;

  case 71: /* reaction: reactantList reactionDivider ';' formula maybein  */
#line 314 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2541 "antimony.tab.cpp"
    break;

  case 72: /* reaction: varmaybein ':' reactantList reactionDivider ';' formula maybein  */
#line 322 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2553 "antimony.tab.cpp"
    break;

  case 73: /* reaction: reactionDivider reactantList ';' formula maybein  */
#line 330 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2565 "antimony.tab.cpp"
    break;

  case 74: /* reaction: varmaybein ':' reactionDivider reactantList ';' formula maybein  */
#line 338 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2577 "antimony.tab.cpp"
    break;

  case 75: /* reactantList: variable  */
#line 347 "antimony.ypp"
                         {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2583 "antimony.tab.cpp"
    break;

  case 76: /* reactantList: "number" variable  */
#line 348 "antimony.ypp"
                             {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2589 "antimony.tab.cpp"
    break;

  case 77: /* reactantList: variable variable  */
#line 349 "antimony.ypp"
                                  {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2595 "antimony.tab.cpp"
    break;

  case 78: /* reactantList: reactantList '+' variable  */
#line 350 "antimony.ypp"
                                          {(yyval.reactantList) = (yyvsp[-2].reactantList); if((yyvsp[-2].reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2601 "antimony.tab.cpp"
    break;

  case 79: /* reactantList: reactantList '+' "number" variable  */
#line 351 "antimony.ypp"
                                              {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2607 "antimony.tab.cpp"
    break;

  case 80: /* reactantList: reactantList '+' variable variable  */
#line 352 "antimony.ypp"
                                                   {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2613 "antimony.tab.cpp"
    break;

  case 81: /* reactionDivider: "->"  */
#line 356 "antimony.ypp"
                           {(yyval.reactionDivider) = rdBecomes;}
#line 2619 "antimony.tab.cpp"
    break;

  case 82: /* reactionDivider: "-|"  */
#line 357 "antimony.ypp"
                           {(yyval.reactionDivider) = rdInhibits;}
#line 2625 "antimony.tab.cpp"
    break;

  case 83: /* reactionDivider: '-' '('  */
#line 358 "antimony.ypp"
                        {(yyval.reactionDivider) = rdInfluences;}
#line 2631 "antimony.tab.cpp"
    break;

  case 84: /* reactionDivider: "-o"  */
#line 359 "antimony.ypp"
                            {(yyval.reactionDivider) = rdInfluences;}
#line 2637 "antimony.tab.cpp"
    break;

  case 85: /* reactionDivider: "=>"  */
#line 360 "antimony.ypp"
                             {(yyval.reactionDivider) = rdBecomesIrreversibly;}
#line 2643 "antimony.tab.cpp"
    break;

  case 86: /* formula: %empty  */
#line 363 "antimony.ypp"
                            {(yyval.formula) = g_registry.NewBlankFormula(); }
#line 2649 "antimony.tab.cpp"
    break;

  case 87: /* formula: formula "..."  */
#line 364 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddEllipses();}
#line 2655 "antimony.tab.cpp"
    break;

  case 88: /* formula: formula variable  */
#line 365 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); if((yyvsp[-1].formula)->AddVariable((yyvsp[0].variable))) YYABORT; }
#line 2661 "antimony.tab.cpp"
    break;

  case 89: /* formula: formula "number"  */
#line 366 "antimony.ypp"
                             {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddNum((yyvsp[0].num)); }
#line 2667 "antimony.tab.cpp"
    break;

  case 90: /* formula: formula "name of a pre-defined constant"  */
#line 367 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2673 "antimony.tab.cpp"
    break;

  case 91: /* formula: formula "name of an existing function"  */
#line 368 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2679 "antimony.tab.cpp"
    break;

  case 92: /* formula: formula '(' commaformula ')'  */
#line 369 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2685 "antimony.tab.cpp"
    break;

  case 93: /* formula: formula '{' commaformula '}'  */
#line 370 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddCurlyBrackets(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2691 "antimony.tab.cpp"
    break;

  case 94: /* formula: formula mathThing  */
#line 371 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddMathThing((yyvsp[0].character)); }
#line 2697 "antimony.tab.cpp"
    break;

  case 95: /* formula: formula inequality  */
#line 372 "antimony.ypp"
                                   {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddInequality((yyvsp[0].inequality)); }
#line 2703 "antimony.tab.cpp"
    break;

  case 96: /* formula: formula '=' '='  */
#line 373 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('='); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2709 "antimony.tab.cpp"
    break;

  case 97: /* formula: formula '&' '&'  */
#line 374 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('&'); (yyvsp[-2].formula)->AddMathThing('&'); }
#line 2715 "antimony.tab.cpp"
    break;

  case 98: /* formula: formula '|' '|'  */
#line 375 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('|'); (yyvsp[-2].formula)->AddMathThing('|'); }
#line 2721 "antimony.tab.cpp"
    break;

  case 99: /* commaformula: formula  */
#line 378 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2727 "antimony.tab.cpp"
    break;

  case 100: /* commaformula: commaformula ',' formula  */
#line 379 "antimony.ypp"
                                         {(yyval.formula) = (yyvsp[-2].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[0].formula)); }
#line 2733 "antimony.tab.cpp"
    break;

  case 101: /* mathThing: '+'  */
#line 382 "antimony.ypp"
                    {(yyval.character) = '+';}
#line 2739 "antimony.tab.cpp"
    break;

  case 102: /* mathThing: '-'  */
#line 383 "antimony.ypp"
                    {(yyval.character) = '-';}
#line 2745 "antimony.tab.cpp"
    break;

  case 103: /* mathThing: '*'  */
#line 384 "antimony.ypp"
                    {(yyval.character) = '*';}
#line 2751 "antimony.tab.cpp"
    break;

  case 104: /* mathThing: '/'  */
#line 385 "antimony.ypp"
                    {(yyval.character) = '/';}
#line 2757 "antimony.tab.cpp"
    break;

  case 105: /* mathThing: '^'  */
#line 386 "antimony.ypp"
                    {(yyval.character) = '^';}
#line 2763 "antimony.tab.cpp"
    break;

  case 106: /* mathThing: '!'  */
#line 387 "antimony.ypp"
                    {(yyval.character) = '!';}
#line 2769 "antimony.tab.cpp"
    break;

  case 107: /* mathThing: '%'  */
#line 388 "antimony.ypp"
                    {(yyval.character) = '%';}
#line 2775 "antimony.tab.cpp"
    break;

  case 108: /* inequality: '<'  */
#line 391 "antimony.ypp"
                    {(yyval.inequality) = constLT;}
#line 2781 "antimony.tab.cpp"
    break;

  case 109: /* inequality: "<="  */
#line 392 "antimony.ypp"
                    {(yyval.inequality) = constLEQ;}
#line 2787 "antimony.tab.cpp"
    break;

  case 110: /* inequality: '>'  */
#line 393 "antimony.ypp"
                    {(yyval.inequality) = constGT;}
#line 2793 "antimony.tab.cpp"
    break;

  case 111: /* inequality: ">="  */
#line 394 "antimony.ypp"
                    {(yyval.inequality) = constGEQ;}
#line 2799 "antimony.tab.cpp"
    break;

  case 112: /* inequality: "!="  */
#line 395 "antimony.ypp"
                    {(yyval.inequality) = constNEQ;}
#line 2805 "antimony.tab.cpp"
    break;

  case 113: /* lineend: ';'  */
#line 398 "antimony.ypp"
                    {}
#line 2811 "antimony.tab.cpp"
    break;

  case 114: /* lineend: '\n'  */
#line 399 "antimony.ypp"
                     {}
#line 2817 "antimony.tab.cpp"
    break;

  case 115: /* lineend: "end of line"  */
#line 400 "antimony.ypp"
                    {}
#line 2823 "antimony.tab.cpp"
    break;

  case 116: /* assignment: varmaybein ':' maxormin formula  */
#line 403 "antimony.ypp"
                                                {if (g_registry.CurrentModule()->AddObjective((yyvsp[-3].variable), (yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 2829 "antimony.tab.cpp"
    break;

  case 117: /* assignment: varmaybein '=' formula  */
#line 404 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2835 "antimony.tab.cpp"
    break;

  case 118: /* assignment: varmaybein "'is'" variable  */
#line 405 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->Synchronize((yyvsp[0].variable), NULL)) YYABORT;}
#line 2841 "antimony.tab.cpp"
    break;

  case 119: /* assignment: varmaybein "'is'" variable '/' variable  */
#line 406 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[-2].variable), (yyvsp[0].variable))) YYABORT;}
#line 2847 "antimony.tab.cpp"
    break;

  case 120: /* assignment: varmaybein '*' variable "'is'" variable  */
#line 407 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[0].variable), (yyvsp[-2].variable))) YYABORT;}
#line 2853 "antimony.tab.cpp"
    break;

  case 121: /* assignment: varmaybein "'is'" "text string"  */
#line 408 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetDisplayName(*((yyvsp[0].word)))) YYABORT;}
#line 2859 "antimony.tab.cpp"
    break;

  case 122: /* assignment: varmaybein ':' '=' formula  */
#line 409 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT;}
#line 2865 "antimony.tab.cpp"
    break;

  case 123: /* assignment: varmaybein '\'' '=' formula  */
#line 410 "antimony.ypp"
                                            {if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT;}
#line 2871 "antimony.tab.cpp"
    break;

  case 124: /* assignment: varmaybein "'has'" unitdef  */
#line 411 "antimony.ypp"
                                           {if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2877 "antimony.tab.cpp"
    break;

  case 125: /* algrule: "number" '=' formula  */
#line 415 "antimony.ypp"
                                {if (g_registry.AddNewAlgebraicRuleToCurrent((yyvsp[-2].num), (yyvsp[0].formula))) YYABORT; }
#line 2883 "antimony.tab.cpp"
    break;

  case 126: /* algrule: varmaybein ':' "number" '=' formula  */
#line 416 "antimony.ypp"
                                               {if ((yyvsp[-4].variable)->SetAlgebraicRule((yyvsp[-2].num), (yyvsp[0].formula)) ) YYABORT;}
#line 2889 "antimony.tab.cpp"
    break;

  case 127: /* $@4: %empty  */
#line 419 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2895 "antimony.tab.cpp"
    break;

  case 128: /* submodule: varmaybein ':' "name of an existing module" '(' $@4 variableimportlist ')' submodifications maybein  */
#line 419 "antimony.ypp"
                                                                                                                             {if ((yyvsp[0].variable) != NULL) {if ((yyvsp[-8].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2901 "antimony.tab.cpp"
    break;

  case 129: /* $@5: %empty  */
#line 420 "antimony.ypp"
                            {if(g_registry.CurrentModule()->SetModule((yyvsp[-1].word))) YYABORT;}
#line 2907 "antimony.tab.cpp"
    break;

  case 130: /* submodule: "name of an existing module" '(' $@5 variableimportlist ')' submodifications maybein  */
#line 420 "antimony.ypp"
                                                                                                                                     {if ((yyvsp[0].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 2913 "antimony.tab.cpp"
    break;

  case 131: /* variableimportlist: %empty  */
#line 424 "antimony.ypp"
                            {}
#line 2919 "antimony.tab.cpp"
    break;

  case 132: /* variableimportlist: variable  */
#line 425 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2925 "antimony.tab.cpp"
    break;

  case 133: /* variableimportlist: variableimportlist ',' variable  */
#line 426 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 2931 "antimony.tab.cpp"
    break;

  case 134: /* variableimportlist: "number"  */
#line 427 "antimony.ypp"
                    {if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2937 "antimony.tab.cpp"
    break;

  case 135: /* variableimportlist: variableimportlist ',' "number"  */
#line 428 "antimony.ypp"
                                           { if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 2943 "antimony.tab.cpp"
    break;

  case 136: /* submodifications: %empty  */
#line 432 "antimony.ypp"
                            {}
#line 2949 "antimony.tab.cpp"
    break;

  case 137: /* submodifications: submodifications ',' "element name" '=' variable  */
#line 433 "antimony.ypp"
                                                          {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].variable));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2957 "antimony.tab.cpp"
    break;

  case 138: /* submodifications: submodifications ',' "element name" '=' "number"  */
#line 437 "antimony.ypp"
                                                     {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].num));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 2965 "antimony.tab.cpp"
    break;

  case 139: /* varinitialize: specinit  */
#line 441 "antimony.ypp"
                         { }
#line 2971 "antimony.tab.cpp"
    break;

  case 140: /* varinitialize: formulainit  */
#line 442 "antimony.ypp"
                            { }
#line 2977 "antimony.tab.cpp"
    break;

  case 141: /* varinitialize: reactioninit  */
#line 443 "antimony.ypp"
                             { }
#line 2983 "antimony.tab.cpp"
    break;

  case 142: /* varinitialize: dnainit  */
#line 444 "antimony.ypp"
                        { }
#line 2989 "antimony.tab.cpp"
    break;

  case 143: /* varinitialize: geneinit  */
#line 445 "antimony.ypp"
                         { }
#line 2995 "antimony.tab.cpp"
    break;

  case 144: /* varinitialize: operatorinit  */
#line 446 "antimony.ypp"
                             { }
#line 3001 "antimony.tab.cpp"
    break;

  case 145: /* varinitialize: compartmentinit  */
#line 447 "antimony.ypp"
                                { }
#line 3007 "antimony.tab.cpp"
    break;

  case 146: /* varinitialize: varconstinit  */
#line 448 "antimony.ypp"
                             { }
#line 3013 "antimony.tab.cpp"
    break;

  case 147: /* specinit: "'species'" varmaybeis  */
#line 451 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3019 "antimony.tab.cpp"
    break;

  case 148: /* specinit: "'var'" "'species'" varmaybeis  */
#line 452 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3025 "antimony.tab.cpp"
    break;

  case 149: /* specinit: "'const'" "'species'" varmaybeis  */
#line 453 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3031 "antimony.tab.cpp"
    break;

  case 150: /* specinit: "'substanceOnly'" "'species'" varmaybeis  */
#line 454 "antimony.ypp"
                                             {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3037 "antimony.tab.cpp"
    break;

  case 151: /* specinit: "'substanceOnly'" varmaybeis  */
#line 455 "antimony.ypp"
                                     {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3043 "antimony.tab.cpp"
    break;

  case 152: /* specinit: "'var'" "'substanceOnly'" "'species'" varmaybeis  */
#line 456 "antimony.ypp"
                                                     {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3049 "antimony.tab.cpp"
    break;

  case 153: /* specinit: "'const'" "'substanceOnly'" "'species'" varmaybeis  */
#line 457 "antimony.ypp"
                                                       {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3055 "antimony.tab.cpp"
    break;

  case 154: /* specinit: specinit ',' varmaybeis  */
#line 458 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3061 "antimony.tab.cpp"
    break;

  case 155: /* formulainit: "'formula'" varmaybeis  */
#line 461 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3067 "antimony.tab.cpp"
    break;

  case 156: /* formulainit: "'var'" "'formula'" varmaybeis  */
#line 462 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3073 "antimony.tab.cpp"
    break;

  case 157: /* formulainit: "'const'" "'formula'" varmaybeis  */
#line 463 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3079 "antimony.tab.cpp"
    break;

  case 158: /* formulainit: formulainit ',' varmaybeis  */
#line 464 "antimony.ypp"
                                           {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3085 "antimony.tab.cpp"
    break;

  case 159: /* reactioninit: "'reaction'" varmaybeis  */
#line 467 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3091 "antimony.tab.cpp"
    break;

  case 160: /* reactioninit: "'var'" "'reaction'" varmaybeis  */
#line 468 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3097 "antimony.tab.cpp"
    break;

  case 161: /* reactioninit: "'const'" "'reaction'"  */
#line 469 "antimony.ypp"
                                   {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; }
#line 3103 "antimony.tab.cpp"
    break;

  case 162: /* reactioninit: reactioninit ',' varmaybeis  */
#line 470 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3109 "antimony.tab.cpp"
    break;

  case 163: /* dnainit: "'DNA'" varmaybeis  */
#line 473 "antimony.ypp"
                               {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3115 "antimony.tab.cpp"
    break;

  case 164: /* dnainit: "'var'" "'DNA'" varmaybeis  */
#line 474 "antimony.ypp"
                                       {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3121 "antimony.tab.cpp"
    break;

  case 165: /* dnainit: "'const'" "'DNA'" varmaybeis  */
#line 475 "antimony.ypp"
                                         {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3127 "antimony.tab.cpp"
    break;

  case 166: /* dnainit: dnainit ',' varmaybeis  */
#line 476 "antimony.ypp"
                                       {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3133 "antimony.tab.cpp"
    break;

  case 167: /* geneinit: "'gene'" varmaybeis  */
#line 479 "antimony.ypp"
                                {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3139 "antimony.tab.cpp"
    break;

  case 168: /* geneinit: "'var'" "'gene'" varmaybeis  */
#line 480 "antimony.ypp"
                                        {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3145 "antimony.tab.cpp"
    break;

  case 169: /* geneinit: "'const'" "'gene'" varmaybeis  */
#line 481 "antimony.ypp"
                                          {g_registry.SetError("Genes may not be set 'const'."); YYABORT; }
#line 3151 "antimony.tab.cpp"
    break;

  case 170: /* geneinit: geneinit ',' varmaybeis  */
#line 482 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3157 "antimony.tab.cpp"
    break;

  case 171: /* operatorinit: "'operator'" varmaybeis  */
#line 485 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3163 "antimony.tab.cpp"
    break;

  case 172: /* operatorinit: "'var'" "'operator'" varmaybeis  */
#line 486 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3169 "antimony.tab.cpp"
    break;

  case 173: /* operatorinit: "'const'" "'operator'" varmaybeis  */
#line 487 "antimony.ypp"
                                              {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3175 "antimony.tab.cpp"
    break;

  case 174: /* operatorinit: operatorinit ',' varmaybeis  */
#line 488 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3181 "antimony.tab.cpp"
    break;

  case 175: /* compartmentinit: "'compartment'" varmaybeis  */
#line 492 "antimony.ypp"
                                       {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3187 "antimony.tab.cpp"
    break;

  case 176: /* compartmentinit: "'var'" "'compartment'" varmaybeis  */
#line 493 "antimony.ypp"
                                               {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3193 "antimony.tab.cpp"
    break;

  case 177: /* compartmentinit: "'const'" "'compartment'" varmaybeis  */
#line 494 "antimony.ypp"
                                                 {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3199 "antimony.tab.cpp"
    break;

  case 178: /* compartmentinit: compartmentinit ',' varmaybeis  */
#line 495 "antimony.ypp"
                                               {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3205 "antimony.tab.cpp"
    break;

  case 179: /* varconstinit: "'var'" varmaybeis  */
#line 498 "antimony.ypp"
                                   {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst();}
#line 3211 "antimony.tab.cpp"
    break;

  case 180: /* varconstinit: "'const'" varmaybeis  */
#line 499 "antimony.ypp"
                                     {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst();}
#line 3217 "antimony.tab.cpp"
    break;

  case 181: /* varconstinit: varconstinit ',' varmaybeis  */
#line 500 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst();}
#line 3223 "antimony.tab.cpp"
    break;

  case 182: /* unitinit: "'unit'" variable '=' formula  */
#line 503 "antimony.ypp"
                                              {if ((yyvsp[-2].variable)->SetType(varUnitDefinition)) YYABORT;
                                               if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                                               if ((yyvsp[-2].variable)->GetUnitDef()->SetFromFormula((yyvsp[0].formula))) YYABORT;}
#line 3231 "antimony.tab.cpp"
    break;

  case 183: /* unitinit: "'unit'" variable  */
#line 506 "antimony.ypp"
                                  {if ((yyvsp[0].variable)->SetType(varUnitDefinition)) YYABORT;}
#line 3237 "antimony.tab.cpp"
    break;

  case 184: /* dnadef: dnastrand  */
#line 509 "antimony.ypp"
                          {if (g_registry.SaveWorkingStrand()) YYABORT;}
#line 3243 "antimony.tab.cpp"
    break;

  case 185: /* dnadef: varmaybein ':' dnastrand  */
#line 510 "antimony.ypp"
                                         {if (g_registry.SetStrandAs((yyvsp[-2].variable))) YYABORT;}
#line 3249 "antimony.tab.cpp"
    break;

  case 186: /* dnastrand: "--" variable  */
#line 513 "antimony.ypp"
                                {if (g_registry.SetNewUpstreamOpen((yyvsp[0].variable))) YYABORT;}
#line 3255 "antimony.tab.cpp"
    break;

  case 187: /* dnastrand: "--" dnamiddle  */
#line 514 "antimony.ypp"
                                 {g_registry.SetOpenUpstream(); }
#line 3261 "antimony.tab.cpp"
    break;

  case 188: /* dnastrand: dnamiddle variable  */
#line 515 "antimony.ypp"
                                   {if (g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3267 "antimony.tab.cpp"
    break;

  case 189: /* dnastrand: "--" dnamiddle variable  */
#line 516 "antimony.ypp"
                                          {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3273 "antimony.tab.cpp"
    break;

  case 190: /* dnastrand: dnamiddle  */
#line 517 "antimony.ypp"
                          { }
#line 3279 "antimony.tab.cpp"
    break;

  case 191: /* dnamiddle: variable "--"  */
#line 520 "antimony.ypp"
                                {if (g_registry.SetNewDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3285 "antimony.tab.cpp"
    break;

  case 192: /* dnamiddle: dnamiddle variable "--"  */
#line 521 "antimony.ypp"
                                          {if (g_registry.SetDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3291 "antimony.tab.cpp"
    break;

  case 193: /* $@6: %empty  */
#line 524 "antimony.ypp"
                           {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula))) YYABORT;}
#line 3297 "antimony.tab.cpp"
    break;

  case 194: /* event: "'at'" formula $@6 eventmodifications colonret assignmentlist  */
#line 524 "antimony.ypp"
                                                                                                                        {}
#line 3303 "antimony.tab.cpp"
    break;

  case 195: /* $@7: %empty  */
#line 525 "antimony.ypp"
                                         {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula))) YYABORT;}
#line 3309 "antimony.tab.cpp"
    break;

  case 196: /* event: "'at'" formula "'after'" formula $@7 eventmodifications colonret assignmentlist  */
#line 525 "antimony.ypp"
                                                                                                                                          {}
#line 3315 "antimony.tab.cpp"
    break;

  case 197: /* $@8: %empty  */
#line 526 "antimony.ypp"
                                          {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula), (yyvsp[-3].variable))) YYABORT;}
#line 3321 "antimony.tab.cpp"
    break;

  case 198: /* event: varmaybein ':' "'at'" formula $@8 eventmodifications colonret assignmentlist  */
#line 526 "antimony.ypp"
                                                                                                                                            {}
#line 3327 "antimony.tab.cpp"
    break;

  case 199: /* $@9: %empty  */
#line 527 "antimony.ypp"
                                                        {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula), (yyvsp[-5].variable))) YYABORT;}
#line 3333 "antimony.tab.cpp"
    break;

  case 200: /* event: varmaybein ':' "'at'" formula "'after'" formula $@9 eventmodifications colonret assignmentlist  */
#line 527 "antimony.ypp"
                                                                                                                                                             {}
#line 3339 "antimony.tab.cpp"
    break;

  case 201: /* colonret: ':'  */
#line 530 "antimony.ypp"
                    {}
#line 3345 "antimony.tab.cpp"
    break;

  case 202: /* colonret: colonret '\n'  */
#line 531 "antimony.ypp"
                              {}
#line 3351 "antimony.tab.cpp"
    break;

  case 203: /* eventmodifications: %empty  */
#line 534 "antimony.ypp"
                                 {}
#line 3357 "antimony.tab.cpp"
    break;

  case 204: /* eventmodifications: eventmodifications ',' "element name" '=' formula  */
#line 535 "antimony.ypp"
                                                           {if (CaselessStrCmp(false, *(yyvsp[-2].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[0].formula));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[0].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;}}
#line 3367 "antimony.tab.cpp"
    break;

  case 205: /* assignmentlist: variable '=' formula  */
#line 542 "antimony.ypp"
                                     {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3373 "antimony.tab.cpp"
    break;

  case 206: /* assignmentlist: variable '=' formula ':' assignmentlist  */
#line 543 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3379 "antimony.tab.cpp"
    break;

  case 207: /* assignmentlist: variable '=' formula ':' '\n' assignmentlist  */
#line 544 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3385 "antimony.tab.cpp"
    break;

  case 208: /* assignmentlist: variable '=' formula ',' assignmentlist  */
#line 545 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3391 "antimony.tab.cpp"
    break;

  case 209: /* assignmentlist: variable '=' formula ',' '\n' assignmentlist  */
#line 546 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3397 "antimony.tab.cpp"
    break;

  case 210: /* deletion: "'delete'" variable  */
#line 549 "antimony.ypp"
                                    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3403 "antimony.tab.cpp"
    break;

  case 211: /* deletion: deletion ',' variable  */
#line 550 "antimony.ypp"
                                      {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3409 "antimony.tab.cpp"
    break;

  case 212: /* unitdef: formula  */
#line 553 "antimony.ypp"
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
#line 3427 "antimony.tab.cpp"
    break;

  case 213: /* constraint: "number" inequality formula  */
#line 568 "antimony.ypp"
                                       {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3433 "antimony.tab.cpp"
    break;

  case 214: /* constraint: '-' "number" inequality formula  */
#line 569 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint(-(yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3439 "antimony.tab.cpp"
    break;

  case 215: /* constraint: "name of a pre-defined constant" inequality formula  */
#line 570 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3445 "antimony.tab.cpp"
    break;

  case 216: /* constraint: "element name" inequality formula  */
#line 571 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3451 "antimony.tab.cpp"
    break;

  case 217: /* constraint: "'constraint'" ':' formula  */
#line 572 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[0].formula))) YYABORT;}
#line 3457 "antimony.tab.cpp"
    break;

  case 218: /* constraint: "'constraint'" variable ':' formula  */
#line 573 "antimony.ypp"
                                                    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3463 "antimony.tab.cpp"
    break;

  case 219: /* objective: maxormin formula  */
#line 576 "antimony.ypp"
                                              {if (g_registry.CurrentModule()->AddObjective((yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 3469 "antimony.tab.cpp"
    break;

  case 220: /* maxormin: "'maximize'"  */
#line 579 "antimony.ypp"
                             {(yyval.maxormin) = true;}
#line 3475 "antimony.tab.cpp"
    break;

  case 221: /* maxormin: "'minimize'"  */
#line 580 "antimony.ypp"
                             {(yyval.maxormin) = false;}
#line 3481 "antimony.tab.cpp"
    break;

  case 222: /* stringlist: "text string"  */
#line 583 "antimony.ypp"
                           { (yyval.stringlist) = new std::vector<std::string>(); (yyval.stringlist)->push_back(*((yyvsp[0].word))); }
#line 3487 "antimony.tab.cpp"
    break;

  case 223: /* stringlist: stringlist ',' "text string"  */
#line 584 "antimony.ypp"
                                          { (yyval.stringlist) = (yyvsp[-2].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3493 "antimony.tab.cpp"
    break;

  case 224: /* stringlist: stringlist ',' '\n' "text string"  */
#line 585 "antimony.ypp"
                                               { (yyval.stringlist) = (yyvsp[-3].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3499 "antimony.tab.cpp"
    break;

  case 225: /* $@10: %empty  */
#line 587 "antimony.ypp"
                                    {if (g_registry.SetCurrentModuleIf((yyvsp[0].word), (yyvsp[-1].word))) YYABORT;}
#line 3505 "antimony.tab.cpp"
    break;

  case 226: /* annotationBlock: "element name" "name of an existing module" $@10 annotations "'end'"  */
#line 587 "antimony.ypp"
                                                                                                          {g_registry.RevertToPreviousModule();}
#line 3511 "antimony.tab.cpp"
    break;

  case 227: /* annotations: %empty  */
#line 590 "antimony.ypp"
                            {}
#line 3517 "antimony.tab.cpp"
    break;

  case 228: /* annotations: "element name" ':' stringlist  */
#line 591 "antimony.ypp"
                                       {string modname = g_registry.CurrentModuleName(); g_registry.ProcessGlobalCVTerm(&modname, (yyvsp[-2].word), (yyvsp[0].stringlist));}
#line 3523 "antimony.tab.cpp"
    break;

  case 229: /* cvterm: variable "element name" stringlist  */
#line 596 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->ProcessCVTerm((yyvsp[-2].variable),(yyvsp[-1].word),(yyvsp[0].stringlist))) YYABORT;}
#line 3529 "antimony.tab.cpp"
    break;

  case 230: /* cvterm: variable "element name" '.' "element name" stringlist  */
#line 597 "antimony.ypp"
                                                        {if (g_registry.ProcessCreatorTerm((yyvsp[-4].variable), (yyvsp[-3].word), (yyvsp[-1].word), (yyvsp[0].stringlist))) YYABORT;}
#line 3535 "antimony.tab.cpp"
    break;

  case 231: /* cvterm: variable "element name" '.' "element name" "number"  */
#line 598 "antimony.ypp"
                                                 {if (g_registry.ProcessCreatorTerm((yyvsp[-4].variable), (yyvsp[-3].word), (yyvsp[-1].word), (yyvsp[0].num))) YYABORT;}
#line 3541 "antimony.tab.cpp"
    break;

  case 232: /* toplevel_sbo: "name of an existing module" '.' "element name" '=' "number"  */
#line 602 "antimony.ypp"
                  { Module* module = g_registry.GetModule(*(yyvsp[-4].word));
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      module->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3555 "antimony.tab.cpp"
    break;

  case 233: /* toplevel_sbo: "name of an existing function" '.' "element name" '=' "number"  */
#line 613 "antimony.ypp"
                  { Module* function = g_registry.GetModule(*(yyvsp[-4].word));
                    if (function && (yyvsp[-2].word) &&  CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      function->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3569 "antimony.tab.cpp"
    break;

  case 234: /* modulename: "name of an existing module" "'is'" "text string" lineend  */
#line 625 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3575 "antimony.tab.cpp"
    break;

  case 235: /* functionname: "name of an existing function" "'is'" "text string" lineend  */
#line 627 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3581 "antimony.tab.cpp"
    break;

  case 236: /* modulecvterm: "name of an existing module" "element name" stringlist lineend  */
#line 630 "antimony.ypp"
                                                   {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3587 "antimony.tab.cpp"
    break;

  case 237: /* modulecvterm: "name of an existing module" "element name" '.' "element name" stringlist lineend  */
#line 631 "antimony.ypp"
                                                               {if (g_registry.ProcessGlobalCreatorTerm((yyvsp[-5].word), (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].stringlist))) YYABORT;}
#line 3593 "antimony.tab.cpp"
    break;

  case 238: /* modulecvterm: "name of an existing module" "element name" '.' "element name" "number" lineend  */
#line 632 "antimony.ypp"
                                                        {if (g_registry.ProcessGlobalCreatorTerm((yyvsp[-5].word), (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].num))) YYABORT;}
#line 3599 "antimony.tab.cpp"
    break;

  case 239: /* functioncvterm: "name of an existing function" "element name" stringlist lineend  */
#line 633 "antimony.ypp"
                                                    {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3605 "antimony.tab.cpp"
    break;


#line 3609 "antimony.tab.cpp"

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

#line 635 "antimony.ypp"



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
