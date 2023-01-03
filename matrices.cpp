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

      
      virtual void SetV(int i , int j , int x){
       
             if(i >j){

           
           
           this->A[(i*(i-1))/2 + j-1]=x;
           
        }
        else  if( i==j)
              this->A[(i*(i-1))/2 + j-1]=x;
         else 
             this->A[(j*(j-1))/2 + i-1]=x;
       

      }


  virtual int Get(int i , int j){
         
            if(i >j){

          return this->A[i*((i-1)/2) + (j-1)];
        }
        else  if( i==j)
             return this->A[(j*((j-1)/2)+(i-1) )];
         else 
            return this->A[(j*((j-1)/2)+(i-1) )];
  }


  virtual void display(){
    for(int i = 1; i<=m ;i++){
      for(int j =  1; j<=m ;j++){
              
            
            
            if(i >j){

            //  if(i == 2 && j==1){
            //   cout<<i*(i-1)/2 <<endl;
            //  }
     cout << this->A[i*(i-1)/2 + (j-1)];
        }
        else  if( i==j)
        
        cout << this->A[(j*(j-1)/2+(i-1) )];
         else 
       cout << this->A[(j*(j-1)/2+(i-1) )];

      } 
      cout<<endl;
    }

  }
} ;


class Toeplitz:public  Matrix{

  public: 
   Toeplitz(int size)
   :Matrix(size , size+size-1){

   }


   virtual void SetV(int i , int  j   , int v){
               if(i<=j){
                this->A[j-i] =  v;
               }
              else 
                this->A[this->m+(i-j-1)] =v ;
              


   }

   virtual int Get(int i , int j){

     if(i<=j){
             return   this->A[j-i]  ;
               }
              else 
              return   this->A[this->m+(i-j-1)]  ;

   }


virtual void display(){

for(int i = 1  ;i<=this->m ; i++){
  for(int j =1;j<= this->m ; j++){

  

           if(i<=j){
           cout<<  this->A[j-i]  ;
               }
              else 
            cout<<  this->A[this->m+(i-j-1)]  ;

}
cout<<endl;
}

} };

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
      Matrix *sym =  new SymmetricMatrix(5);
   sym->SetV(1 ,1 , 0) ;
    sym->SetV(2,1 , 4) ;
  sym->SetV(2,2 , 0) ;
    sym->SetV(3 ,1, 4) ;
      sym->SetV(3 ,2 , 4) ;
  sym->SetV(3 ,3 , 0) ;
  sym->SetV(4,1 , 4) ;
  sym->SetV(4,2 , 4) ;
  sym->SetV(4,3 , 4) ;
  sym->SetV(4,4 , 0) ;
  sym->SetV(5,1 , 4) ;
  sym->SetV(5,2 , 4) ;
  sym->SetV(5,3 ,4) ;
  sym->SetV(5,4 , 4) ;
  sym->SetV(5,5 , 0) ;
   sym->display();

   cout<<"Toeplitz matrix"<<endl;
   Matrix  *Toe =  new Toeplitz(5);
      Toe->SetV(1,1 , 1) ; 
       Toe->SetV(1,2 , 2) ; 
        Toe->SetV(1,3 , 2) ; 
         Toe->SetV(1,4 , 3) ; 
          Toe->SetV(1,5, 4) ;

       Toe->SetV(2,1 , 5) ; 
        Toe->SetV(3,1 , 6) ;  
         Toe->SetV(4,1 , 8) ;  
          Toe->SetV(5,1 ,7) ;   

          Toe->display();
}