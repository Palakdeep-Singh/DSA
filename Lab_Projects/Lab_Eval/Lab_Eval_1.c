#include <stdio.h>
#include <limits.h>
void selection_sort(int *A,int n){

    int max_val,min_val;
    //loop will run till mid because we are swaping both min and max values so loop will go till n/2 
    for(int i=0;i<n/2;i++){
        max_val = i,min_val = i;  //store max min values ...

        // leave first index and check for min max values.
        for(int j = i+1; j<n-i;j++){
            if(A[j] < A[min_val]) min_val = j;  //Find min value and store in min_val

            if(A[j] > A[max_val]) max_val = j;  //Find max value and store in max_val
        }

        // swap the smallest with first and largest with last
        int temp = A[i];
        A[i] = A[min_val];
        A[min_val] = temp;
        
        // If max value was at the current position, update max_val index
        // since it was swapped during min_val swap
        if(max_val == i){
            max_val = min_val;
        }

        
        //now swap max value.
        int temp2 = A[n-i-1];
        A[n-i-1] = A[max_val];
        A[max_val] = temp2;
    }
}

int main(){
    
    int n;
    printf("Enter Length of Array:");
    scanf("%d",&n);

    int A[n];
    for(int i=0;i<n;i++) scanf("%d",&A[i]);
    
    selection_sort(A,n);

    printf("\n");
    for(int i=0;i<n;i++) printf("%d ",A[i]);

    return 0;
}
