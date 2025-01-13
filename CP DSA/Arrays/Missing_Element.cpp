#include<iostream>
#include <stdio.h>

using namespace std;

int main(){
   int *A;
   int n;
   cout<<"Enter Size:\n";
   cin>>n;
   A = new int[n];
   
   for(int i=0;i<n;i++) cin >> A[i];

//    int sum=0;
//    for(int i=0;i<n;i++) sum+=A[i];
//    int m = ((A[n-1])*(A[n-1] +1))/2;

//    printf("Missing Number: %d\n",m-sum);

   //Second Method...
   int diff = A[0];
   for(int i=0;i<n;i++){
    if(diff != A[i] - i){
        cout<<"Missing Number: "<<i+diff<<endl;
        break;
    } 
   }
    return 0;
}