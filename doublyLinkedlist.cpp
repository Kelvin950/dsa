#include <iostream>

using namespace std;
struct Node{
    
    struct Node *prev ;
    int data;
    struct Node *next ;
} *first =NULL;


void create(int  A[] , int n){

    struct Node  *t ,*last;
    int  i;

    first  =  new struct Node();
    first->data =  A[0];
    first->prev =  first->next=NULL;
    last=first;

    for(i = 1 ;i<n;i++){
        t=new struct  Node();
            t->data = A[i];
            t->next = last->next ;
            t->prev =last;
            last->next =t ;
            last = t;
        
    }
    
    }


void Display(struct Node *p){


    while (p)
    {
        
        /* code */
        cout<<p->data ;
        p=p->next ; 
    }
    
}

int Length(struct Node *p ){

      
      int count= 0 ;
          
        while(p){

            count++ ;
            p=p->next ;
        }

        return count;


}

void Insert(struct Node *p , int index , int x){


    struct Node *t ;
    int i;

    if(index  < 0 || index > Length(p)){
        return ;
    }

    if(index == 0 ){

        t= new struct Node();
        t->data= x ;
        t->prev = NULL;
        t->next =  first;
        first->prev =  t ; 
        first = t;
 
    }
    else{

             for(i = 0 ;i<index-1 ;i++){
                p=p->next ;
             }
        t=  new struct Node();
        t->data =x ; 

     t->prev = p ;
     t->next= p->next ;      

     if(p->next)p->next->prev =t;
     p->next =t; 
    }
}

int main(){

 int A[5] = {1,2,4,5,6};

 create(A ,5);

Insert(first , 2 , 3);
    Display(first);

    
}