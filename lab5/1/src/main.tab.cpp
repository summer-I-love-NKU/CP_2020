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
#line 1 "src/main.y" /* yacc.c:339  */

//定义段
//规则段
//辅助函数段
#include "common.h"//包含tree的头文件
#define YYstmt_type TreeNode *  
TreeNode* root;//需要extern吗？？？
extern int lineno;
int yylex();
int yyerror( char const * );
//-----------符号表版本2 使用类！！！
SymTable *cur_tb;
int scopeid=0,n_top=1;
// //-------符号表 版本1 直接使用stack和map-----
// stack<map<string,pair<string,int> > > ST_stack;
// stack<int> NUM_stack;

string ValType_name[10] = {"bool", "int", "char", "string","void","const int","const char","8"};


// //-------------

#line 89 "src/main.tab.cpp" /* yacc.c:339  */

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
   by #include "main.tab.h".  */
#ifndef YY_YY_SRC_MAIN_TAB_H_INCLUDED
# define YY_YY_SRC_MAIN_TAB_H_INCLUDED
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
    T_INT = 258,
    T_CHAR = 259,
    T_BOOL = 260,
    T_VOID = 261,
    CONST = 262,
    ASSIGN = 263,
    ADD_ASSIGN = 264,
    SUB_ASSIGN = 265,
    MUL_ASSIGN = 266,
    DIV_ASSIGN = 267,
    EQ = 268,
    NOT_EQ = 269,
    LESS_THAN = 270,
    LESS_EQ = 271,
    MORE_THAN = 272,
    MORE_EQ = 273,
    AND = 274,
    OR = 275,
    NOT = 276,
    ADD = 277,
    SUB = 278,
    MUL = 279,
    DIV = 280,
    MOD = 281,
    SELF_ADD = 282,
    SELF_SUB = 283,
    SEMICOLON = 284,
    COMMA = 285,
    DOT = 286,
    LPAREN = 287,
    RPAREN = 288,
    LBRACE = 289,
    RBRACE = 290,
    LMPAREN = 291,
    RMPAREN = 292,
    IDENTIFIER = 293,
    INTEGER_H = 294,
    INTEGER_DP = 295,
    INTEGER_DN = 296,
    INTEGER_O = 297,
    INTEGER_B = 298,
    CHAR = 299,
    BOOL = 300,
    STRING = 301,
    MAIN = 302,
    RETURN = 303,
    FOR = 304,
    WHILE = 305,
    IF = 306,
    ELSE = 307,
    ELSE_IF = 308,
    PRINTF = 309,
    SCANF = 310,
    b_OR = 311,
    b_NOR = 312,
    b_AND = 313,
    UMINUS = 314,
    b_NOT = 315,
    pre_SELF_ADD = 316,
    pre_SELF_SUB = 317,
    GET_ADDRESS = 318,
    POINTER = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MAIN_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 205 "src/main.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   117,   128,   132,   140,   141,   142,   143,
     144,   145,   184,   204,   207,   211,   214,   217,   220,   225,
     232,   239,   245,   252,   259,   267,   274,   281,   287,   294,
     301,   308,   315,   322,   333,   364,   384,   412,   429,   448,
     466,   491,   513,   537,   539,   548,   557,   566,   575,   580,
     590,   604,   610,   618,   622,   628,   632,   638,   646,   654,
     660,   675,   675,   675,   677,   677,   679,   679,   682,   683,
     684,   685,   686,   687,   692,   693,   694,   695,   698,   698,
     700,   705,   711,   714,   719,   725,   726,   727,   732
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT", "T_CHAR", "T_BOOL", "T_VOID",
  "CONST", "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "EQ", "NOT_EQ", "LESS_THAN", "LESS_EQ", "MORE_THAN",
  "MORE_EQ", "AND", "OR", "NOT", "ADD", "SUB", "MUL", "DIV", "MOD",
  "SELF_ADD", "SELF_SUB", "SEMICOLON", "COMMA", "DOT", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "LMPAREN", "RMPAREN", "IDENTIFIER", "INTEGER_H",
  "INTEGER_DP", "INTEGER_DN", "INTEGER_O", "INTEGER_B", "CHAR", "BOOL",
  "STRING", "MAIN", "RETURN", "FOR", "WHILE", "IF", "ELSE", "ELSE_IF",
  "PRINTF", "SCANF", "b_OR", "b_NOR", "b_AND", "UMINUS", "b_NOT",
  "pre_SELF_ADD", "pre_SELF_SUB", "GET_ADDRESS", "POINTER", "$accept",
  "program", "fake_1", "statements", "statement", "fake_2", "expr",
  "decl_stmt", "assign_stmt", "base_assign_stmt", "IO_stmt", "O_expr",
  "I_expr", "if_else_while_for_stmt", "for_expr_1", "for_expr_2",
  "for_expr_3", "Type", "INT_CONST", "INTEGER_D", "ARRAY",
  "arr_assign_expr", "arr_element", "arr_ele", "ID", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319
};
# endif

