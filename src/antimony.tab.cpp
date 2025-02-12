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
  bool maxormin;
  constraint_type inequality;
  std::vector<std::string>* stringlist;
  std::vector<Variable*>* variablelist;
  std::vector<double>* numlist;

#line 236 "antimony.tab.cpp"

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
  YYSYMBOL_62_ = 62,                       /* '{'  */
  YYSYMBOL_63_ = 63,                       /* '}'  */
  YYSYMBOL_64_n_ = 64,                     /* '\n'  */
  YYSYMBOL_65_ = 65,                       /* ';'  */
  YYSYMBOL_66_ = 66,                       /* '!'  */
  YYSYMBOL_67_ = 67,                       /* '<'  */
  YYSYMBOL_68_ = 68,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_input = 70,                     /* input  */
  YYSYMBOL_import = 71,                    /* import  */
  YYSYMBOL_module = 72,                    /* module  */
  YYSYMBOL_73_1 = 73,                      /* $@1  */
  YYSYMBOL_74_2 = 74,                      /* $@2  */
  YYSYMBOL_75_3 = 75,                      /* $@3  */
  YYSYMBOL_76_4 = 76,                      /* $@4  */
  YYSYMBOL_function = 77,                  /* function  */
  YYSYMBOL_78_5 = 78,                      /* $@5  */
  YYSYMBOL_spacedformula = 79,             /* spacedformula  */
  YYSYMBOL_variableexportlist = 80,        /* variableexportlist  */
  YYSYMBOL_variable = 81,                  /* variable  */
  YYSYMBOL_variablein = 82,                /* variablein  */
  YYSYMBOL_varmaybein = 83,                /* varmaybein  */
  YYSYMBOL_varmaybeis = 84,                /* varmaybeis  */
  YYSYMBOL_maybein = 85,                   /* maybein  */
  YYSYMBOL_modulebody = 86,                /* modulebody  */
  YYSYMBOL_moduleannotation = 87,          /* moduleannotation  */
  YYSYMBOL_stringConstant = 88,            /* stringConstant  */
  YYSYMBOL_variablelist = 89,              /* variablelist  */
  YYSYMBOL_numlist = 90,                   /* numlist  */
  YYSYMBOL_modulepart = 91,                /* modulepart  */
  YYSYMBOL_reaction = 92,                  /* reaction  */
  YYSYMBOL_reactantList = 93,              /* reactantList  */
  YYSYMBOL_reactionDivider = 94,           /* reactionDivider  */
  YYSYMBOL_formula = 95,                   /* formula  */
  YYSYMBOL_commaformula = 96,              /* commaformula  */
  YYSYMBOL_mathThing = 97,                 /* mathThing  */
  YYSYMBOL_inequality = 98,                /* inequality  */
  YYSYMBOL_lineend = 99,                   /* lineend  */
  YYSYMBOL_assignment = 100,               /* assignment  */
  YYSYMBOL_algrule = 101,                  /* algrule  */
  YYSYMBOL_submodule = 102,                /* submodule  */
  YYSYMBOL_103_6 = 103,                    /* $@6  */
  YYSYMBOL_104_7 = 104,                    /* $@7  */
  YYSYMBOL_variableimportlist = 105,       /* variableimportlist  */
  YYSYMBOL_submodifications = 106,         /* submodifications  */
  YYSYMBOL_varinitialize = 107,            /* varinitialize  */
  YYSYMBOL_specinit = 108,                 /* specinit  */
  YYSYMBOL_formulainit = 109,              /* formulainit  */
  YYSYMBOL_reactioninit = 110,             /* reactioninit  */
  YYSYMBOL_dnainit = 111,                  /* dnainit  */
  YYSYMBOL_geneinit = 112,                 /* geneinit  */
  YYSYMBOL_operatorinit = 113,             /* operatorinit  */
  YYSYMBOL_compartmentinit = 114,          /* compartmentinit  */
  YYSYMBOL_varconstinit = 115,             /* varconstinit  */
  YYSYMBOL_unitinit = 116,                 /* unitinit  */
  YYSYMBOL_dnadef = 117,                   /* dnadef  */
  YYSYMBOL_dnastrand = 118,                /* dnastrand  */
  YYSYMBOL_dnamiddle = 119,                /* dnamiddle  */
  YYSYMBOL_event = 120,                    /* event  */
  YYSYMBOL_121_8 = 121,                    /* $@8  */
  YYSYMBOL_122_9 = 122,                    /* $@9  */
  YYSYMBOL_123_10 = 123,                   /* $@10  */
  YYSYMBOL_124_11 = 124,                   /* $@11  */
  YYSYMBOL_colonret = 125,                 /* colonret  */
  YYSYMBOL_eventmodifications = 126,       /* eventmodifications  */
  YYSYMBOL_assignmentlist = 127,           /* assignmentlist  */
  YYSYMBOL_deletion = 128,                 /* deletion  */
  YYSYMBOL_unitdef = 129,                  /* unitdef  */
  YYSYMBOL_constraint = 130,               /* constraint  */
  YYSYMBOL_objective = 131,                /* objective  */
  YYSYMBOL_maxormin = 132,                 /* maxormin  */
  YYSYMBOL_stringlist = 133,               /* stringlist  */
  YYSYMBOL_annotationBlock = 134,          /* annotationBlock  */
  YYSYMBOL_135_12 = 135,                   /* $@12  */
  YYSYMBOL_annotations = 136,              /* annotations  */
  YYSYMBOL_cvterm = 137,                   /* cvterm  */
  YYSYMBOL_toplevel_sbo = 138,             /* toplevel_sbo  */
  YYSYMBOL_modulename = 139,               /* modulename  */
  YYSYMBOL_functionname = 140,             /* functionname  */
  YYSYMBOL_modulecvterm = 141,             /* modulecvterm  */
  YYSYMBOL_functioncvterm = 142            /* functioncvterm  */
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
#define YYLAST   1351

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  267
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  517

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
      64,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,     2,     2,    12,    10,     4,    61,
      56,    57,     8,     7,    58,     6,    13,     9,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,    65,
      67,    59,    68,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    11,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     5,    63,     2,     2,     2,     2,
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
       0,   163,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   179,   182,   182,   188,
     188,   194,   194,   200,   200,   206,   207,   210,   210,   211,
     212,   215,   216,   217,   227,   228,   229,   232,   233,   239,
     246,   249,   252,   253,   256,   257,   258,   259,   260,   263,
     264,   267,   268,   269,   270,   273,   278,   283,   288,   298,
     308,   322,   336,   350,   366,   367,   368,   369,   371,   372,
     373,   376,   377,   378,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   397,   405,
     413,   421,   429,   437,   447,   448,   449,   450,   451,   452,
     456,   457,   458,   459,   460,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   479,
     480,   483,   484,   485,   486,   487,   488,   489,   492,   493,
     494,   495,   496,   499,   500,   501,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   515,   516,   519,   519,   520,
     520,   524,   525,   526,   527,   528,   532,   533,   537,   541,
     542,   543,   544,   545,   546,   547,   548,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   562,   563,   564,   565,
     568,   569,   570,   571,   572,   575,   576,   577,   578,   581,
     582,   583,   584,   587,   588,   589,   590,   594,   595,   596,
     597,   598,   601,   602,   603,   606,   609,   612,   613,   616,
     617,   618,   619,   620,   623,   624,   627,   627,   628,   628,
     629,   629,   630,   630,   633,   634,   637,   638,   645,   646,
     647,   648,   649,   652,   653,   656,   671,   672,   673,   674,
     675,   676,   679,   682,   683,   686,   687,   688,   690,   690,
     693,   694,   699,   700,   701,   704,   715,   725,   735,   749,
     763,   777,   793,   795,   799,   800,   801,   802
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
  "'('", "')'", "','", "'='", "':'", "'\\''", "'{'", "'}'", "'\\n'", "';'",
  "'!'", "'<'", "'>'", "$accept", "input", "import", "module", "$@1",
  "$@2", "$@3", "$@4", "function", "$@5", "spacedformula",
  "variableexportlist", "variable", "variablein", "varmaybein",
  "varmaybeis", "maybein", "modulebody", "moduleannotation",
  "stringConstant", "variablelist", "numlist", "modulepart", "reaction",
  "reactantList", "reactionDivider", "formula", "commaformula",
  "mathThing", "inequality", "lineend", "assignment", "algrule",
  "submodule", "$@6", "$@7", "variableimportlist", "submodifications",
  "varinitialize", "specinit", "formulainit", "reactioninit", "dnainit",
  "geneinit", "operatorinit", "compartmentinit", "varconstinit",
  "unitinit", "dnadef", "dnastrand", "dnamiddle", "event", "$@8", "$@9",
  "$@10", "$@11", "colonret", "eventmodifications", "assignmentlist",
  "deletion", "unitdef", "constraint", "objective", "maxormin",
  "stringlist", "annotationBlock", "$@12", "annotations", "cvterm",
  "toplevel_sbo", "modulename", "functionname", "modulecvterm",
  "functioncvterm", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-393)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-95)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -393,   681,  -393,  -393,   178,    59,  -393,   122,   259,  -393,
    -393,  -393,  -393,  -393,   292,   331,   136,   330,    59,    59,
      59,  -393,    59,   245,   313,    59,    10,  -393,  -393,   167,
     252,    59,   337,   361,   205,    59,   495,  -393,  -393,  -393,
    -393,  -393,   543,    66,   139,  -393,  -393,    23,   429,   295,
    -393,    23,    23,    23,    23,    97,   129,   182,   210,   227,
     242,   257,   267,    23,    23,  -393,    59,    23,   154,    23,
      23,  -393,  -393,    23,  -393,  -393,  -393,  -393,  -393,   331,
    -393,  -393,   250,  -393,  -393,  -393,  -393,  -393,  -393,   250,
    -393,  -393,  -393,   818,   238,   108,  -393,   343,  -393,  -393,
    -393,    37,    59,    59,    59,    59,    59,  -393,    59,   225,
    -393,   181,    59,   250,  -393,  -393,   296,   291,   312,  -393,
    -393,  -393,  -393,  -393,   355,    39,   338,  -393,   367,   378,
     172,  -393,  -393,  -393,   380,  -393,   384,  -393,    59,  -393,
      40,    59,    59,    59,    59,    59,    59,    59,   342,  -393,
     218,    43,  -393,    59,   250,    59,  -393,   199,  -393,   274,
     357,  -393,   356,   393,    65,    59,   394,     5,  -393,  -393,
    -393,  -393,    59,    59,    59,    59,    59,    59,    59,    59,
    -393,  -393,   216,  -393,    59,  -393,  -393,  -393,  1013,  -393,
    -393,  1013,  1013,   397,  1013,   418,   419,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
     359,  -393,  -393,   250,  -393,  -393,  -393,   372,  -393,  -393,
     387,   395,  1013,  1013,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,    59,   216,   398,  -393,   156,    23,   381,    73,   456,
     156,    23,   408,   396,   100,   463,   427,  1286,   156,   416,
     426,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
      59,  -393,  -393,   477,   440,   250,   235,  1013,  -393,  -393,
     353,  1013,    98,  -393,   444,  -393,   344,   429,   295,  -393,
    -393,  -393,    59,   394,  -393,     7,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,  -393,   250,  1013,   442,   473,
    -393,  -393,  1013,  1013,    71,  -393,   277,   264,  -393,  -393,
    1013,  -393,  -393,  1013,  -393,   493,   197,  -393,  -393,    59,
     496,   249,   198,  -393,  -393,  -393,   250,   376,   454,  1286,
     500,   299,   200,    59,   331,   470,   118,  1070,  -393,  -393,
    -393,  -393,  -393,  1013,  -393,   221,    59,    59,  -393,   883,
    -393,  1013,   192,    13,  1013,  1013,   250,   250,   948,  -393,
     948,   291,  -393,  -393,  -393,  -393,  -393,   510,  -393,    34,
    1013,  1013,  1013,  -393,  -393,   475,   421,   250,   471,  -393,
    -393,  -393,  -393,  -393,  -393,    23,   156,  -393,   415,    59,
    1124,   472,  -393,  -393,    23,   156,   435,   189,  -393,  -393,
    -393,  1013,  1013,  -393,   440,   250,   250,  1013,  -393,  -393,
     408,  -393,    18,  -393,    59,  -393,   948,  -393,   440,   264,
    1013,   476,  -393,   138,  -393,  -393,    23,    59,   171,  -393,
    -393,    27,  -393,   250,   439,  -393,   255,  -393,  -393,  1286,
    1013,   264,   458,   948,  -393,   948,   250,  -393,    34,  -393,
    -393,    26,  1013,    23,   250,  -393,   428,  -393,   517,  -393,
    1286,  -393,   428,  -393,  1178,  -393,    34,  -393,  -393,   948,
    -393,  -393,  1013,   753,  -393,  -393,    23,  -393,   250,   300,
     411,   478,  1232,   413,   414,  -393,   264,  -393,    27,  -393,
      50,    72,   105,  -393,    11,  -393,   441,  -393,  -393,  -393,
      34,  -393,    59,  -393,    59,  -393,    59,   250,  -393,   521,
    -393,   250,  -393,  -393,  -393,   250,  -393
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,    14,     0,     0,   135,     0,    37,   105,
     100,   101,   103,   104,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,   243,   244,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   133,     3,
       4,     6,    42,    83,     0,    13,     5,     0,     0,     0,
      87,     0,     0,     0,     0,   159,   160,   161,   162,   163,
     164,   165,   166,     0,     0,   207,   213,     0,     0,     0,
       0,   105,    12,     0,    11,     7,     8,     9,    10,     0,
     102,    37,    40,   131,   132,   129,   105,   128,   130,    95,
     105,   248,   105,   216,     0,    42,    43,    44,   197,   105,
     105,     0,     0,     0,     0,     0,     0,   182,     0,     0,
     203,   209,   210,   233,   185,   176,     0,     0,     0,    27,
      30,    29,   189,    16,     0,     0,     0,   149,     0,     0,
      19,    26,    25,   193,     0,   180,     0,   167,     0,   171,
     206,     0,     0,     0,     0,     0,     0,     0,     0,   202,
       0,    37,   214,     0,    96,     0,   105,     0,   105,     0,
       0,    74,     0,     0,     0,     0,    94,     0,    75,    86,
      76,    77,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    78,   211,    79,     0,    81,    84,    85,   242,    82,
     105,   145,   236,   250,   239,     0,     0,   122,   121,   123,
     124,   127,   125,   108,   105,   109,   106,   110,   118,   105,
       0,   105,   126,   107,   113,   114,   226,     0,   105,   105,
       0,     0,   238,   240,   105,   199,   187,   178,   191,   195,
     169,     0,   212,     0,   245,     0,     0,     0,     0,     0,
       0,     0,   151,    23,     0,     0,     0,     0,     0,     0,
       0,   170,   105,   198,   186,   177,   190,   194,   181,   168,
       0,    38,    39,     0,   252,    41,     0,   235,   144,   141,
     138,   137,     0,   105,     0,   105,    94,     0,     0,   208,
     105,   105,     0,    97,   105,     0,   105,   174,   179,   183,
     188,   192,   196,   200,   204,   215,   234,   237,     0,     0,
     116,   117,   218,   119,     0,   115,     0,     0,   105,    48,
      45,   105,   105,   241,   173,     0,     0,   267,   263,    34,
       0,     0,     0,   264,   262,   154,   152,     0,     0,     0,
       0,     0,     0,    34,    37,     0,     0,     0,    52,    51,
      55,   105,   105,   205,   172,     0,     0,     0,   105,   220,
     147,   142,     0,     0,   136,   143,    98,    99,    49,   105,
      49,     0,   249,   226,   111,   105,   112,     0,   224,     0,
     201,    46,    47,   256,   246,     0,     0,    35,     0,   255,
      66,    64,    67,    65,   257,     0,     0,   156,     0,    34,
       0,     0,    58,    59,     0,     0,     0,     0,    20,    54,
      53,   184,   175,   254,   253,   140,   139,   146,   105,   226,
     151,   105,     0,   105,     0,    90,    49,    92,   251,     0,
     120,     0,   225,     0,   217,   247,   105,     0,     0,   266,
     265,    49,   155,   153,     0,    24,     0,    57,    56,     0,
     222,     0,     0,    49,   105,    49,    50,    89,     0,   105,
     105,     0,    31,   105,    36,   258,     0,   259,     0,   150,
       0,    60,     0,    61,     0,   226,     0,   156,    91,    49,
      93,   219,   227,   228,    28,    33,    32,    71,    68,     0,
       0,     0,     0,     0,     0,    18,     0,   221,    49,    88,
       0,     0,     0,   260,     0,   261,     0,    22,    62,    63,
       0,   148,     0,   231,     0,   229,     0,    69,    72,     0,
     158,   157,   223,   232,   230,    70,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
      86,  -310,    -1,     0,     2,   489,  -350,  -327,     4,  -320,
      79,    80,     6,  -393,   -41,   -39,   329,   332,  -393,    21,
      -9,  -393,  -393,  -393,  -393,  -393,   141,    85,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,   399,
     536,  -393,  -393,  -393,  -393,  -393,  -392,  -341,  -299,  -393,
     339,  -393,  -393,   400,   -78,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    39,    40,   246,   247,   328,   329,    41,   237,
     451,   376,   213,    96,    97,    98,   415,   337,   338,   384,
     479,   480,   339,    47,    48,    49,   267,   304,   214,   215,
      50,    51,    52,    53,   410,   242,   327,   431,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,   216,   363,   409,   465,   369,   307,   424,    68,
     268,    69,    70,    71,   248,    72,   193,   299,    73,    74,
      75,    76,    77,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    43,   390,    44,    82,    45,    89,    46,   167,   164,
     417,   393,   163,    95,   163,   101,    95,   111,   113,    95,
     163,    95,   419,   396,    95,   163,   508,   448,    90,    92,
      95,    95,    95,    95,   140,    95,    99,     6,   161,   235,
       6,   154,   168,   169,   170,   171,     5,   240,   166,   466,
     150,    81,   239,   150,   180,   181,   263,   474,   183,   185,
     186,   187,     5,   123,   189,   182,   447,    81,   441,   414,
     286,     5,   359,   264,   -43,   509,    81,     5,   413,   434,
     165,   459,    81,   444,     5,   458,   320,    37,    38,    81,
      37,    38,   234,   468,   500,   470,   234,   224,   422,   252,
     190,    95,    95,    95,    95,    95,   -43,    95,   457,   -43,
       5,   232,   464,   330,   502,    81,   463,     5,   277,   489,
     278,   150,    81,   285,   486,   -43,   -43,   -43,   364,   365,
     284,   129,   321,   482,     5,   397,   504,    95,   501,    81,
      95,    95,    95,    95,    95,    95,    95,   155,     5,   471,
     153,   150,   265,    81,   266,   172,   270,   348,   276,   331,
      83,    84,   283,   166,    89,   154,    85,   487,     6,   506,
       6,    95,    95,    95,    95,    95,    95,    95,    95,   156,
     124,    86,   157,   296,   125,   245,   455,   173,   380,    87,
      88,   503,   505,    79,   150,   381,   100,   450,   158,   159,
     160,   512,   245,   513,     5,   514,   382,   165,   152,    81,
     126,     5,   184,   385,   316,   394,    81,     5,    37,    38,
      37,    38,    81,   127,   383,   234,   317,   318,   -17,   150,
      95,   323,   324,   456,    80,   261,   403,   353,   352,   340,
     174,   326,   234,   295,   386,   262,    42,    43,   150,    44,
     374,   234,   269,   234,   395,   217,   138,   411,   116,    95,
     128,   375,   117,   150,   379,   129,   380,   404,   175,   130,
     461,    89,   380,   381,   234,   154,   231,   166,   346,   381,
     162,   356,   357,   418,   382,   176,     5,   131,   118,   272,
     382,    81,   273,    10,    11,    12,    13,    83,    84,   132,
     177,    18,   383,    85,     5,    94,    91,     5,   383,    81,
     165,   412,    81,   233,   392,   178,   380,   462,   377,    27,
      28,   274,   367,   381,   368,   179,    87,    88,    42,    43,
     119,    44,   377,   275,   382,   365,    42,    43,    93,    44,
     366,   399,     5,   400,   234,   405,   406,    81,   120,     5,
     134,   166,   383,   102,    81,    92,     5,   150,   492,   103,
     121,    81,   347,   493,   104,   236,   150,   105,   423,    83,
      84,   152,   238,     5,   136,    85,   429,   430,    81,   106,
     107,   108,   109,   218,   243,   437,   438,   433,   377,    42,
      43,   241,    44,   260,   399,   244,   400,   249,    87,    88,
     188,   250,   219,   220,   221,     5,     5,   150,   282,   326,
      81,    81,    80,   446,   298,   191,   281,   453,   305,   192,
       5,   194,   300,   325,   301,    81,   454,     5,   222,   223,
     432,   308,    81,   387,   388,   162,   163,   319,    42,    43,
       5,    44,   475,   477,   453,    81,   311,   423,    10,    11,
      12,    13,   -21,     5,   312,   478,   510,   315,    81,    42,
      43,   478,    44,    42,    43,   423,    44,   475,   399,   494,
     400,   492,   494,   322,   495,   341,   498,   499,   426,   427,
     332,    42,    43,   333,    44,   342,   399,   271,   400,   423,
     423,   507,   439,   427,   345,   511,   460,   427,   316,   423,
     350,   423,   361,   423,   362,   515,   110,     5,   373,   114,
     389,   115,    81,   378,   122,   467,   388,   391,   141,   297,
     133,   135,   137,   139,   142,   149,   127,   421,   425,   143,
     428,   436,   144,   302,   481,   449,   516,   496,   303,   476,
     303,   483,   484,   306,   145,   146,   147,   148,   310,   -94,
     -94,   442,   488,   313,   112,     5,   150,   309,   279,   280,
     151,     0,   -94,   -94,   -94,   -94,     0,     0,     0,     0,
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   343,     0,     0,     0,   153,     0,     0,     0,     0,
       0,   225,   226,   227,   228,   229,     0,   230,     0,     0,
       0,     0,   349,     0,   351,     0,     0,     0,     0,   354,
     355,     0,     0,   358,     0,   360,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   251,     0,     0,
     253,   254,   255,   256,   257,   258,   259,   370,     0,     0,
     371,   372,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,   294,     0,
     401,   402,     0,     0,     0,     0,     0,   407,     0,     0,
       0,     2,     3,     0,     0,     0,     0,     4,   416,     0,
       0,     0,     0,     5,   420,     6,     7,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     0,     0,    21,     0,    22,    23,    24,    25,     0,
     314,     0,    26,     0,     0,     0,    27,    28,    29,    30,
      31,    32,    33,    34,     0,    35,    36,   440,     0,     0,
     443,     0,   445,     0,     0,    37,    38,     0,     0,   344,
       0,     0,     0,     0,     0,   452,     0,   195,   196,   197,
     198,   199,   200,   201,   202,     5,     0,     0,   203,     0,
      81,     0,     0,   469,     0,     0,     0,   205,   472,   473,
       0,     0,   452,   206,     0,     0,     0,     0,   207,     0,
       0,    83,    84,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,   208,     0,     0,   209,
       0,   490,   210,   491,     0,   211,     0,     0,     0,   212,
      87,    88,   195,   196,   197,   198,   199,   200,   201,   202,
       5,     0,     0,   203,   204,    81,     0,     0,     0,     0,
       0,     0,   205,     0,     0,     0,     0,     0,   206,     0,
       0,     0,     0,   207,     0,     0,    83,    84,     0,     0,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,   208,     0,     0,   209,     0,     0,   210,     0,     0,
     211,     0,     0,     0,   212,    87,    88,   195,   196,   197,
     198,   199,   200,   201,   202,     5,     0,     0,   203,   408,
      81,     0,     0,     0,     0,     0,     0,   205,     0,     0,
       0,     0,     0,   206,     0,     0,     0,     0,   207,     0,
       0,    83,    84,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,   208,     0,     0,   209,
       0,     0,   210,     0,     0,   211,     0,     0,     0,   212,
      87,    88,   195,   196,   197,   198,   199,   200,   201,   202,
       5,     0,     0,   203,     0,    81,     0,     0,     0,     0,
       0,     0,   205,     0,     0,     0,     0,     0,   206,     0,
       0,     0,     0,   207,     0,     0,    83,    84,     0,     0,
     414,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,   208,     0,     0,   209,     0,     0,   210,     0,     0,
     211,     0,     0,     0,   212,    87,    88,   195,   196,   197,
     198,   199,   200,   201,   202,     5,     0,     0,   203,     0,
      81,     0,     0,     0,     0,     0,     0,   205,     0,     0,
       0,     0,     0,   206,     0,     0,     0,     0,   207,     0,
       0,    83,    84,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,   208,     0,     0,   209,
       0,     0,   210,     0,     0,   211,     4,     0,     0,   212,
      87,    88,     5,     0,     6,     7,     0,   334,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,   398,     0,     0,    22,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,    27,    28,   335,   336,    31,
      32,    33,    34,     0,    35,    36,     0,     0,     0,     0,
       4,     0,     0,     0,    37,    38,     5,     0,     6,     7,
       0,   334,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,   435,     0,     0,    22,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,    27,
      28,   335,   336,    31,    32,    33,    34,     0,    35,    36,
       0,     0,     0,     0,     4,     0,     0,     0,    37,    38,
       5,     0,     6,     7,     0,   334,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,   485,
       0,     0,    22,     0,     0,    25,     0,     0,     0,     0,
       0,     0,     0,    27,    28,   335,   336,    31,    32,    33,
      34,     0,    35,    36,     0,     0,     0,     0,     4,     0,
       0,     0,    37,    38,     5,     0,     6,     7,     0,   334,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,   497,     0,     0,    22,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,    27,    28,   335,
     336,    31,    32,    33,    34,     0,    35,    36,     0,     0,
       0,     0,     4,     0,     0,     0,    37,    38,     5,     0,
       6,     7,     0,   334,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
      22,     0,     0,    25,     0,     0,     0,     0,     0,     0,
       0,    27,    28,   335,   336,    31,    32,    33,    34,     0,
      35,    36,     0,     0,     0,     0,     0,     0,     0,     0,
      37,    38
};

