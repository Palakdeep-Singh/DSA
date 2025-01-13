#include<iostream>
 
using namespace std;

int main(){

    int A[5] = {1,2,45,2,46};

    for(int x:A) //giving the values of array to x.
    printf("%d\n",x);

    int n;
    cin>>n;

    int B[n];
    
    B[0] = 2;

    for(int x:B)
    cout<<x<<endl;  //gives garbage value for other indexes except B[0].

    int C[] = {1,2,3}; //it gives error in some compiler because we cannot initialize a variabled array. 

    for(int x:C)
    cout<<x<<endl;

    return 0;
}