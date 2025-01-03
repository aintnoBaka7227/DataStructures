#include <iostream>
#include <vector>
#include <algorithm>

//total runtime: O(m+nlogn)

class Union {
    private:
    std::vector<int> parent;
    std::vector<int> rank;
    public:
    Union(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(-1);
            rank.push_back(1);
        }
    } 
    // time complexity: O(m) for 2m find operations being called
    int find(int i) {
        if (parent[i] == -1) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    // time complexity: O(nlogn) for n-1 union operations
    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) { 
                parent[s1] = s2; 
            } 
            else if (rank[s1] > rank[s2]) { 
                parent[s2] = s1; 
            } 
            else { 
                parent[s2] = s1; 
                rank[s1] += 1; 
            } 
        }
    }
};
