#include<iostream>
#include <stdio.h>

using namespace std;

int Sum_Of_Digits(int n){
  
  if(n==0) return n;

  return n%10 + Sum_Of_Digits(n/10);

}

int main(){
    
    int n;
    printf("Enter the Number: ");
    scanf("%d",&n);

    int sum = Sum_Of_Digits(n);

    printf("Sum of Digits is: %d",sum);

    return 0;
}