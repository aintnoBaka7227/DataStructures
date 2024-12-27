#include <iostream>
#include <climits>

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

int kthSmallest(int array[], int p, int r, int k) {
    if (k > 0 && k <= r - p + 1) {

        // Partition the array around the last 
        // element and get the position of the pivot 
        // element in the sorted array.
        int index = partition(array, p, r);

        // If position is the same as k.
        if (index - p == k - 1)
            return array[index];

        // If position is more, recur for the left subarray.
        if (index - p > k - 1) 
            return kthSmallest(array, p, index - 1, k);

        // Else recur for the right subarray.
        return kthSmallest(array, index + 1, r, k - index + p - 1);
    }
    return INT_MAX;
}

int main() {
    int array[8] = {2,8,7,1,3,5,6,4};
    int n = 8;
    int k = 3;
    std::cout << "K-th smallest element is " << kthSmallest(array, 0, n - 1, k) << std::endl;
    return 0; 
}