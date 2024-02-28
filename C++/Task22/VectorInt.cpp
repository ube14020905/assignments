#include <iostream>
#include <vector>
using namespace std;

vector<int> sorted(vector<int> vect)
{
	int count = vect.size();
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (vect[j] > vect[j + 1])
			{
				int temp = vect[j];
				vect[j] = vect[j + 1];
				vect[j + 1] = temp;
			}
		}
	}
	return vect;
}
int maxInt(vector<int> vect)
{
	vector<int> cp = sorted(vect);
	return cp.back();
}

int sum(vector<int> vect)
{
	int sum = 0;
	for (auto it = vect.begin(); it != vect.end(); it++)
	{
		sum += (*it);
	}
	return sum;
}
void display(vector<int> vect)
{
	for (auto it = vect.begin(); it != vect.end(); it++)
	{
		cout << (*it) << "\t";
	}
	cout << endl;
}
int main()
{
	vector<int> vect;
	cout << "Enter five integers to Vector! " << endl;
	for (int i = 0; i < 5; i++)
	{
		int val;
		cin >> val;
		vect.push_back(val);
	}
	cout << "The Integrs in the Vector: ";
	display(vect);
	cout << "The sum of Integers Presesnt in the Vector: " << sum(vect) << endl;
	cout << "The vector in sorted order: ";
	display(sorted(vect));
	cout << "The max Element in the Vector: " << maxInt(vect) << endl;
	return 0;
}
