.PHONY: all clean main run test debug
all: run

# `main.y`语法分析文件 
# 通过bison编译生成`main.tab.hh` `main.tab.cc` 
# **注意为了生成头文件需要在文件中加入`%option defines`** 
# 在文件中引用`common.h`来使用自定义语法树结点方法 
# 加入`yylex()`函数声明来允许调用词法分析方法 
# 生成的整个过程通过`yyparse()`进行调用
main.tab.cc: main.y
	bison -o main.tab.cc -v main.y

# `main.l`词法分析文件 通过flex编译后生成`lex.yy.cc` 
# 在文件中引用`common.h`来使用自定义语法树结点的方法 
# 引用`main.tab.hh`来使用语法分析过程中声明的token 
# 配合语法分析器使用 生成的整个过程通过`yylex()`进行调用
lex.yy.cc: main.l
	flex -o lex.yy.cc main.l

main: lex.yy.cc main.tab.cc
	g++ $(shell ls *.cpp *.cc) -o main.out

run: main
	./main.out
test:main
	for file in $(basename $(shell find test/*.c)); \
	do \
		./main.out <$$file.c >$$file.res; \
	done
clean:
	rm -f *.output *.yy.* *.tab.* *.out test/*.res