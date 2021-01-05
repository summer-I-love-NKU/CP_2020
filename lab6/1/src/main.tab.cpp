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
SymTable *cur_table;
int scopeid=-1,n_top=1;
string ValType_name[20] = {"bool", "int", "char", "string","void","const int","const char","9"};//对应enum ValueType
//-------------

//类型错误检查（比如字符串、布尔值不能参与某些运算、输入输出函数也有参数类型要求）
//实际上，全局变量的声明如何加入符号表，我是在类型检查（decl）函数中构建的，其他的地方就是stmt的大括号和main的大括号构建符号表
    //if else while
    void check_control_stmt(TreeNode* t)
    {
        /************************TYPE_CHECK*****************************/
            if(t->child->val_type_flag=='i')
            {
                /***************************type trans*********************************/
                cout <<t->lineno<<" : if/while stmt:the expr should be bool type.   type trans!!! int-->bool"<<endl;
                t->child->val_type_flag == 'b';//??????
            }
            else if(t->child->val_type_flag=='b')
            {
                ;
            }
            else
            {
                cout <<t->child->lineno<<" : type error!   if/while stmt:the expr should be bool type!" << endl;
            }
        /************************TYPE_CHECK*****************************/
    }
    void check_for_stmt(TreeNode* t)
    {
            if(t->child->sibling->val_type_flag=='i')//child2(for 的 expr2)
            {
                /***************************type trans*********************************/
                cout <<t->lineno<<" : for stmt:the expr2 should be bool type.\ntype trans!!! int-->bool"<<endl;
                t->child->sibling->val_type_flag == 'b';//??????
            }
            else if(t->child->sibling->val_type_flag=='b')
            {
                ;
            }
            else
            {
                cout <<t->child->lineno<<" : type error!"<<endl<<
                "for stmt:the expr2 should be bool type!" << endl;
            }
    }
    //redecl重声明
    void check_decl(TreeNode* t)
    {
        if(scopeid==-1)
            cur_table=new SymTable(++scopeid);//??????????????
        if(cur_table->tmap.count(t->var_name)==0)
        {
            cur_table->tmap[t->var_name]=make_pair(ValType_name[t->father->type->type],n_top);
            cur_table->nodemap[t->var_name]=t;
            n_top++;
        }
        else
        {
            cout <<t->lineno<<" : "<<t->var_name<<" :redecl error!"<<endl;
        }
    }
    //nodecl未声明    并且对合法的ID 对应到符号表！！
    void check_ID(TreeNode* t)
    {
        //cout<<cur_table->scope<<endl;
        if(cur_table->tmap.count(t->var_name)==0)
        {
            SymTable *p=cur_table;
            while(p!=nullptr)
            {
                if(p->tmap.count(t->var_name)!=0)
                {
                    t->val_type_flag=p->nodemap[t->var_name]->val_type_flag;
                    return;
                }
                    
                p=p->father;
                
            }
            cout <<t->lineno<<" : "<<t->var_name<<" :no decl error!"<<endl;
            //cout<<cur_table->scope<<endl;
        }
        else//对应到符号表！！
        {
            //t=cur_table->nodemap[t->var_name];//似乎不行  怎么深拷贝？？？
            //cout<<"对应到符号表！！"<<t->val_type_flag;
            t->val_type_flag=cur_table->nodemap[t->var_name]->val_type_flag;
        }
    }

    //calculation 运算类型
    void check_CAL_math(TreeNode* t)
    {
        if(t->child->val_type_flag!='i'||t->child->sibling->val_type_flag!='i')
        {
            cout <<t->lineno<<" : calculation type error! expect \"int\"!!!"<<endl;
        }
    }
    void check_CAL_math_negtivenum(TreeNode* t)
    {
        if(t->child->val_type_flag!='i')
        {
            cout <<t->lineno<<" : math calculation type error! expect \"int\"!!!"<<endl;
        }
    }

    void check_CAL_logical(TreeNode* t)
    {
        if(t->child->val_type_flag=='s'||t->child->val_type_flag=='c'||t->child->sibling->val_type_flag=='s'||t->child->sibling->val_type_flag=='c')
        //int bool  可以  string char 不可以 进行逻辑运算
        {
            cout <<t->lineno<<" : logical calculation type error! expect \"int\" or \"bool\"!!!"<<endl;
        }
    }
    void check_CAL_logical_not(TreeNode* t)
    {
        if(t->child->val_type_flag=='s'||t->child->val_type_flag=='c')//int bool  可以  string char 不可以 进行逻辑运算
        {
            cout <<t->lineno<<" : logical calculation type error! expect \"int\" or \"bool\"!!!"<<endl;
        }
    }


    //检查声明和赋值的类型是否正确
    void check_decl_type(TreeNode* t)//int a = 1; t是孩子，这样找父亲方便
    {
        //int a=1;
        if(t->father->father->type==TYPE_INT)
        {
            if(t->val_type_flag!='i')
            {
                cout <<t->lineno<<" : assign type error! expect \"int\"!!!"<<endl;
            }
        }
        else if(t->father->father->type==TYPE_STRING)
        {
            if(t->val_type_flag!='s')
            {
                cout <<t->lineno<<" : assign type error! expect \"string\"!!!"<<endl;
            }
        }
        else if(t->father->father->type==TYPE_CHAR)
        {
            if(t->val_type_flag!='c')
            {
                cout <<t->lineno<<" : assign type error! expect \"char\"!!!"<<endl;
            }
        }
        else if(t->father->father->type==TYPE_BOOL)
        {
            if(t->val_type_flag!='b')
            {
                if(t->val_type_flag!='i')
                {cout <<t->lineno<<" : assign type error! expect \"bool\"!!!"<<endl;}
                else
                {
                    /***************************type trans*********************************/
                    cout <<t->lineno<<" : type trans!!! int-->bool"<<endl;
                    t->val_type_flag='b';
                }
            }
        }
    }
    void check_assign_type(TreeNode* t)//a = 1; a和1是兄弟关系  但这个a是归约得到ID，需要在符号表对应到定义的a
    {
        // cout<<t->val_type_flag<<endl;
        if(t->val_type_flag=='i')
        {
            if(t->sibling->val_type_flag!='i')
            {
                cout <<t->lineno<<" : assign type error! expect \"int\"!!!"<<endl;
            }
        }
        else if(t->val_type_flag=='c')
        {
            if(t->sibling->val_type_flag!='c')
            {
                cout <<t->lineno<<" : assign type error! expect \"char\"!!!"<<endl;
            }
        }
        else if(t->val_type_flag=='s')
        {
            if(t->sibling->val_type_flag!='s')
            {
                cout <<t->lineno<<" : assign type error! expect \"string\"!!!"<<endl;
            }
        }
        else if(t->val_type_flag=='b')
        {
            if(t->sibling->val_type_flag!='b')
            {
                if(t->sibling->val_type_flag!='i')
                {cout <<t->lineno<<" : assign type error! expect \"bool\"!!!"<<endl;}
                else
                {
                    /***************************type trans*********************************/
                    cout <<t->lineno<<" : type trans!!! int-->bool"<<endl;
                    t->sibling->val_type_flag='b';
                }
            }
        }
    }
    //
    void check_IO(TreeNode* t)
    {
        

    }
    /***************************type trans*********************************/
    void type_trans(TreeNode* t)
    {
        //注意可能有的没有val_type_flag属性，导致段错误！！！！

        // //-------类型转换？？？char m=97;-->'a' -----
        // if(ValType_name[t->father->type->type]=="char"&&t->val_type_flag=='i')
        // {
        //     t->ch_val=char(t->int_val);
        //     t->val_type_flag='c';
        //     cout <<t->child->lineno<< "type check：int转换为char" << endl;
        // }
        // if(ValType_name[t->father->type->type]=="bool"&&t->val_type_flag!='b')
        // {
        //     t->b_val=bool(t->int_val)||bool(t->ch_val);
        //     t->val_type_flag='b';
        //     cout <<t->child->lineno<< "type check：转换为bool" << endl;
        // }
    }
