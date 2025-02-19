#include<iostream>
#include <stdio.h>

using namespace std;

int main(){
    
    char string[100];
    printf("Enter a string: ");
    gets(string);
    
    //firstly count the maximum value character in the string..
    int max = (int)string[0];
    for(int i=0;string[i]!='\0';i++){
        if((int)string[i] > max){
            max = (int)string[i];
        }
    }
    //Now create a hash table for counting duplicates.
    int table_length = max-97;
    int Hash[table_length];
    //Initialize hash table to 0..
    for(int i=0;i<table_length;i++) Hash[i] = 0;

    for(int i=0;string[i]!='\0';i++){
        Hash[(int)string[i]-97]++;
    }

    //Now print duplicates..
    cout<<"Duplicates: ";
    for(int i=0;i<table_length;i++){
        if(Hash[i] > 1){
            printf("%c ",i+97);
    }
    }
    cout<<endl;
    return 0;
}