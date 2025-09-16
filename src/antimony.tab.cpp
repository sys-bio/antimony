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
    BECOMESACT = 266,              /* "-o"  */
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
    GENEPRODUCT = 283,             /* "'geneProduct'"  */
    GEQ = 284,                     /* ">="  */
    NEQ = 285,                     /* "!="  */
    HASWORD = 286,                 /* "'has'"  */
    IMPORT = 287,                  /* "'import'"  */
    INWORD = 288,                  /* "'in'"  */
    IS = 289,                      /* "'is'"  */
    LEQ = 290,                     /* "<="  */
    MAXIMIZEWORD = 291,            /* "'maximize'"  */
    MINIMIZEWORD = 292,            /* "'minimize'"  */
    MODNAME = 293,                 /* "name of an existing module"  */
    MODULE = 294,                  /* "'model' or 'module'"  */
    OPERATOR = 295,                /* "'operator'"  */
    REACTION = 296,                /* "'reaction'"  */
    SPECIES = 297,                 /* "'species'"  */
    SUBSTONLY = 298,               /* "'substanceOnly'"  */
    TEXTSTRING = 299,              /* "text string"  */
    UNITWORD = 300,                /* "'unit'"  */
    VARWORD = 301                  /* "'var'"  */
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
  bool maxormin;
  constraint_type inequality;
  std::vector<std::string>* stringlist;
  std::vector<Variable*>* variablelist;
  std::vector<double>* numlist;

#line 237 "antimony.tab.cpp"

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
  YYSYMBOL_BECOMESACT = 21,                /* "-o"  */
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
  YYSYMBOL_GENEPRODUCT = 38,               /* "'geneProduct'"  */
  YYSYMBOL_GEQ = 39,                       /* ">="  */
  YYSYMBOL_NEQ = 40,                       /* "!="  */
  YYSYMBOL_HASWORD = 41,                   /* "'has'"  */
  YYSYMBOL_IMPORT = 42,                    /* "'import'"  */
  YYSYMBOL_INWORD = 43,                    /* "'in'"  */
  YYSYMBOL_IS = 44,                        /* "'is'"  */
  YYSYMBOL_LEQ = 45,                       /* "<="  */
  YYSYMBOL_MAXIMIZEWORD = 46,              /* "'maximize'"  */
  YYSYMBOL_MINIMIZEWORD = 47,              /* "'minimize'"  */
  YYSYMBOL_MODNAME = 48,                   /* "name of an existing module"  */
  YYSYMBOL_MODULE = 49,                    /* "'model' or 'module'"  */
  YYSYMBOL_OPERATOR = 50,                  /* "'operator'"  */
  YYSYMBOL_REACTION = 51,                  /* "'reaction'"  */
  YYSYMBOL_SPECIES = 52,                   /* "'species'"  */
  YYSYMBOL_SUBSTONLY = 53,                 /* "'substanceOnly'"  */
  YYSYMBOL_TEXTSTRING = 54,                /* "text string"  */
  YYSYMBOL_UNITWORD = 55,                  /* "'unit'"  */
  YYSYMBOL_VARWORD = 56,                   /* "'var'"  */
  YYSYMBOL_57_ = 57,                       /* '('  */
  YYSYMBOL_58_ = 58,                       /* ')'  */
  YYSYMBOL_59_ = 59,                       /* ','  */
  YYSYMBOL_60_ = 60,                       /* '='  */
  YYSYMBOL_61_ = 61,                       /* ':'  */
  YYSYMBOL_62_ = 62,                       /* '\''  */
  YYSYMBOL_63_ = 63,                       /* '{'  */
  YYSYMBOL_64_ = 64,                       /* '}'  */
  YYSYMBOL_65_n_ = 65,                     /* '\n'  */
  YYSYMBOL_66_ = 66,                       /* ';'  */
  YYSYMBOL_67_ = 67,                       /* '!'  */
  YYSYMBOL_68_ = 68,                       /* '<'  */
  YYSYMBOL_69_ = 69,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_input = 71,                     /* input  */
  YYSYMBOL_import = 72,                    /* import  */
  YYSYMBOL_module = 73,                    /* module  */
  YYSYMBOL_74_1 = 74,                      /* $@1  */
  YYSYMBOL_75_2 = 75,                      /* $@2  */
  YYSYMBOL_76_3 = 76,                      /* $@3  */
  YYSYMBOL_77_4 = 77,                      /* $@4  */
  YYSYMBOL_function = 78,                  /* function  */
  YYSYMBOL_79_5 = 79,                      /* $@5  */
  YYSYMBOL_spacedformula = 80,             /* spacedformula  */
  YYSYMBOL_variableexportlist = 81,        /* variableexportlist  */
  YYSYMBOL_variable = 82,                  /* variable  */
  YYSYMBOL_variablein = 83,                /* variablein  */
  YYSYMBOL_varmaybein = 84,                /* varmaybein  */
  YYSYMBOL_varmaybeis = 85,                /* varmaybeis  */
  YYSYMBOL_maybein = 86,                   /* maybein  */
  YYSYMBOL_modulebody = 87,                /* modulebody  */
  YYSYMBOL_moduleannotation = 88,          /* moduleannotation  */
  YYSYMBOL_stringConstant = 89,            /* stringConstant  */
  YYSYMBOL_variablelist = 90,              /* variablelist  */
  YYSYMBOL_numlist = 91,                   /* numlist  */
  YYSYMBOL_modulepart = 92,                /* modulepart  */
  YYSYMBOL_reaction = 93,                  /* reaction  */
  YYSYMBOL_reactantList = 94,              /* reactantList  */
  YYSYMBOL_reactionDivider = 95,           /* reactionDivider  */
  YYSYMBOL_formula = 96,                   /* formula  */
  YYSYMBOL_commaformula = 97,              /* commaformula  */
  YYSYMBOL_mathThing = 98,                 /* mathThing  */
  YYSYMBOL_inequality = 99,                /* inequality  */
  YYSYMBOL_lineend = 100,                  /* lineend  */
  YYSYMBOL_assignment = 101,               /* assignment  */
  YYSYMBOL_algrule = 102,                  /* algrule  */
  YYSYMBOL_submodule = 103,                /* submodule  */
  YYSYMBOL_104_6 = 104,                    /* $@6  */
  YYSYMBOL_105_7 = 105,                    /* $@7  */
  YYSYMBOL_variableimportlist = 106,       /* variableimportlist  */
  YYSYMBOL_submodifications = 107,         /* submodifications  */
  YYSYMBOL_varinitialize = 108,            /* varinitialize  */
  YYSYMBOL_specinit = 109,                 /* specinit  */
  YYSYMBOL_geneProductInit = 110,          /* geneProductInit  */
  YYSYMBOL_formulainit = 111,              /* formulainit  */
  YYSYMBOL_reactioninit = 112,             /* reactioninit  */
  YYSYMBOL_dnainit = 113,                  /* dnainit  */
  YYSYMBOL_geneinit = 114,                 /* geneinit  */
  YYSYMBOL_operatorinit = 115,             /* operatorinit  */
  YYSYMBOL_compartmentinit = 116,          /* compartmentinit  */
  YYSYMBOL_varconstinit = 117,             /* varconstinit  */
  YYSYMBOL_unitinit = 118,                 /* unitinit  */
  YYSYMBOL_dnadef = 119,                   /* dnadef  */
  YYSYMBOL_dnastrand = 120,                /* dnastrand  */
  YYSYMBOL_dnamiddle = 121,                /* dnamiddle  */
  YYSYMBOL_event = 122,                    /* event  */
  YYSYMBOL_123_8 = 123,                    /* $@8  */
  YYSYMBOL_124_9 = 124,                    /* $@9  */
  YYSYMBOL_125_10 = 125,                   /* $@10  */
  YYSYMBOL_126_11 = 126,                   /* $@11  */
  YYSYMBOL_colonret = 127,                 /* colonret  */
  YYSYMBOL_eventmodifications = 128,       /* eventmodifications  */
  YYSYMBOL_assignmentlist = 129,           /* assignmentlist  */
  YYSYMBOL_deletion = 130,                 /* deletion  */
  YYSYMBOL_unitdef = 131,                  /* unitdef  */
  YYSYMBOL_constraint = 132,               /* constraint  */
  YYSYMBOL_objective = 133,                /* objective  */
  YYSYMBOL_maxormin = 134,                 /* maxormin  */
  YYSYMBOL_stringlist = 135,               /* stringlist  */
  YYSYMBOL_annotationBlock = 136,          /* annotationBlock  */
  YYSYMBOL_137_12 = 137,                   /* $@12  */
  YYSYMBOL_annotations = 138,              /* annotations  */
  YYSYMBOL_cvterm = 139,                   /* cvterm  */
  YYSYMBOL_toplevel_sbo = 140,             /* toplevel_sbo  */
  YYSYMBOL_modulename = 141,               /* modulename  */
  YYSYMBOL_functionname = 142,             /* functionname  */
  YYSYMBOL_modulecvterm = 143,             /* modulecvterm  */
  YYSYMBOL_functioncvterm = 144            /* functioncvterm  */
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
#define YYLAST   1267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  270
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  522

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      65,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,     2,     2,    12,    10,     4,    62,
      57,    58,     8,     7,    59,     6,    13,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    66,
      68,    60,    69,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56
};

