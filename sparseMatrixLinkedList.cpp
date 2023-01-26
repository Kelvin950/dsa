#include <iostream>

using namespace std; 


class Node{
        
        public:
    int column; 
    int value;
    Node *next;
}; 


Node *Add(Node *A , Node *B ,int n){

          int  i = 0 ; 
          int j = 0 ;
   Node *C =  new Node[n];

   while(i <n && j<n ){
      
      Node  *p = A[i].next ; 
      Node *q = B[i].next; 
      cout<<q->value<<p->value<<endl;
      Node *first=NULL ,*last=NULL;
      

         while (p || q)
         {
            /* code */
         if(p && q){


               if(p->column < q->column){
                  Node *temp = new Node();
                  temp->column  =p->column ;
                  temp->value = p->value ; 
                  if(first==NULL){
                    first=temp ;
                    last=first;
                    cout<<first->value<<endl;
                      
                  } 
                  else{
                     last->next=temp;
                     last=temp;
                     cout<<last->value<<endl;
                  }
                 p=p->next ;
               }
               else if(p->column > q->column){

                  Node *temp = new Node();
                  temp->column  =q->column ;
                  temp->value = q->value ; 
                  if(first==NULL){
                    first=temp ;
                    last=first;
                    cout<<first->value<<endl;
                      
                  } 
                  else{
                     last->next=temp;
                     last=temp;
                     cout<<last->value<<endl;
                  }
                q=q->next ;
               }

            else{

                Node *temp = new Node();
                  temp->column  =q->column ;
                  temp->value = q->value + p->value ; 
                  if(first==NULL){
                    first=temp ;
                    last=first;
                    cout<<first->value<<endl;
                      
                  } 
                  else{
                     last->next=temp;
                     last=temp;
                     cout<<last->value<<endl;
                  }
                q=q->next ;
                p=p->next;
               }
            }
         else if(p && !q){
              
              Node *temp = new Node();
                  temp->column  =p->column ;
                  temp->value = p->value ; 
                  if(first==NULL){
                    first=temp ;
                    last=first;
                    cout<<first->value<<endl;
                      
                  } 
                  else{
                     last->next=temp;
                     last=temp;
                     cout<<last->value<<endl;
                  }
                 p=p->next ;
             
         }
      else if(!p && q){
         Node *temp = new Node();
                  temp->column  =q->column ;
                  temp->value = q->value ; 
                  if(first==NULL){
                    first=temp ;
                    last=first;
                    cout<<first->value<<endl;
                      
                  } 
                  else{
                     last->next=temp;
                     last=temp;
                  }
                 q=q->next ;
      }

         }
         cout<<first->value;
             C[i].next = first;
         i++;
         j++;
         }
         

         return C;

   } 



void Create(Node *q, int row){
for(int i = 0 ; i < row; i++){
    cout<<"Enter the number of non-zero values in the row"<<endl;
    int column ;
    cin >>column ;
    Node *first=NULL;
    Node *last =NULL;
    for(int j = 0 ; j<column ;j++){
        
             Node *t= new Node();
             cout<<"Enter the value"<<endl;
             cin>>t->value; 
             cout<<"Enter the column"<<endl;
             cin>>t->column;
             if(first==NULL){
                first=t ; 
                last=first ;
             }
             else{
                last->next = t;
                last=t;
             }


}
    
 q[i].next =  first ;
} 


}


void Display(Node *q , int row,int col){

 
 for(int i = 0 ; i<row ;i++){
     Node *p = q[i].next;
    for(int j =0 ;j< col;j++){
        if(j==p->column){
         cout<<p->value ; 

         if(p->next){
            p=p->next;
         }
    }
    else{
      cout<<"0";
    }
    }
    cout<<endl;
 }

}
int main(){


  Node *A = new Node[5];
  Node *B =  new Node[5];
 
Create(A , 5);
Display(A , 5,6);
 

Create(B ,5);
cout<<endl;
Display(B , 5, 6);
 

 Node *C =  Add(A ,B , 5);
cout<<endl;
 Display(C, 5,6);
}