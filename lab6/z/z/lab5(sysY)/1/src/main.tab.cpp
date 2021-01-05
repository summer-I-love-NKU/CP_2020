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
//数组的维度
int arr_d_num=0;
//-----------符号表版本2 使用类！！！
SymTable *cur_tb;
int scopeid=0,n_top=1;
// //-------符号表 版本1 直接使用stack和map-----
// stack<map<string,pair<string,int> > > ST_stack;
// stack<int> NUM_stack;

string ValType_name[10] = {"bool", "int", "char", "string","void","const int","const char","8"};


// //-------------

#line 91 "src/main.tab.cpp" /* yacc.c:339  */

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

#line 207 "src/main.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   140

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  117

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
       0,   106,   106,   111,   116,   118,   123,   124,   131,   137,
     145,   149,   161,   169,   176,   180,   187,   188,   193,   196,
     202,   203,   204,   205,   214,   215,   218,   224,   233,   234,
     239,   249,   252,   261,   267,   271,   275,   281,   288,   291,
     295,   302,   306,   313,   319,   326,   327,   328,   334,   335,
     336,   341,   342,   343,   344,   348,   348,   352,   353,   356,
     360,   368,   369,   374,   379,   386,   387,   392
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
  "CompUnit", "Decl", "Const_Decl", "Const_Def", "Var_Decl", "Var_Def",
  "Init_Val", "arr_element", "arr_ele", "ID", "ID_ARRAY_NAME", "BType",
  "Func_Def", "Func_Params", "Func_Param", "Block", "Block_Item",
  "base_Block_Item", "Stmt", "PrimaryExp", "LVal", "NUMBER", "Exp",
  "INT_CONST", "INTEGER_D", "UnaryExp", "MulExp", "AddExp", YY_NULLPTR
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

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -21

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     120,   -25,   -63,   -24,    62,   109,   -63,    24,    45,   -29,
     -63,   -21,   -15,   -13,     8,    -1,    31,   -63,   -29,   -63,
     -63,   -63,   -63,   -29,   -63,   -29,   -63,    41,    27,    37,
      62,    36,    51,    62,   -63,    90,   -63,   -63,    65,    73,
      80,   -29,    10,   -63,    88,    80,    12,    50,    79,    79,
      79,    79,    39,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,    33,    72,   -63,
      34,   -63,   -63,    62,    80,   -63,   -63,    80,   -63,   -63,
     -63,   -63,   -63,    97,   -63,   -63,   -63,   -19,   -63,    -5,
      79,    79,    79,    79,    79,   -63,   -63,    17,   -63,   -63,
     123,   -63,   -63,   -63,   -63,    39,   -63,   -63,   -63,   -63,
      33,    33,   -63,   -63,    79,   -63,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    29,     0,     0,     0,     2,     0,     0,     0,
       3,    24,     0,     0,    25,     0,     0,    28,     0,     1,
       4,     5,     6,     0,     7,     0,    12,    15,     0,     0,
      36,     0,     0,    36,     8,     0,     9,    13,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    55,    56,    53,    54,    14,    48,
      57,    46,    47,    16,    49,    52,    61,    65,    50,    26,
       0,    32,    37,     0,     0,    27,    33,     0,    11,    10,
      60,    58,    59,     0,    21,    22,    23,     0,    18,    49,
       0,     0,     0,     0,     0,    41,    44,     0,    39,    42,
       0,    35,    30,    31,    45,     0,    17,    62,    63,    64,
      66,    67,    38,    40,     0,    19,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,    28,   -63,   110,   -63,   107,    96,   -63,    30,
       9,   -63,    -4,   131,   104,    66,   -38,   -63,    43,   -63,
     -63,   -62,    91,   -50,   -49,   -63,   -44,    35,   -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,    95,     7,    34,     8,    26,    86,    87,    88,
      59,    14,     9,    10,    42,    43,    96,    97,    98,    99,
      60,    61,    62,    63,    64,    65,    66,    67,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      18,    83,    71,    89,    80,    81,    82,    76,   100,    11,
      13,   105,    16,    11,    11,    28,   106,    29,    27,    30,
      17,     2,    12,    15,     4,   -20,    41,    35,     6,    41,
     -20,    32,    35,    20,    27,   100,   102,    17,     2,   103,
      73,     4,    73,    74,    31,    77,   107,   108,   109,    38,
      72,    70,   112,    22,    23,    11,    89,    90,    91,    92,
      48,    49,    50,    33,   116,    17,     2,    39,    70,    41,
      40,    51,    11,    52,    24,    25,    44,    11,    53,    54,
      55,    56,    57,    84,    45,    85,    48,    49,    50,    53,
      54,    55,    56,    57,    93,    94,    78,    51,    47,    52,
      48,    49,    50,    11,    53,    54,    55,    56,    57,    19,
      69,    51,     1,     2,    70,     3,     4,    11,    53,    54,
      55,    56,    57,     1,     2,    75,     3,     4,   110,   111,
     104,   114,    37,    36,    58,   115,    21,    46,    79,   101,
     113
};

