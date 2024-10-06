#include <vector>

using std::vector;

template<typename T>
void heapify(vector<T>& v, int i, int end) {
    int child1 = i*2+1;
    int child2 = i*2+2;
    int new_i = i;
    if (child1 < end && v[child1] > v[new_i]) {
        new_i = child1;
    }
    if (child2 < end && v[child2] > v[new_i]) {
        new_i = child2;
    }
    if (new_i != i) {
        swap(v[i], v[new_i]);
        heapify(v, new_i, end);
    }
}

template<typename T>
void heap_sort(vector<T>& v) {
    for (int i = v.size()-1; i >= 0; --i) {
        heapify(v, i, v.size());
    }

    for (int i = v.size()-1; i > 0; --i) {
        swap(v[0], v[i]);
        heapify(v, 0, i);
    }
}
