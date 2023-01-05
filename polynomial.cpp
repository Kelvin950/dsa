#include <iostream>

using namespace std;


class Term{

 public:
    int coeff ;
    int exp ;
} ;

class  Polynomial{


public :

    Polynomial(int n)
    :n(n){

         
         term =  new Term[n];

    }

    void insertValues( ){

       cout<<"insert exponent and coefficient" <<endl;
       cout<<"Exponent cannot be less than zero"<<endl;
        cout<<"Start with the highest exponent"<<endl;
        
        int exp ;
        int coeff;
        for(int  i= this->n ; i>=0 ;i++){
             
            
            cin >>exp ;
            if(exp <0 ){
                cout<<"Cannot be less than zero"<<endl;
                break;
            }
            cin>>coeff;
            term[i].exp =  exp ; 
            term[i].coeff = coeff ; 
        }
    
    }

        void display(){

         for(int  i= this->n ; i>=0 ;i++){
              
            
            cout<<term[i].coeff <<((term[i].exp>0)?"x":"")<<(term[i].exp >0 ? term[i].exp : ' ')<< "+ ";
            
           
        }

        cout<<endl;
    
    }   


    Polynomial add(Polynomial  &s){

     Polynomial *temp = new Polynomial(this->n + s.n);
            
      int i ,j,k ; 

        i=j=k =0 ;

        while(i <  this->n && j <s.n){

            if(this->term[i].exp >s.term[j].exp ){

                 temp->term[k].exp =  this->term[i].exp ; 
                 temp->term[k].coeff =  this->term[i].coeff ; 
                 k++ ;
                 i++;
            }
            else if(this->term[i].exp < s.term[j].exp){
                  temp->term[k].exp =  s.term[j].exp ; 
                 temp->term[k].coeff =  s.term[j].coeff ; 
                 j++ ;
                 k++;
            }
            else {

                  temp->term[k].exp =  s.term[j].exp ; 
                 temp->term[k].coeff =  s.term[j].coeff  + this->term[i].coeff; 
                 j++ ;
                 k++;
                 i++;
            }

        }



return *temp ;
         
    }    

private:

    int n ;
    Term *term ; 


} ; 


