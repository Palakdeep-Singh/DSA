#include<iostream>
#include<stdio.h>
using namespace std;

void fun(int n){
    if(n>0){
        printf("%d ",n);
        fun(n-1);
    }
}

int main(){
    fun(6);   
    return 0;
}
//Types of Recursion:
/*
1. Head Recursion means sidha function ko call kiya jaye uske baad operations.
  {
  fun(n-1)
  -------
  -------
  }

2. Tail Recursion means return time koi operation nhi like return fun(n-1).
{
  -------
  -------
  return func(n-1)
  }

3.Tree Recursion means 1 se jyada baar func ko call krna
{
  -------
  func(n-1);
  func(n-1);
  }

4. Indirect Recursion means 1 func dusre ko call kre dusra tisre ko or woh phele ko
  A -->  B -->  C --> A.  
*/