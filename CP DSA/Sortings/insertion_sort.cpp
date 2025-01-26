//    Insertion Sort Algorithm...Assuming the 1st element is sorted.
#include<iostream>
using namespace std;
int main(){
    
    int n,*A;
    cout<<"Enter size of Array:";
    cin>>n;
                                  //Initialize a dynamic array...
     A = new int[n];
    cout<<"Enter the elements:\n ";
    for(int i=0;i<n;i++) cin>>A[i];
                                
     int count=0;                           //Now perform insertion sort..also count no. of operations...
    for(int i=0;i<n;i++){
        int temp = A[i];                    //Store every element in temp...
        int j = i-1;                        //Start from last index
        while(j>=0 && temp < A[j]){         //if temp is smaller then change the elements...
            A[j+1] = A[j];
            j--; 
            count++;                          //Decrement the index...
        }
        A[j+1] = temp;                    //Now put temp in j+1 index..
    }
 
    // print the sorted array...
    for(int i=0;i<n;i++) cout<<A[i]<<" ";    
    cout<<endl<<"No. of Operations in insertion sort: "<<count<<endl;
    delete [] A;
    return 0;
}