#if ANTIMONY_YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   164,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   180,   183,   183,   189,
     189,   195,   195,   201,   201,   207,   208,   211,   211,   212,
     213,   216,   217,   218,   228,   229,   230,   233,   234,   242,
     249,   252,   255,   256,   259,   260,   261,   262,   263,   266,
     267,   270,   271,   272,   273,   276,   281,   286,   291,   301,
     311,   325,   339,   353,   369,   370,   371,   372,   374,   375,
     376,   379,   380,   381,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   400,   408,
     416,   424,   432,   440,   450,   451,   452,   453,   454,   455,
     459,   460,   461,   462,   463,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   482,
     483,   486,   487,   488,   489,   490,   491,   492,   495,   496,
     497,   498,   499,   502,   503,   504,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   518,   519,   522,   522,   523,
     523,   527,   528,   529,   530,   531,   535,   536,   540,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   566,   567,   569,
     570,   571,   572,   575,   576,   577,   578,   579,   582,   583,
     584,   585,   588,   589,   590,   591,   594,   595,   596,   597,
     601,   602,   603,   604,   605,   608,   609,   610,   613,   616,
     619,   620,   623,   624,   625,   626,   627,   630,   631,   634,
     634,   635,   635,   636,   636,   637,   637,   640,   641,   644,
     645,   652,   653,   654,   655,   656,   659,   660,   663,   678,
     679,   680,   681,   682,   683,   686,   689,   690,   693,   694,
     695,   697,   697,   700,   701,   706,   707,   708,   711,   722,
     732,   742,   756,   770,   784,   800,   802,   806,   807,   808,
     809
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
  "\"'geneProduct'\"", "\">=\"", "\"!=\"", "\"'has'\"", "\"'import'\"",
  "\"'in'\"", "\"'is'\"", "\"<=\"", "\"'maximize'\"", "\"'minimize'\"",
  "\"name of an existing module\"", "\"'model' or 'module'\"",
  "\"'operator'\"", "\"'reaction'\"", "\"'species'\"",
  "\"'substanceOnly'\"", "\"text string\"", "\"'unit'\"", "\"'var'\"",
  "'('", "')'", "','", "'='", "':'", "'\\''", "'{'", "'}'", "'\\n'", "';'",
  "'!'", "'<'", "'>'", "$accept", "input", "import", "module", "$@1",
  "$@2", "$@3", "$@4", "function", "$@5", "spacedformula",
  "variableexportlist", "variable", "variablein", "varmaybein",
  "varmaybeis", "maybein", "modulebody", "moduleannotation",
  "stringConstant", "variablelist", "numlist", "modulepart", "reaction",
  "reactantList", "reactionDivider", "formula", "commaformula",
  "mathThing", "inequality", "lineend", "assignment", "algrule",
  "submodule", "$@6", "$@7", "variableimportlist", "submodifications",
  "varinitialize", "specinit", "geneProductInit", "formulainit",
  "reactioninit", "dnainit", "geneinit", "operatorinit", "compartmentinit",
  "varconstinit", "unitinit", "dnadef", "dnastrand", "dnamiddle", "event",
  "$@8", "$@9", "$@10", "$@11", "colonret", "eventmodifications",
  "assignmentlist", "deletion", "unitdef", "constraint", "objective",
  "maxormin", "stringlist", "annotationBlock", "$@12", "annotations",
  "cvterm", "toplevel_sbo", "modulename", "functionname", "modulecvterm",
  "functioncvterm", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-415)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-95)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -415,   685,  -415,  -415,    87,    47,  -415,    29,   -11,  -415,
    -415,  -415,  -415,  -415,   299,   339,   167,   276,    47,    47,
      47,  -415,    47,   291,    -4,    47,    47,    70,  -415,  -415,
     203,   317,    47,   386,   400,   250,    47,  1214,  -415,  -415,
    -415,  -415,  -415,   977,    31,    68,  -415,  -415,   117,   415,
     446,  -415,   117,   117,   117,   117,    86,    92,   101,   122,
     185,   213,   272,   295,   301,   117,   117,  -415,    47,   117,
     127,   117,   117,  -415,  -415,   117,  -415,  -415,  -415,  -415,
    -415,   339,  -415,  -415,   256,  -415,  -415,  -415,  -415,  -415,
    -415,   256,  -415,  -415,  -415,   748,   360,    38,  -415,   325,
    -415,  -415,  -415,   158,    47,    47,    47,    47,    47,  -415,
      47,   328,  -415,   227,    47,   256,  -415,  -415,   372,   336,
     348,  -415,  -415,  -415,  -415,  -415,  -415,   392,   217,   376,
    -415,   421,   422,   219,  -415,  -415,  -415,   431,  -415,   436,
    -415,    47,  -415,   183,    47,    47,    47,    47,    47,    47,
      47,   402,  -415,   210,   229,  -415,    47,   256,    47,  -415,
      71,  -415,   543,   395,  -415,   405,   466,    21,    47,   486,
      13,  -415,  -415,  -415,  -415,    47,    47,    47,    47,    47,
      47,    47,    47,    47,  -415,  -415,   305,  -415,    47,  -415,
    -415,  -415,   946,  -415,  -415,   946,   946,   440,   946,   461,
     467,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,   414,  -415,  -415,   256,  -415,  -415,
    -415,   419,  -415,  -415,   437,   441,   946,   946,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,    47,   305,   445,  -415,   156,
     117,   434,   201,   494,   156,   117,   473,   455,   204,   496,
     457,  1169,   156,   470,   474,  -415,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,    47,  -415,  -415,   498,   478,   256,
     271,   946,  -415,  -415,    17,   946,   173,  -415,   469,  -415,
     355,   415,   446,  -415,  -415,  -415,    47,   486,  -415,    14,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
    -415,   256,   946,   480,   522,  -415,  -415,   946,   946,   263,
    -415,    94,   310,  -415,  -415,   946,  -415,  -415,   946,  -415,
     528,   170,  -415,  -415,    47,   539,   265,    12,  -415,  -415,
    -415,   256,   280,   510,  1169,   551,   346,   240,    47,   339,
     517,   307,   608,  -415,  -415,  -415,  -415,  -415,   946,  -415,
     243,    47,    47,  -415,   814,  -415,   946,   135,    16,   946,
     946,   256,   256,   880,  -415,   880,   336,  -415,  -415,  -415,
    -415,  -415,   559,  -415,    35,   946,   946,   946,  -415,  -415,
     524,   287,   256,   525,  -415,  -415,  -415,  -415,  -415,  -415,
     117,   156,  -415,   516,    47,  1004,   526,  -415,  -415,   117,
     156,   357,   244,  -415,  -415,  -415,   946,   946,  -415,   478,
     256,   256,   946,  -415,  -415,   473,  -415,    18,  -415,    47,
    -415,   880,  -415,   478,   310,   946,   532,  -415,   205,  -415,
    -415,   117,    47,   214,  -415,  -415,    27,  -415,   256,   368,
    -415,   224,  -415,  -415,  1169,   946,   310,   370,   880,  -415,
     880,   256,  -415,    35,  -415,  -415,    42,   946,   117,   256,
    -415,   523,  -415,   560,  -415,  1169,  -415,   523,  -415,  1059,
    -415,    35,  -415,  -415,   880,  -415,  -415,   946,   512,  -415,
    -415,   117,  -415,   256,   187,   324,   534,  1114,   332,   381,
    -415,   310,  -415,    27,  -415,    78,    84,    98,  -415,   147,
    -415,   533,  -415,  -415,  -415,    35,  -415,    47,  -415,    47,
    -415,    47,   256,  -415,   567,  -415,   256,  -415,  -415,  -415,
     256,  -415
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,    14,     0,     0,   135,     0,    37,   105,
     100,   101,   103,   104,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   133,
       3,     4,     6,    42,    83,     0,    13,     5,     0,     0,
       0,    87,     0,     0,     0,     0,   159,   164,   160,   161,
     162,   163,   165,   166,   167,     0,     0,   210,   216,     0,
       0,     0,     0,   105,    12,     0,    11,     7,     8,     9,
      10,     0,   102,    37,    40,   131,   132,   129,   105,   128,
     130,    95,   105,   251,   105,   219,     0,    42,    43,    44,
     200,   105,   105,     0,     0,     0,     0,     0,     0,   185,
       0,     0,   206,   212,   213,   236,   188,   179,     0,     0,
       0,    27,    30,    29,   192,   177,    16,     0,     0,     0,
     149,     0,     0,    19,    26,    25,   196,     0,   183,     0,
     168,     0,   172,   209,     0,     0,     0,     0,     0,     0,
       0,     0,   205,     0,    37,   217,     0,    96,     0,   105,
       0,   105,     0,     0,    74,     0,     0,     0,     0,    94,
       0,    75,    86,    76,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    78,   214,    79,     0,    81,
      84,    85,   245,    82,   105,   145,   239,   253,   242,     0,
       0,   122,   121,   123,   124,   127,   125,   108,   105,   109,
     106,   110,   118,   105,     0,   105,   126,   107,   113,   114,
     229,     0,   105,   105,     0,     0,   241,   243,   105,   202,
     190,   181,   194,   198,   170,     0,   215,     0,   248,     0,
       0,     0,     0,     0,     0,     0,   151,    23,     0,     0,
       0,     0,     0,     0,     0,   171,   105,   201,   189,   180,
     193,   197,   184,   169,     0,    38,    39,     0,   255,    41,
       0,   238,   144,   141,   138,   137,     0,   105,     0,   105,
      94,     0,     0,   211,   105,   105,     0,    97,   105,     0,
     105,   175,   178,   182,   186,   191,   195,   199,   203,   207,
     218,   237,   240,     0,     0,   116,   117,   221,   119,     0,
     115,     0,     0,   105,    48,    45,   105,   105,   244,   174,
       0,     0,   270,   266,    34,     0,     0,     0,   267,   265,
     154,   152,     0,     0,     0,     0,     0,     0,    34,    37,
       0,     0,     0,    52,    51,    55,   105,   105,   208,   173,
       0,     0,     0,   105,   223,   147,   142,     0,     0,   136,
     143,    98,    99,    49,   105,    49,     0,   252,   229,   111,
     105,   112,     0,   227,     0,   204,    46,    47,   259,   249,
       0,     0,    35,     0,   258,    66,    64,    67,    65,   260,
       0,     0,   156,     0,    34,     0,     0,    58,    59,     0,
       0,     0,     0,    20,    54,    53,   187,   176,   257,   256,
     140,   139,   146,   105,   229,   151,   105,     0,   105,     0,
      90,    49,    92,   254,     0,   120,     0,   228,     0,   220,
     250,   105,     0,     0,   269,   268,    49,   155,   153,     0,
      24,     0,    57,    56,     0,   225,     0,     0,    49,   105,
      49,    50,    89,     0,   105,   105,     0,    31,   105,    36,
     261,     0,   262,     0,   150,     0,    60,     0,    61,     0,
     229,     0,   156,    91,    49,    93,   222,   230,   231,    28,
      33,    32,    71,    68,     0,     0,     0,     0,     0,     0,
      18,     0,   224,    49,    88,     0,     0,     0,   263,     0,
     264,     0,    22,    62,    63,     0,   148,     0,   234,     0,
     232,     0,    69,    72,     0,   158,   157,   226,   235,   233,
      70,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
     125,  -316,    -1,     2,    15,    28,  -294,  -326,     0,  -293,
     121,   126,     6,  -415,   -48,   -25,   331,   369,  -415,     4,
      51,  -415,  -415,  -415,  -415,  -415,   180,   124,  -415,  -415,
    -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,  -415,
     435,   580,  -415,  -415,  -415,  -415,  -415,  -414,  -359,  -307,
    -415,   377,  -415,  -415,   438,  -114,  -415,  -415,  -415,  -415,
    -415,  -415,  -415,  -415,  -415
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    40,    41,   250,   251,   333,   334,    42,   241,
     456,   381,    97,    98,    99,   100,   420,   342,   343,   389,
     484,   485,   344,    48,    49,    50,   271,   309,   218,   219,
      51,    52,    53,    54,   415,   246,   332,   436,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,   220,   368,   414,   470,   374,   312,   429,
      70,   272,    71,    72,    73,   252,    74,   197,   304,    75,
      76,    77,    78,    79,    80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    46,   170,    44,    84,   239,    91,    47,   395,   424,
     453,    92,    94,   121,   244,   103,    45,   113,   115,   101,
     166,   166,   401,   166,   167,   166,   352,   390,    85,    86,
     153,   122,   471,     5,    87,   143,   168,    93,    83,   -43,
     268,     5,   157,   398,   123,   112,    83,     5,   116,   169,
     117,   153,    83,   124,   125,   446,     6,    89,    90,     5,
     136,   138,   140,   142,    83,   152,   238,   186,    85,    86,
     419,   422,   -43,   479,    87,   -43,   158,   505,   439,   290,
     364,   156,   418,     5,   449,   194,   463,   288,    83,    88,
       5,   -43,   -43,   -43,   217,    83,     5,    89,    90,   164,
     427,    83,    81,   171,   172,   173,   174,    38,    39,   159,
       5,   491,   160,   236,   281,    83,   184,   185,   469,   289,
     187,   189,   190,   191,   126,   273,   193,   452,   161,   162,
     163,     6,   229,   230,   231,   232,   233,   282,   234,   487,
     462,     6,   464,   507,    82,   175,   476,     5,   468,   509,
     168,   176,    83,   370,   473,   269,   475,   270,   371,   274,
     177,   280,   513,   511,   492,   287,   169,    91,   157,   255,
       6,   153,   257,   258,   259,   260,   261,   262,   263,     5,
     494,   178,    38,    39,    83,     5,   188,   301,   508,   510,
      83,   217,    38,    39,   217,   217,   153,   217,   517,   506,
     518,   416,   519,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   514,   391,   325,   321,   127,   335,   153,   228,
     128,    38,    39,   400,   379,   217,   217,   265,   102,   460,
     243,   385,   249,   353,   358,   380,   409,   266,   386,   466,
     153,   385,   267,   256,   179,   331,   497,   129,   386,   387,
      43,   498,   423,    44,   155,   399,   357,   249,   408,   387,
     130,   326,     5,   319,   336,   455,    45,    83,   388,   153,
     217,   238,   180,   238,   217,    91,   -17,   461,   388,   157,
     384,   169,   385,   238,   153,   361,   362,   467,     5,   386,
     322,   323,   349,    83,   238,   328,   329,   238,   238,   104,
     387,   217,   141,   345,   118,   105,   217,   217,   119,   417,
     106,     5,    96,   107,   217,   351,    83,   217,   153,   388,
     132,   369,   370,   382,   402,   131,   108,   109,   110,   111,
     132,   181,   300,    43,   133,   120,    44,   382,   392,   393,
      95,    43,   404,    94,    44,   431,   432,   217,   405,    45,
     410,   411,   134,   217,   182,   217,   169,    45,   217,   217,
     183,   397,   217,   385,   217,   135,   222,     5,   153,   372,
     386,   373,    83,   428,   217,   217,   217,   221,    85,    86,
     235,   387,   155,   499,    87,   223,   224,   225,   500,   237,
     238,   497,   438,   382,    43,   404,   503,    44,     5,   137,
     388,   405,   240,    83,   192,   217,   217,    89,    90,   242,
      45,   217,     5,   139,   331,   444,   432,    83,   451,   195,
     217,   165,   166,   196,   217,   198,   465,   432,   472,   393,
     245,   459,   226,   227,    10,    11,    12,    13,   247,   248,
     499,   434,   435,    43,   217,   504,    44,   217,   253,   217,
     442,   443,   428,   254,   264,   285,   217,   303,     5,    45,
     483,   168,    82,    83,    43,   305,   483,    44,    43,   404,
     428,    44,   306,   217,   310,   405,   217,   217,     5,   313,
      45,   286,   458,    83,    45,     5,    43,   404,   330,    44,
      83,   324,   275,   405,   428,   428,   512,   316,     5,   153,
     516,   317,    45,    83,   428,   320,   428,   480,   428,   458,
     520,   327,   -21,   337,   338,   350,   199,   200,   201,   202,
     203,   204,   205,   206,     5,   302,   355,   207,     5,    83,
     346,   437,   480,    83,   347,     5,   209,   321,   482,   307,
      83,   366,   210,   378,   308,     5,   308,   211,   515,   165,
      83,    85,    86,   367,   315,     5,   383,    87,   276,   318,
      83,   277,    10,    11,    12,    13,   212,   394,   396,   213,
      18,   495,   214,   496,   130,   215,   426,   486,   430,   216,
      89,    90,   521,   481,   311,   433,   441,   348,   488,    28,
      29,   278,   454,   489,   501,   447,   493,   283,   114,   314,
     284,     0,     0,   279,     0,     0,     0,     0,   354,     0,
     356,     0,     0,     0,     4,   359,   360,     0,     0,   363,
       5,   365,     6,     7,     0,   339,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,   403,
       0,     0,    22,     0,   375,    25,    26,   376,   377,     0,
       0,     0,     0,     0,    28,    29,   340,   341,    32,    33,
      34,    35,     0,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,     0,     0,   406,   407,     0,
       0,     0,     0,     0,   412,     2,     3,     0,     0,     0,
       0,     4,     0,     0,     0,   421,     0,     5,     0,     6,
       7,   425,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,    21,     0,    22,
      23,    24,    25,    26,     0,     0,     0,    27,     0,     0,
       0,    28,    29,    30,    31,    32,    33,    34,    35,     0,
      36,    37,     0,     0,   445,     0,     0,   448,     0,   450,
      38,    39,   199,   200,   201,   202,   203,   204,   205,   206,
       5,     0,   457,   207,   208,    83,     0,     0,     0,     0,
       0,     0,   209,     0,     0,     0,     0,     0,   210,     0,
     474,     0,     0,   211,     0,   477,   478,    85,    86,   457,
       0,     0,     0,    87,     0,     0,     0,     0,     0,     0,
       0,     0,   212,     0,     0,   213,     0,     0,   214,     0,
       0,   215,     0,     0,     0,   216,    89,    90,   199,   200,
     201,   202,   203,   204,   205,   206,     5,     0,     0,   207,
     413,    83,     0,     0,     0,     0,     0,     0,   209,     0,
       0,     0,     0,     0,   210,     0,     0,     0,     0,   211,
       0,     0,     0,    85,    86,     0,     0,     0,     0,    87,
       0,     0,     0,     0,     0,     0,     0,     0,   212,     0,
       0,   213,     0,     0,   214,     0,     0,   215,     0,     0,
       0,   216,    89,    90,   199,   200,   201,   202,   203,   204,
     205,   206,     5,     0,     0,   207,     0,    83,     0,     0,
       0,     0,     0,     0,   209,     0,     0,     0,     0,     0,
     210,     0,     0,     0,     0,   211,     0,     0,     0,    85,
      86,     0,     0,   419,     0,    87,     0,     0,     0,     0,
       0,     0,     0,     0,   212,     0,     0,   213,     0,     0,
     214,     0,     0,   215,     0,     0,     0,   216,    89,    90,
     199,   200,   201,   202,   203,   204,   205,   206,     5,     0,
       0,   207,     0,    83,     0,     0,     0,     0,     0,     0,
     209,     0,     0,     0,     0,     0,   210,     0,     0,     0,
       0,   211,     0,   -94,   -94,    85,    86,     0,     0,     5,
     153,    87,     0,     0,   154,     0,   -94,   -94,   -94,   -94,
     212,     0,     0,   213,   155,     0,   214,     0,     0,   215,
       4,     0,     0,   216,    89,    90,     5,     0,     6,     7,
     156,   339,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,   440,     0,     0,    22,     0,
       0,    25,    26,     0,     0,     0,     0,     0,     0,     0,
      28,    29,   340,   341,    32,    33,    34,    35,     0,    36,
      37,     0,     0,     0,     0,     4,     0,     0,     0,    38,
      39,     5,     0,     6,     7,     0,   339,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
     490,     0,     0,    22,     0,     0,    25,    26,     0,     0,
       0,     0,     0,     0,     0,    28,    29,   340,   341,    32,
      33,    34,    35,     0,    36,    37,     0,     0,     0,     0,
       4,     0,     0,     0,    38,    39,     5,     0,     6,     7,
       0,   339,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,   502,     0,     0,    22,     0,
       0,    25,    26,     0,     0,     0,     0,     0,     0,     0,
      28,    29,   340,   341,    32,    33,    34,    35,     0,    36,
      37,     0,     0,     0,     0,     4,     0,     0,     0,    38,
      39,     5,     0,     6,     7,     0,   339,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,    22,     0,     0,    25,    26,     0,     0,
       0,     0,     0,     0,     0,    28,    29,   340,   341,    32,
      33,    34,    35,     0,    36,    37,     5,     0,     0,     0,
       0,    83,     0,     0,    38,    39,     0,   144,     0,     0,
       0,     0,     0,   145,     0,     0,     0,     0,   146,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   149,   150,   151
};

