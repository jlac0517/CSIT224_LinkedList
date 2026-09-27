#include "list.hpp"
#include "node.hpp"
#include <iostream>
//#inlcude <stdexcept>

class SinglyLinkedList : public List{
    node* head;
    node* tail;
    size =0;

    public:
        SinglyLinkedList(){
            head = NULL;
            tail = NULL;
            size = 0;
        }

        void addFirst(int elem){
            node* n = new node; // create a new node for the new elem
            n->next = nullptr; //new node points to nothing at first
            n->elem = elem; //store elem in node
            if (tail){
                tail->next = n; // if tail is not empty then we assign next to be new node
            } else {
                head = n; //if tail is empty, then new node is head
            }
            tail = n; // tail is new node
            size++; // increase size since we added an element to the list
        }

        void addLast(int elem){
            //homework
        }

        int removeFirst(){
            if (!head){
                cout << "List is empty. Nothing to remove";
            }
            int ret = head->elem; // retain element before we lose it
            node* tmp = head; // keep pointer to old head for it to be safely removed later
            head = head->next;

            if(!head){
                tail = NULL; //list is empty
            }

            delete tmp; // safely delete pointer to old head
            size--; // decrease size since we removed an element
            return ret; // return element removed
        }

        int removeLast(){
            //homework
        }

        int get(int pos){
            if (pos<=0 || pos size){
                cout<<"incorrect position"; // check if given position is incorrect
            }
            node* curr = head; //start at the beginning of the list
            if (!head){
                return 0; // nothing to get since its empty
            }
            for (int i=1; i<pos; i++){
                if(!curr){
                    return 0;
                }
                curr = curr->next; //actual traversing, where curr pointer is looking at next node's location
            }
            return curr->elem; //return element that we want
        }

        void print(){
            if (size == 0){
                cout << "List is empty";
            }

            for (node* curr = head; curr != nullptr; curr = curr->next){
                cout << curr->elem;
                if (curr->next){
                    cout <<"->"; 
                }
            }

            node* curr = head;
            for (int i = 1; i <= size ; i++){
                cout<< curr->elem;
                if (curr->next){
                    cout <<"->";
                }
                curr = curr->next;
            }
            cout << endl;
        }

//TO DO
//search()
//size()
//removeLast (in the slides)
//remove()
//addLast()

}
