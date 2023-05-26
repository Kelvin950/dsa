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



int main(){

    int H[] = {0 ,1,2,3,4,5,6,7}  ;



}