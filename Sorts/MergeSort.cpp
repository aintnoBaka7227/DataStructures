#include <iostream> 
#include <vector> 

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1; 
    int n2 = r - q; 
    std::vector<int> L; 
    std::vector<int> R; 
    for (int i = 0; i < n1; i++) {
        L.push_back(arr[p + i]);
    }
    for (int i = 0; i < n2; i++) {
        R.push_back(arr[q + 1 + i]);
    }

    int i = 0, j = 0, k = p;
    // add the smaller of first elements from both array;
    while(i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    } 

    // add the remaining elements of the array that still have elements in it
    while(i < n1) {
        arr[k] = L[i];
        i++; 
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int p, int r) {
    if (p < r) {
        // find the divide point
        int q = p + (r - p) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r); 
        // merge the sorted arrays (O(n))
        merge(arr, p, q, r);
    } 
}

int main() {

    int arr[8] = {5,2,4,7,1,3,2,6}; 
    mergeSort(arr, 0, 7);
    for (int i = 0; i < 8; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0; 
}