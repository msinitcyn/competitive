#include <vector>

using std::vector;
using std::size_t;

template<typename T>
void quick_sort(vector<T>& v, int from, int to) {
    if (from >= to) return;

    size_t pivot = to;
    size_t last_min = from-1;
    for (size_t i = from; i < to; ++i) {
        if (v[i] < v[pivot]) {
            last_min++;
            swap(v[i], v[last_min]);
        }
    }
    pivot = last_min+1;
    swap(v[pivot], v[to]);
    quick_sort(v, from, pivot-1);
    quick_sort(v, pivot+1, to);
}

template<typename T>
void quick_sort(vector<T>& v) {
    quick_sort(v, 0, v.size()-1);
}

