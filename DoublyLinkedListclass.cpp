#include <iostream> 


using namespace std; 


class Node{

public:
  Node *next ; 
  Node *prev;
  int data;

  Node(){

  }

} ; 


class DoublyLinkedList{
 


  public :
     DoublyLinkedList(){
         
         size = 0 ;

     }
    //  ~DoublyLinkedList(){
    //        delete first ;
    //        delete last ;
    //  }
       

     void   Create(int A[] , int n){
     
     Node *temp = new Node();
     temp->data = A[0]; 
     temp->prev=NULL;
     temp->next =NULL;
     first =temp; 
      last=  first;   
      this->size++;
             
             for(int i = 1 ; i < n ;i++){
                 
             Node *temp = new Node() ; 
             temp->data = A[i];
             temp->prev =  last  ;
             temp->next = NULL;
             last->next =  temp ;
             last =temp;
                  size++;
              

             }
      
       }


 void Insert(int x , int index){


     if(index <0 || index > size){
        return ;
     }
       
       Node *temp =  new Node(); 
       temp->data = x;

      if(index ==0){
          
           if(first == NULL){
             
             temp->prev = NULL;
             temp->next = NULL;
             first = temp; 
             last=first ;
           }
          else{

          first->prev  = temp ; 
          temp->next =first ;
          first = temp ;

          }

 
  
       } 

       else{
        Node *p = first ;Node *q;

          for(int i= 0 ;i<index -1  ;i++){
             
             p=p->next ;
          } 

    
            q= p->next;
          

         temp->next =p->next ;
         if(q){
        q->prev =  temp ; 
         }
        
         p->next =  temp ;
         temp->prev =  p;

       }

 }


void Reverse(){

Node *p = first ; 
Node  *q ;
while(p){
    //   cout<<p->data;
      q = p->next ;
    p->next = p->prev ;
    p->prev = q;
     p =p->prev;

     if(p!=NULL && p->next==NULL ){
      first= p ;  
     }
}



}

void Display(){
  Node *p  =  first ; 
    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }

}
 private:
  int size ; 
  Node *first ;
  Node *last;

} ; 


int main(){


    int A[5] = {1,2,3,4,5};
         
        DoublyLinkedList *doubly =  new DoublyLinkedList();
        doubly->Create(A , 5);

        doubly->Reverse();
        doubly->Display();

}