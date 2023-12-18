#include <iostream>
using namespace std;
class arrayOps
{
private:
	int size;
	int *arr;

public:
	int *sortedArr;
	int s;
	arrayOps(int a) : size(a), s(0)
	{
		sortedArr = new int[size];
		arr = new int[size];
		cout << "Enter the Elements to Array:" << endl;
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
			s += arr[i];
		}
	}
	~arrayOps()
	{
		delete arr;
		delete sortedArr;
	}
	void display()
	{
		cout << "The Original Array: " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << "  ";
		}
		cout << endl;
	}
	void sorted(void)
	{
		for (int i = 0; i < size; i++)
		{
			sortedArr[i] = arr[i];
		}
		int i, j;
		for (i = 0; i < size - 1; i++)
		{
			for (j = 0; j < size - i - 1; j++)
			{
				if (sortedArr[j] > sortedArr[j + 1])
				{
					int t = sortedArr[j];
					sortedArr[j] = sortedArr[j + 1];
					sortedArr[j + 1] = t;
				}
			}
		}
	}
	void maxVal()
	{
		sorted();
		cout << sortedArr[size - 1] << "  Is The Max Value of given Array!" << endl;
	}
	void printSorted()
	{
		sorted();
		cout << "The Sorted Array:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << sortedArr[i] << "  ";
		}
		cout << endl;
	}
	void sum()
	{
		cout << "The sum of the elements of the Array:  " << s << endl;
	}
	void average()
	{
		cout << "The average of the integers in the Array:  " << ((double)s / (double)size) << endl;
	}
	void search()
	{
		int k;
		cin >> k;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == k)
			{
				cout << "The value  " << k << "  Found at Index:  " << i << endl;
			}
		}
	}
};
main()
{
	arrayOps a(8);
	a.display();
	a.printSorted();
	a.maxVal();
	a.sum();
	a.average();
	a.search();
}
