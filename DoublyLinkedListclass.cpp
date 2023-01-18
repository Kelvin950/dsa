#include <iostream> 
#include <iomanip>

using namespace std; 


class Node{

public:
  Node *next ; 
  Node *prev;
  int data;

  Node(){

  }

} ; 


class DoublyLinkedList{
 


  public :
     DoublyLinkedList(){
         
         size = 0 ;

     }
    //  ~DoublyLinkedList(){
    //        delete first ;
    //        delete last ;
    //  }
       

     void   Create(int A[] , int n){
     
     Node *temp = new Node();
     temp->data = A[0]; 
     temp->prev=NULL;
     temp->next =NULL;
     first =temp; 
      last=  first;   
      this->size++;
             
             for(int i = 1 ; i < n ;i++){
                 
             Node *temp = new Node() ; 
             temp->data = A[i];
             temp->prev =  last  ;
             temp->next = NULL;
             last->next =  temp ;
             last =temp;
                  size++;
              

             }
      
       }


 void Insert(int x , int index){


     if(index <0 || index > size){
        return ;
     }
       
       Node *temp =  new Node(); 
       temp->data = x;

      if(index ==0){
          
           if(first == NULL){
             
             temp->prev = NULL;
             temp->next = NULL;
             first = temp; 
             last=first ;
           }
          else{

          first->prev  = temp ; 
          temp->next =first ;
          first = temp ;

          }

 
  
       } 

       else{
        Node *p = first ;Node *q;

          for(int i= 0 ;i<index -1  ;i++){
             
             p=p->next ;
          } 

    
            q= p->next;
          

         temp->next =p->next ;
         if(q){
        q->prev =  temp ; 
         }
        
         p->next =  temp ;
         temp->prev =  p;

       }

 }


 void merge(DoublyLinkedList *doubly){
      Node *p = first;
      Node *third ,*last;
      Node *s =  doubly->first;
      if(p->data < s->data){
         
         third=last=p ; 
           p=p->next; 
           last->next  = NULL;

      } 

      else{
        third=last=s ; 
           s=s->next; 
           last->next  = NULL;
      } 


while (p  &&s )
{
    /* code */
     if(p->data < s-> data){
             last->next =  p ;
             p->prev = last;
             last = p ;
             p=p->next ;
             last->next = NULL;

     }
     else{

          last->next =  s ;
             s->prev = last;
             last = s ;
             s=s->next ;
             last->next = NULL;
     }
}

if(p){
    last->next =p;
  
    p->prev = last;
    
}

if(s){
       last->next =s;
       
       s->prev =  last;
     

}

first =third ;
 }



void Reverse(){

Node *p = first ; 
Node  *q ;
while(p){
    //   cout<<p->data;
      q = p->next ;
    p->next = p->prev ;
    p->prev = q;
     p =p->prev;

     if(p!=NULL && p->next==NULL ){
      first= p ;  
     }
}



}

void Display(){
  Node *p  =  first ; 
    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }

}
 private:
  int size ; 
  Node *first ;
  Node *last;

} ; 


int main(){
 
 int A[5]={1,2,3,4,5};
 DoublyLinkedList *list= new DoublyLinkedList();

 list->Create(A, 5);
//  list->Display();

int B[3]={6,11,12};
  DoublyLinkedList *list2= new DoublyLinkedList();
  list2->Create(B ,3);
//   list2->Display();

  list->merge(list2);
  list->Display();
//  
list->Reverse();
list->Display();



}















// float poit =2.3 ;

// // double p = 1.0/6.0;
// // cout.precision(3);
// // cout<<p<<endl;
// // cout<<fixed<< p * poit;

//     // int A[5] = {1,2,3,4,5};
         
//     //     DoublyLinkedList *doubly =  new DoublyLinkedList();
//     //     doubly->Create(A , 5);

//     //     doubly->Reverse();
//     //     doubly->Display();

// double firstyear[20]= {0} ;
// double secondYear[20] = {0};
// double thirdYear[20]={0};
// double fourthYear[20]={0};
// float firstYeargpa;
// float secondYeargpa;
// float thirdYeargpa;
// float fourthYeargpa;

// int choice ;

// do{

//     cout<<"Enter a choice"<<endl;
//     cout<<"1 to find first year average"<<endl;
//     cout<<"2 to find second year average"<<endl;
//     cout<<"3 to find to third year average"<<endl;
//     cout<<"4 to find fourth year average"<<endl;
//     cout<<"5 only click five when you have at least filled  a single year. find fgapa"<<endl; 
//     cin>>choice; 

