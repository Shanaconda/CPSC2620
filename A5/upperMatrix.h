#ifndef UPPERMATRIX_H
#define UPPERMATRIX_H
#include"triangularMatrix.h"
#include<iostream>

using namespace std;

class Upper_Triangular_Matrix: public Triangular_Matrix{

  public:
   //Default constructor
   Upper_Triangular_Matrix(int r, double d);

   //Deconstructor
   ~Upper_Triangular_Matrix();

   //Index operator
   const double& operator()(int i, int j)const;
   double& operator()(int i, int j);

   //Print
   virtual void print();

   //return the largest row sum
   virtual double infnorm();
  
};
#endif