//-----------------------------------

#line 307 "src/main.tab.cpp" /* yacc.c:339  */

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
    T_STRING = 261,
    T_VOID = 262,
    CONST = 263,
    ASSIGN = 264,
    ADD_ASSIGN = 265,
    SUB_ASSIGN = 266,
    MUL_ASSIGN = 267,
    DIV_ASSIGN = 268,
    EQ = 269,
    NOT_EQ = 270,
    LESS_THAN = 271,
    LESS_EQ = 272,
    MORE_THAN = 273,
    MORE_EQ = 274,
    AND = 275,
    OR = 276,
    NOT = 277,
    ADD = 278,
    SUB = 279,
    MUL = 280,
    DIV = 281,
    MOD = 282,
    SELF_ADD = 283,
    SELF_SUB = 284,
    SEMICOLON = 285,
    COMMA = 286,
    DOT = 287,
    LPAREN = 288,
    RPAREN = 289,
    LBRACE = 290,
    RBRACE = 291,
    LMPAREN = 292,
    RMPAREN = 293,
    IDENTIFIER = 294,
    INTEGER_H = 295,
    INTEGER_D = 296,
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

#line 423 "src/main.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   509

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

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
       0,   319,   319,   320,   325,   330,   335,   342,   346,   360,
     372,   376,   384,   385,   386,   387,   388,   389,   394,   418,
     431,   438,   443,   447,   451,   455,   460,   471,   481,   491,
     501,   511,   522,   532,   541,   549,   558,   567,   576,   585,
     594,   607,   626,   638,   650,   660,   673,   684,   703,   715,
     729,   731,   739,   748,   757,   766,   773,   785,   798,   814,
     820,   826,   834,   838,   844,   848,   854,   855,   865,   879,
     900,   925,   941,   965,   985,   985,   985,   987,   987,   989,
     989,   992,   993,   994,   995,   996,   997,   998,  1003,  1004,
    1005,  1006,  1010,  1015,  1021,  1024,  1029,  1035,  1036,  1037,
    1042
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT", "T_CHAR", "T_BOOL", "T_STRING",
  "T_VOID", "CONST", "ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "EQ", "NOT_EQ", "LESS_THAN", "LESS_EQ", "MORE_THAN",
  "MORE_EQ", "AND", "OR", "NOT", "ADD", "SUB", "MUL", "DIV", "MOD",
  "SELF_ADD", "SELF_SUB", "SEMICOLON", "COMMA", "DOT", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "LMPAREN", "RMPAREN", "IDENTIFIER", "INTEGER_H",
  "INTEGER_D", "INTEGER_O", "INTEGER_B", "CHAR", "BOOL", "STRING", "MAIN",
  "RETURN", "FOR", "WHILE", "IF", "ELSE", "ELSE_IF", "PRINTF", "SCANF",
  "b_OR", "b_NOR", "b_AND", "UMINUS", "b_NOT", "pre_SELF_ADD",
  "pre_SELF_SUB", "GET_ADDRESS", "POINTER", "$accept", "CompUnit", "Decl",
  "Func_Def", "fake_1", "statements", "statement", "fake_2", "expr",
  "decl_stmt", "assign_stmt", "base_assign_stmt", "IO_stmt", "O_expr",
  "I_expr", "if_else_while_for_stmt", "if_else_stmt", "if_else_if",
  "for_expr_1", "for_expr_2", "for_expr_3", "Type", "INT_CONST", "ARRAY",
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

