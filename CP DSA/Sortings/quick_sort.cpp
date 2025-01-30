// Quick_Sort function... (Time Complexity: O(n log n)) for best case and O(n^2) for wrost case.
#include<iostream>
#include <stdio.h>

using namespace std;

//create a function for swapping elements...
void swap(int *l,int *h){
    int *temp;
    *temp = *l;
    *l = *h;
    *h = *temp;
}

//Now we have to divide the array in smaller numbers one side and greater another. 
int partition(int *array,int low,int high){

    int pivot = array[low];   //create a pivot which will be compared with other elements

    int i = low, j = high;    
    
    //Create a loop run while starting index < ending index...
    while(i<j){
               //if we get smaller number we will increment i.
               //if we get greater number we will decrement j.
        while(array[i]<=pivot) i++;
        while(array[j]>pivot) j--;
            
        //when loops end we will swap the elements to keep smaller elements one side and greater elements another side.
        if(i<j) swap(array[i],array[j]);
    }

    //Now when i>j we will swap the pivot with that index..
    swap(array[low],array[j]);
    return j;   //return the pivot index to divide the array in smaller and greater sections.
}


//now call a recursive function to cover both the smaller and greater sub arrays.
void quick_sort(int *Array,int low,int high){
    
    if(low<high){
        int pivot_index = partition(Array,low,high);   //get the pivot index..
        quick_sort(Array,low,pivot_index-1);           //first recursive call for smaller section sorting.
        quick_sort(Array,pivot_index+1,high);         //second recursive call for greater section sorting.
    }
}

int main(){

    int n;
    cout<<"Enter size of Array: ";
    cin>>n;

    int *arr;
    arr = new int[n];

    cout<<"Enter elements of Array:\n";
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<"Sorted Array:\n";
    quick_sort(arr,0,n-1);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    delete [] arr;
    return 0;
}