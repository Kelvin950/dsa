#include <iostream>

using namespace std; 

template  <typename T>
class Queue{

public:
    Queue(int size);
    
    T deque();
    void enqueue(T x);
    T Rear();
    T first();
    bool isEmpty(){
        return front==rear;
    }; 
    bool isFull(){
        return (rear+1)%size==front ;
    };
 
// private:
 int front;
 int  rear;
 int size ;
 T *A ; 
} ;


template <typename T>
Queue<T>::Queue(int size):size(size){
    front=rear=0; 
    A = new T[this->size];
}

template <typename T>
T Queue<T>::deque(){
   
    if(isEmpty()){
        return -1;
    }


    front=  (front + 1)%size;

  return A[front];

       
}

template <typename T>
void Queue<T>::enqueue(T x){
    
    if(isFull()){
        return ; 
    }
    
    rear =  (rear+1)%size ;
    A[rear] = x ;

}

template <typename T>
T Queue<T>::first(){
     return  A[front+1];
}

template <typename T>
T Queue<T>::Rear(){
   
   return A[rear];
}

template <typename  T>
void display(Queue<T> q){

int i =q.front+1;

do
{
    /* code */
    cout<<q.A[i]<<endl;
    i =  (i+1)%q.size ;
} while (i != (q.rear+1)%q.size);


  

}


int main(){


    Queue<int > q(5);

    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(3);

    display(q);
   cout<<q.deque()<<endl;
  cout<<"done"<<endl;
  display(q);
}

