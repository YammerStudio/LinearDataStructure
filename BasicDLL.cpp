/*
Basic Double Linked List..
*/

#include <iostream>

//link list using a queue, with a front, and rear:
//FIFO

struct node{
    int data;
    node* next;
    node* prev;


    node(int d, node* n = 0, node* p = 0){
        data = d;
        next = n;
        prev = p;
    }
};

class DoubleQueue{
private:
   node* head;
   node* tail;
   int counter;
public:
    DoubleQueue(){
        head = 0;
        tail = 0;
        counter = 0;
    }
    //~DoubleQueue();
    bool isEmpty(){
        return head == 0;
    }

    void front_add(int x){
        node* temp = new node(x);
        if(isEmpty()){
            head = temp;
            tail = temp;
            counter++;
        } else {
            head->prev = temp;
            temp->next = head;
            head = temp;
            counter++;
        }
    }

    void back_add(int x){
        node* baz = new node(x);
        if(isEmpty()){
            head = baz;
            tail = baz;
            counter++;
        } else {
            tail->next = baz;
            baz->prev = tail;
            tail = baz;
            counter++;
        }
    }

    int remove_atFront(){
        int k;
        if(isEmpty()){
            return -11;
        }
        node* n = head;
        k = n->data;
        head = head->next;
        delete n;
        head->prev = nullptr;
        return k;
    }
    int remove_atBack(){
        int j;
        if(isEmpty()){
            return -11;
        }
        node* temp = tail;
        j = temp->data;
        tail = tail->prev;
        delete temp;
        tail->next = nullptr;
        return j;
    }


    void print(){
        for(node* first = head; first != 0; first = first->next){
            std::cout << first->data << " ";
        }
        std::cout << std::endl;
    }

    void print_(){
        for(node* last = tail; last != 0; last = last->prev){
            std::cout << last->data << " ";
        }
        std::cout << std::endl;
    }
};


int main(){
   DoubleQueue s1;
   s1.front_add(10);
   s1.front_add(20);
   s1.front_add(30);
   s1.front_add(40);
   s1.print();

   s1.back_add(100);
   s1.back_add(200);
   s1.back_add(300);
   s1.back_add(400);

   s1.print();

}
