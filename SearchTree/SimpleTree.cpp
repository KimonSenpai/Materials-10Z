#include <iostream>

class SearchTree {
private:
    struct Node {
        Node* parent;
        int value;
        Node* left;
        Node* right;

        Node(Node* parent, int val): parent(parent), value(val) {}

        ~Node() {
            if(left) delete left;
            if(right) delete right;
        }
    };
    Node* root;

    void print(Node* node) {
        if(node->left) print(node->left);
        std::cout << node->value << ' ';
        if(node->right) print(node->right);
    }

public:
    bool InTree(int v) {
        Node* node = root;
        while(node != nullptr) {

            if(node->value == v) return true;

            if(node->value > v) node = node->left;
            else node = node->right;
        }
        return false;
    }

    bool Push(int v) {
        Node* prev = nullptr;
        Node* node = root;
        while(node != nullptr) {

            if(node->value == v) return false;
            prev = node;
            if(node->value > v) node = node->left;
            else node = node->right;
        }

        node = new Node(prev, v);
        if(prev == nullptr) {
            root = node;
            return true;
        }
        if(prev->value > v) prev->left = node;
        else prev->right = node;

        return true;
    }

    void print() {
        if(root) print(root);
    }

    ~SearchTree() {
        delete root;
    }
};


int main() {
    SearchTree tree;
    int mas[] = {9,4,6,3,5,2,1,7,8};
    for(int v: mas) {
        tree.Push(v);
    }
    tree.print();
}