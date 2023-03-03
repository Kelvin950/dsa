#include <iostream>
 
using namespace std ; 


 
 class Node{

    public:
    Node *leftChilld; 
    Node *rightChild;
    int data;
 } ;

class Nodequeue {
 
 public:
Node *data = NULL ; 
 Nodequeue *next; 

};

class Queue{
 
public:
 Queue(){
     
     front= NULL;
     rear= NULL;

 }


 bool isEmpty(){

   return  front ==NULL;
 }
 
 
 void enqueue(Node  *x){
      
      Nodequeue *temp = new Nodequeue();
      
      if(temp ==NULL){
        return;
      }
    
    temp->data =x ;

    if(isEmpty()){
        front =rear= temp ;
    }else{
      
      rear->next =  temp ; 
      rear=temp;

    }
     
 }
 

 Node * dequeue(){

    Node *x = NULL ; 

    if(isEmpty()){
        return  NULL;
    }

    Nodequeue *q = front ; 
    front =front->next ;

    x = q->data ;
     delete q ;

return x ; 
 }

 void display(){

    Nodequeue  *q = front ; 
     
     while (q)
     {
        /* code */
        cout<<q->data->data<<endl;
        q=q->next ;
     }
     
 }
private:
Nodequeue *front ; 
Nodequeue *rear ; 
} ;


  
class BTree{
         
         public:

         BTree(){
            root = NULL;
         }
    
    void Preorder(Node *p) {Preorder(root) ;};
    void Postorder(Node *p){
      Postorder(root); 
    };
    void Inorder(Node *p){
   Inorder(root);
    };
    void CreateTree(){

     Node *p=NULL  ; Node *t=NULL;
    Queue *queue= new Queue();
      int data ; 
 cout<<"Enter the data of the root"<<endl;
 cin>>data ; 

    root =  new Node() ;
    root->data =  data ;
    
     queue->enqueue(root);  
      

      while(!queue->isEmpty())
{


  p = queue->dequeue(); 
int x ; 
   cout<<"Enter the value of left child, Enter -1 if null"<<endl; 
cin >>x ;
    
  if(x!=-1){
  t =  new Node(); 
  t->data =x ; 
  p->leftChilld =  t ;
  queue->enqueue(t);
  }  

   cout<<"Enter the value of right child, Enter -1 if null"<<endl; 
cin >>x ;
    
  if(x!=-1){
  t =  new Node(); 
  p->rightChild =  t ;
  t->data =x ; 
  queue->enqueue(t);
  }  




}  

    };
    void LevelOrder(Node *p);
    void Height(Node *root);
   void  CreateRoot(int data){
        
    root->data =  data ;
     

     }
   
 Node *Root(){

    return root;
 }


private:
    
    Node *root ; 
   

} ;

void BTree::Postorder(Node *p){
   

 if(p){

         
      Postorder(p->leftChilld);
      Postorder(p->rightChild);
      cout<<p->data;
        }      
    };


    void BTree::Inorder(Node *p){
      if(p){

         
    Inorder(p->leftChilld);
      cout<<p->data;
    Inorder(p->rightChild);
      
        }    
    };


void BTree::Preorder(Node *p){

        if(p){

         cout<<p->data;
      Preorder(p->leftChilld);
      Preorder(p->rightChild);
        }
}



int main(){

BTree  *Tree =new BTree();

Tree->CreateTree();


    return 0 ;
}