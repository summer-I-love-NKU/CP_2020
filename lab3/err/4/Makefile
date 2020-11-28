.PHONY:clean
w4:w4.o
	g++ -Wall -g -std=c++17 w4.o -o w4
w4.o:w4.c 
	g++ -Wall -g -std=c++17 -c w4.c -o w4.o
w4.c:w4.y
	yacc -d w4.y -o w4.c
clean:
	rm *.o w4
# add.o:add.c add.h
#     gcc -Wall -g -c add.c -o add.o
# sub.o:sub.c sub.h
#     gcc -Wall -g -c sub.c -o sub.o
# print.o:print.c print.h
#     gcc -Wall -g -c print.c -o print.o
