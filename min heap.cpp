#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

int main() {
    int arr[] = {3, 5, 9, 6, 8, 20, 10};
    int n = 7;

    // Build Min Heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Print heap
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}