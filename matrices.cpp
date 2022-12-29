#include <iostream>

using namespace  std;


class Matrix{


public:


    Matrix(int size, int size1):
    m(size){

A = new int[size1];        


        for(int i = 0 ; i<m ;i++){
           
           A[i]= 0 ;

        }
    }

   virtual ~Matrix(){
  
    delete [] A;
   } 



virtual void SetV(int i , int j , int x) = 0 ;
 virtual int Get(int i , int j) = 0 ;
 virtual void display() = 0 ;

 
protected:
    int *A;
    int m;
} ;
 







class DiagonalMatrix : public  Matrix{


public:


    DiagonalMatrix(int size ):
    Matrix(size ,size){

    }


virtual void SetV(int i , int j , int x){
 
 if(i == j){

    A[i-1]= x ;
 }

}   
 
 virtual int Get(int i , int j){

 if(i == j){

   return  A[i-1];
 }

 return 0 ;

 }

 virtual void display(){


    int i , j ;
    for(i = 1; i<=m ;i++){
           for(j = 1; j<=m; j++){

            if(i==j){
                cout<<A[i-1];
            }else{
                cout<<0;
            }
           }
           cout<<endl;
    }
 }

} ;
 
 class TriangularMatrix: public Matrix{

public:
      TriangularMatrix(int size)
      : Matrix(size , size*((size+1)/2)) 
     {


          
      }

virtual void SetV(int i , int  j  , int x){

   if(i >=j){
    A[(i*(i-1))/2 + j-1]=x;
     
   }


}  

virtual int Get(int i , int j){
 
 if(i >= j){
    return A[(i*(i-1))/2 + j-1];
 }

 return 0;
} 

virtual void display(){  
      
  cout<<"something"<<this->A[13]<<endl;      
       int i , j ;
    for(i = 1; i<=m ;i++){
           for(j = 1; j<=m; j++){

            if(i>=j){
                cout<< A[(i*(i-1))/2 + j-1];
            }else{
                cout<<0;
            }
           }
           cout<<endl;
    }
}
 } ; 


class SymmetricMatrix:public Matrix{
      
      public:
      SymmetricMatrix(int size):
      Matrix(size ,size*((size+1)/2)){

              
      
      }

      
      virtual void SetV(int i , int j){
       

       

      }

} ;

int main(){

     
  
      Matrix *m  = new DiagonalMatrix(5) ;
 
    m->SetV(1 ,1 , 4) ;
    m->SetV(2,2 , 4) ;
    m->SetV(3 ,3 , 4) ;
    m->SetV(4,4 , 4) ;
 m->SetV(5,5 , 4) ;
     m->display();
     Matrix  *s =  new TriangularMatrix(5);
    s->SetV(1 ,1 , 4) ;
    s->SetV(2,1 , 4) ;
  s->SetV(2,2 , 4) ;
    s->SetV(3 ,1, 4) ;
      s->SetV(3 ,2 , 4) ;
  s->SetV(3 ,3 , 4) ;
  s->SetV(4,1 , 4) ;
  s->SetV(4,2 , 4) ;
  s->SetV(4,3 , 4) ;
  s->SetV(4,4 , 4) ;
  s->SetV(5,1 , 4) ;
  s->SetV(5,2 , 4) ;
  s->SetV(5,3 , 4) ;
  s->SetV(5,4 , 4) ;
  s->SetV(5,5 , 4) ;
        cout<<"Triangular Matrix"<<endl;
s->display();
  

  cout<<"Symmetric matrix"<<endl;
}