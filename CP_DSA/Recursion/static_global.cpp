#include<iostream>
#include <stdio.h>

int fun(int n){
    static int x=0;
    if(n>0){

        x++; // x= 1 2 3 4 5.  Last value is 5 hence 5 will be sent to all return calls.

        return fun(n-1) + x; //firstly func call and return time x will be added.

    // x will have only 1 activation record unlike n which has various activation records.
    // only 1 photocopy of x will be passed to all the return calls.
    }
    return 0;
}

using namespace std;

int main(){
      
    int r;
    r = fun(5);

    cout<<r<<endl;

    return 0;
}