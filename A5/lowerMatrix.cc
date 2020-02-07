#include"lowerMatrix.h"
#include"triangularMatrix.h"
#include"structuredMatrix.h"
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
//************************************************************
//Use the same index operator function for the upper 
//Just reverse the conditional if statements
//************************************************************


//************************************************************
//Default Constructor
//*************************************************************
Lower_Triangular_Matrix::Lower_Triangular_Matrix(int r, int d)
{
   rows=r;

   //Intialzing size as n(n+1)/2
   int size=rows*(rows+1)/2;

   //Declaring a new member on the heap
   element= new double[size];
   

   for(int i=0; i<size; i++)
   {
      element[i]=d;
   }

   
}

//************************************************
//Deconstructor
//*************************************************
Lower_Triangular_Matrix::~Lower_Triangular_Matrix()
{

   delete[]element;
   element=NULL;

}


//************************************************************
//Index Operator
//***********************************************************
const double& Lower_Triangular_Matrix::operator()(int i, int j) const
{
   if(i>=j)
   {
      return element[i*((i+1)/2)+j];
   }

   else{
      double* a= new double[1];
      a[0]=0;
      return a[0];


   }

}
//*******************************************************
//Index Operator
//*******************************************************
double& Lower_Triangular_Matrix::operator()(int i, int j)
{
   if(i>=j)
   {
      return element[i*((i+1)/2)+j];
   }

   else{
      double* a= new double[1];
      a[0]=0;
      return a[0];


   }    
}

//******************************************************
//Print Functtion
//*******************************************************
void Lower_Triangular_Matrix::print()
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

//****************************************
//Returns the largest row sum
//****************************************
double Lower_Triangular_Matrix::infnorm()
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
