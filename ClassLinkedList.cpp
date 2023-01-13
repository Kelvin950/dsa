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


int Max(){

 Node  *p =  first ;

int max =  INT32_MIN;

  while(p){

    if(p->data >max){
             max = p->data;
    }
     p=p->next;
  }

return max ; 

}

int Min(){
  
   Node *q =  first->next;
 int min =first->data;
   while (q)
   {
    /* code */
             if(q->data < min){
               min =  q->data;
             }
            
              q=q->next ;
              
           
   }
   
     return min ;
}

int LinearSearch(int key){


Node *p =first;
Node *q ;
while (p)
{
  /* code */
  if(p->data == key){
          q->next = p->next;
          p->next =  first;
          first = p;

          return p->data;
        

  }
  q=p;
p= p->next ;
}


 

return -1;
}



int Sum(){
       
         int sum = 0 ;
         Node *p = first ;
     while (p)
     {
      /* code */
       sum+=p->data; 
       p=p->next ;
     }
     
  return sum;
} 


void Reverse(){

Node * p =first ;
Node  *r =  NULL ; 
Node *q= NULL;


    while (p)
    {
      /* code */
      r=q ;
      q=p;
      
      p=p->next ;
      q->next = r;
    }
    first = q;
 

}


void Concatenate(LinkedList *list){
  Node * p =first ;
  Node *q;
      if(first== list->first){
        return  ;
      }
   while (p)
   {
    /* code */
    q=p;
    p=p->next;
   }
              

     q->next =  list->first;

}

void Merge(){
  
}

} ;



int main(){



    LinkedList *list =  new LinkedList();
    LinkedList *list2 =  new LinkedList();
       cout<<list->Length()<<endl;
    int A[] =  {1,2,3,4};

      int b[]= {10,12,13,14} ;
      list->Create(A , 4);
      list2->Create(b,4);
         
        list->display();
  list->Concatenate(list2);
   list->display();
        
}