static const yytype_int16 yycheck[] =
{
       1,     1,    50,     1,     5,   119,     7,     1,   334,   368,
     424,     7,     8,    17,   128,    16,     1,    18,    19,    15,
       7,     7,   338,     7,    49,     7,     9,    15,    39,    40,
      13,    35,   446,    12,    45,    36,    15,    48,    17,     8,
     154,    12,    43,   336,    48,    17,    17,    12,    20,    50,
      22,    13,    17,    25,    26,   414,    14,    68,    69,    12,
      32,    33,    34,    35,    17,    37,    54,    68,    39,    40,
      43,   365,    41,    31,    45,    44,     8,   491,   394,    66,
      66,    43,    66,    12,    66,    81,    59,    66,    17,    60,
      12,    60,    61,    62,    95,    17,    12,    68,    69,    48,
      65,    17,    15,    52,    53,    54,    55,    65,    66,    41,
      12,   470,    44,   114,   162,    17,    65,    66,   444,   167,
      69,    70,    71,    72,    54,    54,    75,   421,    60,    61,
      62,    14,   104,   105,   106,   107,   108,   162,   110,   465,
     433,    14,   436,    65,    57,    59,   453,    12,   441,    65,
      15,    59,    17,    59,   448,   156,   450,   158,    64,   160,
      59,   162,    15,    65,   471,   166,   167,   168,   169,   141,
      14,    13,   144,   145,   146,   147,   148,   149,   150,    12,
     474,    59,    65,    66,    17,    12,    59,   188,   495,   496,
      17,   192,    65,    66,   195,   196,    13,   198,   505,   493,
     507,    66,   509,   175,   176,   177,   178,   179,   180,   181,
     182,   183,    65,   327,    13,    59,    13,    13,    13,    61,
      17,    65,    66,   337,    54,   226,   227,    17,    61,    15,
      13,    17,    13,    60,   282,    65,   350,    27,    24,    15,
      13,    17,    13,    60,    59,   246,    59,    44,    24,    35,
     251,    64,   366,   251,    27,    15,   281,    13,    15,    35,
      57,    60,    12,   235,    60,    60,   251,    17,    54,    13,
     271,    54,    59,    54,   275,   276,    57,    63,    54,   280,
      15,   282,    17,    54,    13,   286,   287,    63,    12,    24,
     239,   240,   264,    17,    54,   244,   245,    54,    54,    23,
      35,   302,    52,   252,    13,    29,   307,   308,    17,   357,
      34,    12,    13,    37,   315,    44,    17,   318,    13,    54,
      13,    58,    59,   324,    17,     8,    50,    51,    52,    53,
      13,    59,    27,   334,    17,    44,   334,   338,    58,    59,
       9,   342,   342,   339,   342,    58,    59,   348,   342,   334,
     351,   352,    35,   354,    59,   356,   357,   342,   359,   360,
      59,    15,   363,    17,   365,    48,    41,    12,    13,    59,
      24,    61,    17,   374,   375,   376,   377,    17,    39,    40,
      52,    35,    27,    59,    45,    60,    61,    62,    64,    17,
      54,    59,   393,   394,   395,   395,    64,   395,    12,    13,
      54,   395,    54,    17,    73,   406,   407,    68,    69,    17,
     395,   412,    12,    13,   415,    58,    59,    17,   419,    88,
     421,     6,     7,    92,   425,    94,    58,    59,    58,    59,
      54,   432,   101,   102,    19,    20,    21,    22,    17,    17,
      59,   390,   391,   444,   445,    64,   444,   448,    17,   450,
     399,   400,   453,    17,    52,    60,   457,    17,    12,   444,
     461,    15,    57,    17,   465,     4,   467,   465,   469,   469,
     471,   469,     5,   474,    60,   469,   477,   478,    12,    60,
     465,    15,   431,    17,   469,    12,   487,   487,    15,   487,
      17,    57,   161,   487,   495,   496,   497,    60,    12,    13,
     501,    60,   487,    17,   505,    60,   507,   456,   509,   458,
     511,    17,    57,    17,    57,    17,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   194,    57,    15,    12,    17,
      60,    15,   481,    17,    60,    12,    24,    59,    15,   208,
      17,    61,    30,    15,   213,    12,   215,    35,    15,     6,
      17,    39,    40,    31,   223,    12,    17,    45,    15,   228,
      17,    18,    19,    20,    21,    22,    54,    57,    17,    57,
      27,    59,    60,    61,    57,    63,    17,    17,    54,    67,
      68,    69,    15,   458,   215,    60,    60,   256,   467,    46,
      47,    48,    60,   467,    60,   415,   472,   162,    18,   222,
     162,    -1,    -1,    60,    -1,    -1,    -1,    -1,   277,    -1,
     279,    -1,    -1,    -1,     6,   284,   285,    -1,    -1,   288,
      12,   290,    14,    15,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      -1,    -1,    34,    -1,   313,    37,    38,   316,   317,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    -1,    -1,   346,   347,    -1,
      -1,    -1,    -1,    -1,   353,     0,     1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,   364,    -1,    12,    -1,    14,
      15,   370,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    -1,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    -1,    -1,   413,    -1,    -1,   416,    -1,   418,
      65,    66,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,   431,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,
     449,    -1,    -1,    35,    -1,   454,   455,    39,    40,   458,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    57,    -1,    -1,    60,    -1,
      -1,    63,    -1,    -1,    -1,    67,    68,    69,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    57,    -1,    -1,    60,    -1,    -1,    63,    -1,    -1,
      -1,    67,    68,    69,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    15,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    39,
      40,    -1,    -1,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    -1,    -1,
      60,    -1,    -1,    63,    -1,    -1,    -1,    67,    68,    69,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    35,    -1,     6,     7,    39,    40,    -1,    -1,    12,
      13,    45,    -1,    -1,    17,    -1,    19,    20,    21,    22,
      54,    -1,    -1,    57,    27,    -1,    60,    -1,    -1,    63,
       6,    -1,    -1,    67,    68,    69,    12,    -1,    14,    15,
      43,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    -1,    34,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    65,
      66,    12,    -1,    14,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    -1,    -1,    34,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    65,    66,    12,    -1,    14,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    -1,    34,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    65,
      66,    12,    -1,    14,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    12,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    65,    66,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,     0,     1,     6,    12,    14,    15,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    32,    34,    35,    36,    37,    38,    42,    46,    47,
      48,    49,    50,    51,    52,    53,    55,    56,    65,    66,
      72,    73,    78,    82,    83,    84,    88,    92,    93,    94,
      95,   100,   101,   102,   103,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     130,   132,   133,   134,   136,   139,   140,   141,   142,   143,
     144,    15,    57,    17,    82,    39,    40,    45,    60,    68,
      69,    82,    99,    48,    99,    96,    13,    82,    83,    84,
      85,    99,    61,    82,    23,    29,    34,    37,    50,    51,
      52,    53,    85,    82,   121,    82,    85,    85,    13,    17,
      44,    17,    35,    48,    85,    85,    54,    13,    17,    44,
      57,     8,    13,    17,    35,    48,    85,    13,    85,    13,
      85,    52,    85,    82,    23,    29,    34,    37,    50,    51,
      52,    53,    85,    13,    17,    27,    43,    82,     8,    41,
      44,    60,    61,    62,   100,     6,     7,    95,    15,    82,
      94,   100,   100,   100,   100,    59,    59,    59,    59,    59,
      59,    59,    59,    59,   100,   100,    82,   100,    59,   100,
     100,   100,    96,   100,    99,    96,    96,   137,    96,     4,
       5,     6,     7,     8,     9,    10,    11,    15,    16,    24,
      30,    35,    54,    57,    60,    63,    67,    82,    98,    99,
     123,    17,    41,    60,    61,    62,    96,    96,    61,    85,
      85,    85,    85,    85,    85,    52,    82,    17,    54,   135,
      54,    79,    17,    13,   135,    54,   105,    17,    17,    13,
      74,    75,   135,    17,    17,    85,    60,    85,    85,    85,
      85,    85,    85,    85,    52,    17,    27,    13,   135,    82,
      82,    96,   131,    54,    82,    96,    15,    18,    48,    60,
      82,    94,    95,   120,   134,    60,    15,    82,    66,    94,
      66,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      27,    82,    96,    17,   138,     4,     5,    96,    96,    97,
      60,    97,   128,    60,   131,    96,    60,    60,    96,    85,
      60,    59,   100,   100,    57,    13,    60,    17,   100,   100,
      15,    82,   106,    76,    77,    13,    60,    17,    57,    17,
      48,    49,    87,    88,    92,   100,    60,    60,    96,    85,
      17,    44,     9,    60,    96,    57,    96,    95,    94,    96,
      96,    82,    82,    96,    66,    96,    61,    31,   124,    58,
      59,    64,    59,    61,   127,    96,    96,    96,    15,    54,
      65,    81,    82,    17,    15,    17,    24,    35,    54,    89,
      15,   135,    58,    59,    57,    87,    17,    15,    89,    15,
     135,    81,    17,    31,    88,    92,    96,    96,    15,   135,
      82,    82,    96,    16,   125,   104,    66,    94,    66,    43,
      86,    96,    86,   135,   128,    96,    17,    65,    82,   129,
      54,    58,    59,    60,   100,   100,   107,    15,    82,    81,
      31,    60,   100,   100,    58,    96,   128,   106,    96,    66,
      96,    82,    86,   127,    60,    60,    80,    96,   100,    82,
      15,    63,    89,    59,    86,    58,    15,    63,    89,    87,
     126,   127,    58,    86,    96,    86,   129,    96,    96,    31,
     100,    80,    15,    82,    90,    91,    17,    87,    90,    91,
      31,   128,   129,   107,    86,    59,    61,    59,    64,    59,
      64,    60,    31,    64,    64,   127,    86,    65,   129,    65,
     129,    65,    82,    15,    65,    15,    82,   129,   129,   129,
      82,    15
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    74,    73,    75,
      73,    76,    73,    77,    73,    73,    73,    79,    78,    78,
      78,    80,    80,    80,    81,    81,    81,    82,    82,    82,
      82,    83,    84,    84,    85,    85,    85,    85,    85,    86,
      86,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    89,    89,    90,    90,
      90,    91,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    93,    93,
      93,    93,    93,    93,    94,    94,    94,    94,    94,    94,
      95,    95,    95,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    98,    98,    98,    98,    98,    99,    99,
      99,    99,    99,   100,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   102,   104,   103,   105,
     103,   106,   106,   106,   106,   106,   107,   107,   107,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   110,   110,   111,
     111,   111,   111,   112,   112,   112,   112,   112,   113,   113,
     113,   113,   114,   114,   114,   114,   115,   115,   115,   115,
     116,   116,   116,   116,   116,   117,   117,   117,   118,   118,
     119,   119,   120,   120,   120,   120,   120,   121,   121,   123,
     122,   124,   122,   125,   122,   126,   122,   127,   127,   128,
     128,   129,   129,   129,   129,   129,   130,   130,   131,   132,
     132,   132,   132,   132,   132,   133,   134,   134,   135,   135,
     135,   137,   136,   138,   138,   139,   139,   139,   140,   140,
     140,   140,   140,   140,   140,   141,   142,   143,   143,   143,
     144
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     0,     8,     0,
       5,     0,     9,     0,     6,     2,     2,     0,     8,     2,
       2,     1,     2,     2,     0,     1,     3,     1,     3,     3,
       2,     3,     1,     1,     1,     3,     4,     4,     3,     0,
       2,     1,     1,     2,     2,     4,     6,     6,     5,     5,
       7,     7,     9,     9,     1,     1,     1,     1,     1,     3,
       4,     1,     3,     4,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     2,     2,     1,     8,     6,
       5,     7,     5,     7,     1,     2,     2,     3,     4,     4,
       1,     1,     2,     1,     1,     0,     2,     2,     2,     2,
       2,     4,     4,     2,     2,     3,     3,     3,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     3,     5,
       5,     3,     4,     4,     3,     3,     5,     0,     9,     0,
       7,     0,     1,     3,     1,     3,     0,     5,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     3,     2,     4,     4,     3,     5,     2,     3,     2,
       3,     3,     3,     2,     3,     2,     3,     5,     2,     3,
       3,     3,     2,     3,     3,     3,     2,     3,     3,     3,
       2,     3,     3,     3,     5,     2,     2,     3,     4,     2,
       1,     3,     2,     2,     2,     3,     1,     2,     3,     0,
       6,     0,     8,     0,     8,     0,    10,     1,     2,     0,
       5,     3,     5,     6,     5,     6,     2,     3,     1,     3,
       4,     3,     3,     3,     4,     2,     1,     1,     1,     3,
       4,     0,     5,     0,     3,     3,     5,     5,     5,     5,
       5,     7,     7,     9,     9,     4,     4,     4,     6,     6,
       4
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
#line 165 "antimony.ypp"
                             {}
#line 2153 "antimony.tab.cpp"
    break;

  case 4: /* input: input module  */
#line 166 "antimony.ypp"
                             { /*cout << endl << $2->ToString() << endl << endl;*/ }
#line 2159 "antimony.tab.cpp"
    break;

  case 5: /* input: input modulepart  */
#line 167 "antimony.ypp"
                                 {}
#line 2165 "antimony.tab.cpp"
    break;

  case 6: /* input: input function  */
#line 168 "antimony.ypp"
                               {}
#line 2171 "antimony.tab.cpp"
    break;

  case 7: /* input: input modulename  */
#line 169 "antimony.ypp"
                                 {}
#line 2177 "antimony.tab.cpp"
    break;

  case 8: /* input: input functionname  */
#line 170 "antimony.ypp"
                                   {}
#line 2183 "antimony.tab.cpp"
    break;

  case 9: /* input: input modulecvterm  */
#line 171 "antimony.ypp"
                                   {}
#line 2189 "antimony.tab.cpp"
    break;

  case 10: /* input: input functioncvterm  */
#line 172 "antimony.ypp"
                                     {}
#line 2195 "antimony.tab.cpp"
    break;

  case 11: /* input: input toplevel_sbo  */
#line 173 "antimony.ypp"
                                   {}
#line 2201 "antimony.tab.cpp"
    break;

  case 12: /* input: input annotationBlock  */
#line 174 "antimony.ypp"
                                      {}
#line 2207 "antimony.tab.cpp"
    break;

  case 13: /* input: input moduleannotation  */
#line 175 "antimony.ypp"
                                      {}
#line 2213 "antimony.tab.cpp"
    break;

  case 14: /* input: input error  */
#line 176 "antimony.ypp"
                            {YYABORT;}
#line 2219 "antimony.tab.cpp"
    break;

  case 15: /* input: input "an error"  */
#line 177 "antimony.ypp"
                            {YYABORT;}
#line 2225 "antimony.tab.cpp"
    break;

  case 16: /* import: "'import'" "text string"  */
#line 180 "antimony.ypp"
                                  { if (g_registry.OpenFile(*((yyvsp[0].word)))==0) YYABORT;}
#line 2231 "antimony.tab.cpp"
    break;

  case 17: /* $@1: %empty  */
#line 183 "antimony.ypp"
                               {g_registry.NewCurrentModule((yyvsp[0].word), NULL, false);}
#line 2237 "antimony.tab.cpp"
    break;

  case 18: /* module: "'model' or 'module'" "element name" $@1 '(' variableexportlist ')' modulebody "'end'"  */
#line 184 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2247 "antimony.tab.cpp"
    break;

  case 19: /* $@2: %empty  */
#line 189 "antimony.ypp"
                               {g_registry.NewCurrentModule((yyvsp[0].word), NULL, false);}
#line 2253 "antimony.tab.cpp"
    break;

  case 20: /* module: "'model' or 'module'" "element name" $@2 modulebody "'end'"  */
#line 190 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2263 "antimony.tab.cpp"
    break;

  case 21: /* $@3: %empty  */
#line 195 "antimony.ypp"
                                   {g_registry.NewCurrentModule((yyvsp[0].word), NULL, true);}
#line 2269 "antimony.tab.cpp"
    break;

  case 22: /* module: "'model' or 'module'" '*' "element name" $@3 '(' variableexportlist ')' modulebody "'end'"  */
#line 196 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2279 "antimony.tab.cpp"
    break;

  case 23: /* $@4: %empty  */
#line 201 "antimony.ypp"
                                   {g_registry.NewCurrentModule((yyvsp[0].word), NULL, true);}
#line 2285 "antimony.tab.cpp"
    break;

  case 24: /* module: "'model' or 'module'" '*' "element name" $@4 modulebody "'end'"  */
#line 202 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2295 "antimony.tab.cpp"
    break;

  case 25: /* module: "'model' or 'module'" "name of an existing module"  */
#line 207 "antimony.ypp"
                               {g_registry.SetError("module '" + *((yyvsp[0].word)) + "' already defined."); YYABORT;}
#line 2301 "antimony.tab.cpp"
    break;

  case 26: /* module: "'model' or 'module'" "name of an existing function"  */
#line 208 "antimony.ypp"
                                {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a module because it is already a defined function."); YYABORT;}
#line 2307 "antimony.tab.cpp"
    break;

  case 27: /* $@5: %empty  */
#line 211 "antimony.ypp"
                                     {g_registry.NewUserFunction((yyvsp[0].word));}
#line 2313 "antimony.tab.cpp"
    break;

  case 28: /* function: "'function'" "element name" $@5 '(' variableexportlist ')' spacedformula "'end'"  */
#line 211 "antimony.ypp"
                                                                                                                    {if (g_registry.SetUserFunction((yyvsp[-1].formula))) YYABORT;}
#line 2319 "antimony.tab.cpp"
    break;

  case 29: /* function: "'function'" "name of an existing module"  */
#line 212 "antimony.ypp"
                                     {g_registry.SetError("Cannot use '" + *((yyvsp[0].word)) +"' as a function name because it is already the name of a module."); YYABORT;}
#line 2325 "antimony.tab.cpp"
    break;

  case 30: /* function: "'function'" "name of an existing function"  */
#line 213 "antimony.ypp"
                                      {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a new function because it is already a defined function."); YYABORT;}
#line 2331 "antimony.tab.cpp"
    break;

  case 31: /* spacedformula: formula  */
#line 216 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2337 "antimony.tab.cpp"
    break;

  case 32: /* spacedformula: lineend spacedformula  */
#line 217 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[0].formula);}
#line 2343 "antimony.tab.cpp"
    break;

  case 33: /* spacedformula: spacedformula lineend  */
#line 218 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[-1].formula);}
#line 2349 "antimony.tab.cpp"
    break;

  case 34: /* variableexportlist: %empty  */
#line 228 "antimony.ypp"
                            {}
#line 2355 "antimony.tab.cpp"
    break;

  case 35: /* variableexportlist: variable  */
#line 229 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2361 "antimony.tab.cpp"
    break;

  case 36: /* variableexportlist: variableexportlist ',' variable  */
#line 230 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2367 "antimony.tab.cpp"
    break;

  case 37: /* variable: "element name"  */
#line 233 "antimony.ypp"
                        {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[0].word)); }
#line 2373 "antimony.tab.cpp"
    break;

  case 38: /* variable: variable '.' "element name"  */
#line 234 "antimony.ypp"
                                     {(yyval.variable) = (yyvsp[-2].variable)->GetSubVariable((yyvsp[0].word));
                  if ((yyval.variable) == NULL) {
                    if (g_registry.GetError().empty()) {
                      g_registry.SetError("'" + *((yyvsp[0].word)) + "' is not a subvariable of '" + (yyvsp[-2].variable)->GetNameDelimitedBy(".") + "'.");
                    }
                    YYABORT;
                  }
                }
#line 2386 "antimony.tab.cpp"
    break;

  case 39: /* variable: variable '.' "--"  */
#line 242 "antimony.ypp"
                                    {
		  string dashes("--");
		  (yyval.variable) = (yyvsp[-2].variable)->GetSubVariable(&dashes);
                  if ((yyval.variable) == NULL) {                    g_registry.SetError("There is no empty set that can be set with '.--' for the variable '" + (yyvsp[-2].variable)->GetNameDelimitedBy(".") + "'.");
                    YYABORT;
                  }
                }
#line 2398 "antimony.tab.cpp"
    break;

  case 40: /* variable: '$' variable  */
#line 249 "antimony.ypp"
                             {(yyval.variable) = (yyvsp[0].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;}
#line 2404 "antimony.tab.cpp"
    break;

  case 41: /* variablein: variable "'in'" variable  */
#line 252 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetCompartment((yyvsp[0].variable))) YYABORT; (yyval.variable) = (yyvsp[-2].variable);}
#line 2410 "antimony.tab.cpp"
    break;

  case 42: /* varmaybein: variable  */
#line 255 "antimony.ypp"
                         {(yyval.variable) = (yyvsp[0].variable);}
#line 2416 "antimony.tab.cpp"
    break;

  case 43: /* varmaybein: variablein  */
#line 256 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2422 "antimony.tab.cpp"
    break;

  case 44: /* varmaybeis: varmaybein  */
#line 259 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2428 "antimony.tab.cpp"
    break;

  case 45: /* varmaybeis: varmaybein '=' formula  */
#line 260 "antimony.ypp"
                                       {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2434 "antimony.tab.cpp"
    break;

  case 46: /* varmaybeis: varmaybein ':' '=' formula  */
#line 261 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT; }
#line 2440 "antimony.tab.cpp"
    break;

  case 47: /* varmaybeis: varmaybein '\'' '=' formula  */
#line 262 "antimony.ypp"
                                            {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT; }
#line 2446 "antimony.tab.cpp"
    break;

  case 48: /* varmaybeis: varmaybein "'has'" unitdef  */
#line 263 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2452 "antimony.tab.cpp"
    break;

  case 49: /* maybein: %empty  */
#line 266 "antimony.ypp"
                            {(yyval.variable) = NULL;}
#line 2458 "antimony.tab.cpp"
    break;

  case 50: /* maybein: "'in'" variable  */
#line 267 "antimony.ypp"
                                {(yyval.variable) = (yyvsp[0].variable);}
#line 2464 "antimony.tab.cpp"
    break;

  case 51: /* modulebody: modulepart  */
#line 270 "antimony.ypp"
                           {}
#line 2470 "antimony.tab.cpp"
    break;

  case 52: /* modulebody: moduleannotation  */
#line 271 "antimony.ypp"
                                 {}
#line 2476 "antimony.tab.cpp"
    break;

  case 53: /* modulebody: modulebody modulepart  */
#line 272 "antimony.ypp"
                                      {}
#line 2482 "antimony.tab.cpp"
    break;

  case 54: /* modulebody: modulebody moduleannotation  */
#line 273 "antimony.ypp"
                                           {}
#line 2488 "antimony.tab.cpp"
    break;

  case 55: /* moduleannotation: "'model' or 'module'" "element name" stringlist lineend  */
#line 277 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCVTerm(&modname,(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;
                }
#line 2497 "antimony.tab.cpp"
    break;

  case 56: /* moduleannotation: "'model' or 'module'" "element name" '.' "element name" stringlist lineend  */
#line 282 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCreatorTerm(&modname, (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].stringlist))) YYABORT;
                }
#line 2506 "antimony.tab.cpp"
    break;

  case 57: /* moduleannotation: "'model' or 'module'" "element name" '.' "element name" "number" lineend  */
#line 287 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCreatorTerm(&modname, (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].num))) YYABORT;
                }
