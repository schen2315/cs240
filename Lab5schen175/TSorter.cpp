template<typename ElementType>
TSorter<ElementType>::TSorter() {
	//vector gets automatically instantiated anyway
	// std::cout << "current Capacity " << array.capacity() << std::endl;
	// std::cout << "current size " << array.size() << std::endl;
}
template<typename ElementType>
TSorter<ElementType>::TSorter(unsigned int initialCapacity) {
	//call reserve
	array.reserve(initialCapacity);
	// std::cout << "current Capacity " << array.capacity() << std::endl;
	// std::cout << "current size " << array.size() << std::endl;
}
template<typename ElementType>
TSorter<ElementType>::~TSorter() {
	//nothing to delete	
}

template<typename ElementType>
void TSorter<ElementType>::swap(int i, int j) {
	ElementType temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	return;
}
template<typename ElementType>
void TSorter<ElementType>::clear() {
	//std::cout << "Entering function TSorter::clear()" << std::endl;
	array.clear();
	return;
}

template<typename ElementType>
bool TSorter<ElementType>::insert(ElementType value) {
	array.push_back(value);
	return true;
}

template<typename ElementType>
void TSorter<ElementType>::show(unsigned int n, unsigned int k) {
	//std::cout << "Entering function TSorter::show(unsigned int, unsigned int)" << std::endl;
	unsigned int toShow = ((n < array.size()) ? n : array.size());
	typename std::vector<ElementType>::iterator it;
	for(it = array.begin(); (it - array.begin()) < toShow; it++) {
		if(!((it - array.begin())%k)) std::cout << std::endl;
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return;
}

template<typename ElementType>
void TSorter<ElementType>::shuffle() {
	unsigned int j;
	typename std::vector<ElementType>::iterator it;
	for(it = array.begin(), it++; (it - array.begin()) < array.size(); it++) {
		j = rand() % (it - array.begin());
		swap(it - array.begin(), j);
	}
	return;
}

//Sorter methods
template<typename ElementType>
void TSorter<ElementType>::insertionSortI() {
	//std::cout << "Sorter::insertionSortI()" << std::endl;
	typename std::vector<ElementType>::iterator it;
	for(it = array.begin(), it++; it != array.end(); it++) {
	  typename std::vector<ElementType>::iterator cur = it;
	  while(cur - array.begin() > 0 && (*cur < *(cur-1))) {
	     swap(cur - array.begin(), cur - array.begin() - 1);
	     cur--;
	  }
	}
}
template<typename ElementType>
void TSorter<ElementType>::selectionSortI() {

	typename std::vector<ElementType>::iterator it;
	for(it = array.end(), it--; it - array.begin() > 0; it--) {
	  //search elements from 0 up to this element for largest
	  typename std::vector<ElementType>::iterator largest = array.begin();
	  typename std::vector<ElementType>::iterator j;
	  for(j = array.begin(), j++; j <= it; j++) {
	     if(*largest <= *j) largest = j;  
	     //must be less than or equal so that i don't swap two equal items
	  }
	  swap(it - array.begin(), largest - array.begin());
	  //show(numElements, numElements);
	}
};
template<typename ElementType>
void TSorter<ElementType>::bubbleSortI() {
	typename std::vector<ElementType>::iterator it;
	for(it = array.end(), it--; it - array.begin() > 0; it--) {
		typename std::vector<ElementType>::iterator j;
		for(j = array.begin(); j < it; j++) {
			if(*j > *(j+1)) {   //don't swap if elements are equal.
			swap(j - array.begin(), j-array.begin()+1);
			}
		}
   }
};   
template<typename ElementType>  
void TSorter<ElementType>::insertionSortR(){
	insertionSortRHelper(array.size(), 1);
};
template<typename ElementType>
void TSorter<ElementType>::insertionSortRHelper(int numElements, int index) {
	if(index >= array.size()) return;    //finished entire array
   	insertionSortRSort(index);
    insertionSortRHelper(array.size(), index+1);
};
template<typename ElementType>
void TSorter<ElementType>::insertionSortRSort(int index) {
	if(index == 0 || (array[index] > array[index - 1])) return; //sorted
  	if(array[index] < array[index - 1]) swap(index, index - 1);
   	insertionSortRSort(index - 1);
};
template<typename ElementType>   
void TSorter<ElementType>::selectionSortR() {
	selectionSortRHelper(array.size() - 1);
};	
template<typename ElementType>
void TSorter<ElementType>::selectionSortRHelper(int index) {
	if(index <= 0) return;
  	int max = selectionSortRMax(index, index - 1);
   	swap(max, index);
   	selectionSortRHelper(index - 1);
};
template<typename ElementType>
int TSorter<ElementType>::selectionSortRMax(int currentMax, int index) {
   if(index < 0) return currentMax;
   if(array[currentMax] < array[index]) currentMax = index;
   return selectionSortRMax(currentMax, index-1);
};
template<typename ElementType>  
void TSorter<ElementType>::bubbleSortR() {
	bubbleSortRHelper(array.size() - 1);
}; 
template<typename ElementType>
void TSorter<ElementType>::bubbleSortRHelper(int index) {
	if(index < 0) return;
	bubbleSortRTraverse(1, index);
	bubbleSortRHelper(index - 1);
};
template<typename ElementType>
void TSorter<ElementType>::bubbleSortRTraverse(int index, int end) {
	if(index > end) return;
  	if(array[index-1] > array[index]) swap(index-1, index);
  	bubbleSortRTraverse(index + 1, end);
}; 
