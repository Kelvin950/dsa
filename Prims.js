
class Minheap{

 _array =[]
  size =0
 
     maxifyHeap(index){
 
        const rightChild=  2 *(index)+1 
        const leftChild=  2 *(index)+2 

     let smallestChild =index 

    if(rightChild < this._array.length && this._array[rightChild][0] < this._array[smallestChild][0]){

        smallestChild =  rightChild
    }
          if (
            leftChild < this._array.length &&
            this._array[leftChild][0] < this._array[smallestChild][0]
          ) {
            smallestChild = leftChild;
          } 


           if(smallestChild!==index){
             
             let temp = this._array[smallestChild];
             this._array[smallestChild] = this._array[index];
             this._array[index] = temp;
          
             this.maxifyHeap(smallestChild)
           }
    
    }

    upHeap(index){
     

    while(index >0 ){

       let parent =   Math.floor((index-1)/2)

        if(this._array[parent][0] >  this._array[index][0]){
         
            let temp=  this._array[parent]
             this._array[parent]=  this._array[index] 
             this._array[index]=temp

    index = parent;

        }else{
            break
        }


    }
    }


    pop(){
     
        if(this._array.length==1){
             this.size--;
            return this._array.shift()
        }
        const min = this._array.shift();

        const lastValue = this._array.pop();
        this._array.unshift(lastValue);
        this.maxifyHeap(0);
        this.size--;

        return min;
    }

    push(value){
      
        this._array.push(value)
        this.upHeap(this.size) 
         this.size++ 

    } 


    Print(){
        console.log(this._array)
    }


}


const heap= new Minheap()
heap.push([2,1])
heap.push([3,2])
heap.push([0,3])

console.log(heap.pop())

console.log(heap.pop());

console.log(heap.pop());


class WeightedundirectGrap{
 
    adj = {} 

 
    addVertex(vertex){
     
        if(!this.adj[vertex]){
            this.adj[vertex] = []
        }
    }


    addEdge(vertexA , vertexB , weight){
     
        this.adj[vertexA].push([weight , vertexB])
        this.adj[vertexB].push([weight,vertexA ])
    }

     Print(){
        console.log(this.adj)
     }
} 




const x =  new WeightedundirectGrap()


x.addVertex(1)
x.addVertex(2);
x.addVertex(3);
x.addVertex(4);
x.addVertex(5);
x.addVertex(6);
x.addVertex(7);

x.addEdge(1 ,6, 5)
x.addEdge(1,2,25)
x.addEdge(6,5,18)
x.addEdge(5,4,12)
x.addEdge(4,3,10)
x.addEdge(5,7,16)
x.addEdge(2,7,6)
x.addEdge(3,2,9)
x.addEdge(7,4,11)


x.Print()


let visited={}
let queue= ['1']
const h =  new Minheap()

h.push([0,'1'])
let cost = 0
while(queue.length >0){

    const [c , i] = h.pop() 
    queue.pop()

    if(visited[i]){
        continue ; 
    }

    cost+= c ;
    visited[i]= true 

    for(let neigh of x.adj[i]){
        if(!visited[neigh[1]]){

            queue.push(neigh[1])
            h.push(neigh) 
            h.Print()
        }
    }
}

console.log(cost)