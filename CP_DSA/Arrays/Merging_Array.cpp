#include<iostream>
#include <stdio.h>
using namespace std;


int main(){
   
   int n;
   printf("ENTER THE SIZE OF FIRST ARRAY: ");
   scanf("%d",&n);
  
    int *A;
    A = new int[n];
    printf("Enter elements:\n");
    for(int i=0;i<n;i++) scanf("%d",&A[i]);

    int m;
    printf("ENTER THE SIZE OF SECOND ARRAY: ");
    scanf("%d",&m);

    int *B;
    B = new int[m];
    printf("Enter elements:\n");
    for(int i=0;i<m;i++) scanf("%d",&B[i]);

    int *C;
    C = new int[m+n];

    int i=0,j=0,k=0;
    while(i<n && j<m){ //loop chlao 1st array or 2nd array ke size tk.

        if(A[i]<B[j]){
          C[k++] = A[i++];
          } //jo bhi chota element ho use daldo or index aage kro.
        else{
        C[k++] = B[j++]; 
        }
    }

  //agr koi element bach jaye toh use bhi add krlo.
    while(i<n) C[k++] = A[i++]; 

    while(j<m) C[k++] = B[j++];

    printf("Merged Array:\n");
    for(int t=0;t<m+n;t++) printf("%d ",C[t]);

    delete [] A;
    delete [] B;
    delete [] C;
    return 0;
}