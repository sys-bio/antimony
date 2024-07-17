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
  YYSYMBOL_variablelist = 88,              /* variablelist  */
  YYSYMBOL_numlist = 89,                   /* numlist  */
  YYSYMBOL_modulepart = 90,                /* modulepart  */
  YYSYMBOL_reaction = 91,                  /* reaction  */
  YYSYMBOL_reactantList = 92,              /* reactantList  */
  YYSYMBOL_reactionDivider = 93,           /* reactionDivider  */
  YYSYMBOL_formula = 94,                   /* formula  */
  YYSYMBOL_commaformula = 95,              /* commaformula  */
  YYSYMBOL_mathThing = 96,                 /* mathThing  */
  YYSYMBOL_inequality = 97,                /* inequality  */
  YYSYMBOL_lineend = 98,                   /* lineend  */
  YYSYMBOL_assignment = 99,                /* assignment  */
  YYSYMBOL_algrule = 100,                  /* algrule  */
  YYSYMBOL_submodule = 101,                /* submodule  */
  YYSYMBOL_102_6 = 102,                    /* $@6  */
  YYSYMBOL_103_7 = 103,                    /* $@7  */
  YYSYMBOL_variableimportlist = 104,       /* variableimportlist  */
  YYSYMBOL_submodifications = 105,         /* submodifications  */
  YYSYMBOL_varinitialize = 106,            /* varinitialize  */
  YYSYMBOL_specinit = 107,                 /* specinit  */
  YYSYMBOL_formulainit = 108,              /* formulainit  */
  YYSYMBOL_reactioninit = 109,             /* reactioninit  */
  YYSYMBOL_dnainit = 110,                  /* dnainit  */
  YYSYMBOL_geneinit = 111,                 /* geneinit  */
  YYSYMBOL_operatorinit = 112,             /* operatorinit  */
  YYSYMBOL_compartmentinit = 113,          /* compartmentinit  */
  YYSYMBOL_varconstinit = 114,             /* varconstinit  */
  YYSYMBOL_unitinit = 115,                 /* unitinit  */
  YYSYMBOL_dnadef = 116,                   /* dnadef  */
  YYSYMBOL_dnastrand = 117,                /* dnastrand  */
  YYSYMBOL_dnamiddle = 118,                /* dnamiddle  */
  YYSYMBOL_event = 119,                    /* event  */
  YYSYMBOL_120_8 = 120,                    /* $@8  */
  YYSYMBOL_121_9 = 121,                    /* $@9  */
  YYSYMBOL_122_10 = 122,                   /* $@10  */
  YYSYMBOL_123_11 = 123,                   /* $@11  */
  YYSYMBOL_colonret = 124,                 /* colonret  */
  YYSYMBOL_eventmodifications = 125,       /* eventmodifications  */
  YYSYMBOL_assignmentlist = 126,           /* assignmentlist  */
  YYSYMBOL_deletion = 127,                 /* deletion  */
  YYSYMBOL_unitdef = 128,                  /* unitdef  */
  YYSYMBOL_constraint = 129,               /* constraint  */
  YYSYMBOL_objective = 130,                /* objective  */
  YYSYMBOL_maxormin = 131,                 /* maxormin  */
  YYSYMBOL_stringlist = 132,               /* stringlist  */
  YYSYMBOL_annotationBlock = 133,          /* annotationBlock  */
  YYSYMBOL_134_12 = 134,                   /* $@12  */
  YYSYMBOL_annotations = 135,              /* annotations  */
  YYSYMBOL_cvterm = 136,                   /* cvterm  */
  YYSYMBOL_toplevel_sbo = 137,             /* toplevel_sbo  */
  YYSYMBOL_modulename = 138,               /* modulename  */
  YYSYMBOL_functionname = 139,             /* functionname  */
  YYSYMBOL_modulecvterm = 140,             /* modulecvterm  */
  YYSYMBOL_functioncvterm = 141            /* functioncvterm  */
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
#define YYLAST   1365

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  264
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  514

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
       0,   162,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   178,   181,   181,   187,
     187,   193,   193,   199,   199,   204,   205,   208,   208,   209,
     210,   213,   214,   215,   225,   226,   227,   230,   231,   237,
     240,   243,   244,   247,   248,   249,   250,   251,   254,   255,
     258,   259,   260,   261,   264,   269,   274,   279,   289,   299,
     309,   323,   337,   351,   367,   368,   369,   372,   373,   374,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   393,   401,   409,   417,   425,   433,
     443,   444,   445,   446,   447,   448,   452,   453,   454,   455,
     456,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   475,   476,   479,   480,   481,
     482,   483,   484,   485,   488,   489,   490,   491,   492,   495,
     496,   497,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   511,   512,   515,   515,   516,   516,   520,   521,   522,
     523,   524,   528,   529,   533,   537,   538,   539,   540,   541,
     542,   543,   544,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   558,   559,   560,   561,   564,   565,   566,   567,
     568,   571,   572,   573,   574,   577,   578,   579,   580,   583,
     584,   585,   586,   590,   591,   592,   593,   594,   597,   598,
     599,   602,   605,   608,   609,   612,   613,   614,   615,   616,
     619,   620,   623,   623,   624,   624,   625,   625,   626,   626,
     629,   630,   633,   634,   641,   642,   643,   644,   645,   648,
     649,   652,   667,   668,   669,   670,   671,   672,   675,   678,
     679,   682,   683,   684,   686,   686,   689,   690,   695,   696,
     697,   700,   711,   721,   731,   741,   755,   769,   783,   799,
     801,   805,   806,   807,   808
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
  "variablelist", "numlist", "modulepart", "reaction", "reactantList",
  "reactionDivider", "formula", "commaformula", "mathThing", "inequality",
  "lineend", "assignment", "algrule", "submodule", "$@6", "$@7",
  "variableimportlist", "submodifications", "varinitialize", "specinit",
  "formulainit", "reactioninit", "dnainit", "geneinit", "operatorinit",
  "compartmentinit", "varconstinit", "unitinit", "dnadef", "dnastrand",
  "dnamiddle", "event", "$@8", "$@9", "$@10", "$@11", "colonret",
  "eventmodifications", "assignmentlist", "deletion", "unitdef",
  "constraint", "objective", "maxormin", "stringlist", "annotationBlock",
  "$@12", "annotations", "cvterm", "toplevel_sbo", "modulename",
  "functionname", "modulecvterm", "functioncvterm", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-403)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-91)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -403,   759,  -403,  -403,   133,    25,  -403,   240,   285,  -403,
    -403,  -403,  -403,  -403,   196,   360,   143,   326,    25,    25,
      25,  -403,    25,   287,   275,    25,    74,  -403,  -403,   250,
     278,    25,   303,   409,   286,    25,   396,  -403,  -403,  -403,
    -403,  -403,   352,   107,   174,  -403,  -403,    61,   497,   403,
    -403,    61,    61,    61,    61,    -8,    72,   101,   158,   182,
     185,   251,   289,    61,    61,  -403,    25,    61,   147,    61,
      61,  -403,  -403,    61,  -403,  -403,  -403,  -403,  -403,   360,
    -403,  -403,    44,  -403,  -403,  -403,  -403,  -403,  -403,    44,
    -403,  -403,  -403,   886,    41,   111,  -403,   321,  -403,  -403,
    -403,   126,    25,    25,    25,    25,    25,  -403,    25,   282,
    -403,   122,    25,    44,  -403,  -403,    46,   315,   336,  -403,
    -403,  -403,  -403,  -403,   376,   229,   344,  -403,   388,   397,
     216,  -403,  -403,  -403,   407,  -403,   414,  -403,    25,  -403,
       1,    25,    25,    25,    25,    25,    25,    25,   390,  -403,
     438,   232,  -403,    25,    44,    25,  -403,   104,  -403,   493,
     399,  -403,   410,   417,    47,    25,   460,     3,  -403,  -403,
    -403,  -403,    25,    25,    25,    25,    25,    25,    25,    25,
    -403,  -403,   284,  -403,    25,  -403,  -403,  -403,  1081,  -403,
    -403,  1081,  1081,   463,  1081,   478,   479,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
     435,  -403,  -403,    44,  -403,  -403,  -403,   436,  -403,  -403,
     442,   447,  1081,  1081,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,    25,   284,   450,  -403,   225,    61,   441,     7,   506,
     225,    61,   510,   468,   110,   514,   481,  1300,   225,   484,
     485,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
      25,  -403,   529,   490,    44,    13,  1081,  -403,  -403,   357,
    1081,    37,  -403,   494,  -403,   437,   497,   403,  -403,  -403,
    -403,    25,   460,  -403,     5,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,    44,  1081,   489,   520,  -403,
    -403,  1081,  1081,   244,  -403,   293,   217,  -403,  -403,  1081,
    -403,  -403,  1081,  -403,   538,   209,  -403,  -403,    25,   537,
     297,   191,  -403,  -403,  -403,    44,   261,   499,  1300,   539,
     324,   211,    25,   360,   501,   374,   173,  -403,  -403,  -403,
    -403,  -403,  1081,  -403,   235,    25,    25,  -403,   951,  -403,
    1081,   105,    15,  1081,  1081,    44,    44,  1016,  -403,  1016,
     315,  -403,  -403,  -403,  -403,  -403,   542,  -403,    28,  1081,
    1081,  1081,  -403,  -403,   507,   380,    44,   503,  -403,  -403,
    -403,    61,   225,  -403,   517,    25,  1138,   505,  -403,  -403,
    -403,    61,   225,   382,   241,  -403,  -403,  -403,  1081,  1081,
    -403,   490,    44,    44,  1081,  -403,  -403,   510,  -403,    16,
    -403,    25,  -403,  1016,  -403,   490,   217,  1081,   508,  -403,
     125,  -403,  -403,    61,    25,   119,  -403,  -403,    -3,  -403,
      44,   394,  -403,   234,  -403,  -403,  1300,  1081,   217,   433,
    1016,  -403,  1016,    44,  -403,    28,  -403,  -403,   201,  1081,
      61,    44,  -403,  -403,   518,   548,  -403,  1300,  -403,  -403,
     518,  1192,  -403,    28,  -403,  -403,  1016,  -403,  -403,  1081,
     821,  -403,  -403,    61,  -403,    44,   299,   337,   509,  1246,
     411,   418,  -403,   217,  -403,    -3,  -403,    34,    65,   116,
    -403,    12,  -403,   530,  -403,  -403,  -403,    28,  -403,    25,
    -403,    25,  -403,    25,    44,  -403,   555,  -403,    44,  -403,
    -403,  -403,    44,  -403
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,    14,     0,     0,   131,     0,    37,   101,
      96,    97,    99,   100,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,   239,   240,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   129,     3,
       4,     6,    41,    79,     0,    13,     5,     0,     0,     0,
      83,     0,     0,     0,     0,   155,   156,   157,   158,   159,
     160,   161,   162,     0,     0,   203,   209,     0,     0,     0,
       0,   101,    12,     0,    11,     7,     8,     9,    10,     0,
      98,    37,    39,   127,   128,   125,   101,   124,   126,    91,
     101,   244,   101,   212,     0,    41,    42,    43,   193,   101,
     101,     0,     0,     0,     0,     0,     0,   178,     0,     0,
     199,   205,   206,   229,   181,   172,     0,     0,     0,    27,
      30,    29,   185,    16,     0,     0,     0,   145,     0,     0,
      19,    26,    25,   189,     0,   176,     0,   163,     0,   167,
     202,     0,     0,     0,     0,     0,     0,     0,     0,   198,
       0,    37,   210,     0,    92,     0,   101,     0,   101,     0,
       0,    70,     0,     0,     0,     0,    90,     0,    71,    82,
      72,    73,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    74,   207,    75,     0,    77,    80,    81,   238,    78,
     101,   141,   232,   246,   235,     0,     0,   118,   117,   119,
     120,   123,   121,   104,   101,   105,   102,   106,   114,   101,
       0,   101,   122,   103,   109,   110,   222,     0,   101,   101,
       0,     0,   234,   236,   101,   195,   183,   174,   187,   191,
     165,     0,   208,     0,   241,     0,     0,     0,     0,     0,
       0,     0,   147,    23,     0,     0,     0,     0,     0,     0,
       0,   166,   101,   194,   182,   173,   186,   190,   177,   164,
       0,    38,     0,   248,    40,     0,   231,   140,   137,   134,
     133,     0,   101,     0,   101,    90,     0,     0,   204,   101,
     101,     0,    93,   101,     0,   101,   170,   175,   179,   184,
     188,   192,   196,   200,   211,   230,   233,     0,     0,   112,
     113,   214,   115,     0,   111,     0,     0,   101,    47,    44,
     101,   101,   237,   169,     0,     0,   264,   260,    34,     0,
       0,     0,   261,   259,   150,   148,     0,     0,     0,     0,
       0,     0,    34,    37,     0,     0,     0,    51,    50,    54,
     101,   101,   201,   168,     0,     0,     0,   101,   216,   143,
     138,     0,     0,   132,   139,    94,    95,    48,   101,    48,
       0,   245,   222,   107,   101,   108,     0,   220,     0,   197,
      45,    46,   252,   242,     0,     0,    35,     0,   251,   253,
     254,     0,     0,   152,     0,    34,     0,     0,    57,    58,
      59,     0,     0,     0,     0,    20,    53,    52,   180,   171,
     250,   249,   136,   135,   142,   101,   222,   147,   101,     0,
     101,     0,    86,    48,    88,   247,     0,   116,     0,   221,
       0,   213,   243,   101,     0,     0,   263,   262,    48,   151,
     149,     0,    24,     0,    56,    55,     0,   218,     0,     0,
      48,   101,    48,    49,    85,     0,   101,   101,     0,    31,
     101,    36,   255,   256,     0,     0,   146,     0,    60,    61,
       0,     0,   222,     0,   152,    87,    48,    89,   215,   223,
     224,    28,    33,    32,    67,    64,     0,     0,     0,     0,
       0,     0,    18,     0,   217,    48,    84,     0,     0,     0,
     257,     0,   258,     0,    22,    62,    63,     0,   144,     0,
     227,     0,   225,     0,    65,    68,     0,   154,   153,   219,
     228,   226,    66,    69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
     121,  -294,    -1,     0,     6,   541,  -334,  -326,     4,   118,
     120,    10,  -403,   -46,   -40,   317,   365,  -403,    21,    20,
    -403,  -403,  -403,  -403,  -403,   172,   117,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,   423,   565,
    -403,  -403,  -403,  -403,  -403,  -369,  -353,  -402,  -403,   366,
    -403,  -403,   426,   -73,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    39,    40,   246,   247,   327,   328,    41,   237,
     448,   375,   213,    96,    97,    98,   412,   336,   337,   476,
     477,   338,    47,    48,    49,   266,   303,   214,   215,    50,
      51,    52,    53,   407,   242,   326,   428,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,   216,   362,   406,   462,   368,   306,   421,    68,   267,
      69,    70,    71,   248,    72,   193,   298,    73,    74,    75,
      76,    77,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    43,   386,   167,    82,    45,    89,    44,   164,   416,
     163,    46,   163,    95,   150,   101,    95,   111,   113,    95,
     319,    95,   163,   163,    95,   414,   150,   505,    90,    92,
      95,    95,    95,    95,   140,    95,    99,     5,   393,   411,
       5,   154,    81,   468,   235,    81,     5,   445,   166,     5,
     172,    81,   240,   438,    81,   455,   345,   150,   217,     5,
     252,   484,   165,   233,    81,   182,   320,   161,   285,   463,
     358,   168,   169,   170,   171,     6,   506,     5,   263,   444,
     410,   441,    81,   180,   181,   500,   502,   183,   185,   186,
     187,   431,   419,   189,   456,   509,   347,   510,   499,   511,
     190,    95,    95,    95,    95,    95,   465,    95,   467,   483,
     461,   232,   283,   276,   497,   -42,     5,     5,   284,   277,
     165,    81,    81,   329,   150,    37,    38,   123,     5,   501,
     173,   479,   486,    81,   452,   150,   453,    95,   150,   150,
      95,    95,    95,    95,    95,    95,    95,   -42,    79,   152,
     -42,   498,   264,   153,   265,     5,   269,   268,   275,   174,
      81,     6,   282,   166,    89,   154,   -42,   -42,   -42,   330,
     408,    95,    95,    95,    95,    95,    95,    95,    95,     4,
     503,   454,   155,   295,   447,     5,   224,     6,     7,    80,
     333,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   100,   395,   184,   381,    22,     5,    94,
      25,    37,    38,    81,   156,     6,   175,   157,    27,    28,
     334,   335,    31,    32,    33,    34,   391,    35,    36,   245,
      95,   352,   471,   158,   159,   160,   351,    37,    38,     6,
     176,   325,   239,   177,   234,   262,    42,    43,   382,   458,
     400,   459,     5,    44,   245,   316,   317,    81,   392,    95,
     322,   323,   373,   124,   234,    37,    38,   125,   339,   234,
      89,   401,   -17,   374,   154,   366,   166,   367,    83,    84,
     355,   356,   234,   315,    85,   234,   128,   415,   234,    37,
      38,   129,   119,   126,   234,   130,   460,   150,     5,    86,
     116,   363,   364,    81,   117,   409,   127,    87,    88,   178,
     120,   294,   378,   131,   379,     5,   134,   376,   383,   384,
      81,   380,   121,    83,    84,   132,    93,    42,    43,    85,
     118,   376,    91,   231,    44,    42,    43,   138,     5,   388,
     396,   389,    44,    81,   402,   403,   397,   179,   390,   102,
     166,   364,    87,    88,    92,   103,   365,   489,   -90,   -90,
     104,   218,   490,   105,     5,   150,   346,   420,   234,   151,
     150,   -90,   -90,   -90,   -90,   106,   107,   108,   109,   152,
     219,   220,   221,   430,   376,    42,    43,   129,   188,   236,
     396,   394,    44,   238,   153,   491,   397,   241,    83,    84,
     492,   426,   427,   191,    85,   243,   325,   192,     5,   194,
     443,   434,   435,    81,   244,     5,   222,   223,   165,   141,
      81,     5,   136,   451,   249,   142,    81,    87,    88,     5,
     143,   250,   281,   144,    81,    42,    43,   423,   424,   436,
     424,   260,    44,   450,   420,   145,   146,   147,   148,     5,
     150,   457,   424,   475,    81,   261,    42,    43,   280,   475,
      42,    43,   420,    44,   152,   396,    80,    44,   472,   489,
     450,   397,     5,   150,   495,   270,   491,    81,    42,    43,
     297,   496,   299,   396,   300,    44,   420,   420,   504,   397,
     464,   384,   508,   472,   304,   307,   420,   318,   420,   162,
     420,   310,   512,   162,   163,     5,   311,   296,   271,   314,
      81,   272,    10,    11,    12,    13,    10,    11,    12,    13,
      18,   301,     5,   321,   -21,   324,   302,    81,   302,     5,
       5,   331,   429,   474,    81,    81,   309,   332,    27,    28,
     273,   312,     5,   340,   341,   507,   344,    81,   315,   360,
     349,   361,   274,   372,   377,   385,   387,   127,   110,   418,
     422,   114,   425,   115,   433,   478,   122,   446,   493,   342,
     513,   473,   133,   135,   137,   139,   305,   149,   480,   439,
     481,   485,   278,   112,   308,   279,     0,     0,     0,   348,
       0,   350,     0,     0,     0,     0,   353,   354,     0,     0,
     357,     0,   359,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   369,     0,     0,   370,   371,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,   226,   227,   228,   229,     0,   230,
       0,     0,     0,     0,     0,     0,     0,   398,   399,     0,
       0,     0,     0,     0,   404,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   413,     0,     0,     0,   251,
       0,   417,   253,   254,   255,   256,   257,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,   287,   288,   289,   290,   291,   292,
     293,     0,   437,     0,     0,   440,     0,   442,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     449,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   466,     2,
       3,     0,     0,   469,   470,     4,     0,   449,     0,     0,
       0,     5,   313,     6,     7,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,    21,     0,    22,    23,    24,    25,     0,     0,     0,
      26,   343,     0,     0,    27,    28,    29,    30,    31,    32,
      33,    34,     0,    35,    36,     0,     0,     0,     0,     0,
       0,     0,     0,    37,    38,   195,   196,   197,   198,   199,
     200,   201,   202,     5,     0,     0,   203,     0,    81,     0,
       0,     0,     0,     0,     0,   205,     0,     0,     0,     0,
       0,   206,     0,     0,     0,     0,   207,     0,     0,    83,
      84,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,   208,     0,     0,   209,     0,   487,
     210,   488,     0,   211,     0,     0,     0,   212,    87,    88,
     195,   196,   197,   198,   199,   200,   201,   202,     5,     0,
       0,   203,   204,    81,     0,     0,     0,     0,     0,     0,
     205,     0,     0,     0,     0,     0,   206,     0,     0,     0,
       0,   207,     0,     0,    83,    84,     0,     0,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,   208,
       0,     0,   209,     0,     0,   210,     0,     0,   211,     0,
       0,     0,   212,    87,    88,   195,   196,   197,   198,   199,
     200,   201,   202,     5,     0,     0,   203,   405,    81,     0,
       0,     0,     0,     0,     0,   205,     0,     0,     0,     0,
       0,   206,     0,     0,     0,     0,   207,     0,     0,    83,
      84,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,   208,     0,     0,   209,     0,     0,
     210,     0,     0,   211,     0,     0,     0,   212,    87,    88,
     195,   196,   197,   198,   199,   200,   201,   202,     5,     0,
       0,   203,     0,    81,     0,     0,     0,     0,     0,     0,
     205,     0,     0,     0,     0,     0,   206,     0,     0,     0,
       0,   207,     0,     0,    83,    84,     0,     0,   411,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,   208,
       0,     0,   209,     0,     0,   210,     0,     0,   211,     0,
       0,     0,   212,    87,    88,   195,   196,   197,   198,   199,
     200,   201,   202,     5,     0,     0,   203,     0,    81,     0,
       0,     0,     0,     0,     0,   205,     0,     0,     0,     0,
       0,   206,     0,     0,     0,     0,   207,     0,     0,    83,
      84,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,   208,     0,     0,   209,     0,     0,
     210,     0,     0,   211,     4,     0,     0,   212,    87,    88,
       5,     0,     6,     7,     0,   333,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,   432,
       0,     0,    22,     0,     0,    25,     0,     0,     0,     0,
       0,     0,     0,    27,    28,   334,   335,    31,    32,    33,
      34,     0,    35,    36,     0,     0,     0,     0,     4,     0,
       0,     0,    37,    38,     5,     0,     6,     7,     0,   333,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,   482,     0,     0,    22,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,    27,    28,   334,
     335,    31,    32,    33,    34,     0,    35,    36,     0,     0,
       0,     0,     4,     0,     0,     0,    37,    38,     5,     0,
       6,     7,     0,   333,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,   494,     0,     0,
      22,     0,     0,    25,     0,     0,     0,     0,     0,     0,
       0,    27,    28,   334,   335,    31,    32,    33,    34,     0,
      35,    36,     0,     0,     0,     0,     4,     0,     0,     0,
      37,    38,     5,     0,     6,     7,     0,   333,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,    22,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,    27,    28,   334,   335,    31,
      32,    33,    34,     0,    35,    36,     0,     0,     0,     0,
       0,     0,     0,     0,    37,    38
};

