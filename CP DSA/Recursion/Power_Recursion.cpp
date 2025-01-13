#include<iostream>
#include <stdio.h>

using namespace std;

// Two Recursive functions for power.
// In 1st the no.of multiples is more.
int power(int a,int b){
    if(b==0) return 1;      //when exponent becomes 0 return 1.
    return power(a, b-1) * a;  //recursive function calculating the power by decreasing exponent and
                            // multiplying with base.
}


// This function has less multiples as it divides the powers, 2^8 = 4^4 = 16^2
int power2(int m,int n){
    if(n==0) return 1;  //when exponent become 0 return 1.

    if(n%2==0)
    return power2(m*m,n/2);  //check if exponent is even then multiple base and make the exponent half.
    else
    return m*power2(m*m,(n-1)/2); // if exponent is odd then multiply 1 base seperately
      // 2^9 = 2 * 2^8...

}
int main(){
    
    int c = power2(9,5);
    printf("%d",c);
    return 0;
}