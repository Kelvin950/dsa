
class ListNode {

   constructor(key , next){

     this.key = key
     this.next = next
   }

   
}


function sort(H ,index,key){

    let temp=  new ListNode(key , null) ;
let x=  H[index] ;
let q= null 
 if(!x){

    H[index] =  temp ;
 }

 else {


    while(x && x.key < key){
     
   q  = x ;
   x= x.next
   



    }

     if(x == H[index]){

        console.log("sd")
        temp.next =  H[index] ;
        H[index] = temp
     }
     else{

        temp.next =  q.next ;
        q.next =  temp;
     }
 }



}


function search(H, key) {

    let index =  hash(key) ;


    let p = H[index];

    while(p){
 
        if(p.key == key)return p;
         
        p=p.next;
      
        

      
    }


    return null

}


function hash(key){
 

    return key%10


}

function insert(H, key){

 
    let index =  hash(key) ;
 
    sort(H , index , key)

}
 

//linear probing

function probe(H , index){
 

    let i= 0
    while(H[(index+i*i)%10] !=0){
         i++
    }


    return (index+i*i)%10 ;
}

function linearProbinginsert(H , key){

    let index =  hash(key) ;

    if(H[index]!=0)  {
         
        index = probe(H , index);
    }

    H[index] = key

}
 

function linearProbingsearch(H,key){


let index = hash(key) ;

let i= 0 ;

while(H[(index+i*i)%10] !== key){
    i++ ;
     if(H[(index+i*i)%10] == 0)return -1
}
 
return  (index+i*i)%10 ;
} 


function  doubleHashFunctionOne(key){
 

    return key%10 ;
}

function doubleHashFunctionTwo(key){
    return   7-(key%7) ;
}




function doubleHashInsert(H , key){

    let hash1 =  doubleHashFunctionOne(key) ;
    let hash2 =  doubleHashFunctionTwo(key) ;

    let i =0

 let index = (hash1 + (hash2*i))%10 
 
    while(H[index] !== 0){

         i++
      index = (hash1 + hash2 * i) % 10;    
    }


H[index] =  key;




}


function doubleHashSearch(H , key){
  let hash1 = doubleHashFunctionOne(key);
  let hash2 = doubleHashFunctionTwo(key);

  let i = 0;

 let index = (hash1 + hash2 * i) % 10; 
      while (H[index] !== key) {
        i++;
        index = (hash1 + hash2 * i) % 10;

        if(H[index]==0)return -1;
        
      }


      return index


}

let  H =  Array(10).fill(0)

// insert(H , 12) ;
// insert(H, 22) 
// insert(H, 32)

// linearProbinginsert(H , 55)
// linearProbinginsert(H , 5)
// linearProbinginsert(H , 75)
// linearProbinginsert(H , 100)
// linearProbinginsert(H, 10)
// console.log(H)
// console.log(linearProbingsearch(H,6))
doubleHashInsert(H , 5) ;
doubleHashInsert(H, 25);
doubleHashInsert(H, 65);
console.log(doubleHashSearch(H, 95));

console.log(H)
// console.log(search(H, 42));