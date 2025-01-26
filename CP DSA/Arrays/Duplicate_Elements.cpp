//We will find using Hash Table to reduce time complexity..
#include<iostream>
#include <stdio.h>

using namespace std;
  
int main(){
    
    int n;
   cout<<"Enter size of Array:";
   cin>>n;

   cout<<"Enter elements of Array:\n";
   int *A;
   A = new int[n];

   for(int i=0;i<n;i++) cin>>A[i];

   //Array must be sorted... if not then sort it.
   //Sorting using Bubble Sort...
   for(int i=0;i<n-1;i++){
     for(int j=0;j<n-1-i;j++){
       if(A[j]>A[j+1]){
        int temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
       }
     }
   }
   
//    cout<<"\nSorted Array:\n";
//    for(int i=0;i<n;i++) cout<<A[i]<<" ";
   
                                     //Now create a Hash Table of size of largest element of array A.
   int m = A[n-1];
   int H[m];
                                      
   for(int i=0;i<=m;i++)  H[i] = 0;         //Initialise hash table to 0.

   //Now traverse the array and increase the count of that particular index of element value in hash table..
   for(int i=0;i<n;i++){
    H[A[i]]++;
   } 

//    cout<<"Hash Table: ";
//    for(int i=0;i<=m;i++) cout<<H[i]<<" ";
   
//Now print the duplicates..
   cout<<"\nDuplicate elements: ";
   
   for(int i=0;i<=m;i++){
    if(H[i] > 1) cout<<i<<" ";
   }
   cout<<endl;   

    return 0;
}