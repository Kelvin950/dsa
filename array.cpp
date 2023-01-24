#include <iostream>
using namespace std;


struct Array{
   
   int A[10];
   int size;
   int length;
} ;

void display(struct Array a){
 int i; 
 cout<<"Element are "<<endl;

 for(i= 0 ; i<a.length;i++){

     cout<<a.A[i]<<endl;
 };

} ;

void append(struct Array *arr ,int x){
 
 if(arr->length < arr->size){
     arr->A[arr->length++]=  x;
 }

}

void insert(struct Array *arr , int index ,int x){

    int i; 
    if(index >=0 && index <= arr->length){
         
         for(i = arr->length ; i<index ; i--){
             arr->A[i] =  arr->A[i-1];
         }
        arr->A[index] = x; 
        arr->length++;
    }
}


int Delete(struct Array *a , int index ){

    int x = 0 ;

if(index >=0  && index <a->length){

x = a->A[index] ; 

for(int i = index ; i<a->length-1;i++){
        a->A[i] =  a->A[i+1];

}
    
    a->length--;

}
    return x  ;
} 

void swap(int *x , int *y){

int temp ;

temp = *x ;
*x = *y ;
*y =  temp ;

}

int linearSearch(struct  Array* arr, int key){

int i;
for(i = 0 ; i<arr->length ; i++){
      
      if(key==arr->A[i]){
        
        //transposition 
        // swap(&arr->A[i] , &arr->A[i-1]);
        //move to front
        swap(&arr->A[i] , &arr->A[0]) ;
          return i;
      } 
}
      return -1;

}

int BinSearc( struct Array arr , int key){

int  l,mid,h ;

l=0 ;
h =  arr.length-1 ;

while (l<=h)
{
    mid =  (l+h)/2;
    if(key==arr.A[mid])
        return mid;
    /* code */
    else if(key <arr.A[mid])
        h=mid-1;
    else
        l=mid+1;
    
}
return -1 ;

}

int RBinSearch(int a[] ,int l , int h, int key){
         
         int mid ;
         if(l<=h){
             mid = (l+h)/2;
             if(key==a[mid])
                return mid;
            else if(key<a[mid])
                return RBinSearch(a,l,mid-1,key);
            else 
                return RBinSearch(a, mid+1 ,h ,key);
         }
        
 

    return -1;
}

int Get( struct Array arr,int index){

    if(index >=0 && index<arr.length){
            return arr.A[index];

    } 
    return -1;
}

void Set(struct  Array *arr ,int index){
     if(index >=0 && index<arr->length){
             arr->A[index];

    } 
} 

int Max(struct Array arr){
    int max = arr.A[0] ; 

    for(size_t i = 0 ; i<arr.length ;i++){

        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }

    return max ; 
}

int Min(struct Array arr){
    int min = arr.A[0] ; 

    for(size_t i = 0 ; i<arr.length ;i++){

        if(arr.A[i] < min){
            min= arr.A[i];
        }
    }
 
    return min; 
}




void Reverse(struct Array *arr){

for(int  i = 0 , j =arr->length-1 ; i<j ;i++ , j--){

swap(&arr->A[i] , &arr->A[j]) ; 
}

}

struct Array *Merge(struct Array *arr1 ,struct Array *arr2){

    int i = 0 , j=0 ,k=0 ; 
    struct Array *arr3 = new struct Array();
    while(i<arr1->length && j<arr2->length){

if( arr1->A[i] < arr2->A[j]){
    arr3->A[k++]= arr1->A[i++];
}
   else arr3->A[k++]= arr2->A[j++];
    }
 
for(; i<arr1->length;i++){
    arr3->A[k++]= arr1->A[i];
}
for(; j<arr1->length;j++){
    arr3->A[k++]= arr2->A[j];
}
 
 arr3->length=  arr1->length + arr2->length;
arr3->size = 10 ; 

return arr3 ;
}

struct Array *Intersection(struct Array *arr1 ,struct Array *arr2){

    int i = 0 , j=0 ,k=0 ; 
    struct Array *arr3 = new struct Array( );
    while(i<arr1->length && j<arr2->length){

if( arr1->A[i] < arr2->A[j]){
  i++ ;
}
else if(arr2->A[j] < arr1->A[i]){
j++;
}
   else {arr3->A[k++]= arr1->A[i++];
   j++;}
    }
  

 
 arr3->length=  k;
arr3->size = 10 ; 

return arr3 ;
}


struct Array *Union(struct Array *arr1 ,struct Array *arr2){

