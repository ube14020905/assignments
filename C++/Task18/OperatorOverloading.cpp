#include <iostream>
using namespace std;
class LinearEquation
{
private:
	double x;
	double y;
	double c;

public:
	LinearEquation() : x(0), y(0), c(0) {}
	LinearEquation(double a, double b, double c) : x(a), y(b), c(c) {}
	void display()
	{
		if(y<0){
			cout << x << "x " << y << "y = " << c << endl;
			return;	
		}
		cout << x << "x + " << y << "y = " << c << endl;
	}
	LinearEquation operator+(LinearEquation &l2)
	{
		return LinearEquation(x + l2.x, y + l2.y, c + l2.c);
	}
		LinearEquation operator-(LinearEquation &l2)
	{
		return LinearEquation(x - l2.x, y - l2.y, c - l2.c);
	}
		LinearEquation operator*(LinearEquation &l2)
	{
		return LinearEquation(x * l2.x, y * l2.y, c * l2.c);
	}
		LinearEquation operator/(LinearEquation &l2)
	{
		if(l2.x==0 || l2.y ==0 || l2.c==0){
			return LinearEquation(0,0,0);
		}
		return LinearEquation(x / l2.x, y / l2.y, c / l2.c);
	}
};
int main()
{
	LinearEquation l1(1, 2, 3);
	LinearEquation l2(4, 5, 6);
	LinearEquation res;
	res = l1 + l2;
	cout << "Addition of two Linear Equations: ";
	res.display();
	cout<<"subtration of two Linear Equations: ";
	res=l1-l2;
	res.display();
	cout<<"Multiplication of two Linear Equations: ";
	res=l1*l2;
	res.display();
	cout<<"Division of two Linear Equations: ";
	res=l1/l2;
	res.display();
	return 0;
}
