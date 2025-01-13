#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    // 3 METHODS OF INITIALIZING A 2D ARRAY.
    int A[2][3] = {{1,2,4},{2,4,2}};
  
    //2nd Method Using Pointer Array in Heap.

    int *B[2];  //Created pointer array in Stack;
    B[0] = new int[3];
    B[1] = new int[3];
    
    B[0][0] = 1;B[0][1] = 2;B[0][2] = 4;
    B[1][0] = 2;B[1][1] = 4;B[1][2] = 7;
    
    delete [] B[0]; delete [] B[1];

    //Using Double Pointer in Heap.
    int **C;

    C = new int *[2]; //for C use (int **)malloc(2*sizeof(int*));
    C[0] = new int[3];
    C[1] = new int[3];
 
    C[0][0] = 1;C[0][1] = 2;C[0][2] = 6;
    C[1][0] = 2;C[1][1] = 4;C[1][2] = 3;

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d ",C[i][j]);
    }
    printf("\n");
    }
    delete [] C[0]; delete [] C[1];
    return 0;
    }