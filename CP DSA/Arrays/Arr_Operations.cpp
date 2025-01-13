#include<iostream>
#include <stdio.h>

using namespace std;

struct Array{

    int size;
    int *A;
    int Len;
}arr;

void Display(struct Array arr){

    printf("Array: ");
    for(int i=0;i<arr.Len;i++)
    printf("%d ",arr.A[i]);
     
}

void  Add(struct Array *arr,int n){
    //Adding element at last of an array...
    if(arr->Len<arr->size)
    arr->A[arr->Len++] = n;

}

void insert(struct Array *arr,int index,int n){
    //Check if index entered is valid for array or not.
    if(index >= 0 && index <arr->Len){

        //Now start from last and reach upto the entered index.
        // jb tk index tk nhi pahunchte values change krte rho last me usse phele ki fir usse phele.
        for(int i= arr->Len;i>index;i--)
        arr->A[i] = arr->A[i-1];
        arr->Len++;   //Aise 1 index aage bd jayega toh length increase krna array ki.
        arr->A[index] = n;  //Jo empty index bacha h usme apni value daal do.
}
else{
    printf("\nNo Element Inserted!\n");
}
}

int remove(struct Array *arr,int index){
       
       if(index>=0 && index <arr->Len){

       int x = arr->A[index];  //Jo element delete krna h usko store krlo x me.

       for(int i=index;i<arr->Len;i++)   //Us index se last tk loop chlao.
       arr->A[i] = arr->A[i+1];    //us index ki value uske agle me dalte jao or usse agle ki usse agle me.
       arr->Len--;    //Element khtm hogeya ab length km krdo.

       return x;      //Agr koi element delete hua h toh return krdo.
}
       return 0;    //Wrna 0 return krdo.
}

int get(struct Array arr,int index){

    if(index>=0 && index<arr.Len) return arr.A[index];
    return 0;
}

void set(struct Array *arr,int index,int x){

    if(index>=0 && index<arr->Len)
        arr->A[index] = x;
}

int max(struct Array arr){

     int max = arr.A[0];
     for(int i=0;i<arr.Len;i++){
        if(arr.A[i] > max) max = arr.A[i];
     }
    return max;
}

int min(struct Array arr){

    int min = __INT_MAX__;

    for(int i=0;i<arr.Len;i++){
        if(arr.A[i] < min) min = arr.A[i];
    }
    return min;
}

int sum(struct Array arr,int n){

    if(n<=0){
     return 0;
    }
     else{
    return arr.A[n-1] + sum(arr,n-1);
}
}

float avg(struct Array arr){

    return (float)sum(arr,arr.Len)/arr.Len;
}

int main(){
    
    printf("Enter the Size  of Array: ");
    scanf("%d",&arr.size);

    arr.A = new int(arr.size * sizeof(int));
    
    printf("Enter the no. of Elements You Want: ");
    scanf("%d",&arr.Len);
    
    printf("Enter Elements: ");
    for(int i=0;i<arr.Len;i++) scanf("%d",&arr.A[i]);


    printf("Deleted Element at index 3: %d\n",
    
    remove(&arr,3));
    
    Display(arr);

   
    
    printf("\nArray after inserting element: \n");
    
    insert(&arr,3,70);
    Display(arr);

    printf("\nElement at index: 1 is %d\n",get(arr,1));

    set(&arr,3,80);
    Display(arr);

    int c = sum(arr,arr.Len);

    printf("\nSum = %d Avg = %.2f\n",c,avg(arr));
    
    printf("Max Value: %d, Min Value: %d\n",max(arr),min(arr));
    return 0;
}