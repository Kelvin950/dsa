#include <iostream> 
using namespace  std;
class Node{

public:
int data ; 
Node  *prev ;
Node  *next;

} ; 


class CircularDoublyLinkedList{


   public:
      CircularDoublyLinkedList(){
        size = 0 ;
      } 


     void Create(int A[] , int n){

    Node *temp = new Node();
     temp->next = temp ; 
     temp->prev = temp;
     temp->data = A[0];
       Head =  temp ; 
        last = temp ;
        size++ ;
        
             for(int  i= 1 ; i< n ; i++){ 
                Node *temp = new Node();
                temp->data = A[i];
                last->next = temp ; 
                temp->prev =  last ;
                last = temp ;
              last->next =  Head ;
              Head->prev = last ;
              size++;
             }        
      }

      void Insert(int index , int x){

        if(index < 0  || index > size){
           return ; 

        } 
        Node *temp =  new Node();
        temp->data =  x; 
        ;

        if(index==0){
               
               if(Head == NULL){
                   temp->next =  temp ;
                   temp->prev =  temp ;
                   Head=  temp ; 
                   last =  temp;
                   size++;
                 }else{

                        temp->next =  Head ;
                        temp->prev = Head->prev ;
                        Head->prev->next =  temp ;
                        Head->prev =  temp ;
                        Head=  temp ;
                        size++;
               } 
        }
        else{
              Node *p =  Head ; 
             for(int i =0 ;  i<index-1 ;i++){
                 p=p->next ;
             }
               temp->next =  p->next ; 
               p->next->prev =  temp ;
               temp->prev  = p;
               p->next= temp;
               size++;


        }
      }

      int  Delete(int index){
            

            if(index <0  || index >size){
                return -1;
            }

            if(index == 0){

                    if(Head == NULL){
                        return -1 ;
                    } 

             
             Node *q =  Head->next ; 
             q->prev =  Head->prev ;
             Head->prev->next =q ;
             int x =  Head->data ;
                delete Head ; 
                Head =  q ;  
                 size--;
                return x;
            }
            else{
                Node *p =  Head ;
            for(int  i = 0 ; i< index-1; i++){
                      p=p->next ;
            }
             p->prev->next = p->next ;
             p->next->prev = p->prev ; 
             int x=  p->data;
             delete p; 
             return x;

            }
            

      }

      void Reverse(){
            
            Node *p = Head ; 
            Node *q; 
            do
            {
                q =p->next;  
                p->next = p->prev;
                p->prev= q ;
              
             p=p->prev ;
              
          
                /* code */
            } while (p!= Head);
           
           Head = p->next;
      }

void Display(){

      Node *p =  Head ;

      do
      {
        /* code */
        cout<<p->data <<endl;
        p=p->next;
      } while ( p!= Head);
      
}
    private:
    Node *Head ;
    Node *last ;
    int size ;
}
 ;


int main(){

     
     int A[5]={1,2,3,4,5};
     CircularDoublyLinkedList *list=  new CircularDoublyLinkedList();
      list->Create(A ,5);
       list->Reverse();
      list->Display();

}
