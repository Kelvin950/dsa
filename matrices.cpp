#include <iostream>

using namespace  std;


class Matrix{


public:


    Matrix(int size):
    m(size){

A = new int[size];        


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


    DiagonalMatrix(int size):
    Matrix(size){

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
    for(i = 1; i<m+1 ;i++){
           for(j = 1; j<m+1; j++){

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

      TriangularMatrix(int size):Matrix(size){

     
      }

virtual void SetV(int i , int  j  , int x){

}  

virtual int Get(int i , int j){

} 

virtual void display(){
    
}
 } ; 

int main(){

     
    Matrix *m  = new DiagonalMatrix(5) ;
 
    m->SetV(1 ,1 , 4) ;
    m->SetV(2,2 , 4) ;
    m->SetV(3 ,3 , 4) ;
    m->SetV(4,4 , 4) ;

     m->display();
}