#include<iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct rectangle{

    int len;
    int wid;
};

int main(){
    
    rectangle r = {10,5};

    cout<<r.len<<endl;
    cout<<r.wid<<endl; //Just a variable use .
    
    rectangle *p = &r; //Pointer pointing to a structure r.

    cout<<endl<<p->len<<endl; //For pointer use ->
    cout<<p->wid<<endl;

    //To create an object in heap.
    rectangle *s;

    s = (struct rectangle *) malloc(sizeof(struct rectangle));  //In C language..
    //In C++ we use s = new rectangle;

    s->len = 11;
    s->wid = 20;

    cout<<endl<<s->len<<endl;
    cout<<s->wid<<endl;
    
    return 0;
}