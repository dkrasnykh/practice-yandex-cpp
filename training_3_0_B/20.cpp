//https://contest.yandex.ru/contest/45468/problems/20/
#include <iostream>
#include <vector>

using namespace std;

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

void maxheapify(vector<int>& a, int i, int heapsize) {
    int l = left(i + 1) - 1;
    int r = right(i + 1) - 1;
    int largest;
    if (l < heapsize && a[l] > a[i]) {
        largest = l;
    }
    else {
        largest = i;
    }
    if (r < heapsize && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        maxheapify(a, largest, heapsize);
    }
}

void buildmaxheap(vector<int>& a) {
    int size = static_cast<int>(a.size());
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxheapify(a, i, size);
    }
}

void heapsort(vector<int>& a) {
    buildmaxheap(a);
    int heapsize = a.size();
    int size = static_cast<int>(a.size());
    for (int i = size - 1; i >= 1; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapsize--;
        maxheapify(a, 0, heapsize);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    heapsort(a);
    for (size_t i = 0; i != a.size(); ++i) {
        cout << a[i] << ' ';
    }
    return 0;
}
