#include <iostream>
#include <vector>
#include <algorithm>

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

    int find(int i) {
        if (parent[i] == -1) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

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
