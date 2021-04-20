#include <iostream>
#include <cstdlib>
#include <utility>
#include <functional>
#include <map>
#include <stack>
#include <stdexcept>
using std::stack;
using std::rand;
using std::pair;
using std::less;
using std::cout;


template<class T, class COMP = less<T>>
class SearchTree {
private:
    struct Node {
        Node* parent;
        T x;
        int y;
        Node* left;
        Node* right;

        Node(T val) : parent(nullptr), x(val), y(rand()), left(nullptr), right(nullptr) {}   
    };
    Node* root;
    COMP cmp;
    void deleteTree(Node* root) {
        if(root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

    pair<Node*, Node*> split(Node* tree, T k, bool inLeft = false) { //O(log(n))
        if(tree == nullptr) return {nullptr, nullptr};
        Node* l;
        Node* r;
        if(cmp(tree->x , k) || (inLeft && !cmp(k, tree->x))) {
            auto tmp = split(tree->right, k);
            l = tmp.first;
            r = tmp.second;
            if(l) l->parent = tree;
            tree->right = l;
            l = tree;
        } else {
            auto tmp = split(tree->left, k);
            l = tmp.first;
            r = tmp.second;
            if(r) r->parent = tree;
            tree->left = r;
            r = tree;
        }
        return {l, r};
    }

    Node* merge(Node* left, Node* right) {
        if(!left) return right;
        if(!right) return left;

        if(left->y < right->y) {
            Node* tmp = merge(left->right, right);
            left->right = tmp;
            if(tmp) tmp->parent = left;
            return left;
        } else {
            Node* tmp = merge(left, right->left);
            right->left = tmp;
            if(tmp) tmp->parent = right;
            return right;
        }
    }

    void print(Node* node, int k = 1) {
        if (node->left) print(node->left, k + 1);
        std::cout << node->x << ' ' << k << '\n';
        if (node->right) print(node->right, k + 1);
    }

    int GetH(Node* node, int k = 0) {
        int res = k;
        if(node->left) res = std::max(res, GetH(node->left, k+1));
        if(node->right) res = std::max(res, GetH(node->right, k+1));
        return res;
    }
public:
    SearchTree(): root(nullptr) {}

    class iterator;

    iterator begin() {
        return iterator::Begin(root);
    }

    iterator end() {
        return iterator::End();
    }


    bool InTree(T v) {
        Node* node = root;
        while (node != nullptr) {

            if (!cmp(node->x, v) && !cmp(v, node->x)) return true;

            if (cmp(v, node->x)) node = node->left;
            else node = node->right;
        }
        return false;
    }

    void Push(T v) {
        if(InTree(v)) return;
        Node* tree = new Node(v);
        auto res = split(root, v);
        root = merge(merge(res.first, tree), res.second);
    }

    void Pop(T v) {
        if(InTree(v)) return;
        auto res1 = split(root, v);
        auto res2 = split(res1.second, v, true);

        delete res2.first;
        root = merge(res1.first, res2.second);
    }

    void print() {
        if (root) print(root);
    }

    int GetH() {
        if(!root) return 0;
        return GetH(root);
    }

    ~SearchTree() {
        deleteTree(root);
    }
};

template<class T, class COMP>
class SearchTree<T, COMP>::iterator {
private:
    Node* node;
    stack<char> st;
    void go_left() {
        while(node->left != nullptr) {
            node = node->left;
            st.push('l');
        }
    }
public:
    iterator(Node* node): node(node) {
        if(node != nullptr)
            st.push('l');
    }

    static iterator Begin(Node* node) {
        iterator it(node);
        it.go_left();
        return it;
    }
    static iterator End() {
        return iterator(nullptr);
    }

    const T& operator*() const {
        if(node == nullptr) throw std::out_of_range("Out of tree.");
        return node->x;
    }

    bool operator==(const iterator& it) const {
        return this->node == it.node;
    }

    bool operator!=(const iterator& it) const {
        return !(*this == it);
    }

    iterator operator++() {
        if(node == nullptr) throw std::out_of_range("Out of tree.");
        if(node->right != nullptr) {
            st.push('r');
            node = node->right;
            go_left();
            return *this;
        }
        char last;
        do {
            node = node->parent;
            last = st.top();
            st.pop();
        } while(last != 'l');
        return *this;
    }

    iterator operator++(int) {
        iterator tmp = *this;
        ++(*this);
        return tmp;
    }
};

int __main__() {
    //double mas[7] = {3, 6, 1, 2, 4.3, 4.7, 1.1};
    //less<double>()
    SearchTree<long long> tree;
    for(long long i = 0; i < 10; i++){
        tree.Push(i*i);
    }

    auto p = begin(tree);
    //while(true) p++;

    throw &tree;

    SearchTree<long long>::iterator it = begin(tree);
    
    for(auto p = begin(tree); p != end(tree); p++)
        cout << *p << ' ';

    for(auto r: tree)
        cout << r << ' ';
    
    //cout << *a << '\n';
    //cout << tree.GetH() << '\n';
}

int main() {
    try {
        __main__();
    }
    catch(int) {

    }
    catch(char*) {

    }
    catch(std::string) {

    }
    catch(std::out_of_range e) {
        std::cerr << "Out of range exception: " << e.what() << '\n';
    }
    catch(SearchTree<long long>* e) {
        std::cout << "WTF\n";
    }
    catch(std::exception) {

    }
    catch(...) {

    }
}