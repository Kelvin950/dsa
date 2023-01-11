#include <iostream>

using namespace std ;


struct Node{
    int data ;
    struct Node *next ;
}*first , *second = NULL,*third = NULL ;


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

void create2(int  A[], int n){

int i ;
struct Node *t , *last;

second = new struct Node ;
second->data = A[0] ;
second->next = nullptr;
last =second;

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

void Rdisplay(struct Node *p){

    if(p!=NULL){
        cout<<p->data ;
        Rdisplay(p->next);
    }
}

int count (struct Node *p){
    
    int c = 0 ;

    while(p){

          c++ ;
           p= p->next;
    }

return c;

}

int sum(struct Node *p){

    int s =0 ;
    while (p)
    {
        /* code */
        s+=p->data;
        p=p->next ; 
    }
    
    return s;
}

int Max(struct Node *p){

    int max = INT32_MIN;
    while(p){
        if(p->data>max)
                max=p->data;
        p=p->next;
    }

    return max;

}

int Min(struct Node *p){

    int min = INT32_MAX;
    while(p){
        if(p->data<min)
                min=p->data;
        p=p->next;
    }

    return min;

}

struct Node * LSearch(struct Node *p,int key)
{
struct Node *q;
while(p!=NULL)
{
if(key==p->data){
q->next=p->next;
p->next=first;
first=p;
return p;
}
q=p;
p=p->next;
}




return NULL;
}

void insert(struct Node *p , int index , int x){

struct Node *temp ; 
   if(index  < 0 || index>count(p) ){
    return ;
   }
   

   temp =  new struct Node();
   temp->data =  x ; 

if(index ==0){

    temp->next =  first ;
    first = temp;
}       
else{

    for(int i = 0;i<index-1 ;i++){

         p=p->next ;
    

    }

    temp->next = p->next ;
    p->next =  temp;
}

}


void insertSorted(struct Node *p , int value){
 
 struct Node *q = NULL; 
 
 struct Node *t = new struct Node();
 t->data =  value ; 
 t->next =NULL ; 

     
     if(first==NULL){

        first =  t;
     }
  else{

    while(p && p->data< value){
         
        
        q=p ;
        p=p->next ;}
    
    if(p==first){
        t->next=first ;
        first=t ;
    }else{

        t->next = q->next ; 
        q->next = t ;
    }
    }
  


}


int Delete(struct Node *p , int index){

    struct Node *q=NULL;

    int x = -1 ;

    if(index <1  || index  > count(p)){
            
            return -1;

    }

    if(index ==1){

        q=first ; 
        x = first->data;
        first=first->next;
        delete q;
        return x;
    }
    else{
             for(int i = 0 ; i<index-1 ; i++){
                q=p;
                p=p->next;
             }

             q->next  =p->next;
             x=p->data ;
             return x ;
             delete p;
    }

  }

 bool isSorted(struct Node  *p ){

     struct Node *q =  p->next ; 

cout<<q->data<<endl;
  while (q)
  {
    /* code */
    if(p-> data > q->data){
        return false;
    }

    p=q ; 
    q=p->next ;
  }
  
return true ;
 }

 void removeDuplicate(struct Node *p){

    struct Node *q =  p->next ;

    while (q)
    {
        /* code */

        if(p->data !=q->data){
            p= q;
            q=p->next ;
        }
        else{
            p->next =  q->next ;
            delete q ;
            q=p->next;
        }
    }
    
 }

 void Reverse(struct Node *p){
 
 struct Node  *q =  NULL ,*r =NULL;
 

while(p != NULL){
    r=q ; 
    q=p;
    p=p->next ;
    q->next =  r;
}


 
first=  q ;

     
 }

 void Concat(struct Node *p , struct Node *q){

    third =p ; 

    while (p->next !=NULL)
    {
        /* code */
        p=p->next ;


    }
    p->next =  q ; 
    
 }
 
 void Merge(struct Node *p , struct Node *q){

    struct Node *last ;
    if(p->data < q->data){
        third= last = p;
        p=p->next ;
        third->next =NULL;
    }
    else{
        third = last=q;
        q=q->next ;
        third->next =NULL;
    }

    while (p && q)
    {
        /* code */
        if(p->data <q->data){
            last->next=p ;
            last=p;
            p=p->next ;
            last->next=NULL;
        
        }

        else{
            last->next =q;
            last=q;
            q=q->next;
            last->next= NULL;
        }

    }


    if(p!=NULL)last->next = p;
    if(q) last->next= q;
             
 }

 int isLoop(struct Node *f){

    struct Node *q  ;struct Node *p ;

do{
    p=p->next ;
    q=q->next;
    q= q? q->next : q;
}while(p && q && p != q);
         
        
        if(p==q){
            return 1;
        }
        else return 0;

 }
int main(){
 

 struct Node *t1 , *t2 ;


    int A[5] =  {1,2,3,4,6} ; 
    create(A,5);

    // t1 = first->next->next;
    // t2=first->next->next->next->next;
    // t2->next = t1;
    //  cout<<"length of linked list "<<count(first)<<endl;
    //  cout<<"sum of linked list "<<sum(first)<<endl;
    //  cout<<"Maximum number "<<Max(first)<<endl;
    //   cout<<"Minimum number "<<Min(first)<<endl;

// struct Node  *temp = LSearch(first, 4) ;
//       if(temp){
//         cout<<"Key found "<<temp->data;
//       }
//       else cout<<"key not found";
    
 
    // insert(first , 3 , 10);
    // insertSorted(first ,  5);
    // insertSorted(first , 10);
//     display(first);
//    cout<<isSorted(first)<<endl;
     
 
cout<<isLoop(first);
}
  