#define YYPACT_NINF -131

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-131)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     115,  -131,  -131,  -131,  -131,     6,     5,   -40,  -131,  -131,
    -131,   -21,   -14,   -13,  -131,   265,    85,    85,  -131,    85,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
       3,    25,    26,    32,    43,   159,  -131,   371,    55,     1,
    -131,    57,  -131,   -20,  -131,  -131,   125,  -131,  -131,  -131,
     308,   265,    10,    85,    85,    37,    58,  -131,  -131,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,  -131,  -131,  -131,    23,  -131,  -131,    23,    64,
      23,    -2,    97,    85,    85,    85,    85,    85,  -131,   212,
      77,  -131,   109,   329,   350,   111,   112,   258,   258,   135,
     135,   135,   135,   214,    54,    15,    15,  -131,  -131,  -131,
     137,   138,   103,   140,   116,   113,    85,   387,   387,   387,
     387,   387,  -131,    85,   265,   265,    85,    91,    85,    94,
     130,    23,   -17,  -131,   131,   387,   387,   142,  -131,   117,
     387,    13,    85,    29,   387,    85,  -131,  -131,  -131,  -131,
    -131,   -27,  -131,  -131,    85,   265,    85,  -131,   387,   114,
    -131,   387,   -17,  -131,  -131,   141,  -131,   387,    85,  -131,
     265,   387,  -131
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    68,    69,    70,    71,     0,     0,     0,    72,    73,
       1,     0,     0,     0,     3,     0,     0,     0,     6,     0,
      12,    88,    74,    78,    79,    76,    77,    15,    17,    16,
       0,     0,     0,     0,     0,     0,     4,     0,     0,     0,
      43,     0,    10,     0,    14,    75,    13,    27,    13,    24,
       0,     0,    63,     0,     0,     0,     0,     2,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    49,     7,     0,     8,     9,     0,    88,
       0,    42,    35,     0,     0,     0,     0,     0,    18,     0,
      61,    62,     0,     0,     0,     0,     0,    33,    32,    29,
      28,    31,    30,    25,    26,    19,    20,    21,    22,    23,
      37,    39,     0,     0,     0,     0,     0,    50,    44,    45,
      46,    47,    11,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,    34,    64,     0,    59,    57,
      53,     0,     0,     0,    36,     0,    80,    40,    86,    87,
      85,     0,    83,    81,    67,     0,     0,    51,    55,     0,
      52,    38,     0,    82,    66,     0,    58,    54,     0,    84,
       0,    56,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,   124,   -23,  -131,    28,   126,   -51,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,   176,  -130,  -131,
    -131,  -131,  -131,    17,   -15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    15,    35,    36,    51,    37,    38,    39,    40,
      41,   141,   143,    42,    92,   137,   165,    43,    44,    45,
      81,   133,   151,   152,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    91,   150,   162,    78,    10,   114,    11,   163,     8,
       9,    12,    58,     1,     2,     3,     4,     5,    79,    13,
      46,    14,    22,    23,    24,    25,    26,   148,    82,   149,
      76,    16,   150,    17,   115,    52,    46,    46,    80,    69,
      70,    71,    19,   156,    47,    49,   157,    50,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    53,    54,   159,
     110,    21,   160,   111,    55,   113,    58,    59,    60,    61,
      62,    63,    64,    65,    46,    56,    67,    68,    69,    70,
      71,    93,    94,    95,    74,    75,    77,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     112,   138,   139,   164,    96,   116,    16,    75,    17,    46,
      46,   117,   118,   119,   120,   121,   147,    19,     1,     2,
       3,     4,     5,    21,    22,    23,    24,    25,    26,    27,
      28,    29,   166,    83,    84,    85,    86,    87,   123,    46,
      46,   126,   127,   130,   135,   128,   129,   172,   131,   142,
     132,   136,   145,   134,   140,    46,   144,    67,    68,    69,
      70,    71,     1,     2,     3,     4,     5,   146,   153,   155,
     158,   154,   168,   161,   170,    89,     7,     0,    90,   169,
      16,     0,    17,     0,   167,     0,     0,     0,    18,     0,
       0,    19,     0,    20,    57,     0,   171,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     0,     0,    30,    31,
      32,     0,     0,    33,    34,     1,     2,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,    64,    16,     0,    17,    67,    68,    69,    70,
      71,    18,     0,     0,    19,     0,    20,   122,     0,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
       0,    30,    31,    32,     0,     0,    33,    34,     1,     2,
       3,     4,     5,    61,    62,    63,    64,     0,     0,     0,
      67,    68,    69,    70,    71,     0,    16,     0,    17,     0,
       0,     0,     0,     0,    18,     0,     0,    19,     0,    20,
       0,     0,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     0,     0,    30,    31,    32,     0,     0,    33,
      34,    59,    60,    61,    62,    63,    64,    65,    66,     0,
      67,    68,    69,    70,    71,     0,     0,     0,     0,     0,
       0,    88,    59,    60,    61,    62,    63,    64,    65,    66,
       0,    67,    68,    69,    70,    71,     0,     0,     0,     0,
       0,     0,   124,    59,    60,    61,    62,    63,    64,    65,
      66,     0,    67,    68,    69,    70,    71,     0,     0,     0,
       0,     0,     0,   125,    59,    60,    61,    62,    63,    64,
      65,    66,     0,    67,    68,    69,    70,    71,    72,    73,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,    70,    71
};

