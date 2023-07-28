
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



let  H =  Array(10).fill(null)

insert(H , 12) ;
insert(H, 22) 
insert(H, 32)


console.log(H)
console.log(search(H, 42));