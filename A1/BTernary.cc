#include"BTernary.h"
#include<iostream>

using namespace std;

BTernary::BTernary()   //Default Constructor 
{

   decimal_equivalent=0;

}

BTernary::BTernary(string s1)    //Implementation of constructor with string variables 
{

   if(s1=="10-1-1")
   {
      decimal_equivalent=23;
   }

   else
   {
      cout<<"Invalid input, value set back to zero"<<endl;
      decimal_equivalent=0;
   }

}

BTernary:Plus()
{
}


BTernary::Minus()
{
}

BTernary::Times()
{
}



void BTernary::insert(ostream& sout) //Implementation of the member function for output
{
   sout<<decimal_equivalent<<endl;
   return;
}

void BTernary::extract()
{


}