static const yytype_int16 yycheck[] =
{
      15,    52,   132,    30,    24,     0,     8,    47,    35,     3,
       4,    32,    35,     3,     4,     5,     6,     7,    38,    33,
      35,    34,    39,    40,    41,    42,    43,    44,    43,    46,
      29,    21,   162,    23,    36,    32,    51,    52,    58,    24,
      25,    26,    32,    30,    16,    17,    33,    19,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    32,    32,    30,
      75,    38,    33,    78,    32,    80,    89,    13,    14,    15,
      16,    17,    18,    19,    89,    32,    22,    23,    24,    25,
      26,    53,    54,    46,    29,    30,    29,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      36,   124,   125,   154,    46,     8,    21,    30,    23,   124,
     125,    83,    84,    85,    86,    87,   131,    32,     3,     4,
       5,     6,     7,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   155,     8,     9,    10,    11,    12,    29,   154,
     155,    30,    30,    40,   116,     8,     8,   170,     8,    58,
      34,   123,    58,    40,   126,   170,   128,    22,    23,    24,
      25,    26,     3,     4,     5,     6,     7,    37,    37,    52,
     142,    29,    58,   145,    33,    51,     0,    -1,    52,   162,
      21,    -1,    23,    -1,   156,    -1,    -1,    -1,    29,    -1,
      -1,    32,    -1,    34,    35,    -1,   168,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    49,    50,
      51,    -1,    -1,    54,    55,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    21,    -1,    23,    22,    23,    24,    25,
      26,    29,    -1,    -1,    32,    -1,    34,    35,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    49,    50,    51,    -1,    -1,    54,    55,     3,     4,
       5,     6,     7,    15,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    -1,    21,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    32,    -1,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    49,    50,    51,    -1,    -1,    54,
      55,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    66,    82,     3,     4,
       0,    47,    32,    33,    34,    67,    21,    23,    29,    32,
      34,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      49,    50,    51,    54,    55,    68,    69,    71,    72,    73,
      74,    75,    78,    82,    83,    84,    89,    71,    89,    71,
      71,    70,    32,    32,    32,    32,    32,    35,    69,    13,
      14,    15,    16,    17,    18,    19,    20,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    29,    29,    24,    38,
      58,    85,    89,     8,     9,    10,    11,    12,    33,    68,
      72,    73,    79,    71,    71,    46,    46,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      89,    89,    36,    89,     8,    36,     8,    71,    71,    71,
      71,    71,    35,    29,    33,    33,    30,    30,     8,     8,
      40,     8,    34,    86,    40,    71,    71,    80,    69,    69,
      71,    76,    58,    77,    71,    58,    37,    89,    44,    46,
      83,    87,    88,    37,    29,    52,    30,    33,    71,    30,
      33,    71,    30,    35,    73,    81,    69,    71,    58,    88,
      33,    71,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    68,    68,    69,    69,    69,    69,
      69,    69,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      74,    75,    75,    76,    76,    77,    77,    78,    78,    78,
      78,    79,    79,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    82,    82,    83,    83,    83,    83,    84,    84,
      85,    85,    86,    87,    87,    88,    88,    88,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     0,     1,     2,     1,     2,     2,     2,
       1,     4,     0,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     4,     2,     5,     3,     6,     3,
       5,     4,     2,     1,     3,     3,     3,     3,     2,     2,
       3,     6,     6,     1,     3,     2,     4,     5,     7,     5,
       9,     1,     1,     0,     1,     0,     1,     0,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       4,     4,     3,     1,     3,     1,     1,     1,     1
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
        case 2:
#line 103 "src/main.y" /* yacc.c:1646  */
    {
        root = new TreeNode((yyvsp[-7])->lineno, NODE_PROG); root->addChild((yyvsp[-1]));
        //-------------------
                    // // cout<<"------主函数符号表！！！------\n";
                    cout<<"-------level: "<<cur_tb->scope<<"-------"<<endl;
                    for(map<string,pair<string,int> >::iterator iter = cur_tb->tmap.begin(); iter != cur_tb->tmap.end(); iter++)
                    {
                        cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
                    }cout<<endl;
                    //cout<<"------------\n";
                    // //cout<<"}"<<endl;
        //------------------
        }
#line 1468 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 117 "src/main.y" /* yacc.c:1646  */
    {
            //-----------符号表 版本2----
                    // //cout<<"{"<<endl;
                    // map<string,pair<string,int> > tmp;int numtmp=1;
                    // ST_stack.push(tmp);NUM_stack.push(numtmp);
                    // cur_tb->tmap=ST_stack.top();n_top=NUM_stack.top();
            cur_tb=new SymTable(++scopeid);
            //-------------------
        }
#line 1482 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 128 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_STMT);
        (yyval)=(yyvsp[0]);
    }