static const yytype_int16 yycheck[] =
{
       1,     1,   328,    49,     5,     1,     7,     1,    48,   362,
       7,     1,     7,    14,    13,    16,    17,    18,    19,    20,
      13,    22,     7,     7,    25,   359,    13,    15,     7,     8,
      31,    32,    33,    34,    35,    36,    15,    12,   332,    42,
      12,    42,    17,   445,   117,    17,    12,   416,    49,    12,
      58,    17,   125,   406,    17,    58,    43,    13,    17,    12,
      59,   463,    15,    17,    17,    66,    59,    47,    65,   438,
      65,    51,    52,    53,    54,    14,    64,    12,   151,   413,
      65,    65,    17,    63,    64,   487,   488,    67,    68,    69,
      70,   385,    64,    73,   428,   497,    59,   499,    64,   501,
      79,   102,   103,   104,   105,   106,   440,   108,   442,   462,
     436,   112,    65,   159,   483,     8,    12,    12,   164,   159,
      15,    17,    17,    13,    13,    64,    65,    53,    12,    64,
      58,   457,   466,    17,    15,    13,    17,   138,    13,    13,
     141,   142,   143,   144,   145,   146,   147,    40,    15,    27,
      43,   485,   153,    42,   155,    12,   157,    53,   159,    58,
      17,    14,   163,   164,   165,   166,    59,    60,    61,    59,
      65,   172,   173,   174,   175,   176,   177,   178,   179,     6,
      64,    62,     8,   184,    59,    12,    60,    14,    15,    56,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    60,    31,    58,    15,    34,    12,    13,
      37,    64,    65,    17,    40,    14,    58,    43,    45,    46,
      47,    48,    49,    50,    51,    52,    15,    54,    55,    13,
     231,   277,    31,    59,    60,    61,   276,    64,    65,    14,
      58,   242,    13,    58,    53,    13,   247,   247,   321,    15,
      15,    17,    12,   247,    13,   235,   236,    17,   331,   260,
     240,   241,    53,    13,    53,    64,    65,    17,   248,    53,
     271,   344,    56,    64,   275,    58,   277,    60,    38,    39,
     281,   282,    53,    58,    44,    53,     8,   360,    53,    64,
      65,    13,    17,    43,    53,    17,    62,    13,    12,    59,
      13,    57,    58,    17,    17,   351,    56,    67,    68,    58,
      35,    27,    15,    35,    17,    12,    13,   318,    57,    58,
      17,    24,    47,    38,    39,    47,     9,   328,   328,    44,
      43,   332,    47,    51,   328,   336,   336,    51,    12,    15,
     336,    17,   336,    17,   345,   346,   336,    58,    24,    23,
     351,    58,    67,    68,   333,    29,    63,    58,     6,     7,
      34,    40,    63,    37,    12,    13,     9,   368,    53,    17,
      13,    19,    20,    21,    22,    49,    50,    51,    52,    27,
      59,    60,    61,   384,   385,   386,   386,    13,    71,    53,
     386,    17,   386,    17,    42,    58,   386,    53,    38,    39,
      63,   381,   382,    86,    44,    17,   407,    90,    12,    92,
     411,   391,   392,    17,    17,    12,    99,   100,    15,    23,
      17,    12,    13,   424,    17,    29,    17,    67,    68,    12,
      34,    17,    15,    37,    17,   436,   436,    57,    58,    57,
      58,    51,   436,   423,   445,    49,    50,    51,    52,    12,
      13,    57,    58,   454,    17,    17,   457,   457,    59,   460,
     461,   461,   463,   457,    27,   461,    56,   461,   448,    58,
     450,   461,    12,    13,    63,   158,    58,    17,   479,   479,
      17,    63,     4,   479,     5,   479,   487,   488,   489,   479,
      57,    58,   493,   473,    59,    59,   497,    56,   499,     6,
     501,    59,   503,     6,     7,    12,    59,   190,    15,    59,
      17,    18,    19,    20,    21,    22,    19,    20,    21,    22,
      27,   204,    12,    17,    56,    15,   209,    17,   211,    12,
      12,    17,    15,    15,    17,    17,   219,    56,    45,    46,
      47,   224,    12,    59,    59,    15,    17,    17,    58,    60,
      56,    31,    59,    15,    17,    56,    17,    56,    17,    17,
      53,    20,    59,    22,    59,    17,    25,    59,    59,   252,
      15,   450,    31,    32,    33,    34,   211,    36,   460,   407,
     460,   464,   159,    18,   218,   159,    -1,    -1,    -1,   272,
      -1,   274,    -1,    -1,    -1,    -1,   279,   280,    -1,    -1,
     283,    -1,   285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   307,    -1,    -1,   310,   311,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,    -1,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   340,   341,    -1,
      -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,    -1,   138,
      -1,   364,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   172,   173,   174,   175,   176,   177,   178,
     179,    -1,   405,    -1,    -1,   408,    -1,   410,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   441,     0,
       1,    -1,    -1,   446,   447,     6,    -1,   450,    -1,    -1,
      -1,    12,   231,    14,    15,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    -1,    34,    35,    36,    37,    -1,    -1,    -1,
      41,   260,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    65,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    15,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    -1,    58,
      59,    60,    -1,    62,    -1,    -1,    -1,    66,    67,    68,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    62,    -1,
      -1,    -1,    66,    67,    68,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    -1,    -1,    -1,    66,    67,    68,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    38,    39,    -1,    -1,    42,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    62,    -1,
      -1,    -1,    66,    67,    68,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    15,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,     6,    -1,    -1,    66,    67,    68,
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
      24,    25,    26,    27,    28,    29,    -1,    31,    -1,    -1,
      34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      54,    55,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      64,    65,    12,    -1,    14,    15,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,     0,     1,     6,    12,    14,    15,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    32,    34,    35,    36,    37,    41,    45,    46,    47,
      48,    49,    50,    51,    52,    54,    55,    64,    65,    71,
      72,    77,    81,    82,    83,    87,    90,    91,    92,    93,
      98,    99,   100,   101,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   127,   129,
     130,   131,   133,   136,   137,   138,   139,   140,   141,    15,
      56,    17,    81,    38,    39,    44,    59,    67,    68,    81,
      97,    47,    97,    94,    13,    81,    82,    83,    84,    97,
      60,    81,    23,    29,    34,    37,    49,    50,    51,    52,
      84,    81,   118,    81,    84,    84,    13,    17,    43,    17,
      35,    47,    84,    53,    13,    17,    43,    56,     8,    13,
      17,    35,    47,    84,    13,    84,    13,    84,    51,    84,
      81,    23,    29,    34,    37,    49,    50,    51,    52,    84,
      13,    17,    27,    42,    81,     8,    40,    43,    59,    60,
      61,    98,     6,     7,    93,    15,    81,    92,    98,    98,
      98,    98,    58,    58,    58,    58,    58,    58,    58,    58,
      98,    98,    81,    98,    58,    98,    98,    98,    94,    98,
      97,    94,    94,   134,    94,     4,     5,     6,     7,     8,
       9,    10,    11,    15,    16,    24,    30,    35,    53,    56,
      59,    62,    66,    81,    96,    97,   120,    17,    40,    59,
      60,    61,    94,    94,    60,    84,    84,    84,    84,    84,
      84,    51,    81,    17,    53,   132,    53,    78,    17,    13,
     132,    53,   103,    17,    17,    13,    73,    74,   132,    17,
      17,    84,    59,    84,    84,    84,    84,    84,    84,    84,
      51,    17,    13,   132,    81,    81,    94,   128,    53,    81,
      94,    15,    18,    47,    59,    81,    92,    93,   117,   131,
      59,    15,    81,    65,    92,    65,    84,    84,    84,    84,
      84,    84,    84,    84,    27,    81,    94,    17,   135,     4,
       5,    94,    94,    95,    59,    95,   125,    59,   128,    94,
      59,    59,    94,    84,    59,    58,    98,    98,    56,    13,
      59,    17,    98,    98,    15,    81,   104,    75,    76,    13,
      59,    17,    56,    17,    47,    48,    86,    87,    90,    98,
      59,    59,    94,    84,    17,    43,     9,    59,    94,    56,
      94,    93,    92,    94,    94,    81,    81,    94,    65,    94,
      60,    31,   121,    57,    58,    63,    58,    60,   124,    94,
      94,    94,    15,    53,    64,    80,    81,    17,    15,    17,
      24,    15,   132,    57,    58,    56,    86,    17,    15,    17,
      24,    15,   132,    80,    17,    31,    87,    90,    94,    94,
      15,   132,    81,    81,    94,    16,   122,   102,    65,    92,
      65,    42,    85,    94,    85,   132,   125,    94,    17,    64,
      81,   126,    53,    57,    58,    59,    98,    98,   105,    15,
      81,    80,    31,    59,    98,    98,    57,    94,   125,   104,
      94,    65,    94,    81,    85,   124,    59,    59,    79,    94,
      98,    81,    15,    17,    62,    58,    85,    57,    15,    17,
      62,    86,   123,   124,    57,    85,    94,    85,   126,    94,
      94,    31,    98,    79,    15,    81,    88,    89,    17,    86,
      88,    89,    31,   125,   126,   105,    85,    58,    60,    58,
      63,    58,    63,    59,    31,    63,    63,   124,    85,    64,
     126,    64,   126,    64,    81,    15,    64,    15,    81,   126,
     126,   126,    81,    15
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    71,    73,    72,    74,
      72,    75,    72,    76,    72,    72,    72,    78,    77,    77,
      77,    79,    79,    79,    80,    80,    80,    81,    81,    81,
      82,    83,    83,    84,    84,    84,    84,    84,    85,    85,
      86,    86,    86,    86,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    88,    89,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      92,    92,    92,    92,    92,    92,    93,    93,    93,    93,
      93,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    95,    95,    96,    96,    96,
      96,    96,    96,    96,    97,    97,    97,    97,    97,    98,
      98,    98,    99,    99,    99,    99,    99,    99,    99,    99,
      99,   100,   100,   102,   101,   103,   101,   104,   104,   104,
     104,   104,   105,   105,   105,   106,   106,   106,   106,   106,
     106,   106,   106,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   109,   109,   109,   109,
     109,   110,   110,   110,   110,   111,   111,   111,   111,   112,
     112,   112,   112,   113,   113,   113,   113,   113,   114,   114,
     114,   115,   115,   116,   116,   117,   117,   117,   117,   117,
     118,   118,   120,   119,   121,   119,   122,   119,   123,   119,
     124,   124,   125,   125,   126,   126,   126,   126,   126,   127,
     127,   128,   129,   129,   129,   129,   129,   129,   130,   131,
     131,   132,   132,   132,   134,   133,   135,   135,   136,   136,
     136,   137,   137,   137,   137,   137,   137,   137,   137,   138,
     139,   140,   140,   140,   141
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     0,     8,     0,
       5,     0,     9,     0,     6,     2,     2,     0,     8,     2,
       2,     1,     2,     2,     0,     1,     3,     1,     3,     2,
       3,     1,     1,     1,     3,     4,     4,     3,     0,     2,
       1,     1,     2,     2,     4,     6,     6,     5,     5,     5,
       7,     7,     9,     9,     1,     3,     4,     1,     3,     4,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     2,     1,     8,     6,     5,     7,     5,     7,
       1,     2,     2,     3,     4,     4,     1,     1,     2,     1,
       1,     0,     2,     2,     2,     2,     2,     4,     4,     2,
       2,     3,     3,     3,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     3,     5,     5,     3,     4,     4,
       3,     3,     5,     0,     9,     0,     7,     0,     1,     3,
       1,     3,     0,     5,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     3,     2,     4,     4,
       3,     5,     2,     3,     3,     3,     2,     3,     2,     3,
       5,     2,     3,     3,     3,     2,     3,     3,     3,     2,
       3,     3,     3,     2,     3,     3,     3,     5,     2,     2,
       3,     4,     2,     1,     3,     2,     2,     2,     3,     1,
       2,     3,     0,     6,     0,     8,     0,     8,     0,    10,
       1,     2,     0,     5,     3,     5,     6,     5,     6,     2,
       3,     1,     3,     4,     3,     3,     3,     4,     2,     1,
       1,     1,     3,     4,     0,     5,     0,     3,     3,     5,
       5,     5,     5,     5,     5,     7,     7,     9,     9,     4,
       4,     4,     6,     6,     4
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
#line 163 "antimony.ypp"
                             {}
#line 2162 "antimony.tab.cpp"
    break;

  case 4: /* input: input module  */
#line 164 "antimony.ypp"
                             { /*cout << endl << $2->ToString() << endl << endl;*/ }
#line 2168 "antimony.tab.cpp"
    break;

  case 5: /* input: input modulepart  */
#line 165 "antimony.ypp"
                                 {}
#line 2174 "antimony.tab.cpp"
    break;

  case 6: /* input: input function  */
#line 166 "antimony.ypp"
                               {}
#line 2180 "antimony.tab.cpp"
    break;

  case 7: /* input: input modulename  */
#line 167 "antimony.ypp"
                                 {}
#line 2186 "antimony.tab.cpp"
    break;

  case 8: /* input: input functionname  */
#line 168 "antimony.ypp"
                                   {}
#line 2192 "antimony.tab.cpp"
    break;

  case 9: /* input: input modulecvterm  */
#line 169 "antimony.ypp"
                                   {}
#line 2198 "antimony.tab.cpp"
    break;

  case 10: /* input: input functioncvterm  */
#line 170 "antimony.ypp"
                                     {}
#line 2204 "antimony.tab.cpp"
    break;

  case 11: /* input: input toplevel_sbo  */
#line 171 "antimony.ypp"
                                   {}
#line 2210 "antimony.tab.cpp"
    break;

  case 12: /* input: input annotationBlock  */
#line 172 "antimony.ypp"
                                      {}
#line 2216 "antimony.tab.cpp"
    break;

  case 13: /* input: input moduleannotation  */
#line 173 "antimony.ypp"
                                      {}
#line 2222 "antimony.tab.cpp"
    break;

  case 14: /* input: input error  */
#line 174 "antimony.ypp"
                            {YYABORT;}
#line 2228 "antimony.tab.cpp"
    break;

  case 15: /* input: input "an error"  */
#line 175 "antimony.ypp"
                            {YYABORT;}
#line 2234 "antimony.tab.cpp"
    break;

  case 16: /* import: "'import'" "text string"  */
#line 178 "antimony.ypp"
                                  { if (g_registry.OpenFile(*((yyvsp[0].word)))==0) YYABORT;}
#line 2240 "antimony.tab.cpp"
    break;

  case 17: /* $@1: %empty  */
#line 181 "antimony.ypp"
                               {g_registry.NewCurrentModule((yyvsp[0].word), NULL, false);}
#line 2246 "antimony.tab.cpp"
    break;

  case 18: /* module: "'model' or 'module'" "element name" $@1 '(' variableexportlist ')' modulebody "'end'"  */
#line 182 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2256 "antimony.tab.cpp"
    break;

  case 19: /* $@2: %empty  */
#line 187 "antimony.ypp"
                               {g_registry.NewCurrentModule((yyvsp[0].word), NULL, false);}
#line 2262 "antimony.tab.cpp"
    break;

  case 20: /* module: "'model' or 'module'" "element name" $@2 modulebody "'end'"  */
#line 188 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2272 "antimony.tab.cpp"
    break;

  case 21: /* $@3: %empty  */
#line 193 "antimony.ypp"
                                   {g_registry.NewCurrentModule((yyvsp[0].word), NULL, true);}
#line 2278 "antimony.tab.cpp"
    break;

  case 22: /* module: "'model' or 'module'" '*' "element name" $@3 '(' variableexportlist ')' modulebody "'end'"  */
#line 194 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2288 "antimony.tab.cpp"
    break;

  case 23: /* $@4: %empty  */
#line 199 "antimony.ypp"
                                   {g_registry.NewCurrentModule((yyvsp[0].word), NULL, true);}
#line 2294 "antimony.tab.cpp"
    break;

  case 24: /* module: "'model' or 'module'" '*' "element name" $@4 modulebody "'end'"  */
#line 200 "antimony.ypp"
                {
                  (yyval.module) = g_registry.CurrentModule();
                  if ((yyval.module)->Finalize()) YYABORT;
                  g_registry.RevertToPreviousModule();
                }
#line 2304 "antimony.tab.cpp"
    break;

  case 25: /* module: "'model' or 'module'" "name of an existing module"  */
#line 204 "antimony.ypp"
                                                {g_registry.SetError("module '" + *((yyvsp[0].word)) + "' already defined."); YYABORT;}
#line 2310 "antimony.tab.cpp"
    break;

  case 26: /* module: "'model' or 'module'" "name of an existing function"  */
#line 205 "antimony.ypp"
                                {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a module because it is already a defined function."); YYABORT;}
#line 2316 "antimony.tab.cpp"
    break;

  case 27: /* $@5: %empty  */
#line 208 "antimony.ypp"
                                     {g_registry.NewUserFunction((yyvsp[0].word));}
#line 2322 "antimony.tab.cpp"
    break;

  case 28: /* function: "'function'" "element name" $@5 '(' variableexportlist ')' spacedformula "'end'"  */
#line 208 "antimony.ypp"
                                                                                                                    {if (g_registry.SetUserFunction((yyvsp[-1].formula))) YYABORT;}
#line 2328 "antimony.tab.cpp"
    break;

  case 29: /* function: "'function'" "name of an existing module"  */
#line 209 "antimony.ypp"
                                     {g_registry.SetError("Cannot use '" + *((yyvsp[0].word)) +"' as a function name because it is already the name of a module."); YYABORT;}
#line 2334 "antimony.tab.cpp"
    break;

  case 30: /* function: "'function'" "name of an existing function"  */
#line 210 "antimony.ypp"
                                      {g_registry.SetError("Cannot define '" + *((yyvsp[0].word)) + "' as a new function because it is already a defined function."); YYABORT;}
#line 2340 "antimony.tab.cpp"
    break;

  case 31: /* spacedformula: formula  */
#line 213 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2346 "antimony.tab.cpp"
    break;

  case 32: /* spacedformula: lineend spacedformula  */
#line 214 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[0].formula);}
#line 2352 "antimony.tab.cpp"
    break;

  case 33: /* spacedformula: spacedformula lineend  */
#line 215 "antimony.ypp"
                                      {(yyval.formula) = (yyvsp[-1].formula);}
#line 2358 "antimony.tab.cpp"
    break;

  case 34: /* variableexportlist: %empty  */
#line 225 "antimony.ypp"
                            {}
#line 2364 "antimony.tab.cpp"
    break;

  case 35: /* variableexportlist: variable  */
#line 226 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2370 "antimony.tab.cpp"
    break;

  case 36: /* variableexportlist: variableexportlist ',' variable  */
#line 227 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentExportList((yyvsp[0].variable))) YYABORT; }
#line 2376 "antimony.tab.cpp"
    break;

  case 37: /* variable: "element name"  */
#line 230 "antimony.ypp"
                        {(yyval.variable) = g_registry.AddVariableToCurrent((yyvsp[0].word)); }
#line 2382 "antimony.tab.cpp"
    break;

  case 38: /* variable: variable '.' "element name"  */
#line 231 "antimony.ypp"
                                     {(yyval.variable) = (yyvsp[-2].variable)->GetSubVariable((yyvsp[0].word));
                  if ((yyval.variable) == NULL) {
                    g_registry.SetError("'" + *((yyvsp[0].word)) + "' is not a subvariable of '" + (yyvsp[-2].variable)->GetNameDelimitedBy(".") + "'.");
                    YYABORT;
                  }
                }
#line 2393 "antimony.tab.cpp"
    break;

  case 39: /* variable: '$' variable  */
#line 237 "antimony.ypp"
                             {(yyval.variable) = (yyvsp[0].variable); if ((yyval.variable)->SetIsConst(true)) YYABORT;}
#line 2399 "antimony.tab.cpp"
    break;

  case 40: /* variablein: variable "'in'" variable  */
#line 240 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetCompartment((yyvsp[0].variable))) YYABORT; (yyval.variable) = (yyvsp[-2].variable);}
#line 2405 "antimony.tab.cpp"
    break;

  case 41: /* varmaybein: variable  */
#line 243 "antimony.ypp"
                         {(yyval.variable) = (yyvsp[0].variable);}
#line 2411 "antimony.tab.cpp"
    break;

  case 42: /* varmaybein: variablein  */
#line 244 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2417 "antimony.tab.cpp"
    break;

  case 43: /* varmaybeis: varmaybein  */
#line 247 "antimony.ypp"
                           {(yyval.variable) = (yyvsp[0].variable);}
#line 2423 "antimony.tab.cpp"
    break;

  case 44: /* varmaybeis: varmaybein '=' formula  */
#line 248 "antimony.ypp"
                                       {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 2429 "antimony.tab.cpp"
    break;

  case 45: /* varmaybeis: varmaybein ':' '=' formula  */
#line 249 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT; }
#line 2435 "antimony.tab.cpp"
    break;

  case 46: /* varmaybeis: varmaybein '\'' '=' formula  */
#line 250 "antimony.ypp"
                                            {(yyval.variable) = (yyvsp[-3].variable); if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT; }
#line 2441 "antimony.tab.cpp"
    break;

  case 47: /* varmaybeis: varmaybein "'has'" unitdef  */
#line 251 "antimony.ypp"
                                           {(yyval.variable) = (yyvsp[-2].variable); if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 2447 "antimony.tab.cpp"
    break;

  case 48: /* maybein: %empty  */
#line 254 "antimony.ypp"
                            {(yyval.variable) = NULL;}
#line 2453 "antimony.tab.cpp"
    break;

  case 49: /* maybein: "'in'" variable  */
#line 255 "antimony.ypp"
                                {(yyval.variable) = (yyvsp[0].variable);}
#line 2459 "antimony.tab.cpp"
    break;

  case 50: /* modulebody: modulepart  */
#line 258 "antimony.ypp"
                           {}
#line 2465 "antimony.tab.cpp"
    break;

  case 51: /* modulebody: moduleannotation  */
#line 259 "antimony.ypp"
                                 {}
#line 2471 "antimony.tab.cpp"
    break;

  case 52: /* modulebody: modulebody modulepart  */
#line 260 "antimony.ypp"
                                      {}
#line 2477 "antimony.tab.cpp"
    break;

  case 53: /* modulebody: modulebody moduleannotation  */
#line 261 "antimony.ypp"
                                           {}
#line 2483 "antimony.tab.cpp"
    break;

  case 54: /* moduleannotation: "'model' or 'module'" "element name" stringlist lineend  */
#line 265 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCVTerm(&modname,(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;
                }
#line 2492 "antimony.tab.cpp"
    break;

  case 55: /* moduleannotation: "'model' or 'module'" "element name" '.' "element name" stringlist lineend  */
#line 270 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCreatorTerm(&modname, (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].stringlist))) YYABORT;
                }
#line 2501 "antimony.tab.cpp"
    break;

  case 56: /* moduleannotation: "'model' or 'module'" "element name" '.' "element name" "number" lineend  */
#line 275 "antimony.ypp"
                {
                  string modname = g_registry.CurrentModuleName();
                  if (g_registry.ProcessGlobalCreatorTerm(&modname, (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].num))) YYABORT;
                }
#line 2510 "antimony.tab.cpp"
    break;

  case 57: /* moduleannotation: "'model' or 'module'" '.' "element name" '=' "number"  */
#line 280 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      module->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-2].word)) + "'. The only thing that can be set on the model to a number is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 2524 "antimony.tab.cpp"
    break;

  case 58: /* moduleannotation: "'model' or 'module'" '.' "element name" '=' "element name"  */
#line 290 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "autolayout")) {
                      if (module->SetAutoLayout((yyvsp[0].word))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-2].word)) + "'. The only thing that can be set on the model to a string is 'autolayout'.");
                      YYABORT;
                    }
                  }
