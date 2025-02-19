#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

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

int main() {
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter elements:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (k <= 0 || k > n) {
        printf("Invalid value of k!\n");
        free(arr);
        return 1;
    }

    int result = Largest_Kth_Term(arr, n, k);
    printf("The %dth largest element is: %d\n", k, result);

    free(arr);
    return 0;
}
