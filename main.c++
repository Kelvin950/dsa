#include  <iostream>
#include <string>
#include  <iomanip>
#include <vector>
#include  <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
struct Card{

string face;
string suits;

    
} ;

//  class Deck{
//        public :
//        static const int numberOfCards =  52;
//        static const int faces =  14 ; 
//         static const int suits =  4;

// Deck():deck(numberOfCards){
      
//   static string suit[suits]  = {
//        "Hearts", "Diamonds", "Clubs", "Spades"
//   } ;

//   static string face[faces] = {
//       "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", 
//  "Eight", "Nine", "Ten", "Jack", "Queen", "King"
//   } ;


//   for(int  i = 0 ; i <numberOfCards ;i++){

//       deck[i].face =  face[i % faces] ;
//       deck[i].suits = suit[i / suits];
//   }


//   srand(time(0));

// }
 
// void shuffle(){

//     for(int i = 0 ; i < numberOfCards ; i++){
//       int  j =  rand() % numberOfCards;
//       Card temp =  deck[i] ; 
//       deck[i] =deck[j];
//       deck[j] =  temp;  
//     }
// }

//    void deal(){

// for(int i = 0 ; i < numberOfCards ; i++){
//     cout << right << setw( 5 ) << deck[i].face<< " of "
// << left << setw( 8 ) << deck[i].suits<< ( ( i + 1 ) % 2 ? '\t' : '\n' );
//     }

//    }  
//     private:
//        vector<Card> deck;    
// };

 

int *sum(int *a  , int *b){
     
    int v =  *a +  *b;

    int *p = &v ;
  return p ;
}


int *newPointer(int z){


return new int[z];

}

int  *DeletePointer(int *P , int *Q , int z){
   

   for(int  i  = 0  ; i<z ; i++){

      Q[i] =  P[i];
   }

   delete  [] P  ; 

    P=Q ; 

     Q =  nullptr; 

for(int  i  = 0  ; i<z ; i++){

      P[i] =  0;
   }
return  P;
}

template <typename T>
T *createPointer(int z){

   return new  T[z];

}

int main(){
//  int  *p =  new int[5];

//   for(int i = 0 ; i<  5; i++){
//             p[i]= 0 ;
//   }
//  for(int i = 0 ; i<  5; i++){
//             cout<<p[i]<<endl;
//   }


// int *p =  new int[5] ;
  
//   for(int i = 0 ; i < 5 ; i++){

//      p[i] =  0 ; 
//   }
         
// int *q =  newPointer(10);

//  p = DeletePointer(p , q , 10);

//       for(int i = 0 ; i < 10 ; i++){

//       cout<< *(p+1);
//   }  
   
  
//  int *a[3] ; 

//  a[0] =  new int [4] ; 
//  a[1]=  new int[4] ;
//  a[2] =  new int[4];





 
//   int a[2][2] =  {{1 ,2} ,{1,2}};


double p =   17; 
double g =  3; 

  int a  = 8; 
  int b =  6; 

// double x = (pow(g , a) ) % p ; 
// double y = ( pow(g , b) )%  p ;

// std::cout<<x<<" "<<y<<std::endl;



// double ka = pow(x ,b) % p ; 
// double kb =  pow(y ,a) %  p ; 
// std::cout<<ka<<" "<<kb<<std::endl;


std::cout<< (((int)pow(5, 5) % 6)) <<std::endl;




}