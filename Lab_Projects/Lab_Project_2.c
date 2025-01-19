// <-- Lab Project 2-->
//Things remained to Cover: Moving Avg,Sorting by minimum repeatition of elements..  
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Array{
        int *A;
        int size;
    }array;
    
       //Finding Frequency of each element in an array...
       void frequency(int arr[],int n){

        int freq[n],count=1;
        //Run two loops to compare each element with other elements.
        //By usuing count variable count the occurence of element. 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
            if(arr[i] == arr[j]){
             count++;
             freq[j] = 0;   //Now when we find second duplicate element make it 0.
            }
            }
            if(freq[i] != 0){
            freq[i] = count;  //Now just put the counted elements in array and print only that indexes which are !=0.
            }
            count=1;
        }

        for(int i=0;i<array.size;i++){
            if(freq[i]!=0){
            printf("\nfrequency of %d is: %d",arr[i],freq[i]);
            }
       }
       }
      //Bubble Sort for Sorting the Array...
      //Make a count variable and increment it when swapping occurs.
      //Help to find out no. of swaps.
      void Bubble_Sort(struct Array *arr,int n){
        int temp,count=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                if(arr->A[j]>arr->A[j+1]){
                    temp = arr->A[j];
                    arr->A[j] = arr->A[j+1];
                    arr->A[j+1] = temp;
                    count++;
                }
            }
        }
     printf("\nThe sorted array is: \n");
     for(int i=0;i<arr->size;i++) printf("%d ",arr->A[i]);
    
    printf("\nNo. Swaps in Bubble Sort: %d\n",count);
     }
        
    //Insertion Sort... we assume the first element is sorted.
    //then we compare and add in the sorted list by sorting it
    void Insertion_Sort(int arr1[],int n){
    
        int operations=0; //Use this var to find out no. of operations.
        for(int i=1;i<n;i++){   
        int temp = arr1[i];  //Store in temp and compare and copy on index where it become less.
        int j= i-1;          //Now sort the array 
        while(j>=0 && temp < arr1[j]){
           arr1[j+1] = arr1[j];
           j--;           
           operations++;
        }
        arr1[j+1] = temp;
        }
        printf("\nSorted Array Using Insertion Sort: \n");
        for(int i=0;i<n;i++) printf("%d ",arr1[i]);
        printf("\nNo. of Operations in Insertion Sort: %d\n",operations);
    }
    //Removing Duplicates...
    //Just Like finding frequency of each element,
    //Print only array elements don't print frequency.
    void Duplicate_Removal(int arr[],int n){

        int remove[n],count=1;
         
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
            if(arr[i] == arr[j]){
             count++;
             remove[j] =0;
            } }
            if(remove[i] != 0){
            remove[i] = count;
            }
            count=1;
        }
        for(int i=0;i<n;i++){
            if(remove[i]!=0){
                printf("%d ",arr[i]); //just print that array elements.
            }
    }
    }


    //Finding Kth Largest Element...
    int Largest_Kth_Term(int arr[],int n,int k){
         int count=0,array[n],max,index=0;  //Some variables to store data.
                                          // Create an array of size n and initialize it with -1.
                                         //Now when we get the maximum number we will change the value of that index to 0.
         for(int i=0;i<n;i++) array[i] = -1;

         if(k>=0 && k<n){          
                                        //Check only if k is > or <= array size.
         while(count!=k){               //Run loop until we get the kth largest element.
            max = INT_MIN;              //Storing the lowest value in max variable 
                                        
       for(int i=0;i<n;i++){   
             if(max<arr[i] && array[i]!=0){    //Find maximum element... Remove that element in next iteration.
                 max = arr[i];
                 index = i;                   //Store the index of maximum element. When we get the maximum element.
         }
       }
       array[index] = 0;   //Now increment in that particular index in array. 

                           //Now it may be possible to get duplicates we have to remove them.
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] == arr[j] && array[j]!=0){
                array[j] = 0;
            }
        }
       }
                          //Now after getting max element increment in count.
       count++;
       }
       if(count == k){   //when we reach upto k just return that maximum value.
           return max;
       }
    }
    }


int main(){

    //Create a Dynamic Array in Structure...
    array.A = (int *) malloc (array.size * sizeof(int));
    printf("Enter the size of the array: ");
    scanf("%d",&array.size);
    
    printf("Enter the elements of the array: ");
    for(int i=0;i<array.size;i++) scanf("%d",&array.A[i]); 

    // frequency(array.A,array.size);
    // Bubble_Sort(&array,array.size);

    // int arr1[array.size];
    // printf("\nEnter Array elements for Insertion Sort: ");
    // for(int i=0;i<array.size;i++) scanf("%d",&arr1[i]);

    // Insertion_Sort(arr1,array.size);
    // Duplicate_Removal(array.A,array.size);
    
   
    //Input for Kth Largest Element..
    int t;
    printf("\nEnter the value of K: ");
    scanf("%d",&t);
    if(t > array.size){
        printf("Invalid Input!\n");
        return 0; //If t crosses size of array just stop the program.
    }
    
    //Just for printing... You can skip this part.
    if(t== 1){ printf("1st Largest Element is: %d",Largest_Kth_Term(array.A,array.size,t)); }
    else if(t== 2 ){ printf("2nd Largest Element is: %d",Largest_Kth_Term(array.A,array.size,t)); }
    else if(t== 3){ printf("3rd Largest Element is: %d",Largest_Kth_Term(array.A,array.size,t)); }
    else printf("%dth Largest Element is: %d",t,Largest_Kth_Term(array.A,array.size,t));
    return 0;
}