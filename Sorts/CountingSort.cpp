#include <iostream>
#include <vector>
#include <algorithm>

// Complexity
// Time Complexity	 
// Best	                O(n+max)
// Worst	            O(n+max)
// Average	            O(n+max)
// Space Complexity	    O(max)          larger range -> larger space complexity (count[] and output[])
// Stability	        Yes

// Counting sort is used when:
// there are smaller integers with multiple counts.
// linear complexity
// radix sort: using counting sort for digit sort. 

void countingSort(std::vector<int> &array) {
    int max = *max_element(array.begin(), array.end());
    std::vector<int> count(max + 1, 0);
    std::vector<int> output(array.size());

    // Store the count of each element
    for (int n : array) 
        count[n]++;

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++) 
        count[i] += count[i - 1];

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = array.size() - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements into original array
    for (size_t i = 0; i < array.size(); i++)
        array[i] = output[i];
}

int main() {
    std::vector<int> array = {4, 2, 2, 8, 3, 3, 1};
    countingSort(array);
    for (size_t i = 0; i < array.size(); i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}