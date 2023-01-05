#include <iostream>


using namespace std;

class Element{
    public:
    int i ;
    int j ;
    int x;
} ;

class Sparse{

    public:
    Sparse(int m , int n , int num)
    :m(m) , n(n) , num(num){
             
             ele =  new Element[this->num] ; 
    } 

     ~Sparse(){

        delete [] ele;
     }

     void read(){

        cout<<"Enter non-zero elements";
        for(int   i=0 ;i<num;i++){
            cin>>ele[i].i>>ele[i].j>>ele[i].x;
        }



     }

     void display(){

        int k = 0 ;
        for(int i = 0 ; i<m ;i++){
            for(int j =0 ; j<n ;j++){
                    if(ele[k].i ==i && ele[k].j==j){
                        cout<<ele[k++].x<<" " ;
                    }
                    else cout<<"0 ";
            } 

            cout<<endl;
        }
     }
     

 Sparse operator+(Sparse &s){
      int i,j,k;if(m!=s.m || n!=s.n)
return Sparse(0,0,0);
Sparse *sum=new Sparse(m,n,num+s.num);
i=j=k=0;
while(i<num && j<s.num)
{
if(ele[i].i<s.ele[j].i)
sum->ele[k++]=ele[i++];
else if(ele[i].i > s.ele[j].i)
sum->ele[k++]=s.ele[j++];
else
{
if(ele[i].j<s.ele[j].j)
sum->ele[k++]=ele[i++];
else if(ele[i].j > s.ele[j].j)
sum->ele[k++]=s.ele[j++];
else
{
sum->ele[k]=ele[i];
sum->ele[k++].x=ele[i++].x+s.ele[j++].x;
}
}
}
for(;i<num;i++)sum->ele[k++]=ele[i];
for(;j<s.num;j++)sum->ele[k++]=s.ele[j];
sum->num=k;
return *sum;
  
 }

     private:
     int m;
     int n;
     int num;
     Element *ele;
 };

int main(){
          

          Sparse matrix(5, 5, 5) ;
          matrix.read();
          matrix.display();

    Sparse matrix2(5,5,5) ;
    matrix2.read();
    Sparse Matrix =  matrix + matrix2 ; 

    Matrix.display() ; 

}