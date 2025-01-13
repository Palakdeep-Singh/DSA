#include<iostream>
#include <stdlib.h>

using namespace std;

int main(){

    int a=10;
    int *p;

    p = &a; //storing address of variable a inside a pointer.

    cout<<p<<endl; //gives address of a.
    cout<<*p<<endl; //drefference to get value at adress a.
   

    //For allocating memory in heap in C lang. we use.
    p = (int *) malloc(5*sizeof(int));

    p[0] = 12; p[1] = 4; p[2] = 56; p[3] = 17; p[4] = 5;

    for(int i=0;i<5;i++) cout<<p[i]<<' ';
    cout<<endl;

    free(p); //deallocating heap memory in C lang.

    //for C++ use delete [ ] p;

    //In C++ we use p = new int[5];

    //Array as a pointer.

    int A[5] = {1,2,4,6,4};

    int *q;
    q = A;

    for(int i=0;i<5;i++) cout<<q[i]<<' ';
    cout<<endl;


    return 0;
}