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
    int data;
    string name;
    node * next, * prev;

    node(int d, string na, node * ne = nullptr, node * p = nullptr){
      data = d;
      name = na;
      next = ne;
      prev = p;
    }
};

class DList{
private:
  node* head;
  //node *wHead;
public:
  DList(){
    head = nullptr;
    //wHead = nullptr;
  }

  void insertName(string n, int w){
    node* temp = new node(w, n);
    //node* h = head;
    node* he = head;
    if(head == 0){
      head = temp;
    } else if (temp->name < head->name){
      temp->next = head;
      head->prev = temp;
      head = temp;
    } else if(temp->name  > head->name && he->next != 0) {
      //meaning new node is bigger than n

      while(he->next != 0){
        he = he->next;

            if(temp->name  > he->prev->name && temp->name  < he->name){
            //not last element, and lest then current (tranversed head):
            //need to rpelate head->prev, and head->prev->next = head;

            //attaches new node on
            temp->prev = he->prev;
            temp->next = he;

            //replaces links from prev, and head
            he->prev->next = temp;
            he->prev = temp;

            }
      }
    } else if (temp->name  > head->name && he->next == 0){
        he->next = temp;
        temp->prev = he;

    }
    //insertWeight(moi);
  }

  void printName(){
    node* he = head;
    while(he != 0){
      cout << he->name << " " << he->data <<endl;
      he = he->next;

    }
    cout << endl;
  }
};

int main(){
  DList s1;
  string n;
  int w;

  for(int i = 0;i < 5;i++){
    cout << "Enter in name: ";
    cin >> n;


    cout << "Enter in weight: ";
    cin >> w;

    s1.insertName(n, w);
  }

  s1.printName();
}