#define YYPACT_NINF -109

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-109)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,  -109,  -109,  -109,  -109,  -109,     1,   142,  -109,  -109,
      16,   -19,  -109,  -109,  -109,  -109,  -109,  -109,   -22,   -22,
     -18,     5,   -22,    -8,    58,  -109,    86,   113,    30,    89,
     124,    49,    98,    46,    46,    82,   105,   118,   -22,   115,
    -109,   125,    46,    46,    46,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,   339,  -109,  -109,   339,    46,  -109,  -109,  -109,
    -109,  -109,  -109,   -15,  -109,  -109,  -109,  -109,   361,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,   339,   275,   115,  -109,  -109,   111,   111,    50,
      50,    50,    50,   224,   482,    56,    56,  -109,  -109,  -109,
    -109,  -109,     0,   129,   131,   135,   137,   145,   169,  -109,
     466,    32,   149,  -109,   150,  -109,  -109,    61,   -13,    90,
    -109,   275,   152,   328,    46,    46,   138,   140,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,   275,   154,    46,    46,    46,
      46,    46,   222,  -109,   157,  -109,   153,   382,   403,    62,
     158,  -109,    46,   339,  -109,   181,   339,   339,   339,   339,
    -109,    46,   275,   275,    46,  -109,   134,   424,   339,   164,
    -109,    63,   339,    75,    46,    77,   275,    46,   275,   162,
      46,  -109,   339,   139,  -109,  -109,  -109,   166,  -109,    46,
     339,    46,   275,   445,   339,  -109,   275,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    81,    82,    83,    84,    85,     0,     0,     6,     5,
       0,     0,    86,    87,     1,     4,     3,     7,     0,     0,
     100,     0,     0,    49,    42,   100,    44,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,     0,     0,    88,    89,    90,    91,    22,
      24,    23,    41,    21,    20,    43,     0,    92,     9,    47,
      98,    99,    97,     0,    95,    93,    34,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,    94,    25,    40,    39,    36,
      35,    38,    37,    32,    33,    26,    27,    28,    29,    30,
      12,    19,     0,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,    50,     0,    16,    66,     0,     0,    20,
      96,     0,     0,    76,     0,     0,     0,     0,     8,    11,
      55,    56,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    74,    75,     0,     0,     0,     0,
       0,    71,     0,    57,    58,    20,    51,    52,    53,    54,
      18,    78,     0,     0,     0,    60,     0,     0,    77,     0,
      67,    69,    62,     0,     0,     0,     0,    80,     0,     0,
       0,    59,    64,     0,    61,    73,    79,     0,    70,     0,
      63,     0,     0,     0,    65,    68,     0,    72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,   189,   191,  -109,    80,   -98,  -109,   -20,     2,
    -108,    66,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,    18,   -36,  -109,  -109,  -109,   122,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    83,   108,   109,   121,   110,   111,
     112,   113,   114,   173,   175,   115,   116,   117,   146,   169,
     187,   118,    53,    23,    40,    63,    64,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      24,    31,    10,    62,    12,    13,    19,    26,    27,    10,
     129,    30,    19,    52,    55,   145,    84,    25,    11,    28,
      20,    85,    66,    67,    68,    11,    20,    59,    21,    32,
       1,     2,     3,     4,     5,     6,    82,   151,    29,    22,
      45,    46,    47,    48,   129,    22,    17,    18,    62,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   132,    18,   170,   171,   122,    33,    42,   186,
      43,    36,   119,    77,    78,    79,    80,    81,   185,    44,
     188,    79,    80,    81,    39,    25,    45,    46,    47,    48,
      49,    50,    51,   164,   195,    34,   165,   119,   197,   137,
     138,   139,   140,   141,   147,   148,   180,    24,   183,   181,
     119,   184,   119,   135,   136,   178,   179,   153,   156,   157,
     158,   159,    35,    37,   119,   144,   155,    71,    72,    73,
      74,   119,   167,    38,    77,    78,    79,    80,    81,    41,
      56,   168,    14,    57,   172,     1,     2,     3,     4,     5,
       6,   119,   119,    58,   182,    45,    46,    47,    48,    60,
     190,    61,   123,    65,   124,   119,   119,   119,   125,   193,
     126,   194,     1,     2,     3,     4,     5,     6,   127,   133,
     134,   119,   143,   161,   149,   119,   150,   152,    18,   166,
     137,    42,   174,    43,   177,   189,    15,   191,    16,   100,
     192,   142,    44,   154,   101,   128,   120,     0,    25,    45,
      46,    47,    48,    49,    50,    51,     0,   102,   103,   104,
     105,     0,     0,   106,   107,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,    74,    42,     0,    43,    77,    78,    79,
      80,    81,   100,     0,     0,    44,     0,   101,   160,     0,
       0,    25,    45,    46,    47,    48,    49,    50,    51,     0,
     102,   103,   104,   105,     0,     0,   106,   107,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,     0,    43,
       0,     0,     0,     0,     0,   100,     0,     0,    44,     0,
     101,     0,     0,     0,    25,    45,    46,    47,    48,    49,
      50,    51,     0,   102,   103,   104,   105,     0,     0,   106,
     107,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,     0,    43,    69,    70,    71,    72,    73,    74,    75,
      76,    44,    77,    78,    79,    80,    81,    25,    45,    46,
      47,    48,    49,    50,    51,    69,    70,    71,    72,    73,
      74,    75,    76,     0,    77,    78,    79,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    69,    70,    71,    72,
      73,    74,    75,    76,     0,    77,    78,    79,    80,    81,
       0,     0,     0,     0,     0,     0,   162,    69,    70,    71,
      72,    73,    74,    75,    76,     0,    77,    78,    79,    80,
      81,     0,     0,     0,     0,     0,     0,   163,    69,    70,
      71,    72,    73,    74,    75,    76,     0,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,     0,   176,    69,
      70,    71,    72,    73,    74,    75,    76,     0,    77,    78,
      79,    80,    81,     0,     0,     0,     0,     0,     0,   196,
      69,    70,    71,    72,    73,    74,    75,    76,     0,    77,
      78,    79,    80,    81,   130,   131,    69,    70,    71,    72,
      73,    74,    75,     0,     0,    77,    78,    79,    80,    81
};

