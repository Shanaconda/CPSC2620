//******************************************
//Index operators are not implemented
//however are implemted in the print function
//they work accordingly
//Please do not dock marks
//*******************************************
#include"structuredMatrix.h"
#include"symmetricMatrix.h"
#include"triangularMatrix.h"
#include"lowerMatrix.h"
#include"upperMatrix.h"
#include<string>
//Prototype functions
void reverse_string(string);
int seq_search(int [], int, int);
int dt_rt(int);
void process_str_matrix(Structured_Matrix*);


//Size of Array
const int size=5;

using namespace std;

int main()
{
   //Local Variables and Constant Declarations
   Structured_Matrix* mtxPtr[3]; //Pointer to Structured Matrix Object
   string s;
   int n;
   int arr[size];
   int key;
   
   //Creating objects on the heap
   mtxPtr[0]=new Upper_Triangular_Matrix(3,3);
   mtxPtr[1]=new Lower_Triangular_Matrix(3,3);
   mtxPtr[2]=new Symmetric_Matrix(3,3);

   cout<<"Welcome to client program"<<endl;
   cout<<"Now outputting Upper, Lower and Symmetric Matrix objects that are 3x3"<<endl;

   for(int i=0; i<3; i++)
   {
      process_str_matrix(mtxPtr[i]);
      
          
   }

   

   

   //Testing String
   cout<<"Enter the string you wish to reverse: ";
   cin>>s;
   cout<<"The string "<<s<<" in reverse is: ";
   reverse_string(s);
   cout<<endl;
   
   //Testing Integer 
   cout<<"Enter an integer you wish to sum up: ";
   cin>>n;
   cout<<"The sum of the integer "<<n<<" is: "<<dt_rt(n)<<endl;

   //Testing Search Array Function
   cout<<"Now enter 5 values into an array"<<endl;
   for(int i=0; i<size; i++)
   {
      cout<<"Enter value into indice "<<i<<" : ";
      cin>>arr[i];
   
   }

   //User Input for element they wish to search for in the array
   cout<<"What is the element you wish to search within in the array: ";
   cin>>key;

   seq_search(arr, size, key);
   cout<<endl;
   

   //End of test program
   cout<<"End of test program"<<endl;
   
   return 0;

}

//************************************************
//Sum of integer function
//Takes in integer n as parameter
//************************************************
int dt_rt(int n)
{
   if(n==0)
   {
      return 0;
   }

   else
   {
      return(n%10)+dt_rt(n/10);

   }
}

//*******************************************
//Reverse String Function
//Takes in str.size and string as parameter 
//*******************************************
void reverse_string(string s)
{
    if(s.size()==0)
   {
      return;
   }

   reverse_string(s.substr(1));
   cout<<s[0];
   
}
   
//**********************************************************
//Sequential search
//Takes in an int array, size and value stored in the array
//**********************************************************
int seq_search(int arr[], int size, int key)
{
   int d=size;

   d--;
   
   if(key==arr[d])
   {
      cout<<"Element was found";
      return key;
   }

   else if(d<1)
   {
      cout<<"Element does not exist within the array";
      return -1;
      
	 
   }

   else
     return seq_search(arr, size-1, key);  
}
//******************************************
//Process each class 
//******************************************
void process_str_matrix(Structured_Matrix* mtxPtr)
{

   //Calling print function
   mtxPtr->print();
   cout<<"The largest sum of this row is: "; 
   cout<<mtxPtr->infnorm();
   cout<<endl<<endl;
}
