#include"structuredMatrix.h"
#include"triangularMatrix.h"
#include<iostream>

using namespace std;
//************************************************
//Default Constructor
//************************************************
Triangular_Matrix::Triangular_Matrix(int r, double d)
{
   rows=r;

   int size=rows*(rows+1)/2;

   element = new double[size];

   for(int i=0; i<size; i++)
   {

      element[i]=d;
      
   }
   
   
}
//**********************************
//Deconstructor
//**********************************
Triangular_Matrix::~Triangular_Matrix()
{

   delete []element;
   element=NULL;

}


