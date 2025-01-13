#include<iostream>
using namespace std;


void fun(int A[]/*(also we can use *A)*/,int n){
   
   A[0] = 56;
   A[4] = 106;
   //we can modify the array because we used call by address.
for(int i=0;i<n;i++) cout<<A[i]<<' ';
}


int * func(int n){
    //we created a pointer.
    int *p;
    p = new int[n]; //create a array in heap of given size n.

    for(int i=0;i<n;i++) p[i] = i+1; //initializing the array with values from 1 to n.

    return p; //returning an array.

}


int main(){

    int Arr[] = {1,6,3,9,5,2,6};
    int n = sizeof(Arr)/sizeof(int);
    
    //while passing Array we directly use name of array.
    //No need of &Arr or &Arr[] or &Arr[n].
    fun(Arr,n);
    cout<<endl;

//--------------------------------------------------------------
    //Can we get array as a return type?? Yes!! using heap

    int *ptr = func(n); //pointer must be there to get access to heap array.
    //Dynamic Allocation of array.
    for(int i=0;i<n;i++) cout<<ptr[i]<<" ";

    return 0;
}