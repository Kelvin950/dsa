// #include  "stdlib.h"
// #include "stdio.h"

// struct  Rectangle
// {
//     int length ; 
//     int breadth ;
//     /* data */



// };
// int Area(int x , int r){

//     return x*r;
// }


// int main(){

//  printf("Hello world\n");
      
//     struct Rectangle r  = {2 ,3};

//     printf("The length and breadth of the rectangle r is %d , %d" ,r.breadth ,r.length);
//     printf("\nthe area of the rectangle is %d " ,Area(r.breadth , r.length) );

//     struct  Rectangle *a =  (struct Rectangle*) malloc(sizeof(struct Rectangle));
  
    
// }



#include <stdio.h>
void funB(int) ;
int fun(int n){

    if(n > 100 ){
      
     return n-10;
    

    }
else{
    return fun(fun(n+11));
}

   
}

void funB(int  n){


    if(n > 1){
        printf("%d " , n);
        fun(n/2);
    }
}

int sum(int n ){

    if(n == 0 || n==1){
        return n ;
    }
     
     return n + sum(n - 1);

}
int pow2(int m , int n ){

    if(n == 1){
        return m ;
    }

return  m * pow2(m , n-1);
}

double e(int x , int n){

    static double  p =1 , f =1 ;
 double r ;
    if(n == 0 ){
        return 1 ; 

    }

    r =  e(x ,n-1);
    p *= x ;
    f *=  n ; 
    return  r + p/f;
    
}

double homer(int x  , int n){
    static double s =  1 ;
    if(n == 0){

        return s;
    }

s =  1 + x*s / n  ;
   return homer(x ,n-1);
}

int  r[10];
int  fibonacci(int n){
 
 if(n <=1){

     r[n]=  n ;
     return n ;
 }

  else {
      if( r[n-2] == -1){
           r[n-2] = fibonacci(n-2);
      }
      if(r[n-1]== -1){
          r[n-1]=  fibonacci(n-1);
          
      }

      return r[n - 1] + r[n - 2] ;
  }
  

}
void hanoiTower(int n , int in ,int mov ,int temp ){

if(n == 1){
     printf("%d -->  %d\n" , in ,mov );
     return ;
}
  hanoiTower(n-1,  in,temp,mov);
  printf("%d -->  %d\n" , in ,mov );
  hanoiTower(n-1,  temp,mov ,in);
}

//  int *newPointer(int z){

//  int  *q =  new int[z];
//      return q;
//  }
int main(){
// for(int  i = 0 ; i< 10; i++){
//     r[i] =  -1;
// } 
// hanoiTower(3 , 1,3,2);
 

}