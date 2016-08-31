a6p1: Assign06P1.o
	g++ Assign06P1.o -o a6p1
Assign06P1.o: Assign06P1.cpp
	g++ -Wall -ansi -pedantic -c Assign06P1.cpp

test:
	./a6p1 > a6p1test.out
clean:
	@rm -rf Assign06P1.o
cleanall:
	@rm -rf Assign06P1.o a6p1
