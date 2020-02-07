#include"BTernary.h"
#include<iostream>

using namespace std;


int main()
{

   string s1 = "10-1-1"; //Test input
   string s2 = "41-10"; //Invalid input

   //Default constructor 
   BTernary a;
   
   cout<<"The decimal output after calling the default constructor:  ";
   a.insert(cout);
   
   BTernary b(s1);

   cout<<"The decimal output after calling the constructor with variable s1:  ";

   
   b.insert(cout);

   cout<<"Now with string variable s2"<<endl;
   
   BTernary c(s2);

   cout<<"The decimal output after calling the constructor with variable s2:  ";

   c.insert(cout);

   return 0;
}
