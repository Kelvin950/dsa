#include <iostream>

using namespace  std;

class Matrix{


public:


    Matrix(){

        for(int i = 0 ; i<m ;i++){
           
           A[i]= 0 ;

        }
    }


 void SetM(int x){

    m=  x ; 
 }


void SetV(int i , int j , int x){
 
 if(i == j){

    A[i-1]= x ;
 }

}   
 
 int Get(int i , int j){

 if(i == j){

   return  A[i-j];
 }

 return 0 ;

 }

 void display(){


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
private:
    int A[10];
    int m;
} ;
 

int main(){

     
     Matrix m ;
    m.SetM(4);
    m.SetV(1 ,1 , 4) ;
    m.SetV(2,2 , 4) ;
    m.SetV(3 ,3 , 4) ;
    m.SetV(4,4 , 4) ;


     m.display();
}