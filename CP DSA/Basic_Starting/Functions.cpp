/********* Functions********/

#include<iostream>
using namespace std;

int add(int x,int y){
    // x,y are formal parameters.
    return x+y;
}

/*********** Parameter Passing **********/

void swap(int x,int y){
    //it is call by value.

    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swap2(int &x,int &y){
   //it is call by reference.
   int temp;
   temp = x;
   x = y;
   y = temp;
   //reference do not take any extra memory.

}

void swap3(int *a,int *b){
    //it is call by address using pointers.
    int temp = *a;
    *a = *b;
    *b = temp;

} 

int main(){

    int a = 10,b=15;
    int c = add(a,b);

    cout<<c<<endl;
     swap(a,b); //swap is call by value fun(actual parameters do not change).

     cout<<endl<<a<<' '<<b<<endl;

     swap2(a,b);
    
    cout<<endl<<a<<' '<<b<<endl; //actual parameters are modified. why??
    //Program chlta rhega lekin jese hi swap2 function call hua uske andar
    // a ka refernce x bna or  ka y toh a ki jga x b ki jga y and swapping hui machine code hi paste hua.
    
    //Generslly reference is not used much.

    /*********** Call by Address **********/

       swap3(&a,&b); //we have to pass the address. Use &.

       cout<<a<<' '<<b<<endl;

   
    return 0;
}