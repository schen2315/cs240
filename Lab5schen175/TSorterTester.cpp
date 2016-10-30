#include <iostream>
#include <cstdlib>
#include <math.h>
#include "TSorter.h"

#define DEFAULT_NUMVALUES 10
#define MAX_NUMVALUES 1000
#define MIN_NUMVALUES 1

int main(int argc, char **argv) {	
	unsigned int numValues = DEFAULT_NUMVALUES; 
	if (argc > 1)
	  numValues = atoi(argv[1]);  
	if ((numValues < MIN_NUMVALUES) || (numValues > MAX_NUMVALUES)) {
	  std::cerr << "Specify numValues in the range [" << MIN_NUMVALUES; 
	  std::cerr << ", " << MAX_NUMVALUES << std::endl; 
	  std::cerr << "\nUsage: " << argv[0] << " {numValues}" << std::endl; 
	}
	if (argc > 2) 
	  std::cerr << "Ignoring extra command line arguments." << std::endl; 
	std::cout << std::endl << "Generating " << numValues << " values for sorting." << std::endl; 	
	TSorter<int> s;
	TSorter<char> s0;
	TSorter<double> s1;

	srand(time(NULL));
	for(int i=0; i < numValues; i++) {
		int val = rand() % 100;
		s.insert(val);
	}
	for(int i=0; i < numValues; i++) {
		char ch = 'a' + (int)(rand() % 26);
		s0.insert(ch);
	}
	for(int i=0; i < numValues; i++) {
		double d = ((double)rand())/ 41;
		d = fmod(d, 100);
		s1.insert(d);
	}
	std::cout << "0th Initial array: ";
	s.show(numValues, 10); 


	std::cout << "After iterative Insertion Sort:" << std::endl;
	s.insertionSortI();
	s.show(numValues, 10);
	
	s.shuffle(); 
	std::cout << "Shuffled: "; 
	s.show(numValues, 10); 


	std::cout << "After iterative Selection Sort:" << std::endl;
	s.selectionSortI();
	s.show(numValues,10);

	s.shuffle(); 
	std::cout << "Shuffled: "; 
	s.show(numValues, 10); 


	std::cout << "After iterative Bubble Sort:" << std::endl;
	s.bubbleSortI();
	s.show(numValues, 10); 
	
	s.shuffle(); 
	std::cout << "Shuffled: "; 
	s.show(numValues, 10); 


	std::cout << "After recursive Insertion Sort:" << std::endl;
	s.insertionSortR();
	s.show(numValues, 10); 
	
	s.shuffle(); 
	std::cout << "Shuffled: "; 
	s.show(numValues, 10); 


	std::cout << "After recursive Selection Sort:" << std::endl;
	s.selectionSortR();
	s.show(25, 10); 

	s.shuffle(); 
	std::cout << "Shuffled: "; 
	s.show(25, 10); 


	std::cout << "After recursive Bubble Sort:" << std::endl;
	s.bubbleSortR();
	s.show(25, 10);
	
	std::cout << "1st Initial array: ";
	s0.show(numValues, 10); 


	std::cout << "After iterative Insertion Sort:" << std::endl;
	s0.insertionSortI();
	s0.show(numValues, 10);
	
	s0.shuffle(); 
	std::cout << "Shuffled: "; 
	s0.show(numValues, 10); 


	std::cout << "After iterative Selection Sort:" << std::endl;
	s0.selectionSortI();
	s0.show(numValues,10);

	s0.shuffle(); 
	std::cout << "Shuffled: "; 
	s0.show(numValues, 10); 


	std::cout << "After iterative Bubble Sort:" << std::endl;
	s0.bubbleSortI();
	s0.show(numValues, 10); 
	
	s0.shuffle(); 
	std::cout << "Shuffled: "; 
	s0.show(numValues, 10); 


	std::cout << "After recursive Insertion Sort:" << std::endl;
	s0.insertionSortR();
	s0.show(numValues, 10); 
	
	s0.shuffle(); 
	std::cout << "Shuffled: "; 
	s0.show(numValues, 10); 


	std::cout << "After recursive Selection Sort:" << std::endl;
	s0.selectionSortR();
	s0.show(25, 10); 

	s0.shuffle(); 
	std::cout << "Shuffled: "; 
	s0.show(25, 10); 


	std::cout << "After recursive Bubble Sort:" << std::endl;
	s0.bubbleSortR();
	s0.show(25, 10);
	




	std::cout << "2st Initial array: ";
	s1.show(numValues, 10); 


	std::cout << "After iterative Insertion Sort:" << std::endl;
	s1.insertionSortI();
	s1.show(numValues, 10);

	s1.shuffle(); 
	std::cout << "Shuffled: "; 
	s1.show(numValues, 10); 


	std::cout << "After iterative Selection Sort:" << std::endl;
	s1.selectionSortI();
	s1.show(numValues,10);

	s1.shuffle(); 
	std::cout << "Shuffled: "; 
	s1.show(numValues, 10); 


	std::cout << "After iterative Bubble Sort:" << std::endl;
	s1.bubbleSortI();
	s1.show(numValues, 10); 

	s1.shuffle(); 
	std::cout << "Shuffled: "; 
	s1.show(numValues, 10); 
	

	std::cout << "After recursive Insertion Sort:" << std::endl;
	s1.insertionSortR();
	s1.show(numValues, 10); 

	s1.shuffle(); 
	std::cout << "Shuffled: "; 
	s1.show(numValues, 10); 


	std::cout << "After recursive Selection Sort:" << std::endl;
	s1.selectionSortR();
	s1.show(25, 10); 

	s1.shuffle(); 
	std::cout << "Shuffled: "; 
	s1.show(25, 10); 


	std::cout << "After recursive Bubble Sort:" << std::endl;
	s1.bubbleSortR();
	s1.show(25, 10); 
	
	return 0;
}