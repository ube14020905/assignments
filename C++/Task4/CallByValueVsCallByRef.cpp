#include<iostream>
using namespace std;
void callByVal(int a,int b){
    a=a+b;
    b=a-b;
    a=a-b;
    cout<<"Call by value A: "<<a<<" B: "<<b<<endl;
}

void callByRef(int& a,int& b){
    a=a+b;
    b=a-b;
    a=a-b;
    cout<<"CallByRef A: "<<a<<" B: "<<b<<endl;
}
main(){
    int a=10,b=20;
    cout<<"Before calling callByValue Function: "<<"A: "<<a<<" B: "<<b<<endl;
    callByVal(a,b);
    cout<<"\nAfter calling callByValue Function: "<<"A: "<<a<<" B: "<<b<<endl;
    cout<<"\n\nBefore calling callByRef Function: "<<"A: "<<a<<" B: "<<b<<endl;
    callByRef(a,b);
    cout<<"\nAfter calling callByRef Function: "<<"A: "<<a<<" B: "<<b<<endl;
    return 0;
}
