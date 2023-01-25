
#include <iostream>
using namespace std;
class  Node{


public:
    int data ; 
    Node *next ;
} ;


class LStack{

      


     public:

     LStack(){
        cout<<"Created"<<endl;
     }

    bool isFull(){
        Node *t= new Node();
 
   bool r =  t ? false: true;
      
      delete t ;
      return r;



    }

    bool  isEmpty(){

return top==NULL;
    }
    
 void push(int x){
        
    if(isFull()){
        cerr<<"stack overflow\n"<<endl;
        return ;
    }
      
      Node *temp = new Node();
      temp->data =  x ;
      temp->next = top; 
      top=temp ;
 } ; 


int  pop(){
int x =-1;
    if(isEmpty()){
        cerr<<"Stack underflow\n"<<endl;
        return x; 
    }
   x =  top->data ; 
   Node *p = top ; 
    top= top->next ; 
    delete p ;   
   
return x;
}

void Display(){

    Node *p = top; 
    while (p)
    {
        /* code */

        cout<<p->data<<" ";
        p=p->next ;
    }
    
}
    private:
    Node *top = NULL;
};


int main(){
 
  
 LStack s;
 s.push(5);
  s.push(4) ;
  s.push(15);
  s.push(19);
  s.Display();


 cout<<s.pop()<<endl;
 s.Display();

}