#line 2538 "antimony.tab.cpp"
    break;

  case 59: /* moduleannotation: "'model' or 'module'" '.' "element name" '=' "name of a pre-defined constant"  */
#line 300 "antimony.ypp"
                  { Module* module = g_registry.CurrentModule();
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "autolayout")) {
                      if (module->SetAutoLayout((yyvsp[0].word))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax 'model." + *((yyvsp[-2].word)) + "'. The only thing that can be set on the model to a string is 'autolayout'.");
                      YYABORT;
                    }
                  }
#line 2552 "antimony.tab.cpp"
    break;

  case 60: /* moduleannotation: "'model' or 'module'" '.' "element name" '.' "element name" '=' "number"  */
#line 310 "antimony.ypp"
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
                    module->SetAutoLayout("on");
                  }
#line 2570 "antimony.tab.cpp"
    break;

  case 61: /* moduleannotation: "'model' or 'module'" '.' "element name" '.' "element name" '=' "element name"  */
#line 324 "antimony.ypp"
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
                    module->SetAutoLayout("on");
                  }
#line 2588 "antimony.tab.cpp"
    break;

  case 62: /* moduleannotation: "'model' or 'module'" '.' "element name" '.' "element name" '=' '{' variablelist '}'  */
#line 338 "antimony.ypp"
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
                    module->SetAutoLayout("on");
                  }
