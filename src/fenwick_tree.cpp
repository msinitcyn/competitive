#include <vector>

using std::vector;

class Fenwick {
public:

    Fenwick(int n) {
        bit.assign(n, 0);
    }

    Fenwick(const vector<int>& data) : Fenwick(data.size()) {
        for (int i = 0; i < data.size(); ++i) {
            add(i, data[i]);
        }
    }

    void add(int idx, int value) {
        int cur = idx;
        while (cur < bit.size()) {
            bit[cur] += value;
            cur |= cur+1; 
        }

    }

    int sum(int idx) {
        int result = 0;
        int cur = idx;
        while (cur >= 0) {
            result += bit[cur];
            cur &= cur+1;
            cur--;
        }
        return result;
    }

private:

    vector<int> bit;
};
