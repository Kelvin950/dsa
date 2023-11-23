const  fs =  require("fs");
const path = require("path");
const { workerData } = require("worker_threads");
class Graph{

 
    _adjacencyList ={}
    
    constructor(){

    }
 
    addVertex(vertex){
      if(this._adjacencyList[vertex]){
        throw new Error('vertex already exist')
      }
      this._adjacencyList[vertex] =[]
    }
  
    addEdge(A , B){
        this._adjacencyList[A].push(B) 
        this._adjacencyList[B].push(A) 
    }
 

    print(){
        console.log(this._adjacencyList)
    }
  
    BFS(startingVertex){
      
        const queue= [startingVertex] 
        const visit= {}
       
        console.log(startingVertex);

        visit[startingVertex] = true; 
     while(queue.length > 0){
           
        let vertex =  queue.shift() 
          

        for(let i = 0 ; i  < this._adjacencyList[vertex].length;  i++){

            if(!visit[this._adjacencyList[vertex][i]]){
                  console.log(this._adjacencyList[vertex][i]);
                    visit[this._adjacencyList[vertex][i]] = true;
                queue.push(this._adjacencyList[vertex][i])
            }
        }
        
     }

    }


  visit = {}
     
    DFS(startingVertex){
   
     this.visit[startingVertex] = true; 
     console.log(startingVertex);
    for(let i=0 ; i < this._adjacencyList[startingVertex].length ; i++){

        if(!this.visit[this._adjacencyList[startingVertex][i]]){
            this.DFS(this._adjacencyList[startingVertex][i]);
        }
    }
     
    
      
    }
 
}



let graph = new Graph() 

graph.addVertex('A')

graph.addVertex('B');

graph.addVertex('C');

graph.addVertex('D');

graph.addVertex('E');

graph.addVertex('F');

graph.addVertex('G');

graph.addEdge('A' , 'B')
graph.addEdge('A' , 'C')

graph.addEdge('B' , 'C')
graph.addEdge('B' , 'D')
graph.addEdge('C' , 'D')
graph.addEdge('C' , 'E')
graph.addEdge('E' , 'F')
graph.addEdge("E", "G");
graph.print()

graph.BFS('A')

graph.DFS('A')


class DAG{

    _adjacencyList= new Map()

     
    addVertex(vertex){
        if(this._adjacencyList.has(vertex)){
            throw  new Error(" ")
        }

        this._adjacencyList.set(vertex , [])

    }

    addEdge(vertexA , ...vertexB){
        
        console.log(vertexA)
       for(let i= 0 ; i <vertexB.length ;i++){
          this._adjacencyList.get(vertexA).push(vertexB[i])
       }
    }

     print(){
        console.log(this._adjacencyList)
     }

     topologySort(vertex){
         

   let  _stack = [];
    let  _visit = {};  
         const  dfs = (vertex)=>{




   _visit[vertex] = true 



    if(this._adjacencyList.has(vertex)){
        for (let node of this._adjacencyList.get(vertex)) {
          if (!_visit[node]) {
            dfs(node);
          }
        }
    }

       _stack.push(vertex)
     }


         for(let a of this._adjacencyList.keys()){
               dfs(a)
         }

         let res= []
         while(_stack.length >0){
            res.push(_stack.pop()) 


         }

         return res
     }
   

     BFS(){ 
            let visit = {};
            const queue = [];
        const  seee = (vertex)=>{
         
    
         visit[vertex] =true ;
     

       queue.push(vertex) ; 

       while(queue.length >0){

        const x =  queue.shift() ;
  console.log(x); 
       if(this._adjacencyList.has(x)){
         for (let a of this._adjacencyList.get(x)) {
           if (!visit[a]) {
            
             queue.push(a);
           visit[a] = true
           }
         }
       }
       }
        }

         for (let a of this._adjacencyList.keys()) {
        seee(a);
         }
     } 
  
}



let dag=  new DAG() 

dag.addVertex("algorithms");

dag.addVertex("calculus");

dag.addVertex("compilers");

dag.addVertex("data structures");

dag.addVertex("discrete math");

dag.addVertex("formal languages");

dag.addVertex("databases")

dag.addEdge("algorithms", "data structures");

dag.addEdge("calculus", "linear algebra");

dag.addEdge(
  "compilers",
  "data structures",
  "formal languages",
  "computer organization"
);

dag.addEdge("data structures", "discrete math");

dag.addEdge("databases" , "data structures");

dag.addEdge("discrete math", "intro to programming");

dag.addEdge("formal languages", "discrete math");
dag.print()
dag.BFS("algorithms")
console.log(dag.topologySort("algorithms"))


///example
 /*Use the breadthFirst function to explore a different structure. For example,
you could use the course dependencies from the topoSort example (a directed graph), the file
system hierarchy on your computer (a tree), or a list of bus or subway routes downloaded from
your city government’s web site (an undirected graph).*/



function returnDirlist(dir){
 
    let isDir;
    if(dir == "/home/kelvin/Desktop/sources/cpp"){
         isDir = fs.statSync(dir);
    }else{
        console.log(dir);
        
            isDir = fs.statSync(dir);
    }

     
    if(isDir.isDirectory()){

    const dirList=  fs.readdirSync(dir) 
     
     console.log(dirList)
     
    return dirList.map((d) => `${dir}/${d}`);

    }
   return []
}

let worklist =["/home/kelvin/Desktop/sources/cpp"]

function BFS( worklist , callback){

 
const visited= {} 


if(worklist.length >0 ){

  let  item =  worklist ;


for(let a of item) {
         
    if(!visited[a]){
        visited[a]= true 
       let dirlist = callback(a)
       
       worklist.push(...dirlist) 
console.log(worklist, "cew");
    }
}
}


}


BFS(worklist , returnDirlist)

const s = fs.statSync("/home/kelvin/Desktop/sources/cpp/DSA");
console.log(s)