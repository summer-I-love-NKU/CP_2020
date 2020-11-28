.PHONY:clean
w0:w0.o
	gcc -Wall -g w0.o -o w0
w0.o:w0.c 
	gcc -Wall -g -c w0.c -o w0.o
w0.c:w0.y
	yacc -d w0.y -o w0.c
clean:
	rm *.o w0
