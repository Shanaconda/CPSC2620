#include"triangularMatrix.h"
#include"structuredMatrix.h"
#include"upperMatrix.h"
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

//***********************************************************
//I was able to determine the index operator by making a
//condition for i and j. If i<j || i==j it would always output a value
//in the array. However if i>j then it would output a zero
//
//***********************************************************



//**************************************************************
//Default Constructor
//**************************************************************
Upper_Triangular_Matrix::Upper_Triangular_Matrix(int r, double d)
{

   rows=r;
   int size;

   size=rows*(rows+1)/2;

   element=new double[size];
   

   for(int i=0; i<size; i++)
   {
      element[i]=d;
   }

}
//*************************************************
//Deconstructor
//**************************************************
Upper_Triangular_Matrix::~Upper_Triangular_Matrix()
{

   delete[]element;
   element=NULL;


}
//*********************************************************
//Index operator
//**********************************************************
const double& Upper_Triangular_Matrix::operator()(int i, int j)const
{

   int size;
   size=rows*((rows+1)/2);
   
   if(i<=j)
   {
      return element[i*((i+1)/2)+j];
   }

   else
   {
      
      return element[size];
   }


}
//***********************************************************
//Index Operator
//************************************************************
double& Upper_Triangular_Matrix::operator()(int i, int j)
{
   double* a= new double [1];
   a[0]=0;

   if(i<=j)
   {
      return element[i*((i+1)/2)+j];
   }

   else
   {
      return a[0];
   }

}
//***********************************
//Print function
//***********************************
void Upper_Triangular_Matrix::print()
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
//**************************************
//Returns the largest row sum
//***************************************
double Upper_Triangular_Matrix::infnorm()
{

   //Temp array
   int temp[rows];

   //Feeding values into a temp array
   for(int i=0; i<rows; i++)
   {
      temp[i]=0;
      for(int j=0; j<rows; j++)
      {
	 temp[i]+=abs(element[i*rows+j]);
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