static const yytype_int16 yycheck[] =
{
      11,     9,     0,    39,     3,     4,    25,    18,    19,     7,
     108,    22,    25,    33,    34,   123,    31,    39,     0,    37,
      39,    36,    42,    43,    44,     7,    39,    38,    47,    37,
       3,     4,     5,     6,     7,     8,    56,   135,    33,    58,
      40,    41,    42,    43,   142,    58,    30,    31,    84,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    30,    31,   162,   163,   102,     9,    22,   177,
      24,    41,    83,    23,    24,    25,    26,    27,   176,    33,
     178,    25,    26,    27,    35,    39,    40,    41,    42,    43,
      44,    45,    46,    31,   192,     9,    34,   108,   196,     9,
      10,    11,    12,    13,   124,   125,    31,   118,    31,    34,
     121,    34,   123,    52,    53,    52,    53,   137,   138,   139,
     140,   141,     9,    34,   135,   123,   137,    16,    17,    18,
      19,   142,   152,     9,    23,    24,    25,    26,    27,    41,
      58,   161,     0,    38,   164,     3,     4,     5,     6,     7,
       8,   162,   163,    35,   174,    40,    41,    42,    43,    44,
     180,    46,    33,    38,    33,   176,   177,   178,    33,   189,
      33,   191,     3,     4,     5,     6,     7,     8,    33,    30,
      30,   192,    30,    30,    46,   196,    46,    33,    31,    31,
       9,    22,    58,    24,    30,    33,     7,    58,     7,    30,
      34,   121,    33,   137,    35,    36,    84,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    -1,    -1,    54,    55,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    22,    -1,    24,    23,    24,    25,
      26,    27,    30,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    -1,    -1,    54,    55,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    -1,    -1,    54,
      55,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    24,    14,    15,    16,    17,    18,    19,    20,
      21,    33,    23,    24,    25,    26,    27,    39,    40,    41,
      42,    43,    44,    45,    46,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    34,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    34,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    23,    24,    25,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    66,    67,    68,
      74,    86,     3,     4,     0,    67,    68,    30,    31,    25,
      39,    47,    58,    88,    92,    39,    92,    92,    37,    33,
      92,     9,    37,     9,     9,     9,    41,    34,     9,    35,
      89,    41,    22,    24,    33,    40,    41,    42,    43,    44,
      45,    46,    73,    87,    92,    73,    58,    38,    35,    92,
      44,    46,    87,    90,    91,    38,    73,    73,    73,    14,
      15,    16,    17,    18,    19,    20,    21,    23,    24,    25,
      26,    27,    73,    69,    31,    36,    34,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      30,    35,    48,    49,    50,    51,    54,    55,    70,    71,
      73,    74,    75,    76,    77,    80,    81,    82,    86,    92,
      91,    72,    87,    33,    33,    33,    33,    33,    36,    71,
      28,    29,    30,    30,    30,    52,    53,     9,    10,    11,
      12,    13,    70,    30,    74,    75,    83,    73,    73,    46,
      46,    71,    33,    73,    76,    92,    73,    73,    73,    73,
      36,    30,    34,    34,    31,    34,    31,    73,    73,    84,
      71,    71,    73,    78,    58,    79,    34,    30,    52,    53,
      31,    34,    73,    31,    34,    71,    75,    85,    71,    33,
      73,    58,    34,    73,    73,    71,    34,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    66,    66,    66,    67,    68,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    77,
      77,    77,    78,    78,    79,    79,    80,    80,    80,    81,
      81,    81,    82,    82,    83,    83,    83,    84,    84,    85,
      85,    86,    86,    86,    86,    86,    86,    86,    87,    87,
      87,    87,    88,    88,    89,    90,    90,    91,    91,    91,
      92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     2,     8,     0,
       1,     2,     1,     2,     2,     2,     1,     3,     4,     0,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     4,     2,     5,     3,     6,     3,     5,     4,     2,
       1,     3,     3,     3,     3,     2,     2,     3,     3,     6,
       4,     6,     1,     3,     2,     4,     1,     5,     9,     5,
       7,     3,    10,     6,     1,     1,     0,     1,     0,     1,
       0,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     4,     4,     3,     1,     3,     1,     1,     1,
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
        case 3:
#line 320 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[-1]);
        (yyval)->addChild((yyvsp[0]));
        // root->addChild($2);
    }
