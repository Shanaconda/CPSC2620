#include"structuredMatrix.h"
#include<iostream>

//**********************
//BASE CLASE
//**********************

using namespace std;

//*******************************************
//Default Constructor
//Stores values in a single dimensional array
//******************************************
Structured_Matrix::Structured_Matrix(int r, double d)
{
   //Declaring
   r=rows;

   //Declaring size n(n+1)/2;
   int size=rows*(rows+1)/2;

   element=new double[size+1];

   for(int i=0; i<size; i++)
   {
      element[i]=d;
   }

   element[size]=0;
   

}

//*****************************************************
//Destructor
//Release the dynamic memory held by the matrix object
//*****************************************************
Structured_Matrix::~Structured_Matrix()
{
   delete[]element;
   element=NULL;
   

}