//     switch (choice)
//     {
//     case 1:
//     int classes ;
//     int credit ;
//    double totalcredit;
//     totalcredit =0;
//     double grade; 
//   ; 
//     cout<<"How many classes did you take that year"<<endl;
//     cin>>classes ;

         
//            for(int i = 0;  i< classes; i++){
//                   cout<<"Enter your  credit"<<endl; 
//                  cin>>credit ;
//                  totalcredit +=credit ;
//             cout<<"Enter your grade"<<endl;
//              cin>>grade ;
//              firstyear[i]= grade;
//            }
//         double sum  ;
//          sum= 0;
//          for(int i =0 ; i<20 ;i++){
//             sum+=firstyear[i];
//          }
           
//            firstYeargpa =  sum/totalcredit;
//          cout<<"Your firstyear gpa is  " <<firstYeargpa<<endl;
//         /* code */
//         break;
//         case 2:
//     int classes2 ;
//     int credit2 ;
//    double totalcredit2;
//     totalcredit2 =0;
//     double grade2; 
//   ; 
//     cout<<"How many classes2 did you take that year"<<endl;
//     cin>>classes2 ;

         
//            for(int i = 0;  i< classes2; i++){
//                   cout<<"Enter your  credit2"<<endl; 
//                  cin>>credit2 ;
//                  totalcredit2 +=credit2 ;
//             cout<<"Enter your grade2"<<endl;
//              cin>>grade2 ;
//              secondYear[i]= grade2;
//            }
//         double sum2  ;
//          sum2= 0;
//          for(int i =0 ; i<20 ;i++){
//             sum2+=secondYear[i];
//          }
           
//            secondYeargpa =  sum2/totalcredit2;
//          cout<<"Your secondyear gpa is  " <<secondYeargpa<<endl;
//         /* code */
//         break;
//         case 3:
//     int classes3 ;
//     int credit3 ;
//    double totalcredit3;
//     totalcredit3 =0;
//     double grade3; 
//   ; 
//     cout<<"How many classes3 did you take that year"<<endl;
//     cin>>classes3 ;

         
//            for(int i = 0;  i< classes3; i++){
//                   cout<<"Enter your  credit3"<<endl; 
//                  cin>>credit3 ;
//                  totalcredit3 +=credit3 ;
//             cout<<"Enter your grade3"<<endl;
//              cin>>grade3 ;
//              thirdYear[i]= grade3;
//            }
//         double sum3  ;
//          sum3= 0;
//          for(int i =0 ; i<20 ;i++){
//             sum3+=thirdYear[i];
//          }
           
//            thirdYeargpa =  sum3/totalcredit3;
//          cout<<"Your thirdyear gpa is  " <<thirdYeargpa<<endl;
//         /* code */
//         break;
//         case 4:
//     int classes4 ;
//     int credit4 ;
//    double totalcredit4;
//     totalcredit4 =0;
//     double grade4; 
//   ; 
//     cout<<"How many classes4 did you take that year"<<endl;
//     cin>>classes4 ;

         
//            for(int i = 0;  i< classes4; i++){
//                   cout<<"Enter your  credit4"<<endl; 
//                  cin>>credit4 ;
//                  totalcredit4 +=credit4 ;
//             cout<<"Enter your grade4"<<endl;
//              cin>>grade4 ;
//             fourthYear[i]= grade4;
//            }
//         double sum4  ;
//          sum4= 0;
//          for(int i =0 ; i<20 ;i++){
//             sum4+=fourthYear[i];
//          }
           
//           fourthYeargpa =  sum4/totalcredit4;
//          cout<<"Your fourthyear gpa is  " <<fourthYeargpa<<endl;
//         /* code */
//         break;
//         case 5: 
//         cout<<fourthYeargpa << secondYeargpa<<thirdYeargpa<<firstYeargpa<<endl;
//  float junyear;
//         float Senyear;
//         junyear=  ((1.0/6.0) * firstYeargpa) + ((1.0/6.0)* secondYeargpa);
//         cout<<junyear; 

//         Senyear =((2.0/6.0) * thirdYeargpa) +((2.0/6.0 )* fourthYeargpa);
//         cout<<Senyear;
//         cout<<"Your fgpa is "<<junyear + Senyear;
   
//         /* code */
//         break;
    
//     default:
//     cout<<"Wrong choice"<<endl;
//         break;
//     }

// }while( choice !=99);