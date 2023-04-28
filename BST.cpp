#include  <iostream> 


using namespace  std ; 



class  Node {
 
 public: 
 Node *lchild ;
 int data ; 
 Node *rchild; 

} 
;


Node *root  =NULL ;


void insert(int key){

Node *t=root  ;

Node *r , *p = NULL; 

  
if(root ==NULL){
    
    root = new Node() ;
    root->data =  key ; 
 root->lchild = root->rchild =NULL ;
}

 while (t)
 {
  
 r=t; 

  if(t->data ==key){
    return ;
  }

  if(t->data < key) {
           r=t ; 
    t=t->rchild ; 
  }
  else  {
      r=t ;
      t=t->lchild;
  }
 }

 p = new Node() ;
    p->data =  key ; 
     p->lchild = p->rchild =NULL ;

     if(r->data > key)
        r->lchild =  p  ;
    else  
        r->rchild = p;
}


bool Search(int key){

Node *t =root; 


while (t)
{ 

    if(t->data ==key){
        return  true ;
    }
 
 if(t->data > key){
       
       t=t->lchild ;
 }
 else {

t=t->rchild; 
 }

    /* code */
}

return false;


}


void inorder(Node *p){

 
 if(p){
 
  inorder(p->lchild); 
  cout<<p->data ; 
  inorder(p->rchild) ;
 }

}

int main (){
 

 insert(5) ;
insert(3)  ;



 inorder(root) ;

}