#line 1708 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 325 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[-1]);
        (yyval)->addChild((yyvsp[0]));
        // root->addChild($2);
    }
#line 1718 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 330 "src/main.y" /* yacc.c:1646  */
    {
        root = new TreeNode(0, NODE_PROG);
        root->addChild((yyvsp[0]));
        (yyval)=root;
    }
#line 1728 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 335 "src/main.y" /* yacc.c:1646  */
    {
        root = new TreeNode(0, NODE_PROG);
        root->addChild((yyvsp[0]));
        (yyval)=root;
    }
#line 1738 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 342 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1744 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 346 "src/main.y" /* yacc.c:1646  */
    {
        //cout<<"FUNC!!!\n";
        (yyval) = new TreeNode(0, NODE_FUNC); 
        (yyval)->addChild((yyvsp[-1]));
        
        //symboltable
        // cout<<"-------level: "<<cur_table->scope<<"-------"<<endl;
        // for(map<string,pair<string,int> >::iterator iter = cur_table->tmap.begin(); iter != cur_table->tmap.end(); iter++)
        // {
        //     cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
        // }cout<<endl;

    }
#line 1762 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 360 "src/main.y" /* yacc.c:1646  */
    {
            
            SymTable* t=new SymTable(++scopeid);
            if(scopeid!=0)//不是第一级作用域
            {
                t->father=cur_table;
                cur_table=t;
                n_top=1;
            }
        }
#line 1777 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 372 "src/main.y" /* yacc.c:1646  */
    {/*****增加头节点，一个block************/
        (yyval) = new TreeNode(lineno, NODE_BLOCK);
        (yyval)->addChild((yyvsp[0]));
    }
#line 1786 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 377 "src/main.y" /* yacc.c:1646  */
    {   
        (yyval)=(yyvsp[-1]);
        (yyval)->addChild((yyvsp[0]));
    }
#line 1795 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 384 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stmt_type = STMT_SKIP;}
#line 1801 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 385 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1807 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 386 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1813 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 387 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1819 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 388 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1825 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 389 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_STMT); 
        (yyval)->stmt_type = STMT_RETURN;
        (yyval)->addChild((yyvsp[-1]));
    }
#line 1835 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 394 "src/main.y" /* yacc.c:1646  */
    {
        // //语句加一个总的根结点，解决问题???????
        // $$ = new TreeNode($3->lineno, NODE_BLOCK);//NODE_STMT);
        // $$->stmt_type=STMT_BLOCK;
        // $$->addChild($3);
        (yyval) = (yyvsp[-1]);

        
        cur_table=cur_table->father;

        //-----------------符号表 版本2--------------------
        /* cout<<-------level:<<cur_table->scope<<-------<<endl;*/
        // for(SymTable* t=cur_table;t!=nullptr;t=t->father)
        // {
        //     cout<<"level"<<t->scope<<":"<<endl;
        //     for(map<string,pair<string,int> >::iterator iter = t->tmap.begin(); iter != t->tmap.end(); iter++)
        //     {
        //         cout<<iter->first<<":"<<iter->second.first<<"  "<<iter->second.second<<endl;
        //     }
        // }   
        // cout<<endl;
        //-------------------------
    }
#line 1863 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 418 "src/main.y" /* yacc.c:1646  */
    {
            //-------------符号表 版本2------------
            SymTable* t=new SymTable(++scopeid);
            t->father=cur_table;
            cur_table=t;
            n_top=1;
            //----------------------------
        }
#line 1876 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 431 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
        //$$->nodeType=NODE_EXPR;

        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID((yyvsp[0]));
    }
#line 1888 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 438 "src/main.y" /* yacc.c:1646  */
    {
        //注意这部分的int char bool类型常量在词法分析的.l文件就已经定义初始化树结点了！！！
        (yyval) = (yyvsp[0]);
        (yyval)->val_type_flag='i';
    }
#line 1898 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 443 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
        (yyval)->val_type_flag='c';
    }
#line 1907 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 447 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
        (yyval)->val_type_flag='s';
    }
#line 1916 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 451 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[0]);
        (yyval)->val_type_flag='b';
    }
#line 1925 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 455 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[-1]);
        (yyval)->val_type_flag=(yyvsp[-1])->val_type_flag;//??----------
        }
#line 1934 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 460 "src/main.y" /* yacc.c:1646  */
    {

        //运算的类型就先规定为整形，只是支持int
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_ADD;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));

        (yyval)->val_type_flag=(yyvsp[-2])->val_type_flag;
    /*********************check_CAL_math*********************************************/
        check_CAL_math((yyval));
        }