#line 1491 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 133 "src/main.y" /* yacc.c:1646  */
    {   
        (yyval)=(yyvsp[-1]);
        (yyval)->addSibling((yyvsp[0]));
    }
#line 1500 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 140 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stmt_type = STMT_SKIP;}
#line 1506 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 141 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1512 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 142 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1518 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 143 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1524 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1530 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 145 "src/main.y" /* yacc.c:1646  */
    {
        //语句加一个总的根结点，解决问题
        (yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
        (yyval)->stmt_type=STMT_BLOCK;
        (yyval)->addChild((yyvsp[-1]));
        //-----------------符号表 版本2--------------------
                        // // cout<<"------------\n";
                    cout<<"-------level: "<<cur_tb->scope<<"-------"<<endl;
                    for(SymTable* t=cur_tb;t!=nullptr;t=t->father)
                    {
                        cout<<"level"<<t->scope<<":"<<endl;
                        for(map<string,pair<string,int> >::iterator iter = t->tmap.begin(); iter != t->tmap.end(); iter++)
                        {
                            cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
                        }
                    }
                       
                    cout<<endl;
                        //cout<<"------------\n";
                        
                        // if(ST_stack.size()>1)
                        // {
                        //     ST_stack.pop();cur_tb->tmap=ST_stack.top();
                        //     // cout<<"弹栈后！！！"<<endl;cout<<"stack size"<<ST_stack.size()<<endl<<"stack empty:"<<ST_stack.empty()
                        //     // <<endl<<"map empty:"<<cur_tb->tmap.empty()<<endl;
                        //         // for(map<string,pair<string,int> >::iterator iter = cur_tb->tmap.begin(); iter != cur_tb->tmap.end(); iter++)
                        //         // {
                        //         //     cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
                        //         // }
                        // }
                        // if(NUM_stack.size()>1)
                        // {
                        //     NUM_stack.pop();
                        //     n_top=NUM_stack.top();
                        // }
        cur_tb=cur_tb->father;
        //-------------------------
        }
#line 1573 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 184 "src/main.y" /* yacc.c:1646  */
    {
            //-------------符号表 版本2------------
                    // //===================更新!!!
                    // ST_stack.pop();ST_stack.push(cur_tb->tmap);

                    // //===============再压栈下一级作用域符号表
                    // map<string,pair<string,int> > tmp;int numtmp=1;
                    // ST_stack.push(tmp);NUM_stack.push(numtmp);
                    // cur_tb->tmap=ST_stack.top();n_top=NUM_stack.top();
            SymTable* t=new SymTable(++scopeid);
            t->father=cur_tb;
            cur_tb=t;
            n_top=1;
            //----------------------------
        }
#line 1593 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 204 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
    }
