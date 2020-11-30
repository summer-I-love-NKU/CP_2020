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
TreeNode* p_add_stmt;
extern int lineno;
int yylex();
int yyerror( char const * );
// //------------
stack<map<string,pair<string,int> > > ST_stack;
stack<int> NUM_stack;
map<string,pair<string,int> > t_top;
int n_top;
string ValType_name[10] = {"bool", "int", "char", "string","void","6"};
// //-------------

#line 86 "src/main.tab.cpp" /* yacc.c:339  */

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
    ASSIGN = 262,
    ADD_ASSIGN = 263,
    SUB_ASSIGN = 264,
    MUL_ASSIGN = 265,
    DIV_ASSIGN = 266,
    EQ = 267,
    NOT_EQ = 268,
    LESS_THAN = 269,
    LESS_EQ = 270,
    MORE_THAN = 271,
    MORE_EQ = 272,
    AND = 273,
    OR = 274,
    NOT = 275,
    ADD = 276,
    SUB = 277,
    MUL = 278,
    DIV = 279,
    MOD = 280,
    SELF_ADD = 281,
    SELF_SUB = 282,
    SEMICOLON = 283,
    COMMA = 284,
    DOT = 285,
    LPAREN = 286,
    RPAREN = 287,
    LBRACE = 288,
    RBRACE = 289,
    IDENTIFIER = 290,
    INTEGER = 291,
    CHAR = 292,
    BOOL = 293,
    STRING = 294,
    MAIN = 295,
    RETURN = 296,
    FOR = 297,
    WHILE = 298,
    IF = 299,
    ELSE = 300,
    ELSE_IF = 301,
    PRINTF = 302,
    SCANF = 303,
    b_OR = 304,
    b_NOR = 305,
    b_AND = 306,
    UMINUS = 307,
    b_NOT = 308,
    pre_SELF_ADD = 309,
    pre_SELF_SUB = 310,
    GET_ADDRESS = 311
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

