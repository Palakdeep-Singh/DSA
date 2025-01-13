#include<iostream>
#include <stdio.h>
using namespace std;

//Recursive function for sum of array elements...
int Sum(int *p,int n){
   if(n<0) return 0;
   return p[n] + Sum(p,n-1);
}
int main(){
     
     int n;
     printf("Enter size of array: ");
     scanf("%d",&n);

     int *p;
     p = new int[n];

     //Input for array:
     for(int i=0;i<n;i++) scanf("%d",&p[i]);
    
    int c = Sum(p,n-1); //Pass Array and last index of array.
    printf("Sum of Array elements: %d",c);

    delete [] p;
    return 0;
}