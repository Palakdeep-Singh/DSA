#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int pallindrom(string str,int start,int end){
    if(start > end){
        return true;
    }
    else{
       if(str[start] != str[end]) return false;
       return pallindrom(str,start++,end--);
        }
}
int main(){
       
    char str[200];
    fgets(str,200,stdin);
    int c = pallindrom(str,0,strlen(str)-1);
    printf("%d\n",c);
    return 0;
}