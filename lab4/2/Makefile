.PHONY:reg_to_dfa,clean
reg_to_dfa:reg_to_dfa.c 
	g++ -Wall -g reg_to_dfa.c -o reg_to_dfa.out
	./reg_to_dfa.out <input >output
	cat output
reg_to_dfa.c:reg_to_dfa.y
	yacc -d reg_to_dfa.y -o reg_to_dfa.c
clean:
	rm *.out
