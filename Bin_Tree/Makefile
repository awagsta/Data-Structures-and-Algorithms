a7: btNode.o Assign07.o
	g++ btNode.o Assign07.o -o a7
btNode.o: btNode.cpp btNode.h
	g++ -Wall -ansi -pedantic -c btNode.cpp
Assign07.o: Assign07.cpp btNode.h
	g++ -Wall -ansi -pedantic -c Assign07.cpp
nt:
	@rm -rf *.h *.cpp *o *.out a7
clean:
	@rm -rf btNode.o Assign07.o
cleanall:
	@rm -rf btNode.o Assign07.o a7
