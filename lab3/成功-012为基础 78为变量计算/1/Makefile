.PHONY:clean
w1:w1.o
	gcc -Wall -g w1.o -o w1
w1.o:w1.c 
	gcc -Wall -g -c w1.c -o w1.o
w1.c:w1.y
	yacc -d w1.y -o w1.c
clean:
	rm *.o w1
# add.o:add.c add.h
#     gcc -Wall -g -c add.c -o add.o
# sub.o:sub.c sub.h
#     gcc -Wall -g -c sub.c -o sub.o
# print.o:print.c print.h
#     gcc -Wall -g -c print.c -o print.o
