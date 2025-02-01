#include<iostream>
#include <stdio.h>

using namespace std;

int main(){
    
    char name[100];
    char reverse_string[100];

    cout<<"Enter String You want to Reverse:";
    gets(name);
    
    int i;  //firstly get the length of string..
    for(i=0;name[i]!='\0';i++);
    //Now we reached to the end of string..now we will reverse the string by removing the null character ..
    i= i-1;

    //Just put the reverse string in another array..
    for(int j=0;i>=0;i--,j++){
        reverse_string[j] = name[i]; 
    }
           //Simply print the reversed string.
    for(int i=0;reverse_string[i] != '\0';i++) cout<<reverse_string[i];
    return 0;
}