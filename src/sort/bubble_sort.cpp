#include <vector>

using std::size_t;
using std::swap;
using std::vector;

template <typename T>
void bubble_sort(vector<T>& v) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (size_t i = 1; i < v.size(); ++i) {
            if (v[i-1] > v[i]) {
                swap(v[i-1], v[i]);
                sorted = false;
            }
        }
    }
}
