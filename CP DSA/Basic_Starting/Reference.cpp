#include<iostream>

using namespace std;

int main(){

   int a=60;
   int &r = a; // a ka dusra name r. Must be initialised.Uses same memory of a.
   //It doesn't use memory.

   int b=12;

   r = b;

   cout<<a<<' '<<r<<endl;
   cout<<&a<<' '<<&r<<endl; 
   //Same address and value.
   //Useful in parameter passing...


    return 0;
}