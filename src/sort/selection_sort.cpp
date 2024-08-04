#include <vector>

using std::vector;
using std::size_t;

template<typename T>
void selection_sort(vector<T>& v) {
    for (size_t i = 0; i < v.size()-1; ++i) {
        size_t cur = i;
        for (size_t j = i+1; j < v.size(); ++j) {
            if (v[j] < v[cur]) cur = j;
        }
        swap(v[i], v[cur]);
    }
}
