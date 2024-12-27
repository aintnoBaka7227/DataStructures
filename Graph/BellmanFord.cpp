#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> bellmanFord(int vertices, vector<vector<int>> &edges, int src) {
    vector<int> dist(vertices, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < vertices; i++) {
        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                if (i == vertices - 1) // negative cycle
                    return {-1}; 

                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist;
}

int main() {
    int verticesertices = 5;
    vector<vector<int>> edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
    int src = 0;
    vector<int> ans = bellmanFord(verticesertices, edges, src);

    for (int dist : ans) cout << dist << " ";
    return 0;
}