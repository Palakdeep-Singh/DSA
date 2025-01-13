#include<iostream>
#include <stdio.h>

using namespace std;

class rec{
   private:
   //declare the data members which we use in functions.
   int len;
   int wid;

   public:

   rec(){
    len = 0;
    wid = 0;
   }

   rec(int l,int w){

    len = l;
    wid = w;
   }

   int area();

   int perimeter(){
    return 2*(len + wid);
   }
    
   int getlen(){
    return len;
   }

   int setlen(int l){
    len = l;
    return len;
   }

   ~rec(){ //It is used to deallocate the memory which is allocated by the class.
    cout<<"Destructor called"<<endl; //object destroyed.
   }
};

  int rec::area(){ 
 //scope resolution operator(::) is used to access the member functions of the class.

    return len*wid;
   }


int main(){
    
    rec r(10,8);

    //functions are accessable by using . operator.
    cout<<"Area:"<<r.area()<<endl;
    cout<<"Perimeter:"<<r.perimeter()<<endl;
    cout<<"Len:"<<r.getlen()<<endl;
    cout<<"Len changed:"<<r.setlen(56)<<endl;
    return 0;
}