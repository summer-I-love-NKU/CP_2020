/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
