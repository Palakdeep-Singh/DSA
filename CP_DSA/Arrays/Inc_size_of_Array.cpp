#include<iostream>
#include <stdio.h>

using namespace std;
 
int main(){
   int *p,*q;   //Declare 2 pointers to access heap.
   p = new int[5]; //Created an array of 5 integers in Heap.

   //Initialze Heap Array.
   p[0] =12;
   p[1] = 3;
   p[2] = 4;
   p[3] = 10;
   p[4] = 0;
   

   printf("\nArray before:\n");
   for(int i=0;i<5;i++) printf("%d ",p[i]);

   q = new int[10]; //Created Array of 10 integers in Heap.
   //We will now put elements of P in Q.

   for(int i=0;i<5;i++) q[i] = p[i];
    
   //Now delete P.
   delete [] p;

   //Now give address of q to p.
   p = q;
   //p will point to q now delete q.

   q = NULL;
   delete [] q;

   p[5] = 32;p[6] =43;p[7]=1;p[8]=57;p[9]=90;
   
   //Printing P.
   printf("\n\nArray After Increasing Size:\n");
   for(int i=0;i<10;i++) printf("%d ",p[i]);

   printf("\n\n");
   
   delete [] p; //Free Heap Memory.

    return 0;
}