#include <iostream>
using namespace std;

#include "Sorter.h"

void Sorter::swap(int i, int j) {
   int tmp; 
   tmp = array[i]; 
   array[i] = array[j];
   array[j] = tmp; 
   return; 
}

Sorter::Sorter() {
   numElements = 0;
   capacity = 0;
   array = NULL;  
}

Sorter::Sorter(unsigned int initialCapacity) {
   capacity = initialCapacity; 
   numElements = 0;
   array = new int[capacity]; 
}

unsigned int Sorter::makeSpace(unsigned int newCapacity) {
   int *old; 
   unsigned int i;
   if (newCapacity > capacity) {
      old = array; 
      array = new int[newCapacity]; 
      for (i=0; i<numElements; i++) 
         array[i] = old[i]; 
      capacity = newCapacity;
      delete old; //does deleting a pointer to an array delete the whole array?
   }

   return capacity;
}

void Sorter::clear() {
   numElements = 0;
   return; 
}

bool Sorter::insert(int element) {
   if (numElements >= capacity) 
      return false;
   array[numElements++] = element;  
   return true;
}

Sorter::~Sorter() {
   if (array) {
      delete array; 
      numElements = 0; 
   }
}

// Shuffle array elements
void Sorter::shuffle() {
   unsigned int j; 
   for (unsigned int i=1; i<numElements; i++) {
      j = rand() % i; 
      swap(i, j); 
   }
}

// Show the first n elements, k per line, using << 
void Sorter::show(unsigned int n, unsigned int k) {
   unsigned int toShow = ((n < numElements) ? n : capacity); 
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << array[i] << " "; 
   }
   cout << endl << endl;
} 

// Iterative Snsertion Sort
void Sorter::insertionSortI() {
   cout << "Sorter::insertionSortI()" << endl;
   for(unsigned int i=1; i < numElements; i++) {
      int current = i;
      while(current > 0 && (array[current] < array[current - 1])) {
         swap(current, current - 1);
         current--;
      }
   }
}

// Iterative Selection Sort
void Sorter::selectionSortI() {
   //cout << "Sorter::selectionSortI()" << endl << endl;
   //show(numElements, numElements);
   //start from last element
   //swap current element w/ largest
   //keeping iterating until zero
   for(unsigned int i = numElements - 1; i > 0; i--) {
      //search elements from 0 up to this element for largest
      int largest = 0;
      for(int j=1; j <= i; j++) {
         if(array[largest] <= array[j]) largest = j;  
         //must be less than or equal so that i don't swap two equal items
      }
      swap(i, largest);
      //show(numElements, numElements);
   }
}

// Iterative Bubble Sort
void Sorter::bubbleSortI() {
   cout << "Sorter::bubbleSortI()" << endl;
   for(unsigned int i= numElements - 1; i > 0; i-- ) {
      for(int j=0; j < i; j++) {
         if(array[j] > array[j+1]) {   //don't swap if elements are equal.
            swap(j, j+1);
         }
      }
   }
}
     
// Recursive Insertion Sort
void Sorter::insertionSortR() {
   //cout << "Sorter::insertionSortR() not implemented yet." << endl;
   //recursive function to sort the entire array -> inserttionSortRHelper
   //recursive function to move an element to its correct position
      //relative to the other elements -> insertionSortRSort
   insertionSortRHelper(numElements, 1);
}
void Sorter::insertionSortRHelper(int numElements, int index) {
   //cout << "Sorter::insertionSortRHelper() not implemented yet." << endl;
   if(index >= numElements) return;    //finished entire array
   insertionSortRSort(index);
   insertionSortRHelper(numElements, index+1);
}
void Sorter::insertionSortRSort(int index) {
   //cout << "Sorter::insertionSortRSort() not implemented yet." << endl;
   if(index == 0 || (array[index] > array[index - 1])) return; //sorted
   if(array[index] < array[index - 1]) swap(index, index - 1);
   insertionSortRSort(index - 1);
}
 
// Recursive Selection Sort
void Sorter::selectionSortR() {
   //cout << "Sorter::selectionSortR() not implemented yet." << endl;
   //one function to find the max in the array
   //another function to swap the max element w/ the given index
   selectionSortRHelper(numElements - 1);
}

void Sorter::selectionSortRHelper(int index) {
   if(index <= 0) return;
   int max = selectionSortRMax(index, index - 1);
   swap(max, index);
   selectionSortRHelper(index - 1);
};
int Sorter::selectionSortRMax(int currentMax, int index) {
   //return index of currentMax
   if(index < 0) return currentMax;
   if(array[currentMax] < array[index]) currentMax = index;
   return selectionSortRMax(currentMax, index-1);
};
	
// Recursive Bubble Sort
void Sorter::bubbleSortR() {
   //cout << "Sorter::bubbleSortR() not implemented yet." << endl;
   bubbleSortRHelper(numElements - 1);
}
void Sorter::bubbleSortRHelper(int index) {
   if(index < 0) return;
   bubbleSortRTraverse(1, index);
   bubbleSortRHelper(index - 1);
};
void Sorter::bubbleSortRTraverse(int index, int end) {
   if(index > end) return;
   if(array[index-1] > array[index]) swap(index-1, index);
   bubbleSortRTraverse(index + 1, end);
}; 




