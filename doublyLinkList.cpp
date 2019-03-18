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
            node* h = head;

            while(h->next != 0){
                h = h->next;

                if(moi->name < h->name){
                    //insertion
                    moi->next = h;
                    moi->prev = h->prev;
                    moi->prev->next = moi;
                    h->prev = moi;
                } else if(h->next == 0 && moi->name > h->name){
                    h->next = moi;
                    moi->prev = h;
                }
            }
                //assuming that at last element, so h->next has to be null after going through loop
                //h->next = moi;
                //moi->prev = h;


        }

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
          node* wH = wHead;
          while(wH->next != 0){

            wH = wH->next;

            if(moi->data < wH->data){
              //tranvseral
              moi->next = wH;
              moi->prev = wH->prev;
              moi->prev->next = moi;
              wH->prev = moi;
            } else if(wH->next == 0 && moi->data > wH->data){
                wH->next = moi;
                moi->prev = wH;
            }
          }
          //wH->next = moi;
          //moi->prev = wH;
        }
    }


  void printName(){
    node* h = head;
    cout << "Printing names in alphabetical order: " << endl;
    while(h != 0){
        cout << h->name << " - " << h->data << endl;
        h = h->next;
    }
  }
  void printWeight(){
    node* h = wHead;
    cout << "Printing weight in order: " << endl;
    while(h != 0){
        cout << h->name << " - " << h->data << endl;
        h = h->next;
    }
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
  cout << endl;
  cout << endl;
  s1.printWeight();

   cout << endl;
  cout << endl;
  return 0;
}