#line 1601 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 207 "src/main.y" /* yacc.c:1646  */
    {
        //注意这部分的int char bool类型常量在词法分析的.l文件就已经定义初始化树结点了！！！
        (yyval) = (yyvsp[0]);
    }
#line 1610 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 211 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
    }
#line 1618 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 214 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
    }
#line 1626 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 217 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
    }
#line 1634 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 220 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[-1]);
        (yyval)->val_type_flag=(yyvsp[-1])->val_type_flag;//??----------
        }
#line 1643 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 225 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_ADD;
        // $$->int_val=$1->int_val+$3->int_val;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag=(yyvsp[-2])->val_type_flag;//??----------
        }
#line 1655 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 232 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_SUB;
        // $$->int_val=$1->int_val-$3->int_val;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag=(yyvsp[-2])->val_type_flag;//??----------
        }
#line 1667 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 239 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_MUL;
        // $$->int_val=$1->int_val*$3->int_val;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        }
#line 1678 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 245 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_DIV;
        // $$->int_val=$1->int_val/$3->int_val;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag=(yyvsp[-2])->val_type_flag;//??----------
        }
#line 1690 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 252 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_MOD;
        // $$->int_val=$1->int_val%$3->int_val;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag=(yyvsp[-2])->val_type_flag;//??----------
        }
#line 1702 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 259 "src/main.y" /* yacc.c:1646  */
    {
        // $2就是expr
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_NEG;
        // $$->int_val=-$2->int_val;
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag=(yyvsp[-1])->val_type_flag;//??----------
    }
#line 1714 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 267 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_AND;
        // $$->int_val=$1->int_val&&$3->int_val;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------
    }
#line 1726 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 274 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_OR;
        // $$->int_val=$1->int_val||$3->int_val;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------
    }
#line 1738 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 281 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_NOT;
        // $$->int_val=!$2->int_val;
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------
    }
#line 1749 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 287 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_LESS_EQ;
        // $$->int_val=($1->int_val<=$3->int_val);
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------
    }
#line 1761 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 294 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_LESS_THAN;
        // $$->int_val=($1->int_val<$3->int_val);
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------
    }
#line 1773 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 301 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_MORE_EQ;
        // $$->int_val=($1->int_val>=$3->int_val);
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------
    }