static const yytype_int16 yycheck[] =
{
       1,     1,   329,     1,     5,     1,     7,     1,    49,    48,
     360,   331,     7,    14,     7,    16,    17,    18,    19,    20,
       7,    22,   363,   333,    25,     7,    15,   419,     7,     8,
      31,    32,    33,    34,    35,    36,    15,    14,    47,   117,
      14,    42,    51,    52,    53,    54,    12,   125,    49,   441,
      13,    17,    13,    13,    63,    64,    13,    31,    67,    68,
      69,    70,    12,    53,    73,    66,   416,    17,   409,    42,
      65,    12,    65,   151,     8,    64,    17,    12,    65,   389,
      15,   431,    17,    65,    12,    58,    13,    64,    65,    17,
      64,    65,    53,   443,   486,   445,    53,    60,    64,    59,
      79,   102,   103,   104,   105,   106,    40,   108,   428,    43,
      12,   112,   439,    13,    64,    17,   436,    12,   159,   469,
     159,    13,    17,   164,   465,    59,    60,    61,    57,    58,
      65,    13,    59,   460,    12,    17,    64,   138,   488,    17,
     141,   142,   143,   144,   145,   146,   147,     8,    12,   448,
      42,    13,   153,    17,   155,    58,   157,    59,   159,    59,
      38,    39,   163,   164,   165,   166,    44,   466,    14,    64,
      14,   172,   173,   174,   175,   176,   177,   178,   179,    40,
      13,    59,    43,   184,    17,    13,    15,    58,    17,    67,
      68,   490,   491,    15,    13,    24,    60,    59,    59,    60,
      61,   500,    13,   502,    12,   504,    35,    15,    27,    17,
      43,    12,    58,    15,    58,    15,    17,    12,    64,    65,
      64,    65,    17,    56,    53,    53,   235,   236,    56,    13,
     231,   240,   241,    62,    56,    17,    15,   278,   277,   248,
      58,   242,    53,    27,   322,    27,   247,   247,    13,   247,
      53,    53,    53,    53,   332,    17,    51,    65,    13,   260,
       8,    64,    17,    13,    15,    13,    17,   345,    58,    17,
      15,   272,    17,    24,    53,   276,    51,   278,    43,    24,
       6,   282,   283,   361,    35,    58,    12,    35,    43,    15,
      35,    17,    18,    19,    20,    21,    22,    38,    39,    47,
      58,    27,    53,    44,    12,    13,    47,    12,    53,    17,
      15,   352,    17,    17,    15,    58,    17,    62,   319,    45,
      46,    47,    58,    24,    60,    58,    67,    68,   329,   329,
      17,   329,   333,    59,    35,    58,   337,   337,     9,   337,
      63,   337,    12,   337,    53,   346,   347,    17,    35,    12,
      13,   352,    53,    23,    17,   334,    12,    13,    58,    29,
      47,    17,     9,    63,    34,    53,    13,    37,   369,    38,
      39,    27,    17,    12,    13,    44,   385,   386,    17,    49,
      50,    51,    52,    40,    17,   394,   395,   388,   389,   390,
     390,    53,   390,    51,   390,    17,   390,    17,    67,    68,
      71,    17,    59,    60,    61,    12,    12,    13,    15,   410,
      17,    17,    56,   414,    17,    86,    59,   426,    59,    90,
      12,    92,     4,    15,     5,    17,   427,    12,    99,   100,
      15,    59,    17,    57,    58,     6,     7,    56,   439,   439,
      12,   439,   451,    15,   453,    17,    59,   448,    19,    20,
      21,    22,    56,    12,    59,   456,    15,    59,    17,   460,
     460,   462,   460,   464,   464,   466,   464,   476,   464,    58,
     464,    58,    58,    17,    63,    59,    63,    63,    57,    58,
      17,   482,   482,    56,   482,    59,   482,   158,   482,   490,
     491,   492,    57,    58,    17,   496,    57,    58,    58,   500,
      56,   502,    60,   504,    31,   506,    17,    12,    15,    20,
      56,    22,    17,    17,    25,    57,    58,    17,    23,   190,
      31,    32,    33,    34,    29,    36,    56,    17,    53,    34,
      59,    59,    37,   204,    17,    59,    15,    59,   209,   453,
     211,   462,   462,   211,    49,    50,    51,    52,   219,     6,
       7,   410,   467,   224,    18,    12,    13,   218,   159,   159,
      17,    -1,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,   102,   103,   104,   105,   106,    -1,   108,    -1,    -1,
      -1,    -1,   273,    -1,   275,    -1,    -1,    -1,    -1,   280,
     281,    -1,    -1,   284,    -1,   286,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,
     141,   142,   143,   144,   145,   146,   147,   308,    -1,    -1,
     311,   312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   172,   173,   174,   175,   176,   177,   178,   179,    -1,
     341,   342,    -1,    -1,    -1,    -1,    -1,   348,    -1,    -1,
      -1,     0,     1,    -1,    -1,    -1,    -1,     6,   359,    -1,
      -1,    -1,    -1,    12,   365,    14,    15,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    -1,    34,    35,    36,    37,    -1,
     231,    -1,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,   408,    -1,    -1,
     411,    -1,   413,    -1,    -1,    64,    65,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,   426,    -1,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    15,    -1,
      17,    -1,    -1,   444,    -1,    -1,    -1,    24,   449,   450,
      -1,    -1,   453,    30,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,
      -1,    58,    59,    60,    -1,    62,    -1,    -1,    -1,    66,
      67,    68,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    56,    -1,    -1,    59,    -1,    -1,
      62,    -1,    -1,    -1,    66,    67,    68,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,
      -1,    -1,    59,    -1,    -1,    62,    -1,    -1,    -1,    66,
      67,    68,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    15,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    38,    39,    -1,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    56,    -1,    -1,    59,    -1,    -1,
      62,    -1,    -1,    -1,    66,    67,    68,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    15,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,
      -1,    -1,    59,    -1,    -1,    62,     6,    -1,    -1,    66,
      67,    68,    12,    -1,    14,    15,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    -1,    -1,    34,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    64,    65,    12,    -1,    14,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    -1,    -1,    34,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    64,    65,
      12,    -1,    14,    15,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    54,    55,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    64,    65,    12,    -1,    14,    15,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    -1,    -1,    34,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    64,    65,    12,    -1,
      14,    15,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,     0,     1,     6,    12,    14,    15,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    32,    34,    35,    36,    37,    41,    45,    46,    47,
      48,    49,    50,    51,    52,    54,    55,    64,    65,    71,
      72,    77,    81,    82,    83,    87,    91,    92,    93,    94,
      99,   100,   101,   102,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   128,   130,
     131,   132,   134,   137,   138,   139,   140,   141,   142,    15,
      56,    17,    81,    38,    39,    44,    59,    67,    68,    81,
      98,    47,    98,    95,    13,    81,    82,    83,    84,    98,
      60,    81,    23,    29,    34,    37,    49,    50,    51,    52,
      84,    81,   119,    81,    84,    84,    13,    17,    43,    17,
      35,    47,    84,    53,    13,    17,    43,    56,     8,    13,
      17,    35,    47,    84,    13,    84,    13,    84,    51,    84,
      81,    23,    29,    34,    37,    49,    50,    51,    52,    84,
      13,    17,    27,    42,    81,     8,    40,    43,    59,    60,
      61,    99,     6,     7,    94,    15,    81,    93,    99,    99,
      99,    99,    58,    58,    58,    58,    58,    58,    58,    58,
      99,    99,    81,    99,    58,    99,    99,    99,    95,    99,
      98,    95,    95,   135,    95,     4,     5,     6,     7,     8,
       9,    10,    11,    15,    16,    24,    30,    35,    53,    56,
      59,    62,    66,    81,    97,    98,   121,    17,    40,    59,
      60,    61,    95,    95,    60,    84,    84,    84,    84,    84,
      84,    51,    81,    17,    53,   133,    53,    78,    17,    13,
     133,    53,   104,    17,    17,    13,    73,    74,   133,    17,
      17,    84,    59,    84,    84,    84,    84,    84,    84,    84,
      51,    17,    27,    13,   133,    81,    81,    95,   129,    53,
      81,    95,    15,    18,    47,    59,    81,    93,    94,   118,
     132,    59,    15,    81,    65,    93,    65,    84,    84,    84,
      84,    84,    84,    84,    84,    27,    81,    95,    17,   136,
       4,     5,    95,    95,    96,    59,    96,   126,    59,   129,
      95,    59,    59,    95,    84,    59,    58,    99,    99,    56,
      13,    59,    17,    99,    99,    15,    81,   105,    75,    76,
      13,    59,    17,    56,    17,    47,    48,    86,    87,    91,
      99,    59,    59,    95,    84,    17,    43,     9,    59,    95,
      56,    95,    94,    93,    95,    95,    81,    81,    95,    65,
      95,    60,    31,   122,    57,    58,    63,    58,    60,   125,
      95,    95,    95,    15,    53,    64,    80,    81,    17,    15,
      17,    24,    35,    53,    88,    15,   133,    57,    58,    56,
      86,    17,    15,    88,    15,   133,    80,    17,    31,    87,
      91,    95,    95,    15,   133,    81,    81,    95,    16,   123,
     103,    65,    93,    65,    42,    85,    95,    85,   133,   126,
      95,    17,    64,    81,   127,    53,    57,    58,    59,    99,
      99,   106,    15,    81,    80,    31,    59,    99,    99,    57,
      95,   126,   105,    95,    65,    95,    81,    85,   125,    59,
      59,    79,    95,    99,    81,    15,    62,    88,    58,    85,
      57,    15,    62,    88,    86,   124,   125,    57,    85,    95,
      85,   127,    95,    95,    31,    99,    79,    15,    81,    89,
      90,    17,    86,    89,    90,    31,   126,   127,   106,    85,
      58,    60,    58,    63,    58,    63,    59,    31,    63,    63,
     125,    85,    64,   127,    64,   127,    64,    81,    15,    64,
      15,    81,   127,   127,   127,    81,    15
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    71,    73,    72,    74,
      72,    75,    72,    76,    72,    72,    72,    78,    77,    77,
      77,    79,    79,    79,    80,    80,    80,    81,    81,    81,
      81,    82,    83,    83,    84,    84,    84,    84,    84,    85,
      85,    86,    86,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    88,    88,    89,    89,
      89,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    93,    93,
      94,    94,    94,    94,    94,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      96,    97,    97,    97,    97,    97,    97,    97,    98,    98,
      98,    98,    98,    99,    99,    99,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   101,   101,   103,   102,   104,
     102,   105,   105,   105,   105,   105,   106,   106,   106,   107,
     107,   107,   107,   107,   107,   107,   107,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   109,   109,   109,   109,
     110,   110,   110,   110,   110,   111,   111,   111,   111,   112,
     112,   112,   112,   113,   113,   113,   113,   114,   114,   114,
     114,   114,   115,   115,   115,   116,   116,   117,   117,   118,
     118,   118,   118,   118,   119,   119,   121,   120,   122,   120,
     123,   120,   124,   120,   125,   125,   126,   126,   127,   127,
     127,   127,   127,   128,   128,   129,   130,   130,   130,   130,
     130,   130,   131,   132,   132,   133,   133,   133,   135,   134,
     136,   136,   137,   137,   137,   138,   138,   138,   138,   138,
     138,   138,   139,   140,   141,   141,   141,   142
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
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       3,     2,     4,     4,     3,     5,     2,     3,     3,     3,
       2,     3,     2,     3,     5,     2,     3,     3,     3,     2,
       3,     3,     3,     2,     3,     3,     3,     2,     3,     3,
       3,     5,     2,     2,     3,     4,     2,     1,     3,     2,
       2,     2,     3,     1,     2,     3,     0,     6,     0,     8,
       0,     8,     0,    10,     1,     2,     0,     5,     3,     5,
       6,     5,     6,     2,     3,     1,     3,     4,     3,     3,
       3,     4,     2,     1,     1,     1,     3,     4,     0,     5,
       0,     3,     3,     5,     5,     5,     5,     5,     7,     7,
       9,     9,     4,     4,     4,     6,     6,     4
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
#line 164 "antimony.ypp"
                             {}
#line 2162 "antimony.tab.cpp"
    break;

  case 4: /* input: input module  */
#line 165 "antimony.ypp"
                             { /*cout << endl << $2->ToString() << endl << endl;*/ }
#line 2168 "antimony.tab.cpp"
    break;

  case 5: /* input: input modulepart  */
#line 166 "antimony.ypp"
                                 {}
#line 2174 "antimony.tab.cpp"
    break;

  case 6: /* input: input function  */
#line 167 "antimony.ypp"
                               {}
#line 2180 "antimony.tab.cpp"
    break;

  case 7: /* input: input modulename  */
#line 168 "antimony.ypp"
                                 {}
#line 2186 "antimony.tab.cpp"
    break;

  case 8: /* input: input functionname  */
#line 169 "antimony.ypp"
                                   {}
#line 2192 "antimony.tab.cpp"
    break;

  case 9: /* input: input modulecvterm  */
#line 170 "antimony.ypp"
                                   {}
#line 2198 "antimony.tab.cpp"
    break;

  case 10: /* input: input functioncvterm  */
#line 171 "antimony.ypp"
                                     {}
#line 2204 "antimony.tab.cpp"
    break;

  case 11: /* input: input toplevel_sbo  */
#line 172 "antimony.ypp"
                                   {}
#line 2210 "antimony.tab.cpp"
    break;

  case 12: /* input: input annotationBlock  */
#line 173 "antimony.ypp"
                                      {}
#line 2216 "antimony.tab.cpp"
    break;

  case 13: /* input: input moduleannotation  */
#line 174 "antimony.ypp"
                                      {}
#line 2222 "antimony.tab.cpp"
    break;

  case 14: /* input: input error  */
#line 175 "antimony.ypp"
                            {YYABORT;}
#line 2228 "antimony.tab.cpp"
    break;

  case 15: /* input: input "an error"  */
#line 176 "antimony.ypp"
                            {YYABORT;}
#line 2234 "antimony.tab.cpp"
    break;

  case 16: /* import: "'import'" "text string"  */
#line 179 "antimony.ypp"
                                  { if (g_registry.OpenFile(*((yyvsp[0].word)))==0) YYABORT;}
#line 2240 "antimony.tab.cpp"
    break;

  case 17: /* $@1: %empty  */
#line 182 "antimony.ypp"
                               {g_registry.NewCurrentModule((yyvsp[0].word), NULL, false);}
#line 2246 "antimony.tab.cpp"
    break;

  case 18: /* module: "'model' or 'module'" "element name" $@1 '(' variableexportlist ')' modulebody "'end'"  */
#line 183 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2256 "antimony.tab.cpp"
    break;

  case 19: /* $@2: %empty  */
#line 188 "antimony.ypp"
                               {g_registry.NewCurrentModule((yyvsp[0].word), NULL, false);}
#line 2262 "antimony.tab.cpp"
    break;

  case 20: /* module: "'model' or 'module'" "element name" $@2 modulebody "'end'"  */
#line 189 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2272 "antimony.tab.cpp"
    break;

  case 21: /* $@3: %empty  */
#line 194 "antimony.ypp"
                                   {g_registry.NewCurrentModule((yyvsp[0].word), NULL, true);}
#line 2278 "antimony.tab.cpp"
    break;

  case 22: /* module: "'model' or 'module'" '*' "element name" $@3 '(' variableexportlist ')' modulebody "'end'"  */
#line 195 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2288 "antimony.tab.cpp"
    break;

  case 23: /* $@4: %empty  */
#line 200 "antimony.ypp"
                                   {g_registry.NewCurrentModule((yyvsp[0].word), NULL, true);}
#line 2294 "antimony.tab.cpp"
    break;

  case 24: /* module: "'model' or 'module'" '*' "element name" $@4 modulebody "'end'"  */
#line 201 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2304 "antimony.tab.cpp"
    break;

  case 25: /* module: "'model' or 'module'" "name of an existing module"  */
#line 206 "antimony.ypp"
                               {g_registry.SetError("module '" + *((yyvsp[0].word)) + "' already defined."); YYABORT;}
#line 2310 "antimony.tab.cpp"
    break;

  case 26: /* module: "'model' or 'module'" "name of an existing function"  */
#line 207 "antimony.ypp"
                                {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a module because it is already a defined function."); YYABORT;}
#line 2316 "antimony.tab.cpp"
    break;

  case 27: /* $@5: %empty  */
#line 210 "antimony.ypp"
                                     {g_registry.NewUserFunction((yyvsp[0].word));}
#line 2322 "antimony.tab.cpp"
    break;

  case 28: /* function: "'function'" "element name" $@5 '(' variableexportlist ')' spacedformula "'end'"  */
#line 210 "antimony.ypp"
                                                                                                                    {if (g_registry.SetUserFunction((yyvsp[-1].formula))) YYABORT;}
#line 2328 "antimony.tab.cpp"
    break;

  case 29: /* function: "'function'" "name of an existing module"  */
#line 211 "antimony.ypp"
                                     {g_registry.SetError("Cannot use '" + *((yyvsp[0].word)) +"' as a function name because it is already the name of a module."); YYABORT;}
#line 2334 "antimony.tab.cpp"
    break;

  case 30: /* function: "'function'" "name of an existing function"  */
#line 212 "antimony.ypp"
                                      {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a new function because it is already a defined function."); YYABORT;}
#line 2340 "antimony.tab.cpp"
    break;

  case 31: /* spacedformula: formula  */
#line 215 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2346 "antimony.tab.cpp"
    break;

  case 32: /* spacedformula: lineend spacedformula  */
#line 216 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[0].formula);}
#line 2352 "antimony.tab.cpp"
    break;

  case 33: /* spacedformula: spacedformula lineend  */
#line 217 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[-1].formula);}
#line 2358 "antimony.tab.cpp"
    break;

  case 34: /* variableexportlist: %empty  */
#line 227 "antimony.ypp"
                            {}
#line 2364 "antimony.tab.cpp"
    break;

  case 35: /* variableexportlist: variable  */
#line 228 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2370 "antimony.tab.cpp"
    break;

  case 36: /* variableexportlist: variableexportlist ',' variable  */
#line 229 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2376 "antimony.tab.cpp"
    break;

  case 37: /* variable: "element name"  */
#line 232 "antimony.ypp"
                        {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[0].word)); }
#line 2382 "antimony.tab.cpp"
    break;

  case 38: /* variable: variable '.' "element name"  */
#line 233 "antimony.ypp"
                                     {(yyval.variable) = (yyvsp[-2].variable)->GetSubVariable((yyvsp[0].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[0].word)) + "' is not a subvariable of '" + (yyvsp[-2].variable)->GetNameDelimitedBy(".") + "'.");
                    YYABORT;
                  }
                }
