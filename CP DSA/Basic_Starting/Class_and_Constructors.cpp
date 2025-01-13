#include<iostream>
using namespace std;



//Structure is a class of type public.
//All elements are accessable.
struct rectangle{
   int len;
   int wid;

   void initialize(int l,int w){
    len=l;
    wid=w;
}

int area(){
    return len*wid;
}

void changeLength(int l){
    len=l;
}
};

//Class is similar to Structure of C.
class rec{
    private: //Accessable within the class only.
    int len;
    int wid;

    public: //Functions which we use.

    rec (int l,int w){     //IT IS A CONSTRUCTOR...

    //Removed initialized function as it is not required.
    //Initialized the len and wid in class
    len=l;
    wid=w;
}

int area(){
    return len*wid;
}

void changeLength(int l){
    len=l;
}
};

int main(){
    
    rectangle r = {0,0};
    
    r.initialize(19,5);
    r.area();
    r.changeLength(5);


/*    class in C++ = structure in C.   */

    rec r1(0,50); //declaration + initialization.

    r1.changeLength(6);

    r1.area();

    return 0;
}