#line 1785 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 308 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_MORE_THAN;
        // $$->int_val=($1->int_val>$3->int_val);
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------
    }
#line 1797 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 315 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_NOT_EQ;
        // $$->int_val=($1->int_val!=$3->int_val);
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------
    }
#line 1809 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 322 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_EQ;
        // $$->int_val=($1->int_val==$3->int_val);
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------
    }
#line 1821 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 333 "src/main.y" /* yacc.c:1646  */
    {  
        // declare and init
        (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL_V;
        (yyval)->addChild((yyvsp[-3]));
        (yyvsp[-3])->addChild((yyvsp[-2]));
        //-------类型转换？？？char m=97;-->'a' -----
            if(ValType_name[(yyvsp[-3])->type->type]=="char"&&(yyvsp[0])->val_type_flag=='i')
            {
                (yyvsp[0])->ch_val=char((yyvsp[0])->int_val);
                (yyvsp[0])->val_type_flag='c';
            }
            if(ValType_name[(yyvsp[-3])->type->type]=="bool"&&(yyvsp[0])->val_type_flag!='b')
            {
                (yyvsp[0])->b_val=bool((yyvsp[0])->int_val)||bool((yyvsp[0])->ch_val);
                (yyvsp[0])->val_type_flag='b';
            }
        //-----------
        (yyvsp[-2])->addChild((yyvsp[0])); 
        //----------------
        if(cur_tb->tmap.count((yyvsp[-2])->var_name)==0)
        {
            cur_tb->tmap[(yyvsp[-2])->var_name]=make_pair(ValType_name[(yyvsp[-3])->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redefine error!!!"<<endl;
        }
        //-------------
    }
#line 1857 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 364 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL_V;
        (yyval)->addChild((yyvsp[-1]));
        (yyvsp[-1])->addChild((yyvsp[0]));
        //--------------------------
        if(cur_tb->tmap.count((yyvsp[0])->var_name)==0)
        {
            cur_tb->tmap[(yyvsp[0])->var_name]=make_pair(ValType_name[(yyvsp[-1])->type->type],n_top);
            // cout<<"!!!!"<<$2->var_name<<"  "<< ValType_name[$1->type->type]<<" "<<n_top<<endl;
            // cout<<"当前map中元素个数："<<cur_tb->tmap.size()<<endl;
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;

        }
        //-----------------------
    }
#line 1882 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 384 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[-4]);
        (yyval)->child->addChild((yyvsp[-2]));
        (yyvsp[-2])->addChild((yyvsp[0]));
        //-------类型转换？？？char m=97;-->'a' -----
            if(ValType_name[(yyval)->child->type->type]=="char"&&(yyvsp[0])->val_type_flag=='i')
            {
                (yyvsp[0])->ch_val=char((yyvsp[0])->int_val);
                (yyvsp[0])->val_type_flag='c';
            }
            if(ValType_name[(yyval)->child->type->type]=="bool"&&(yyvsp[0])->val_type_flag!='b')
            {
                (yyvsp[0])->b_val=bool((yyvsp[0])->int_val)||bool((yyvsp[0])->ch_val);//无法转换字符串，看看规则？？？？
                (yyvsp[0])->val_type_flag='b';
            }
        //-------------------------
        //--------------------------
        if(cur_tb->tmap.count((yyvsp[-2])->var_name)==0)
        {
            cur_tb->tmap[(yyvsp[-2])->var_name]=make_pair(ValType_name[(yyvsp[-4])->child->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redefine error!!!"<<endl;
        }
        //-----------------------
    }
#line 1915 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 412 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[-2]);
        (yyval)->child->addChild((yyvsp[0]));
        //--------------------------
        if(cur_tb->tmap.count((yyvsp[0])->var_name)==0)
        {
            cur_tb->tmap[(yyvsp[0])->var_name]=make_pair(ValType_name[(yyvsp[-2])->child->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;
        }
        //-----------------------
    }
#line 1935 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 429 "src/main.y" /* yacc.c:1646  */
    {  
        // declare and init
        (yyval) = new TreeNode((yyvsp[-5])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL_P;
        (yyval)->addChild((yyvsp[-5]));
        (yyvsp[-5])->addChild((yyvsp[-3]));
        (yyvsp[-3])->addChild((yyvsp[0])); 
        //----------------
        if(cur_tb->tmap.count((yyvsp[-3])->var_name)==0)
        {
            cur_tb->tmap[(yyvsp[-3])->var_name]=make_pair(ValType_name[(yyvsp[-5])->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redefine error!!!"<<endl;
        }
        //-------------
    }
#line 1959 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 448 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL_P;
        (yyval)->addChild((yyvsp[-2]));
        (yyvsp[-2])->addChild((yyvsp[0]));
        //--------------------------
        if(cur_tb->tmap.count((yyvsp[0])->var_name)==0)
        {
            cur_tb->tmap[(yyvsp[0])->var_name]=make_pair(ValType_name[(yyvsp[-2])->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;

        }
        //-----------------------
    }
#line 1982 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 466 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-4])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL_R;
        (yyval)->addChild((yyvsp[-4]));
        (yyvsp[-4])->addChild((yyvsp[-2]));
        (yyvsp[-4])->addChild((yyvsp[0]));
        //--------------------------
        if(cur_tb->tmap.count((yyvsp[-2])->var_name)==0)
        {
            cur_tb->tmap[(yyvsp[-2])->var_name]=make_pair(ValType_name[(yyvsp[-4])->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;

        }
        if(cur_tb->tmap.count((yyvsp[0])->var_name)==0)
        {
            cout<<"引用的变量未定义！！！"<<endl;
        }
        //-----------------------
    }
#line 2010 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 491 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL_A;
        (yyval)->addChild((yyvsp[-3]));
        (yyvsp[-3])->addChild((yyvsp[-2]));
        (yyvsp[-3])->addChild((yyvsp[0]));
        //--------------------------
        if(cur_tb->tmap.count((yyvsp[-2])->var_name)==0)
        {
            cur_tb->tmap[(yyvsp[-2])->var_name]=make_pair(ValType_name[(yyvsp[-3])->type->type],n_top);
            // cout<<"!!!!"<<$2->var_name<<"  "<< ValType_name[$1->type->type]<<" "<<n_top<<endl;
            // cout<<"当前map中元素个数："<<cur_tb->tmap.size()<<endl;
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;

        }
        //-----------------------

    }
#line 2037 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 513 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL_A;
        (yyval)->addChild((yyvsp[-1]));
        (yyvsp[-1])->addChild((yyvsp[0]));
        //--------------------------
        if(cur_tb->tmap.count((yyvsp[0])->var_name)==0)
        {
            cur_tb->tmap[(yyvsp[0])->var_name]=make_pair(ValType_name[(yyvsp[-1])->type->type],n_top);
            // cout<<"!!!!"<<$2->var_name<<"  "<< ValType_name[$1->type->type]<<" "<<n_top<<endl;
            // cout<<"当前map中元素个数："<<cur_tb->tmap.size()<<endl;
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;

        }
        //-----------------------

    }
#line 2063 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 537 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2069 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 539 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_ADD_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        
        // TreeNode* p=$$->child;
        // p->int_val+=p->sibling->int_val;
    }
#line 2083 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 548 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_SUB_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        
        // TreeNode* p=$$->child;
        // p->int_val-=p->sibling->sibling->int_val;
    }
#line 2097 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 557 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_MUL_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        
        // TreeNode* p=$$->child;
        // p->int_val*=p->sibling->sibling->int_val;
    }
#line 2111 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 566 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DIV_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        
        // TreeNode* p=$$->child;
        // p->int_val/=p->sibling->sibling->int_val;
    }
#line 2125 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 575 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stmt_type = STMT_SELF_ADD_ASSIGN;
        // $$->int_val=$1->int_val+1;
        (yyval)->addChild((yyvsp[-1]));
        }
#line 2135 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 580 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stmt_type = STMT_SELF_SUB_ASSIGN;
        // $$->int_val=$1->int_val-1;
        (yyval)->addChild((yyvsp[-1]));
        }
#line 2145 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 590 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));

        // //赋值操作，无论是什么类型，都赋过来就好了
        // $1->int_val=$3->int_val;
        // $1->ch_val=$3->ch_val;
        // $1->str_val=$3->str_val;
    }
