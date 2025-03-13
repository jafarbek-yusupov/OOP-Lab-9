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
    void addFront(T val){
       // head->prev = nnode; -- crashes if head is nullptr
        Node* nnode = new Node(val);
        if(!head){ head = tail = nnode;}
        else{ nnode->next = head; head->prev = nnode; head = nnode; }
    }
    void addTail(T val){
        Node* nnode = new Node(val);
        if(!tail){ head = tail = nnode;}
        else{ nnode->prev = tail; tail->next = nnode; tail = nnode;}
    }
    T getFront(){  if(head == nullptr){ throw std::runtime_error("List is empty. Cannot get front.");} return head->val; }
    T getTail(){  if (tail == nullptr){ throw std::runtime_error("List is empty. Cannot get tail.");} return tail->val; }
    void displayForward(){ Node* tmp = head; while(tmp != nullptr){ std::cout << getFront() << " -> "; tmp = tmp->next; } std::cout << "NULL\n";}
    void displayTail(){ Node* tmp = tail; while(tmp != nullptr){ std::cout << getTail() << " -> "; tmp = tmp->prev; } std::cout << "NULL\n";}
    // Part 2
    bool isEmpty(){ return head == nullptr; }
    void removeFront(){
        if(head==nullptr){ /*throw std::runtime_error("List is empty. Cannot remove front.");*/ std::cout << "List is empty. Cannot remove front.\n"; return;}
        Node* tmp = head; head = head->next; head->prev = nullptr;
        if(head){ head->prev = nullptr;} else{ tail = nullptr;}
        delete tmp;
    }
    void removeTail(){
        if(tail==nullptr){  std::cout << "List is empty. Cannot remove tail.\n"; return;}
        Node* tmp = tail; tail = tail->prev; tail->next = nullptr;
        if(tail){ tail->next = nullptr;} else{ head = nullptr;}
        delete tmp;
    }
    T getAt(int idx){
        if(idx<0){ throw std::runtime_error("negative index.");}
        Node* cc = head;
        for(int i=0; cc != nullptr && i<idx; i++){ cc = cc->next; }
        if(cc == nullptr){ throw std::runtime_error("List is mpty, cnat get yo idx"); }
        return cc->val;
    }
    void insertAt(int idx, T val) {
        if(idx<0){ throw std::runtime_error("negative index.");}
        if(!idx){ addFront(val); return; }
        Node* cc = head; int i=0;
        while(cc != nullptr && i!=idx){ cc = cc->next; i++;}
        if(cc==nullptr){ if(i==idx){ addTail(val);} else{ throw std::runtime_error("cant insert there");} return;}
        Node* nnode = new Node(val); nnode->next = cc; nnode->prev = cc->prev;
        if(cc->next){ cc->next->prev = nnode;} else{ tail = nnode; /*if insert at 0 => upd head*/}
        cc->prev = nnode;
    }
    void removeAt(int idx) {
        if(idx<0){ throw std::runtime_error("negative index.");} if(isEmpty()){ throw std::runtime_error("List is empty.");}
        if(!idx){ removeFront(); return ;}
        Node* cc = head; int i=0;
        while(cc != nullptr && i!=idx){ cc = cc->next; i++;}
        if(cc==nullptr){ throw std::runtime_error("idx out of bounds");}
        if(cc->next){ cc->next->prev = cc->prev; /*fx nodes prev ptr*/}
        else{ tail  = cc->prev; /*if removing tail upd tail ptr*/}

        if(cc->prev){ cc->prev->next = cc->next; /* next ptr of PREVIOUS node */}
        delete cc;
    }
};

#endif