#line 2393 "antimony.tab.cpp"
    break;

  case 39: /* variable: variable '.' "--"  */
#line 239 "antimony.ypp"
                                    {
		  string dashes("--");
		  (yyval.variable) = (yyvsp[-2].variable)->GetSubVariable(&dashes);
                  if ((yyval.variable) == NULL) {                    g_registry.SetError("There is no empty set that can be set with '.--' for the variable '" + (yyvsp[-2].variable)->GetNameDelimitedBy(".") + "'.");
                    YYABORT;
                  }
                }
#line 2405 "antimony.tab.cpp"
    break;

  case 40: /* variable: '$' variable  */
#line 246 "antimony.ypp"
                             {(yyval.variable) = (yyvsp[0].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;}
#line 2411 "antimony.tab.cpp"
    break;

  case 41: /* variablein: variable "'in'" variable  */
#line 249 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetCompartment((yyvsp[0].variable))) YYABORT; (yyval.variable) = (yyvsp[-2].variable);}
#line 2417 "antimony.tab.cpp"
    break;

  case 42: /* varmaybein: variable  */
#line 252 "antimony.ypp"
                         {(yyval.variable) = (yyvsp[0].variable);}
#line 2423 "antimony.tab.cpp"
    break;

  case 43: /* varmaybein: variablein  */
#line 253 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2429 "antimony.tab.cpp"
    break;

  case 44: /* varmaybeis: varmaybein  */
#line 256 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2435 "antimony.tab.cpp"
    break;

  case 45: /* varmaybeis: varmaybein '=' formula  */
#line 257 "antimony.ypp"
                                       {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2441 "antimony.tab.cpp"
    break;

  case 46: /* varmaybeis: varmaybein ':' '=' formula  */
#line 258 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT; }
#line 2447 "antimony.tab.cpp"
    break;

  case 47: /* varmaybeis: varmaybein '\'' '=' formula  */
#line 259 "antimony.ypp"
                                            {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT; }
#line 2453 "antimony.tab.cpp"
    break;

  case 48: /* varmaybeis: varmaybein "'has'" unitdef  */
#line 260 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2459 "antimony.tab.cpp"
    break;

  case 49: /* maybein: %empty  */
#line 263 "antimony.ypp"
                            {(yyval.variable) = NULL;}
#line 2465 "antimony.tab.cpp"
    break;

  case 50: /* maybein: "'in'" variable  */
#line 264 "antimony.ypp"
                                {(yyval.variable) = (yyvsp[0].variable);}
#line 2471 "antimony.tab.cpp"
    break;

  case 51: /* modulebody: modulepart  */
#line 267 "antimony.ypp"
                           {}
#line 2477 "antimony.tab.cpp"
    break;

  case 52: /* modulebody: moduleannotation  */
#line 268 "antimony.ypp"
                                 {}
#line 2483 "antimony.tab.cpp"
    break;

  case 53: /* modulebody: modulebody modulepart  */
#line 269 "antimony.ypp"
                                      {}
#line 2489 "antimony.tab.cpp"
    break;

  case 54: /* modulebody: modulebody moduleannotation  */
#line 270 "antimony.ypp"
                                           {}
#line 2495 "antimony.tab.cpp"
    break;

  case 55: /* moduleannotation: "'model' or 'module'" "element name" stringlist lineend  */
#line 274 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCVTerm(&modname,(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;
                }
#line 2504 "antimony.tab.cpp"
    break;

  case 56: /* moduleannotation: "'model' or 'module'" "element name" '.' "element name" stringlist lineend  */
#line 279 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCreatorTerm(&modname, (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].stringlist))) YYABORT;
                }
