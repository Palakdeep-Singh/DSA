#include<iostream>
#include <stdio.h>

using namespace std;

int e(double x,double n){
    static double s=1;  //calling time operations krne h.

    if(n==0) return s;  // jb n=0 pe pahunch jaye tb return call krlo.
    else{
      s = 1 + x/n *s;  // multiple 1+x/n usse pichle wale se. 
      return e(x,n-1); //func ko aage bdao return time kuch nhi krna.
    }
}

int main(){
    
    double c = e(2,5);
    printf("%lf",c);
    return 0;
}

/*   Explanation...
          e(2,5)
       |          |
    s= 1+2/5     e(2,4) 
               |          |
        s =1+2/4*s     e(2,3)
                     |         |
              s= 1+2/3*s     e(2,2)
                           |          |
                    s=1+2/2*s       e(2,1)
                                  |         |
                           s=1+2/1*s   e(2,0)
                                          |
                                        return s
*/