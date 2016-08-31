a8: Assign08Test.o DPQueue.o
	g++ Assign08Test.o DPQueue.o -o a8
Assign08Test.o: Assign08Test.cpp DPQueue.h
	g++ -Wall -ansi -pedantic -c Assign08Test.cpp
DPQueue.o: DPQueue.cpp DPQueue.h
	g++ -Wall -ansi -pedantic -c DPQueue.cpp

clean:
	@rm -rf Assign08Test.o DPQueue.o

cleanall:
	@rm -rf Assign08Test.o DPQueue.o a8
