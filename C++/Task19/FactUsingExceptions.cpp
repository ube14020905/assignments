#include <iostream>
#include <exception>
using namespace std;
using ll = long long;
ll factorial(ll num)
{
	ll fact = 1;
	while (num != 0)
	{
		fact *= num;
		num--;
	}
	return fact;
}
int main()
{
	try
	{
		ll number;
		cout << "Enter a Number: ";
		cin >> number;
		if (number < 0)
		{
			throw number;
		}
		cout << "Factorial of the Given number is: " << factorial(number) << endl;
	}
	catch (ll e)
	{
		cerr << "Please enter a positive Number: " << e << endl;
	}
	catch (...)
	{
		cerr << "An Unknown Exception Occurred" << endl;
	}
}
