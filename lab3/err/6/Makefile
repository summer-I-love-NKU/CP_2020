.PHONY:clean
# w6:w6.c
# 	g++ -Wall -g -std=c++17 w6.o -o w6
w6:w6.c 
	g++ -Wall -g -std=c++17 w6.c -o w6
w6.c:w6.y
	yacc -d w6.y -o w6.c
clean:
	rm *.o w6
# add.o:add.c add.h
#     gcc -Wall -g -c add.c -o add.o
# sub.o:sub.c sub.h
#     gcc -Wall -g -c sub.c -o sub.o
# print.o:print.c print.h
#     gcc -Wall -g -c print.c -o print.o
