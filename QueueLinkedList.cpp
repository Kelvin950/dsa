#include <iostream>

using namespace std ; 


class Node {
 
 public:
 int data ; 
 Node *next; 

};

class Queue{
 
public:
 Queue(){
     
     front= NULL;
     rear= NULL;

 }


 bool isEmpty(){

   return  front ==NULL;
 }
 
 
 void enqueue(int x){
      
      Node *temp = new Node();
      
      if(temp ==NULL){
        return;
      }
    
    temp->data =x ;

    if(isEmpty()){
        front =rear= temp ;
    }else{
      
      rear->next =  temp ; 
      rear=temp;

    }
     
 }
 

 int dequeue(){

    int x = -1 ; 

    if(isEmpty()){
        return x ;
    }

    Node *q = front ; 
    front =front->next ;

    x = q->data ;
     delete q ;

return x ; 
 }

 void display(){

    Node  *q = front ; 
     
     while (q)
     {
        /* code */
        cout<<q->data<<endl;
        q=q->next ;
     }
     
 }
private:
Node *front ; 
Node *rear ; 
} ;


int main(){
     
     Queue  s ;
     s.enqueue(33);
     s.enqueue(21);

s.display();
}