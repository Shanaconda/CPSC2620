#include"./polynom.h"
#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

//***********************************************************
//Default constructor Polynom()
//Creates an empty polynomial 
//************************************************************
Polynom::Polynom()
{
   //Empty

}

//***********************************************************
//Polynom constructor
//Creates a polynomial with the values provided in the
//vector
//************************************************************

Polynom::Polynom(const vector<int>& coeff)
{
   //Declares coeff
   P=coeff;
   
}

//***********************************************************
//Overloaded add operator
//Adds two polynomial and returns Polynomial
//************************************************************
Polynom Polynom::operator+(const Polynom& RHS) const
{
   unsigned int len1=P.size(); //Declaring a length equal to the size of the vector
   unsigned int len2= RHS.P.size();
   int max,min; //assigning the max and min sizes
   vector<int> longer; //Longer vector
   vector<int> small;  //Shorter vector

   //If the first vector is bigger than the second, the following conditions are followed
   if(len1>len2)
    {
      longer=P;
      small=RHS.P;
      max=len1;
      min=len2;

      
   }
   
   else
   {
      
      longer=RHS.P;
      small=P;
      max=len2;
      min=len1;
      
   }
   //Temp vector to store the values from both vectors
   vector<int>temp(max);

   
   //Offset between the two vectors
   int difference=(max)-(min);
   
   //For loop to add the values from the smallest vector into the temp vector
   for(int i=max-1; i>=min; i--)
   {
     
      temp[i]=longer[i]+small[i-difference];
     
   }

   //For loop to add the remaining values for the largest vector in the temp vector
   for(int i=0; i<min; i++)
   {
      temp[i]=longer[i];
   }
	 
   
   return Polynom(temp);
 

}
//***********************************************************
//Overloaded subtractor operator
//Subtracts two polynomials and returns the sum
//************************************************************
Polynom Polynom::operator-(const Polynom& RHS) const
{
   unsigned int len1=P.size();
   unsigned int len2= RHS.P.size();
   int max,min;
   vector<int> longer;
   vector<int> small;
   if(len1>len2)
   {
      longer=P;
      small=RHS.P;
      max=len1;
      min=len2;
      
   }
   
   else
   {
      
      longer=RHS.P;
      small=P;
      max=len2;
      min=len1;
      
   }
   
   vector<int>temp(max);

   //Offset between the two vectors 
   int difference=max-min;
   
   //For loop to add the values from the smallest vector into the temp vector
   for(int i=max-1; i>=min; i--)
   {
      temp[i]=longer[i]-small[i-difference];
     
   }

   //For loop to add the remaining values for the largest vector in the temp vector
   for(int i=0; i<min; i++)
   {
      temp[i]=longer[i];
   }
	 
   
   return Polynom(temp);
 


  


}
//******************************************************************
//Overloaded operator 
//Takes a double value into the polynomial and outputs the results
//******************************************************************
double Polynom::operator()(double x) const
{

   int n=(P.size()-1); //Prevents warning errors in the for loop
   double t =P[0] * x;

   for(signed int i=1; i<n; i++)
   {
      t=((t+P[i]) * x);
   }

   t = t+ P[P.size()-1];
   return t;



}
//***********************************************************
//Overloaded operator
//Sets the coeff of x^k
//************************************************************
bool Polynom::setCoeff(int k, int c)
{

   int n=P.size()-1; //Prevents warning erros in the for loop
   
      if(k>=0 && k<=n)
   {
      P[n-(k+1)] = c;
      return true;
   }

   else
   {
      return false;

   }


}
//***********************************************************
//Overloaded operator
//Get the coefficient of x^k
//************************************************************
bool Polynom::getCoeff(int k, int& c)const
{

   int n=P.size()-1; //Prevents errors in the for loop

   if(k>=0 && k<=n)
   {
      int deg = n -(k+1);
      c=P[deg];
      return true;
   }

   else
   {
      return false;
   }


}
//***********************************************************
//Overloaded ostream operator
//Outputs the data enter by client and prints an polynomial
//************************************************************
ostream& Polynom::insert(ostream& oStr)const
{

   //Condition if the polynomial is empty
   if(P.capacity()==0)
      oStr<<"Empty";

   else{
   for(unsigned int i; i<P.size(); i++)
   {
      int temp=P[i]; 
      char sign;
      
      if(temp<0)
      {
	 sign ='-';
      }

      else
      {
	 sign ='+';
      }

      //Power of the coefficient
      int pwr=(P.size()-i)-1;

      //Calling print function
      printTerm(sign,pwr,temp,oStr);

   }
       
   
   }
   return oStr;



}

//*******************************************************
//Overloaded print function
//takes as parameter sign, power and coeff and displays
//Polynomial term
//*******************************************************
ostream& Polynom::printTerm(char sign, int pwr, int coeff, ostream& sout) const
{
   
      if(coeff==0)
      {
	 sout<<"";
      }

      else if(pwr==0)
      {
	 sout<<" "<<sign<<""<<coeff;
	 
      }

      else if(pwr==1)
      {
	 sout<<" "<<sign<<""<<coeff<<"x";
      }

      else if(coeff==-1||coeff==1)
      {
	 sout<<" "<<sign<<""<<"x^"<<pwr;
      }

                
      else
      {
	 sout<<" "<<sign<<abs(coeff)<<"x^"<<pwr;
	 
      }
      
   return sout;


}


//*******************************************************
//Overloaded istream operator
//Takes coeffients input from the users
//*********************************************************
istream& Polynom::extract(istream& iStr)
{

   int coeff;
   iStr>>coeff;

   while(!iStr.eof())
   {
      P.push_back(coeff);
      iStr>>coeff;
   }

   iStr.clear();
   return iStr;



}

//****************************************************************
//overloaded stream to extract the polynomial rhs from stream iStr 
//
//*****************************************************************

ostream& operator<<(ostream& oStr, const Polynom& rhs)
{


   rhs.insert(oStr);
   return oStr;




}
//****************************************************************
//overloaded stream to extract the polynomial rhs from stream iStr 
//
//****************************************************************
istream& operator>>(istream& iStr, Polynom& rhs)
{

   rhs.extract(iStr);
   return iStr;

}



