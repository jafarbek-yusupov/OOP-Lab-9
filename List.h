#ifndef LIST_H
#define LIST_H

template<typename T>
class List {
    class Node {
        public: T val; Node * next; Node * prev; Node(T val = NULL){ this->val=val; next=nullptr; prev=nullptr; }
    };
    Node* head; Node* tail;
    public:
    List(): head(nullptr), tail(nullptr){}
    void addFront(T val){ Node* nnode = new Node(val); nnode->next=head; head=nnode; }
    void addTail(T val){ Node* nnode = new Node(val); nnode->prev=tail; tail=nnode; }

};

#endif