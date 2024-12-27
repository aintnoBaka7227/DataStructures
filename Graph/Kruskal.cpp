#include "UnionFind.cpp"
#include <sstream> 
#include <algorithm>

int char_to_cost(char c) {
    if ('A' <= c && 'Z' >= c) {
        return c - 'A';
    }
    return c - 'a' + 26;
}

class RoadGraph {
    private: 
    std::vector<std::string> country;
    std::vector<std::string> build;
    std::vector<std::string> destroy;
    std::vector<std::pair<int, std::pair<int, int>>> cost_build;
    std::vector<std::pair<int, std::pair<int, int>>> cost_destroy;
    int n;
    public:
    RoadGraph(std::vector<std::string> &country, std::vector<std::string> &build, std::vector<std::string> &destroy) {
        this->country = country;
        this->build = build;
        this->destroy = destroy;
        n = country.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (country[i][j] == '1') {
                    cost_destroy.push_back({char_to_cost(destroy[i][j]), {i,j}});
                }
                else {
                    cost_build.push_back({char_to_cost(build[i][j]), {i,j}});
                }
            }
        }

        std::sort(cost_build.begin(), cost_build.end());
        std::sort(cost_destroy.begin(), cost_destroy.end());
    }

    int reconstruct () {
        Union union_set(n);
        int total_cost = 0; 
        int len1 = cost_destroy.size();
        for (int i = len1 - 1; i >= 0; i--) {
            int cost = cost_destroy[i].first;
            int city1 = cost_destroy[i].second.first;
            int city2 = cost_destroy[i].second.second;
            if (union_set.find(city1) != union_set.find(city2)) {
                union_set.unite(city1, city2);
            }
            else {
                total_cost += cost;
            }
        }
        int len2 = cost_build.size();
        for (int i = 0; i < len2; i++) {
            int cost = cost_build[i].first;
            int city1 = cost_build[i].second.first;
            int city2 = cost_build[i].second.second;
            if (union_set.find(city1) != union_set.find(city2)) {
                union_set.unite(city1, city2);
                total_cost += cost;
            }
        }
        return total_cost;
    }

};

int main() {    
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    std::string c, b, d;
    std::getline(ss, c, ' ');
    std::getline(ss, b, ' ');
    std::getline(ss, d, ' ');
    std::vector<std::string> country, build, destroy;
    
    std::stringstream ss_c(c);
    std::string s;
    while (std::getline(ss_c, s, ',')) {
        country.push_back(s);
    }

    std::stringstream ss_b(b);
    while (std::getline(ss_b, s, ',')) {
        build.push_back(s);
    }

    std::stringstream ss_d(d);
    while (std::getline(ss_d, s, ',')) {
        destroy.push_back(s);
    }

    RoadGraph graph(country, build, destroy);
    std::cout << graph.reconstruct() << std::endl;
    return 0;
}