#line 2515 "antimony.tab.cpp"
    break;

  case 58: /* moduleannotation: "'model' or 'module'" '.' "element name" '=' "number"  */
#line 292 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      module->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-2].word)) + "'. The only thing that can be set on the model to a number is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 2529 "antimony.tab.cpp"
    break;

  case 59: /* moduleannotation: "'model' or 'module'" '.' "element name" '=' stringConstant  */
#line 302 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "layout")) {
                      if (module->SetLayout((yyvsp[0].word))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-2].word)) + "'. The only thing that can be set on the model to a string is 'layout'.");
                      YYABORT;
                    }
                  }
#line 2543 "antimony.tab.cpp"
    break;

  case 60: /* moduleannotation: "'model' or 'module'" '.' "element name" '.' "element name" '=' "number"  */
#line 312 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-4].word) && CaselessStrCmp(true, *((yyvsp[-4].word)), "autolayout")) {
                      if (module->SetAutoLayout((yyvsp[-2].word), (yyvsp[0].num))) YYABORT;
                    }
                    else if (module && (yyvsp[-4].word) && CaselessStrCmp(true, *((yyvsp[-4].word)), "layout")) {
                      if (module->SetLayout((yyvsp[-2].word), (yyvsp[0].num))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-4].word)) + "'.*:  The core word here must be 'layout' or 'autolayout'.");
                      YYABORT;
                    }
                    module->SetLayout("on");
                  }
