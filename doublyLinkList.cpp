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

struct node {

  std::string name;
  int data;
  node* next, * prev;
  node(int d, std::string n, node* ne = 0, node* p = 0){
    data = d;
    name = n;
    next = ne;
    prev = p;
  }
};


class DList {

private:
node* head, *wHead;

public:
  DList(){
    head = wHead = 0;
  }

  void insertName(std::string n, int d){
    node* temp = new node(d, n);
    node* foo = head;

    if(foo != 0){
      //less than head
      if(temp->name < foo->name){
        temp->next = foo;
        foo->prev = temp;
        foo = temp;
      } else {
        //not empty, and greater than head.
        while(foo->next != 0){
          foo = foo->next;

          if(temp->name < foo->name ){
            //insert
            temp->next = foo;
            temp->prev = foo->prev;

            foo->prev = temp;
            temp->prev->next = temp;
          }
        }

        if(foo->next == 0){
        //inside else, after while loop when head->next = null
        foo->next = temp;
        temp->prev = foo;
        std::cout << "insertname_shouldwork\n";
        }
      }
    } else {
      //fails initial condition, meaning foo is empty
      foo = head;
    }
  }

  void insertWeight(std::string n, int d){
    //case 1: empty
    node* moi = new node(d, n);
    node* wH = wHead;

    if(wH != 0){
      //less than head
      if(moi->data < wH->data){
        moi->next = wH;
        wH->prev = moi;
        wH = moi;
      } else {
        //not empty, and greater than
        while(wH->next != 0){
          wH = wH->next;
          //less than tranversal
          if(moi->data < wH->data){
              moi->next = wH;
              moi->prev = wH->prev;

              wH->prev = moi;
              moi->prev->next = moi;
          }
        }

        //after while loop executes, which mean the head->next poitns to null, we can insert last element'
        if(wH->next == 0){
        wH->next = moi;
        moi->prev = wH;
        }
      }
    } else {
      //meaning wH is empty
      wH = moi;
    }

  }
  void printNames(){

     std::cout << std::endl;

     std::cout << "Names in alphabetical order: " << std::endl;

     for(node* temp = head; temp != 0; temp = temp->next){
         std::cout << temp->name << " - " << temp->data << std::endl;
     }
     std::cout << std::endl;
   }

   void printWeights(){

     std::cout << std::endl;
     std::cout << "Weights in ascending order: " << std::endl;
    for(node* temp = wHead; temp != 0; temp = temp->next){
         std::cout << temp->name << " - " << temp->data << std::endl;
     }
     std::cout << std::endl;

   }


};



int main(){

   DList s1;
   int weight;
   std::string name;

   for(int i = 0; i < 3;i++){
   std::cout << "Enter in name: " << std::endl;
   std::cin >> name;
   std::cout << "Enter in weight: " << std::endl;
   std::cin >> weight;


   s1.insertName(name, weight);
   s1.insertWeight(name, weight);

   s1.printNames();
   s1.printWeights();
   }

    std::cout << "it worked right? " << std::endl;
}
