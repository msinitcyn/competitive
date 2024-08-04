#include <vector>

using std::vector;

template<typename T>
void merge_sort(vector<T>& v, int start, int end) {
    if (start == end) return;

    vector<T> tmp(end-start+1);
    int mid = (start+end)/2;
    merge_sort(v, start, mid);
    merge_sort(v, mid+1, end);

    int i = start;
    int j = mid+1;
    int idx = 0;

    while (i <= mid || j <= end) {
        if (i <= mid && j <= end) {
            if (v[i] < v[j]) tmp[idx++] = v[i++];
            else tmp[idx++] = v[j++];
        } else if (i <= mid) tmp[idx++] = v[i++];
        else tmp[idx++] = v[j++];
    }

    for (int i = 0; i < tmp.size(); ++i)
        v[start+i] = tmp[i];
}

template<typename T>
void merge_sort(vector<T>& v) {
    merge_sort(v, 0, v.size()-1);
}
