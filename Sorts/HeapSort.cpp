#include <iostream> 
#include <vector> 

//using max heap 

// heapify bottom up for max heap
void maxHeapify(std::vector<int> &array, int n, int i) {
    int largest = i;
    int l = 2*i+1; 
    int r = 2*i+2;
    if (l < n && array[l] > array[largest]) {
        largest = l;
    }
    if (r < n && array[r] > array[largest]) {
        largest = r; 
    }
    if (largest != i) {
        std::swap(array[i], array[largest]);
        // heapify subtree with largest as root to ensure property in new subtree
        maxHeapify(array, n, largest);
    }
}

void heapSort(std::vector<int> &array) {
    // build max heap
    for(int i = array.size() / 2 - 1; i >= 0; i--) {
        maxHeapify(array, array.size(), i);
    }

    // heapsort: swap the curr largest with the last element, retrieve and delete
    // and heapify to ensure properties
    for (int i = array.size() - 1; i >=0; i--) {
        std::swap(array[0], array[i]);
        maxHeapify(array, i, 0);
    }
}
 
int main() {
    std::vector<int> array = {4,1,3,2,16,9,10,14,8,7};
    heapSort(array);
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    return 0; 
}