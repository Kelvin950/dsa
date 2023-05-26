#include <iostream>

using namespace std ;


void insert(int h[] , int  n){


    int i =n , temp ;
    temp = h[i] ;

while(i>1 && temp > h[i/2]){
     
     h[i]= h[i/2] ;
     i =i/2 ;

}

h[i] =  temp ;

}

int Delete(int A[] , int n){

    int i , j ,x ;
    int val = A[1] ;
    x=A[n];
    A[1] = A[n] ;
     A[n] = val;
    i =1 ; j=i*2 ;

    while(j<n-1){
        if(A[j+1]> A[j]){
            j = j+1 ;
        }
    
    if(A[j] > A[i]){
        int temp =  A[i] ;
        A[i] =  A[j] ;
        A[j] = temp ;
        i=j ; 
        j= 2*j ;
    }
    else {
        break ;
    }
    }


    return val ;
}

int main(){

    int H[] = {0 ,10,20,30,25,5,40,35}  ;
 

    for(int i = 2  ; i<=7 ;i++){

        insert(H , i) ;
    }
    


    for( int i =1 ; i<=7 ;i++){
            cout<< H[i]<<endl;
    }


 cout<<Delete(H, 7) ;

    for( int i =1 ; i<=7 ;i++){
            cout<< H[i]<<endl;
    }
}