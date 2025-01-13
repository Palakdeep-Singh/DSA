#include<iostream>
using namespace std;


struct rectangle{

    int len;
    int wid;
};

void initialize(struct rectangle *r,int l,int w){
    r->len=l;
    r->wid=w;
}

int area(struct rectangle r){
    return r.len*r.wid;
}

void changeLength(struct rectangle *r,int l){
    r->len=l;
}

int main(){
    
    struct rectangle r;

    initialize(&r,10,5);

    cout<<"Length: "<<r.len<<" "<<"Width: "<<r.wid;
    int c = area(r);

    cout<<endl<<"Area: "<<c<<endl;
    changeLength(&r,20);

    cout<<"Changed Length: "<<r.len<<endl;
    return 0;
}