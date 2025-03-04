// <-- Lab Project 2-->
//Things remained to Cover: Sorting by minimum repeatition of elements..  
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Array{
        int *A;
        int size;
    }array;
    
       //Moving average....
       void moving_avg(struct Array arr,int n,int win){
    
        float array2[n],sum=0;   //create some variables used in program and array to store the average values.
        int box=win, k=0,count=1;     //store value of window in a box variable and count the values..
       
                                       //Now if we have box size greater than count we will find average of numbers upto the count index.
            while(win>=count){
            for(int j=0;j<count;j++){
                sum += arr.A[j]; 
            }
            array2[k++] = sum/count;
            count++;
            sum = 0;                         
        }
         sum=0;                       //Now keep the value of sum to 0 if it is non zero.
                                       //when box size is greater than count what to do?
                                        //Run loop until box is smaller than the array length...
            while(box < n){
              for(int j = count-win;j<count;j++){   //Here we will start from count - win index and go upto count
                                                   // if win size is 3 and count becomes 4 we will start from 1 and reach upto 3 counting 1 2 3 index
                                                   // and getting average and storing in the array2.
                sum += arr.A[j];
              }
           array2[k++] = sum/win;
           sum = 0;
           count++;
           box++;                                   //Increase count and box values 1 by 1 to move to next index until reached the last index.
        }
        for(int i=0;i<k;i++) printf("%.1f ",array2[i]);   //Simply print the elements of array2..
       }


       //Finding Frequency of each element in an array...
       void frequency(int arr[],int n){
        int freq[n],count=1;
        for(int i=0;i<n;i++) freq[i] = -1;
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
        
        for(int i=0;i<n;i++) remove[i] = -1;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
            if(arr[i] == arr[j]){
             count++;
             remove[j] = 0;
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


int main(){

    //Create a Dynamic Array in Structure...
    printf("Enter the size of the array: ");
    scanf("%d",&array.size);

    array.A = (int *) malloc (array.size * sizeof(int));
    
    printf("Enter the elements of the array: ");
    for(int i=0;i<array.size;i++) scanf("%d",&array.A[i]); 


    // frequency(array.A,array.size);
    // Bubble_Sort(&array,array.size);
  
    // frequency(array.A,array.size);
    // Bubble_Sort(&array,array.size);

    //              Perform all operations....
    moving_avg(array,array.size,3);
    printf("\n");
    frequency(array.A,array.size);
    printf("\n");
    
    Bubble_Sort(&array,array.size);

    int arr1[array.size];
    printf("\nEnter Array elements for Insertion Sort: ");
    for(int i=0;i<array.size;i++) scanf("%d",&arr1[i]);

    Insertion_Sort(arr1,array.size);
    Duplicate_Removal(array.A,array.size);

    free(array.A); //Free the memory allocated.
    return 0;
}