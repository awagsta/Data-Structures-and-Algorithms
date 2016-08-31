llcp: llcpImp.o Assign06P2.o
	g++ llcpImp.o Assign06P2.o -o a6p2
llcpImp.o: llcpImp.cpp llcpInt.h
	g++ -Wall -ansi -pedantic -c llcpImp.cpp
Assign06P2.o: Assign06P2.cpp llcpInt.h
	g++ -Wall -ansi -pedantic -c Assign06P2.cpp

go:
	./a6p2
gogo:
	./a6p2 > a6p2test.out

nt:
	@rm -rf llcpImp.o Assign06P2.o a6p2 a6p2test.out
clean:
	@rm -rf llcpImp.o Assign06P2.o
cleanall:
	@rm -rf llcpImp.o Assign06P2.o a6p2
