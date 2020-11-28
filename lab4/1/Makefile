.PHONY:w1,clean
w1:
	flex -+ w1.l
	g++ -Wall -fpermissive lex.yy.cc -o w1.out
	./w1.out <input >output
	cat output
clean:
	rm *.out
# add.o:add.c add.h
#     gcc -Wall -g -c add.c -o add.o
# sub.o:sub.c sub.h
#     gcc -Wall -g -c sub.c -o sub.o
# print.o:print.c print.h
#     gcc -Wall -g -c print.c -o print.o