    int i = 0 , j=0 ,k=0 ; 
    struct Array *arr3 = new struct Array( );
    while(i<arr1->length && j<arr2->length){

if( arr1->A[i] < arr2->A[j]){
    arr3->A[k++]= arr1->A[i++];
}
else if(arr2->A[j] < arr1->A[i]){
    arr3->A[k++]= arr2->A[j++];
}
   else {arr3->A[k++]= arr1->A[i++];
   j++;}
    }
 
for(; i<arr1->length;i++){
    arr3->A[k++]= arr1->A[i]; 
}
for(; j<arr1->length;j++){
    arr3->A[k++]= arr2->A[j];
}
 
 arr3->length=  k;
arr3->size = 10 ; 

return arr3 ;
}

struct Array *Differnce(struct Array *arr1 ,struct Array *arr2){

    int i = 0 , j=0 ,k=0 ; 
    struct Array *arr3 = new struct Array( );
    while(i<arr1->length && j<arr2->length){

if( arr1->A[i] < arr2->A[j]){
    arr3->A[k++]= arr1->A[i++];
}
else if(arr2->A[j] < arr1->A[i]){
   j++;
}
   else { i++;
   j++;}
    }
 
for(; i<arr1->length;i++){
    arr3->A[k++]= arr1->A[i]; 
}

 
 arr3->length=  k;
arr3->size = 10 ; 

return arr3 ;


} 

//finding the missing element in a sorted array

int missSorted(struct  Array a){
int sum = 0;

for(int i = 0 ; i< a.length ;i++){

    sum +=  a.A[i];
}

int S =  (a.A[a.length-1]*(a.A[a.length-1] + 1))/2 ; 


return S-sum ;
}
int mmissSorted(struct Array a){

int difference = a.A[0];
int missElement ; 
    for(int i= 0 ; i <a.length ;i++){

        if(a.A[i]-i != difference){
         missElement=  i  + difference ; 
        }
    }

return missElement ; 
}

void multiplemissSorted(struct Array a){

int difference = a.A[0];
int missElement ; 
    for(int i= 0 ; i <a.length ;i++){

        if(a.A[i]-i != difference){
          while(difference < a.A[i]-1){
              cout<<i+difference<<endl;
              i++;
    difference++;
          } 
      
        }
    }

// return missElement ; 
}
void multiplemissunSorted(struct Array a){


int v[20] ; 


for(int i = 0 ; i<20;i++){
    v[i] = 0 ; 
}


for(int  i = 0 ; i<a.length ;i++){
      v[a.A[i]]++  ;   
    

}
for(int i = 0 ; i<20;i++){
    cout<<v[i]; 
}

for(int  i =  2; i < 20 ; i++){
      if(v[i]==0 ) cout<<i<<endl;
             
        
}

// return missElement ; 
}

void duplicateSorted(struct Array a){


//  int lastDuplicate ;

//  for(int  i=  0 ; i<a.length-1;i++){

//      if(a.A[i]== a.A[i+1] && a.A[i] != lastDuplicate){
//          cout<<a.A[i]<<endl;
//          lastDuplicate = a.A[i];
//      }
//  }

//  for(int  i=  0 ; i<a.length-1;i++){
// int  j = 0 ; 
//      if(a.A[i]== a.A[i+1]){
//  j = i+1 ;  
//  while(a.A[j] == a.A[i]){
//      j++ ; 
//  }
//  cout<<a.A[i]<< j-i<<endl;
//       i = j-1 ;
//      }




//  }

int v[20]  ; 
 for(int i = 0 ; i<20 ;i++){

v[i]= 0;
 }
 for(int i = 0 ; i<a.length ;i++){
     
     v[a.A[i]]++ ; 
 }
 for(int i = 0 ; i<20 ;i++){

                    if(v[i] >1) cout<<i<< " "<<v[i]<<endl;  
 }



}

void duplicateUnsorted(struct Array a){

// for(int i = 0 ; i<a.length -1; i++){
//     int count =1 ;
//     if(a.A[i]!=-1){
//     for(int j = i+1 ; i<a.length ;i++){
        
//         if(a.A[i]== a.A[j]){
//             count++;
//             a.A[j]= -1;
//         }

//     }

// }
// cout<<a.A[i]<<" "<<count<<endl;
// }

int v[12] ;

 for(int i = 0 ; i<12 ;i++){

v[i]= 0;
 }

  for(int i = 0 ; i<a.length ;i++){
         
         v[a.A[i]]++;
 }
 for(int i = 0 ; i<20 ;i++){

                    if(v[i] >1) cout<<i<< " "<<v[i]<<endl;  
 }

}


int main(){
 
  int A[6]={0, 1, 2, 2, 0, 1};
  int B[6]={0, 1, 5, 4, 0, 3} ;

int min = 10000 ,index=-1;
  for(int i = 0 ; i< 6 ; i++){

    if(A[i]> 1 && min > B[i]){
        cout<<A[i]<<B[i]<<endl;
        min = B[i] ;
        index = i;
    }
  }
         
// Reverse(&arr);
//  display(*arr3);  
  

 cout<<endl<<index;

return  0 ;
}

 