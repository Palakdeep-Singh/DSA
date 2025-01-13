#include<iostream>

using namespace std;

//struct name { data}
//size will be sum of all data types of a structure.
struct Rectangle{
    int length; //4
    int width;  //4
    char c;     //1 will be used but allocatd 4

    //total is 9 but it will take 12 means 3 extra.
    //Easy for machine to understand.
}r;

int main(){
    
    //dot operator is used to access members or modify them.
    r.length = 10;
    r.width = 20;

    int area = r.length * r.width;

    cout<<area<<endl;
    
    //another way..
    //declaration + initialization.
    struct Rectangle r = {30,20,'a'};
    
    cout<<r.length*r.width<<endl;

    cout<<endl<<sizeof(r)<<endl;
    return 0;
}