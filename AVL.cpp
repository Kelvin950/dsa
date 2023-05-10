#include <iostream> 


using namespace  std ;

class Node{

public:
Node *lchild;
Node *rchild ;
int height ;
int data ;

} ; 

Node *root = NULL ;



Node  *RInsert(Node *p , int key){
      

Node *t ; 
if(p==NULL){
  
  t = new Node() ;

  t->data =  key ;
  t->height =1; 
  t->lchild=t->rchild=NULL;

return t  ;
}


else if(p->data > key ){
    
    p->lchild= RInsert(p->lchild , key) ;
}

else if(p->data < key){
     
     p->rchild =RInsert(p->rchild , key) ; 
}

return  p; 



}


void Inorder(Node *p){

    if(p){
     
     Inorder(p->lchild) ;
     cout<<p->data <<endl;
         
        Inorder(p->rchild) ; 
    }
}


int Height(Node *p){
int x ,y ;

    if(p){
    x =  Height(p->lchild) ;
    y= Height(p->rchild) ;


    if(x>y){
        return x+1 ;
    }
    else return y+1 ;



    }

    return 0 ;
}

int main(){


root =  RInsert(root , 10) ;
RInsert(root , 5) ;
RInsert(root , 3) ;

Inorder(root) ;

cout<<Height(root)<<endl;

}

