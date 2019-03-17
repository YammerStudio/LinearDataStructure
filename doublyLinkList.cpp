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

using std::string;

struct node {
  int weight;
  string name;

  node* next, * prev;
  node(int w, string n, node* ne = 0, node* p = 0){
    weight = w;
    name = n;
    next = ne;
    prev = p;
  }

};

class DLinkList{

private:
  node * head, *wHead;
public:
  DLinkList(){
    head = wHead = 0;
  }
  DLinkList(string na, int w){
    node* n = new node(w, na);
    head = wHead = n;
  }
  void insertName(string nan, int wei){
    node* moi = new node(wei, nan);
    node* h = head;
    insertWeight(nan, wei);
    //three conditions:
    if(moi->name < h->name){
      moi->next = h;
      h->prev = moi;
      h = moi;
    } else if (moi->name > h->name){

      //transverse
      while(h->next != 0){

        h = h->next;
        if( moi->name > h->name){
          //last element:
          h->next = moi;
          moi->prev = h;
        } else{
          moi->next = h;
          moi->prev = h->prev;
          h->prev = moi;
          moi->prev->next = moi;
        }
      }
    }
  }
  void insertWeight(string nan, int wei){
    node* moi = new node(wei, nan);
    node* wH = wHead;

    //three conditions:
    if(moi->weight < wH->weight){
      moi->next = wH;
      wH->prev = moi;
      wH = moi;
    } else if (moi->weight > wH->weight){

      //transverse
      while(wH->next != 0){

        wH = wH->next;
        if(wH->next == 0 && moi->weight > wH->weight){
          //last element:
          wH->next = moi;
          moi->prev = wH;
        } else {
          moi->next = wH;
          moi->prev = wH->prev;
          wH->prev = moi;
          moi->prev->next = moi;
        }
      }
    }
  }

  void printName(){
    std::cout << "Names in alphabetical order: " << std::endl;

  for(node* temp = head; temp != 0; temp = temp->next){
      std::cout << temp->name << " - " << temp->weight << std::endl;
  }
  std::cout << std::endl;
  }
  void printWeight(){
    std::cout << "Weights in ascending order: " << std::endl;

    for(node* temp = wHead; temp != 0; temp = temp->next){
        std::cout << temp->name << " - " << temp->weight << std::endl;
    }
    std::cout << std::endl;
  }
};

int main(){

   int weight;
   string name;

    std::cout << "Enter in name: " << std::endl;
   std::cin >> name;
   std::cout << "Enter in weight: " << std::endl;
   std::cin >> weight;

   DLinkList s1(name, weight);

   for(int i = 0; i < 3;i++){
   std::cout << "Enter in name: " << std::endl;
   std::cin >> name;
   std::cout << "Enter in weight: " << std::endl;
   std::cin >> weight;


   s1.insertName(name, weight);
   }
   s1.printName();
   s1.printWeight();
    std::cout << "it worked right? " << std::endl;
}