#line 2561 "antimony.tab.cpp"
    break;

  case 61: /* moduleannotation: "'model' or 'module'" '.' "element name" '.' "element name" '=' stringConstant  */
#line 326 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-4].word) && CaselessStrCmp(true, *((yyvsp[-4].word)), "autolayout")) {
                      if (module->SetAutoLayout((yyvsp[-2].word), (yyvsp[0].word))) YYABORT;
                    }
                    else if (module && (yyvsp[-4].word) && CaselessStrCmp(true, *((yyvsp[-4].word)), "layout")) {
                      if (module->SetLayout((yyvsp[-2].word), (yyvsp[0].word))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-4].word)) + "'.*:  The core word here must be 'layout' or 'autolayout'.");
                      YYABORT;
                    }
                    module->SetLayout("on");
                  }
#line 2579 "antimony.tab.cpp"
    break;

  case 62: /* moduleannotation: "'model' or 'module'" '.' "element name" '.' "element name" '=' '{' variablelist '}'  */
#line 340 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-6].word) && CaselessStrCmp(true, *((yyvsp[-6].word)), "autolayout")) {
                      if (module->SetAutoLayout((yyvsp[-4].word), (yyvsp[-1].variablelist))) YYABORT;
                    }
                    else if (module && (yyvsp[-6].word) && CaselessStrCmp(true, *((yyvsp[-6].word)), "layout")) {
                      if (module->SetLayout((yyvsp[-4].word), (yyvsp[-1].variablelist))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-6].word)) + "'.*:  The core word here must be 'layout' or 'autolayout'.");
                      YYABORT;
                    }
                    module->SetLayout("on");
                  }
#line 2597 "antimony.tab.cpp"
    break;

  case 63: /* moduleannotation: "'model' or 'module'" '.' "element name" '.' "element name" '=' '{' numlist '}'  */
#line 354 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-6].word) && CaselessStrCmp(true, *((yyvsp[-6].word)), "autolayout")) {
                      if (module->SetAutoLayout((yyvsp[-4].word), (yyvsp[-1].numlist))) YYABORT;
                    }
                    else if (module && (yyvsp[-6].word) && CaselessStrCmp(true, *((yyvsp[-6].word)), "layout")) {
                      if (module->SetLayout((yyvsp[-4].word), (yyvsp[-1].numlist))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-6].word)) + "'.*:  The core word here must be 'layout' or 'autolayout'.");
                      YYABORT;
                    }
                    module->SetLayout("on");
                  }
#line 2615 "antimony.tab.cpp"
    break;

  case 64: /* stringConstant: "name of a pre-defined constant"  */
#line 369 "antimony.ypp"
                         {(yyval.word) = (yyvsp[0].word);}
#line 2621 "antimony.tab.cpp"
    break;

  case 65: /* stringConstant: "text string"  */
#line 370 "antimony.ypp"
                           {(yyval.word) = (yyvsp[0].word);}
#line 2627 "antimony.tab.cpp"
    break;

  case 66: /* stringConstant: "element name"  */
#line 371 "antimony.ypp"
                        {(yyval.word) = (yyvsp[0].word);}
#line 2633 "antimony.tab.cpp"
    break;

  case 67: /* stringConstant: "name of an existing function"  */
#line 372 "antimony.ypp"
                         {(yyval.word) = (yyvsp[0].word);}
#line 2639 "antimony.tab.cpp"
    break;

  case 68: /* variablelist: variable  */
#line 374 "antimony.ypp"
                         { (yyval.variablelist) = new std::vector<Variable*>(); (yyval.variablelist)->push_back((yyvsp[0].variable));}
#line 2645 "antimony.tab.cpp"
    break;

  case 69: /* variablelist: variablelist ',' variable  */
#line 375 "antimony.ypp"
                                          { (yyval.variablelist) = (yyvsp[-2].variablelist); (yyval.variablelist)->push_back((yyvsp[0].variable)); }
#line 2651 "antimony.tab.cpp"
    break;

  case 70: /* variablelist: variablelist ',' '\n' variable  */
#line 376 "antimony.ypp"
                                               { (yyval.variablelist) = (yyvsp[-3].variablelist); (yyval.variablelist)->push_back((yyvsp[0].variable)); }
#line 2657 "antimony.tab.cpp"
    break;

  case 71: /* numlist: "number"  */
#line 379 "antimony.ypp"
                    { (yyval.numlist) = new std::vector<double>(); (yyval.numlist)->push_back((yyvsp[0].num)); }
#line 2663 "antimony.tab.cpp"
    break;

  case 72: /* numlist: numlist ',' "number"  */
#line 380 "antimony.ypp"
                                { (yyval.numlist) = (yyvsp[-2].numlist); (yyval.numlist)->push_back((yyvsp[0].num)); }
#line 2669 "antimony.tab.cpp"
    break;

  case 73: /* numlist: numlist ',' '\n' "number"  */
#line 381 "antimony.ypp"
                                     { (yyval.numlist) = (yyvsp[-3].numlist); (yyval.numlist)->push_back((yyvsp[0].num)); }
#line 2675 "antimony.tab.cpp"
    break;

  case 74: /* modulepart: reaction lineend  */
#line 384 "antimony.ypp"
                                 {}
#line 2681 "antimony.tab.cpp"
    break;

  case 75: /* modulepart: assignment lineend  */
#line 385 "antimony.ypp"
                                   {}
#line 2687 "antimony.tab.cpp"
    break;

  case 76: /* modulepart: submodule lineend  */
#line 386 "antimony.ypp"
                                  {}
#line 2693 "antimony.tab.cpp"
    break;

  case 77: /* modulepart: varinitialize lineend  */
#line 387 "antimony.ypp"
                                      {}
#line 2699 "antimony.tab.cpp"
    break;

  case 78: /* modulepart: dnadef lineend  */
#line 388 "antimony.ypp"
                               {}
#line 2705 "antimony.tab.cpp"
    break;

  case 79: /* modulepart: event lineend  */
#line 389 "antimony.ypp"
                              {}
#line 2711 "antimony.tab.cpp"
    break;

  case 80: /* modulepart: unitinit lineend  */
#line 390 "antimony.ypp"
                                 {}
#line 2717 "antimony.tab.cpp"
    break;

  case 81: /* modulepart: deletion lineend  */
#line 391 "antimony.ypp"
                                 {}
#line 2723 "antimony.tab.cpp"
    break;

  case 82: /* modulepart: cvterm lineend  */
#line 392 "antimony.ypp"
                               {}
#line 2729 "antimony.tab.cpp"
    break;

  case 83: /* modulepart: variablein  */
#line 393 "antimony.ypp"
                           {}
#line 2735 "antimony.tab.cpp"
    break;

  case 84: /* modulepart: constraint lineend  */
#line 394 "antimony.ypp"
                                   {}
#line 2741 "antimony.tab.cpp"
    break;

  case 85: /* modulepart: objective lineend  */
#line 395 "antimony.ypp"
                                  {}
#line 2747 "antimony.tab.cpp"
    break;

  case 86: /* modulepart: algrule lineend  */
#line 396 "antimony.ypp"
                                {}
#line 2753 "antimony.tab.cpp"
    break;

  case 87: /* modulepart: lineend  */
#line 397 "antimony.ypp"
                        {}
#line 2759 "antimony.tab.cpp"
    break;

  case 88: /* reaction: varmaybein ':' reactantList reactionDivider reactantList ';' formula maybein  */
#line 401 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-7].variable), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-7].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2771 "antimony.tab.cpp"
    break;

  case 89: /* reaction: reactantList reactionDivider reactantList ';' formula maybein  */
#line 409 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2783 "antimony.tab.cpp"
    break;

  case 90: /* reaction: reactantList reactionDivider ';' formula maybein  */
#line 417 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2795 "antimony.tab.cpp"
    break;

  case 91: /* reaction: varmaybein ':' reactantList reactionDivider ';' formula maybein  */
#line 425 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2807 "antimony.tab.cpp"
    break;

  case 92: /* reaction: reactionDivider reactantList ';' formula maybein  */
#line 433 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2819 "antimony.tab.cpp"
    break;

  case 93: /* reaction: varmaybein ':' reactionDivider reactantList ';' formula maybein  */
#line 441 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2831 "antimony.tab.cpp"
    break;

  case 94: /* reactantList: variable  */
