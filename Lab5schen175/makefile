
# Here's the flag for C++11 support and a flag asking to be warned about
# everything. 
FLAGS = -Wall -std=c++11

all: Lab5 TSorterTester

Lab5: Lab5.o Sorter.o
	g++ $(FLAGS) Lab5.o Sorter.o -o Lab5

Sorter.o: Sorter.cpp Sorter.h
	g++ $(FLAGS) -c Sorter.cpp -o Sorter.o

Lab5.o: Lab5.cpp Sorter.h
	g++ $(FLAGS) -c Lab5.cpp -o Lab5.o

TSorterTester: TSorterTester.o 
	g++ $(FLAGS) TSorterTester.o -o TSorterTester

#TSorter.h: 
#	g++ $(FLAGS) -c TSorter.h TSorter.o

TSorterTester.o: TSorterTester.cpp
	g++ $(FLAGS) -c TSorterTester.cpp -o TSorterTester.o

clean:
	rm -f *.o Lab5 TSorterTester

