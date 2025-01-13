#include<iostream>
#include <stdio.h>

using namespace std;

int _max_(int *arr,int n){  

   static int max = arr[0];

   if(n==0) return max;

   if(arr[n]>=max){
    max = arr[n];
    return _max_(arr,n-1);
   }
   else
   return _max_(arr,n-1);
}


int main(){
    
    int size;
    printf("Enter size: ");
    scanf("%d",&size);
    
    printf("Enter elements:\n");
    int arr[size];
    for(int i=0;i<size;i++) scanf("%d",&arr[i]);

    printf("Maximum elements is: %d",_max_(arr,size-1));

    return 0;
}