#include<iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Array{
    int size;
    int A[20];
    int Len;
}arr;

int LinearSearch(struct Array arr,int element){

    for(int i=0;i<arr.Len;i++){
        if(element == arr.A[i]) return i;
    }
    return -1;
}

//Improving Linear Search Method.

void swap(int *A,int *B){
    int temp;
    temp = *A;
    *A = *B;
    *B = temp;
}

int LS(struct Array *arr,int element){

    for(int i=0;i<arr->Len;i++){
        if(element == arr->A[i]){
            swap(&arr->A[i],&arr->A[0]); //Element ko aage le ayo 0 index pe.To avoid O(n).
            return i;
        }
    }
    return -1;
}

int main(){
    
    arr = {10,{2,3,4,5,6},5};
    int key = LS(&arr,4);
    printf("Found at index: %d\n",key);

    printf("Array: ");
    for(int i=0;i<arr.Len;i++){
        printf("%d ",arr.A[i]);
    }

    return 0;
}