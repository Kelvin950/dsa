#include <iostream>

using namespace std ;


struct Node{
    int data ;
    struct Node *next ;
}*first ;


void create(int  A[], int n){

int i ;
struct Node *t , *last;

first = new struct Node ;
first->data = A[0] ;
first->next = nullptr;
last =first;

   for(i =1 ; i<n ;i++){
     t=  new struct Node;
     t->data =A[i];
     t->next =nullptr;
     last->next=t ;
     last =t ;
   }


}

void display(struct Node *p){

    while(p){

        cout<<p->data ;
        p= p->next ;
    }
}
int main(){


    int A[5] =  {1,2,3,4,6} ; 
    create(A,5);
    display(first);
}
