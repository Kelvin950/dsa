#include <iostream>
#include <cmath>
#include <cstring>
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
      
  void push(char  x){
        if(Full()){
       cerr<<"Stack  overflow"<<endl;   
       return ;
        }
        
        top++;
        S[top] = x ;

   }

 char pop(){
       char  x=-1;
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
            return 0 ;
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

 int predence(char x){

 int v= 0;
   switch (x)
   {
      case '+':
   v =1 ;
      break;
   
   case '-':
  v= 1;
    break; 

    case '/':
   v=2 ;
    break;
   
   case '*':
   v=2;
   break;
   
     
   }
return v ; 
 }

int eval(Stack *s , char *exp){
   int x2 ,x1 ;
   for(int  i = 0 ; exp[i]!='\0' ;i++){
     
    if(isOperand(exp[i])){
        s->push(exp[i]-'0');
    }
        else{
         x1 =  s->StackTop() ? s->pop() :0;
         x2 =  s->StackTop() ? s->pop() :0;
         
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

char  *toPostfix(Stack *s , char *exp ){
         
 int  i = 0 ;
 int j = 0;
 char *postfix = new char[strlen(exp)+1];
      while(exp[i]!='\0'){

            if(isOperand(exp[i])){

               postfix[j] = exp[i];
               i++;
               j++;
            }
            else {

               if(predence(exp[i])> predence(s->StackTop())){
                  s->push(exp[i]);
                  i++;
               }
               else{
                    postfix[j]=  s->pop();
                    j++;
                  //   i++;

               }
            }



 
      }
        
          while (!s->Empty())
          {
            /* code */
            postfix[j]=s->pop();
            j++;
          }
          

return postfix;
}

int main(){
 
 char *p  = "22213";

    Stack s(10); 

    
//  s.push(3) ;
//  s.push(2);
//  s.push(4);


// s.Display();

// cout<<s.peek(1);
// cout<<s.pop()<<endl;

// s.Display();
//  cout<<toPostfix(&s ,p);

// cout<<isBalanced(&s , p);
 cout<<eval(&s ,p);


}

void unReachable(){

   cout<<"hello world"<<endl;
}