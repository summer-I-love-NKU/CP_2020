.PHONY:clean
w5:w5.o
	g++ -Wall -g -std=c++17 w5.o -o w5
w5.o:w5.c 
	g++ -Wall -g -std=c++17 -c w5.c -o w5.o
w5.c:w5.y
	yacc -d w5.y -o w5.c
clean:
	rm *.o w5
# add.o:add.c add.h
#     gcc -Wall -g -c add.c -o add.o
# sub.o:sub.c sub.h
#     gcc -Wall -g -c sub.c -o sub.o
# print.o:print.c print.h
#     gcc -Wall -g -c print.c -o print.o
