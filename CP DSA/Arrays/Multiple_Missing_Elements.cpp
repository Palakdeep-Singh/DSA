#include<iostream>
#include <stdio.h>

using namespace std;

int main(){
    int *arr;

    int n;
    printf("Enter size of Array: ");
    cin >> n;
    arr = new int[n];
    
    printf("Enter Elements:\n");
    for(int i=0;i<n;i++) cin >> arr[i];

    int diff = arr[0];

    printf("Missing Elements:\n");
    for(int i=0;i<n;i++){
        //Check if difference != A[i] -i
        if(diff!= arr[i]-i){

            //Run loop to find missing elements until difference is smaller...
            while(diff<arr[i]-i){
            //Print numbers and increase difference value by 1 to check further missing elements...
                printf("%d ",diff+i);
                diff++;
            }
        }
    }

    return 0;
}