#include<iostream>
using namespace std;

struct Array{
    int A[20];
    int size;
    int Len;
}arr;


//For Binary we need to sort the array.
void sort(struct Array *arr){
    
    int temp;
    for(int i=0;i<arr->Len;i++){
        for(int j=0;j<arr->Len-i;j++){

            if(arr->A[j] < arr->A[j-1]){
               temp = arr->A[j-1];
               arr->A[j-1] = arr->A[j];
               arr->A[j] = temp;
            }
        }
    }
}

//Using Recursion...
int RBinary_Search(struct Array arr,int low,int high,int element){

    int mid = (low+high)/2;
    int x = element;

    if(low<=high){            //Run only when low <= high. else return -1.

    if(x==arr.A[mid]){ 
     return mid;              //when element is found it will return the index.
    }
    else if(x>arr.A[mid]){
         low = mid+1;
         return RBinary_Search(arr,mid+1,high,x);   //Call fun with low = mid+1.
    }
    else{
            high = mid-1;
            return RBinary_Search(arr,low,mid-1,x);  //Call fun with high = mid-1.
          }
    }    
    else return -1;
}

//Iterative form of the Recursion.
int Binary_Search(struct Array arr,int a,int b,int element){

    int low =a,high = b;
    
    int x = element;

    while(low<=high){
        int mid = (low+high)/2;
        if(x == arr.A[mid]){ 
            return mid;
        }
        else if(x>arr.A[mid]){
             low = mid +1;
        }
        else{ 
            high = mid-1;                   
    }
    }
    return -1;
}

int main(){

    arr = {{2,5,7,9,4},10,5}; 
    //Firstly we need to sort the Array.
    sort(&arr);
   
    int c = RBinary_Search(arr,0,4,7);

    int d = Binary_Search(arr,0,4,2);
    printf("Index1: %d Index2: %d\n",c,d);
    return 0;
}