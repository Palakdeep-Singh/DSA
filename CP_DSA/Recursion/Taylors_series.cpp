#include<iostream>
using namespace std;


double e(int x,int n){
    static double p =1,f=1;  //Static variables function return call me state change nhi krte.
    double r;

    if(n==0) return 1;
    else{
        r = e(x,n-1);  // function call kro jbtk ye n=0 tk nahi pahunchta and baaki sab operations return call me lena h 
        p = p*x;    // func jb return hoga toh inme increments krke result me add krna h.
        f = f*n;

        return r + p/f; //returning result.
    }
}
int main(){
    
   int x=2;
   printf("%.2lf ",e(2,5));

    return 0;
}