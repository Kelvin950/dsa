function Maxheapify(A , index){

 
  let   left   = 2 *(index)+1 ;
   let rigth =  2 * (index)+2 ;

let largest = index  ;
console.log(rigth , left , A[index])
if(left < A.length  && A[left] > A[largest]){

    largest = left ;
}

if(rigth < A.length && A[rigth] >  A[largest]){

    largest = rigth ;
}


if(largest !== index){
  console.log(A[largest] , A[index])
    let temp = A[largest] ;
    A[largest] =  A[index] ;
    A[index] =  temp 
    Maxheapify(A , largest)

}



}


function swap( a , b){

    let temp =a ;
     a = b ;
     b= temp;
}


let a = [5, 3, 17, 10, 84, 19, 6, 22, 9 ] ;

for (let i = Math.floor(a.length / 2);  i >=0; i -- ) {


    Maxheapify(a , i)  ;
}

console.log(a)