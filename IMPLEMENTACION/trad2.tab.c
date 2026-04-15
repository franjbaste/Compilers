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




/* First part of user prologue.  */
#line 1 "trad2.y"
                          // SECCION 1 Declaraciones de C-Yacc
/*
Grupo 81: Fran Jurado Basté, Sergio González Jiménez
Correos: 100522213@alumnos.uc3m.es, 100522264@alumnos.uc3m.es
*/

#include <stdio.h>
#include <ctype.h>            // declaraciones para tolower
#include <string.h>           // declaraciones para cadenas
#include <stdlib.h>           // declaraciones para exit ()

#define FF fflush(stdout);    // para forzar la impresion inmediata

int yylex () ;
int yyerror () ;
char *my_malloc (int);
char *gen_code (char *) ;
char *int_to_string (int) ;
char *char_to_string (char) ;

// MIS DECLARACIONES
extern int in_function ;          
extern char current_func[256] ;
char* get_var_name(char *name);
void add_local(char *name);
int is_local(char *name);
void clear_locals();


char temp [2048] ;

// Abstract Syntax Tree (AST) Node Structure

typedef struct ASTnode t_node ;

struct ASTnode {
    char *op ;
    int type ;		// leaf, unary or binary nodes
    t_node *left ;
    t_node *right ;
} ;


// Definitions for explicit attributes

typedef struct s_attr {
    int value ;    // - Numeric value of a NUMBER 
    char *code ;   // - to pass IDENTIFIER names, and other translations 
    t_node *node ; // - for possible future use of AST
} t_attr ;

#define YYSTYPE t_attr


