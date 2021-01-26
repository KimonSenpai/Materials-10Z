#include <cstdlib>
#include <utility>
using std::rand;
using std::pair;



class SearchTree {
private:
    struct Node {
        Node* parent;
        int x;
        int y;
        Node* left;
        Node* right;

        Node(Node* parent, int val) : parent(parent), x(val), y(rand()), left(nullptr), right(nullptr) {}

        
    };
    Node* root;

    void deleteTree(Node* root) {
        if(root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

    pair<Node*, Node*> split(Node* tree, int k) { //O(log(n))
        if(tree == nullptr) return {nullptr, nullptr};
        Node* l;
        Node* r;
        if(tree->x >= k) {
            auto tmp = split(tree->left, k);
            l = tmp.first;
            r = tmp.second;
            r->parent = tree;
            tree->left = r;
            r = tree;
        } else {
            auto tmp = split(tree->right, k);
            l = tmp.first;
            r = tmp.second;
            l->parent = tree;
            tree->right = l;
            l = tree;
        }
        return {l, r};
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
        
    }


    ~SearchTree() {
        deleteTree(root);
    }
};