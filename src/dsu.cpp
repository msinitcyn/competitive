#include <numeric>
#include <vector>

class DSU {

    std::vector<int> parent;

public:

    DSU(int n) : parent(n), rank(n, -1) {
    }

    int find(int a) {
        if (parent[a] < 0) {
            return a;
        }
        parent[a] = find(parent[a]);
        return parent[a];
    }

    void union_sets(int a, int b) {
        int set_a = find(a);
        int set_b = find(b);
        if (set_a == set_b) return;

        if (parent[set_a] < parent[set_b]) {
            parent[set_a] += parent[set_b];
            parent[set_b] = set_a;
        } else {
            parent[set_b] += parent[set_a];
            parent[set_a] = set_b;
        }
    }
};
