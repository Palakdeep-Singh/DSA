//          Selection Sort... Time Complexity(O(n^2) in worst case and O(n) in best case).
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
                                 
     int count=0;              //In selection sort we just put the minimum element at first by finding it.
     
     for(int i=0;i<n;i++){
        int _index = i,temp = A[i];      //Store the index of element in _index and that element in temp.
        
        for(int j=i+1;j<n;j++){
            if(A[j]<A[_index]){          //when we get the minimum element we will store that index in _index...
                _index = j;
            }
        }
        if(_index!=i){                   //If _index != i then swap the elements.
            A[i] = A[_index];
            A[_index] = temp;           //Here we just put the  smallest number ahead.
            count++;                    //Increment count for counting operations...
        }
     }
     for(int i=0;i<n;i++) cout<<A[i]<<" ";
     cout<<endl<<"No. of operations in selection sort: "<<count<<endl;
     delete [] A;
    return 0;
}