#line 1950 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 471 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_SUB;
        
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        
        (yyval)->val_type_flag=(yyvsp[-2])->val_type_flag;

        check_CAL_math((yyval));
        }
#line 1965 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 481 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_MUL;
        
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        
        (yyval)->val_type_flag=(yyvsp[-2])->val_type_flag;

        check_CAL_math((yyval));
        }
#line 1980 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 491 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_DIV;
        
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        
        (yyval)->val_type_flag=(yyvsp[-2])->val_type_flag;

        check_CAL_math((yyval));
        }
#line 1995 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 501 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_MOD;
        
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        
        (yyval)->val_type_flag=(yyvsp[-2])->val_type_flag;

        check_CAL_math((yyval));
    }
#line 2010 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 511 "src/main.y" /* yacc.c:1646  */
    {
        //$2就是expr
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_NEG;
       
        (yyval)->addChild((yyvsp[0]));
        
        (yyval)->val_type_flag=(yyvsp[-1])->val_type_flag;

        check_CAL_math_negtivenum((yyval));
    }
#line 2025 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 522 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_AND;
        
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));

        (yyval)->val_type_flag='b';//??----------

        check_CAL_logical((yyval));
    }
#line 2040 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 532 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_OR;

        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------

        check_CAL_logical((yyval));
    }
#line 2054 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 541 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_NOT;

        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------

        check_CAL_logical_not((yyval));
    }
#line 2067 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 549 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_LESS_EQ;

        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------

        check_CAL_logical((yyval));
    }
#line 2081 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 558 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_LESS_THAN;

        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------

        check_CAL_logical((yyval));
    }
#line 2095 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 567 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_MORE_EQ;

        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------

        check_CAL_logical((yyval));
    }
#line 2109 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 576 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_MORE_THAN;

        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------

        check_CAL_logical((yyval));
    }
#line 2123 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 585 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_NOT_EQ;

        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------

        check_CAL_logical((yyval));
    }
#line 2137 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 594 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_EXPR); (yyval)->op_type = OP_EQ;

        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        (yyval)->val_type_flag='b';//??----------

        check_CAL_logical((yyval));
    }
#line 2151 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 607 "src/main.y" /* yacc.c:1646  */
    { 
        // declare and init    int a = 1;
        (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL_V;

        (yyval)->addChild((yyvsp[-3]));
        (yyvsp[-3])->addChild((yyvsp[-2]));

        (yyvsp[-2])->val_type_flag=ValType_name[(yyvsp[-3])->type->type][0];// i b c s 
        // cout<<$2->val_type_flag<<endl;

        /*************************TYPE__CHECK————TYPE__TRANS************************************/
        //类型转换！！！！！！！！？？？？？？？
        type_trans((yyvsp[0]));
        (yyvsp[-2])->addChild((yyvsp[0])); 

        check_decl((yyvsp[-2]));
        check_decl_type((yyvsp[0]));
    }
#line 2175 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 626 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL_V;

        (yyval)->addChild((yyvsp[-1]));
        (yyvsp[-1])->addChild((yyvsp[0]));

        (yyvsp[0])->val_type_flag=ValType_name[(yyvsp[-1])->type->type][0];

        /*************************TYPE__CHECK************************************/
        check_decl((yyvsp[0]));
    }
#line 2192 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 638 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[-4]);
        (yyval)->child->addChild((yyvsp[-2]));
        
        (yyvsp[-2])->val_type_flag=ValType_name[(yyvsp[-2])->father->type->type][0];
        /*************************TYPE__CHECK————TYPE__TRANS************************************/
        type_trans((yyvsp[0]));
        (yyvsp[-2])->addChild((yyvsp[0]));

        check_decl((yyvsp[-2]));
        check_decl_type((yyvsp[0]));
    }
#line 2209 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 650 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = (yyvsp[-2]);
        (yyval)->child->addChild((yyvsp[0]));

        (yyvsp[0])->val_type_flag=ValType_name[(yyvsp[0])->father->type->type][0];
        /*************************TYPE__CHECK************************************/
        check_decl((yyvsp[0]));
    }
#line 2222 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 660 "src/main.y" /* yacc.c:1646  */
    {  
        // declare and init
        (yyval) = new TreeNode((yyvsp[-5])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL_P;
        (yyval)->addChild((yyvsp[-5]));
        (yyvsp[-5])->addChild((yyvsp[-3]));
        (yyvsp[-3])->addChild((yyvsp[0])); 

        //$3->val_type_flag=ValType_name[$3->father->type->type][0];

        /*************************TYPE__CHECK************************************/
        check_decl((yyvsp[-3]));
    }
#line 2240 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 673 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL_P;
        (yyval)->addChild((yyvsp[-2]));
        (yyvsp[-2])->addChild((yyvsp[0]));

        //$3->val_type_flag=ValType_name[$3->father->type->type][0];

        /*************************TYPE__CHECK************************************/
        check_decl((yyvsp[0]));
    }
#line 2256 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 684 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-4])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL_R;
        (yyval)->addChild((yyvsp[-4]));
        (yyvsp[-4])->addChild((yyvsp[-2]));
        (yyvsp[-4])->addChild((yyvsp[0]));

        //$3->val_type_flag=ValType_name[$3->father->type->type][0];

        /*************************TYPE__CHECK************************************/
        check_decl((yyvsp[-2]));

        if(cur_table->tmap.count((yyvsp[0])->var_name)==0)
        {
            cout <<(yyval)->lineno<<" : 引用的变量未定义！！！"<<endl;
        }
    }
