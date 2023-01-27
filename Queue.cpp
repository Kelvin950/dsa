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
        return rear==size-1 ;
    };
 
// private:
 int front;
 int  rear;
 int size ;
 T *A ; 
} ;


template <typename T>
Queue<T>::Queue(int size):size(size){
    front=rear=-1; 
    A = new T[this->size];
}

template <typename T>
T Queue<T>::deque(){
   
    if(isEmpty()){
        return -1;
    }


    front++;

  return A[front];

       
}

template <typename T>
void Queue<T>::enqueue(T x){
    
    if(isFull()){
        return ; 
    }
    
    rear++;
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

    for(int  i =q.front + 1 ; i<=q.rear ;i++ ){
        cout<<q.A[i]<<endl;        
    }

  

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

