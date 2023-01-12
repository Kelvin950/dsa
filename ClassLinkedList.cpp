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
        temp->next =  p->next ;
             p->next =  temp ;
               size++;
            
            }
   } 


   int Length(){

    return  this->size;
   }

} ;


