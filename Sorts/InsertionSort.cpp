#include <iostream> 
#include <vector> 

// Insertion sort in C++

// traverse through all elements, compare with each other to the left and insert in a suitable position (move all element to the right 1 step)

// Insertion Sort Complexity
// Time Complexity	 
// Best	                O(n)            sorted (inner loop does not run)
// Worst	            O(n^2)          reversely sorted
// Average	            O(n^2)          random
// Space Complexity	    O(1)            variable key
// Stability	        Yes

std::vector<int> insertionSort(std::vector<int> arr) {
    // start from index 1
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i]; 
        int j = i - 1; 
        // swap key with each element before key in the 
        // arr if key < element until key > element
        while (j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return arr;
}

int main() {
    std::vector<int> arr = {9,5,1,4,3}; 
    arr = insertionSort(arr); 
    for (auto i : arr) {
        std::cout << i << " "; 
    }
    std::cout << std::endl;
    return 0; 
}