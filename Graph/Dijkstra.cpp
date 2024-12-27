#include <iostream>
#include <queue>
#include <vector>
#include <climits>

/*
Time Complexity:
	O((V + E) * log V) = O(), where V is the number of vertices and E is the number of edges.
Space Complexity:
	O(V + E) for the adjacency list and O(V) for the priority queue.
*/


typedef std::pair<int, int> pii; // (distance, vertex)

void dijkstra(int source, std::vector<std::vector<std::pair<int, int>>> &graph, int n) {
    std::vector<int> dist(n, INT_MAX); // vector of distance
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq; // min heap to sort distance

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second; // current vertix
        pq.pop();

        if (current_dist > dist[u]) continue;

        for (auto &neighbor : graph[u]) {
            int weight = neighbor.first; // edge weight
            int v = neighbor.second; // neighbor vertex

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    std::cout << "Vertex\tDistance from Source" << std::endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            std::cout << i << "\t" << "INF" << std::endl;
        else
            std::cout << i << "\t" << dist[i] << std::endl;
    }
}

int main() {
    int n, m;
    std::cout << "Enter the number of vertices and edges: ";
    std::cin >> n >> m;

    std::vector<std::vector<pii>> graph(n);

    std::cout << "Enter edges (u, v, weight):" << std::endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].push_back({w, v});// Directed edge u -> v
        // Uncomment the line below for an undirected graph
        // graph[v].push_back({w, u});
    }
    int source;
    std::cout << "Enter source vertex: ";
    std::cin >> source;

    dijkstra(source, graph, n);

    return 0;
}