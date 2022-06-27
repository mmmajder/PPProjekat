/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "semantic.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "defs.h"
  #include "symtab.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
	int type=-1;
	char *class_names[100];  
	int class_count = 0;
	int *class_name_size[100];
	int list_vars_type = -1;
	int func_count = 0;
	int id_cls = 0;
	
	int constr_arg_count = 0;
	
	int return_count = 0;
	
	int lab_num = -1;
	
	int constr_type = -1;
	
	int ret_type = -1;
	

#line 105 "semantic.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "semantic.tab.h".  */
#ifndef YY_YY_SEMANTIC_TAB_H_INCLUDED
# define YY_YY_SEMANTIC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _TYPE = 258,
    _ACCESS_SPECIFIER = 259,
    _IF = 260,
    _ELSE = 261,
    _RETURN = 262,
    _ID = 263,
    _INT_NUMBER = 264,
    _UINT_NUMBER = 265,
    _CLASSNAME = 266,
    _LPAREN = 267,
    _RPAREN = 268,
    _LBRACKET = 269,
    _RBRACKET = 270,
    _ASSIGN = 271,
    _SEMICOLON = 272,
    _AROP = 273,
    _RELOP = 274,
    _COMMA = 275,
    _INC = 276,
    _WHILE = 277,
    _DO = 278,
    _PRIVATE = 279,
    _PROTECTED = 280,
    _PUBLIC = 281,
    _THIS = 282,
    _FOR = 283,
    _CONTIUNE = 284,
    _BREAK = 285,
    _NEW = 286,
    _CLASS = 287,
    _STATIC = 288,
    _DOT = 289,
    ONLY_IF = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "semantic.y" /* yacc.c:355  */

  int i;
  char *s;

#line 186 "semantic.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SEMANTIC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 203 "semantic.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   120

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    90,    94,    95,   100,   100,   121,   124,
     126,   129,   131,   135,   135,   146,   147,   147,   151,   152,
     157,   157,   171,   173,   177,   177,   201,   203,   208,   207,
     237,   239,   244,   246,   257,   262,   264,   268,   269,   270,
     271,   272,   273,   277,   282,   289,   277,   296,   298,   302,
     309,   320,   319,   334,   347,   352,   353,   358,   357,   369,
     377,   369,   389,   397,   398,   404,   405,   410,   413,   419,
     418,   436,   438,   448,   449,   457,   459,   463,   463,   471,
     471,   479,   491,   507,   514,   524,   532
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_TYPE", "_ACCESS_SPECIFIER", "_IF",
  "_ELSE", "_RETURN", "_ID", "_INT_NUMBER", "_UINT_NUMBER", "_CLASSNAME",
  "_LPAREN", "_RPAREN", "_LBRACKET", "_RBRACKET", "_ASSIGN", "_SEMICOLON",
  "_AROP", "_RELOP", "_COMMA", "_INC", "_WHILE", "_DO", "_PRIVATE",
  "_PROTECTED", "_PUBLIC", "_THIS", "_FOR", "_CONTIUNE", "_BREAK", "_NEW",
  "_CLASS", "_STATIC", "_DOT", "ONLY_IF", "$accept", "program",
  "class_list", "class", "@1", "class_statements", "class_variable_list",
  "constructor_list", "constructor", "$@2", "_constr_param_list", "$@3",
  "_constr_with_params", "_constr_param", "$@4", "_constructor_body",
  "_constructor_row", "$@5", "function_list", "function", "@6", "static",
  "parameter", "func_body", "statement_list", "statement",
  "make_object_statement", "@7", "$@8", "$@9", "ids", "id_list",
  "inc_statement", "$@10", "assignment_statement", "compound_statement",
  "if_statement", "if_part", "@11", "for_statement", "$@12", "@13",
  "rel_exp", "exp", "literal", "function_call", "$@14", "argument",
  "num_exp", "variable_list", "variable", "$@15", "class_variable", "$@16",
  "class_line_vars", "vars", "return_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

#define YYPACT_NINF -76

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-76)))

