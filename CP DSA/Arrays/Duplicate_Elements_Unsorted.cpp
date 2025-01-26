//Finding duplicate elements in Unsorted Array...
#include<iostream>
#include <stdio.h>

using namespace std;
 
int main(){

   int n;
   cout<<"Enter the length of Array:";
   cin>>n;

   //Initialize array...
   int *A,*B;
   A = new int[n];

   for(int i=0;i<n;i++) cin>>A[i];
   
   cout<<"Duplicate Elements: ";
   int count = 0;
   for(int i=0;i<n;i++){         //Time complexity O(n^2)
    for(int j=i;j<n;j++){        //We will start from i index and count other duplicate numbers..
        if(A[i] == A[j]){
            count++;
        }
    }
    if(count>1) cout<<A[i]<<" ";      //print duplicate numbers.
    count = 0;                        //now reset count to 0.
   }
    
    delete [] A; //free the memory..

    //Another method you can use by Hash table to count the duplicates... Time Complexity(O(n)).
    return 0;
}