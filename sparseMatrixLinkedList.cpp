#include <iostream>

using namespace std; 


class Node{
        
        public:
    int column; 
    int value;
    Node *next;
}; 




int main(){


  Node *A = new Node[2];
 

for(int i = 0 ; i < 2; i++){
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
    
 A[i].next =  first ;
} 
 
 
 for(int i = 0 ; i<2 ;i++){
     Node *p = A[i].next;
    for(int j =0 ;j<2 ;j++){
        if(j==p->column){
         cout<<p->value ; 

         if(p->next){
            p=p->next;
         }
    }}
 }

}