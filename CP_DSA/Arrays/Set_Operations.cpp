#include <iostream>

using namespace std;

int main(){

    int m;
    cout<<"Enter the Length of 1st Array: ";
    cin>>m;

    int *A;
    A = new int[m];
    cout<<"Enter elements:\n";
    for(int i=0;i<m;i++) cin>> A[i];

    int n;
    cout<<"Enter the Length of 2nd Array: ";
    cin>>n;

    int *B = new int[n];
    cout<<"Enter elements:\n";
    for(int j=0;j<n;j++) cin>> B[j];

    int i=0,j=0,k=0;
    int *C = new int[k];

    //Union...
//     while(i<m && j<n){

//         if(A[i]<B[j]) {
//             C[k++] = A[i++];
//     }
//     else if(A[i]>B[j]){
//         C[k++] = B[j++];
//     }
//     else{
//         C[k++] = A[i++];
//         j++;
//     }
// }  
    
   //Intersection...
   while(i<m && j<n){
    if(A[i]<B[j]){
        i++;
    }
    else if(A[i]>B[j]){
        j++;
    }
    else{
        C[k++] = A[i++];
        j++;
    }
   }
// while( i<m ) C[k++] = A[i++];
// while(j<n) C[k++] = B[j++];
 
  int p=k;
// cout<<"Union of 2 Arrays:\n";
cout<<"Intersection of 2 Arrays:\n";
for(int t=0;t<p;t++) cout<<C[t]<<" ";
 
delete [] A;
delete [] B;
delete [] C;

return 0;

}