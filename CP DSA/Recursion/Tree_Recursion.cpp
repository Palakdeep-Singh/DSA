#include<iostream>
#include <stdio.h>

using namespace std;

void fun(int n){
    if(n>0){

        printf("%d ",n);
 
        fun(n-1);    //tree formation.
        fun(n-1);    // Time Complexity = 2^n & activation records n+1
    }
}
int main(){
    fun(3);
    return 0; 
}