#line 2513 "antimony.tab.cpp"
    break;

  case 57: /* moduleannotation: "'model' or 'module'" "element name" '.' "element name" "number" lineend  */
#line 284 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCreatorTerm(&modname, (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].num))) YYABORT;
                }
#line 2522 "antimony.tab.cpp"
    break;

  case 58: /* moduleannotation: "'model' or 'module'" '.' "element name" '=' "number"  */
#line 289 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      module->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-2].word)) + "'. The only thing that can be set on the model to a number is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 2536 "antimony.tab.cpp"
    break;

  case 59: /* moduleannotation: "'model' or 'module'" '.' "element name" '=' stringConstant  */
#line 299 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "layout")) {
                      if (module->SetLayout((yyvsp[0].word))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-2].word)) + "'. The only thing that can be set on the model to a string is 'layout'.");
                      YYABORT;
                    }
                  }
#line 2550 "antimony.tab.cpp"
    break;

  case 60: /* moduleannotation: "'model' or 'module'" '.' "element name" '.' "element name" '=' "number"  */
#line 309 "antimony.ypp"
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
#line 2568 "antimony.tab.cpp"
    break;

  case 61: /* moduleannotation: "'model' or 'module'" '.' "element name" '.' "element name" '=' stringConstant  */
#line 323 "antimony.ypp"
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
#line 2586 "antimony.tab.cpp"
    break;

  case 62: /* moduleannotation: "'model' or 'module'" '.' "element name" '.' "element name" '=' '{' variablelist '}'  */