#line 126 "trad2.tab.c"

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
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    IDENTIF = 259,                 /* IDENTIF  */
    INTEGER = 260,                 /* INTEGER  */
    STRING = 261,                  /* STRING  */
    MAIN = 262,                    /* MAIN  */
    WHILE = 263,                   /* WHILE  */
    PUTS = 264,                    /* PUTS  */
    PRINTF = 265,                  /* PRINTF  */
    AND = 266,                     /* AND  */
    OR = 267,                      /* OR  */
    EQ = 268,                      /* EQ  */
    NEQ = 269,                     /* NEQ  */
    LEQ = 270,                     /* LEQ  */
    GEQ = 271,                     /* GEQ  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    FOR = 274,                     /* FOR  */
    INC = 275,                     /* INC  */
    DEC = 276,                     /* DEC  */
    SWITCH = 277,                  /* SWITCH  */
    CASE = 278,                    /* CASE  */
    DEFAULT = 279,                 /* DEFAULT  */
    BREAK = 280,                   /* BREAK  */
    RETURN = 281,                  /* RETURN  */
    UNARY_SIGN = 282               /* UNARY_SIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIF = 4,                    /* IDENTIF  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_MAIN = 7,                       /* MAIN  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_PUTS = 9,                       /* PUTS  */
  YYSYMBOL_PRINTF = 10,                    /* PRINTF  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_NEQ = 14,                       /* NEQ  */
  YYSYMBOL_LEQ = 15,                       /* LEQ  */
  YYSYMBOL_GEQ = 16,                       /* GEQ  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_INC = 20,                       /* INC  */
  YYSYMBOL_DEC = 21,                       /* DEC  */
  YYSYMBOL_SWITCH = 22,                    /* SWITCH  */
  YYSYMBOL_CASE = 23,                      /* CASE  */
  YYSYMBOL_DEFAULT = 24,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 25,                     /* BREAK  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_27_ = 27,                       /* '='  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_UNARY_SIGN = 35,                /* UNARY_SIGN  */
  YYSYMBOL_36_ = 36,                       /* '!'  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_axioma = 47,                    /* axioma  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_inicio_main = 51,               /* inicio_main  */
  YYSYMBOL_funcion_main = 52,              /* funcion_main  */
  YYSYMBOL_funcion_user = 53,              /* funcion_user  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_lista_params_def = 55,          /* lista_params_def  */
  YYSYMBOL_param_def = 56,                 /* param_def  */
  YYSYMBOL_instruccion = 57,               /* instruccion  */
  YYSYMBOL_lista_sentencias = 58,          /* lista_sentencias  */
  YYSYMBOL_lista_elems = 59,               /* lista_elems  */
  YYSYMBOL_elem = 60,                      /* elem  */
  YYSYMBOL_r_axioma = 61,                  /* r_axioma  */
  YYSYMBOL_sentencia = 62,                 /* sentencia  */
  YYSYMBOL_declaracion = 63,               /* declaracion  */
  YYSYMBOL_lista_vars = 64,                /* lista_vars  */
  YYSYMBOL_var_init = 65,                  /* var_init  */
  YYSYMBOL_bucle_while = 66,               /* bucle_while  */
  YYSYMBOL_incremento = 67,                /* incremento  */
  YYSYMBOL_bucle_for = 68,                 /* bucle_for  */
  YYSYMBOL_sentencia_switch = 69,          /* sentencia_switch  */
  YYSYMBOL_lista_casos = 70,               /* lista_casos  */
  YYSYMBOL_caso_switch = 71,               /* caso_switch  */
  YYSYMBOL_sentencia_if = 72,              /* sentencia_if  */
  YYSYMBOL_expresion = 73,                 /* expresion  */
  YYSYMBOL_termino = 74,                   /* termino  */
  YYSYMBOL_operando = 75,                  /* operando  */
  YYSYMBOL_lista_args = 76                 /* lista_args  */
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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   514

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,     2,     2,    34,     2,     2,
      38,    39,    32,    30,    42,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    37,
      28,    27,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    83,    85,    85,    87,    87,    92,    95,
     103,   102,   112,   113,   114,   120,   123,   124,   125,   126,
     127,   130,   131,   139,   140,   144,   146,   154,   155,   158,
     160,   163,   164,   166,   167,   168,   169,   176,   179,   180,
     184,   190,   196,   206,   213,   217,   223,   230,   236,   237,
     243,   247,   255,   259,   267,   268,   270,   272,   274,   276,
     278,   280,   282,   284,   286,   288,   290,   292,   296,   297,
     298,   300,   304,   306,   308,   310,   311,   312,   316,   317
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIF",
  "INTEGER", "STRING", "MAIN", "WHILE", "PUTS", "PRINTF", "AND", "OR",
  "EQ", "NEQ", "LEQ", "GEQ", "IF", "ELSE", "FOR", "INC", "DEC", "SWITCH",
  "CASE", "DEFAULT", "BREAK", "RETURN", "'='", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "UNARY_SIGN", "'!'", "';'", "'('", "')'", "'{'",
  "'}'", "','", "'['", "']'", "':'", "$accept", "axioma", "$@1", "$@2",
  "$@3", "inicio_main", "funcion_main", "funcion_user", "$@4",
  "lista_params_def", "param_def", "instruccion", "lista_sentencias",
  "lista_elems", "elem", "r_axioma", "sentencia", "declaracion",
  "lista_vars", "var_init", "bucle_while", "incremento", "bucle_for",
  "sentencia_switch", "lista_casos", "caso_switch", "sentencia_if",
  "expresion", "termino", "operando", "lista_args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-43)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     111,   -18,    26,   -15,    -4,    12,   207,    40,   488,   -43,
     -43,    17,   -43,   207,   187,   207,    51,    38,   -43,    20,
      84,    90,   -43,    -7,     3,     3,     3,   207,   395,   -43,
     -43,   -43,    -6,    61,    74,    79,    87,   -43,     7,    89,
     -43,   -43,   -43,   -43,   111,   111,   -43,   395,   127,   -43,
      13,   -43,   395,    19,   235,   129,   130,    26,   106,   112,
     108,   191,   207,   -43,   -43,   -43,   269,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     203,   207,   207,     9,   207,   -43,   -43,   -43,   -43,   -43,
     -43,   111,   -43,   113,   147,   -43,   207,   132,   -43,   122,
     -43,   -43,   -43,   124,   -43,    42,   242,   -43,   291,   419,
     262,   262,   140,   140,   140,   140,    69,    69,   -43,   -43,
     -43,   298,   327,   120,   356,   -43,   -43,   -43,   395,   207,
     -43,   -43,    50,   -43,   395,   -43,   -43,   135,   137,   207,
     142,   488,   395,   -43,   124,   488,   488,   385,   -19,    34,
     -43,    78,   139,   102,   176,   141,     4,   -43,   -43,   -43,
     175,   161,   164,   158,   163,   488,   -43,   -43,   169,   199,
     200,   172,   488,   450,   488,   174,   177,   488,   469,   178,
     159,   -43,   -43,   179,   182,   -43,   -43,   -43,   -43
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       6,     0,    31,     0,    12,     0,    40,    37,    38,     0,
       0,     0,    74,    72,     0,     0,     0,     0,    36,    54,
      68,     1,     0,     0,     0,     0,     0,    21,     0,     0,
      17,    19,    20,    18,    27,    27,     2,    29,     0,    34,
       0,    13,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,    22,    16,    28,     5,
       7,    27,    15,     0,     0,    35,     0,     0,    41,     0,
      39,     8,    32,     0,    76,     0,     0,    75,    66,    67,
      64,    65,    62,    63,    60,    61,    55,    56,    57,    58,
      59,     0,     0,     0,     0,     3,    10,    14,    79,     0,
      42,    26,     0,    23,    25,    77,    73,     0,     0,     0,
       0,     0,    30,    33,     0,     0,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,    48,    11,    43,
      52,     0,     0,     0,     0,     0,    47,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,    45,     0,     0,    51,    53,    46,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   214,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     134,   -38,   -36,   -43,    80,   -42,     2,   -43,   -43,   183,
     -43,   -43,   -43,   -43,   -43,    75,   -43,    -5,   -43,    82,
     171
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    88,    91,    44,    45,     8,     9,    10,   141,    50,
      51,    37,    38,   132,   133,    89,    39,    12,    17,    18,
      40,   163,    41,    42,   156,   157,    43,    52,    29,    30,
      53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      86,    28,    11,    90,   154,   155,    22,    23,    47,    13,
      54,    32,     2,    32,     2,    33,     4,     5,     4,     5,
      14,    13,    66,    19,    34,    15,    35,   154,   155,    36,
      16,    61,    80,     6,    20,     6,    62,    15,    32,     2,
      31,    27,    33,     4,     5,   166,    11,    11,    85,   125,
      21,    34,    93,    35,    46,    94,    36,   106,    95,    58,
       6,    96,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   158,   121,   122,    55,   124,
      57,   135,    32,     2,    96,   123,    33,     4,     5,   143,
      59,   128,   144,    11,    56,    34,    60,    35,   134,    81,
      36,    77,    78,    79,     6,   149,    63,    64,    65,   151,
     152,    86,    82,    86,    86,     1,     2,    83,     3,   159,
       4,     5,   161,   162,   142,    84,    87,    22,    23,   173,
     131,    92,    98,    99,   147,    86,   178,     6,   180,   134,
      86,   183,    86,    32,     2,    86,   101,    33,     4,     5,
     103,   102,    48,   126,    24,    25,    34,   139,    35,   129,
      26,    36,    27,    32,     2,     6,   130,    33,     4,     5,
      75,    76,    77,    78,    79,   145,    34,   146,    35,   164,
     160,    36,   148,    32,     2,     6,   165,    33,     4,     5,
      22,    23,    48,   168,    22,    23,    34,   171,    35,   169,
     186,    36,   170,   175,   176,     6,    22,    23,   172,   174,
      22,    23,   177,   181,     7,   185,   182,    24,    25,   188,
     187,    24,    25,    26,   150,    27,    49,    26,   127,    27,
     104,   167,   105,    24,    25,     0,     0,    24,    25,    26,
     100,    27,    49,    26,     0,    27,    67,    68,    69,    70,
      71,    72,     0,    67,    68,    69,    70,    71,    72,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    78,    79,
      73,    74,    75,    76,    77,    78,    79,    71,    72,    97,
      67,    68,    69,    70,    71,    72,   136,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    79,    73,    74,    75,
      76,    77,    78,    79,    69,    70,    71,    72,   107,    67,
      68,    69,    70,    71,    72,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,    79,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,     0,   137,    67,    68,
      69,    70,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,    79,     0,     0,     0,     0,   138,    67,    68,    69,
      70,    71,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,     0,   140,    67,    68,    69,    70,
      71,    72,     0,     0,     0,     0,    67,    68,    69,    70,
      71,    72,     0,    73,    74,    75,    76,    77,    78,    79,
       0,     0,   153,    73,    74,    75,    76,    77,    78,    79,
      67,     0,    69,    70,    71,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,    75,
      76,    77,    78,    79,    32,     2,     0,     0,    33,     4,
       5,     0,     0,     0,     0,     0,     0,    34,     0,    35,
       0,     0,    36,    32,     2,   179,     6,    33,     4,     5,
       0,     0,     0,     0,     0,     0,    34,     0,    35,     0,
       0,    36,    32,     2,   184,     6,    33,     4,     5,     0,
       0,     0,     0,     0,     0,    34,     0,    35,     0,     0,
      36,     0,     0,     0,     6
};

