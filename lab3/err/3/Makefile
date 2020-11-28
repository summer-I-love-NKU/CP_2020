.PHONY:clean
w3:w3.o
	g++ -Wall -g -std=c++17 w3.o -o w3
w3.o:w3.c 
	g++ -Wall -g -std=c++17 -c w3.c -o w3.o
w3.c:w3.y
	yacc -d w3.y -o w3.c
clean:
	rm *.o w3
# add.o:add.c add.h
#     gcc -Wall -g -c add.c -o add.o
# sub.o:sub.c sub.h
#     gcc -Wall -g -c sub.c -o sub.o
# print.o:print.c print.h
#     gcc -Wall -g -c print.c -o print.o
