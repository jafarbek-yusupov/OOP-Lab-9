#ifndef LIST_H
#define LIST_H

template<typename T>
class List {
    class Node {
        public: T val; Node * next; Node * prev; Node(T val = T()) { this->val = val; next = nullptr; prev = nullptr; }
    };
    Node* head; Node* tail;
    public:
    List(): head(nullptr), tail(nullptr){}
    void addFront(T val) {
       // head->prev = nnode; -- crashes if head is nullptr
        Node* nnode = new Node(val);
        if(!head){ head = tail = nnode;}
        else{ nnode->next = head; head->prev = nnode; head = nnode; }
    }
    void addTail(T val) {
        Node* nnode = new Node(val);
        if(!tail){ head = tail = nnode;}
        else{ nnode->prev = tail; tail->next = nnode; tail = nnode;}
    }
    T getFront(){  if(head == nullptr){ throw std::runtime_error("List is empty. Cannot get front.");} return head->val; }
    T getTail(){  if (tail == nullptr){ throw std::runtime_error("List is empty. Cannot get tail.");} return tail->val; }
    void displayForward(){ Node* tmp = head; while(tmp != nullptr){ std::cout << getFront() << " -> "; tmp = tmp->next; } std::cout << "NULL\n";}
    void displayTail(){ Node* tmp = tail; while(tmp != nullptr){ std::cout << getTail() << " -> "; tmp = tmp->prev; } std::cout << "NULL\n";}
};

#endif