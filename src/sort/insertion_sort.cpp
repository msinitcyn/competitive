#include <vector>

using std::vector;

template <typename T>
void insertion_sort(vector<T>& v) {
    for (int i = 1; i < v.size(); ++i) {
        T cur = v[i];
        int j = i-1;
        while (j >= 0 && v[j] > cur) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = cur;
    }
}
