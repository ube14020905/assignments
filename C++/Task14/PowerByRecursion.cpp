#include<iostream>
using namespace std;
using ll=long long;
ll calculatePower(ll base,ll power){
	if(power==0){
		return 1;
	}
	return (base*calculatePower(base,power-1));
}
int main(){
	ll base,power;
	cout<<"Enter the Base number and Power: ";
	cin>>base>>power;
	cout<<power<<" th power of "<<base<<" is "<<calculatePower(base,power)<<endl;
	return 0;
}
