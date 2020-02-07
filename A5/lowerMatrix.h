#ifndef LOWERMATRIX_H
#define LOWERMATRIX_H
#include"triangularMatrix.h"
#include"structuredMatrix.h"
#include<iostream>

using namespace std;

class Lower_Triangular_Matrix: public Triangular_Matrix{

  public:
   //Default constructor 
   Lower_Triangular_Matrix(int r=0, int d=0);

   //Deconstructor
   ~Lower_Triangular_Matrix();

   //Indexing operator 
   const double& operator()(int i, int j) const;
   double& operator()(int i, int j);

   //Print function
   virtual void print();

   //returns the largest row sum
   virtual double infnorm();  
   
};
#endif
