#include<iostream>
using namespace std;
void squareByVal(int val){
	val=val*val;
	cout<<"The Square of given number is "<<val<<endl;
}
void cubeByRef(int& ref){
	ref=ref*ref*ref;
	cout<<"the cube of given number is "<<ref<<endl;
}
int main(){
	int val;
	cout<<"Enter an integer: ";
	cin>>val;
	squareByVal(val);
	cout<<"The value after SquareByVal: "<<val<<endl;
	cubeByRef(val);
	cout<<"The value after CubeByref: "<<val<<endl;
	return 0;
}
