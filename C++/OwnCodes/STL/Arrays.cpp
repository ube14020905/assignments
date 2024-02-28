#include<iostream>
#include<array>
using namespace std;
int main(){
	array<int,5> arr;
	int s=0;
	cout<<"Enter 5 integers:"<<endl;
	for(int i=0;i<5;i++){
		cin>>arr[i];
		s+=arr.at(i);
	}
	cout<<"Sum of elements: "<<s<<endl;
}

