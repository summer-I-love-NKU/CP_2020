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