#define YYTABLE_NINF -70

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      19,   -19,    36,    19,   -76,    28,   -76,   -76,   -76,    30,
     -76,   -76,    43,   -76,    39,   -76,    47,   -76,   -76,    15,
     -76,     5,    45,    25,   -76,   -76,   -76,    51,    57,   -76,
      58,   -76,    49,    60,    56,    52,   -76,    48,   -76,   -76,
     -76,    59,    60,    53,   -13,   -76,   -76,    66,   -76,    37,
     -76,    62,    61,    64,   -76,    63,    65,   -76,   -76,    67,
      70,   -76,   -76,    -4,   -76,    68,    71,    72,    23,    73,
     -76,   -76,    74,   -76,   -76,   -76,   -76,   -76,    76,   -76,
     -76,   -76,   -76,    17,   -76,    75,   -76,   -76,    33,   -76,
     -76,   -76,   -76,    31,    33,    55,    80,    77,    69,   -76,
      82,    33,    79,    -8,   -76,    33,    34,    78,   -76,    84,
      10,   -76,   -76,    81,     9,    33,   -76,   -76,   -76,   -76,
      83,   -76,    85,    69,    33,    88,    86,    87,    89,   -76,
     -76,    86,   -76,    91,    44,   -76,    90,    94,    33,    95,
      92,   -76,    97,    93,   100,    98,   103,    96,   -76,   -76,
      99,   102,   -76,   -76,     1,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     3,     4,     0,     1,     5,     6,     0,
       9,     7,    11,    79,    26,    10,     0,    13,    12,     0,
      81,     0,     0,    30,     8,    27,    80,     0,    15,    31,
       0,    82,     0,     0,     0,     0,    20,    17,    18,    28,
      22,     0,     0,     0,     0,    21,    19,    32,    14,     0,
      23,     0,     0,     0,    33,     0,     0,    75,    29,     0,
      35,    24,    77,     0,    76,     0,     0,     0,     0,    51,
      43,    34,     0,    36,    38,    39,    40,    42,    55,    37,
      41,    25,    83,     0,    57,    64,    67,    68,     0,    86,
      73,    63,    65,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,    85,     0,     0,     0,    44,     0,
       0,    56,    84,     0,     0,    71,    66,    74,    53,    52,
       0,    59,     0,     0,     0,     0,    72,     0,     0,    54,
      58,    62,    70,     0,     0,    45,     0,     0,     0,    47,
       0,    49,     0,    48,     0,     0,     0,     0,    46,    50,
       0,     0,    60,    35,     0,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   -76,   111,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,    54,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -75,   -17,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -26,   -76,   -76,   -76,   -76,
     -76,   -76,   -40,    14,   -14,   -76,   -76,   -76,   -68,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     9,    11,    12,    14,    18,    22,
      32,    33,    37,    38,    41,    44,    50,    65,    19,    25,
      43,    30,    52,    58,    63,    73,    74,    96,   120,   137,
     142,   143,    75,    95,    76,   111,    77,    78,   101,    79,
     128,   153,   113,    90,    91,    92,   102,   125,   114,    60,
      64,    66,    15,    16,    21,    83,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      93,    67,    48,    68,    69,   116,    67,    70,    68,    69,
     105,    71,    70,     5,    49,    67,   155,    68,    69,    23,
     103,    70,    26,     1,    72,    27,   106,   105,   124,    72,
      24,    85,    86,    87,    99,    88,     6,   100,    72,     8,
      89,    85,    86,    87,    10,    88,    13,   126,   104,   105,
      17,   118,   105,    86,    87,    20,   131,    28,    29,    31,
     -16,    34,    35,    36,    39,    47,    40,    45,    42,    51,
      54,    53,    56,    62,    55,    61,   107,    57,   154,    82,
     109,    59,    98,   110,    84,    81,    97,   -69,   108,    94,
     112,   115,   121,   122,   123,   119,    46,   130,   140,   127,
     129,   132,   135,   141,   105,   134,   139,   138,   147,   144,
     145,   149,   151,   146,     7,   148,   152,   150,   133,   117,
     136
};

