#include<iostream>
#include <stdio.h>


struct Array{

    int A[20];
    int Len;
}arr;

int size = sizeof(arr.A)/sizeof(int);

void Display(struct Array arr){

    for(int i=0;i<arr.Len;i++) printf("%d ",arr.A[i]);
}

void Reverse(struct Array *arr){

    int *B;
    B = new int[arr->Len*sizeof(int)];
    for(int i=arr->Len-1,j=0;i>=0;i--,j++)  B[j] = arr->A[i];

    for(int i=0;i<arr->Len;i++) arr->A[i] = B[i];
}

void Reverse2(struct Array *arr){

    for(int i=0,j=arr->Len-1;i<j;i++,j--){
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;

}
}

void LeftShift(struct Array *arr){

    int x = arr->A[0];
    for(int i=0;i<arr->Len;i++){
        arr->A[i] = arr->A[i+1];
}
    arr->A[arr->Len-1] = x;
}

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void InsertSort(struct Array *arr,int n){

    int i= arr->Len-1;
    if(arr->Len == size) return;
    while(arr->A[i]>n){

        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = n;
    arr->Len++;
}

//Check for sort...
int isSort(struct Array arr){
    int i;
    for(i=0;i<arr.Len-1;i++){
        if(arr.A[i]>arr.A[i+1])
        return 0;
    }
    return 1;
}

//It will just print -ve one side and +ve one side.
void ReArrange(struct Array *arr){

    int i,j;
    i=0;
    j=arr->Len-1;

    while(i<j){
        while(arr->A[i]<0)  i++;
        while(arr->A[j]>=0) j--;
        if(i<j) swap(&arr->A[i],&arr->A[j]);
    }
}
int main(){
    
   arr = {{0,-1,3,4,-6,8,-9},7};

   //LeftShift(&arr);
   //InsertSort(&arr,2);
   ReArrange(&arr);
   Display(arr);      
   
   //printf("\n%d\n",isSort(arr));
    return 0;
}