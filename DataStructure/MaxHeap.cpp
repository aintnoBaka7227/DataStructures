#include <iostream> 
#include <vector>

class maxHeap {
    private: 
    std::vector<int> max_heap; 
    public: 

    void maxHeapify(int n, int i) {
    int largest = i;
    int l = 2*i+1; 
    int r = 2*i+2;
    if (l < n && max_heap[l] > max_heap[largest]) {
        largest = l;
    }
    if (r < n && max_heap[r] > max_heap[largest]) {
        largest = r; 
    }
    if (largest != i) {
        std::swap(max_heap[i], max_heap[largest]);
        // heapify subtree with largest as root to ensure property in new subtree
        maxHeapify(n, largest);
    }
    }

    void insert(int data) {
        max_heap.push_back(data);
        int curr = max_heap.size() - 1;
        while(curr > 0) {
            int parent = (curr - 1) / 2; 
            if (max_heap[curr] > max_heap[parent]) {
                std::swap(max_heap[curr], max_heap[parent]);
                curr = parent; 
            }
            else {
                break;
            }
        }
    } 

    void remove(int data) {
        int index = -1;
        for (int i = 0; i < max_heap.size(); i++) {
            if (max_heap[i] == data) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return;
        }
        std::swap(max_heap[index], max_heap[max_heap.size() - 1]);
        max_heap.pop_back();
        if (index < max_heap.size()) {
            maxHeapify(max_heap.size(), index);
        }
    }

    void print() {
        for (int i = 0; i < max_heap.size(); i++) {
            std::cout << max_heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    maxHeap test;
    test.insert(4);
    test.insert(1);
    test.insert(3);
    test.insert(2);
    test.insert(16); 
    test.insert(9);
    test.insert(10);
    test.insert(14);
    test.insert(8);
    test.insert(7);
    test.print();
    test.remove(16);
    test.print();
    test.remove(10);
    test.print();
    return 0;
}