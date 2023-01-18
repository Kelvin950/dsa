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

void Merge(LinkedList *list){
         Node *p = first ,*third =NULL , *last=NULL;
     Node *q =  list->first;     
    if(p->data < q->data){

        last=third= p ;
        p=p->next ; 
        last->next = NULL;
       }
       else{

         last=third= q ;
        q=q->next ; 
        last->next = NULL;
       }
    while(p!=NULL && q != NULL){
       

       if(p->data < q->data){
                   
                    last->next  = p ;
                    last=p ;
                     p=p->next;
                    last->next = NULL;
                   
       }else{
              last->next  = q ;
                    last=q ;
                      q=q->next;
                    last->next = NULL;
                  

       }
    }

    if(p!=NULL){
              last->next =  p;  

    }
    if(q !=NULL){
             last->next=q;
    }
      
         first =third ;
}

} ;


Node *reverse(Node *p){
 
  Node *q =NULL,*r=NULL; 

  while(p){

    r =q ;
    q= p ;
    p=p->next ;
    q->next =r ;
  }

    
return q ;

}


Node *addTwoLinkedList(Node *a , Node *b){

 int carry = 0 ;
 Node *sum =NULL;
    
 a = reverse(a);
 b =  reverse(b); 

 while (a || b ||carry)
 {
  /* code */ 
  int x  =  a ? a->data: 0 ;
  int y =  b ?b->data : 0; 

    Node *temp = new Node();
    temp->data =  (carry + x + y) % 10000 ;
    temp->next =  sum;
    sum =temp ;

    carry =  ((carry + x + y) /10000) | 0 ;   


     if(a)a=a->next ;
     if(b) b=b->next;   

 }
 
return sum;

}
int main(){

 Node *first= new Node();
   
   first->data =  3 ; 
  
  for(int i =1  ; i<=3 ;i++){
      
      Node *temp =  new Node();
      temp->data = i*4 ; 
      
      temp->next = first ; 
      first=temp ;

  }

 Node *second=  new Node();

 second->data =  5 ; 

 for(int i =  3  ; i<=6 ;i++){

  Node *temp = new Node() ; 
  temp->data=  i*2 ; 
  temp->next  =second ; 
  second= temp ;
 }



Node *result =  new Node() ;
result = addTwoLinkedList(first, second);     

 
 int a =  (10000/10000);
 a = (a| 0);
cout<<a<<endl;


}