#include <numeric>
#include <vector>

class DSU {

    std::vector<int> parent;
    std::vector<int> rank;

public:

    DSU(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int a) {
        int set_a = parent[a];
        if (a != set_a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }

    void union_sets(int a, int b) {
        int set_a = find(a);
        int set_b = find(b);

        if (set_a != set_b) {
            if (rank[set_a] < rank[set_b]) {
                std::swap(set_a, set_b);
            }

            if (rank[set_a] == rank[set_b]) {
                rank[set_a]++;
            }

            parent[set_b] = set_a;
        }
    }
};
