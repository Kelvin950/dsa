

function swap(A , i,j){


    let temp = A[i] ;
    A[i] =  A[j] ;
    A[j] =  temp;
}


function bubbleSort(A ){

 

    for(let i = 0 ; i<A.length-1 ; i++){
        for(let j = 0 ; j< A.length-1-i ; j++){
                  

            if(A[j] > A[j+1]){

                swap(A , j, j+1) ;
            }

        }
    }


}


// making it adaptable to use 

function bubbleSortA(A) {
  for (let i = 0; i < A.length - 1; i++) {
    let flag= 0
    for (let j = 0; j < A.length - 1 - i; j++) {
      if (A[j] > A[j + 1]) {
        swap(A, j, j + 1);
        flag =1 ;
      }
    }
    if(flag == 0)break ;
  }
  
}



function insertionSort(A){
    
    let x ,  j ;

    for(let i = 1 ; i< A.length ;i++){

         j =  i-1 ; 
         x =  A[i] ;

         while( j  >-1  &&  A[j] >x){

            A[j+1] =  A[j] ;
            j--
         }

        A[j+1] =x ;
    }

}

function selectionSort( A) {

 
 let  k  , j ;
  for(let  i = 0   ;i < A.length ;i++){
     
      for(k =j = i  ;  j<A.length ;j++){

             if(A[j] < A[k]){

              k=j ;
             }         

      }

      swap(A , i , k) ;
     
  }

}


function quicksort(A , start , end){


  if(end <= start) return  ;

 
     let pivot = partition(A , start , end) ;
     partition(A , 0 , pivot-1) ;
     partition(A ,pivot+1, end) 

  
   
}

function partition(A , start ,end){

  let i =  start-1 ;
  let pivot =  end ;

  for(let j = start ;j<=end-1 ;j++){
       
   if(A[j] < A[pivot]){
    i++ ;

    swap(A , i , j)
   }



  }

     i++ ;
   swap(A , i ,pivot) ;

 
   return i ;

}
const A  =   [ 10, 3,1,2] ;

// bubbleSort(A) ;
// insertionSort(A)
// selectionSort(A) ;
quicksort(A , 0 , A.length-1) ;
console.log(A) ;