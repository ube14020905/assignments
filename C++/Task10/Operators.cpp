#include <iostream>
using namespace std;
void ArithmeticOps()
{
	int a, b;
	cout << "Enter Two Integers" << endl;
	cin >> a >> b;
	cout << "Sum: " << (a + b) << endl;
	cout << "Difference: " << (a - b) << endl;
	cout << "Product: " << (a * b) << endl;
	if (b == 0)
	{
		cout << "Division not Possible" << endl;
	}
	else
	{
		cout << "Quotient: " << (a / b) << endl;
		cout << "Reminder: " << (a % b) << endl;
	}
}
void RelationalOps()
{
	int num1, num2;
	cout << "Enter to Integers: " << endl;
	cin >> num1 >> num2;
	cout << "Equality: \nnum1 == num2: " << (num1 == num2) << endl;
	cout << "Inequality: \nnum1 != num2: " << (num1 != num2) << endl;
	cout << "Less Than: \nnum1 < num2: " << (num1 < num2) << endl;
	cout << "Greater Than: \nnum1 > num2: " << (num1 > num2) << endl;
}
void LogicalOps()
{
	bool b1, b2;
	cout << " Enter Two Boolean Values ( 0 or 1 ): " << endl;
	cin >> b1 >> b2;
	cout << "Logical AND b1 && b2 :" << (b1 && b2) << endl;
	cout << "Logical OR b1 || b2 :" << (b1 || b2) << endl;
	cout << "Logical NOT for !b1: " << (!b1) << endl;
	cout << "Logical NOT for !b2: " << (!b2) << endl;
}
void AssignmentOps()
{
	int x = 5;
	cout << "Assigned Value: " << x << endl;
	x += 3;
	cout << "After += 3 : " << x << endl;
	x -= 2;
	cout << "After -= 2 : " << x << endl;
	x *= 2;
	cout << "After *= 2 : " << x << endl;
	x /= 2;
	cout << "After /= 2 : " << x << endl;
	x %= 5;
	cout << "After %= 5 : " << x << endl;
}
main()
{
	cout << "1.Arithmetic Operations:" << endl;
	ArithmeticOps();
	cout << "2.Relational Operations:" << endl;
	RelationalOps();
	cout << "3.Logical operations:" << endl;
	LogicalOps();
	cout << "4.Assignment Operations: " << endl;
	AssignmentOps();
}
