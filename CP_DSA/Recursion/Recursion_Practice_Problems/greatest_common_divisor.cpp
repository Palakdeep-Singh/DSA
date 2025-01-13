#include<iostream>
#include <stdio.h>

using namespace std;

int gcd(int m,int n){
     
      if(m==0) return n;
      if(n==0) return m;

      return gcd(n,m%n);
}

int main(){

    int m,n;
    printf("Input 1st Number: ");
    scanf("%d",&m);

    printf("Enter 2nd Number: ");
    scanf("%d",&n);

    int r = gcd(m,n);
    printf("The Greatest Common Divisor of %d and %d is: %d",m,n,r);
    return 0;
}

