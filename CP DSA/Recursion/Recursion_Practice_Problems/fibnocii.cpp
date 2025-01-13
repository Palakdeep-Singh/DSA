#include<iostream>
#include <stdio.h>

using namespace std;

int fibnocii(int *A,int n){
     if(n<=1){
     A[n] = n;
     return n;
     }
     else{
     if(A[n-1] == -1) A[n-1] = fibnocii(A,n-1);
     if(A[n-2] == -1) A[n-2] = fibnocii(A,n-2);

     A[n] = A[n-1] + A[n-2];
     return  A[n-1] + A[n-2];
    }
}

int main(){
    int n;    
    printf("Enter nth number to get fibnocii number: ");
    scanf("%d",&n);
    int A[n];

    //Initialise array with -1
    for(int i=0;i<n+1;i++) A[i] = -1;

    int f = fibnocii(A,n);
    printf("Last Fibnocii Element is: %d",f);
    return 0;
}