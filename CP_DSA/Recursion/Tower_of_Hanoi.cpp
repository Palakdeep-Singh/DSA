//Let's code Tower Of Hanoi problem.
#include <stdio.h>
#include<iostream>
using namespace std;


void tow_of_han(int n,int A,int B,int C){
    //NO. OF DISCS     from  using  to
    if(n>0){
    tow_of_han(n-1,A,C,B);  // 1 disc uthao B me rkho using C.
    printf("(%d,%d)\n",A,C); //  ab A se C me daalo 
    tow_of_han(n-1,B,A,C);  //  ab B se uthaake C me daalo using A.
}
}
    //Time Complexity of this recursive function is 2^n.
    // No. of times disc will be moved is 2^n - 1.
int main(){

    tow_of_han(3,1,2,3);
    
    return 0;
}
/*  Explanation of recursive function.
                                      (3,1,2,3)
                     |                     |                 |
                (2,1,3,2)                (1,3)           (2,2,1,3)
        |            |        |                      |          |          |    
     (1,1,2,3)     (1,2)   (1,3,1,2)             (1,2,3,1)    (2,3)    (1,1,2,3)
  |      |    |          |      |     |        |     |   |            |    |     |      
  X    (1,3)  X          X    (3,2)    X       X   (2,1)  X           X   (1,3)  X
*/