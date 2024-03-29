function swap(A, i, j) {
  let temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

function bubbleSort(A) {
  for (let i = 0; i < A.length - 1; i++) {
    for (let j = 0; j < A.length - 1 - i; j++) {
      if (A[j] > A[j + 1]) {
        swap(A, j, j + 1);
      }
    }
  }
}

// making it adaptable to use

function bubbleSortA(A) {
  for (let i = 0; i < A.length - 1; i++) {
    let flag = 0;
    for (let j = 0; j < A.length - 1 - i; j++) {
      if (A[j] > A[j + 1]) {
        swap(A, j, j + 1);
        flag = 1;
      }
    }
    if (flag == 0) break;
  }
}

function insertionSort(A) {
  let x, j;

  for (let i = 1; i < A.length; i++) {
    j = i - 1;
    x = A[i];

    while (j > -1 && A[j] > x) {
      A[j + 1] = A[j];
      j--;
    }

    A[j + 1] = x;
  }
}

function selectionSort(A) {
  let k, j;
  for (let i = 0; i < A.length; i++) {
    for (k = j = i; j < A.length; j++) {
      if (A[j] < A[k]) {
        k = j;
      }
    }

    swap(A, i, k);
  }
}

function quicksort(A, start, end) {
  if (end <= start) return;

  let pivot = partition(A, start, end);
  partition(A, 0, pivot - 1);
  partition(A, pivot + 1, end);
}

function partition(A, start, end) {
  let i = start - 1;
  let pivot = end;

  for (let j = start; j <= end - 1; j++) {
    if (A[j][0] < A[pivot][0]) {
      i++;

      swap(A, i, j);
    }
  }

  i++;
  swap(A, i, pivot);

  return i;
}

function merge(A , l , mid ,h ){

  let i  = l , j= mid+1 , k=l;

   let B = Array(h+1).fill(0) ;


   while(i <=mid && j<=h){
 

    if( A[i] < A[j]){

      B[k++] = A[i++]  

    }

    else B[k++] = A[j++]  


   } 


   for( ;  j<=h; i++){
     
     B[k++] =  A[j]
   }
 
   for(; i <=mid ;i++){
    B[k++] =  A[i]
   }


   for(let i = 0 ;i<B.length ;i++){

    A[i] =  B[i]
   }
}


function mergeSort(A , l , h){
let mid;
  if(l<h){
  mid = Math.floor((l+h)/2)
    mergeSort(A , l , mid) 
    mergeSort(A , mid+1, h) ;
    merge(A , l ,mid ,  h) 

  }
}

function countSort(A){

const max =  Math.max(...A) ;

const C=  Array(max+1).fill(0) ;


for(let i = 0 ;i<C.length ;i++){

  C[A[i]]++ ;}


 
let i =0 ,j= 0 ;

while( i< C.length){


  if(C[i]> 0){

    A[j++] = i ;
    C[i]--
  }
  else i++
}
 


}
const A = [10, 3, 1, 2];


// bubbleSort(A) ;
// insertionSort(A)
// selectionSort(A) ;
// quicksort(x, 0, A.length - 1);
// mergeSort(A , 0 , 3) ;
countSort(A)
console.log(A);
