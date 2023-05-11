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
  return;
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


int Height(Node *p){

int x , y ;

    if(p){
 
 x =  Height(p->lchild) ;

y = Height(p->rchild) ;
       

return   x>y? x+1 : y+1;
 
    }
    return 0 ;
}

void inorder(Node *p){

 
 if(p){
 
  inorder(p->lchild); 
  cout<<p->data ; 
  inorder(p->rchild) ;
 }

}


 Node * RInsert(Node *p , int key){
 

 Node *t =NULL; 

 if(p==NULL){
    t= new Node() ;
    t->data =  key ;
     t->lchild = t->rchild =NULL; 

     return t ;
 }


 if(p->data > key){
    p->lchild =  RInsert(p->lchild , key) ;
 }

 else if(p->data < key){
    p->rchild =  RInsert(p->rchild , key) ;
 }



return p ;
  


}


Node *minimum(Node *p){


    while(p->lchild){
         p=p->lchild ;
    }

    return p ;
}


Node *maximum(Node *p){

    while (p->rchild){
 

 p=p->rchild ;
    }
        /* code */
    
    return p;
}

Node *inSucc(Node *p){ 


while (p && p->lchild)
{
    /* code */
    p=p->lchild ;
}

return  p ;

}

Node *inPred(Node *p){
 

while (p && p->rchild)
{
    /* code */
    p=p->rchild ;
}

return p;
}


Node *Delete(Node *p , int key){
  

Node *q=NULL; 

if(p==NULL){
    return NULL;
}
 
if(!p->rchild  && !p->lchild){
      

 if(p==root){
    root=NULL ;
  }

 delete p ;
 
 return NULL ;
 
    

}

if(p->data > key){

p->lchild = Delete(p->lchild, key);
}

else if(p->data < key){
 p->rchild= Delete(p->rchild,key);
} 
  
else{

if(Height(p->lchild) > Height(p->rchild)){
  

  q =  inPred(p->lchild) ;
  p->data = q->data ; 

  p->lchild = Delete(p->lchild, q->data);


}
else{


  q =  inSucc(p->rchild) ;
  p->data = q->data ; 

  p->rchild = Delete(p->rchild, q->data);
}


}

return p ;

}

int main (){
 

 root = RInsert(root  , 10) ;
RInsert(root , 15)  ;
RInsert(root, 6) ;
RInsert(root , 7) ;
RInsert(root ,5);



Delete(root , 5) ;
Delete(root,  15);
cout<<Height(root) <<endl;
inorder(root) ;
}