#include <iostream>

using namespace std;


struct Node{
    int data ; 
    struct Node *next ;

}*Head ;


void create(int  A[ ] , int n){

 int i;
 struct Node  *t , *last;
 Head =  new struct Node()     ;
 Head->data= A[0];
 Head->next = Head ; 
last =Head; 
 for( i = 1  ; i <n ; i++){
      
      t=  new struct Node();
      t->data = A[i];
      t->next = last->next;
      last->next= t ;
      last = t;
 }
}
 
 int Length(struct Node *p){
int count = 0 ;

do{

  count++;
    p=p->next ; 
}
while (p!=Head);


return count ;
     
 }
void insert(struct Node  *p ,int  pos , int x){

 
 struct Node *t ;
 int  i ;

 if(pos < 0  || pos > Length(p))return;
 
 if(pos ==0){
    t =new struct Node();
    t->data = x ;
    if(Head == NULL){
        Head =  t;
        Head->next =Head ;
    }
    else{
        while (p->next !=Head)

        {
            /* code */
            p=p->next ;
        }
        
        p->next = t;
        t->next=Head ;
        Head =t ;
    }
 }

 else {
      for(i = 0 ;i<pos-1 ;i++){
         
         t= new struct Node();
         t->data =x; 
         t->next =  Head ;
         t->next =  p->next;
         p->next = t;
          
      }

 }


}

int Delete(struct Node *p,  int index){

    struct Node *q ;
    int i ,x ;

    if(index < 0  || index > Length(Head)){
        return -1 ;
    }

    if(index == 1){
         
         while (p->next  != Head)p=p->next;
         
         x = Head->data ;
         if(Head ==p){
            delete  Head;
         }
         else {
                p->next =  Head->next;
                delete Head ;
                Head=p->next;
         }
         
    }
    else{
        for(i = 0 ; i<index-2 ;i++){
            p=p->next ;
        }
        q=p->next;
        p->next = q->next;
        x=q->data ;
        delete  p; 
    }
    return x ;
}
void Display(struct Node *p){

     do{
        cout<<p->data ;
        p=p->next;
     }while(p!=Head);

}


void Reverse(struct Node *p){


    struct Node *q  =NULL;
    struct Node *r =NULL; struct Node *v = Head; 
   
   
    do{
           r=q ;
          q=p;
         
          p=p->next ;
          q->next = r ;
        
    }while(p != Head) ;
      
      Head->next =  q ; 
      Head =  q ; 

}
int main(){

    int A[]={1,2,3,4,5};

    create(A,5);
    // Delete(Head , 1);
        // Display(Head);

        // cout<<Length(Head)<<endl;
        Reverse(Head);
        Display(Head);
        // cout<<Head->data;
    return 0 ;
}