static const yytype_uint8 yycheck[] =
{
      68,     5,    15,     7,     8,    13,     5,    11,     7,     8,
      18,    15,    11,    32,    27,     5,    15,     7,     8,     4,
      88,    11,    17,     4,    28,    20,    94,    18,    19,    28,
      15,     8,     9,    10,    17,    12,     0,    20,    28,    11,
      17,     8,     9,    10,    14,    12,     3,   115,    17,    18,
      11,    17,    18,     9,    10,     8,   124,    12,    33,     8,
       3,     3,    13,     3,     8,    12,    14,     8,    20,     3,
       8,    34,     8,     3,    13,     8,    21,    14,   153,     8,
       3,    16,     6,    14,    12,    17,    12,    12,     8,    16,
       8,    12,     8,   110,    13,    17,    42,   123,   138,    16,
      15,    13,    11,     8,    18,    16,    12,    17,     8,    17,
      13,     8,    13,    20,     3,    17,    14,    21,    31,   105,
     134
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    37,    38,    39,    32,     0,    39,    11,    40,
      14,    41,    42,     3,    43,    88,    89,    11,    44,    54,
       8,    90,    45,     4,    15,    55,    17,    20,    12,    33,
      57,     8,    46,    47,     3,    13,     3,    48,    49,     8,
      14,    50,    20,    56,    51,     8,    49,    12,    15,    27,
      52,     3,    58,    34,     8,    13,     8,    14,    59,    16,
      85,     8,     3,    60,    86,    53,    87,     5,     7,     8,
      11,    15,    28,    61,    62,    68,    70,    72,    73,    75,
      92,    17,     8,    91,    12,     8,     9,    10,    12,    17,
      79,    80,    81,    84,    16,    69,    63,    12,     6,    17,
      20,    74,    82,    84,    17,    18,    84,    21,     8,     3,
      14,    71,     8,    78,    84,    12,    13,    79,    17,    17,
      64,     8,    61,    13,    19,    83,    84,    16,    76,    15,
      71,    84,    13,    31,    16,    11,    80,    65,    17,    12,
      78,     8,    66,    67,    17,    13,    20,     8,    17,     8,
      21,    13,    14,    77,    60,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    40,    39,    41,    42,
      42,    43,    43,    45,    44,    46,    47,    46,    48,    48,
      50,    49,    51,    51,    53,    52,    54,    54,    56,    55,
      57,    57,    58,    58,    59,    60,    60,    61,    61,    61,
      61,    61,    61,    63,    64,    65,    62,    66,    66,    67,
      67,    69,    68,    70,    71,    72,    72,    74,    73,    76,
      77,    75,    78,    79,    79,    79,    79,    80,    80,    82,
      81,    83,    83,    84,    84,    85,    85,    87,    86,    89,
      88,    90,    90,    91,    91,    92,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     0,     5,     5,     0,
       2,     0,     2,     0,     8,     0,     0,     2,     1,     3,
       0,     3,     0,     2,     0,     7,     0,     2,     0,     9,
       0,     1,     0,     2,     4,     0,     2,     1,     1,     1,
       1,     1,     1,     0,     0,     0,    12,     0,     1,     1,
       3,     0,     4,     4,     3,     1,     3,     0,     6,     0,
       0,    17,     3,     1,     1,     1,     3,     1,     1,     0,
       5,     0,     1,     1,     3,     0,     2,     0,     4,     0,
       4,     1,     3,     1,     3,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
        case 6:
#line 100 "semantic.y" /* yacc.c:1646  */
    {
	//provera da li postoji funkcija sa datim imenom
			int cls_idx = lookup_symbol((yyvsp[0].s), CLS);
			
			if(cls_idx == NO_INDEX)
			{
        class_count++;
        (yyval.i) = insert_symbol((yyvsp[0].s), CLS, (yyvsp[-2].i), NO_ATR, class_count);
      }
      else 
        err("redefinition of class '%s'", (yyvsp[0].s));

	}
#line 1405 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 112 "semantic.y" /* yacc.c:1646  */
    {
		if (get_type((yyvsp[-1].i))==1) {
			 clear_symbols((yyvsp[-1].i)+1);
		}
	  print_symtab();
	}
#line 1416 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 135 "semantic.y" /* yacc.c:1646  */
    {
		func_count++;
		int idx = lookup_symbol_last((yyvsp[0].s), CLS, class_count);
		if (idx==NO_INDEX) {
			err("Wrong constructor");
		}
		insert_symbol((yyvsp[0].s), CONSTR, NO_ATR, NO_ATR, class_count);
	}
#line 1429 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 146 "semantic.y" /* yacc.c:1646  */
    {constr_type=-1; }
#line 1435 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 147 "semantic.y" /* yacc.c:1646  */
    {constr_type=-1; }
#line 1441 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 152 "semantic.y" /* yacc.c:1646  */
    {
	}
#line 1448 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 157 "semantic.y" /* yacc.c:1646  */
    {
		if (constr_type==-1)
			constr_type = (yyvsp[0].i);
		else {
			if (constr_type!=(yyvsp[0].i))
				err("parameter cannot be of VOID type");
		}
	}
#line 1461 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 164 "semantic.y" /* yacc.c:1646  */
    {
		insert_symbol((yyvsp[0].s), PAR, (yyvsp[-2].i), NO_ATR, func_count);
		if((yyvsp[-2].i) == VOID)
			err("parameter cannot be of VOID type");
	}
#line 1471 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 177 "semantic.y" /* yacc.c:1646  */
    {

		int idx = lookup_symbol((yyvsp[-2].s), CLS_ATR);
		if (idx==-1) {
			err("Variable is not declared in last class");
		}
		
		if (get_atr2(idx) != class_count) {
			err("Variable is not declared in last class");
		}
		
		if(lookup_symbol_last((yyvsp[0].s), PAR, func_count)==NO_INDEX) {
			if(lookup_symbol_last((yyvsp[0].s), CLS_ATR, class_count)==NO_INDEX) {
				err("value for param is not declared in this scope: '%s'", (yyvsp[0].s));
			}
		}
		
	}
#line 1494 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 208 "semantic.y" /* yacc.c:1646  */
    {
				func_count++;
        fun_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fun_idx == NO_INDEX) {
          fun_idx = insert_symbol((yyvsp[0].s), FUN, (yyvsp[-1].i), (yyvsp[-3].i), class_count);
}
        else {
        	if (get_atr2(fun_idx)!=class_count) {
        		fun_idx = insert_symbol((yyvsp[0].s), FUN, (yyvsp[-1].i), (yyvsp[-3].i), class_count);
        	}
        	else 
          	err("redefinition of function '%s'", (yyvsp[0].s));
        }
        (yyval.i) = fun_idx;
      }
