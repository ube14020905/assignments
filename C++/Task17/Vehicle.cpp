#include <iostream>
#include <string>
using namespace std;
class Vehicle
{
private:
	string brand;
	int year;

public:
	Vehicle(string brand, int year) : brand(brand), year(year) {}

	void displayInfo() const
	{
		cout << "Brand: " << brand << ", Year: " << year << endl;
	}
};

class Car : public Vehicle
{
private:
	int numDoors;

public:
	Car(string brand, int year, int numDoors) : Vehicle(brand, year), numDoors(numDoors) {}

	void displayInfo() const
	{
		Vehicle::displayInfo();
		cout << "Number of doors: " << numDoors << endl;
	}
};

class Bicycle : public Vehicle
{
private:
	int numGears;

public:
	Bicycle(string brand, int year, int numGears) : Vehicle(brand, year), numGears(numGears) {}

	void displayInfo() const
	{
		Vehicle::displayInfo();
		cout << "Number of gears: " << numGears << endl;
	}
};

int main()
{
	Car myCar("Toyota", 2022, 4);
	Bicycle myBicycle("Giant", 2021, 21);

	cout << "Car Information:" << endl;
	myCar.displayInfo();
	cout << endl;

	cout << "Bicycle Information:" << endl;
	myBicycle.displayInfo();

	return 0;
}
