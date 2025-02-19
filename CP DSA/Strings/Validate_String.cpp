#include<iostream>

using namespace std;

//Function for checking valid or invalid name.
int validate(char *str){
      
      for(int i=0;str[i]!='\0';i++){
        //just remove the special characters..
        if(!(str[i]>=65 && str[i]<=90)
            && !(str[i]>=97 && str[i]<=122)
            && !(str[i] >=48 && str[i] <= 57)){

                   return 0;
      }
       }
       return 1;
}


int main(){

    //Create a string.    
    char name[100];
    cout<<"Enter Your Name: ";
    gets(name);

    //now check the name is valid or not.
    if(validate(name)){ 
        cout<<"Valid Name"<<endl; 
        }
        else{
        cout<<"Invalid Name"<<endl;
    }
    return 0;
}