#line 1514 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 224 "semantic.y" /* yacc.c:1646  */
    {
      
        if( (return_count == 0) && ((yyvsp[-6].i) != VOID) ) 
					warn("Function should return a value");
				return_count = 0;
      
      	if ((yyvsp[-8].i)==1) {
      		clear_symbols((yyvsp[-4].i) + 1);
      	}
        var_num = 0;
      }
#line 1530 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 244 "semantic.y" /* yacc.c:1646  */
    { set_atr1(fun_idx, 0); }
#line 1536 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 247 "semantic.y" /* yacc.c:1646  */
    {
        insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), 1, NO_ATR);
        set_atr1(fun_idx, 1);
        set_atr2(fun_idx, (yyvsp[-1].i));
    		if((yyvsp[-1].i) == VOID)
					err("parameter cannot be of VOID type");
      }
#line 1548 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 277 "semantic.y" /* yacc.c:1646  */
    {
		id_cls = lookup_symbol((yyvsp[0].s), CLS);
		if (id_cls == -1) 
			err("Class not found"); 
		(yyval.i) = id_cls;
	}
#line 1559 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 282 "semantic.y" /* yacc.c:1646  */
    {
		int id_index = lookup_symbol((yyvsp[0].s), VAR);
		if (id_index!=-1) {
			if (func_count==get_atr2(id_index)) {
				err("Redefinition of variable"); 
			}
		}
	}
