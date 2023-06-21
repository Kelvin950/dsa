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


Heapsort([4,
1,
3 ,2 ,16, 9, 10, 14, 8,
7 ]  , 9)
console.log(b)