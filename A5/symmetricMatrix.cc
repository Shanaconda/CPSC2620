#include"symmetricMatrix.h"
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cmath>

//*************************************************************
//Use the same index operators as upper however
//made conditions in the event that i,j=j,i then it outputs
//the identical element 
//*************************************************************

using namespace std;

//**********************************************************
//Default constructor
//**********************************************************
Symmetric_Matrix::Symmetric_Matrix(int n, double d)
{

   rows=n;

   int size=rows*(rows+1)/2;

   //Pointer to a new element on the heap
   element=new double[size];

   for(int i=0; i<size; i++)
   {
      element[i]=d;

   }
  
}

//***********************************************************
//Index Operator
//***********************************************************
const double& Symmetric_Matrix::operator()(int i, int j) const
{

   if(j>i)
   {
      return element[j*((j+1)/2)+1];

   }

   else
   {
      return element[i*((i+1)/2)+1];
   }

}
//***********************************************************
//Index Operator
//***********************************************************
double& Symmetric_Matrix::operator()(int i, int j)
{
   
   if(j>i)
   {
      return element[j*((j+1)/2)+1];

   }

   else
   {
      return element[i*((i+1)/2)+1];
   }


}

//**********************************************************
//Searches for the largest row
//**********************************************************
double Symmetric_Matrix::infnorm()
{
   //Temp Array
   int temp[rows];

   //Feeding values into a temp array
   for(int i=0; i<rows; i++)
   {
      temp[i]=0;
      for(int j=0; j<rows; j++)
      {
	 temp[i]+=element[i*rows+j];
      }
   }

   //Searching for the largest value
   int largest=temp[0];

   for(int i=1; i<rows; i++)
   {
      if(temp[i]>largest)
      {
	 largest=temp[i];
      }

   }

   return largest;



}
//***********************************************************
//Display the matrix
//***********************************************************
void Symmetric_Matrix::print()
{
   int cols=rows;
   
   for(int i=0; i<rows; i++)
   {
      cout<<"|";
      for(int j=0; j<cols; j++)
      {
	 cout<<setw(5)<<(*this)(i,j);
	 
      }
      cout<<" |"<<endl;
   }
  
}

		    
