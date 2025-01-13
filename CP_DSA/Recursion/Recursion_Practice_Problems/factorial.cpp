#include<iostream>
#include <stdio.h>

using namespace std;

int factorial(int n){
    if(n==0) return 1;
    return factorial(n-1)*n; 
}
int main(){
    
    printf("Factorial of 7 is: %d",factorial(7));
    return 0;
}