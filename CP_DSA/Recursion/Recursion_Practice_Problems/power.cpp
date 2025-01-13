#include<iostream>
#include <stdio.h>

using namespace std;

int power(int b,int e){

    if(e==0) return 1;
    return b*power(b,e-1);
    
}
int main(){
    
    int base,exponent;
    printf("Enter the Number: ");
    scanf("%d",&base);

    printf("Enter the Power You Want:");
    scanf("%d",&exponent);

    int p = power(base,exponent);

    printf("Result: %d",p);
    return 0;
}