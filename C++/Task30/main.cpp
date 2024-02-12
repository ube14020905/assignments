#include <iostream>
#include "stringOps.h"
using namespace std;

int main()
{
	string str1, str2;
	cout << "Enter string 1: ";
	cin >> str1;
	cout << "Enter String 2: ";
	cin >> str2;
	cout << "Reverse of String 1: " << reverse(str1) << endl;
	cout << "Reverse of String 2: " << reverse(str2) << endl;
	string cat = concat(str1, str2);
	cout << "Concatenation of str1 + str2 : " << cat << endl;
	cout << "Reverse of Concatenated string: " << reverse(cat) << endl;
	int start, end;
	cout << "Enter starting char index and no. of chars to be in substr: ";
	cin >> start >> end;
	if (start + end >= cat.length())
	{
		cout << "size of string exceeded" << endl;
		return 1;
	}
	cout << "substring: " << substr(cat, start, end) << endl;
	return 0;
}
