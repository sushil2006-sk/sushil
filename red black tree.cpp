#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int val) {
        data = val;
        color = RED;
        left = right = parent = NULL;
    }
};

int main() {
    cout << "Red-Black Tree basic structure created";
    return 0;
}