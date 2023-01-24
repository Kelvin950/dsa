#include <iostream>
using namespace std ; 



class Stack{
 

        public:
        Stack(int size)
   {
      this->size = size;
       this->top = -1 ; 
       this->S = new  int[this->size];

        }

    void Display(){
 int i ; 

 for(i = top ; i>=0 ; i--  ){
          cout<<S[i]<<endl;
 }
    

    }           

 bool Empty(){

    return top==-1 ;
 }
 
 bool Full(){

    
    return top == size-1;
 }
      
  void push(int x){
        if(Full()){
       cerr<<"Stack  overflow"<<endl;   
       return ;
        }
        
        top++;
        S[top] = x ;

   }

   int pop(){
         int x=-1;
    if(Empty()){
        cerr<<"Stack underflow"<<endl;
        return x; 
    }
   x = S[top];
    top--;
    return x;
   }

   int peek(int index){
       
       int x =  -1; 
       if(top-index+1 < 0){
        cerr<<"invalid index"<<endl;
        return x ;
       }

    return x = S[top-index+1];   

   }
    

    int StackTop(){

        if(Empty()){
            return -1 ;
        }
    return S[top];
    }
   

    private:
    int size; 
    int top;
    int *S; 
} ;


int main(){

    Stack s(5); 
 

 s.push(3) ;
 s.push(2);
 s.push(4);


s.Display();

cout<<s.peek(1);
cout<<s.pop()<<endl;

s.Display();
}