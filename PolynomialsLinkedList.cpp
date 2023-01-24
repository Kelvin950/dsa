#include <iostream>

using namespace std; 


class Node{
      public:
 int coff;
 int exp;
 Node *next ;
} ;


class Polynomial{

        public:
     Polynomial(){
          
    
     } 

     void Create(){
              int term;  
        cout<<"Enter the term of the polynomia"<<endl;
        cin>>term;
        
        for(int i = 0 ; i<term ;i++){
                 Node *temp = new Node();

            cout<<"From the highest exponent to the lowest enter the coefficient and the exponential"<<endl;
            cin>>temp->coff;
            cin>>temp->exp ;
            if(first ==NULL){

                first=temp ;
                last=first ;
            }
            else{

                last->next =  temp ;
                last=temp;
            }
        }

     } 

     void Display(){
          Node  *p =  first;

          while(p){
            cout<< p->coff<<"x"<<p->exp;
            p=p->next ; 
          }
     }

 private:
Node *first =NULL;
Node *last =NULL;

 };


 int main(){


     Polynomial *p =  new Polynomial();

     p->Create();
     p->Display();

 }