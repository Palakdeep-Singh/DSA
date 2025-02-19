// Time complexity = O(n).
// Comparisons = 2*(n-1) for worst case and (n-1) for best case..
#include<iostream>
#include <stdio.h>

using namespace std;

int main(){
    
    //Firstly initialize a dynamic array.
    int n;
    cout<<"Enter Size Of Array:";
    cin>>n;

    int *A;
     A = new int[n];
     
     cout<< "Enter the elements:\n";
     for(int i=0;i<n;i++) cin>>A[i];

     //Now lets find the max and min element in single scan.
     int min = A[0];
     int max = A[0];

     //run a loop and everytime check if element is smaller than store in min,
     //if it's greater than store in max.
     for(int i=1;i<n;i++){
        if(A[i]<min){
            min = A[i];
        }
        else if(A[i]>max){
            max = A[i];
        }
     }

     //Now lets print the max min values...
     cout<<"Max value:"<<max<<endl;
     cout<<"Min value:"<<min<<endl;
    
    delete [] A;
    return 0;
}