#line 2278 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 703 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL_A;
        (yyval)->addChild((yyvsp[-3]));
        (yyvsp[-3])->addChild((yyvsp[-2]));
        (yyvsp[-3])->addChild((yyvsp[0]));

        //$2->val_type_flag=ValType_name[$2->father->type->type][0];
        /*************************TYPE__CHECK************************************/
        check_decl((yyvsp[-2]));

    }
#line 2295 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 715 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DECL_A;

        (yyval)->addChild((yyvsp[-1]));
        (yyvsp[-1])->addChild((yyvsp[0]));

        /*************************TYPE__CHECK************************************/
        check_decl((yyvsp[0]));

    }
#line 2311 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 729 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2317 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 731 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_ADD_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID((yyvsp[-2]));
    }
#line 2330 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 739 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_SUB_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID((yyvsp[-2]));
        check_assign_type((yyvsp[-2]));
    }
#line 2344 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 748 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_MUL_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID((yyvsp[-2]));
        check_assign_type((yyvsp[-2]));
    }
#line 2358 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 757 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_DIV_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));
        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID((yyvsp[-2]));
        check_assign_type((yyvsp[-2]));
    }
#line 2372 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 766 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stmt_type = STMT_SELF_ADD_ASSIGN;

        (yyval)->addChild((yyvsp[-1]));
        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID((yyvsp[-1]));
        }
#line 2384 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 773 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stmt_type = STMT_SELF_SUB_ASSIGN;

        (yyval)->addChild((yyvsp[-1]));
        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID((yyvsp[-1]));
        }
#line 2396 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 785 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));

        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID((yyvsp[-2]));
        check_assign_type((yyvsp[-2]));
        // cout<<$1->val_type_flag<<endl;
        // cout<<$3->val_type_flag<<endl;
        
    }
#line 2414 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 798 "src/main.y" /* yacc.c:1646  */
    {//a=b=3;!!!!
        (yyval) = new TreeNode(lineno, NODE_STMT);
        (yyval)->stmt_type = STMT_ASSIGN;
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));

        /******************TYPE__CHECK----ID_CHECK****************************/
        check_ID((yyvsp[-2]));
        check_assign_type((yyvsp[-2]));
        // cout<<$1->val_type_flag<<endl;
        // cout<<$3->val_type_flag<<endl;
        
    }
#line 2432 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 814 "src/main.y" /* yacc.c:1646  */
    {
            (yyval) = new TreeNode(lineno, NODE_STMT);
            (yyval)->stmt_type=STMT_PRINTF;
            (yyval)->addChild((yyvsp[-3]));
            (yyval)->addChild((yyvsp[-1]));
        }
#line 2443 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 820 "src/main.y" /* yacc.c:1646  */
    {
            (yyval) = new TreeNode(lineno, NODE_STMT);
            (yyval)->stmt_type=STMT_PRINTF;
            (yyval)->addChild((yyvsp[-1]));
        }
#line 2453 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 826 "src/main.y" /* yacc.c:1646  */
    {
            (yyval) = new TreeNode(lineno, NODE_STMT);
            (yyval)->stmt_type=STMT_SCANF;
            (yyval)->addChild((yyvsp[-3]));
            (yyval)->addChild((yyvsp[-1]));
        }
#line 2464 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 834 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_BLOCK);
        (yyval)->addChild((yyvsp[0]));
    }
#line 2473 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 838 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)->addChild((yyvsp[0]));

    }
#line 2482 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 844 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode(lineno, NODE_BLOCK);
        (yyval)->addChild((yyvsp[0]));
    }
#line 2491 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 848 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)->addChild((yyvsp[0]));

    }
#line 2500 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 854 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2506 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 855 "src/main.y" /* yacc.c:1646  */
    {
        //while expr stmt
        (yyval) = new TreeNode((yyvsp[-2])->lineno, NODE_STMT);
        (yyval)->stmt_type=STMT_WHILE;

        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));

        check_control_stmt((yyval));
    }
#line 2521 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 866 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[-6])->lineno, NODE_STMT);
        (yyval)->stmt_type=STMT_FOR;
        (yyval)->addChild((yyvsp[-6]));
        (yyval)->addChild((yyvsp[-4]));
        (yyval)->addChild((yyvsp[-2]));
        (yyval)->addChild((yyvsp[0]));

        check_for_stmt((yyval));
        }
#line 2536 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 879 "src/main.y" /* yacc.c:1646  */
    {
        // cout<<"if !!"<<endl;
        //这里不能用$1,要么直接lineno 要么$3->lineno

        //if ( expr ) stmt 
        (yyval) = new TreeNode((yyvsp[-4])->lineno, NODE_STMT);
        (yyval)->stmt_type=STMT_IF;
        (yyval)->addChild((yyvsp[-2]));

        if((yyvsp[0])->nodeType!=NODE_BLOCK)
        {
            TreeNode* t = new TreeNode((yyvsp[0])->lineno, NODE_BLOCK);
            t->addChild((yyvsp[0]));
            (yyval)->addChild(t);
        }
        else
            (yyval)->addChild((yyvsp[0]));

        /************************TYPE_CHECK*****************************/
        check_control_stmt((yyval));
    }
