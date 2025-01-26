#include <stdio.h>
#include <limits.h>

//Insertion Sort Algorithm...
void Insertion_Sort(int *Array,int n){

     int temp;
     for(int i=1;i<n;i++){

        temp = Array[i];
        int j = i-1;
        while(j>=0 && temp < Array[j]){
            Array[j+1] = Array[j];
            j--;
        }
        if(j!=i-1) Array[j+1] = temp;
     }
    
    for(int i=0;i<n;i++) printf("%d ",Array[i]);
}

//Selection_Sort...
      void Selection_Sort(int *Array,int n){
        int min_index;
        
        for(int i=0;i<n;i++){
            int temp = Array[i];
            min_index = i;
            for(int j=i+1;j<n;j++){
               if(Array[min_index]>Array[j]){
                min_index = j;
               }
            }

            if(min_index !=i){
                Array[i] = Array[min_index];
                Array[min_index] = temp; 
            }
           
        }

        for(int i=0;i<n;i++) printf("%d ",Array[i]);
      }


int main(){
    
    int n;
    printf("Enter Array Size:");
    scanf("%d",&n);

    int array[n];
 
    printf("Enter elements:\n");
    for(int i=0;i<n;i++) scanf("%d",&array[i]);
    Insertion_Sort(array,n);
    printf("\n");
    Selection_Sort(array,n);
    //Sorting Array...

    return 0;
}