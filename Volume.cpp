#include  <iostream>


using namespace std;

int length ; 
const int sizev=10 ;
void insert( int a[] , int i , int v){

if(i > length && length >= sizev)
         return ;
   
    int j =  length -1 ;

    for( ; j > i ; j--){
            
            a[j+1] =  a[j] ;

    }
   
   a[j]= v  ; 
length++;


}  

void Delete(int a[], int index){


  if(index < length && length ==0 ){
        return ; 
  } 

 for( int i = index  ; i<length-1 ; i++){
   
   a[i] =  a[i+1]; 

 }
 
 length--; 
}

void display(int a[]){

for(int i= 0 ; i<4;i++){
    cout<<a[i]<<endl;
}
}


int binarySearch(int a[] , int key){

  int l = 0 , h= 3 ,mid = 0  ; 

  while ( l <= h)
  {
    mid =  (l+h)/2;
    if(key==a[mid])
        return mid;
    /* code */
    else if(key <a[mid])
        h=mid-1;
    else
        l=mid+1;
  }
  

  return -1 ;
}


int main(){
 
 int a[sizev] =  {1,2,3,5} ; 
 length=  4 ;

cout<<binarySearch(a , 5)<<endl;
cout <<a[0]<<endl;
display(a);


    return 0 ;
}