#line 2606 "antimony.tab.cpp"
    break;

  case 63: /* moduleannotation: "'model' or 'module'" '.' "element name" '.' "element name" '=' '{' numlist '}'  */
#line 352 "antimony.ypp"
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
                    module->SetAutoLayout("on");
                  }
#line 2624 "antimony.tab.cpp"
    break;

  case 64: /* variablelist: variable  */
#line 367 "antimony.ypp"
                         { (yyval.variablelist) = new std::vector<Variable*>(); (yyval.variablelist)->push_back((yyvsp[0].variable));}
#line 2630 "antimony.tab.cpp"
    break;

  case 65: /* variablelist: variablelist ',' variable  */
#line 368 "antimony.ypp"
                                          { (yyval.variablelist) = (yyvsp[-2].variablelist); (yyval.variablelist)->push_back((yyvsp[0].variable)); }
#line 2636 "antimony.tab.cpp"
    break;

  case 66: /* variablelist: variablelist ',' '\n' variable  */
#line 369 "antimony.ypp"
                                               { (yyval.variablelist) = (yyvsp[-3].variablelist); (yyval.variablelist)->push_back((yyvsp[0].variable)); }
#line 2642 "antimony.tab.cpp"
    break;

  case 67: /* numlist: "number"  */
#line 372 "antimony.ypp"
                    { (yyval.numlist) = new std::vector<double>(); (yyval.numlist)->push_back((yyvsp[0].num)); }
