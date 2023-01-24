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
            cout<< p->coff<<"x"<<p->exp<<"+ ";
            p=p->next ; 
          }
     }

   Polynomial * Add(Polynomial *second){

         Node *p =  this->first;
         Node *q =  second->first;
   Polynomial *z = new Polynomial();
         while(p && q){

            if(p->exp > q->exp){
                Node *temp = new Node();
                        temp->exp = p->exp ;
                        temp->coff= p->coff;
                    if(z->first==NULL &&p==first &&q == second->first){
                        
                       z->first = temp ; 
                       z->last = temp;
                         p=p->next;
                       cout<<z->first->coff<<endl;
                    }else{
                           
                            z->last->next=temp;
                            z->last = temp;
                              p=p->next;
                              
                    }

                   
            }else if(p->exp < q->exp){
                        Node *temp = new Node();
                        temp->exp = q->exp ;
                        temp->coff= q->coff;
                if(z->first==NULL &&p==first &&q == second->first){
                       
                       z->first = temp ; 
                       z->last = temp;

                      
                    
                    }else{
                            // Node *temp = new Node();
                            // temp->exp = q->exp ;
                            // temp->coff = q->coff;
                            z->last->next=temp;
                            z->last = temp;
                            // q=q->next;
                    }

                 q=q->next;
            }
            else{


                    Node *temp = new Node();
                    temp->exp = p->exp;
                    temp->coff = q->coff + p->coff ; 
                    if(z->first==NULL &&p==first &&q == second->first){
                        
                       z->first = temp ; 
                       z->last = temp;
                         p=p->next;
                         q=q->next;
                    }
                    else{

                    


                    z->last->next = temp;
                    z->last =temp;
                    p=p->next;
                    q=q->next ;}
            }

         }
    
return z ; 
     }

 private:
Node *first =NULL;
Node *last =NULL;

 };


 int main(){


     Polynomial *p =  new Polynomial();

     p->Create();
     p->Display();
         

         Polynomial *q = new Polynomial();
        q->Create();
        p->Display();
    
    Polynomial *r = p->Add(q);
    cout<<endl;
    r->Display();

 }