#line 1572 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 289 "semantic.y" /* yacc.c:1646  */
    {
		if (lookup_symbol((yyvsp[0].s), CLS)!=lookup_symbol((yyvsp[-6].s), CLS))
			err("Class not the same"); 
		insert_symbol((yyvsp[-4].s), VAR, (yyvsp[-5].i), ++var_num, func_count);
	}
#line 1582 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 302 "semantic.y" /* yacc.c:1646  */
    {
		if(lookup_symbol_last((yyvsp[0].s), VAR|PAR, func_count)==NO_INDEX) {
			if(lookup_symbol_last((yyvsp[0].s), CLS_ATR, class_count)==NO_INDEX) {
				err("value for inc is not declared in this scope: '%s'", (yyvsp[0].s));
			}
		}
	}
#line 1594 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 309 "semantic.y" /* yacc.c:1646  */
    {
		if(lookup_symbol_last((yyvsp[0].s), VAR|PAR, func_count)==NO_INDEX) {
			if(lookup_symbol_last((yyvsp[0].s), CLS_ATR, class_count)==NO_INDEX) {
				err("value for inc is not declared in this scope: '%s'", (yyvsp[0].s));
			}
		}
	}
#line 1606 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 320 "semantic.y" /* yacc.c:1646  */
    {
		if (lookup_symbol((yyvsp[0].s), FUN)!=NO_INDEX) {
			err("Postincrement may be only used on variables, not functions.");
		}
		if(lookup_symbol_last((yyvsp[0].s), VAR|PAR, func_count)==NO_INDEX) {
			if(lookup_symbol_last((yyvsp[0].s), CLS_ATR, class_count)==NO_INDEX) {
				err("value for inc is not declared in this scope: '%s'", (yyvsp[0].s));
			}
		}
	}
#line 1621 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 335 "semantic.y" /* yacc.c:1646  */
    {
        int idx = lookup_symbol((yyvsp[-3].s), VAR|PAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", (yyvsp[-3].s));
        else
          if(get_type(idx) != get_type((yyvsp[-1].i)))
            err("incompatible types in assignment");
      }
#line 1634 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 358 "semantic.y" /* yacc.c:1646  */
    {
        (yyval.i) = ++lab_num;
      }
#line 1642 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 363 "semantic.y" /* yacc.c:1646  */
    {
        (yyval.i) = (yyvsp[-3].i);
      }
#line 1650 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 369 "semantic.y" /* yacc.c:1646  */
    {
		int fun_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol((yyvsp[0].s), VAR, (yyvsp[-1].i), ++var_num, NO_ATR);
        else 
          err("redefinition of '%s'", (yyvsp[0].s));
	}
#line 1662 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 377 "semantic.y" /* yacc.c:1646  */
    {
		func_count++; 
		(yyval.i) = get_last_element(); 
	}
#line 1671 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 382 "semantic.y" /* yacc.c:1646  */
    {
		printf("$<i>15 %d", (yyvsp[-2].i));
	 	clear_symbols((yyvsp[-2].i)+1);
	}
#line 1680 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 390 "semantic.y" /* yacc.c:1646  */
    {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: relational operator");
      }
#line 1689 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 399 "semantic.y" /* yacc.c:1646  */
    {
        (yyval.i) = lookup_symbol((yyvsp[0].s), VAR|PAR);
        if((yyval.i) == NO_INDEX)
          err("'%s' undeclared", (yyvsp[0].s));
      }
#line 1699 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 406 "semantic.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 1705 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 411 "semantic.y" /* yacc.c:1646  */
    { (yyval.i) = insert_literal((yyvsp[0].s), INT); }
#line 1711 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 414 "semantic.y" /* yacc.c:1646  */
    { (yyval.i) = insert_literal((yyvsp[0].s), UINT); }
#line 1717 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 419 "semantic.y" /* yacc.c:1646  */
    {
        fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", (yyvsp[0].s));
      }
#line 1727 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 425 "semantic.y" /* yacc.c:1646  */
    {
        if(get_atr1(fcall_idx) != (yyvsp[-1].i))
          err("wrong number of args to function '%s'", 
              get_name(fcall_idx));
        set_type(FUN_REG, get_type(fcall_idx));
        (yyval.i) = FUN_REG;
      }
#line 1739 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 436 "semantic.y" /* yacc.c:1646  */
    { (yyval.i) = 0; }
#line 1745 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 439 "semantic.y" /* yacc.c:1646  */
    { 
      if(get_atr2(fcall_idx) != get_type((yyvsp[0].i)))
        err("incompatible type for argument in '%s'",
            get_name(fcall_idx));
      (yyval.i) = 1;
    }
#line 1756 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 450 "semantic.y" /* yacc.c:1646  */
    {
        if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i)))
          err("invalid operands: arithmetic operation");
      }