#line 194 "src/main.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   338

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

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
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,   107,   117,   121,   129,   130,   131,   132,
     133,   134,   165,   179,   182,   186,   189,   192,   196,   202,
     208,   214,   220,   226,   232,   238,   244,   249,   255,   261,
     267,   273,   279,   287,   306,   326,   341,   361,   372,   381,
     390,   399,   408,   413,   421,   427,   436,   436,   436,   438,
     438,   440,   440,   443,   451,   459,   465,   480,   481,   482,
     483
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT", "T_CHAR", "T_BOOL", "T_VOID",
  "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "EQ",
  "NOT_EQ", "LESS_THAN", "LESS_EQ", "MORE_THAN", "MORE_EQ", "AND", "OR",
  "NOT", "ADD", "SUB", "MUL", "DIV", "MOD", "SELF_ADD", "SELF_SUB",
  "SEMICOLON", "COMMA", "DOT", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "IDENTIFIER", "INTEGER", "CHAR", "BOOL", "STRING", "MAIN", "RETURN",
  "FOR", "WHILE", "IF", "ELSE", "ELSE_IF", "PRINTF", "SCANF", "b_OR",
  "b_NOR", "b_AND", "UMINUS", "b_NOT", "pre_SELF_ADD", "pre_SELF_SUB",
  "GET_ADDRESS", "$accept", "program", "fake_1", "statements", "statement",
  "fake_2", "expr", "decl_stmt", "assign_stmt", "IO_stmt", "for_expr_1",
  "for_expr_2", "for_expr_3", "if_else_while_for_stmt", "Type", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -43

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-43)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   -43,   -43,   -43,   -43,    19,    -4,   -43,    -6,     5,
      28,   -43,   192,   134,   134,   -43,   -43,    60,   -43,   -43,
     -43,   -43,    21,    43,    44,    45,    52,   100,   -43,   271,
       6,    56,    58,   -43,    53,   -43,   -43,   -43,   192,   134,
     134,   134,   134,   134,    74,   134,   134,    50,    54,   -43,
     -43,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   -43,   -43,   -43,    62,   -43,   -43,
      84,   146,   287,   287,   287,   287,   287,    69,   -43,    72,
      -1,    41,    78,    79,   313,   313,   136,   136,   136,   136,
     102,   301,   -15,   -15,   -43,   -43,   -43,    94,   134,   -43,
     134,   192,   192,   134,    70,   134,   287,   287,   101,   -43,
      85,   229,   134,   287,   180,   192,   -43,   250,   -43,    99,
     -43,   -43,   192,   -43
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    57,    58,    59,    60,     0,     0,     1,     0,     0,
       0,     3,     0,     0,     0,     6,    12,    13,    14,    15,
      17,    16,     0,     0,     0,     0,     0,     0,     4,     0,
       0,     0,     0,    10,     0,    13,    26,    23,     0,     0,
       0,     0,     0,     0,    48,     0,     0,     0,     0,     2,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    43,     7,     0,     8,     9,
      34,     0,    37,    38,    39,    40,    41,    46,    47,     0,
       0,     0,     0,     0,    32,    31,    28,    27,    30,    29,
      24,    25,    18,    19,    20,    21,    22,    35,     0,    11,
      50,     0,     0,     0,     0,     0,    33,    49,     0,    55,
      53,     0,     0,    36,    52,     0,    44,     0,    51,     0,
      54,    45,     0,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,   -43,   103,   -20,   -43,   -13,    88,   -42,   -43,
     -43,   -43,   -43,   -43,   140
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,    12,    27,    28,    38,    29,    30,    31,    32,
      79,   108,   119,    33,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    37,    78,     1,     2,     3,     4,    50,    61,    62,
      63,    51,    52,    53,    54,    55,    56,    57,    58,     7,
      59,    60,    61,    62,    63,     9,    72,    73,    74,    75,
      76,   101,    80,    81,    66,    67,     8,    10,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    50,    44,    51,    52,    53,    54,    55,    56,    57,
      58,    11,    59,    60,    61,    62,    63,    39,    40,    41,
      42,    43,   118,   102,    45,    46,    47,     1,     2,     3,
       4,   109,   110,    48,    68,   106,    69,   107,    70,    82,
     111,    98,   113,    83,    13,   120,    14,    97,    67,   117,
     100,   105,   123,     1,     2,     3,     4,   103,   104,    17,
      18,    19,    20,    21,    51,    52,    53,    54,    55,    56,
      13,   112,    14,    59,    60,    61,    62,    63,    15,   114,
     115,   122,    77,    16,    49,    17,    18,    19,    20,    21,
       6,    71,    22,    23,    24,     0,     0,    25,    26,     1,
       2,     3,     4,     0,    13,     0,    14,    59,    60,    61,
      62,    63,     0,     0,     0,     0,    13,     0,    14,    35,
      18,    19,    20,    21,    15,     0,     0,     0,     0,    16,
      99,    17,    18,    19,    20,    21,     0,     0,    22,    23,
      24,     0,     0,    25,    26,     1,     2,     3,     4,     0,
      13,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     0,    14,    17,    18,    19,    20,    21,
      15,     0,     0,     0,     0,    16,     0,    17,    18,    19,
      20,    21,     0,     0,    22,    23,    24,     0,     0,    25,
      26,    51,    52,    53,    54,    55,    56,    57,    58,     0,
      59,    60,    61,    62,    63,     0,     0,     0,     0,     0,
       0,   116,    51,    52,    53,    54,    55,    56,    57,    58,
       0,    59,    60,    61,    62,    63,     0,     0,     0,     0,
       0,     0,   121,    51,    52,    53,    54,    55,    56,    57,
      58,     0,    59,    60,    61,    62,    63,    64,    65,    51,
      52,    53,    54,    55,    56,    57,    58,     0,    59,    60,
      61,    62,    63,    51,    52,    53,    54,    55,    56,    57,
       0,     0,    59,    60,    61,    62,    63,    53,    54,    55,
      56,     0,     0,     0,    59,    60,    61,    62,    63
};

