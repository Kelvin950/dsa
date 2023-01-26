#include <iostream>
#include <cmath>
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
      
  void push(int  x){
        if(Full()){
       cerr<<"Stack  overflow"<<endl;   
       return ;
        }
        
        top++;
        S[top] = x ;

   }

  int pop(){
        int  x=-1;
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
    

   int StackTop(){

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

          if(exp[i] == '(' || exp[i]=='[' || exp[i]=='{'){
            s->push(exp[i]);

          }   
      else if(exp[i]== ')' || exp[i]==']' || exp[i]=='}'){

        if(s->Empty())return false ;
      char x =   s->pop();
           if(abs(exp[i]-x )> 2){
            return false;
           }

      }


 }

   return s->Empty();


 }

 bool isOperand(char x){


   if(x == '/' || x== '*' || x== '-' || x== '+'){
          return   false  ;
   }
   return true ;
 }     

int eval(Stack *s , char *exp){
   int x2 ,x1 ;
   for(int  i = 0 ; exp[i]!='\0' ;i++){
     
    if(isOperand(exp[i])){
        s->push(exp[i]-'0');
    }
        else{
         x2 = s->pop();
         x1 = s->pop();
         
         switch(exp[i]){

            case '-':
               s->push(x1-x2);
              break;
                          case '+':
               s->push(x1+x2);
              break;
                          case '/':
               s->push(x1/x2);
              break;
                          case '*':
               s->push(x1*x2);
              break;
         }

        }
   } 
 
      return  s->pop();
}

int main(){
 
 char *p  = "234*+82/-";

    Stack s(10); 

    
//  s.push(3) ;
//  s.push(2);
//  s.push(4);


// s.Display();

// cout<<s.peek(1);
// cout<<s.pop()<<endl;

// s.Display();

 

// cout<<isBalanced(&s , p);
 cout<<eval(&s ,p);
}