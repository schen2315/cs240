#

all: link

#
#
link:	compile
	g++ voter.o voterDatabase.o main.o -o Voter
#
#
compile:	
	g++ -c voter.cpp voterDatabase.cpp main.cpp -std=c++11

#
#
clean:
	rm -f *.o *~ Voter 