static const yytype_int8 yycheck[] =
{
      13,    14,    44,     3,     4,     5,     6,    27,    23,    24,
      25,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      21,    22,    23,    24,    25,    31,    39,    40,    41,    42,
      43,    32,    45,    46,    28,    29,    40,    32,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    71,    31,    12,    13,    14,    15,    16,    17,    18,
      19,    33,    21,    22,    23,    24,    25,     7,     8,     9,
      10,    11,   114,    32,    31,    31,    31,     3,     4,     5,
       6,   101,   102,    31,    28,    98,    28,   100,    35,    39,
     103,     7,   105,    39,    20,   115,    22,    35,    29,   112,
      28,     7,   122,     3,     4,     5,     6,    29,    29,    35,
      36,    37,    38,    39,    12,    13,    14,    15,    16,    17,
      20,    51,    22,    21,    22,    23,    24,    25,    28,    28,
      45,    32,    44,    33,    34,    35,    36,    37,    38,    39,
       0,    38,    42,    43,    44,    -1,    -1,    47,    48,     3,
       4,     5,     6,    -1,    20,    -1,    22,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    20,    -1,    22,    35,
      36,    37,    38,    39,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    43,
      44,    -1,    -1,    47,    48,     3,     4,     5,     6,    -1,
      20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    22,    35,    36,    37,    38,    39,
      28,    -1,    -1,    -1,    -1,    33,    -1,    35,    36,    37,
      38,    39,    -1,    -1,    42,    43,    44,    -1,    -1,    47,
      48,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    14,    15,    16,
      17,    -1,    -1,    -1,    21,    22,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    58,    71,     0,    40,    31,
      32,    33,    59,    20,    22,    28,    33,    35,    36,    37,
      38,    39,    42,    43,    44,    47,    48,    60,    61,    63,
      64,    65,    66,    70,    71,    35,    63,    63,    62,     7,
       8,     9,    10,    11,    31,    31,    31,    31,    31,    34,
      61,    12,    13,    14,    15,    16,    17,    18,    19,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    28,    28,
      35,    60,    63,    63,    63,    63,    63,    64,    65,    67,
      63,    63,    39,    39,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    35,     7,    34,
      28,    32,    32,    29,    29,     7,    63,    63,    68,    61,
      61,    63,    51,    63,    28,    45,    32,    63,    65,    69,
      61,    32,    32,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    64,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    66,    66,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    70,    70,    71,    71,    71,
      71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     0,     1,     2,     1,     2,     2,     2,
       1,     4,     0,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     2,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     4,     2,     3,     5,     3,     3,     3,
       3,     3,     2,     2,     6,     7,     1,     1,     0,     1,
       0,     1,     0,     5,     7,     5,     9,     1,     1,     1,
       1
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
#line 95 "src/main.y" /* yacc.c:1646  */
    {
        root = new TreeNode((yyvsp[-7])->lineno, NODE_PROG); root->addChild((yyvsp[-1]));
        //-------------------
        cout<<"------主函数符号表！！！------\n";
        for(map<string,pair<string,int> >::iterator iter = t_top.begin(); iter != t_top.end(); iter++)
        {
            cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
        }cout<<"------------\n";
        cout<<"}"<<endl;
        //------------------
        }
#line 1411 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 107 "src/main.y" /* yacc.c:1646  */
    {
        //---------------
        cout<<"{"<<endl;
        map<string,pair<string,int> > tmp;int numtmp=1;
        ST_stack.push(tmp);NUM_stack.push(numtmp);
        t_top=ST_stack.top();n_top=NUM_stack.top();
        //-------------------
    }
#line 1424 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 117 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_STMT);
        (yyval)=(yyvsp[0]);
    }
#line 1433 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 122 "src/main.y" /* yacc.c:1646  */
    {   
        (yyval)=(yyvsp[-1]);
        (yyval)->addSibling((yyvsp[0]));
    }
