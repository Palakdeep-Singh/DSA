#include<iostream>

using namespace std;


template <class T>
//To create a generic template of class use template <class T>
//before each class function and variable where the data type is required use T.
class arithematic{
   private:
   T num1;
   T num2;

   public:
   arithematic(T num1, T num2);

   T add();
   T sub();  
};

template <class T>
arithematic<T>::arithematic(T a, T b){
    this->num1 = a; //this-> refers to class data member.
    this->num2 = b;
}

template <class T>
T arithematic<T>::add(){
    T c;
    c = num1 + num2;
    return c;
}

template <class T>
T arithematic<T>::sub(){
    T c;
    c = num1 - num2;
    return c;
    }


int main(){
    
    arithematic<int> a(10,6);
    arithematic<float> b(1.6,2.7);
    cout<<"Add for int: "<<a.add()<<endl;
   
    cout<<"Add for float: "<<b.add()<<endl;
    cout<<"Subtract for int: "<<a.sub()<<endl;
    cout<<"Subtract for float :"<<b.sub()<<endl;

    return 0;
}