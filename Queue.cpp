#include <iostream>
using namespace std;




template<typename T>
class Queue{
private:
    struct Node{
        T val;
        Node* next;
        Node* prev;
        ~Node(){
            if(next != nullptr)
                delete next;
        }
    };
    Node* head;
    Node* tail;
    size_t size;

    void rev(Node* beg, Node* end){
        if(beg == end || beg->prev == end) return;

        rev(beg->next, end->prev);
        swap(beg->prev, beg->next);
        swap(end->prev, end->next);
        
    }

public:
    Queue():head(nullptr), size(0), tail(nullptr)
    {}
    void push(T val){
        Node* node = new Node;
        node->val = val;
        node->prev = tail;
        node->next = nullptr;
        if(tail != nullptr)
            tail->next = node;
        tail = node;
        size++;
        if(head == nullptr){
            head = node;
        }
        
    }
    //pop -- убирает первое значение и возвращает его
    T pop();

    size_t Size() const{
        return size;
    }

    void reverse(){
        rev(head, tail);
        swap(head, tail);
    }

    void seed(int i){
        if(size == 0)
            return;
        cout << i << '\n';
        cout << size << '\n';
        i %= (long)size;
        cout << i << '\n';

        head->prev = tail;
        tail->next = head;
        if(i > 0){
            for(int j = 0; j < i; j++){
                head = head->next;
                tail = tail->next;
            }
        } else {
            for(int j = 0; j < -i; j++){
                head = head->prev;
                tail = tail->prev;
            }
        }
        head->prev = nullptr;
        tail->next = nullptr;
    }

    ~Queue(){
        if(head != nullptr)
            delete head;
    }
};

int main(){
    Queue<int> q;
    for(int i = 0;i < 10; i++){
        q.push(i);
        //cout << i;
    }
    int i = -3;
    cout << i % 9u << '\n';
    i %= 10;
    cout << i << '\t' << i%10 <<  '\n';
    
    for(int i = 0;i < 10; i++)
        cout << q.pop() << '\t';
    cout << '\n';

    for(int i = 0;i < 10; i++)
        q.push(i);
    q.reverse();
    for(int i = 0;i < 10; i++)
        cout << q.pop() << '\t';
    cout << '\n';
    for(int i = 0;i < 10; i++)
        q.push(i);
    q.seed(4);
    for(int i = 0;i < 10; i++)
        cout << q.pop() << '\t';
    cout << '\n';
    for(int i = 0;i < 10; i++)
        q.push(i);
    q.seed(-3);
    for(int i = 0;i < 10; i++)
        cout << q.pop() << '\t';
    cout << '\n';
}

template<typename T>
T Queue<T>::pop(){
    if(head == nullptr)
        throw 1;
    if(size == 1){
        tail = nullptr;
    }
    T val = head->val;

    Node* first = head;
    head = head->next;
    if(head != nullptr)
        head->prev = nullptr;
    first->next = nullptr;
    delete first;

    size--;
    return val;
}