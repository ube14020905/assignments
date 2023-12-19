#include<iostream>
using namespace std;
namespace math{
	double square(double d){
		return (d*d);
	}
}
namespace display{
	void printResult(double d){
		cout<<"The square value of given value: "<<math::square(d)<<endl;
	}
}
using namespace display;
main(){
	double d;
	cout<<"Enter a value to square: "<<endl;
	cin>>d;
	printResult(d);
}
