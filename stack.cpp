#include <iostream>
using namespace std ; 



class Stack{
 

        public:
        Stack(int size)
   {
      this->size = size;
       this->top = -1 ; 
       this->S = new  char[this->size];

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
      
  void push(char x){
        if(Full()){
       cerr<<"Stack  overflow"<<endl;   
       return ;
        }
        
        top++;
        S[top] = x ;

   }

   char pop(){
         char x=-1;
    if(Empty()){
        cerr<<"Stack underflow"<<endl;
        return x; 
    }
   x = S[top];
    top--;
    return x;
   }
char peek(char index){
       
       char x =  -1; 
       if(top-index+1 < 0){
        cerr<<"invalid index"<<endl;
        return x ;
       }

    return x = S[top-index+1];   

   }
    

   char StackTop(){

        if(Empty()){
            return -1 ;
        }
    return S[top];
    }
   

    private:
    int size; 
    int top;
    char *S; 
} ;

   
 
 bool isBalanced(Stack *s , char *exp){
 
 int i = 0 ; 

 for(int  i = 0 ; exp[i] !='\0' ; i++ ){

          if(exp[i] == '('){
            s->push(exp[i]);

          }   
      else if(exp[i]== ')'){
        if(s->Empty())return false ;
        s->pop();

      }


 }

   return s->Empty();


 }

int main(){
 
 char *p  = "((a+b) *(c+d)))";

    Stack s(10); 


//  s.push(3) ;
//  s.push(2);
//  s.push(4);


// s.Display();

// cout<<s.peek(1);
// cout<<s.pop()<<endl;

// s.Display();

 

cout<<isBalanced(&s , p);
}