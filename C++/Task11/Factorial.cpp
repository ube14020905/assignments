#include<iostream>
using namespace std;
int main(){
	long fact=1;
	int num;
	cout<<"Enter a Positive Integer: ";
	cin>>num;
	if(num<0)
	{
		cout<<"Negative numbers don't have Factorial!"<<endl;
	}
	else{
		do{
			fact=fact*num;
			num--;
		}while(num>1);
		cout<<"The Factorial of Given Number: "<<fact<<endl;
	}
	return 0;
}


