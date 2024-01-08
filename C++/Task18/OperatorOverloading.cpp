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
		cout << x << "x + " << y << "y = " << c << endl;
	}
	LinearEquation operator+(LinearEquation &l2)
	{
		return LinearEquation(x + l2.x, y + l2.y, c + l2.c);
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
	return 0;
}