#line 337 "antimony.ypp"
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
#line 2604 "antimony.tab.cpp"
    break;

  case 63: /* moduleannotation: "'model' or 'module'" '.' "element name" '.' "element name" '=' '{' numlist '}'  */
#line 351 "antimony.ypp"
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
#line 2622 "antimony.tab.cpp"
    break;

  case 64: /* stringConstant: "name of a pre-defined constant"  */
#line 366 "antimony.ypp"
                         {(yyval.word) = (yyvsp[0].word);}
#line 2628 "antimony.tab.cpp"
    break;

  case 65: /* stringConstant: "text string"  */
#line 367 "antimony.ypp"
                           {(yyval.word) = (yyvsp[0].word);}
#line 2634 "antimony.tab.cpp"
    break;

  case 66: /* stringConstant: "element name"  */
#line 368 "antimony.ypp"
                        {(yyval.word) = (yyvsp[0].word);}
#line 2640 "antimony.tab.cpp"
    break;

  case 67: /* stringConstant: "name of an existing function"  */
#line 369 "antimony.ypp"
                         {(yyval.word) = (yyvsp[0].word);}
#line 2646 "antimony.tab.cpp"
    break;

  case 68: /* variablelist: variable  */
#line 371 "antimony.ypp"
                         { (yyval.variablelist) = new std::vector<Variable*>(); (yyval.variablelist)->push_back((yyvsp[0].variable));}
#line 2652 "antimony.tab.cpp"
    break;

  case 69: /* variablelist: variablelist ',' variable  */
#line 372 "antimony.ypp"
                                          { (yyval.variablelist) = (yyvsp[-2].variablelist); (yyval.variablelist)->push_back((yyvsp[0].variable)); }
#line 2658 "antimony.tab.cpp"
    break;

  case 70: /* variablelist: variablelist ',' '\n' variable  */
#line 373 "antimony.ypp"
                                               { (yyval.variablelist) = (yyvsp[-3].variablelist); (yyval.variablelist)->push_back((yyvsp[0].variable)); }
#line 2664 "antimony.tab.cpp"
    break;

  case 71: /* numlist: "number"  */
#line 376 "antimony.ypp"
                    { (yyval.numlist) = new std::vector<double>(); (yyval.numlist)->push_back((yyvsp[0].num)); }
#line 2670 "antimony.tab.cpp"
    break;

  case 72: /* numlist: numlist ',' "number"  */
#line 377 "antimony.ypp"
                                { (yyval.numlist) = (yyvsp[-2].numlist); (yyval.numlist)->push_back((yyvsp[0].num)); }
#line 2676 "antimony.tab.cpp"
    break;

  case 73: /* numlist: numlist ',' '\n' "number"  */
#line 378 "antimony.ypp"
                                     { (yyval.numlist) = (yyvsp[-3].numlist); (yyval.numlist)->push_back((yyvsp[0].num)); }
#line 2682 "antimony.tab.cpp"
    break;

  case 74: /* modulepart: reaction lineend  */
#line 381 "antimony.ypp"
                                 {}
#line 2688 "antimony.tab.cpp"
    break;

  case 75: /* modulepart: assignment lineend  */
#line 382 "antimony.ypp"
                                   {}
#line 2694 "antimony.tab.cpp"
    break;

  case 76: /* modulepart: submodule lineend  */
#line 383 "antimony.ypp"
                                  {}
#line 2700 "antimony.tab.cpp"
    break;

  case 77: /* modulepart: varinitialize lineend  */
#line 384 "antimony.ypp"
                                      {}
#line 2706 "antimony.tab.cpp"
    break;

  case 78: /* modulepart: dnadef lineend  */
#line 385 "antimony.ypp"
                               {}
#line 2712 "antimony.tab.cpp"
    break;

  case 79: /* modulepart: event lineend  */
#line 386 "antimony.ypp"
                              {}
#line 2718 "antimony.tab.cpp"
    break;

  case 80: /* modulepart: unitinit lineend  */
#line 387 "antimony.ypp"
                                 {}
#line 2724 "antimony.tab.cpp"
    break;

  case 81: /* modulepart: deletion lineend  */
#line 388 "antimony.ypp"
                                 {}
#line 2730 "antimony.tab.cpp"
    break;

  case 82: /* modulepart: cvterm lineend  */
#line 389 "antimony.ypp"
                               {}
#line 2736 "antimony.tab.cpp"
    break;

  case 83: /* modulepart: variablein  */
#line 390 "antimony.ypp"
                           {}
#line 2742 "antimony.tab.cpp"
    break;

  case 84: /* modulepart: constraint lineend  */
#line 391 "antimony.ypp"
                                   {}
#line 2748 "antimony.tab.cpp"
    break;

  case 85: /* modulepart: objective lineend  */
#line 392 "antimony.ypp"
                                  {}
#line 2754 "antimony.tab.cpp"
    break;

  case 86: /* modulepart: algrule lineend  */
#line 393 "antimony.ypp"
                                {}
#line 2760 "antimony.tab.cpp"
    break;

  case 87: /* modulepart: lineend  */
#line 394 "antimony.ypp"
                        {}
#line 2766 "antimony.tab.cpp"
    break;

  case 88: /* reaction: varmaybein ':' reactantList reactionDivider reactantList ';' formula maybein  */
#line 398 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-7].variable), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-7].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2778 "antimony.tab.cpp"
    break;

  case 89: /* reaction: reactantList reactionDivider reactantList ';' formula maybein  */
#line 406 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2790 "antimony.tab.cpp"
    break;

  case 90: /* reaction: reactantList reactionDivider ';' formula maybein  */
#line 414 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2802 "antimony.tab.cpp"
    break;

  case 91: /* reaction: varmaybein ':' reactantList reactionDivider ';' formula maybein  */
#line 422 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2814 "antimony.tab.cpp"
    break;

  case 92: /* reaction: reactionDivider reactantList ';' formula maybein  */
#line 430 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2826 "antimony.tab.cpp"
    break;

  case 93: /* reaction: varmaybein ':' reactionDivider reactantList ';' formula maybein  */
#line 438 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2838 "antimony.tab.cpp"
    break;

  case 94: /* reactantList: variable  */
