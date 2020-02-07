#ifndef BTERNARY_H
#define BTERNARY_H

#include<string>
#include<iostream>

using namespace std;
//Class BTernary

class BTernary
{

//Functions made public because client requires functions 

public:

   BTernary(); //Default constructor 
   BTernary(string); //Constructor for string 

   //Function adds two BTernary numbers
   BTernary plus(const BTernary&); 
   //Function subtracts BTernary numbers
   BTernary minus (const BTernary&);
   //Function multiples BTernary numbers
   BTernary times(const BTernary&);

   //To access the decimal equivalent in the private class
   int getDecimalValue();
   
   //Function multiples BTernary numbers
   void insert (ostream&); //Functions outputs BTernary number
   void extract (istream&); //Function takes inputs from user 

   //The following Data members and functions
   //have been made private because client does not require it
   //
   
   private:
   
   int decimal_equivalent;
   string s1;
   string decimalToternary(int);
   bool isTernary(string);
   int ternaryTodecimal(string);

   
};

#endif
   