#line 2161 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 604 "src/main.y" /* yacc.c:1646  */
    {
            (yyval) = new TreeNode(lineno, NODE_STMT);
            (yyval)->stmt_type=STMT_PRINTF;
            (yyval)->addChild((yyvsp[-3]));
            (yyval)->addChild((yyvsp[-1]));
        }
#line 2172 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 610 "src/main.y" /* yacc.c:1646  */
    {
            (yyval) = new TreeNode(lineno, NODE_STMT);
            (yyval)->stmt_type=STMT_SCANF;
            (yyval)->addChild((yyvsp[-3]));
            (yyval)->addChild((yyvsp[-1]));
        }
#line 2183 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 618 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_STMT);
        (yyval)->addChild((yyvsp[0]));
    }
#line 2192 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 622 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)->addChild((yyvsp[0]));

    }
#line 2201 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 628 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_STMT);
        (yyval)->addChild((yyvsp[0]));
    }
#line 2210 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 632 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)->addChild((yyvsp[0]));

    }
#line 2219 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 638 "src/main.y" /* yacc.c:1646  */
    {
        // cout<<"if !!"<<endl;
        //这里不能用$1,要么直接lineno 要么$3->lineno
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type=STMT_IF;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 2232 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 646 "src/main.y" /* yacc.c:1646  */
    {
        //这里不能用$1,要么直接lineno 要么$3->lineno
        (yyval) = new TreeNode((yyvsp[-4])->lineno, NODE_STMT);
        (yyval)->stmt_type=STMT_IF_ELSE;
        (yyval)->addChild((yyvsp[-4]));
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 2245 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 654 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type=STMT_WHILE;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 2256 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 661 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-6])->lineno, NODE_STMT);
        (yyval)->stmt_type=STMT_FOR;
        (yyval)->addChild((yyvsp[-6]));
        (yyval)->addChild((yyvsp[-4]));
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        }
#line 2269 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 675 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2275 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 675 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2281 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 675 "src/main.y" /* yacc.c:1646  */
    {(yyval)=new TreeNode(lineno,NODE_STMT);(yyval)->stmt_type=STMT_SKIP;}
