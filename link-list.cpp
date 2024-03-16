// g++ -std=c++11  link-list.cpp -o link-list

#include <iostream>
#include <unordered_map>
#include <cstdlib>



struct Node {
    int value;
    Node* prev;
    Node* next;
    Node(int value){
        this -> value = value;
        this ->prev = nullptr;
        this->next = nullptr;
    }
    Node(){
        this -> value = 0;
        this ->prev = nullptr;
        this->next = nullptr;

    }

};



class doubleLinkList {
    public: int length;
    private: Node* head = nullptr;

    doubleLinkList(){
        this -> length = 0;
    }
    void prepend(Node item){
        this -> length ++;
        if(head == nullptr){
            this -> head -> value = item.value;
            return;
        }
        item.next = this -> head;
        this -> head -> prev = &item;
        this -> head -> value = item.value;
    }
    void insertAt(Node item, int idx){
        if(idx > this -> length){
            return;
        }
        if(idx == this -> length){
            this->prepend(item);
        }
        Node* curr = this -> head;
        for(int i = 0 ; i < idx ; i++){
            curr = curr -> next;
        }
        
        curr -> prev->next = &item;
        item.prev = curr -> prev;

        curr -> prev = &item;
        item.next = curr;

    }
    void append(Node item){}
    void remove(Node item){}
    Node* get(int idx){}
    Node* remove(int idx){}

    
};

int main (){
    printf("hellow world");
    return 0;
}
