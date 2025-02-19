#include <stdio.h>

void merge(int *A, int low, int mid, int high) {
    int B[high + 1];  // Size of B should be (high+ 1)
    int i = low, j = mid + 1, k = low;  // `k` should start from low.

    //loop to merge the subarrays.
    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    
    //add remaining elements..
    while (i <= mid) {
        B[k++] = A[i++];
    }

    while (j <= high) {
        B[k++] = A[j++];
    }

    // Copy the merged result back to the original array A
    for (i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

//use passes to divide the array and then apply merge function.
//if array size is odd we will keep the last element as it is and sort it in the last step.
void merge_sort_iterative(int A[],int n){
      int passes,i,l,h,mid;

      for(passes = 2;passes<=n; passes = passes*2){
       for(i=0;i + passes - 1< n; i = i+passes){
                            // i = starting index of subarrays, passes = length of sub array and i + passes - 1 = end index of subarray
            l = i;
            h = i+passes-1;
            mid = (l+h)/2;
            merge(A,l,mid,h);
        }
      }
      //for odd size add the remaining last element
      if(passes/2 < n) merge(A,0,passes/2 - 1,n);

}

    
int main(){

    int n;
    printf("Enter size:");
    scanf("%d",&n);

    int A[n];
    for(int i=0;i<n;i++) scanf("%d",&A[i]);
    merge_sort_iterative(A,n);
    
    printf("Merge Sort:\n");
    for(int i =0;i<n;i++) printf("%d ",A[i]);
    return 0;
}