static const yytype_int16 yycheck[] =
{
      38,     6,     0,    45,    23,    24,     3,     4,    13,    27,
      15,     4,     5,     4,     5,     8,     9,    10,     9,    10,
      38,    27,    27,    38,    17,    43,    19,    23,    24,    22,
       4,    38,    38,    26,    38,    26,    43,    43,     4,     5,
       0,    38,     8,     9,    10,    41,    44,    45,    41,    91,
      38,    17,    39,    19,    37,    42,    22,    62,    39,    39,
      26,    42,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    41,    81,    82,    27,    84,
      42,    39,     4,     5,    42,    83,     8,     9,    10,    39,
       6,    96,    42,    91,    43,    17,     6,    19,   103,    38,
      22,    32,    33,    34,    26,   141,    24,    25,    26,   145,
     146,   149,    38,   151,   152,     4,     5,    38,     7,    41,
       9,    10,    20,    21,   129,    38,    37,     3,     4,   165,
       6,     4,     3,     3,   139,   173,   172,    26,   174,   144,
     178,   177,   180,     4,     5,   183,    40,     8,     9,    10,
      42,    39,     5,    40,    30,    31,    17,    37,    19,    27,
      36,    22,    38,     4,     5,    26,    44,     8,     9,    10,
      30,    31,    32,    33,    34,    40,    17,    40,    19,     3,
      41,    22,    40,     4,     5,    26,    45,     8,     9,    10,
       3,     4,     5,    18,     3,     4,    17,    39,    19,    38,
      41,    22,    38,     4,     4,    26,     3,     4,    45,    40,
       3,     4,    40,    39,     0,    37,    39,    30,    31,    37,
      41,    30,    31,    36,   144,    38,    39,    36,    94,    38,
      39,   156,    61,    30,    31,    -1,    -1,    30,    31,    36,
      57,    38,    39,    36,    -1,    38,    11,    12,    13,    14,
      15,    16,    -1,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      28,    29,    30,    31,    32,    33,    34,    15,    16,    44,
      11,    12,    13,    14,    15,    16,    44,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    28,    29,    30,
      31,    32,    33,    34,    13,    14,    15,    16,    39,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    39,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    39,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    -1,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    37,    28,    29,    30,    31,    32,    33,    34,
      11,    -1,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,     4,     5,    -1,    -1,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,
      -1,    -1,    22,     4,     5,    25,    26,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    -1,
      -1,    22,     4,     5,    25,    26,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,
      22,    -1,    -1,    -1,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     7,     9,    10,    26,    47,    51,    52,
      53,    62,    63,    27,    38,    43,     4,    64,    65,    38,
      38,    38,     3,     4,    30,    31,    36,    38,    73,    74,
      75,     0,     4,     8,    17,    19,    22,    57,    58,    62,
      66,    68,    69,    72,    49,    50,    37,    73,     5,    39,
      55,    56,    73,    76,    73,    27,    43,    42,    39,     6,
       6,    38,    43,    75,    75,    75,    73,    11,    12,    13,
      14,    15,    16,    28,    29,    30,    31,    32,    33,    34,
      38,    38,    38,    38,    38,    41,    57,    37,    47,    61,
      61,    48,     4,    39,    42,    39,    42,    44,     3,     3,
      65,    40,    39,    42,    39,    76,    73,    39,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    62,    73,    61,    40,    56,    73,    27,
      44,     6,    59,    60,    73,    39,    44,    39,    39,    37,
      39,    54,    73,    39,    42,    40,    40,    73,    40,    58,
      60,    58,    58,    37,    23,    24,    70,    71,    41,    41,
      41,    20,    21,    67,     3,    45,    41,    71,    18,    38,
      38,    39,    45,    58,    40,     4,     4,    40,    58,    25,
      58,    39,    39,    58,    25,    37,    41,    41,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    48,    47,    49,    47,    50,    47,    51,    52,
      54,    53,    55,    55,    55,    56,    57,    57,    57,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    64,    64,
      65,    65,    65,    66,    67,    67,    68,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    74,    75,    75,    75,    75,    75,    75,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     3,     0,     3,     4,     3,
       0,     8,     0,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     0,     1,     3,
       6,     1,     4,     6,     3,     4,     2,     2,     1,     3,
       1,     3,     4,     7,     4,     4,    11,     7,     1,     2,
       6,     5,     7,    11,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     2,
       2,     2,     1,     4,     1,     3,     3,     4,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

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
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
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
  yychar = YYEMPTY;
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
  case 2: /* $@1: %empty  */
#line 83 "trad2.y"
                                         { printf ("%s\n", yyvsp[-1].code) ; }
#line 1432 "trad2.tab.c"
    break;

  case 3: /* axioma: sentencia ';' $@1 r_axioma  */
#line 84 "trad2.y"
                                         { ; }
#line 1438 "trad2.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 85 "trad2.y"
                                         { printf ("%s\n", yyvsp[0].code) ; }
#line 1444 "trad2.tab.c"
    break;

  case 5: /* axioma: funcion_main $@2 r_axioma  */
#line 86 "trad2.y"
                                         { ; }
#line 1450 "trad2.tab.c"
    break;

  case 6: /* $@3: %empty  */
#line 87 "trad2.y"
                                         { printf ("%s\n", yyvsp[0].code) ; }
#line 1456 "trad2.tab.c"
    break;

  case 7: /* axioma: funcion_user $@3 r_axioma  */
#line 88 "trad2.y"
                                         { ; }
#line 1462 "trad2.tab.c"
    break;

  case 8: /* inicio_main: MAIN '(' ')' '{'  */
#line 92 "trad2.y"
                                         { in_function = 1 ; strcpy(current_func, "main") ; }
#line 1468 "trad2.tab.c"
    break;

  case 9: /* funcion_main: inicio_main lista_sentencias '}'  */
#line 95 "trad2.y"
                                               { 
                  sprintf (temp, "(defun main ()\n%s\n)", yyvsp[-1].code) ;
                  yyval.code = gen_code (temp) ; 
                  in_function = 0 ; clear_locals() ; // Limpiamos al salir
              }
#line 1478 "trad2.tab.c"
    break;

  case 10: /* $@4: %empty  */
#line 103 "trad2.y"
                  { in_function = 1; strcpy(current_func, yyvsp[-4].code); }
#line 1484 "trad2.tab.c"
    break;

  case 11: /* funcion_user: IDENTIF '(' lista_params_def ')' '{' $@4 lista_sentencias '}'  */
#line 105 "trad2.y"
                  { 
                      sprintf (temp, "(defun %s (%s)\n%s\n)", yyvsp[-7].code, yyvsp[-5].code, yyvsp[-1].code) ;
                      yyval.code = gen_code (temp) ; 
                      in_function = 0 ; clear_locals() ; 
                  }
#line 1494 "trad2.tab.c"
    break;

  case 12: /* lista_params_def: %empty  */
#line 112 "trad2.y"
                                                 { yyval.code = gen_code("") ; }
#line 1500 "trad2.tab.c"
    break;

  case 13: /* lista_params_def: param_def  */
#line 113 "trad2.y"
                                                 { yyval = yyvsp[0] ; }
#line 1506 "trad2.tab.c"
    break;

  case 14: /* lista_params_def: lista_params_def ',' param_def  */
#line 114 "trad2.y"
                                                 { 
                      sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;
                      yyval.code = gen_code (temp) ; 
                  }
#line 1515 "trad2.tab.c"
    break;

  case 15: /* param_def: INTEGER IDENTIF  */
#line 120 "trad2.y"
                                                 { yyval = yyvsp[0] ; }
#line 1521 "trad2.tab.c"
    break;

  case 16: /* instruccion: sentencia ';'  */
#line 123 "trad2.y"
                                     { yyval = yyvsp[-1] ; }
#line 1527 "trad2.tab.c"
    break;

  case 17: /* instruccion: bucle_while  */
#line 124 "trad2.y"
                                     { yyval = yyvsp[0] ; }
#line 1533 "trad2.tab.c"
    break;

  case 18: /* instruccion: sentencia_if  */
#line 125 "trad2.y"
                                     { yyval = yyvsp[0] ; }
#line 1539 "trad2.tab.c"
    break;

  case 19: /* instruccion: bucle_for  */
#line 126 "trad2.y"
                                     { yyval = yyvsp[0] ; }
#line 1545 "trad2.tab.c"
    break;

  case 20: /* instruccion: sentencia_switch  */
#line 127 "trad2.y"
                                     { yyval = yyvsp[0] ; }
#line 1551 "trad2.tab.c"
    break;

  case 21: /* lista_sentencias: instruccion  */
#line 130 "trad2.y"
                                                     { yyval = yyvsp[0] ; }
#line 1557 "trad2.tab.c"
    break;

  case 22: /* lista_sentencias: lista_sentencias instruccion  */
#line 131 "trad2.y"
                                                     { 
                      sprintf (temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code) ;
                      yyval.code = gen_code (temp) ; 
                  }
#line 1566 "trad2.tab.c"
    break;

  case 23: /* lista_elems: elem  */
#line 139 "trad2.y"
                                         { yyval = yyvsp[0] ; }
#line 1572 "trad2.tab.c"
    break;

  case 24: /* lista_elems: lista_elems ',' elem  */
#line 140 "trad2.y"
                                         { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1579 "trad2.tab.c"
    break;

  case 25: /* elem: expresion  */
#line 144 "trad2.y"
                                         { sprintf (temp, "(princ %s)", yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1586 "trad2.tab.c"
    break;

  case 26: /* elem: STRING  */
#line 146 "trad2.y"
                                         { sprintf (temp, "(princ \"%s\")", yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1593 "trad2.tab.c"
    break;

  case 27: /* r_axioma: %empty  */
#line 154 "trad2.y"
                                         { ; }
#line 1599 "trad2.tab.c"
    break;

  case 28: /* r_axioma: axioma  */
#line 155 "trad2.y"
                                         { ; }
#line 1605 "trad2.tab.c"
    break;

  case 29: /* sentencia: IDENTIF '=' expresion  */
#line 158 "trad2.y"
                                        { sprintf (temp, "(setf %s %s)", get_var_name(yyvsp[-2].code), yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1612 "trad2.tab.c"
    break;

  case 30: /* sentencia: IDENTIF '[' expresion ']' '=' expresion  */
#line 160 "trad2.y"
                                                      { 
                                           sprintf (temp, "(setf (aref %s %s) %s)", get_var_name(yyvsp[-5].code), yyvsp[-3].code, yyvsp[0].code) ; 
                                           yyval.code = gen_code (temp) ; }
#line 1620 "trad2.tab.c"
    break;

  case 31: /* sentencia: declaracion  */
#line 163 "trad2.y"
                                         { yyval = yyvsp[0] ; }
#line 1626 "trad2.tab.c"
    break;

  case 32: /* sentencia: PUTS '(' STRING ')'  */
#line 164 "trad2.y"
                                         { sprintf (temp, "(print \"%s\")", yyvsp[-1].code) ;  
                                           yyval.code = gen_code (temp) ; }
#line 1633 "trad2.tab.c"
    break;

  case 33: /* sentencia: PRINTF '(' STRING ',' lista_elems ')'  */
#line 166 "trad2.y"
                                                    { yyval = yyvsp[-1] ; }
#line 1639 "trad2.tab.c"
    break;

  case 34: /* sentencia: IDENTIF '(' ')'  */
#line 167 "trad2.y"
                                             { sprintf(temp, "(%s)", yyvsp[-2].code); yyval.code = gen_code(temp); }
#line 1645 "trad2.tab.c"
    break;

  case 35: /* sentencia: IDENTIF '(' lista_args ')'  */
#line 168 "trad2.y"
                                             { sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1651 "trad2.tab.c"
    break;

  case 36: /* sentencia: RETURN expresion  */
#line 169 "trad2.y"
                                             { sprintf(temp, "(return-from %s %s)", current_func, yyvsp[0].code); yyval.code = gen_code(temp); }
#line 1657 "trad2.tab.c"
    break;

  case 37: /* declaracion: INTEGER lista_vars  */
#line 176 "trad2.y"
                                         { yyval = yyvsp[0] ; }
#line 1663 "trad2.tab.c"
    break;

  case 38: /* lista_vars: var_init  */
#line 179 "trad2.y"
                                         { yyval = yyvsp[0] ; }
#line 1669 "trad2.tab.c"
    break;

  case 39: /* lista_vars: lista_vars ',' var_init  */
#line 180 "trad2.y"
                                         { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1676 "trad2.tab.c"
    break;

  case 40: /* var_init: IDENTIF  */
#line 184 "trad2.y"
                                         { 
                                           char *vname = yyvsp[0].code ;
                                           if (in_function) { add_local(vname); vname = get_var_name(vname); }
                                           sprintf (temp, "(setq %s 0)", vname) ;
                                           yyval.code = gen_code (temp) ; 
                                         }
#line 1687 "trad2.tab.c"
    break;

  case 41: /* var_init: IDENTIF '=' NUMBER  */
#line 190 "trad2.y"
                                         { 
                                           char *vname = yyvsp[-2].code ;
                                           if (in_function) { add_local(vname); vname = get_var_name(vname); }
                                           sprintf (temp, "(setq %s %d)", vname, yyvsp[0].value) ;
                                           yyval.code = gen_code (temp) ; 
                                         }
#line 1698 "trad2.tab.c"
    break;

  case 42: /* var_init: IDENTIF '[' NUMBER ']'  */
#line 196 "trad2.y"
                                         { 
                                           char *vname = yyvsp[-3].code ;
                                           if (in_function) { add_local(vname); vname = get_var_name(vname); }
                                           sprintf (temp, "(setq %s (make-array %d))", vname, yyvsp[-1].value) ;
                                           yyval.code = gen_code (temp) ; 
                                         }
#line 1709 "trad2.tab.c"
    break;

  case 43: /* bucle_while: WHILE '(' expresion ')' '{' lista_sentencias '}'  */
#line 206 "trad2.y"
                                                               { 
                  sprintf (temp, "(loop while %s do\n%s\n)", yyvsp[-4].code, yyvsp[-1].code) ;
                  yyval.code = gen_code (temp) ; 
              }
#line 1718 "trad2.tab.c"
    break;

  case 44: /* incremento: INC '(' IDENTIF ')'  */
#line 213 "trad2.y"
                                     { 
                                         sprintf(temp, "(setf %s (+ %s 1))", get_var_name(yyvsp[-1].code), get_var_name(yyvsp[-1].code));
                                         yyval.code = gen_code(temp); 
                                     }
#line 1727 "trad2.tab.c"
    break;

  case 45: /* incremento: DEC '(' IDENTIF ')'  */
#line 217 "trad2.y"
                                     { 
                                         sprintf(temp, "(setf %s (- %s 1))", get_var_name(yyvsp[-1].code), get_var_name(yyvsp[-1].code));
                                         yyval.code = gen_code(temp); 
                                     }
#line 1736 "trad2.tab.c"
    break;

  case 46: /* bucle_for: FOR '(' sentencia ';' expresion ';' incremento ')' '{' lista_sentencias '}'  */
#line 223 "trad2.y"
                                                                                          { 
                  sprintf(temp, "%s\n(loop while %s do\n%s\n%s\n)", yyvsp[-8].code, yyvsp[-6].code, yyvsp[-1].code, yyvsp[-4].code);
                  yyval.code = gen_code(temp); 
              }
#line 1745 "trad2.tab.c"
    break;

  case 47: /* sentencia_switch: SWITCH '(' expresion ')' '{' lista_casos '}'  */
#line 230 "trad2.y"
                                                               { 
                      sprintf(temp, "(case %s\n%s\n)", yyvsp[-4].code, yyvsp[-1].code);
                      yyval.code = gen_code(temp); 
                  }
#line 1754 "trad2.tab.c"
    break;

  case 48: /* lista_casos: caso_switch  */
#line 236 "trad2.y"
                                               { yyval = yyvsp[0] ; }
#line 1760 "trad2.tab.c"
    break;

  case 49: /* lista_casos: lista_casos caso_switch  */
#line 237 "trad2.y"
                                               { 
                      sprintf(temp, "%s\n%s", yyvsp[-1].code, yyvsp[0].code);
                      yyval.code = gen_code(temp); 
                  }
#line 1769 "trad2.tab.c"
    break;

  case 50: /* caso_switch: CASE NUMBER ':' lista_sentencias BREAK ';'  */
#line 243 "trad2.y"
                                                             { 
                      sprintf(temp, "(%d\n%s)", yyvsp[-4].value, yyvsp[-2].code);
                      yyval.code = gen_code(temp); 
                  }
#line 1778 "trad2.tab.c"
    break;

  case 51: /* caso_switch: DEFAULT ':' lista_sentencias BREAK ';'  */
#line 247 "trad2.y"
                                                         { 
                      sprintf(temp, "(otherwise\n%s)", yyvsp[-2].code);
                      yyval.code = gen_code(temp); 
                  }
#line 1787 "trad2.tab.c"
    break;

  case 52: /* sentencia_if: IF '(' expresion ')' '{' lista_sentencias '}'  */
#line 255 "trad2.y"
                                                            { 
                  sprintf (temp, "(if %s\n(progn\n%s\n))", yyvsp[-4].code, yyvsp[-1].code) ;
                  yyval.code = gen_code (temp) ; 
              }
#line 1796 "trad2.tab.c"
    break;

  case 53: /* sentencia_if: IF '(' expresion ')' '{' lista_sentencias '}' ELSE '{' lista_sentencias '}'  */
#line 259 "trad2.y"
                                                                                          { 
                  sprintf (temp, "(if %s\n(progn\n%s\n)\n(progn\n%s\n))", yyvsp[-8].code, yyvsp[-5].code, yyvsp[-1].code) ;
                  yyval.code = gen_code (temp) ; 
              }
#line 1805 "trad2.tab.c"
    break;

  case 54: /* expresion: termino  */
#line 267 "trad2.y"
                                         { yyval = yyvsp[0] ; }
#line 1811 "trad2.tab.c"
    break;

  case 55: /* expresion: expresion '+' expresion  */
#line 268 "trad2.y"
                                         { sprintf (temp, "(+ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1818 "trad2.tab.c"
    break;

  case 56: /* expresion: expresion '-' expresion  */
#line 270 "trad2.y"
                                         { sprintf (temp, "(- %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1825 "trad2.tab.c"
    break;

  case 57: /* expresion: expresion '*' expresion  */
#line 272 "trad2.y"
                                         { sprintf (temp, "(* %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1832 "trad2.tab.c"
    break;

  case 58: /* expresion: expresion '/' expresion  */
#line 274 "trad2.y"
                                         { sprintf (temp, "(/ %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1839 "trad2.tab.c"
    break;

  case 59: /* expresion: expresion '%' expresion  */
#line 276 "trad2.y"
                                       { sprintf (temp, "(mod %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                         yyval.code = gen_code (temp) ; }
#line 1846 "trad2.tab.c"
    break;

  case 60: /* expresion: expresion '<' expresion  */
#line 278 "trad2.y"
                                       { sprintf (temp, "(< %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                         yyval.code = gen_code (temp) ; }
#line 1853 "trad2.tab.c"
    break;

  case 61: /* expresion: expresion '>' expresion  */
#line 280 "trad2.y"
                                       { sprintf (temp, "(> %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                         yyval.code = gen_code (temp) ; }
#line 1860 "trad2.tab.c"
    break;

  case 62: /* expresion: expresion LEQ expresion  */
#line 282 "trad2.y"
                                       { sprintf (temp, "(<= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                         yyval.code = gen_code (temp) ; }
#line 1867 "trad2.tab.c"
    break;

  case 63: /* expresion: expresion GEQ expresion  */
#line 284 "trad2.y"
                                       { sprintf (temp, "(>= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                         yyval.code = gen_code (temp) ; }
#line 1874 "trad2.tab.c"
    break;

  case 64: /* expresion: expresion EQ expresion  */
#line 286 "trad2.y"
                                       { sprintf (temp, "(= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                         yyval.code = gen_code (temp) ; }
#line 1881 "trad2.tab.c"
    break;

  case 65: /* expresion: expresion NEQ expresion  */
#line 288 "trad2.y"
                                       { sprintf (temp, "(/= %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                         yyval.code = gen_code (temp) ; }
#line 1888 "trad2.tab.c"
    break;

  case 66: /* expresion: expresion AND expresion  */
#line 290 "trad2.y"
                                       { sprintf (temp, "(and %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                         yyval.code = gen_code (temp) ; }
#line 1895 "trad2.tab.c"
    break;

  case 67: /* expresion: expresion OR expresion  */
#line 292 "trad2.y"
                                       { sprintf (temp, "(or %s %s)", yyvsp[-2].code, yyvsp[0].code) ;
                                         yyval.code = gen_code (temp) ; }
#line 1902 "trad2.tab.c"
    break;

  case 68: /* termino: operando  */
#line 296 "trad2.y"
                                                   { yyval = yyvsp[0] ; }
#line 1908 "trad2.tab.c"
    break;

  case 69: /* termino: '+' operando  */
#line 297 "trad2.y"
                                                   { yyval = yyvsp[-1] ; }
#line 1914 "trad2.tab.c"
    break;

  case 70: /* termino: '-' operando  */
#line 298 "trad2.y"
                                                   { sprintf (temp, "(- %s)", yyvsp[0].code) ;
                                                     yyval.code = gen_code (temp) ; }
#line 1921 "trad2.tab.c"
    break;

  case 71: /* termino: '!' operando  */
#line 300 "trad2.y"
                                                 { sprintf (temp, "(not %s)", yyvsp[0].code) ;
                                                   yyval.code = gen_code (temp) ; }
#line 1928 "trad2.tab.c"
    break;

  case 72: /* operando: IDENTIF  */
#line 304 "trad2.y"
                                           { sprintf (temp, "%s", get_var_name(yyvsp[0].code)) ;
                                           yyval.code = gen_code (temp) ; }
#line 1935 "trad2.tab.c"
    break;

  case 73: /* operando: IDENTIF '[' expresion ']'  */
#line 306 "trad2.y"
                                           { sprintf (temp, "(aref %s %s)", get_var_name(yyvsp[-3].code), yyvsp[-1].code) ;
                                           yyval.code = gen_code (temp) ; }
#line 1942 "trad2.tab.c"
    break;

  case 74: /* operando: NUMBER  */
#line 308 "trad2.y"
                                         { sprintf (temp, "%d", yyvsp[0].value) ;
                                           yyval.code = gen_code (temp) ; }
#line 1949 "trad2.tab.c"
    break;

  case 75: /* operando: '(' expresion ')'  */
#line 310 "trad2.y"
                                         { yyval = yyvsp[-1] ; }
#line 1955 "trad2.tab.c"
    break;

  case 76: /* operando: IDENTIF '(' ')'  */
#line 311 "trad2.y"
                                             { sprintf(temp, "(%s)", yyvsp[-2].code); yyval.code = gen_code(temp); }
#line 1961 "trad2.tab.c"
    break;

  case 77: /* operando: IDENTIF '(' lista_args ')'  */
#line 312 "trad2.y"
                                             { sprintf(temp, "(%s %s)", yyvsp[-3].code, yyvsp[-1].code); yyval.code = gen_code(temp); }
#line 1967 "trad2.tab.c"
    break;

  case 78: /* lista_args: expresion  */
#line 316 "trad2.y"
                                             { yyval = yyvsp[0] ; }
#line 1973 "trad2.tab.c"
    break;

  case 79: /* lista_args: lista_args ',' expresion  */
#line 317 "trad2.y"
                                             { sprintf (temp, "%s %s", yyvsp[-2].code, yyvsp[0].code) ; yyval.code = gen_code (temp) ; }
#line 1979 "trad2.tab.c"
    break;


#line 1983 "trad2.tab.c"

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  if (yychar != YYEMPTY)
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

  return yyresult;
}

#line 321 "trad2.y"
                            // SECCION 4    Codigo en C

int n_line = 1 ;


// --- GESTIÓN DE VARIABLES LOCALES ---
char local_vars[100][256] ;
int num_locals = 0 ;
int in_function = 0 ;           // Bandera: 1 si estamos dentro de una función
char current_func[256] = "" ;   // Nombre de la función actual

void add_local (char *name) {
    strcpy (local_vars[num_locals++], name) ;
}

int is_local (char *name) {
    for (int i = 0; i < num_locals; i++) {
        if (strcmp (local_vars[i], name) == 0) return 1 ; // Es local
    }
    return 0 ; // Es global
}

void clear_locals () {
    num_locals = 0 ;
}

char* get_var_name (char *name) {
    if (is_local (name)) {
        // Si es local, devolvemos "funcion_variable"
        char *new_name = my_malloc (strlen(current_func) + strlen(name) + 2) ;
        sprintf (new_name, "%s_%s", current_func, name) ;
        return new_name ;
    }
    return name ; // Si es global, devolvemos el nombre normal
}
// ------------------------------------



int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_line) ;
    printf ( "\n") ;	// bye
}

char *int_to_string (int n)
{
    char ltemp [2048] ;

    sprintf (ltemp, "%d", n) ;

    return gen_code (ltemp) ;
}

char *char_to_string (char c)
{
    char ltemp [2048] ;

    sprintf (ltemp, "%c", c) ;

    return gen_code (ltemp) ;
}

char *my_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_keyword { // para las palabras reservadas de C
    char *name ;
    int token ;
} t_keyword ;

t_keyword keywords [] = { // define las palabras reservadas y los
    "main",        MAIN,           // y los token asociados
    "int",         INTEGER,
    "puts",        PUTS,
    "printf",      PRINTF,
    "&&",          AND,            
    "||",          OR,
    "==",          EQ,
    "!=",          NEQ,
    "<=",          LEQ,
    ">=",          GEQ,
    "while",       WHILE, 
    "if",          IF,            
    "else",        ELSE, 
    "for",         FOR,           
    "inc",         INC,
    "dec",         DEC,   
    "switch",      SWITCH,        
    "case",        CASE,
    "default",     DEFAULT,
    "break",       BREAK,    
    "return",      RETURN,  
    NULL,          0
                  // para marcar el fin de la tabla
} ;

t_keyword *search_keyword (char *symbol_name)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_keyword *sim ;

    i = 0 ;
    sim = keywords ;
    while (sim [i].name != NULL) {
	    if (strcmp (sim [i].name, symbol_name) == 0) {
		                             // strcmp(a, b) devuelve == 0 si a==b
            return &(sim [i]) ;
        }
        i++ ;
    }

    return NULL ;
}

 
/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *gen_code (char *name)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l ;
	
    l = strlen (name)+1 ;
    p = (char *) my_malloc (l) ;
    strcpy (p, name) ;
	
    return p ;
}


int yylex ()
{
// NO MODIFICAR ESTA FUNCION SIN PERMISO
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "!<=|>%&/+-*" ;
    char temp_str [256] ;
    t_keyword *symbol ;

    do {
        c = getchar () ;

        if (c == '#') {	// Ignora las lineas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                ungetc (cc, stdin) ;
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        } else if (c == '\\') c = getchar () ;
		
        if (c == '\n')
            n_line++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            temp_str [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_line) ;
        }		 	// habria que leer hasta el siguiente " , pero, y si falta?
        temp_str [--i] = '\0' ;
        yylval.code = gen_code (temp_str) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        ungetc (c, stdin) ;
        scanf ("%d", &yylval.value) ;
//         printf ("\nDEV: NUMBER %d\n", yylval.value) ;        // PARA DEPURAR
        return NUMBER ;
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') && i < 255) {
            temp_str [i++] = tolower (c) ;
            c = getchar () ;
        }
        temp_str [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.code = gen_code (temp_str) ;
        symbol = search_keyword (yylval.code) ;
        if (symbol == NULL) {    // no es palabra reservada -> identificador antes vrariabre
//               printf ("\nDEV: IDENTIF %s\n", yylval.code) ;    // PARA DEPURAR
            return (IDENTIF) ;
        } else {
//               printf ("\nDEV: OTRO %s\n", yylval.code) ;       // PARA DEPURAR
            return (symbol->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (temp_str, "%c%c", (char) c, (char) cc) ;
        symbol = search_keyword (temp_str) ;
        if (symbol == NULL) {
            ungetc (cc, stdin) ;
            yylval.code = NULL ;
            return (c) ;
        } else {
            yylval.code = gen_code (temp_str) ; // aunque no se use
            return (symbol->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
//         printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}


int main ()
{
    yyparse () ;
}