#line 450 "antimony.ypp"
                         {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2837 "antimony.tab.cpp"
    break;

  case 95: /* reactantList: "number" variable  */
#line 451 "antimony.ypp"
                             {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2843 "antimony.tab.cpp"
    break;

  case 96: /* reactantList: variable variable  */
#line 452 "antimony.ypp"
                                  {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2849 "antimony.tab.cpp"
    break;

  case 97: /* reactantList: reactantList '+' variable  */
#line 453 "antimony.ypp"
                                          {(yyval.reactantList) = (yyvsp[-2].reactantList); if((yyvsp[-2].reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2855 "antimony.tab.cpp"
    break;

  case 98: /* reactantList: reactantList '+' "number" variable  */
#line 454 "antimony.ypp"
                                              {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2861 "antimony.tab.cpp"
    break;

  case 99: /* reactantList: reactantList '+' variable variable  */
#line 455 "antimony.ypp"
                                                   {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2867 "antimony.tab.cpp"
    break;

  case 100: /* reactionDivider: "->"  */
#line 459 "antimony.ypp"
                           {(yyval.reactionDivider) = rdBecomes;}
#line 2873 "antimony.tab.cpp"
    break;

  case 101: /* reactionDivider: "-|"  */
#line 460 "antimony.ypp"
                           {(yyval.reactionDivider) = rdInhibits;}
#line 2879 "antimony.tab.cpp"
    break;

  case 102: /* reactionDivider: '-' '('  */
#line 461 "antimony.ypp"
                        {(yyval.reactionDivider) = rdInfluences;}
#line 2885 "antimony.tab.cpp"
    break;

  case 103: /* reactionDivider: "-o"  */
#line 462 "antimony.ypp"
                           {(yyval.reactionDivider) = rdActivates;}
#line 2891 "antimony.tab.cpp"
    break;

  case 104: /* reactionDivider: "=>"  */
#line 463 "antimony.ypp"
                             {(yyval.reactionDivider) = rdBecomesIrreversibly;}
#line 2897 "antimony.tab.cpp"
    break;

  case 105: /* formula: %empty  */
#line 466 "antimony.ypp"
                            {(yyval.formula) = g_registry.NewBlankFormula(); }
#line 2903 "antimony.tab.cpp"
    break;

  case 106: /* formula: formula "..."  */
#line 467 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddEllipses();}
#line 2909 "antimony.tab.cpp"
    break;

  case 107: /* formula: formula variable  */
#line 468 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); if((yyvsp[-1].formula)->AddVariable((yyvsp[0].variable))) YYABORT; }
#line 2915 "antimony.tab.cpp"
    break;

  case 108: /* formula: formula "number"  */
#line 469 "antimony.ypp"
                             {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddNum((yyvsp[0].num)); }
#line 2921 "antimony.tab.cpp"
    break;

  case 109: /* formula: formula "name of a pre-defined constant"  */
#line 470 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2927 "antimony.tab.cpp"
    break;

  case 110: /* formula: formula "name of an existing function"  */
#line 471 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2933 "antimony.tab.cpp"
    break;

  case 111: /* formula: formula '(' commaformula ')'  */
#line 472 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2939 "antimony.tab.cpp"
    break;

  case 112: /* formula: formula '{' commaformula '}'  */
#line 473 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddCurlyBrackets(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2945 "antimony.tab.cpp"
    break;

  case 113: /* formula: formula mathThing  */
#line 474 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddMathThing((yyvsp[0].character)); }
#line 2951 "antimony.tab.cpp"
    break;

  case 114: /* formula: formula inequality  */
#line 475 "antimony.ypp"
                                   {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddInequality((yyvsp[0].inequality)); }
#line 2957 "antimony.tab.cpp"
    break;

  case 115: /* formula: formula '=' '='  */
#line 476 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('='); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2963 "antimony.tab.cpp"
    break;

  case 116: /* formula: formula '&' '&'  */
#line 477 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('&'); (yyvsp[-2].formula)->AddMathThing('&'); }
#line 2969 "antimony.tab.cpp"
    break;

  case 117: /* formula: formula '|' '|'  */
#line 478 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('|'); (yyvsp[-2].formula)->AddMathThing('|'); }
#line 2975 "antimony.tab.cpp"
    break;

  case 118: /* formula: formula "text string"  */
#line 479 "antimony.ypp"
                                   {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word), true); }
#line 2981 "antimony.tab.cpp"
    break;

  case 119: /* commaformula: formula  */
#line 482 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2987 "antimony.tab.cpp"
    break;

  case 120: /* commaformula: commaformula ',' formula  */
#line 483 "antimony.ypp"
                                         {(yyval.formula) = (yyvsp[-2].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[0].formula)); }
#line 2993 "antimony.tab.cpp"
    break;

  case 121: /* mathThing: '+'  */
#line 486 "antimony.ypp"
                    {(yyval.character) = '+';}
#line 2999 "antimony.tab.cpp"
    break;

  case 122: /* mathThing: '-'  */
#line 487 "antimony.ypp"
                    {(yyval.character) = '-';}
#line 3005 "antimony.tab.cpp"
    break;

  case 123: /* mathThing: '*'  */
#line 488 "antimony.ypp"
                    {(yyval.character) = '*';}
#line 3011 "antimony.tab.cpp"
    break;

  case 124: /* mathThing: '/'  */
#line 489 "antimony.ypp"
                    {(yyval.character) = '/';}
#line 3017 "antimony.tab.cpp"
    break;

  case 125: /* mathThing: '^'  */
#line 490 "antimony.ypp"
                    {(yyval.character) = '^';}
#line 3023 "antimony.tab.cpp"
    break;

  case 126: /* mathThing: '!'  */
#line 491 "antimony.ypp"
                    {(yyval.character) = '!';}
#line 3029 "antimony.tab.cpp"
    break;

  case 127: /* mathThing: '%'  */
#line 492 "antimony.ypp"
                    {(yyval.character) = '%';}
#line 3035 "antimony.tab.cpp"
    break;

  case 128: /* inequality: '<'  */
#line 495 "antimony.ypp"
                    {(yyval.inequality) = constLT;}
#line 3041 "antimony.tab.cpp"
    break;

  case 129: /* inequality: "<="  */
#line 496 "antimony.ypp"
                    {(yyval.inequality) = constLEQ;}
#line 3047 "antimony.tab.cpp"
    break;

  case 130: /* inequality: '>'  */
#line 497 "antimony.ypp"
                    {(yyval.inequality) = constGT;}
#line 3053 "antimony.tab.cpp"
    break;

  case 131: /* inequality: ">="  */
#line 498 "antimony.ypp"
                    {(yyval.inequality) = constGEQ;}
#line 3059 "antimony.tab.cpp"
    break;

  case 132: /* inequality: "!="  */
#line 499 "antimony.ypp"
                    {(yyval.inequality) = constNEQ;}
#line 3065 "antimony.tab.cpp"
    break;

  case 133: /* lineend: ';'  */
#line 502 "antimony.ypp"
                    {}
#line 3071 "antimony.tab.cpp"
    break;

  case 134: /* lineend: '\n'  */
#line 503 "antimony.ypp"
                     {}
#line 3077 "antimony.tab.cpp"
    break;

  case 135: /* lineend: "end of line"  */
#line 504 "antimony.ypp"
                    {}
#line 3083 "antimony.tab.cpp"
    break;

  case 136: /* assignment: varmaybein ':' maxormin formula  */
#line 507 "antimony.ypp"
                                                {if (g_registry.CurrentModule()->AddObjective((yyvsp[-3].variable), (yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 3089 "antimony.tab.cpp"
    break;

  case 137: /* assignment: varmaybein '=' formula  */
#line 508 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 3095 "antimony.tab.cpp"
    break;

  case 138: /* assignment: varmaybein "'is'" variable  */
#line 509 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->Synchronize((yyvsp[0].variable), NULL)) YYABORT;}
#line 3101 "antimony.tab.cpp"
    break;

  case 139: /* assignment: varmaybein "'is'" variable '/' variable  */
#line 510 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[-2].variable), (yyvsp[0].variable))) YYABORT;}
#line 3107 "antimony.tab.cpp"
    break;

  case 140: /* assignment: varmaybein '*' variable "'is'" variable  */
#line 511 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[0].variable), (yyvsp[-2].variable))) YYABORT;}
#line 3113 "antimony.tab.cpp"
    break;

  case 141: /* assignment: varmaybein "'is'" "text string"  */
#line 512 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetDisplayName(*((yyvsp[0].word)))) YYABORT;}
#line 3119 "antimony.tab.cpp"
    break;

  case 142: /* assignment: varmaybein ':' '=' formula  */
#line 513 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT;}
#line 3125 "antimony.tab.cpp"
    break;

  case 143: /* assignment: varmaybein '\'' '=' formula  */
#line 514 "antimony.ypp"
                                            {if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT;}
#line 3131 "antimony.tab.cpp"
    break;

  case 144: /* assignment: varmaybein "'has'" unitdef  */
#line 515 "antimony.ypp"
                                           {if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 3137 "antimony.tab.cpp"
    break;

  case 145: /* algrule: "number" '=' formula  */
#line 518 "antimony.ypp"
                                {if (g_registry.AddNewAlgebraicRuleToCurrent((yyvsp[-2].num), (yyvsp[0].formula))) YYABORT; }
#line 3143 "antimony.tab.cpp"
    break;

  case 146: /* algrule: varmaybein ':' "number" '=' formula  */
#line 519 "antimony.ypp"
                                               {if ((yyvsp[-4].variable)->SetAlgebraicRule((yyvsp[-2].num), (yyvsp[0].formula)) ) YYABORT;}
#line 3149 "antimony.tab.cpp"
    break;

  case 147: /* $@6: %empty  */
#line 522 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetModule((yyvsp[-1].word))) YYABORT;}
#line 3155 "antimony.tab.cpp"
    break;

  case 148: /* submodule: varmaybein ':' "name of an existing module" '(' $@6 variableimportlist ')' submodifications maybein  */
#line 522 "antimony.ypp"
                                                                                                                             {if ((yyvsp[0].variable) != NULL) {if ((yyvsp[-8].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 3161 "antimony.tab.cpp"
    break;

  case 149: /* $@7: %empty  */
#line 523 "antimony.ypp"
                            {if(g_registry.CurrentModule()->SetModule((yyvsp[-1].word))) YYABORT;}
#line 3167 "antimony.tab.cpp"
    break;

  case 150: /* submodule: "name of an existing module" '(' $@7 variableimportlist ')' submodifications maybein  */
#line 523 "antimony.ypp"
                                                                                                                                     {if ((yyvsp[0].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 3173 "antimony.tab.cpp"
    break;

  case 151: /* variableimportlist: %empty  */
#line 527 "antimony.ypp"
                            {}
#line 3179 "antimony.tab.cpp"
    break;

  case 152: /* variableimportlist: variable  */
#line 528 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 3185 "antimony.tab.cpp"
    break;

  case 153: /* variableimportlist: variableimportlist ',' variable  */
#line 529 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 3191 "antimony.tab.cpp"
    break;

  case 154: /* variableimportlist: "number"  */
#line 530 "antimony.ypp"
                    {if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 3197 "antimony.tab.cpp"
    break;

  case 155: /* variableimportlist: variableimportlist ',' "number"  */
#line 531 "antimony.ypp"
                                           { if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 3203 "antimony.tab.cpp"
    break;

  case 156: /* submodifications: %empty  */
#line 535 "antimony.ypp"
                            {}
#line 3209 "antimony.tab.cpp"
    break;

  case 157: /* submodifications: submodifications ',' "element name" '=' variable  */
#line 536 "antimony.ypp"
                                                          {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].variable));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 3217 "antimony.tab.cpp"
    break;

  case 158: /* submodifications: submodifications ',' "element name" '=' "number"  */
#line 540 "antimony.ypp"
                                                     {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].num));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 3225 "antimony.tab.cpp"
    break;

  case 159: /* varinitialize: specinit  */
#line 544 "antimony.ypp"
                         { }
#line 3231 "antimony.tab.cpp"
    break;

  case 160: /* varinitialize: formulainit  */
#line 545 "antimony.ypp"
                            { }
#line 3237 "antimony.tab.cpp"
    break;

  case 161: /* varinitialize: reactioninit  */
#line 546 "antimony.ypp"
                             { }
#line 3243 "antimony.tab.cpp"
    break;

  case 162: /* varinitialize: dnainit  */
#line 547 "antimony.ypp"
                        { }
#line 3249 "antimony.tab.cpp"
    break;

  case 163: /* varinitialize: geneinit  */
#line 548 "antimony.ypp"
                         { }
#line 3255 "antimony.tab.cpp"
    break;

  case 164: /* varinitialize: geneProductInit  */
#line 549 "antimony.ypp"
                                { }
#line 3261 "antimony.tab.cpp"
    break;

  case 165: /* varinitialize: operatorinit  */
#line 550 "antimony.ypp"
                             { }
#line 3267 "antimony.tab.cpp"
    break;

  case 166: /* varinitialize: compartmentinit  */
#line 551 "antimony.ypp"
                                { }
#line 3273 "antimony.tab.cpp"
    break;

  case 167: /* varinitialize: varconstinit  */
#line 552 "antimony.ypp"
                             { }
#line 3279 "antimony.tab.cpp"
    break;

  case 168: /* specinit: "'species'" varmaybeis  */
#line 555 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3285 "antimony.tab.cpp"
    break;

  case 169: /* specinit: "'var'" "'species'" varmaybeis  */
#line 556 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3291 "antimony.tab.cpp"
    break;

  case 170: /* specinit: "'const'" "'species'" varmaybeis  */
#line 557 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3297 "antimony.tab.cpp"
    break;

  case 171: /* specinit: "'substanceOnly'" "'species'" varmaybeis  */
#line 558 "antimony.ypp"
                                             {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3303 "antimony.tab.cpp"
    break;

  case 172: /* specinit: "'substanceOnly'" varmaybeis  */
#line 559 "antimony.ypp"
                                     {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3309 "antimony.tab.cpp"
    break;

  case 173: /* specinit: "'var'" "'substanceOnly'" "'species'" varmaybeis  */
#line 560 "antimony.ypp"
                                                     {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3315 "antimony.tab.cpp"
    break;

  case 174: /* specinit: "'const'" "'substanceOnly'" "'species'" varmaybeis  */
#line 561 "antimony.ypp"
                                                       {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3321 "antimony.tab.cpp"
    break;

  case 175: /* specinit: specinit ',' varmaybeis  */
#line 562 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3327 "antimony.tab.cpp"
    break;

  case 176: /* specinit: "'species'" '.' "element name" '=' formula  */
#line 563 "antimony.ypp"
                                                {if (g_registry.CurrentModule()->AddSpeciesLayoutInfo((yyvsp[-2].word), (yyvsp[0].formula))) YYABORT;}
#line 3333 "antimony.tab.cpp"
    break;

  case 177: /* geneProductInit: "'geneProduct'" varmaybeis  */
#line 566 "antimony.ypp"
                                              {if ((yyvsp[0].variable)->SetType(varGeneProduct)) YYABORT; }
#line 3339 "antimony.tab.cpp"
    break;

  case 178: /* geneProductInit: geneProductInit ',' varmaybeis  */
#line 567 "antimony.ypp"
                                                      {if ((yyvsp[0].variable)->SetType(varGeneProduct)) YYABORT;}
#line 3345 "antimony.tab.cpp"
    break;

  case 179: /* formulainit: "'formula'" varmaybeis  */
#line 569 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3351 "antimony.tab.cpp"
    break;

  case 180: /* formulainit: "'var'" "'formula'" varmaybeis  */
#line 570 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3357 "antimony.tab.cpp"
    break;

  case 181: /* formulainit: "'const'" "'formula'" varmaybeis  */
#line 571 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3363 "antimony.tab.cpp"
    break;

  case 182: /* formulainit: formulainit ',' varmaybeis  */
#line 572 "antimony.ypp"
                                           {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3369 "antimony.tab.cpp"
    break;

  case 183: /* reactioninit: "'reaction'" varmaybeis  */
#line 575 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3375 "antimony.tab.cpp"
    break;

  case 184: /* reactioninit: "'var'" "'reaction'" varmaybeis  */
#line 576 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3381 "antimony.tab.cpp"
    break;

  case 185: /* reactioninit: "'const'" "'reaction'"  */
#line 577 "antimony.ypp"
                                   {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; }
#line 3387 "antimony.tab.cpp"
    break;

  case 186: /* reactioninit: reactioninit ',' varmaybeis  */
#line 578 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3393 "antimony.tab.cpp"
    break;

  case 187: /* reactioninit: "'reaction'" '.' "element name" '=' formula  */
#line 579 "antimony.ypp"
                                                 {if (g_registry.CurrentModule()->AddReactionLayoutInfo((yyvsp[-2].word), (yyvsp[0].formula))) YYABORT;}
#line 3399 "antimony.tab.cpp"
    break;

  case 188: /* dnainit: "'DNA'" varmaybeis  */
#line 582 "antimony.ypp"
                               {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3405 "antimony.tab.cpp"
    break;

  case 189: /* dnainit: "'var'" "'DNA'" varmaybeis  */
#line 583 "antimony.ypp"
                                       {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3411 "antimony.tab.cpp"
    break;

  case 190: /* dnainit: "'const'" "'DNA'" varmaybeis  */
#line 584 "antimony.ypp"
                                         {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3417 "antimony.tab.cpp"
    break;

  case 191: /* dnainit: dnainit ',' varmaybeis  */
#line 585 "antimony.ypp"
                                       {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3423 "antimony.tab.cpp"
    break;

  case 192: /* geneinit: "'gene'" varmaybeis  */
#line 588 "antimony.ypp"
                                {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3429 "antimony.tab.cpp"
    break;

  case 193: /* geneinit: "'var'" "'gene'" varmaybeis  */
#line 589 "antimony.ypp"
                                        {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3435 "antimony.tab.cpp"
    break;

  case 194: /* geneinit: "'const'" "'gene'" varmaybeis  */
#line 590 "antimony.ypp"
                                          {g_registry.SetError("Genes may not be set 'const'."); YYABORT; }
#line 3441 "antimony.tab.cpp"
    break;

  case 195: /* geneinit: geneinit ',' varmaybeis  */
#line 591 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3447 "antimony.tab.cpp"
    break;

  case 196: /* operatorinit: "'operator'" varmaybeis  */
#line 594 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3453 "antimony.tab.cpp"
    break;

  case 197: /* operatorinit: "'var'" "'operator'" varmaybeis  */
#line 595 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3459 "antimony.tab.cpp"
    break;

  case 198: /* operatorinit: "'const'" "'operator'" varmaybeis  */
#line 596 "antimony.ypp"
                                              {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3465 "antimony.tab.cpp"
    break;

  case 199: /* operatorinit: operatorinit ',' varmaybeis  */
#line 597 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3471 "antimony.tab.cpp"
    break;

  case 200: /* compartmentinit: "'compartment'" varmaybeis  */
#line 601 "antimony.ypp"
                                       {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3477 "antimony.tab.cpp"
    break;

  case 201: /* compartmentinit: "'var'" "'compartment'" varmaybeis  */
#line 602 "antimony.ypp"
                                               {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3483 "antimony.tab.cpp"
    break;

  case 202: /* compartmentinit: "'const'" "'compartment'" varmaybeis  */
#line 603 "antimony.ypp"
                                                 {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3489 "antimony.tab.cpp"
    break;

  case 203: /* compartmentinit: compartmentinit ',' varmaybeis  */
#line 604 "antimony.ypp"
                                               {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3495 "antimony.tab.cpp"
    break;

  case 204: /* compartmentinit: "'compartment'" '.' "element name" '=' formula  */
#line 605 "antimony.ypp"
                                                    {if (g_registry.CurrentModule()->AddCompartmentLayoutInfo((yyvsp[-2].word), (yyvsp[0].formula))) YYABORT;}
#line 3501 "antimony.tab.cpp"
    break;

  case 205: /* varconstinit: "'var'" varmaybeis  */
#line 608 "antimony.ypp"
                                   {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst();}
#line 3507 "antimony.tab.cpp"
    break;

  case 206: /* varconstinit: "'const'" varmaybeis  */
#line 609 "antimony.ypp"
                                     {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst();}
#line 3513 "antimony.tab.cpp"
    break;

  case 207: /* varconstinit: varconstinit ',' varmaybeis  */
#line 610 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst();}
#line 3519 "antimony.tab.cpp"
    break;

  case 208: /* unitinit: "'unit'" variable '=' formula  */
#line 613 "antimony.ypp"
                                              {if ((yyvsp[-2].variable)->SetType(varUnitDefinition)) YYABORT;
                                               if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                                               if ((yyvsp[-2].variable)->GetUnitDef()->SetFromFormula((yyvsp[0].formula))) YYABORT;}
#line 3527 "antimony.tab.cpp"
    break;

  case 209: /* unitinit: "'unit'" variable  */
#line 616 "antimony.ypp"
                                  {if ((yyvsp[0].variable)->SetType(varUnitDefinition)) YYABORT;}
#line 3533 "antimony.tab.cpp"
    break;

  case 210: /* dnadef: dnastrand  */
#line 619 "antimony.ypp"
                          {if (g_registry.SaveWorkingStrand()) YYABORT;}
#line 3539 "antimony.tab.cpp"
    break;

  case 211: /* dnadef: varmaybein ':' dnastrand  */
#line 620 "antimony.ypp"
                                         {if (g_registry.SetStrandAs((yyvsp[-2].variable))) YYABORT;}
#line 3545 "antimony.tab.cpp"
    break;

  case 212: /* dnastrand: "--" variable  */
#line 623 "antimony.ypp"
                                {if (g_registry.SetNewUpstreamOpen((yyvsp[0].variable))) YYABORT;}
#line 3551 "antimony.tab.cpp"
    break;

  case 213: /* dnastrand: "--" dnamiddle  */
#line 624 "antimony.ypp"
                                 {g_registry.SetOpenUpstream(); }
#line 3557 "antimony.tab.cpp"
    break;

  case 214: /* dnastrand: dnamiddle variable  */
#line 625 "antimony.ypp"
                                   {if (g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3563 "antimony.tab.cpp"
    break;

  case 215: /* dnastrand: "--" dnamiddle variable  */
#line 626 "antimony.ypp"
                                          {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3569 "antimony.tab.cpp"
    break;

  case 216: /* dnastrand: dnamiddle  */
#line 627 "antimony.ypp"
                          { }
#line 3575 "antimony.tab.cpp"
    break;

  case 217: /* dnamiddle: variable "--"  */
#line 630 "antimony.ypp"
                                {if (g_registry.SetNewDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3581 "antimony.tab.cpp"
    break;

  case 218: /* dnamiddle: dnamiddle variable "--"  */
#line 631 "antimony.ypp"
                                          {if (g_registry.SetDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3587 "antimony.tab.cpp"
    break;

  case 219: /* $@8: %empty  */
#line 634 "antimony.ypp"
                           {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula))) YYABORT;}
#line 3593 "antimony.tab.cpp"
    break;

  case 220: /* event: "'at'" formula $@8 eventmodifications colonret assignmentlist  */
#line 634 "antimony.ypp"
                                                                                                                        {}
#line 3599 "antimony.tab.cpp"
    break;

  case 221: /* $@9: %empty  */
#line 635 "antimony.ypp"
                                         {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula))) YYABORT;}
#line 3605 "antimony.tab.cpp"
    break;

  case 222: /* event: "'at'" formula "'after'" formula $@9 eventmodifications colonret assignmentlist  */
#line 635 "antimony.ypp"
                                                                                                                                          {}
#line 3611 "antimony.tab.cpp"
    break;

  case 223: /* $@10: %empty  */
#line 636 "antimony.ypp"
                                          {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula), (yyvsp[-3].variable))) YYABORT;}
#line 3617 "antimony.tab.cpp"
    break;

  case 224: /* event: varmaybein ':' "'at'" formula $@10 eventmodifications colonret assignmentlist  */
#line 636 "antimony.ypp"
                                                                                                                                            {}
#line 3623 "antimony.tab.cpp"
    break;

  case 225: /* $@11: %empty  */
#line 637 "antimony.ypp"
                                                        {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula), (yyvsp[-5].variable))) YYABORT;}
#line 3629 "antimony.tab.cpp"
    break;

  case 226: /* event: varmaybein ':' "'at'" formula "'after'" formula $@11 eventmodifications colonret assignmentlist  */
#line 637 "antimony.ypp"
                                                                                                                                                             {}
#line 3635 "antimony.tab.cpp"
    break;

  case 227: /* colonret: ':'  */
#line 640 "antimony.ypp"
                    {}
#line 3641 "antimony.tab.cpp"
    break;

  case 228: /* colonret: colonret '\n'  */
#line 641 "antimony.ypp"
                              {}
#line 3647 "antimony.tab.cpp"
    break;

  case 229: /* eventmodifications: %empty  */
#line 644 "antimony.ypp"
                                 {}
#line 3653 "antimony.tab.cpp"
    break;

  case 230: /* eventmodifications: eventmodifications ',' "element name" '=' formula  */
#line 645 "antimony.ypp"
                                                           {if (CaselessStrCmp(false, *(yyvsp[-2].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[0].formula));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[0].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;}}
#line 3663 "antimony.tab.cpp"
    break;

  case 231: /* assignmentlist: variable '=' formula  */
#line 652 "antimony.ypp"
                                     {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3669 "antimony.tab.cpp"
    break;

  case 232: /* assignmentlist: variable '=' formula ':' assignmentlist  */
#line 653 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3675 "antimony.tab.cpp"
    break;

  case 233: /* assignmentlist: variable '=' formula ':' '\n' assignmentlist  */
#line 654 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3681 "antimony.tab.cpp"
    break;

  case 234: /* assignmentlist: variable '=' formula ',' assignmentlist  */
#line 655 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3687 "antimony.tab.cpp"
    break;

  case 235: /* assignmentlist: variable '=' formula ',' '\n' assignmentlist  */
#line 656 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3693 "antimony.tab.cpp"
    break;

  case 236: /* deletion: "'delete'" variable  */
#line 659 "antimony.ypp"
                                    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3699 "antimony.tab.cpp"
    break;

  case 237: /* deletion: deletion ',' variable  */
#line 660 "antimony.ypp"
                                      {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3705 "antimony.tab.cpp"
    break;

  case 238: /* unitdef: formula  */
#line 663 "antimony.ypp"
                        {
                    if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                    if ((yyvsp[0].formula)->IsSingleVariable()) {
                      (yyval.variable) = g_registry.CurrentModule()->GetVariable(((yyvsp[0].formula)->GetVariableStrings())[0]);
                      if ((yyval.variable)==NULL) YYABORT;
                    }
                    else {
                      UnitDef ud("", g_registry.CurrentModule()->GetModuleName());
                      if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                      if (ud.SetFromFormula((yyvsp[0].formula))) YYABORT;
                      (yyval.variable) = g_registry.CurrentModule()->AddOrFindUnitDef(ud);
                    }
                }
#line 3723 "antimony.tab.cpp"
    break;

  case 239: /* constraint: "number" inequality formula  */
#line 678 "antimony.ypp"
                                       {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3729 "antimony.tab.cpp"
    break;

  case 240: /* constraint: '-' "number" inequality formula  */
#line 679 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint(-(yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3735 "antimony.tab.cpp"
    break;

  case 241: /* constraint: "name of a pre-defined constant" inequality formula  */
#line 680 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3741 "antimony.tab.cpp"
    break;

  case 242: /* constraint: "element name" inequality formula  */
#line 681 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3747 "antimony.tab.cpp"
    break;

  case 243: /* constraint: "'constraint'" ':' formula  */
#line 682 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[0].formula))) YYABORT;}
#line 3753 "antimony.tab.cpp"
    break;

  case 244: /* constraint: "'constraint'" variable ':' formula  */
#line 683 "antimony.ypp"
                                                    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3759 "antimony.tab.cpp"
    break;

  case 245: /* objective: maxormin formula  */
#line 686 "antimony.ypp"
                                              {if (g_registry.CurrentModule()->AddObjective((yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 3765 "antimony.tab.cpp"
    break;

  case 246: /* maxormin: "'maximize'"  */
#line 689 "antimony.ypp"
                             {(yyval.maxormin) = true;}
#line 3771 "antimony.tab.cpp"
    break;

  case 247: /* maxormin: "'minimize'"  */
#line 690 "antimony.ypp"
                             {(yyval.maxormin) = false;}
#line 3777 "antimony.tab.cpp"
    break;

  case 248: /* stringlist: "text string"  */
#line 693 "antimony.ypp"
                           { (yyval.stringlist) = new std::vector<std::string>(); (yyval.stringlist)->push_back(*((yyvsp[0].word))); }
#line 3783 "antimony.tab.cpp"
    break;

  case 249: /* stringlist: stringlist ',' "text string"  */
#line 694 "antimony.ypp"
                                          { (yyval.stringlist) = (yyvsp[-2].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3789 "antimony.tab.cpp"
    break;

  case 250: /* stringlist: stringlist ',' '\n' "text string"  */
#line 695 "antimony.ypp"
                                               { (yyval.stringlist) = (yyvsp[-3].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3795 "antimony.tab.cpp"
    break;

  case 251: /* $@12: %empty  */
#line 697 "antimony.ypp"
                                    {if (g_registry.SetCurrentModuleIf((yyvsp[0].word), (yyvsp[-1].word))) YYABORT;}
#line 3801 "antimony.tab.cpp"
    break;

  case 252: /* annotationBlock: "element name" "name of an existing module" $@12 annotations "'end'"  */
#line 697 "antimony.ypp"
                                                                                                          {g_registry.RevertToPreviousModule();}
#line 3807 "antimony.tab.cpp"
    break;

  case 253: /* annotations: %empty  */
#line 700 "antimony.ypp"
                            {}
#line 3813 "antimony.tab.cpp"
    break;

  case 254: /* annotations: "element name" ':' stringlist  */
#line 701 "antimony.ypp"
                                       {string modname = g_registry.CurrentModuleName(); g_registry.ProcessGlobalCVTerm(&modname, (yyvsp[-2].word), (yyvsp[0].stringlist));}
#line 3819 "antimony.tab.cpp"
    break;

  case 255: /* cvterm: variable "element name" stringlist  */
#line 706 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->ProcessCVTerm((yyvsp[-2].variable),(yyvsp[-1].word),(yyvsp[0].stringlist))) YYABORT;}
#line 3825 "antimony.tab.cpp"
    break;

  case 256: /* cvterm: variable "element name" '.' "element name" stringlist  */
#line 707 "antimony.ypp"
                                                        {if (g_registry.ProcessCreatorTerm((yyvsp[-4].variable), (yyvsp[-3].word), (yyvsp[-1].word), (yyvsp[0].stringlist))) YYABORT;}
#line 3831 "antimony.tab.cpp"
    break;

  case 257: /* cvterm: variable "element name" '.' "element name" "number"  */
#line 708 "antimony.ypp"
                                                 {if (g_registry.ProcessCreatorTerm((yyvsp[-4].variable), (yyvsp[-3].word), (yyvsp[-1].word), (yyvsp[0].num))) YYABORT;}
#line 3837 "antimony.tab.cpp"
    break;

  case 258: /* toplevel_sbo: "name of an existing module" '.' "element name" '=' "number"  */
#line 712 "antimony.ypp"
                  { Module* module = g_registry.GetModule(*(yyvsp[-4].word));
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      module->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3851 "antimony.tab.cpp"
    break;

  case 259: /* toplevel_sbo: "name of an existing function" '.' "element name" '=' "number"  */
#line 723 "antimony.ypp"
                  { Module* function = g_registry.GetModule(*(yyvsp[-4].word));
                    if (function && (yyvsp[-2].word) &&  CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      function->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can set '" + *((yyvsp[-4].word)) + "' to a number is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3865 "antimony.tab.cpp"
    break;

  case 260: /* toplevel_sbo: "name of an existing module" '.' "element name" '=' stringConstant  */
#line 733 "antimony.ypp"
                  { Module* function = g_registry.GetModule(*(yyvsp[-4].word));
                    if (function && (yyvsp[-2].word) &&  CaselessStrCmp(true, *((yyvsp[-2].word)), "autolayout")) {
                      if (function->SetLayout((yyvsp[0].word))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can set on '" + *((yyvsp[-4].word)) + "' to a string is 'layout'.");
                      YYABORT;
                    }
                  }
#line 3879 "antimony.tab.cpp"
    break;

  case 261: /* toplevel_sbo: "name of an existing module" '.' "element name" '.' "element name" '=' "number"  */
#line 743 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-4].word) && CaselessStrCmp(true, *((yyvsp[-4].word)), "autolayout")) {
                      if (module->SetAutoLayout((yyvsp[-2].word), (yyvsp[0].num))) YYABORT;
                    }
                    else if (module && (yyvsp[-4].word) && CaselessStrCmp(true, *((yyvsp[-4].word)), "layout")) {
                      if (module->SetLayout((yyvsp[-2].word), (yyvsp[0].num))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-4].word)) + "'.*:  The core word here must be 'layout' or 'autolayout'.");
                      YYABORT;
                    }
                    module->SetLayout("on");
                  }
#line 3897 "antimony.tab.cpp"
    break;

  case 262: /* toplevel_sbo: "name of an existing module" '.' "element name" '.' "element name" '=' stringConstant  */
#line 757 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-4].word) && CaselessStrCmp(true, *((yyvsp[-4].word)), "autolayout")) {
                      if (module->SetAutoLayout((yyvsp[-2].word), (yyvsp[0].word))) YYABORT;
                    }
                    else if (module && (yyvsp[-4].word) && CaselessStrCmp(true, *((yyvsp[-4].word)), "layout")) {
                      if (module->SetLayout((yyvsp[-2].word), (yyvsp[0].word))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-4].word)) + "'.*:  The core word here must be 'layout' or 'autolayout'.");
                      YYABORT;
                    }
                    module->SetLayout("on");
                  }
#line 3915 "antimony.tab.cpp"
    break;

  case 263: /* toplevel_sbo: "name of an existing module" '.' "element name" '.' "element name" '=' '{' variablelist '}'  */
#line 771 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-6].word) && CaselessStrCmp(true, *((yyvsp[-6].word)), "autolayout")) {
                      if (module->SetAutoLayout((yyvsp[-4].word), (yyvsp[-1].variablelist))) YYABORT;
                    }
                    else if (module && (yyvsp[-6].word) && CaselessStrCmp(true, *((yyvsp[-6].word)), "layout")) {
                      if (module->SetLayout((yyvsp[-4].word), (yyvsp[-1].variablelist))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-6].word)) + "'.*:  The core word here must be 'layout' or 'autolayout'.");
                      YYABORT;
                    }
                    module->SetLayout("on");
                  }
#line 3933 "antimony.tab.cpp"
    break;

  case 264: /* toplevel_sbo: "name of an existing module" '.' "element name" '.' "element name" '=' '{' numlist '}'  */
#line 785 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-6].word) && CaselessStrCmp(true, *((yyvsp[-6].word)), "autolayout")) {
                      if (module->SetAutoLayout((yyvsp[-4].word), (yyvsp[-1].numlist))) YYABORT;
                    }
                    else if (module && (yyvsp[-6].word) && CaselessStrCmp(true, *((yyvsp[-6].word)), "layout")) {
                      if (module->SetLayout((yyvsp[-4].word), (yyvsp[-1].numlist))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-6].word)) + "'.*:  The core word here must be 'layout' or 'autolayout'.");
                      YYABORT;
                    }
                    module->SetLayout("on");
                  }
#line 3951 "antimony.tab.cpp"
    break;

  case 265: /* modulename: "name of an existing module" "'is'" "text string" lineend  */
#line 801 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3957 "antimony.tab.cpp"
    break;

  case 266: /* functionname: "name of an existing function" "'is'" "text string" lineend  */
#line 803 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3963 "antimony.tab.cpp"
    break;

  case 267: /* modulecvterm: "name of an existing module" "element name" stringlist lineend  */
#line 806 "antimony.ypp"
                                                   {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3969 "antimony.tab.cpp"
    break;

  case 268: /* modulecvterm: "name of an existing module" "element name" '.' "element name" stringlist lineend  */
#line 807 "antimony.ypp"
                                                               {if (g_registry.ProcessGlobalCreatorTerm((yyvsp[-5].word), (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].stringlist))) YYABORT;}
#line 3975 "antimony.tab.cpp"
    break;

  case 269: /* modulecvterm: "name of an existing module" "element name" '.' "element name" "number" lineend  */
#line 808 "antimony.ypp"
                                                        {if (g_registry.ProcessGlobalCreatorTerm((yyvsp[-5].word), (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].num))) YYABORT;}
#line 3981 "antimony.tab.cpp"
    break;

  case 270: /* functioncvterm: "name of an existing function" "element name" stringlist lineend  */
#line 809 "antimony.ypp"
                                                    {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3987 "antimony.tab.cpp"
    break;


#line 3991 "antimony.tab.cpp"

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

#line 811 "antimony.ypp"



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
    // Something else went wrong!
    g_registry.SetError("Failure reading input stream in line " + DoubleToString(antimony_yylloc_last_line) + ".  Try adding a space anywhere before that line and re-running.");
    // In case knowing the following helps during debugging:
    bool eof = g_registry.input->eof();
    bool fail = g_registry.input->fail();
    bool bad = g_registry.input->bad();
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
    if (CaselessStrCmp(false, word, "geneProduct")) {
      return GENEPRODUCT;
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
        return BECOMESACT;
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
      if (cc == '\\') {
        g_registry.input->get(cc);
        textstring += cc;
        ccount++;
      }
      else {
        textstring += cc;
      }
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