#line 1765 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 463 "semantic.y" /* yacc.c:1646  */
    { list_vars_type = (yyvsp[0].i); }
#line 1771 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 464 "semantic.y" /* yacc.c:1646  */
    {				
      if((yyvsp[-3].i) == VOID)
				err("variable cannot be of VOID type");
      }
#line 1780 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 471 "semantic.y" /* yacc.c:1646  */
    { list_vars_type = (yyvsp[0].i); }
#line 1786 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 472 "semantic.y" /* yacc.c:1646  */
    {
    if((yyvsp[-3].i) == VOID)
			err("variable cannot be of VOID type");
	}
#line 1795 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 479 "semantic.y" /* yacc.c:1646  */
    {
		int idx = lookup_symbol((yyvsp[0].s), CLS_ATR);
		if(idx != -1)
			if (get_atr2(idx)!=class_count) {
			  insert_symbol((yyvsp[0].s), CLS_ATR, list_vars_type, ++var_num, class_count);
			}
			else	{
		  	err("redefinition of '%s'", (yyvsp[0].s));
			}
		else
		  insert_symbol((yyvsp[0].s), CLS_ATR, list_vars_type, ++var_num, class_count);
  }
#line 1812 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 492 "semantic.y" /* yacc.c:1646  */
    {
		int idx = lookup_symbol((yyvsp[0].s), CLS_ATR);
		if(idx != -1)
			if (get_atr2(idx)!=class_count) {
			  insert_symbol((yyvsp[0].s), CLS_ATR, list_vars_type, ++var_num, class_count);
			}
			else	{
		  	err("redefinition of '%s'", (yyvsp[0].s));
			}
		else
		  insert_symbol((yyvsp[0].s), CLS_ATR, list_vars_type, ++var_num, class_count);
  }
#line 1829 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 507 "semantic.y" /* yacc.c:1646  */
    {
	int idx = lookup_symbol((yyvsp[0].s), VAR|PAR);
  if(idx != -1 && get_atr2(idx)==func_count)
    err("redefinition of '%s'", (yyvsp[0].s));
  else
    insert_symbol((yyvsp[0].s), VAR, list_vars_type, ++var_num, func_count);
  }
#line 1841 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 515 "semantic.y" /* yacc.c:1646  */
    {
    if(lookup_symbol((yyvsp[0].s), VAR|PAR) != -1)
      err("redefinition of '%s'", (yyvsp[0].s));
    else
      insert_symbol((yyvsp[0].s), VAR, list_vars_type, ++var_num, func_count);
  }
#line 1852 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 525 "semantic.y" /* yacc.c:1646  */
    {
		if(get_type(fun_idx) == VOID) 
			err("Function cannot return value");
		else if(get_type(fun_idx) != get_type((yyvsp[-1].i)))
			err("incompatible types in return");
		return_count++; 
	}
#line 1864 "semantic.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 533 "semantic.y" /* yacc.c:1646  */
    {
		if(get_type(fun_idx) != VOID) 
		warn("Function should return a value");
		return_count++; 
	}
#line 1874 "semantic.tab.c" /* yacc.c:1646  */
    break;


#line 1878 "semantic.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 540 "semantic.y" /* yacc.c:1906  */


int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();

  synerr = yyparse();

  clear_symtab();
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count)
    printf("\n%d error(s).\n", error_count);

  if(synerr)
    return -1; //syntax error
  else
    return error_count; //semantic errors
}

