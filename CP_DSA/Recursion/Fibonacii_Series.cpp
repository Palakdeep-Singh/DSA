#include<iostream>
#include <stdio.h>

using namespace std;

int f(int n){
    if(n<=1) return n; // for n=0 return 0 and for n=1 return 1.
    return f(n-2) + f(n-1);
}

//Using Array to reduce function calls.
int F[10];

int mf(int n){
    if(n<=1){
        F[n] = n;
        return n;
    }
    else{

        if(F[n-1] == -1) F[n-1] = mf(n-1);
        if(F[n-2] == -1) F[n-2] = mf(n-2);

        F[n] = F[n-1] + F[n-2];

        return F[n-1] + F[n-2];
    }
}

int main(){
    //Initialize array of -1 to put fibnocii numbers in it to prevent function calls.
for(int i=0;i<10;i++)  F[i] = -1;

   printf("%d\n",mf(6));    
    return 0;
}