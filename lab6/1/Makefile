CC := g++
CFLAGS := -Wall -Wextra -std=c++11 -fpermissive# without debug
# TARGET := ./bin/main    

all: run

src/main.l.yy.c: src/main.l
	 flex --noyywrap -o src/main.l.yy.cpp  src/main.l 

src/main.tab.c: src/main.y
	bison -o src/main.tab.cpp --defines=src/main.tab.h -v src/main.y

src/pch.h.gch: src/pch.h
	g++ -x c++-header -std=c++11 -o src/pch.h.gch -c src/pch.h

lex: src/main.l.yy.c

yacc: src/main.tab.c

main: src/pch.h.gch
	$(CC) $(CFLAGS) $(shell ls ./src/*.cpp) -o ./tests/main.out

.PHONY: all clean main run lex yacc test debug link testscope asm nasm example-code out

run: lex yacc main test


clean:
	# rm -f src/*.output src/main.l.yy.cpp src/main.tab.cpp src/main.tab.h src/main.output src/pch.h.gch $(TARGET) *.o 
	rm -f src/*.output src/main.l.yy.cpp src/main.tab.cpp src/main.tab.h src/main.output src/pch.h.gch *.o 

test: 
	./tests/main.out <./tests/test.c  >./tests/result.S
	cat ./tests/result.S
	cp ./tests/main.out ../lab6_test
	gcc -m32 ./tests/result.S -o ./tests/result.out
	././tests/result.out