#line 2562 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 900 "src/main.y" /* yacc.c:1646  */
    {
        //if  expr  stmt1  stmt2
        (yyval) = new TreeNode((yyvsp[-6])->lineno, NODE_STMT);
        (yyval)->stmt_type=STMT_IF_ELSE;

        (yyval)->addChild((yyvsp[-4]));
        if((yyvsp[-2])->nodeType!=NODE_BLOCK)
        {
            TreeNode* t = new TreeNode((yyvsp[-2])->lineno, NODE_BLOCK);
            t->addChild((yyvsp[-2]));
            (yyval)->addChild(t);
        }
        else
            (yyval)->addChild((yyvsp[-2]));
        if((yyvsp[0])->nodeType!=NODE_BLOCK)
        {
            TreeNode* t = new TreeNode((yyvsp[0])->lineno, NODE_BLOCK);
            t->addChild((yyvsp[0]));
            (yyval)->addChild(t);
        }
        else 
            (yyval)->addChild((yyvsp[0]));

        check_control_stmt((yyval));
    }
#line 2592 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 925 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[-2]);
        //给else也加个头节点
        TreeNode* else_block = new TreeNode((yyvsp[0])->lineno, NODE_BLOCK);
        (yyval)->addChild(else_block);
        if((yyvsp[0])->nodeType!=NODE_BLOCK)
        {
            TreeNode* t = new TreeNode((yyvsp[0])->lineno, NODE_BLOCK);
            t->addChild((yyvsp[0]));
            else_block->addChild(t);
        }
        else
            else_block->addChild((yyvsp[0]));
    }
#line 2611 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 941 "src/main.y" /* yacc.c:1646  */
    {
            (yyval) = new TreeNode((yyvsp[-7])->lineno, NODE_STMT);
            (yyval)->stmt_type=STMT_IF_ELSE_IF;

            (yyval)->addChild((yyvsp[-7]));
            if((yyvsp[-5])->nodeType!=NODE_BLOCK)
            {
                TreeNode* t = new TreeNode((yyvsp[-5])->lineno, NODE_BLOCK);
                t->addChild((yyvsp[-5]));
                (yyvsp[-7])->addChild(t);
            }
            else
                (yyvsp[-7])->addChild((yyvsp[-5]));

            (yyval)->addChild((yyvsp[-2]));
            if((yyvsp[0])->nodeType!=NODE_BLOCK)
            {
                TreeNode* t = new TreeNode((yyvsp[0])->lineno, NODE_BLOCK);
                t->addChild((yyvsp[0]));
                (yyvsp[-2])->addChild(t);
            }
            else
                (yyvsp[-2])->addChild((yyvsp[0]));
        }
#line 2640 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 965 "src/main.y" /* yacc.c:1646  */
    {
            (yyval)=(yyvsp[-5]);

            (yyval)->addChild((yyvsp[-2]));

            if((yyvsp[0])->nodeType!=NODE_BLOCK)
            {
                TreeNode* t = new TreeNode((yyvsp[0])->lineno, NODE_BLOCK);
                t->addChild((yyvsp[0]));
                (yyvsp[-2])->addChild(t);
            }
            else
                (yyvsp[-2])->addChild((yyvsp[0]));

        }
#line 2660 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 985 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2666 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 985 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2672 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 985 "src/main.y" /* yacc.c:1646  */
    {(yyval)=new TreeNode(lineno,NODE_STMT);(yyval)->stmt_type=STMT_SKIP;}
#line 2678 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 987 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2684 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 987 "src/main.y" /* yacc.c:1646  */
    {(yyval)=new TreeNode(lineno,NODE_STMT);(yyval)->stmt_type=STMT_SKIP;}
#line 2690 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 989 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2696 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 989 "src/main.y" /* yacc.c:1646  */
    {(yyval)=new TreeNode(lineno,NODE_STMT);(yyval)->stmt_type=STMT_SKIP;}
#line 2702 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 992 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_INT;}
#line 2708 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 993 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CHAR;}
#line 2714 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 994 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_BOOL;}
#line 2720 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 995 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_STRING;}
#line 2726 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 996 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_VOID;}
#line 2732 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 997 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CONST_INT;}
#line 2738 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 998 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_CONST_CHAR;}
#line 2744 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1003 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2750 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1004 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2756 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1005 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2762 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1006 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2768 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1010 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[-3]);
        (yyval)->nodeType=NODE_ARR;
        (yyval)->addChild((yyvsp[-1]));
    }
#line 2778 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1015 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)=(yyvsp[-3]);
        (yyval)->addChild((yyvsp[-1]));
    }
#line 2787 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1021 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2793 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1024 "src/main.y" /* yacc.c:1646  */
    {
        (yyval) = new TreeNode((yyvsp[0])->lineno, NODE_STMT);//???
        (yyval)->addChild((yyvsp[0]));

    }
#line 2803 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1029 "src/main.y" /* yacc.c:1646  */
    {
        (yyval)->addChild((yyvsp[0]));
    }
#line 2811 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1035 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2817 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1036 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2823 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1037 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2829 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1042 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2835 "src/main.tab.cpp" /* yacc.c:1646  */
    break;


#line 2839 "src/main.tab.cpp" /* yacc.c:1646  */
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
#line 1047 "src/main.y" /* yacc.c:1906  */


int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
