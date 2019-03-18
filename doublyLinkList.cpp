/*
Assignment: 
1. Read data for names and weights for 15 people from the console where there is a name on a line followed by a weight on the next line, like in names.txt.
2. Your program will build a list for the data maintained in ascending order based on both name and weight via a doubly linked list. 
3. This dll will use one pointer to keep weights in sorted order, and use the other link to keep names on sorted order. 
4. You need to build the list as you go maintaining this ordering, so at any time a print method was called it would print the related field in order.

tldr: in-order insertion doubly linked list. 
*/

#include <iostream>
#include <string>

using namespace std;


struct node {
    string name;
    int data;
    node* next, * prev;

    node(string n, int d, node* ne = 0, node* p = 0){
      name = n;
      data = d;
      next = ne;
      prev = p;
    }
};

class DLongList{
private:
  node* head, * wHead;
public:
  DLongList(){
    head = wHead = 0;
  }

  void insertName(string n, int d){
    node * moi = new node(n, d);
    if(head == 0 ){
      head = moi;
    } else if(moi->name < head->name){
        moi->next = head;
        head->prev = moi;
        head = moi;
    } else {
        //else meaning new node is greater than head
          while(head->next != 0){

            if(moi->name < head->name){
                //insertion
                moi->next = head;
                moi->prev = head->prev;
                head->prev = moi;
                moi->prev->next = moi;
            }
            head = head->next;
            if(head->next == 0){
                moi->next = head;
                head->prev = moi;
            }
          }
          std::cout << std::endl;
    }
    return;
  }
  void insertWeight(string w, int k){
    node* moi = new node(w, k);
    if(wHead == 0){
      wHead = moi;
    }
    else if(moi->data < wHead->data){
          moi->next = wHead;
          wHead->prev = moi;
          wHead = moi;
        } else {
          //assuming that new node is bigger than wHead
          while(wHead->next != 0){

            wHead = wHead->next;

            if(moi->data < wHead->data){
              //tranvseral
              moi->next = wHead;
              moi->prev = wHead->prev;
              wHead->prev = moi;
              moi->prev->next = moi;
            }
            wHead = wHead->next;
            if(wHead->next == 0){
              moi->next = wHead;
              wHead->prev = moi;
            }
          }
          std::cout << std::endl;
        }
        return;
    }


  void printName(){
    for(node* h = head; h != 0; h = h->next){
      cout << h->name << " - " << h->data << endl;
    }
    cout << endl;
  }
  void printWeight(){
    for(node* h = wHead; h != 0; h = h->next){
      cout << h->name << " - " << h->data << endl;
    }
    cout << endl;
  }
};


int main(){

  DLongList s1;

  string n;
  int weight;
  int i = 0;
  while(i != 3){
    i++;
  cout << "enter in name: ";
  cin >> n;
  cout << "Enter in weight: ";
  cin >> weight;
  s1.insertName(n,weight);
  s1.insertWeight(n, weight);
  }

  s1.printName();
  s1.printWeight();
  return 0;
}