#line 2648 "antimony.tab.cpp"
    break;

  case 68: /* numlist: numlist ',' "number"  */
#line 373 "antimony.ypp"
                                { (yyval.numlist) = (yyvsp[-2].numlist); (yyval.numlist)->push_back((yyvsp[0].num)); }
#line 2654 "antimony.tab.cpp"
    break;

  case 69: /* numlist: numlist ',' '\n' "number"  */
#line 374 "antimony.ypp"
                                     { (yyval.numlist) = (yyvsp[-3].numlist); (yyval.numlist)->push_back((yyvsp[0].num)); }
#line 2660 "antimony.tab.cpp"
    break;

  case 70: /* modulepart: reaction lineend  */
#line 377 "antimony.ypp"
                                 {}
#line 2666 "antimony.tab.cpp"
    break;

  case 71: /* modulepart: assignment lineend  */
#line 378 "antimony.ypp"
                                   {}
#line 2672 "antimony.tab.cpp"
    break;

  case 72: /* modulepart: submodule lineend  */
#line 379 "antimony.ypp"
                                  {}
#line 2678 "antimony.tab.cpp"
    break;

  case 73: /* modulepart: varinitialize lineend  */
#line 380 "antimony.ypp"
                                      {}
#line 2684 "antimony.tab.cpp"
    break;

  case 74: /* modulepart: dnadef lineend  */
#line 381 "antimony.ypp"
                               {}
#line 2690 "antimony.tab.cpp"
    break;

  case 75: /* modulepart: event lineend  */
#line 382 "antimony.ypp"
                              {}
#line 2696 "antimony.tab.cpp"
    break;

  case 76: /* modulepart: unitinit lineend  */
#line 383 "antimony.ypp"
                                 {}
#line 2702 "antimony.tab.cpp"
    break;

  case 77: /* modulepart: deletion lineend  */
#line 384 "antimony.ypp"
                                 {}
#line 2708 "antimony.tab.cpp"
    break;

  case 78: /* modulepart: cvterm lineend  */
#line 385 "antimony.ypp"
                               {}
#line 2714 "antimony.tab.cpp"
    break;

  case 79: /* modulepart: variablein  */
#line 386 "antimony.ypp"
                           {}
#line 2720 "antimony.tab.cpp"
    break;

  case 80: /* modulepart: constraint lineend  */
#line 387 "antimony.ypp"
                                   {}
#line 2726 "antimony.tab.cpp"
    break;

  case 81: /* modulepart: objective lineend  */
#line 388 "antimony.ypp"
                                  {}
#line 2732 "antimony.tab.cpp"
    break;

  case 82: /* modulepart: algrule lineend  */
#line 389 "antimony.ypp"
                                {}
#line 2738 "antimony.tab.cpp"
    break;

  case 83: /* modulepart: lineend  */
#line 390 "antimony.ypp"
                        {}
#line 2744 "antimony.tab.cpp"
    break;

  case 84: /* reaction: varmaybein ':' reactantList reactionDivider reactantList ';' formula maybein  */
#line 394 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-7].variable), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-7].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2756 "antimony.tab.cpp"
    break;

  case 85: /* reaction: reactantList reactionDivider reactantList ';' formula maybein  */
#line 402 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 0);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2768 "antimony.tab.cpp"
    break;

  case 86: /* reaction: reactantList reactionDivider ';' formula maybein  */
#line 410 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2780 "antimony.tab.cpp"
    break;

  case 87: /* reaction: varmaybein ':' reactantList reactionDivider ';' formula maybein  */
#line 418 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-3].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 1);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2792 "antimony.tab.cpp"
    break;

  case 88: /* reaction: reactionDivider reactantList ';' formula maybein  */
#line 426 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if (var->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2804 "antimony.tab.cpp"
    break;

  case 89: /* reaction: varmaybein ':' reactionDivider reactantList ';' formula maybein  */
