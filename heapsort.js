function Maxheapify(A, index) {
  let left = 2 * index + 1;
  let rigth = 2 * index + 2;

  let largest = index;
  console.log(rigth, left, A[index]);
  if (left < A.length && A[left] > A[largest]) {
    largest = left;
  }

  if (rigth < A.length && A[rigth] > A[largest]) {
    largest = rigth;
  }

  if (largest !== index) {
    console.log(A[largest], A[index]);
    let temp = A[largest];
    A[largest] = A[index];
    A[index] = temp;
    Maxheapify(A, largest);
  }
}

function swap(a, b) {
  let temp = a;
  a = b;
  b = temp;
}

function CreateHeap(a) {
  for (let i = Math.floor(a.length / 2); i >= 0; i--) {
    Maxheapify(a, i);
  }
}

const b = [];
function Heapsort(a, n) {
  CreateHeap(a);

  console.log(a);

  for (let i = n; i >=0; i--) {
    let temp = a[0];
    a[0] = a[i];
    a[i] = temp;

  b.unshift(a.pop());
    Maxheapify(a, 0);
   console.log(a ,'aa')
  }

console.log(a);
}


// Heapsort([4,5,2,1,3]  , 5)

function insert(A, index){
 
  

  while(index >0 ){
let parent = Math.floor((index - 1) / 2);
    if(A[index] > A[parent]){

      let temp =  A[index] ;
      A[index] =  A[parent] ;
      A[parent]=temp ;

      index = parent ; 

    }
    else break ;
  }


}
console.log(b)



class PriorityQueue{

    
  constructor(size){
    this.heapSize = size ;
    this._size = 0 ;
    this._array =  []
  }
      

push(value){
   
  if(this.full()){
    throw new Error('queue is full') ;
  }

  this._array.push(value) ;
 

  insert(this._array , this._size)
   console.log(this._array);
 this._size++;
}


pop(){
      
  if(this.isempty()){
    throw new Error('queue is empty');

  }

  let max =  this._array[0] ;
let temp =   this._array[0] ; 
 this._array[0] = this._array[this._size-1] ;
 this._array[this._size-1]=  temp;
 this._array.pop() ;
  Maxheapify(this._array , 0) ;
  console.log(this._array ,'ew')
this._size-- ;
  return max ;
}
 
top(){

  return  this._array[0];
}


full(){

  return  this._size === this.heapSize ;
}

isempty(){

  return    this._size == 0  ;
}


}

let pq =  new PriorityQueue(5) ;

pq.push(4) ;
pq.push(5);
pq.push(2) ;
pq.push(1);
pq.push(3);
console.log(pq.pop())
console.log(pq.pop());
console.log(pq.pop());
console.log(pq.pop());
console.log(pq.pop());
