// TMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class SearchTree {
private:
    struct Node {
        Node* parent;
        int value;
        Node* left;
        Node* right;

        Node(Node* parent, int val) : parent(parent), value(val), left(nullptr), right(nullptr) {}

        ~Node() {
            if (left) delete left;
            if (right) delete right;
        }
    };
    Node* root;

    void print(Node* node) {
        if (node->left) print(node->left);
        std::cout << node->value << ' ';
        if (node->right) print(node->right);
    }

public:
    bool InTree(int v) {
        Node* node = root;
        while (node != nullptr) {

            if (node->value == v) return true;

            if (node->value > v) node = node->left;
            else node = node->right;
        }
        return false;
    }

    bool Push(int v) {
        Node* prev = nullptr;
        Node* node = root;
        while (node != nullptr) {

            if (node->value == v) return false;
            prev = node;
            if (node->value > v) node = node->left;
            else node = node->right;
        }

        node = new Node(prev, v);
        if (prev == nullptr) {
            root = node;
            return true;
        }
        if (prev->value > v) prev->left = node;
        else prev->right = node;

        return true;
    }

    void print() {
        if (root) print(root);
    }

    ~SearchTree() {
        delete root;
    }
};


int main() {
    SearchTree tree;
    int mas[] = { 9,4,6,3,5,2,1,7,8 };
    for (int v : mas) {
        tree.Push(v);
    }
    tree.print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
