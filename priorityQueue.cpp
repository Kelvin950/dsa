#include <iostream>
using namespace std;

class PriorityQueue{

 public:
  PriorityQueue(int size){
    this->size = size;
    rear=-1;
    front=-1; 
    A = new int[size];
  }




 int  dequeue(){
 
  int x = -1 ; 
       
       if(front == rear){
        return x ;
       }

      
    x =  A[rear] ;
       rear--;

return x ; 

  }


  void Enqueue(int x){
     if(rear==size-1){
        return ; 
     }


   
     if(rear==-1){
        rear++;
        A[rear]=x;
     }
     else{
          int y = rear ; 
 
     while (A[y]< x && y>-1)
     {
        /* code */ 
    
        A[y+1] =  A[y] ;
        
        y-- ;
     }

     A[y+1] = x ;
  
      rear++;
     }

  }


  void display(){

    for(int i = front+1 ; i<size ;i++){
        cout<<A[i]<<endl;

    }
  }


private:
int front; 
int rear ; 
int size ;
 int *A ;
} ;


int main(){


    PriorityQueue q(5) ; 

    q.Enqueue(6);
    q.Enqueue(8);
    q.Enqueue(3);
    q.Enqueue(10);
    q.Enqueue(15) ;

    q.display(); 
}