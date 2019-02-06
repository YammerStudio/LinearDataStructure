#ifndef LINKQUEUE_H_INCLUDED
#define LINKQUEUE_H_INCLUDED



class LinkQueue{

    struct nade {
        int data;
        nade* next;

        nade(int d, nade* n = 0){
            data = d;
            next = n;
        }
    };

private:
    nade* _front;
    nade* _rear;
    int counter;

public:
    LinkQueue(){
        _front = 0;
        _rear = 0;
        counter = 0;
    }
    bool isEmpty(){
        return _front == 0;
    }
    void enqueue(int x){
        //if queue is empty
        nade* temp = new nade(x);
        if(isEmpty()){
            _front = temp;
            _rear = temp;
            counter++; //increment up
        } else{
            temp->next = _front;
            _rear = temp;
            counter++;
        }
    }
    void dequeue(){
        if(isEmpty()){
            std::cout << "Nothing to delete from queue list ..." << std::endl;
        }
        nade* temp = _front;
        _front = _front->next;
        delete temp;
        counter--;
    }

    void printCount(){
        if(isEmpty()){
            std::cout << "no elements in queue" << std::endl;
        }
        std::cout << "There are .... " << counter  << " in the queue list. " << std::endl;
    }

    void printStuff(){
        if(isEmpty()){
            std::cout << "Nothing to see " << std::endl;
        } else {
        for(nade* temp = _front; temp != 0; temp = temp->next){
            std::cout << temp->data << " ";
        }
        std::cout << std::endl;
        }
    }

};


#endif



/*
tester code: 
LinkQueue q1;

    q1.enqueue(20);
    q1.printStuff();

    q1.enqueue(40);
    q1.printStuff();
    q1.printCount();

    q1.enqueue(50);
    q1.printStuff();

    q1.enqueue(60);
    q1.printStuff();



    q1.dequeue();
    q1.printStuff();



    q1.enqueue(100);
    q1.printStuff();
    q1.printCount();

    q1.dequeue();
    q1.printStuff();
    q1.printCount();

    q1.dequeue();
    q1.dequeue();
    q1.printStuff();
    q1.printCount();

    q1.dequeue();
    q1.printStuff();
    q1.printCount();

*/








































































































































































