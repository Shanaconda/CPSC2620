#include"BTernary.h"
#include<iostream>

using namespace std;


int main()
{
 
   //Default constructor  
   BTernary a;

   //Testing input 1
   BTernary b1("10-1-1");
   cout<<"BTernary b1 is: ";
   b1.insert(cout);
   cout<<endl;
   cout<<"Decimal number after calling constructor with test input 1 is: " << b1.getDecimalValue()<<endl;
   
   //Testing input 2
   BTernary b2("-10-1-1-1");
   cout<<"BTernary b2 is: ";
   b2.insert(cout);
   cout<<endl;
   cout<<"Decimal number after calling constructor with test input 2 is: "<<b2.getDecimalValue()<<endl;
   cout<<endl;
   
   //Testing non BTernary number
   cout<<"After calling the invalid input the result is: ";
   BTernary b3("-41-10");
   
  
   //Testing addition function
   cout<<"The addition of test input 1 and 2"<<endl;
   BTernary d1 = b1.plus(b2);
   d1.insert(cout);
   cout<<endl;
   cout<<"And the decimal value is: "<<d1.getDecimalValue()<<endl;
   cout<<endl;

   //Testing subtraction function
   BTernary d2 = b1.minus(b2);
   cout<<"The subtraction of test input 1 and 2 is: "<<endl;
   d2.insert(cout);
   cout<<endl;
   cout<<"And the decimal value is: "<<d2.getDecimalValue()<<endl;
   cout<<endl;

   //Testing multiplication function
   cout<<"Testing multiplcation function"<<endl;

   BTernary d3 = b1.times(b2);
   cout<<"The multiplication of test input 1 and 2 is: ";
   d3.insert(cout);
   cout<<endl;
   cout<<"And the decimal value is: "<<d3.getDecimalValue()<<endl;
   cout<<endl;


   //User input
   cout<<"Enter a Ternary Number"<<endl;
   BTernary(d4);
   d4.extract(cin);
   cout<<endl;
   
   cout<<"The decimal value of input is: "<<d4.getDecimalValue()<<endl;
   
   return 0;
}
