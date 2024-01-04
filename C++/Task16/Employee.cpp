#include <iostream>
#include <string>
using namespace std;
class Employee
{
public:
	virtual void calculateSalary() = 0;
};
class Manager : public Employee
{
private:
	double salary;
	double bonusPercentage;

public:
	Manager(double sal, double bonus) : salary(sal), bonusPercentage(bonus) {}

	void calculateSalary()
	{
		double totalSalary = salary + ((salary * bonusPercentage) / 100);
		cout << "The Total Salary Of Manager is : " << totalSalary << endl;
	}
};
class Developer : public Employee
{
private:
	double salary;
	double OvertimeRate;

public:
	Developer(double basic, double OvertimeSal) : salary(basic), OvertimeRate(OvertimeSal) {}

	void calculateSalary()
	{
		double totalSalary = salary + OvertimeRate;
		cout << "The Total Salary of Developer is : " << totalSalary << endl;
	}
};
int main()
{
	Employee *emp1 = new Manager(60000, 15);
	Employee *emp2 = new Developer(30000, 6000);
	emp1->calculateSalary();
	emp2->calculateSalary();
	return 0;
}
