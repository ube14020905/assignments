#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
private:
	long ac_no;
	string name;
	double balance;

public:
	BankAccount() : ac_no(0), name(""), balance(0.0) {}

	BankAccount(int n, string name, double b) : ac_no(n), name(name), balance(b) {}

	void deposite(double amount)
	{
		balance += amount;
		cout << "Current Balance: " << balance << endl;
	}

	void withDraw(double amount)
	{
		if (balance >= amount)
		{
			balance -= amount;
			cout << "Current Balance: " << balance << endl;
		}
		else
		{
			cout << "Inssufient Balance: " << balance << endl;
		}
	}
	void displayAccountInfo()
	{
		cout << "NAME: " << name << endl
			 << "Account Number: " << ac_no << endl
			 << "Balance: " << balance << endl;
	}
};
int main()
{
	BankAccount usr1;
	BankAccount usr2(14022002, "Stark", 500.12);
	cout << "User 1 Account Details: " << endl;
	usr1.displayAccountInfo();
	cout << "Account 2 Details: " << endl;
	usr2.displayAccountInfo();
	usr1.deposite(1000);
	usr1.displayAccountInfo();
	usr2.withDraw(100);
	usr2.displayAccountInfo();
	return 0;
}