#line 1442 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 129 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stmt_type = STMT_SKIP;}
#line 1448 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 130 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1454 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 131 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1460 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 132 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1466 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 133 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1472 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "src/main.y" /* yacc.c:1646  */
    {
        //语句加一个总的根结点，解决问题
        (yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
        (yyval)->stmt_type=STMT_BLOCK;
        (yyval)->addChild((yyvsp[-1]));
        //-------------------------------------
            cout<<"------------\n";
            cout<<"显示啊！！！"<<endl;
            for(map<string,pair<string,int> >::iterator iter = t_top.begin(); iter != t_top.end(); iter++)
            {
                cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
            }cout<<"------------\n";
            
            if(ST_stack.size()>1)
            {
                ST_stack.pop();t_top=ST_stack.top();
                // cout<<"弹栈后！！！"<<endl;cout<<"stack size"<<ST_stack.size()<<endl<<"stack empty:"<<ST_stack.empty()
                // <<endl<<"map empty:"<<t_top.empty()<<endl;
                    // for(map<string,pair<string,int> >::iterator iter = t_top.begin(); iter != t_top.end(); iter++)
                    // {
                    //     cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
                    // }
            }
            if(NUM_stack.size()>1)
            {
                NUM_stack.pop();
                n_top=NUM_stack.top();
            }
        //-------------------------
        }
#line 1507 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 165 "src/main.y" /* yacc.c:1646  */
    {
        //-------------------------
        //===================更新!!!
        ST_stack.pop();ST_stack.push(t_top);

        //===============再压栈下一级作用域符号表
        map<string,pair<string,int> > tmp;int numtmp=1;
        ST_stack.push(tmp);NUM_stack.push(numtmp);
        t_top=ST_stack.top();n_top=NUM_stack.top();
        //----------------------------
    }
#line 1523 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 179 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
    }
#line 1531 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 182 "src/main.y" /* yacc.c:1646  */
    {
        //注意这部分的int char bool类型常量在词法分析的.l文件就已经定义初始化树结点了！！！
        (yyval) = (yyvsp[0]);
    }
#line 1540 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 186 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
    }
#line 1548 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 189 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
    }
#line 1556 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 192 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
    }
#line 1564 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 196 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_ADD;
        // $$->int_val=$1->int_val+$3->int_val;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        }
#line 1575 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 202 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_SUB;
        // $$->int_val=$1->int_val-$3->int_val;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        }
#line 1586 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 208 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_MUL;
        // $$->int_val=$1->int_val*$3->int_val;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        }
#line 1597 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 214 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_DIV;
        // $$->int_val=$1->int_val/$3->int_val;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        }
#line 1608 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 220 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_MOD;
        // $$->int_val=$1->int_val%$3->int_val;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        }
#line 1619 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 226 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_NEG;
        // $$->int_val=-$2->int_val;
        (yyval)->addChild((yyvsp[0]));
    }
#line 1629 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 232 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_AND;
        // $$->int_val=$1->int_val&&$3->int_val;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 1640 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 238 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_OR;
        // $$->int_val=$1->int_val||$3->int_val;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 1651 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 244 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_NOT;
        // $$->int_val=!$2->int_val;
        (yyval)->addChild((yyvsp[0]));
    }
#line 1661 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 249 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_LESS_EQ;
        // $$->int_val=($1->int_val<=$3->int_val);
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 1672 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 255 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_LESS_THAN;
        // $$->int_val=($1->int_val<$3->int_val);
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 1683 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 261 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_MORE_EQ;
        // $$->int_val=($1->int_val>=$3->int_val);
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 1694 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 267 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_MORE_THAN;
        // $$->int_val=($1->int_val>$3->int_val);
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 1705 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 273 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_NOT_EQ;
        // $$->int_val=($1->int_val!=$3->int_val);
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 1716 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 279 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_EQ;
        // $$->int_val=($1->int_val==$3->int_val);
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 1727 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 287 "src/main.y" /* yacc.c:1646  */
    {  
        // declare and init
        (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL;
        (yyval)->addChild((yyvsp[-3]));
        (yyvsp[-3])->addChild((yyvsp[-2]));
        (yyvsp[-2])->addChild((yyvsp[0])); 
        //----------------
        if(t_top.count((yyvsp[-2])->var_name)==0)
        {
            t_top[(yyvsp[-2])->var_name]=make_pair(ValType_name[(yyvsp[-3])->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redefine error!!!"<<endl;
        }
        //-------------
    }
#line 1751 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 306 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL;
        (yyval)->addChild((yyvsp[-1]));
        (yyvsp[-1])->addChild((yyvsp[0]));
        //--------------------------
        if(t_top.count((yyvsp[0])->var_name)==0)
        {
            t_top[(yyvsp[0])->var_name]=make_pair(ValType_name[(yyvsp[-1])->type->type],n_top);
            // cout<<"!!!!"<<$2->var_name<<"  "<< ValType_name[$1->type->type]<<" "<<n_top<<endl;
            // cout<<"当前map中元素个数："<<t_top.size()<<endl;
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;

        }
        //-----------------------
    }
#line 1776 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 326 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[-2]);
        (yyval)->child->addChild((yyvsp[0]));
        //--------------------------
        if(t_top.count((yyvsp[0])->var_name)==0)
        {
            t_top[(yyvsp[0])->var_name]=make_pair(ValType_name[(yyvsp[-2])->child->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redeclare error!!!"<<endl;
        }
        //-----------------------
    }
#line 1796 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 341 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[-4]);
        (yyval)->child->addChild((yyvsp[-2]));
        (yyvsp[-2])->addChild((yyvsp[0]));
        //--------------------------
        if(t_top.count((yyvsp[-2])->var_name)==0)
        {
            t_top[(yyvsp[-2])->var_name]=make_pair(ValType_name[(yyvsp[-4])->child->type->type],n_top);
            n_top++;
        }
        else
        {
            cout<<"redefine error!!!"<<endl;
        }
        //-----------------------
    }
#line 1817 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 361 "src/main.y" /* yacc.c:1646  */
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
#line 1833 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 372 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_ADD_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        
        // TreeNode* p=$$->child;
        // p->int_val+=p->sibling->int_val;
    }
#line 1847 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 381 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_SUB_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        
        // TreeNode* p=$$->child;
        // p->int_val-=p->sibling->sibling->int_val;
    }
