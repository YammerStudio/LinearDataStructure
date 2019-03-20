/*
Creating an insertion doubly linked list. Tried many different ways. The one that is working is creating functions to do the insertion and 
only passing a value instead of a node. creating a new node whenever those functions are called. 

*/

#include <iostream>
using namespace std;

struct node {
  int data;
  node* next, * prev;

  node(int d): data(d), next(nullptr), prev(nullptr) {};

};


class DoublyList{
private:
  node* head, * tail;
public:
  DoublyList(){
    head = tail = nullptr;
  }
  void insertBefore(node* temp){
    //if new node is less than head
    temp->next = head;
    head->prev = temp;
    head = temp;
  }

  void isEmpty(int x){
    node * moi = new node(x);
    if(head == 0){
      head = moi;
      tail = head;
    }
  }
  void insertNow(int x){

    node * moi = new node(x);
    node* te = head;
    if(head == 0){
      isEmpty(x);
    } else {
      if ( x < te->data){
        insertBefore(moi);
      }

      //tranverse list if x is not less than head
      while(x > te->data && te->next != tail->next){
        te = te->next;
      }

      if(x < te->data && te->next != 0){
        insertBetween(te, moi);
      }

        if(te->next == 0 && x > te->data){
          insertEnd(x);
        }
    }
  }


  void insertBetween(node* he, node* moi){
    node* before = he->prev;

    moi->next = he;
    moi->prev = before;
    he->prev = moi;
    before->next = moi;

    return;
  }
  void insertEnd(int x){
    node* t = new node(x);
    tail->next = t;
    t->prev = tail;
    tail = t;
    return;
  }

  void display(){
    node* h = head;
    while(h != 0){
      cout << h->data << " ";
      h = h->next;
    }
    cout << endl;
  }
};

int main() {

  DoublyList s1;
 s1.insertNow(10);
 s1.insertNow(5);
 s1.insertNow(15);
 s1.insertNow(7);
 s1.display();
 s1.insertNow(20);
 s1.insertNow(100);
 s1.insertNow(50);
 s1.insertNow(25);
 s1.display();

}
