#include <iostream> 
#include <vector> 
#include <list>
using namespace std;

// use tarjan algorithm 
// Time complexity: O(V+E)
// Initial idea: track discovery time of a node to identify which nodes are parent nodes and which nodes are children nodes (dicovery later)
// For example: DFS A B C then discovery_time[A] < discovery_time[C]
// Main ideas : 
// 1. Start at node U, and V is its neighbor. There is no way to reach node V with discovery_time[V] < discovery_time[U] using DFS (not visited the same path twice)
// or in another words, no back edges from V or any neighbors of V to U.  
// 2. low links: low[U] represents the lowest discovery time through DFS reachable directly from U or its descendants. it is updated while DFS investigating its neighbor. 
// this reflects any back edges to ealier discovered nodes
// 3. for edge UV to be considered a bridge, discovery_time[U] has be strictly smaller than low[V], indicating that there exist no back edges from V or V's neighbors with 
// lower discovery time to U 
// or ancestors of U  (UV not part of any cycle)

// adj[u] = adjacent nodes of u
// disc[u] = discovery time of u
// low[u] = 'low' node of u
// br = bridges

class Graph {
    public: 
    int n; 
    list<int> *adj; 
    vector<pair<int,int>> br;

    Graph(int n) : n(n){
        adj = new list<int>[n];
    };

    // tarjan dfs for finding bridges
    void bridgeDFS(int u, int parent, vector<bool> &visited, vector<int> &disc, vector<int> &low) {
        static int Time = 0; 
        visited[u] = true;
        // initialize discovery time and low link values
        // increment Time for next discovery 
        low[u] = disc[u] = ++Time;

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = *i;
            // avoid going back the same path 
            if (v == parent) {
                continue;
            }
            // v was discovered -> found ancestors of u
            if (visited[v]) {
                // found ancestor with least discovery time
                low[u] = min(low[u], disc[v]);
            }
            // not discovered yet
            else {
                parent = u;
                bridgeDFS(v, parent, visited, disc, low);
                // low[v] might be ancestor of u
                low[u] = min(low[u], low[v]);
                // condition to find bridge
                if (disc[u] < low[v]) {
                    br.push_back({u,v});
                }
            }
        }
    }

    

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void bridge() {
        vector<bool> visited(n, false);
        vector<int> low(n, -1);
        vector<int> disc(n, -1);
        // start node has no parent
        int parent = -1; 
        // dfs all unvisted nodes
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bridgeDFS(i, parent, visited, disc, low);
            }
        }
        for (auto &bridge : br) {
            cout << bridge.first << " " << bridge.second << endl;
        }
    }
};


int main() {
    Graph test(5);
    test.addEdge(1, 0);
    test.addEdge(0, 2);
    test.addEdge(2, 1);
    test.addEdge(0, 3);
    test.addEdge(3, 4);
    test.bridge();
}

