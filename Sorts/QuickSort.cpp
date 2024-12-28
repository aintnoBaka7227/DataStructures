#include <iostream>
#include <vector> 
#include <algorithm>

// Quicksort Complexity
// Time Complexity	 
// Best	                O(nlog n)               Pivot is the middle element -> 2 equal sub-arrays -> log2(n) height
// Worst	            O(n^2)                  Pivot is the biggest or smallest -> cannot split to 2 good sub-arrays (one is empty, one has n-1 elements)
// Average	            O(nlog n)               
// Space Complexity	    O(log n)                Recursion -> space = height
// Stability	        No

int partition(int array[], int p, int r) {
    int pivot = array[r];
    int i = p - 1; 

    for (int j = p; j < r; j++) {
        if (array[j] <= pivot) {
            i++;
            std::swap(array[i], array[j]); 
        }
    }
    std::swap(array[i+1], array[r]); 
    return i+1; 
}

void quickSort(int array[], int p, int r) {
    if (p < r) {
        int pivot = partition(array, p, r); 
        quickSort(array, p, pivot - 1); 
        quickSort(array, pivot + 1, r);
    }
}

int main() {
    int array[8] = {2,8,7,1,3,5,6,4};
    quickSort(array, 0, 7);

    for (int i = 0; i < 8; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    return 0; 
}