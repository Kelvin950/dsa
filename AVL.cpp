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

int main(){


root =  RInsert(root , 5) ;
RInsert(root , 10) ;
RInsert(root , 9) ;

Inorder(root) ;

cout<<Height(root)<<endl;

}

