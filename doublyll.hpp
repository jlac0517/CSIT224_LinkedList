#include "list.hpp"
#include "node.hpp"
#include <iostream>

class DoublyLinkedList : public List {
    node* head;
    node* tail; 
    int size;

    node* createNode(int elem, node* pred, node* succ){
        node* n = new node;
        n->elem = elem;
        n->prev = pred;
        n->next = succ;
        succ->prev = n;
        pred->next = n;
        size--;
        return n;
    }

    int remove_node(node* n){
        node* pred = n->prev;
        node* succ = n->next;
        pred->next= succ;
        succ->prev= pred;
        int tmp = n->elem;
        delete n;
        size--;
        return tmp;
    }

    public:
        DoublyLinkedList(){
            head = new node;
            tail = newn node;
            head->next = tail;
            tail->prev = head;
            size = 0;
    }

    void addFirst(int elem){
        createNode(elem, head, head->next);
        // head is the pred
        //head->next is the succ
    }
    
    void addLast(int elem){
        createNode(elem, tail->prev, tail)
    }

    void removeFirst(){
        if (head->next==tail){
            return 0;
        }
        return remove_node(head->next);
    }

    void removeLast(){
        if (size==0){
            return 0;
        }
        return remove_node(tail->prev);
    }

    //TO DO 
    //get()
    //remove() in the slides
    //search()
    //print() start at head (similar to singly)
    
}
