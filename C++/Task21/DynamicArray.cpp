#include <iostream>
#include <stdexcept>
using namespace std;
class IntArray
{
private:
	int *arr;
	int size;

public:
	IntArray(int size) : size(size)
	{
		arr = new int[size];
		cout << "Enter Integer to the Array: ";
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
	}
	~IntArray()
	{
		delete arr;
	}
	void DisplayArray()
	{
		cout << "Elements of the Array: ";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << "\t";
		}
		cout << endl;
	}
	int intAtIndex(int index)
	{
		if (index < 0 || index >= size)
		{
			throw out_of_range("Please Enter Index from zero to size-1");
		}
		return arr[index];
	}
	void setAtIndex(int index)
	{
		if (index < 0 || index >= size)
		{
			throw out_of_range("Please Enter index from zero to size-1");
		}
		int val;
		cout << "Enter the Value to Replace: ";
		cin >> val;
		arr[index] = val;
	}
};
int main()
{
	int size;
	cout << "Enter the Size of The Array: ";
	cin >> size;
	IntArray arr(size);
	arr.DisplayArray();
	try
	{
		int index;
		cout << "Enter The Index to search: ";
		cin >> index;
		cout << "The Value at the Index " << index << " : " << arr.intAtIndex(index) << endl;
		cout << "Enter the Index to change the Value: ";
		cin >> index;
		arr.setAtIndex(index);
		cout << "The integers After Changes!" << endl;
		arr.DisplayArray();
	}
	catch (out_of_range e)
	{
		cerr << "Exception: " << e.what() << endl;
	}
	catch (...)
	{
		cerr << "Unknown Exception Occurred" << endl;
	}
	return 0;
}