#line 1861 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 390 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_MUL_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        
        // TreeNode* p=$$->child;
        // p->int_val*=p->sibling->sibling->int_val;
    }
#line 1875 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 399 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DIV_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        
        // TreeNode* p=$$->child;
        // p->int_val/=p->sibling->sibling->int_val;
    }
#line 1889 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 408 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stmt_type = STMT_SELF_ADD_ASSIGN;
        // $$->int_val=$1->int_val+1;
        (yyval)->addChild((yyvsp[-1]));
        }
#line 1899 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 413 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stmt_type = STMT_SELF_SUB_ASSIGN;
        // $$->int_val=$1->int_val-1;
        (yyval)->addChild((yyvsp[-1]));
        }
#line 1909 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 421 "src/main.y" /* yacc.c:1646  */
    {
            (yyval) = new TreeNode(lineno, NODE_STMT);
            (yyval)->stmt_type=STMT_PRINTF;
            (yyval)->addChild((yyvsp[-3]));
            (yyval)->addChild((yyvsp[-1]));
        }
#line 1920 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 427 "src/main.y" /* yacc.c:1646  */
    {
            (yyval) = new TreeNode(lineno, NODE_STMT);
            (yyval)->stmt_type=STMT_SCANF;
            (yyval)->addChild((yyvsp[-4]));
            (yyval)->addChild((yyvsp[-1]));
        }
#line 1931 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 443 "src/main.y" /* yacc.c:1646  */
    {
        // cout<<"if !!"<<endl;
        //这里不能用$1,要么直接lineno 要么$3->lineno
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type=STMT_IF;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 1944 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 451 "src/main.y" /* yacc.c:1646  */
    {
        //这里不能用$1,要么直接lineno 要么$3->lineno
        (yyval) = new TreeNode((yyvsp[-4])->lineno, NODE_STMT);
        (yyval)->stmt_type=STMT_IF_ELSE;
        (yyval)->addChild((yyvsp[-4]));
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 1957 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 459 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type=STMT_WHILE;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
    }
#line 1968 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 466 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-6])->lineno, NODE_STMT);
        (yyval)->stmt_type=STMT_FOR;
        (yyval)->addChild((yyvsp[-6]));
        (yyval)->addChild((yyvsp[-4]));
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        }
#line 1981 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 480 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_INT;}
#line 1987 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 481 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CHAR;}
#line 1993 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 482 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_BOOL;}
#line 1999 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 483 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_VOID;}
#line 2005 "src/main.tab.cpp" /* yacc.c:1646  */
    break;


#line 2009 "src/main.tab.cpp" /* yacc.c:1646  */
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
#line 490 "src/main.y" /* yacc.c:1906  */


int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