#line 2287 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 677 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2293 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 677 "src/main.y" /* yacc.c:1646  */
    {(yyval)=new TreeNode(lineno,NODE_STMT);(yyval)->stmt_type=STMT_SKIP;}
#line 2299 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 679 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2305 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 679 "src/main.y" /* yacc.c:1646  */
    {(yyval)=new TreeNode(lineno,NODE_STMT);(yyval)->stmt_type=STMT_SKIP;}
#line 2311 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 682 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_INT;}
#line 2317 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 683 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CHAR;}
#line 2323 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 684 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_BOOL;}
#line 2329 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 685 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_VOID;}
#line 2335 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 686 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CONST_INT;}
#line 2341 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 687 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CONST_CHAR;}
#line 2347 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 692 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2353 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 693 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2359 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 694 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2365 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 695 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2371 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 698 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2377 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 698 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2383 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 700 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[-3]);
        (yyval)->nodeType=NODE_ARR;
        (yyval)->addChild((yyvsp[-1]));
    }
#line 2393 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 705 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[-3]);
        (yyval)->addChild((yyvsp[-1]));
    }
#line 2402 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 711 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2408 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 714 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[0])->lineno, NODE_STMT);//???
        (yyval)->addChild((yyvsp[0]));

    }
#line 2418 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 719 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)->addChild((yyvsp[0]));
    }
#line 2426 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 725 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2432 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 726 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2438 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 727 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2444 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 732 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2450 "src/main.tab.cpp" /* yacc.c:1646  */
    break;


#line 2454 "src/main.tab.cpp" /* yacc.c:1646  */
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
#line 737 "src/main.y" /* yacc.c:1906  */


int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
