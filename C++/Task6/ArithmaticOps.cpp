#include<iostream>
using namespace std;
int add(int a,int b){
    return a+b;
}
int subtract(int a,int b){
    return a-b;
}
int multiply(int a,int b){
    return a*b;
}
int divide(int a,int b){
    if(b == 0){
        return 0;
    }
    else{
        return a/b;
    }
}
int mod(int a,int b){
        if(b == 0){
        return 0;
    }
    else{
        return a%b;
    }
}
int main(){
    int a,b;
    cout << "Enter a,b:" << endl;
    cin >> a;
    cin >> b;
    cout << "Addition: " << add(a,b) << endl;
    cout << "Subtraction: " << subtract(a,b) << endl;
    cout << "Multiplication: "<< multiply(a,b) << endl;
    cout << "Division: "<< divide(a,b) << endl;
    cout << "Modulus: " << mod(a,b) << endl;
}
