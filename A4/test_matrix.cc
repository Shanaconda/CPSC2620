#include"matrix.h"
#include<iostream>

using namespace std;

int main()
{

   //Program banner
   cout<<"Matrix program"<<endl;
   
   //Default Constructors
   Matrix m;

   //Creating a 2x3 Matrix
   Matrix m1(2,3,2);

   //Creating a 3x5 Matrix
   Matrix m2(3,5,3);
   
   //Creating a 3x3 Matrix
   Matrix m3(3,3,3);
   Matrix m4(3,3,3);

   //Calling default constructor
   cout<<"The default constructor is: ";
   cout<<endl;

   //Outputting object m1
   cout<<"The matrix of m1 is: "<<endl;
   cout<<m1<<endl;

   //Outputting object m2
   cout<<"The matrix m2 is: "<<endl;
   cout<<m2<<endl;

   //Outputting object m3
   cout<<"The matrix m3 is: "<<endl;
   cout<<m3<<endl;

   //Outputting object m4
   cout<<"The matrix m4 is: "<<endl;
   cout<<m4<<endl;
  
   //Testing accessor functions
   cout<<"The rows and cols of m1 are: "<<m1.ncols()<<" "<<m1.nrows()<<endl;

   //Testing copy constructor
   Matrix m5;
   cout<<"Object m5 after passing m1 is now: "<<endl;
   m5=m1;
   cout<<m5;

   //Testing index operator
   cout<<"The value store in 0,1 in object m1 is now: "<<endl;
   cout<<m1(0,1);
   cout<<endl;

   //Inserting value 4 into location 0,1
   cout<<"After putting 4 into location 0,1 m1 is now: "<<endl;
   m1(0,1)=4;
   cout<<m1<<endl;

   //Testing scalar multiplication
   cout<<"m1*3 is: "<<endl;
   cout<<m1*3<<endl;

   cout<<"3*m1 is: "<<endl;
   cout<<3*m1<<endl;
     
   //Testing -=
   cout<<"m3-=m4 is: "<<endl;
   m3-=m4;
   cout<<m3;

   //Testing +=
   cout<<"m3+=m4 is: "<<endl;
   m3+=m4;
   cout<<m3;

   //Creating new Matrix 4x4
   Matrix m6(4,4,4);
   Matrix m7(4,4,4);

   //Creating new Matrix 2x2 
   Matrix m8(2,2,2);
   Matrix m9(2,2,2);
     
   cout<<"The object m6 is: "<<endl;
   cout<<m6<<endl;

   cout<<"The object m7 is: "<<endl;
   cout<<m7<<endl;
       
   //Testing +
   cout<<"m6+m7 is: "<<endl;
   cout<<m6+m7<<endl;

   //Testing -
   cout<<"m6-m7 is: "<<endl;
   cout<<m6-m7<<endl;

   //Testing *
   cout<<"m8*m9 is: "<<endl;
   cout<<m8*m9<<endl;

   //Testing *=
   cout<<"m8*=m9 is: "<<endl;
   m8*=m9;
   cout<<m8<<endl;

   //End of Test Program
   return 0;
  
}
   



   
   
      

   
