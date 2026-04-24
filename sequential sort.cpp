#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 3};
    int n = 5, key = 9;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i;
            return 0;
        }
    }

    cout << "Element not found";
    return 0;
}