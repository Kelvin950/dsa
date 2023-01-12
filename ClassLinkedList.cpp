#include <iostream>

using namespace std; 

class Node{

public:
  int data ; 

  Node *next ;
         
         Node(){

            this->data =0 ;
           
         }
} ;


class  LinkedList{
 

 private:
 Node *first ; 
 Node  *last ;
 int size ; 


   public :
   LinkedList(){
         size = 0 ;
         last=first=NULL;
   }


  void Insert(int pos , int data){
            


        
            if(pos < 1  && pos >size){
                return ;
            }
  Node *temp = new Node();
          temp->data =  data ;
            if(pos==0){

          temp->next =NULL;
          first = temp;
          if(!last){
            last=temp;
          }
               size++;
            }
            
            else{
                Node *p = first;
                
        for(int i= 0 ; i<pos-1 ; i++){

          p= p->next ;  
                
        }       
        temp->next =p->next ;
           p->next =  temp ;
          
               size++;
                 
            }
   } 


   int Length(){

    return  this->size;
   }

 
  void Create(int A[] , int  n){

    Node *temp =  new Node();
    temp->data  =A[0] ;
       first = temp ;
       last =temp ; 
       size++;
      
      for(int i= 1 ; i<n ;i++){
            Node *temp =  new Node();
    temp->data  =A[i] ;
      last->next = temp;
          last=temp;
          last->next = NULL;
          size++;
       }

  }
void display(){
 
 Node *p =  first;

    while(p){
        cout<<p->data<<endl;
        p=p->next ;
    }
}
} ;



int main(){



    LinkedList *list =  new LinkedList();
       cout<<list->Length()<<endl;
    int A[] =  {1,2,3,4};
      
      list->Create(A , 4);
         
        list->display();
    list->Insert(4 , 5);
    list->display();
        cout<<list->Length()<<endl;
}