#ifndef BTERNARY_H
#define BTERNARY_H

#include<string>
#include <iostream>

using namespace std;
//Class BTernary

class BTernary
{

   //Functions made public because client requires functions 

public:

   BTernary(); //Default constructor 
   BTernary(string); //Constructor for string 

   //Function adds two BTernary numbers
   BTernary plus(int);
   //Function subtracts BTernary numbers 
   BTernary minus(int);
   //Function subtracts  BTernary numbers
   BTernary times(int);
   //Function multiples BTernary numbers
   void insert (ostream&); //Functions outputs BTernary number
   void extract (istream&); //Function takes inputs from user 

   //Data members made private because client does not require it
private:
   
   int decimal_equivalent;  
};

#endif
   