#line 447 "antimony.ypp"
                         {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2844 "antimony.tab.cpp"
    break;

  case 95: /* reactantList: "number" variable  */
#line 448 "antimony.ypp"
                             {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2850 "antimony.tab.cpp"
    break;

  case 96: /* reactantList: variable variable  */
#line 449 "antimony.ypp"
                                  {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2856 "antimony.tab.cpp"
    break;

  case 97: /* reactantList: reactantList '+' variable  */
#line 450 "antimony.ypp"
                                          {(yyval.reactantList) = (yyvsp[-2].reactantList); if((yyvsp[-2].reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2862 "antimony.tab.cpp"
    break;

  case 98: /* reactantList: reactantList '+' "number" variable  */
#line 451 "antimony.ypp"
                                              {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2868 "antimony.tab.cpp"
    break;

  case 99: /* reactantList: reactantList '+' variable variable  */
#line 452 "antimony.ypp"
                                                   {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2874 "antimony.tab.cpp"
    break;

  case 100: /* reactionDivider: "->"  */
#line 456 "antimony.ypp"
                           {(yyval.reactionDivider) = rdBecomes;}
#line 2880 "antimony.tab.cpp"
    break;

  case 101: /* reactionDivider: "-|"  */
#line 457 "antimony.ypp"
                           {(yyval.reactionDivider) = rdInhibits;}
#line 2886 "antimony.tab.cpp"
    break;

  case 102: /* reactionDivider: '-' '('  */
#line 458 "antimony.ypp"
                        {(yyval.reactionDivider) = rdInfluences;}
#line 2892 "antimony.tab.cpp"
    break;

  case 103: /* reactionDivider: "-o"  */
#line 459 "antimony.ypp"
                            {(yyval.reactionDivider) = rdInfluences;}
#line 2898 "antimony.tab.cpp"
    break;

  case 104: /* reactionDivider: "=>"  */
#line 460 "antimony.ypp"
                             {(yyval.reactionDivider) = rdBecomesIrreversibly;}
#line 2904 "antimony.tab.cpp"
    break;

  case 105: /* formula: %empty  */
#line 463 "antimony.ypp"
                            {(yyval.formula) = g_registry.NewBlankFormula(); }
#line 2910 "antimony.tab.cpp"
    break;

  case 106: /* formula: formula "..."  */
#line 464 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddEllipses();}
#line 2916 "antimony.tab.cpp"
    break;

  case 107: /* formula: formula variable  */
#line 465 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); if((yyvsp[-1].formula)->AddVariable((yyvsp[0].variable))) YYABORT; }
#line 2922 "antimony.tab.cpp"
    break;

  case 108: /* formula: formula "number"  */
#line 466 "antimony.ypp"
                             {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddNum((yyvsp[0].num)); }
#line 2928 "antimony.tab.cpp"
    break;

  case 109: /* formula: formula "name of a pre-defined constant"  */
#line 467 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2934 "antimony.tab.cpp"
    break;

  case 110: /* formula: formula "name of an existing function"  */
#line 468 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2940 "antimony.tab.cpp"
    break;

  case 111: /* formula: formula '(' commaformula ')'  */
#line 469 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2946 "antimony.tab.cpp"
    break;

  case 112: /* formula: formula '{' commaformula '}'  */
#line 470 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddCurlyBrackets(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2952 "antimony.tab.cpp"
    break;

  case 113: /* formula: formula mathThing  */
#line 471 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddMathThing((yyvsp[0].character)); }
#line 2958 "antimony.tab.cpp"
    break;

  case 114: /* formula: formula inequality  */
#line 472 "antimony.ypp"
                                   {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddInequality((yyvsp[0].inequality)); }
#line 2964 "antimony.tab.cpp"
    break;

  case 115: /* formula: formula '=' '='  */
#line 473 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('='); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2970 "antimony.tab.cpp"
    break;

  case 116: /* formula: formula '&' '&'  */
#line 474 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('&'); (yyvsp[-2].formula)->AddMathThing('&'); }
#line 2976 "antimony.tab.cpp"
    break;

  case 117: /* formula: formula '|' '|'  */
#line 475 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('|'); (yyvsp[-2].formula)->AddMathThing('|'); }
#line 2982 "antimony.tab.cpp"
    break;

  case 118: /* formula: formula "text string"  */
#line 476 "antimony.ypp"
                                   {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word), true); }
#line 2988 "antimony.tab.cpp"
    break;

  case 119: /* commaformula: formula  */
#line 479 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2994 "antimony.tab.cpp"
    break;

  case 120: /* commaformula: commaformula ',' formula  */
#line 480 "antimony.ypp"
                                         {(yyval.formula) = (yyvsp[-2].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[0].formula)); }
#line 3000 "antimony.tab.cpp"
    break;

  case 121: /* mathThing: '+'  */
#line 483 "antimony.ypp"
                    {(yyval.character) = '+';}
#line 3006 "antimony.tab.cpp"
    break;

  case 122: /* mathThing: '-'  */
#line 484 "antimony.ypp"
                    {(yyval.character) = '-';}
#line 3012 "antimony.tab.cpp"
    break;

  case 123: /* mathThing: '*'  */
#line 485 "antimony.ypp"
                    {(yyval.character) = '*';}
#line 3018 "antimony.tab.cpp"
    break;

  case 124: /* mathThing: '/'  */
#line 486 "antimony.ypp"
                    {(yyval.character) = '/';}
#line 3024 "antimony.tab.cpp"
    break;

  case 125: /* mathThing: '^'  */
#line 487 "antimony.ypp"
                    {(yyval.character) = '^';}
#line 3030 "antimony.tab.cpp"
    break;

  case 126: /* mathThing: '!'  */
#line 488 "antimony.ypp"
                    {(yyval.character) = '!';}
#line 3036 "antimony.tab.cpp"
    break;

  case 127: /* mathThing: '%'  */
#line 489 "antimony.ypp"
                    {(yyval.character) = '%';}
#line 3042 "antimony.tab.cpp"
    break;

  case 128: /* inequality: '<'  */
#line 492 "antimony.ypp"
                    {(yyval.inequality) = constLT;}
#line 3048 "antimony.tab.cpp"
    break;

  case 129: /* inequality: "<="  */
#line 493 "antimony.ypp"
                    {(yyval.inequality) = constLEQ;}
#line 3054 "antimony.tab.cpp"
    break;

  case 130: /* inequality: '>'  */
#line 494 "antimony.ypp"
                    {(yyval.inequality) = constGT;}
#line 3060 "antimony.tab.cpp"
    break;

  case 131: /* inequality: ">="  */
#line 495 "antimony.ypp"
                    {(yyval.inequality) = constGEQ;}
#line 3066 "antimony.tab.cpp"
    break;

  case 132: /* inequality: "!="  */
#line 496 "antimony.ypp"
                    {(yyval.inequality) = constNEQ;}
#line 3072 "antimony.tab.cpp"
    break;

  case 133: /* lineend: ';'  */
#line 499 "antimony.ypp"
                    {}
#line 3078 "antimony.tab.cpp"
    break;

  case 134: /* lineend: '\n'  */
#line 500 "antimony.ypp"
                     {}
#line 3084 "antimony.tab.cpp"
    break;

  case 135: /* lineend: "end of line"  */
#line 501 "antimony.ypp"
                    {}
#line 3090 "antimony.tab.cpp"
    break;

  case 136: /* assignment: varmaybein ':' maxormin formula  */
#line 504 "antimony.ypp"
                                                {if (g_registry.CurrentModule()->AddObjective((yyvsp[-3].variable), (yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 3096 "antimony.tab.cpp"
    break;

  case 137: /* assignment: varmaybein '=' formula  */
#line 505 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 3102 "antimony.tab.cpp"
    break;

  case 138: /* assignment: varmaybein "'is'" variable  */
#line 506 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->Synchronize((yyvsp[0].variable), NULL)) YYABORT;}
#line 3108 "antimony.tab.cpp"
    break;

  case 139: /* assignment: varmaybein "'is'" variable '/' variable  */
#line 507 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[-2].variable), (yyvsp[0].variable))) YYABORT;}
#line 3114 "antimony.tab.cpp"
    break;

  case 140: /* assignment: varmaybein '*' variable "'is'" variable  */
#line 508 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[0].variable), (yyvsp[-2].variable))) YYABORT;}
#line 3120 "antimony.tab.cpp"
    break;

  case 141: /* assignment: varmaybein "'is'" "text string"  */
#line 509 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetDisplayName(*((yyvsp[0].word)))) YYABORT;}
#line 3126 "antimony.tab.cpp"
    break;

  case 142: /* assignment: varmaybein ':' '=' formula  */
#line 510 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT;}
#line 3132 "antimony.tab.cpp"
    break;

  case 143: /* assignment: varmaybein '\'' '=' formula  */
#line 511 "antimony.ypp"
                                            {if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT;}
#line 3138 "antimony.tab.cpp"
    break;

  case 144: /* assignment: varmaybein "'has'" unitdef  */
#line 512 "antimony.ypp"
                                           {if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 3144 "antimony.tab.cpp"
    break;

  case 145: /* algrule: "number" '=' formula  */
#line 515 "antimony.ypp"
                                {if (g_registry.AddNewAlgebraicRuleToCurrent((yyvsp[-2].num), (yyvsp[0].formula))) YYABORT; }
#line 3150 "antimony.tab.cpp"
    break;

  case 146: /* algrule: varmaybein ':' "number" '=' formula  */
#line 516 "antimony.ypp"
                                               {if ((yyvsp[-4].variable)->SetAlgebraicRule((yyvsp[-2].num), (yyvsp[0].formula)) ) YYABORT;}
#line 3156 "antimony.tab.cpp"
    break;

  case 147: /* $@6: %empty  */
#line 519 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetModule((yyvsp[-1].word))) YYABORT;}
#line 3162 "antimony.tab.cpp"
    break;

  case 148: /* submodule: varmaybein ':' "name of an existing module" '(' $@6 variableimportlist ')' submodifications maybein  */
#line 519 "antimony.ypp"
                                                                                                                             {if ((yyvsp[0].variable) != NULL) {if ((yyvsp[-8].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 3168 "antimony.tab.cpp"
    break;

  case 149: /* $@7: %empty  */
#line 520 "antimony.ypp"
                            {if(g_registry.CurrentModule()->SetModule((yyvsp[-1].word))) YYABORT;}
#line 3174 "antimony.tab.cpp"
    break;

  case 150: /* submodule: "name of an existing module" '(' $@7 variableimportlist ')' submodifications maybein  */
#line 520 "antimony.ypp"
                                                                                                                                     {if ((yyvsp[0].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 3180 "antimony.tab.cpp"
    break;

  case 151: /* variableimportlist: %empty  */
#line 524 "antimony.ypp"
                            {}
#line 3186 "antimony.tab.cpp"
    break;

  case 152: /* variableimportlist: variable  */
#line 525 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 3192 "antimony.tab.cpp"
    break;

  case 153: /* variableimportlist: variableimportlist ',' variable  */
#line 526 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 3198 "antimony.tab.cpp"
    break;

  case 154: /* variableimportlist: "number"  */
#line 527 "antimony.ypp"
                    {if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 3204 "antimony.tab.cpp"
    break;

  case 155: /* variableimportlist: variableimportlist ',' "number"  */
#line 528 "antimony.ypp"
                                           { if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 3210 "antimony.tab.cpp"
    break;

  case 156: /* submodifications: %empty  */
#line 532 "antimony.ypp"
                            {}
#line 3216 "antimony.tab.cpp"
    break;

  case 157: /* submodifications: submodifications ',' "element name" '=' variable  */
#line 533 "antimony.ypp"
                                                          {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].variable));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 3224 "antimony.tab.cpp"
    break;

  case 158: /* submodifications: submodifications ',' "element name" '=' "number"  */
#line 537 "antimony.ypp"
                                                     {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].num));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 3232 "antimony.tab.cpp"
    break;

  case 159: /* varinitialize: specinit  */
#line 541 "antimony.ypp"
                         { }
#line 3238 "antimony.tab.cpp"
    break;

  case 160: /* varinitialize: formulainit  */
#line 542 "antimony.ypp"
                            { }
#line 3244 "antimony.tab.cpp"
    break;

  case 161: /* varinitialize: reactioninit  */
#line 543 "antimony.ypp"
                             { }
#line 3250 "antimony.tab.cpp"
    break;

  case 162: /* varinitialize: dnainit  */
#line 544 "antimony.ypp"
                        { }
#line 3256 "antimony.tab.cpp"
    break;

  case 163: /* varinitialize: geneinit  */
#line 545 "antimony.ypp"
                         { }
#line 3262 "antimony.tab.cpp"
    break;

  case 164: /* varinitialize: operatorinit  */
#line 546 "antimony.ypp"
                             { }
#line 3268 "antimony.tab.cpp"
    break;

  case 165: /* varinitialize: compartmentinit  */
#line 547 "antimony.ypp"
                                { }
#line 3274 "antimony.tab.cpp"
    break;

  case 166: /* varinitialize: varconstinit  */
#line 548 "antimony.ypp"
                             { }
#line 3280 "antimony.tab.cpp"
    break;

  case 167: /* specinit: "'species'" varmaybeis  */
#line 551 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3286 "antimony.tab.cpp"
    break;

  case 168: /* specinit: "'var'" "'species'" varmaybeis  */
#line 552 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3292 "antimony.tab.cpp"
    break;

  case 169: /* specinit: "'const'" "'species'" varmaybeis  */
#line 553 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3298 "antimony.tab.cpp"
    break;

  case 170: /* specinit: "'substanceOnly'" "'species'" varmaybeis  */
#line 554 "antimony.ypp"
                                             {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3304 "antimony.tab.cpp"
    break;

  case 171: /* specinit: "'substanceOnly'" varmaybeis  */
#line 555 "antimony.ypp"
                                     {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3310 "antimony.tab.cpp"
    break;

  case 172: /* specinit: "'var'" "'substanceOnly'" "'species'" varmaybeis  */
#line 556 "antimony.ypp"
                                                     {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3316 "antimony.tab.cpp"
    break;

  case 173: /* specinit: "'const'" "'substanceOnly'" "'species'" varmaybeis  */
#line 557 "antimony.ypp"
                                                       {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3322 "antimony.tab.cpp"
    break;

  case 174: /* specinit: specinit ',' varmaybeis  */
#line 558 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3328 "antimony.tab.cpp"
    break;

  case 175: /* specinit: "'species'" '.' "element name" '=' formula  */
#line 559 "antimony.ypp"
                                                {if (g_registry.CurrentModule()->AddSpeciesLayoutInfo((yyvsp[-2].word), (yyvsp[0].formula))) YYABORT;}
#line 3334 "antimony.tab.cpp"
    break;

  case 176: /* formulainit: "'formula'" varmaybeis  */
#line 562 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3340 "antimony.tab.cpp"
    break;

  case 177: /* formulainit: "'var'" "'formula'" varmaybeis  */
#line 563 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3346 "antimony.tab.cpp"
    break;

  case 178: /* formulainit: "'const'" "'formula'" varmaybeis  */
#line 564 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3352 "antimony.tab.cpp"
    break;

  case 179: /* formulainit: formulainit ',' varmaybeis  */
#line 565 "antimony.ypp"
                                           {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3358 "antimony.tab.cpp"
    break;

  case 180: /* reactioninit: "'reaction'" varmaybeis  */
#line 568 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3364 "antimony.tab.cpp"
    break;

  case 181: /* reactioninit: "'var'" "'reaction'" varmaybeis  */
#line 569 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3370 "antimony.tab.cpp"
    break;

  case 182: /* reactioninit: "'const'" "'reaction'"  */
#line 570 "antimony.ypp"
                                   {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; }
#line 3376 "antimony.tab.cpp"
    break;

  case 183: /* reactioninit: reactioninit ',' varmaybeis  */
#line 571 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3382 "antimony.tab.cpp"
    break;

  case 184: /* reactioninit: "'reaction'" '.' "element name" '=' formula  */
#line 572 "antimony.ypp"
                                                 {if (g_registry.CurrentModule()->AddReactionLayoutInfo((yyvsp[-2].word), (yyvsp[0].formula))) YYABORT;}
#line 3388 "antimony.tab.cpp"
    break;

  case 185: /* dnainit: "'DNA'" varmaybeis  */
#line 575 "antimony.ypp"
                               {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3394 "antimony.tab.cpp"
    break;

  case 186: /* dnainit: "'var'" "'DNA'" varmaybeis  */
#line 576 "antimony.ypp"
                                       {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3400 "antimony.tab.cpp"
    break;

  case 187: /* dnainit: "'const'" "'DNA'" varmaybeis  */
#line 577 "antimony.ypp"
                                         {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3406 "antimony.tab.cpp"
    break;

  case 188: /* dnainit: dnainit ',' varmaybeis  */
#line 578 "antimony.ypp"
                                       {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3412 "antimony.tab.cpp"
    break;

  case 189: /* geneinit: "'gene'" varmaybeis  */
#line 581 "antimony.ypp"
                                {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3418 "antimony.tab.cpp"
    break;

  case 190: /* geneinit: "'var'" "'gene'" varmaybeis  */
#line 582 "antimony.ypp"
                                        {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3424 "antimony.tab.cpp"
    break;

  case 191: /* geneinit: "'const'" "'gene'" varmaybeis  */
#line 583 "antimony.ypp"
                                          {g_registry.SetError("Genes may not be set 'const'."); YYABORT; }
#line 3430 "antimony.tab.cpp"
    break;

  case 192: /* geneinit: geneinit ',' varmaybeis  */
#line 584 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3436 "antimony.tab.cpp"
    break;

  case 193: /* operatorinit: "'operator'" varmaybeis  */
#line 587 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3442 "antimony.tab.cpp"
    break;

  case 194: /* operatorinit: "'var'" "'operator'" varmaybeis  */
#line 588 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3448 "antimony.tab.cpp"
    break;

  case 195: /* operatorinit: "'const'" "'operator'" varmaybeis  */
#line 589 "antimony.ypp"
                                              {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3454 "antimony.tab.cpp"
    break;

  case 196: /* operatorinit: operatorinit ',' varmaybeis  */
#line 590 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3460 "antimony.tab.cpp"
    break;

  case 197: /* compartmentinit: "'compartment'" varmaybeis  */
#line 594 "antimony.ypp"
                                       {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3466 "antimony.tab.cpp"
    break;

  case 198: /* compartmentinit: "'var'" "'compartment'" varmaybeis  */
#line 595 "antimony.ypp"
                                               {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3472 "antimony.tab.cpp"
    break;

  case 199: /* compartmentinit: "'const'" "'compartment'" varmaybeis  */
#line 596 "antimony.ypp"
                                                 {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3478 "antimony.tab.cpp"
    break;

  case 200: /* compartmentinit: compartmentinit ',' varmaybeis  */
#line 597 "antimony.ypp"
                                               {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3484 "antimony.tab.cpp"
    break;

  case 201: /* compartmentinit: "'compartment'" '.' "element name" '=' formula  */
#line 598 "antimony.ypp"
                                                    {if (g_registry.CurrentModule()->AddCompartmentLayoutInfo((yyvsp[-2].word), (yyvsp[0].formula))) YYABORT;}
#line 3490 "antimony.tab.cpp"
    break;

  case 202: /* varconstinit: "'var'" varmaybeis  */
#line 601 "antimony.ypp"
                                   {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst();}
#line 3496 "antimony.tab.cpp"
    break;

  case 203: /* varconstinit: "'const'" varmaybeis  */
#line 602 "antimony.ypp"
                                     {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst();}
#line 3502 "antimony.tab.cpp"
    break;

  case 204: /* varconstinit: varconstinit ',' varmaybeis  */
#line 603 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst();}
#line 3508 "antimony.tab.cpp"
    break;

  case 205: /* unitinit: "'unit'" variable '=' formula  */
#line 606 "antimony.ypp"
                                              {if ((yyvsp[-2].variable)->SetType(varUnitDefinition)) YYABORT;
                                               if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                                               if ((yyvsp[-2].variable)->GetUnitDef()->SetFromFormula((yyvsp[0].formula))) YYABORT;}
#line 3516 "antimony.tab.cpp"
    break;

  case 206: /* unitinit: "'unit'" variable  */
#line 609 "antimony.ypp"
                                  {if ((yyvsp[0].variable)->SetType(varUnitDefinition)) YYABORT;}
#line 3522 "antimony.tab.cpp"
    break;

  case 207: /* dnadef: dnastrand  */
#line 612 "antimony.ypp"
                          {if (g_registry.SaveWorkingStrand()) YYABORT;}
#line 3528 "antimony.tab.cpp"
    break;

  case 208: /* dnadef: varmaybein ':' dnastrand  */
#line 613 "antimony.ypp"
                                         {if (g_registry.SetStrandAs((yyvsp[-2].variable))) YYABORT;}
#line 3534 "antimony.tab.cpp"
    break;

  case 209: /* dnastrand: "--" variable  */
#line 616 "antimony.ypp"
                                {if (g_registry.SetNewUpstreamOpen((yyvsp[0].variable))) YYABORT;}
#line 3540 "antimony.tab.cpp"
    break;

  case 210: /* dnastrand: "--" dnamiddle  */
#line 617 "antimony.ypp"
                                 {g_registry.SetOpenUpstream(); }
#line 3546 "antimony.tab.cpp"
    break;

  case 211: /* dnastrand: dnamiddle variable  */
#line 618 "antimony.ypp"
                                   {if (g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3552 "antimony.tab.cpp"
    break;

  case 212: /* dnastrand: "--" dnamiddle variable  */
#line 619 "antimony.ypp"
                                          {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3558 "antimony.tab.cpp"
    break;

  case 213: /* dnastrand: dnamiddle  */
#line 620 "antimony.ypp"
                          { }
#line 3564 "antimony.tab.cpp"
    break;

  case 214: /* dnamiddle: variable "--"  */
#line 623 "antimony.ypp"
                                {if (g_registry.SetNewDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3570 "antimony.tab.cpp"
    break;

  case 215: /* dnamiddle: dnamiddle variable "--"  */
#line 624 "antimony.ypp"
                                          {if (g_registry.SetDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3576 "antimony.tab.cpp"
    break;

  case 216: /* $@8: %empty  */
#line 627 "antimony.ypp"
                           {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula))) YYABORT;}
#line 3582 "antimony.tab.cpp"
    break;

  case 217: /* event: "'at'" formula $@8 eventmodifications colonret assignmentlist  */
#line 627 "antimony.ypp"
                                                                                                                        {}
#line 3588 "antimony.tab.cpp"
    break;

  case 218: /* $@9: %empty  */
#line 628 "antimony.ypp"
                                         {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula))) YYABORT;}
#line 3594 "antimony.tab.cpp"
    break;

  case 219: /* event: "'at'" formula "'after'" formula $@9 eventmodifications colonret assignmentlist  */
#line 628 "antimony.ypp"
                                                                                                                                          {}
#line 3600 "antimony.tab.cpp"
    break;

  case 220: /* $@10: %empty  */
#line 629 "antimony.ypp"
                                          {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula), (yyvsp[-3].variable))) YYABORT;}
#line 3606 "antimony.tab.cpp"
    break;

  case 221: /* event: varmaybein ':' "'at'" formula $@10 eventmodifications colonret assignmentlist  */
#line 629 "antimony.ypp"
                                                                                                                                            {}
#line 3612 "antimony.tab.cpp"
    break;

  case 222: /* $@11: %empty  */
#line 630 "antimony.ypp"
                                                        {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula), (yyvsp[-5].variable))) YYABORT;}
#line 3618 "antimony.tab.cpp"
    break;

  case 223: /* event: varmaybein ':' "'at'" formula "'after'" formula $@11 eventmodifications colonret assignmentlist  */
#line 630 "antimony.ypp"
                                                                                                                                                             {}
#line 3624 "antimony.tab.cpp"
    break;

  case 224: /* colonret: ':'  */
#line 633 "antimony.ypp"
                    {}
#line 3630 "antimony.tab.cpp"
    break;

  case 225: /* colonret: colonret '\n'  */
#line 634 "antimony.ypp"
                              {}
#line 3636 "antimony.tab.cpp"
    break;

  case 226: /* eventmodifications: %empty  */
#line 637 "antimony.ypp"
                                 {}
#line 3642 "antimony.tab.cpp"
    break;

  case 227: /* eventmodifications: eventmodifications ',' "element name" '=' formula  */
#line 638 "antimony.ypp"
                                                           {if (CaselessStrCmp(false, *(yyvsp[-2].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[0].formula));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[0].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;}}
#line 3652 "antimony.tab.cpp"
    break;

  case 228: /* assignmentlist: variable '=' formula  */
#line 645 "antimony.ypp"
                                     {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3658 "antimony.tab.cpp"
    break;

  case 229: /* assignmentlist: variable '=' formula ':' assignmentlist  */
#line 646 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3664 "antimony.tab.cpp"
    break;

  case 230: /* assignmentlist: variable '=' formula ':' '\n' assignmentlist  */
#line 647 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3670 "antimony.tab.cpp"
    break;

  case 231: /* assignmentlist: variable '=' formula ',' assignmentlist  */
#line 648 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3676 "antimony.tab.cpp"
    break;

  case 232: /* assignmentlist: variable '=' formula ',' '\n' assignmentlist  */
#line 649 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3682 "antimony.tab.cpp"
    break;

  case 233: /* deletion: "'delete'" variable  */
#line 652 "antimony.ypp"
                                    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3688 "antimony.tab.cpp"
    break;

  case 234: /* deletion: deletion ',' variable  */
#line 653 "antimony.ypp"
                                      {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3694 "antimony.tab.cpp"
    break;

  case 235: /* unitdef: formula  */
#line 656 "antimony.ypp"
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
#line 3712 "antimony.tab.cpp"
    break;

  case 236: /* constraint: "number" inequality formula  */
#line 671 "antimony.ypp"
                                       {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3718 "antimony.tab.cpp"
    break;

  case 237: /* constraint: '-' "number" inequality formula  */
#line 672 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint(-(yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3724 "antimony.tab.cpp"
    break;

  case 238: /* constraint: "name of a pre-defined constant" inequality formula  */
#line 673 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3730 "antimony.tab.cpp"
    break;

  case 239: /* constraint: "element name" inequality formula  */
#line 674 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3736 "antimony.tab.cpp"
    break;

  case 240: /* constraint: "'constraint'" ':' formula  */
#line 675 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[0].formula))) YYABORT;}
#line 3742 "antimony.tab.cpp"
    break;

  case 241: /* constraint: "'constraint'" variable ':' formula  */
#line 676 "antimony.ypp"
                                                    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3748 "antimony.tab.cpp"
    break;

  case 242: /* objective: maxormin formula  */
#line 679 "antimony.ypp"
                                              {if (g_registry.CurrentModule()->AddObjective((yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 3754 "antimony.tab.cpp"
    break;

  case 243: /* maxormin: "'maximize'"  */
#line 682 "antimony.ypp"
                             {(yyval.maxormin) = true;}
#line 3760 "antimony.tab.cpp"
    break;

  case 244: /* maxormin: "'minimize'"  */
#line 683 "antimony.ypp"
                             {(yyval.maxormin) = false;}
#line 3766 "antimony.tab.cpp"
    break;

  case 245: /* stringlist: "text string"  */
#line 686 "antimony.ypp"
                           { (yyval.stringlist) = new std::vector<std::string>(); (yyval.stringlist)->push_back(*((yyvsp[0].word))); }
#line 3772 "antimony.tab.cpp"
    break;

  case 246: /* stringlist: stringlist ',' "text string"  */
#line 687 "antimony.ypp"
                                          { (yyval.stringlist) = (yyvsp[-2].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3778 "antimony.tab.cpp"
    break;

  case 247: /* stringlist: stringlist ',' '\n' "text string"  */
#line 688 "antimony.ypp"
                                               { (yyval.stringlist) = (yyvsp[-3].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3784 "antimony.tab.cpp"
    break;

  case 248: /* $@12: %empty  */
#line 690 "antimony.ypp"
                                    {if (g_registry.SetCurrentModuleIf((yyvsp[0].word), (yyvsp[-1].word))) YYABORT;}
#line 3790 "antimony.tab.cpp"
    break;

  case 249: /* annotationBlock: "element name" "name of an existing module" $@12 annotations "'end'"  */
#line 690 "antimony.ypp"
                                                                                                          {g_registry.RevertToPreviousModule();}
#line 3796 "antimony.tab.cpp"
    break;

  case 250: /* annotations: %empty  */
#line 693 "antimony.ypp"
                            {}
#line 3802 "antimony.tab.cpp"
    break;

  case 251: /* annotations: "element name" ':' stringlist  */
#line 694 "antimony.ypp"
                                       {string modname = g_registry.CurrentModuleName(); g_registry.ProcessGlobalCVTerm(&modname, (yyvsp[-2].word), (yyvsp[0].stringlist));}
#line 3808 "antimony.tab.cpp"
    break;

  case 252: /* cvterm: variable "element name" stringlist  */
#line 699 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->ProcessCVTerm((yyvsp[-2].variable),(yyvsp[-1].word),(yyvsp[0].stringlist))) YYABORT;}
#line 3814 "antimony.tab.cpp"
    break;

  case 253: /* cvterm: variable "element name" '.' "element name" stringlist  */
#line 700 "antimony.ypp"
                                                        {if (g_registry.ProcessCreatorTerm((yyvsp[-4].variable), (yyvsp[-3].word), (yyvsp[-1].word), (yyvsp[0].stringlist))) YYABORT;}
#line 3820 "antimony.tab.cpp"
    break;

  case 254: /* cvterm: variable "element name" '.' "element name" "number"  */
#line 701 "antimony.ypp"
                                                 {if (g_registry.ProcessCreatorTerm((yyvsp[-4].variable), (yyvsp[-3].word), (yyvsp[-1].word), (yyvsp[0].num))) YYABORT;}
#line 3826 "antimony.tab.cpp"
    break;

  case 255: /* toplevel_sbo: "name of an existing module" '.' "element name" '=' "number"  */
#line 705 "antimony.ypp"
                  { Module* module = g_registry.GetModule(*(yyvsp[-4].word));
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      module->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3840 "antimony.tab.cpp"
    break;

  case 256: /* toplevel_sbo: "name of an existing function" '.' "element name" '=' "number"  */
#line 716 "antimony.ypp"
                  { Module* function = g_registry.GetModule(*(yyvsp[-4].word));
                    if (function && (yyvsp[-2].word) &&  CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      function->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can set '" + *((yyvsp[-4].word)) + "' to a number is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3854 "antimony.tab.cpp"
    break;

  case 257: /* toplevel_sbo: "name of an existing module" '.' "element name" '=' stringConstant  */
#line 726 "antimony.ypp"
                  { Module* function = g_registry.GetModule(*(yyvsp[-4].word));
                    if (function && (yyvsp[-2].word) &&  CaselessStrCmp(true, *((yyvsp[-2].word)), "autolayout")) {
                      if (function->SetLayout((yyvsp[0].word))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can set on '" + *((yyvsp[-4].word)) + "' to a string is 'layout'.");
                      YYABORT;
                    }
                  }
#line 3868 "antimony.tab.cpp"
    break;

  case 258: /* toplevel_sbo: "name of an existing module" '.' "element name" '.' "element name" '=' "number"  */
#line 736 "antimony.ypp"
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
#line 3886 "antimony.tab.cpp"
    break;

  case 259: /* toplevel_sbo: "name of an existing module" '.' "element name" '.' "element name" '=' stringConstant  */
#line 750 "antimony.ypp"
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
#line 3904 "antimony.tab.cpp"
    break;

  case 260: /* toplevel_sbo: "name of an existing module" '.' "element name" '.' "element name" '=' '{' variablelist '}'  */
#line 764 "antimony.ypp"
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
#line 3922 "antimony.tab.cpp"
    break;

  case 261: /* toplevel_sbo: "name of an existing module" '.' "element name" '.' "element name" '=' '{' numlist '}'  */
#line 778 "antimony.ypp"
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
#line 3940 "antimony.tab.cpp"
    break;

  case 262: /* modulename: "name of an existing module" "'is'" "text string" lineend  */
#line 794 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3946 "antimony.tab.cpp"
    break;

  case 263: /* functionname: "name of an existing function" "'is'" "text string" lineend  */
#line 796 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3952 "antimony.tab.cpp"
    break;

  case 264: /* modulecvterm: "name of an existing module" "element name" stringlist lineend  */
#line 799 "antimony.ypp"
                                                   {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3958 "antimony.tab.cpp"
    break;

  case 265: /* modulecvterm: "name of an existing module" "element name" '.' "element name" stringlist lineend  */
#line 800 "antimony.ypp"
                                                               {if (g_registry.ProcessGlobalCreatorTerm((yyvsp[-5].word), (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].stringlist))) YYABORT;}
#line 3964 "antimony.tab.cpp"
    break;

  case 266: /* modulecvterm: "name of an existing module" "element name" '.' "element name" "number" lineend  */
#line 801 "antimony.ypp"
                                                        {if (g_registry.ProcessGlobalCreatorTerm((yyvsp[-5].word), (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].num))) YYABORT;}
#line 3970 "antimony.tab.cpp"
    break;

  case 267: /* functioncvterm: "name of an existing function" "element name" stringlist lineend  */
#line 802 "antimony.ypp"
                                                    {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3976 "antimony.tab.cpp"
    break;


#line 3980 "antimony.tab.cpp"

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

#line 804 "antimony.ypp"



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
