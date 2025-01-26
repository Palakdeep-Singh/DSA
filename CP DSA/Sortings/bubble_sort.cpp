//           Bubble Sort Algorithm... (time complexity O(n^2) in worst case and O(n) in best case)..
#include<iostream>

using namespace std;

int main(){
                //Dynamic Memory Allocation..
    int *A,n;

    cout<<"Enter the size of Array:";
    cin>>n;

    A = new int[n];
    int count=0;

    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++) cin >> A[i];
     
    for(int i=0;i<n-1;i++){                  //Run a outer loop n-1 times and compare values then perform swap.
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){                 //If value of A[j] > A[j+1] perform swap...
                int temp = A[j];             
                A[j] = A[j+1];
                A[j+1] = temp;
                count++;                     //Count the number of swaps...
            }
        }
    }
    
                                           //Print the Sorted Array...
    cout<<"Sorted Array:";
    for(int i=0;i<n;i++) cout<<A[i]<<" ";

    cout<<"\nNumber of Swaps: "<<count<<"\n";

                                          //Free the memory...
    delete [] A;
    return 0;
}