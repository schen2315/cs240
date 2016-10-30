#include <vector>

template <typename ElementType>
class TSorter {
private:
	std::vector<ElementType> array;
	//vector::size() -> numElements
	//vector::capacity() -> capacity
	void swap(int i, int j);
public:
	TSorter();
	TSorter(unsigned int initialCapacity);
	~TSorter();

	void clear();	//call vector<ElementType>::clear();
	bool insert(ElementType value);

	void show(unsigned int n, unsigned int k);
	void shuffle();

	void insertionSortI();
	void selectionSortI();
	void bubbleSortI();     
	void insertionSortR(); 
	void selectionSortR();	
	void bubbleSortR(); 

	void insertionSortRHelper(int numElements, int index);
	void insertionSortRSort(int index);

	void selectionSortRHelper(int index);
	int selectionSortRMax(int currentMax, int index);

	void bubbleSortRHelper(int index);
	void bubbleSortRTraverse(int index, int end); 
};

#include "TSorter.cpp"