static const yytype_uint8 yycheck[] =
{
       4,    51,    40,    52,    48,    49,    50,    45,    70,    38,
       1,    30,     3,    38,    38,    36,    35,    32,     9,    32,
       3,     4,    47,    47,     7,    30,    30,    18,     0,    33,
      35,    32,    23,     5,    25,    97,    74,     3,     4,    77,
      30,     7,    30,    33,    36,    33,    90,    91,    92,     8,
      41,    34,    35,    29,    30,    38,   105,    24,    25,    26,
      21,    22,    23,    32,   114,     3,     4,    40,    34,    73,
      33,    32,    38,    34,    29,    30,    40,    38,    39,    40,
      41,    42,    43,    44,    33,    46,    21,    22,    23,    39,
      40,    41,    42,    43,    22,    23,    46,    32,     8,    34,
      21,    22,    23,    38,    39,    40,    41,    42,    43,     0,
      37,    32,     3,     4,    34,     6,     7,    38,    39,    40,
      41,    42,    43,     3,     4,    37,     6,     7,    93,    94,
      33,     8,    25,    23,    38,   105,     5,    33,    47,    73,
      97
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,     7,    66,    67,    68,    70,    77,
      78,    38,    47,    75,    76,    47,    75,     3,    77,     0,
      67,    78,    29,    30,    29,    30,    71,    75,    36,    32,
      32,    36,    32,    32,    69,    75,    69,    71,     8,    40,
      33,    77,    79,    80,    40,    33,    79,     8,    21,    22,
      23,    32,    34,    39,    40,    41,    42,    43,    72,    75,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    37,
      34,    81,    75,    30,    33,    37,    81,    33,    46,    87,
      91,    91,    91,    88,    44,    46,    72,    73,    74,    89,
      24,    25,    26,    22,    23,    67,    81,    82,    83,    84,
      86,    80,    81,    81,    33,    30,    35,    91,    91,    91,
      92,    92,    35,    83,     8,    74,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    78,    78,    79,    79,    79,    80,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    85,    86,    87,
      88,    89,    89,    89,    89,    90,    90,    91,    91,    91,
      91,    92,    92,    92,    92,    93,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     2,     3,     3,
       3,     3,     2,     3,     3,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     4,     4,     1,     1,
       6,     6,     5,     5,     1,     3,     0,     2,     3,     1,
       2,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     1,     3,     3,     3,     1,     3,     3
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
#line 106 "src/main.y" /* yacc.c:1646  */
    {
        root = new TreeNode((yyvsp[0])->lineno, NODE_PROG); 
        root->addChild((yyvsp[0]));
        root->printChildrenId();cout<<"Decl"<<endl;
        }
#line 1384 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 111 "src/main.y" /* yacc.c:1646  */
    {
        root = new TreeNode((yyvsp[0])->lineno, NODE_PROG); 
        root->addChild((yyvsp[0]));
        root->printChildrenId();cout<<"funcdef"<<endl;
        }
#line 1394 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 116 "src/main.y" /* yacc.c:1646  */
    {
        root->addChild((yyvsp[0]));}
#line 1401 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 118 "src/main.y" /* yacc.c:1646  */
    {
        root->addChild((yyvsp[0]));}
#line 1408 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 123 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1414 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 124 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[-1]);
        (yyval)->printChildrenId();
        }
#line 1423 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 131 "src/main.y" /* yacc.c:1646  */
    {
            (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
            (yyval)->stmt_type = STMT_DECL_C;
            (yyval)->addChild((yyvsp[-1]));//int
            (yyvsp[-1])->addChild((yyvsp[0]));//a=5
        }
#line 1434 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 137 "src/main.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-2]);//int
            (yyval)->child->addChild((yyvsp[0]));//a=5,b=6
        }
#line 1443 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 145 "src/main.y" /* yacc.c:1646  */
    {
                    (yyval) = (yyvsp[-2]);
                    (yyval)->addChild((yyvsp[0]));
                }
#line 1452 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 149 "src/main.y" /* yacc.c:1646  */
    {
                    (yyval) = (yyvsp[-2]);
                    (yyval)->addChild((yyvsp[0]));
                }
#line 1461 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 161 "src/main.y" /* yacc.c:1646  */
    {
            (yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
            (yyval)->stmt_type = STMT_DECL_V;
            (yyval)->addChild((yyvsp[-1]));//int
            (yyval)->child->addChild((yyvsp[0]));//a=5

            (yyval)->printChildrenId();
        }
#line 1474 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 169 "src/main.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-2]);//int
            (yyval)->child->addChild((yyvsp[0]));//a=5,b=6
        }
#line 1483 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 176 "src/main.y" /* yacc.c:1646  */
    {
                    (yyval) = (yyvsp[-2]);
                    (yyval)->addChild((yyvsp[0]));//a=1
                }
#line 1492 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 180 "src/main.y" /* yacc.c:1646  */
    {
                    (yyval)=(yyvsp[0]);
                    }
#line 1500 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 187 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1506 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 188 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-2]);}
#line 1512 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 193 "src/main.y" /* yacc.c:1646  */
    {
                            (yyval) = new TreeNode((yyvsp[0])->lineno, NODE_CONST);//???
                            (yyval)->addChild((yyvsp[0]));}
