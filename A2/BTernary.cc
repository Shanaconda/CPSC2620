#include"BTernary.h"
#include<iostream>
#include<cmath>
#include<string>


using namespace std;


//*****************************************
//Default constructor
//Purpose: Initializing the default value of
//decimal equivalent=0;
//******************************************

BTernary::BTernary()
{

   decimal_equivalent=0;
   
}

//**********************************************************************
//Implementation of function  with string variables
//Purpose: taking in string value and declaring it as decimal equivalent 
//**********************************************************************

BTernary::BTernary(string s1)
{

   if(isTernary(s1))
      decimal_equivalent=ternaryTodecimal(s1);
      else
      {
	 cout<<"Invalid input the value is reset to zero"<<endl;
	 decimal_equivalent=0;
      }
}
      
      

//***********************************************************************
//Implementation of function to return decimal equivalent
//**********************************************************************

int BTernary::getDecimalValue()
{

   return decimal_equivalent;
}


//**********************************************************************
//Implementation of function to check each value of string input
//To verify if its a valid Ternary
//Takes in string input
//**********************************************************************

bool BTernary::isTernary(string s1)
{
   int stringLength = s1.length();
   int i, temp=0;

   for(i=0;i<stringLength;i++)
   {
      if (s1.at(i)=='-' || s1.at(i)=='0' || s1.at(i)=='1')
	 temp++;
      else
	 return false;
   }


   return true;
   
   
}

//***************************************************************
//Implementation of function to convert ternary value
//to a decimal value
//Takes in string parameter 
//
//***************************************************************


int BTernary::ternaryTodecimal(string s1)
{
   int i, temp=0;
   int stringLength = s1.length();
   int power = s1.length();

   power--;

   for(i=0; i<stringLength;i++)
   {
      if(s1.at(i) == '-')
	 power--;
   }


   for(i=0; i<stringLength; i++)
   {
      if(s1.at(i) == '-')
      {
	 temp = temp + (-1 * pow(3, power));
	 i++;
      }
      else if (s1.at(i) == '0')
      {

	 temp = temp + (0 * pow(3, power));
      }
      else if(s1.at(i) == '1')
      {

	 temp = temp + (1 * pow(3, power));

      }
      else
      {
	 cout<<"Invalid Ternary Number. The value is now  set to 0"<<endl;
	 return temp=0;
      }

      power--;
   }

   return temp;
}

//***************************************************************
//Implementation of function to convert decimal value
//to a Ternary 
//Takes in int parameter 
//
//***************************************************************

string BTernary::decimalToternary(int d)
{
   int temp, trit;
   bool negative = false;
   string s;

   temp = abs(d);

   if (d <0)
      negative = true;

   while (temp > 0)
   {
      trit = temp % 3;

      if (trit == 0)
      {
	 s = "0" + s;
	 temp = temp/3;
      }
      else if(trit == 1)
      {
	 if (negative)
	    s = "-1" + s;
	 else
	    s = "1" + s;
	 temp = temp/3;
      }
      else if(trit == 2)
      {
	 if(negative)
	    s = "1" + s;
	 else
	    s = "-1" + s;
	 temp = (temp+1) / 3;
      }
   }

   return s;
}
   
//***********************************************************************
//Implementation of function add two BTernary numbers
//
//Takes in parameter d 
//
//************************************************************************


BTernary BTernary::plus(const BTernary& d)
{

   int temp = decimal_equivalent+d.decimal_equivalent;
   string str = decimalToternary(temp);
   return BTernary(str); 
   
}


//**********************************************************************
//Implementation of function to minus ternary numbers 
//Takes in BTernary value d
//**********************************************************************


BTernary BTernary::minus(const BTernary& d)
{

   int temp = decimal_equivalent - d.decimal_equivalent;
   string str = decimalToternary(temp);
      return BTernary(str);
   

}


//**********************************************************************
//Implementation of function  to minus ternary numbers 
//Takes in BTernary value d
//**********************************************************************

BTernary BTernary::times(const BTernary& d)
{

   int temp = decimal_equivalent * d.decimal_equivalent;
   string str = decimalToternary(temp);
   return BTernary(str);
   
}

//**********************************************
//Implemenation of extract function
//to input value from user 
//***********************************************

void BTernary::extract(istream &sin)
{
   sin>>s1;
   decimal_equivalent = ternaryTodecimal(s1);
   return;  
}

void BTernary::insert(ostream& sout)
{
   s1=decimalToternary(decimal_equivalent);
   sout<<s1;
   return;
}
