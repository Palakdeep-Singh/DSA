#include<iostream>
using namespace std;

struct rectangle{
  int len;
  int wid;
};

struct arr{
    int num[5];
    int n;
};

struct rectangle *fun(){ //Return type pointer.

  struct rectangle *p; //creating an object of type rectangle in heap...
  p = new rectangle; //in C++..

  p->len = 20;
  p->wid = 58;

  return p;
};

int area(struct rectangle r){
  int area = r.len * r.wid;
  r.len = 100;
  r.wid = 50;

  return area;

  // it is call by value ,actual parameters will not change.
}

int area2(struct rectangle *r){

    r->len = 12;
    r->wid = 70;

    int area = r->len * r->wid;

    return area;
}

void func(struct arr A){

    A.num[0] = 20;
    A.num[1] = 23;

    cout<<"Function Elements: "<<A.num[0]<<' '<<A.num[1];
}
int main(){

    rectangle r1 = {10,6};

    int c = area(r1);

   cout<<c<<endl;

   cout<<r1.len<<" "<<r1.wid<<endl; //CALL BY VALUE len wid will not change!.

   //can we modify the actual parameter in the function?? 
   //Use pointer to structure.
   
   int c2 = area2(&r1); //Passing address of structure.

   cout<<c2<<endl;


   //what if array is there in structre and structure is passed to a function?

   arr  a1 = {{1,6,4,2,7},5};
   
   func(a1); //array is passed as call by value!!.
            //But Actual array will not change!!

   cout<<endl<<"Actual Array Elements: "<<a1.num[0]<<' '<<a1.num[1]<<endl; 

  struct rectangle *ptr; //To Access Structure in Heap. 

  ptr = fun();  

  cout<<endl<<"Length: "<<ptr->len<<' '<<"Width: "<<ptr->wid<<endl;
    return 0;
}