#line 434 "antimony.ypp"
                {
                  Variable* var = g_registry.AddNewReactionToCurrent((yyvsp[-4].reactionDivider), (yyvsp[-1].formula), (yyvsp[-6].variable), 2);
                  if (var == NULL) YYABORT;
                  if ((yyvsp[0].variable) != NULL) {
                    if ((yyvsp[-6].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;
                  }
                }
#line 2816 "antimony.tab.cpp"
    break;

  case 90: /* reactantList: variable  */
#line 443 "antimony.ypp"
                         {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2822 "antimony.tab.cpp"
    break;

  case 91: /* reactantList: "number" variable  */
#line 444 "antimony.ypp"
                             {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2828 "antimony.tab.cpp"
    break;

  case 92: /* reactantList: variable variable  */
#line 445 "antimony.ypp"
                                  {(yyval.reactantList) = g_registry.NewBlankReactantList(); if((yyval.reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2834 "antimony.tab.cpp"
    break;

  case 93: /* reactantList: reactantList '+' variable  */
#line 446 "antimony.ypp"
                                          {(yyval.reactantList) = (yyvsp[-2].reactantList); if((yyvsp[-2].reactantList)->AddReactant((yyvsp[0].variable))) YYABORT; }
#line 2840 "antimony.tab.cpp"
    break;

  case 94: /* reactantList: reactantList '+' "number" variable  */
#line 447 "antimony.ypp"
                                              {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].num))) YYABORT; }
#line 2846 "antimony.tab.cpp"
    break;

  case 95: /* reactantList: reactantList '+' variable variable  */
#line 448 "antimony.ypp"
                                                   {(yyval.reactantList) = (yyvsp[-3].reactantList); if((yyvsp[-3].reactantList)->AddReactant((yyvsp[0].variable), (yyvsp[-1].variable))) YYABORT; }
#line 2852 "antimony.tab.cpp"
    break;

  case 96: /* reactionDivider: "->"  */
#line 452 "antimony.ypp"
                           {(yyval.reactionDivider) = rdBecomes;}
#line 2858 "antimony.tab.cpp"
    break;

  case 97: /* reactionDivider: "-|"  */
#line 453 "antimony.ypp"
                           {(yyval.reactionDivider) = rdInhibits;}
#line 2864 "antimony.tab.cpp"
    break;

  case 98: /* reactionDivider: '-' '('  */
#line 454 "antimony.ypp"
                        {(yyval.reactionDivider) = rdInfluences;}
#line 2870 "antimony.tab.cpp"
    break;

  case 99: /* reactionDivider: "-o"  */
#line 455 "antimony.ypp"
                            {(yyval.reactionDivider) = rdInfluences;}
#line 2876 "antimony.tab.cpp"
    break;

  case 100: /* reactionDivider: "=>"  */
#line 456 "antimony.ypp"
                             {(yyval.reactionDivider) = rdBecomesIrreversibly;}
#line 2882 "antimony.tab.cpp"
    break;

  case 101: /* formula: %empty  */
#line 459 "antimony.ypp"
                            {(yyval.formula) = g_registry.NewBlankFormula(); }
#line 2888 "antimony.tab.cpp"
    break;

  case 102: /* formula: formula "..."  */
#line 460 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddEllipses();}
#line 2894 "antimony.tab.cpp"
    break;

  case 103: /* formula: formula variable  */
#line 461 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); if((yyvsp[-1].formula)->AddVariable((yyvsp[0].variable))) YYABORT; }
#line 2900 "antimony.tab.cpp"
    break;

  case 104: /* formula: formula "number"  */
#line 462 "antimony.ypp"
                             {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddNum((yyvsp[0].num)); }
#line 2906 "antimony.tab.cpp"
    break;

  case 105: /* formula: formula "name of a pre-defined constant"  */
#line 463 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2912 "antimony.tab.cpp"
    break;

  case 106: /* formula: formula "name of an existing function"  */
#line 464 "antimony.ypp"
                                 {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word)); }
#line 2918 "antimony.tab.cpp"
    break;

  case 107: /* formula: formula '(' commaformula ')'  */
#line 465 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddParentheses(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2924 "antimony.tab.cpp"
    break;

  case 108: /* formula: formula '{' commaformula '}'  */
#line 466 "antimony.ypp"
                                             {(yyval.formula) = (yyvsp[-3].formula); (yyvsp[-1].formula)->AddCurlyBrackets(); (yyval.formula)->AddFormula((yyvsp[-1].formula)); }
#line 2930 "antimony.tab.cpp"
    break;

  case 109: /* formula: formula mathThing  */
#line 467 "antimony.ypp"
                                  {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddMathThing((yyvsp[0].character)); }
#line 2936 "antimony.tab.cpp"
    break;

  case 110: /* formula: formula inequality  */
#line 468 "antimony.ypp"
                                   {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddInequality((yyvsp[0].inequality)); }
#line 2942 "antimony.tab.cpp"
    break;

  case 111: /* formula: formula '=' '='  */
#line 469 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('='); (yyvsp[-2].formula)->AddMathThing('='); }
#line 2948 "antimony.tab.cpp"
    break;

  case 112: /* formula: formula '&' '&'  */
#line 470 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('&'); (yyvsp[-2].formula)->AddMathThing('&'); }
#line 2954 "antimony.tab.cpp"
    break;

  case 113: /* formula: formula '|' '|'  */
#line 471 "antimony.ypp"
                                {(yyval.formula) = (yyvsp[-2].formula); (yyvsp[-2].formula)->AddMathThing('|'); (yyvsp[-2].formula)->AddMathThing('|'); }
#line 2960 "antimony.tab.cpp"
    break;

  case 114: /* formula: formula "text string"  */
#line 472 "antimony.ypp"
                                   {(yyval.formula) = (yyvsp[-1].formula); (yyvsp[-1].formula)->AddText((yyvsp[0].word), true); }
#line 2966 "antimony.tab.cpp"
    break;

  case 115: /* commaformula: formula  */
#line 475 "antimony.ypp"
                        {(yyval.formula) = (yyvsp[0].formula);}
#line 2972 "antimony.tab.cpp"
    break;

  case 116: /* commaformula: commaformula ',' formula  */
#line 476 "antimony.ypp"
                                         {(yyval.formula) = (yyvsp[-2].formula); (yyval.formula)->AddMathThing(','); (yyval.formula)->AddFormula((yyvsp[0].formula)); }
#line 2978 "antimony.tab.cpp"
    break;

  case 117: /* mathThing: '+'  */
#line 479 "antimony.ypp"
                    {(yyval.character) = '+';}
#line 2984 "antimony.tab.cpp"
    break;

  case 118: /* mathThing: '-'  */
#line 480 "antimony.ypp"
                    {(yyval.character) = '-';}
#line 2990 "antimony.tab.cpp"
    break;

  case 119: /* mathThing: '*'  */
#line 481 "antimony.ypp"
                    {(yyval.character) = '*';}
#line 2996 "antimony.tab.cpp"
    break;

  case 120: /* mathThing: '/'  */
#line 482 "antimony.ypp"
                    {(yyval.character) = '/';}
#line 3002 "antimony.tab.cpp"
    break;

  case 121: /* mathThing: '^'  */
#line 483 "antimony.ypp"
                    {(yyval.character) = '^';}
#line 3008 "antimony.tab.cpp"
    break;

  case 122: /* mathThing: '!'  */
#line 484 "antimony.ypp"
                    {(yyval.character) = '!';}
#line 3014 "antimony.tab.cpp"
    break;

  case 123: /* mathThing: '%'  */
#line 485 "antimony.ypp"
                    {(yyval.character) = '%';}
#line 3020 "antimony.tab.cpp"
    break;

  case 124: /* inequality: '<'  */
#line 488 "antimony.ypp"
                    {(yyval.inequality) = constLT;}
#line 3026 "antimony.tab.cpp"
    break;

  case 125: /* inequality: "<="  */
#line 489 "antimony.ypp"
                    {(yyval.inequality) = constLEQ;}
#line 3032 "antimony.tab.cpp"
    break;

  case 126: /* inequality: '>'  */
#line 490 "antimony.ypp"
                    {(yyval.inequality) = constGT;}
#line 3038 "antimony.tab.cpp"
    break;

  case 127: /* inequality: ">="  */
#line 491 "antimony.ypp"
                    {(yyval.inequality) = constGEQ;}
#line 3044 "antimony.tab.cpp"
    break;

  case 128: /* inequality: "!="  */
#line 492 "antimony.ypp"
                    {(yyval.inequality) = constNEQ;}
#line 3050 "antimony.tab.cpp"
    break;

  case 129: /* lineend: ';'  */
#line 495 "antimony.ypp"
                    {}
#line 3056 "antimony.tab.cpp"
    break;

  case 130: /* lineend: '\n'  */
#line 496 "antimony.ypp"
                     {}
#line 3062 "antimony.tab.cpp"
    break;

  case 131: /* lineend: "end of line"  */
#line 497 "antimony.ypp"
                    {}
#line 3068 "antimony.tab.cpp"
    break;

  case 132: /* assignment: varmaybein ':' maxormin formula  */
#line 500 "antimony.ypp"
                                                {if (g_registry.CurrentModule()->AddObjective((yyvsp[-3].variable), (yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 3074 "antimony.tab.cpp"
    break;

  case 133: /* assignment: varmaybein '=' formula  */
#line 501 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->SetFormula((yyvsp[0].formula))) YYABORT; }
#line 3080 "antimony.tab.cpp"
    break;

  case 134: /* assignment: varmaybein "'is'" variable  */
#line 502 "antimony.ypp"
                                       {if ((yyvsp[-2].variable)->Synchronize((yyvsp[0].variable), NULL)) YYABORT;}
#line 3086 "antimony.tab.cpp"
    break;

  case 135: /* assignment: varmaybein "'is'" variable '/' variable  */
#line 503 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[-2].variable), (yyvsp[0].variable))) YYABORT;}
#line 3092 "antimony.tab.cpp"
    break;

  case 136: /* assignment: varmaybein '*' variable "'is'" variable  */
#line 504 "antimony.ypp"
                                                    {if ((yyvsp[-4].variable)->Synchronize((yyvsp[0].variable), (yyvsp[-2].variable))) YYABORT;}
#line 3098 "antimony.tab.cpp"
    break;

  case 137: /* assignment: varmaybein "'is'" "text string"  */
#line 505 "antimony.ypp"
                                         {if ((yyvsp[-2].variable)->SetDisplayName(*((yyvsp[0].word)))) YYABORT;}
#line 3104 "antimony.tab.cpp"
    break;

  case 138: /* assignment: varmaybein ':' '=' formula  */
#line 506 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetAssignmentRule((yyvsp[0].formula))) YYABORT;}
#line 3110 "antimony.tab.cpp"
    break;

  case 139: /* assignment: varmaybein '\'' '=' formula  */
#line 507 "antimony.ypp"
                                            {if ((yyvsp[-3].variable)->SetRateRule((yyvsp[0].formula))) YYABORT;}
#line 3116 "antimony.tab.cpp"
    break;

  case 140: /* assignment: varmaybein "'has'" unitdef  */
#line 508 "antimony.ypp"
                                           {if ((yyvsp[-2].variable)->SetUnit((yyvsp[0].variable))) YYABORT; }
#line 3122 "antimony.tab.cpp"
    break;

  case 141: /* algrule: "number" '=' formula  */
#line 511 "antimony.ypp"
                                {if (g_registry.AddNewAlgebraicRuleToCurrent((yyvsp[-2].num), (yyvsp[0].formula))) YYABORT; }
#line 3128 "antimony.tab.cpp"
    break;

  case 142: /* algrule: varmaybein ':' "number" '=' formula  */
#line 512 "antimony.ypp"
                                               {if ((yyvsp[-4].variable)->SetAlgebraicRule((yyvsp[-2].num), (yyvsp[0].formula)) ) YYABORT;}
#line 3134 "antimony.tab.cpp"
    break;

  case 143: /* $@6: %empty  */
#line 515 "antimony.ypp"
                                           {if ((yyvsp[-3].variable)->SetModule((yyvsp[-1].word))) YYABORT;}
#line 3140 "antimony.tab.cpp"
    break;

  case 144: /* submodule: varmaybein ':' "name of an existing module" '(' $@6 variableimportlist ')' submodifications maybein  */
#line 515 "antimony.ypp"
                                                                                                                             {if ((yyvsp[0].variable) != NULL) {if ((yyvsp[-8].variable)->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 3146 "antimony.tab.cpp"
    break;

  case 145: /* $@7: %empty  */
#line 516 "antimony.ypp"
                            {if(g_registry.CurrentModule()->SetModule((yyvsp[-1].word))) YYABORT;}
#line 3152 "antimony.tab.cpp"
    break;

  case 146: /* submodule: "name of an existing module" '(' $@7 variableimportlist ')' submodifications maybein  */
#line 516 "antimony.ypp"
                                                                                                                                     {if ((yyvsp[0].variable) != NULL) {if (g_registry.GetCurrentSubmodel()->SetCompartment((yyvsp[0].variable))) YYABORT;}}
#line 3158 "antimony.tab.cpp"
    break;

  case 147: /* variableimportlist: %empty  */
#line 520 "antimony.ypp"
                            {}
#line 3164 "antimony.tab.cpp"
    break;

  case 148: /* variableimportlist: variable  */
#line 521 "antimony.ypp"
                         {if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 3170 "antimony.tab.cpp"
    break;

  case 149: /* variableimportlist: variableimportlist ',' variable  */
#line 522 "antimony.ypp"
                                                { if (g_registry.AddVariableToCurrentImportList((yyvsp[0].variable))) YYABORT; }
#line 3176 "antimony.tab.cpp"
    break;

  case 150: /* variableimportlist: "number"  */
#line 523 "antimony.ypp"
                    {if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 3182 "antimony.tab.cpp"
    break;

  case 151: /* variableimportlist: variableimportlist ',' "number"  */
#line 524 "antimony.ypp"
                                           { if (g_registry.AddNumberToCurrentImportList((yyvsp[0].num))) YYABORT; }
#line 3188 "antimony.tab.cpp"
    break;

  case 152: /* submodifications: %empty  */
#line 528 "antimony.ypp"
                            {}
#line 3194 "antimony.tab.cpp"
    break;

  case 153: /* submodifications: submodifications ',' "element name" '=' variable  */
#line 529 "antimony.ypp"
                                                          {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].variable));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].variable))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 3202 "antimony.tab.cpp"
    break;

  case 154: /* submodifications: submodifications ',' "element name" '=' "number"  */
#line 533 "antimony.ypp"
                                                     {if (CaselessStrCmp(false, *(yyvsp[-2].word), "extentconv")) {g_registry.GetCurrentSubmodel()->SetExtentConversionFactor((yyvsp[0].num));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "timeconv")) {if (g_registry.GetCurrentSubmodel()->SetTimeConversionFactor((yyvsp[0].num))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in submodel declaration.  You may use the terms 'extentconv' and 'timeconv' to set the extent and time conversion factors for this submodel, respectively."); YYABORT;}}
#line 3210 "antimony.tab.cpp"
    break;

  case 155: /* varinitialize: specinit  */
#line 537 "antimony.ypp"
                         { }
#line 3216 "antimony.tab.cpp"
    break;

  case 156: /* varinitialize: formulainit  */
#line 538 "antimony.ypp"
                            { }
#line 3222 "antimony.tab.cpp"
    break;

  case 157: /* varinitialize: reactioninit  */
#line 539 "antimony.ypp"
                             { }
#line 3228 "antimony.tab.cpp"
    break;

  case 158: /* varinitialize: dnainit  */
#line 540 "antimony.ypp"
                        { }
#line 3234 "antimony.tab.cpp"
    break;

  case 159: /* varinitialize: geneinit  */
#line 541 "antimony.ypp"
                         { }
#line 3240 "antimony.tab.cpp"
    break;

  case 160: /* varinitialize: operatorinit  */
#line 542 "antimony.ypp"
                             { }
#line 3246 "antimony.tab.cpp"
    break;

  case 161: /* varinitialize: compartmentinit  */
#line 543 "antimony.ypp"
                                { }
#line 3252 "antimony.tab.cpp"
    break;

  case 162: /* varinitialize: varconstinit  */
#line 544 "antimony.ypp"
                             { }
#line 3258 "antimony.tab.cpp"
    break;

  case 163: /* specinit: "'species'" varmaybeis  */
#line 547 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3264 "antimony.tab.cpp"
    break;

  case 164: /* specinit: "'var'" "'species'" varmaybeis  */
#line 548 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3270 "antimony.tab.cpp"
    break;

  case 165: /* specinit: "'const'" "'species'" varmaybeis  */
#line 549 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(false); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3276 "antimony.tab.cpp"
    break;

  case 166: /* specinit: "'substanceOnly'" "'species'" varmaybeis  */
#line 550 "antimony.ypp"
                                             {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3282 "antimony.tab.cpp"
    break;

  case 167: /* specinit: "'substanceOnly'" varmaybeis  */
#line 551 "antimony.ypp"
                                     {g_registry.SetConstness(constDEFAULT); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3288 "antimony.tab.cpp"
    break;

  case 168: /* specinit: "'var'" "'substanceOnly'" "'species'" varmaybeis  */
#line 552 "antimony.ypp"
                                                     {g_registry.SetConstness(constVAR); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3294 "antimony.tab.cpp"
    break;

  case 169: /* specinit: "'const'" "'substanceOnly'" "'species'" varmaybeis  */
#line 553 "antimony.ypp"
                                                       {g_registry.SetConstness(constCONST); g_registry.SetSubstOnly(true); (yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3300 "antimony.tab.cpp"
    break;

  case 170: /* specinit: specinit ',' varmaybeis  */
#line 554 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegSpecVals(); if ((yyvsp[0].variable)->SetType(varSpeciesUndef)) YYABORT; }
#line 3306 "antimony.tab.cpp"
    break;

  case 171: /* specinit: "'species'" '.' "element name" '=' formula  */
#line 555 "antimony.ypp"
                                                {if (g_registry.CurrentModule()->AddSpeciesLayoutInfo((yyvsp[-2].word), (yyvsp[0].formula))) YYABORT;}
#line 3312 "antimony.tab.cpp"
    break;

  case 172: /* formulainit: "'formula'" varmaybeis  */
#line 558 "antimony.ypp"
                                   {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3318 "antimony.tab.cpp"
    break;

  case 173: /* formulainit: "'var'" "'formula'" varmaybeis  */
#line 559 "antimony.ypp"
                                           {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3324 "antimony.tab.cpp"
    break;

  case 174: /* formulainit: "'const'" "'formula'" varmaybeis  */
#line 560 "antimony.ypp"
                                             {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3330 "antimony.tab.cpp"
    break;

  case 175: /* formulainit: formulainit ',' varmaybeis  */
#line 561 "antimony.ypp"
                                           {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaUndef)) YYABORT; }
#line 3336 "antimony.tab.cpp"
    break;

  case 176: /* reactioninit: "'reaction'" varmaybeis  */
#line 564 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3342 "antimony.tab.cpp"
    break;

  case 177: /* reactioninit: "'var'" "'reaction'" varmaybeis  */
#line 565 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3348 "antimony.tab.cpp"
    break;

  case 178: /* reactioninit: "'const'" "'reaction'"  */
#line 566 "antimony.ypp"
                                   {g_registry.SetError("Reactions may not be set 'const'."); YYABORT; }
#line 3354 "antimony.tab.cpp"
    break;

  case 179: /* reactioninit: reactioninit ',' varmaybeis  */
#line 567 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionUndef)) YYABORT; }
#line 3360 "antimony.tab.cpp"
    break;

  case 180: /* reactioninit: "'reaction'" '.' "element name" '=' formula  */
#line 568 "antimony.ypp"
                                                 {if (g_registry.CurrentModule()->AddReactionLayoutInfo((yyvsp[-2].word), (yyvsp[0].formula))) YYABORT;}
#line 3366 "antimony.tab.cpp"
    break;

  case 181: /* dnainit: "'DNA'" varmaybeis  */
#line 571 "antimony.ypp"
                               {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3372 "antimony.tab.cpp"
    break;

  case 182: /* dnainit: "'var'" "'DNA'" varmaybeis  */
#line 572 "antimony.ypp"
                                       {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3378 "antimony.tab.cpp"
    break;

  case 183: /* dnainit: "'const'" "'DNA'" varmaybeis  */
#line 573 "antimony.ypp"
                                         {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3384 "antimony.tab.cpp"
    break;

  case 184: /* dnainit: dnainit ',' varmaybeis  */
#line 574 "antimony.ypp"
                                       {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varDNA)) YYABORT; }
#line 3390 "antimony.tab.cpp"
    break;

  case 185: /* geneinit: "'gene'" varmaybeis  */
#line 577 "antimony.ypp"
                                {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3396 "antimony.tab.cpp"
    break;

  case 186: /* geneinit: "'var'" "'gene'" varmaybeis  */
#line 578 "antimony.ypp"
                                        {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3402 "antimony.tab.cpp"
    break;

  case 187: /* geneinit: "'const'" "'gene'" varmaybeis  */
#line 579 "antimony.ypp"
                                          {g_registry.SetError("Genes may not be set 'const'."); YYABORT; }
#line 3408 "antimony.tab.cpp"
    break;

  case 188: /* geneinit: geneinit ',' varmaybeis  */
#line 580 "antimony.ypp"
                                        {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varReactionGene)) YYABORT; }
#line 3414 "antimony.tab.cpp"
    break;

  case 189: /* operatorinit: "'operator'" varmaybeis  */
#line 583 "antimony.ypp"
                                    {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3420 "antimony.tab.cpp"
    break;

  case 190: /* operatorinit: "'var'" "'operator'" varmaybeis  */
#line 584 "antimony.ypp"
                                            {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3426 "antimony.tab.cpp"
    break;

  case 191: /* operatorinit: "'const'" "'operator'" varmaybeis  */
#line 585 "antimony.ypp"
                                              {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3432 "antimony.tab.cpp"
    break;

  case 192: /* operatorinit: operatorinit ',' varmaybeis  */
#line 586 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varFormulaOperator)) YYABORT; }
#line 3438 "antimony.tab.cpp"
    break;

  case 193: /* compartmentinit: "'compartment'" varmaybeis  */
#line 590 "antimony.ypp"
                                       {g_registry.SetConstness(constDEFAULT); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3444 "antimony.tab.cpp"
    break;

  case 194: /* compartmentinit: "'var'" "'compartment'" varmaybeis  */
#line 591 "antimony.ypp"
                                               {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3450 "antimony.tab.cpp"
    break;

  case 195: /* compartmentinit: "'const'" "'compartment'" varmaybeis  */
#line 592 "antimony.ypp"
                                                 {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3456 "antimony.tab.cpp"
    break;

  case 196: /* compartmentinit: compartmentinit ',' varmaybeis  */
#line 593 "antimony.ypp"
                                               {(yyvsp[0].variable)->SetRegConst(); if ((yyvsp[0].variable)->SetType(varCompartment)) YYABORT; }
#line 3462 "antimony.tab.cpp"
    break;

  case 197: /* compartmentinit: "'compartment'" '.' "element name" '=' formula  */
#line 594 "antimony.ypp"
                                                    {if (g_registry.CurrentModule()->AddCompartmentLayoutInfo((yyvsp[-2].word), (yyvsp[0].formula))) YYABORT;}
#line 3468 "antimony.tab.cpp"
    break;

  case 198: /* varconstinit: "'var'" varmaybeis  */
#line 597 "antimony.ypp"
                                   {g_registry.SetConstness(constVAR); (yyvsp[0].variable)->SetRegConst();}
#line 3474 "antimony.tab.cpp"
    break;

  case 199: /* varconstinit: "'const'" varmaybeis  */
#line 598 "antimony.ypp"
                                     {g_registry.SetConstness(constCONST); (yyvsp[0].variable)->SetRegConst();}
#line 3480 "antimony.tab.cpp"
    break;

  case 200: /* varconstinit: varconstinit ',' varmaybeis  */
#line 599 "antimony.ypp"
                                            {(yyvsp[0].variable)->SetRegConst();}
#line 3486 "antimony.tab.cpp"
    break;

  case 201: /* unitinit: "'unit'" variable '=' formula  */
#line 602 "antimony.ypp"
                                              {if ((yyvsp[-2].variable)->SetType(varUnitDefinition)) YYABORT;
                                               if ((yyvsp[0].formula)->MakeAllVariablesUnits()) YYABORT;
                                               if ((yyvsp[-2].variable)->GetUnitDef()->SetFromFormula((yyvsp[0].formula))) YYABORT;}
#line 3494 "antimony.tab.cpp"
    break;

  case 202: /* unitinit: "'unit'" variable  */
#line 605 "antimony.ypp"
                                  {if ((yyvsp[0].variable)->SetType(varUnitDefinition)) YYABORT;}
#line 3500 "antimony.tab.cpp"
    break;

  case 203: /* dnadef: dnastrand  */
#line 608 "antimony.ypp"
                          {if (g_registry.SaveWorkingStrand()) YYABORT;}
#line 3506 "antimony.tab.cpp"
    break;

  case 204: /* dnadef: varmaybein ':' dnastrand  */
#line 609 "antimony.ypp"
                                         {if (g_registry.SetStrandAs((yyvsp[-2].variable))) YYABORT;}
#line 3512 "antimony.tab.cpp"
    break;

  case 205: /* dnastrand: "--" variable  */
#line 612 "antimony.ypp"
                                {if (g_registry.SetNewUpstreamOpen((yyvsp[0].variable))) YYABORT;}
#line 3518 "antimony.tab.cpp"
    break;

  case 206: /* dnastrand: "--" dnamiddle  */
#line 613 "antimony.ypp"
                                 {g_registry.SetOpenUpstream(); }
#line 3524 "antimony.tab.cpp"
    break;

  case 207: /* dnastrand: dnamiddle variable  */
#line 614 "antimony.ypp"
                                   {if (g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3530 "antimony.tab.cpp"
    break;

  case 208: /* dnastrand: "--" dnamiddle variable  */
#line 615 "antimony.ypp"
                                          {g_registry.SetOpenUpstream(); if(g_registry.SetDownstreamEnd((yyvsp[0].variable))) YYABORT;}
#line 3536 "antimony.tab.cpp"
    break;

  case 209: /* dnastrand: dnamiddle  */
#line 616 "antimony.ypp"
                          { }
#line 3542 "antimony.tab.cpp"
    break;

  case 210: /* dnamiddle: variable "--"  */
#line 619 "antimony.ypp"
                                {if (g_registry.SetNewDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3548 "antimony.tab.cpp"
    break;

  case 211: /* dnamiddle: dnamiddle variable "--"  */
#line 620 "antimony.ypp"
                                          {if (g_registry.SetDownstreamOpen((yyvsp[-1].variable))) YYABORT;}
#line 3554 "antimony.tab.cpp"
    break;

  case 212: /* $@8: %empty  */
#line 623 "antimony.ypp"
                           {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula))) YYABORT;}
#line 3560 "antimony.tab.cpp"
    break;

  case 213: /* event: "'at'" formula $@8 eventmodifications colonret assignmentlist  */
#line 623 "antimony.ypp"
                                                                                                                        {}
#line 3566 "antimony.tab.cpp"
    break;

  case 214: /* $@9: %empty  */
#line 624 "antimony.ypp"
                                         {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula))) YYABORT;}
#line 3572 "antimony.tab.cpp"
    break;

  case 215: /* event: "'at'" formula "'after'" formula $@9 eventmodifications colonret assignmentlist  */
#line 624 "antimony.ypp"
                                                                                                                                          {}
#line 3578 "antimony.tab.cpp"
    break;

  case 216: /* $@10: %empty  */
#line 625 "antimony.ypp"
                                          {if (g_registry.SetNewCurrentEvent((yyvsp[0].formula), (yyvsp[-3].variable))) YYABORT;}
#line 3584 "antimony.tab.cpp"
    break;

  case 217: /* event: varmaybein ':' "'at'" formula $@10 eventmodifications colonret assignmentlist  */
#line 625 "antimony.ypp"
                                                                                                                                            {}
#line 3590 "antimony.tab.cpp"
    break;

  case 218: /* $@11: %empty  */
#line 626 "antimony.ypp"
                                                        {if (g_registry.SetNewCurrentEvent((yyvsp[-2].formula), (yyvsp[0].formula), (yyvsp[-5].variable))) YYABORT;}
#line 3596 "antimony.tab.cpp"
    break;

  case 219: /* event: varmaybein ':' "'at'" formula "'after'" formula $@11 eventmodifications colonret assignmentlist  */
#line 626 "antimony.ypp"
                                                                                                                                                             {}
#line 3602 "antimony.tab.cpp"
    break;

  case 220: /* colonret: ':'  */
#line 629 "antimony.ypp"
                    {}
#line 3608 "antimony.tab.cpp"
    break;

  case 221: /* colonret: colonret '\n'  */
#line 630 "antimony.ypp"
                              {}
#line 3614 "antimony.tab.cpp"
    break;

  case 222: /* eventmodifications: %empty  */
#line 633 "antimony.ypp"
                                 {}
#line 3620 "antimony.tab.cpp"
    break;

  case 223: /* eventmodifications: eventmodifications ',' "element name" '=' formula  */
#line 634 "antimony.ypp"
                                                           {if (CaselessStrCmp(false, *(yyvsp[-2].word), "priority")) {g_registry.GetCurrentEvent()->SetPriority(*(yyvsp[0].formula));}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "t0")) {if (g_registry.GetCurrentEvent()->SetInitialValue(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "fromTrigger")) {if (g_registry.GetCurrentEvent()->SetUseValuesFromTriggerTime(*(yyvsp[0].formula))) YYABORT;}
                else if (CaselessStrCmp(false, *(yyvsp[-2].word), "persistent")) {if (g_registry.GetCurrentEvent()->SetPersistent(*(yyvsp[0].formula))) YYABORT;}
                else { g_registry.SetError("Illegal term '" + *(yyvsp[-2].word) + "' in event defintion.  You may use the terms 'priority', 't0', 'fromTrigger', and 'persistent' here to set those properties of an event."); YYABORT;}}
#line 3630 "antimony.tab.cpp"
    break;

  case 224: /* assignmentlist: variable '=' formula  */
#line 641 "antimony.ypp"
                                     {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3636 "antimony.tab.cpp"
    break;

  case 225: /* assignmentlist: variable '=' formula ':' assignmentlist  */
#line 642 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3642 "antimony.tab.cpp"
    break;

  case 226: /* assignmentlist: variable '=' formula ':' '\n' assignmentlist  */
#line 643 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3648 "antimony.tab.cpp"
    break;

  case 227: /* assignmentlist: variable '=' formula ',' assignmentlist  */
#line 644 "antimony.ypp"
                                                        {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-4].variable), (yyvsp[-2].formula))) YYABORT;}
#line 3654 "antimony.tab.cpp"
    break;

  case 228: /* assignmentlist: variable '=' formula ',' '\n' assignmentlist  */
#line 645 "antimony.ypp"
                                                             {if (g_registry.GetCurrentEvent()->AddResult((yyvsp[-5].variable), (yyvsp[-3].formula))) YYABORT;}
#line 3660 "antimony.tab.cpp"
    break;

  case 229: /* deletion: "'delete'" variable  */
#line 648 "antimony.ypp"
                                    {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3666 "antimony.tab.cpp"
    break;

  case 230: /* deletion: deletion ',' variable  */
#line 649 "antimony.ypp"
                                      {if (g_registry.CurrentModule()->AddDeletion((yyvsp[0].variable))) YYABORT;}
#line 3672 "antimony.tab.cpp"
    break;

  case 231: /* unitdef: formula  */
#line 652 "antimony.ypp"
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
#line 3690 "antimony.tab.cpp"
    break;

  case 232: /* constraint: "number" inequality formula  */
#line 667 "antimony.ypp"
                                       {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3696 "antimony.tab.cpp"
    break;

  case 233: /* constraint: '-' "number" inequality formula  */
#line 668 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint(-(yyvsp[-2].num), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3702 "antimony.tab.cpp"
    break;

  case 234: /* constraint: "name of a pre-defined constant" inequality formula  */
#line 669 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3708 "antimony.tab.cpp"
    break;

  case 235: /* constraint: "element name" inequality formula  */
#line 670 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].word), (yyvsp[0].formula), (yyvsp[-1].inequality))) YYABORT;}
#line 3714 "antimony.tab.cpp"
    break;

  case 236: /* constraint: "'constraint'" ':' formula  */
#line 671 "antimony.ypp"
                                           {if (g_registry.CurrentModule()->AddConstraint((yyvsp[0].formula))) YYABORT;}
#line 3720 "antimony.tab.cpp"
    break;

  case 237: /* constraint: "'constraint'" variable ':' formula  */
#line 672 "antimony.ypp"
                                                    {if (g_registry.CurrentModule()->AddConstraint((yyvsp[-2].variable), (yyvsp[0].formula))) YYABORT;}
#line 3726 "antimony.tab.cpp"
    break;

  case 238: /* objective: maxormin formula  */
#line 675 "antimony.ypp"
                                              {if (g_registry.CurrentModule()->AddObjective((yyvsp[0].formula), (yyvsp[-1].maxormin))) YYABORT;}
#line 3732 "antimony.tab.cpp"
    break;

  case 239: /* maxormin: "'maximize'"  */
#line 678 "antimony.ypp"
                             {(yyval.maxormin) = true;}
#line 3738 "antimony.tab.cpp"
    break;

  case 240: /* maxormin: "'minimize'"  */
#line 679 "antimony.ypp"
                             {(yyval.maxormin) = false;}
#line 3744 "antimony.tab.cpp"
    break;

  case 241: /* stringlist: "text string"  */
#line 682 "antimony.ypp"
                           { (yyval.stringlist) = new std::vector<std::string>(); (yyval.stringlist)->push_back(*((yyvsp[0].word))); }
#line 3750 "antimony.tab.cpp"
    break;

  case 242: /* stringlist: stringlist ',' "text string"  */
#line 683 "antimony.ypp"
                                          { (yyval.stringlist) = (yyvsp[-2].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3756 "antimony.tab.cpp"
    break;

  case 243: /* stringlist: stringlist ',' '\n' "text string"  */
#line 684 "antimony.ypp"
                                               { (yyval.stringlist) = (yyvsp[-3].stringlist); (yyval.stringlist)->push_back(*(yyvsp[0].word)); }
#line 3762 "antimony.tab.cpp"
    break;

  case 244: /* $@12: %empty  */
#line 686 "antimony.ypp"
                                    {if (g_registry.SetCurrentModuleIf((yyvsp[0].word), (yyvsp[-1].word))) YYABORT;}
#line 3768 "antimony.tab.cpp"
    break;

  case 245: /* annotationBlock: "element name" "name of an existing module" $@12 annotations "'end'"  */
#line 686 "antimony.ypp"
                                                                                                          {g_registry.RevertToPreviousModule();}
#line 3774 "antimony.tab.cpp"
    break;

  case 246: /* annotations: %empty  */
#line 689 "antimony.ypp"
                            {}
#line 3780 "antimony.tab.cpp"
    break;

  case 247: /* annotations: "element name" ':' stringlist  */
#line 690 "antimony.ypp"
                                       {string modname = g_registry.CurrentModuleName(); g_registry.ProcessGlobalCVTerm(&modname, (yyvsp[-2].word), (yyvsp[0].stringlist));}
#line 3786 "antimony.tab.cpp"
    break;

  case 248: /* cvterm: variable "element name" stringlist  */
#line 695 "antimony.ypp"
                                            {if (g_registry.CurrentModule()->ProcessCVTerm((yyvsp[-2].variable),(yyvsp[-1].word),(yyvsp[0].stringlist))) YYABORT;}
#line 3792 "antimony.tab.cpp"
    break;

  case 249: /* cvterm: variable "element name" '.' "element name" stringlist  */
#line 696 "antimony.ypp"
                                                        {if (g_registry.ProcessCreatorTerm((yyvsp[-4].variable), (yyvsp[-3].word), (yyvsp[-1].word), (yyvsp[0].stringlist))) YYABORT;}
#line 3798 "antimony.tab.cpp"
    break;

  case 250: /* cvterm: variable "element name" '.' "element name" "number"  */
#line 697 "antimony.ypp"
                                                 {if (g_registry.ProcessCreatorTerm((yyvsp[-4].variable), (yyvsp[-3].word), (yyvsp[-1].word), (yyvsp[0].num))) YYABORT;}
#line 3804 "antimony.tab.cpp"
    break;

  case 251: /* toplevel_sbo: "name of an existing module" '.' "element name" '=' "number"  */
#line 701 "antimony.ypp"
                  { Module* module = g_registry.GetModule(*(yyvsp[-4].word));
                    if (module && (yyvsp[-2].word) && CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      module->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can be set on '" + *((yyvsp[-4].word)) + "' this way is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3818 "antimony.tab.cpp"
    break;

  case 252: /* toplevel_sbo: "name of an existing function" '.' "element name" '=' "number"  */
#line 712 "antimony.ypp"
                  { Module* function = g_registry.GetModule(*(yyvsp[-4].word));
                    if (function && (yyvsp[-2].word) &&  CaselessStrCmp(true, *((yyvsp[-2].word)), "sboTerm")) {
                      function->SetSBOTerm(lround((yyvsp[0].num)));
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can set '" + *((yyvsp[-4].word)) + "' to a number is 'sboTerm'.");
                      YYABORT;
                    }
                  }
#line 3832 "antimony.tab.cpp"
    break;

  case 253: /* toplevel_sbo: "name of an existing module" '.' "element name" '=' "element name"  */
#line 722 "antimony.ypp"
                  { Module* function = g_registry.GetModule(*(yyvsp[-4].word));
                    if (function && (yyvsp[-2].word) &&  CaselessStrCmp(true, *((yyvsp[-2].word)), "autolayout")) {
                      if (function->SetAutoLayout((yyvsp[0].word))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can set on '" + *((yyvsp[-4].word)) + "' to a string is 'autolayout'.");
                      YYABORT;
                    }
                  }
#line 3846 "antimony.tab.cpp"
    break;

  case 254: /* toplevel_sbo: "name of an existing module" '.' "element name" '=' "name of a pre-defined constant"  */
#line 732 "antimony.ypp"
                  { Module* function = g_registry.GetModule(*(yyvsp[-4].word));
                    if (function && (yyvsp[-2].word) &&  CaselessStrCmp(true, *((yyvsp[-2].word)), "autolayout")) {
                      if (function->SetAutoLayout((yyvsp[0].word))) YYABORT;
                    }
                    else {
                      g_registry.SetError("Invalid syntax '" + *((yyvsp[-4].word)) + "." + *((yyvsp[-2].word)) + "'. The only thing that can set on '" + *((yyvsp[-4].word)) + "' to a string is 'autolayout'.");
                      YYABORT;
                    }
                  }
#line 3860 "antimony.tab.cpp"
    break;

  case 255: /* toplevel_sbo: "name of an existing module" '.' "element name" '.' "element name" '=' "number"  */
#line 742 "antimony.ypp"
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
                    module->SetAutoLayout("on");
                  }
#line 3878 "antimony.tab.cpp"
    break;

  case 256: /* toplevel_sbo: "name of an existing module" '.' "element name" '.' "element name" '=' "element name"  */
#line 756 "antimony.ypp"
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
                    module->SetAutoLayout("on");
                  }
#line 3896 "antimony.tab.cpp"
    break;

  case 257: /* toplevel_sbo: "name of an existing module" '.' "element name" '.' "element name" '=' '{' variablelist '}'  */
#line 770 "antimony.ypp"
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
                    module->SetAutoLayout("on");
                  }
#line 3914 "antimony.tab.cpp"
    break;

  case 258: /* toplevel_sbo: "name of an existing module" '.' "element name" '.' "element name" '=' '{' numlist '}'  */
#line 784 "antimony.ypp"
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
                    module->SetAutoLayout("on");
                  }
#line 3932 "antimony.tab.cpp"
    break;

  case 259: /* modulename: "name of an existing module" "'is'" "text string" lineend  */
#line 800 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3938 "antimony.tab.cpp"
    break;

  case 260: /* functionname: "name of an existing function" "'is'" "text string" lineend  */
#line 802 "antimony.ypp"
                { g_registry.GetModule(*(yyvsp[-3].word))->SetDisplayName(*(yyvsp[-1].word)); }
#line 3944 "antimony.tab.cpp"
    break;

  case 261: /* modulecvterm: "name of an existing module" "element name" stringlist lineend  */
#line 805 "antimony.ypp"
                                                   {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3950 "antimony.tab.cpp"
    break;

  case 262: /* modulecvterm: "name of an existing module" "element name" '.' "element name" stringlist lineend  */
#line 806 "antimony.ypp"
                                                               {if (g_registry.ProcessGlobalCreatorTerm((yyvsp[-5].word), (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].stringlist))) YYABORT;}
#line 3956 "antimony.tab.cpp"
    break;

  case 263: /* modulecvterm: "name of an existing module" "element name" '.' "element name" "number" lineend  */
#line 807 "antimony.ypp"
                                                        {if (g_registry.ProcessGlobalCreatorTerm((yyvsp[-5].word), (yyvsp[-4].word), (yyvsp[-2].word), (yyvsp[-1].num))) YYABORT;}
#line 3962 "antimony.tab.cpp"
    break;

  case 264: /* functioncvterm: "name of an existing function" "element name" stringlist lineend  */
#line 808 "antimony.ypp"
                                                    {if (g_registry.ProcessGlobalCVTerm((yyvsp[-3].word),(yyvsp[-2].word),(yyvsp[-1].stringlist))) YYABORT;}
#line 3968 "antimony.tab.cpp"
    break;


#line 3972 "antimony.tab.cpp"

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

#line 810 "antimony.ypp"



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
