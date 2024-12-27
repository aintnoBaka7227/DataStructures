#include <iostream>
#include <vector> 
#include <unordered_map> 
#include <unordered_set> 
#include <queue> 

// undirected graph implementations

class Graph {
    private: 
    std::unordered_map<int, std::unordered_set<int>> adj_lists;
    std::unordered_map<int, bool> dfs_visited;
    public: 
    void addVertice(int vertice, std::vector<int> edges) {
        for (auto edge : edges) {
            adj_lists[vertice].insert(edge);
            adj_lists[edge].insert(vertice);
        }
    }

    // assumne the graph is connected 
    // disconnected graph can be resolved by bfs all non-visited node
    // in this case, bfs from a single source
    void bfs() {
        std::queue<int> q; 
        std::unordered_map<int, bool> visited; 
        int source = adj_lists.begin()->first; 
        q.push(source);
        visited[source] = true;

        while(!q.empty()) {
            int curr = q.front(); 
            q.pop();
            std::cout << curr << " ";
            for (int node : adj_lists[curr]) {
                if (visited.find(node) == visited.end()) {
                    visited[node] = true; 
                    q.push(node);
                }
            }
        }
        std::cout << std::endl; 
    }

    void recursiveDFS(int source) {
        dfs_visited[source] = true; 
        std::cout << source << " "; 

        for (int i : adj_lists[source]) {
            if (!dfs_visited[i]) {
                recursiveDFS(i); 
            }
        }

    }
    
    // dfs using recursion 
    // same for single source 
    void dfs() {
        dfs_visited.clear();
        int source = adj_lists.begin()->first; 
        recursiveDFS(source);
        std::cout << std::endl; 
    }
};

int main() {
    Graph g;
    g.addVertice(1, {2, 3});
    g.addVertice(2, {1, 3, 4});
    g.addVertice(3, {1, 2});
    g.addVertice(4, {2});
    g.bfs(); 
    g.dfs();
    return 0; 
}