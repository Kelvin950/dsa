

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




const A =  [ 10, 3,1,2] ;

bubbleSort(A) ;
console.log(A) ;