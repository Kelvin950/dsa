#include <iostream>
#include "stdlib.h"

using namespace std ;


int main(){


    char s[] =  {'w' , 'e' , '?' , 'L', '\0'}; 
int  i = 0 ,word = 0;
    for(; s[i]!= '\0' ; i++){
 
if( !(s[i] >=65 && s[i]<= 90 )  && !(s[i]>= 97 &&  s[i]<= 122) && !(s[i]>=48 && s[i]<= 57 )){

   cout<<s[i];
}
  
    }
 for(int i = 0 ; s[i]!= '\0' ; i++){

 

 cout<<s[i]<<endl; 
    }

}