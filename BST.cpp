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
    
    p = new Node() ;
    p->data =  key ; 

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

}


int main (){
 

 insert(4) ;

 


}