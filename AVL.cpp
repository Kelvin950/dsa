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



int newHeight(Node *p){

    int hl = p &&p->lchild ? p->lchild->height :0 ;
    int hr = p &&p->rchild ? p->rchild->height : 0 ;

    return hl>hr ? hl+1 : hr+1 ;

}


int BalanceFactor(Node *p){
    int hl = p &&p->lchild ? p->lchild->height :0 ;
    int hr = p &&p->rchild ? p->rchild->height : 0 ;

    return hl -hr ;
}


Node * llRotation(Node *p){
Node *pl = p->lchild ;
Node *prl =pl->rchild ;

pl->rchild =  p ;
p->lchild = prl ;

p->height =  newHeight(p) ;
pl->height = newHeight(pl) ;



if(p==root){
    root= pl ;
}

return pl ; 

}


Node  *lrRotation(Node *p){
 
 Node *pl =  p->lchild ;
 Node  *plr =  pl->rchild;


 p->lchild = plr->rchild ;
 pl->rchild = plr->lchild ;
  

  plr->rchild =  p ; 
  plr->lchild = pl ;

 p->height =  newHeight(p);
 pl->height = newHeight(pl); 
 plr->height = newHeight(plr) ;


 if(root==p){
    root=plr ;
 }


return plr ;
}

Node *rrRotation(Node *p){
   
  Node *pr = p->rchild ; 
  Node *prl=  pr->lchild ;

  pr->lchild =  p ;
  p->rchild = prl ;


  p->height = newHeight(p) ;
  pr->height = newHeight(pr) ;

  if(root==p){
      root= pr ;
  }

  return  pr ;
}

Node *rlRotation(Node *p){
  
  Node *pr =  p->rchild ;
  Node *prl =  pr->lchild ;

  p->rchild =  prl->lchild ;
  pr->lchild = prl->rchild ;

  prl->lchild =p;
  prl->rchild  =pr ;


 p->height = newHeight(p) ;
 pr->height  =newHeight(pr) ;
 prl->height = newHeight(prl) ;

  if(root== p){
    root= prl ;
  }

  return prl; 
}


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


p->height = newHeight(p) ;


const int treeBalanced = BalanceFactor(p) ;
const int lefttreeBalanced = BalanceFactor(p->lchild) ;
const int RightTreeBalanced =BalanceFactor(p->rchild) ;

if(treeBalanced ==2 && lefttreeBalanced ==1){
 return llRotation(p) ;
}
if(treeBalanced ==2 && lefttreeBalanced == -1){
 return lrRotation(p);
}
if(treeBalanced == -2 && RightTreeBalanced == -1){
 return rrRotation(p) ;
}
if(treeBalanced == -2 && RightTreeBalanced == 1){
 return rlRotation(p) ;
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


const int treeBalanced = BalanceFactor(p) ;
const int lefttreeBalanced = BalanceFactor(p->lchild) ;
const int RightTreeBalanced =BalanceFactor(p->rchild) ;


cout<<p->data<<" "<<treeBalanced<<lefttreeBalanced<<RightTreeBalanced<<"ew"<<endl;
if(treeBalanced ==2 && lefttreeBalanced ==1){
 return llRotation(p) ;
}
if(treeBalanced ==2 && lefttreeBalanced == -1){
 return lrRotation(p);
}
if(treeBalanced == -2 && RightTreeBalanced == -1){
 return rrRotation(p) ;
}
if(treeBalanced == -2 && RightTreeBalanced == 1){
 return rlRotation(p) ;
}


return p ;

}

int main(){


root =  RInsert(root , 10) ;
RInsert(root , 15) ;
RInsert(root , 5) ;
RInsert(root ,6) ;
RInsert(root , 4);

Inorder(root) ;

Delete(root ,4) ;
Delete(root  ,15);

cout<<Height(root)<<endl;

}

