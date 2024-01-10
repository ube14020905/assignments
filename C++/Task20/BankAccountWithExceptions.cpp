#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class InsufficientFundsException : public exception
{
public:
	const char *what() const noexcept override
	{
		return "Insufficient funds for withdrawal";
	}
};

class BankAccount
{
private:
	long ac_no;
	string name;
	double balance;

public:
	BankAccount() : ac_no(0), name(""), balance(0.0) {}

	BankAccount(int n, string name, double b) : ac_no(n), name(name), balance(b) {}

	void deposit(double amount)
	{
		if (amount < 0)
		{
			throw invalid_argument("Invalid deposit amount. Amount must be non-negative.");
		}

		balance += amount;
		cout << "Deposit successful. Current Balance: " << balance << endl;
	}

	void withdraw(double amount)
	{
		if (balance >= amount)
		{
			balance -= amount;
			cout << "Withdrawal successful. Current Balance: " << balance << endl;
		}
		else
		{
			throw InsufficientFundsException();
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
	try
	{
		BankAccount usr1;
		BankAccount usr2(14022002, "Stark", 500.12);

		cout << "User 1 Account Details: " << endl;
		usr1.displayAccountInfo();
		cout << "Account 2 Details: " << endl;
		usr2.displayAccountInfo();

		usr2.deposit(-1000);
		usr1.displayAccountInfo();

		usr2.withdraw(1000);
		usr2.displayAccountInfo();
	}
	catch (InsufficientFundsException &e)
	{
		cerr << "Exception: " << e.what() << endl;
	}
	catch (invalid_argument e)
	{
		cerr << "Exception: " << e.what() << endl;
	}
	catch (...)
	{
		cerr << "Unknown Exception Occurred!" << endl;
	}

	return 0;
}
