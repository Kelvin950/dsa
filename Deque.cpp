
#include <iostream>
using namespace  std ;
class deque{

   public:
   deque(int size):size(size){
          front =-1;
          rear=-1;
          A  = new int[size];
   } ;

    
    void AddFront(int x){
           
           if(front ==-1){
            return ;
           }

             A[front] = x ;
             front --;
    }

int deleteFront(){

    int x =-1 ; 
     if(front >rear){

        front=rear=-1; 
        return  x;
     }
 
  front++;
  x =  A[front];

  return x ; 


}

int deleteRear(){
 
 int x = -1 ; 

 if(front >= rear){
    rear=front=-1; 
    return x  ;
 }
  x = A[rear];
       rear--; 

    return x ;         

}


void insertRear(int x){

 if(rear ==size-1){
    return   ; 

 }
  
  rear++; 
  A[rear] =x;
}

void display(){

    for(int  i = front+1 ;  i<size ;i++){

        cout<<A[i]<<endl;
    }
}

private:
int size ;
 int front;
 int rear ; 
 int *A ;

} ;


int main(){


    deque q(5) ; 

    q.insertRear(1) ;
    q.insertRear(2);
    q.insertRear(3);
    q.insertRear(4);
     cout<<q.deleteFront()<<"front"<<endl;
     cout<<q.deleteFront()<<"front"<<endl;
     q.AddFront(4);
    q.display();
}