#line 1520 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 196 "src/main.y" /* yacc.c:1646  */
    {
                            (yyval)=(yyvsp[-2]);
                            (yyval)->addChild((yyvsp[0]));}
#line 1528 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 202 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1534 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 203 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1540 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 204 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1546 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 205 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1552 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 214 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);/*已经在.l定义了*/}
#line 1558 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 215 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1564 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 218 "src/main.y" /* yacc.c:1646  */
    {
                    (yyval)->nodeType=NODE_ARR;
                    (yyval)->var_name=(yyvsp[-3])->var_name;
                    arr_d_num=0;//注意重新计数！！！
                    (yyval)->arr_d[arr_d_num++]=(yyvsp[-1])->int_val;
                    }
#line 1575 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 224 "src/main.y" /* yacc.c:1646  */
    {
                    (yyval)->nodeType=NODE_ARR;
                    (yyval)->var_name=(yyvsp[-3])->var_name;
                    (yyval)->arr_d[arr_d_num++]=(yyvsp[-1])->int_val;
                    }
#line 1585 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 233 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_INT;}
#line 1591 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 234 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CHAR;}
#line 1597 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 239 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)=new TreeNode((yyvsp[-5])->lineno,NODE_FUNC);
        (yyval)->func_type=TYPE_INT;
        (yyval)->func_name=(yyvsp[-4])->var_name;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));

        cout<<"hanshu!!!"<<endl;
        (yyval)->printChildrenId();
    }
#line 1612 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 249 "src/main.y" /* yacc.c:1646  */
    {
        
    }
#line 1620 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 252 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)=new TreeNode((yyvsp[-4])->lineno,NODE_FUNC);
        (yyval)->func_type=TYPE_INT;
        (yyval)->func_name="main";
        (yyval)->addChild((yyvsp[0]));

        cout<<"hanshu!!!"<<endl;
        (yyval)->printChildrenId();
    }
#line 1634 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 261 "src/main.y" /* yacc.c:1646  */
    {

        }
#line 1642 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 267 "src/main.y" /* yacc.c:1646  */
    {
                (yyval)=new TreeNode((yyvsp[0])->lineno,NODE_PARA);
                (yyval)->addChild((yyvsp[0]));//param-int-a
            }
#line 1651 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 271 "src/main.y" /* yacc.c:1646  */
    {
                (yyval)=(yyvsp[-2]);
                (yyval)->addChild((yyvsp[0]));
            }
#line 1660 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 275 "src/main.y" /* yacc.c:1646  */
    {
                (yyval)=new TreeNode(lineno,NODE_NULL);cout<<"NULLnode"<<endl;
            }
#line 1668 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 281 "src/main.y" /* yacc.c:1646  */
    {
                    (yyval)=(yyvsp[-1]);
                    (yyval)->addChild((yyvsp[0]));// int--a
                }
#line 1677 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 288 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1683 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 291 "src/main.y" /* yacc.c:1646  */
    {
            (yyval)=new TreeNode((yyvsp[0])->lineno,NODE_BLOCK);
            (yyval)->addChild((yyvsp[0]));
		}
#line 1692 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 295 "src/main.y" /* yacc.c:1646  */
    {
            (yyval)=(yyvsp[-1]);
            (yyval)->addChild((yyvsp[0]));
        }
#line 1701 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 302 "src/main.y" /* yacc.c:1646  */
    {
                    (yyval)=(yyvsp[0]);
                    cout<<"decl!"<<endl;
                }
#line 1710 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 306 "src/main.y" /* yacc.c:1646  */
    {
                    (yyval)=(yyvsp[0]);
                }
#line 1718 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 313 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)=new TreeNode((yyvsp[-2])->lineno,NODE_STMT);
        (yyval)->stmt_type=STMT_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 1729 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 319 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1735 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 326 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1741 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 327 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1747 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 328 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[0]);
        cout<<"number!"<<endl;
    }
#line 1756 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 334 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1762 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 335 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1768 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 336 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);
    }
#line 1775 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 341 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1781 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 342 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1787 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 343 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1793 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 344 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1799 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 348 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1805 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 348 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1811 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 352 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1817 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 353 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[0]);
    }
#line 1825 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 356 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)->op_type=OP_SUB;
        (yyval)->addChild((yyvsp[0]));
    }
#line 1834 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 360 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)->op_type=OP_NOT;
        (yyval)->addChild((yyvsp[0]));
    }
#line 1843 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 368 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1849 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 369 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->op_type=OP_MUL;
    }
#line 1859 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 374 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->op_type=OP_DIV;
    }
#line 1869 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 379 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->op_type=OP_MOD;
    }
#line 1879 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 386 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1885 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 387 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->op_type=OP_ADD;
    }
#line 1895 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 392 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->op_type=OP_SUB;
    }
#line 1905 "src/main.tab.cpp" /* yacc.c:1646  */
    break;


#line 1909 "src/main.tab.cpp" /* yacc.c:1646  */
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
#line 401 "src/main.y" /* yacc.c:1906  */


int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
