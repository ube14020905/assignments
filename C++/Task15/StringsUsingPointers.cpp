#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int stringLen(string *str)
{
	int len = 0;
	for (char &c : *str)
	{
		len++;
	}
	return len;
}
void stringConcate(string *str1, string *str2)
{
	*str1 += *str2;
}
void stringRev(string *str)
{
	int len = stringLen(str);
	for (int i = 0; i < len / 2; i++)
	{
		swap((*str)[i], (*str)[len - 1 - i]);
	}
}
int main()
{
	string str1, str2,str3;
	cout << "Enter String 1: ";
	cin >> str1;
	cout << "Length of Given String 1: " << stringLen(&str1) << endl;
	cout << "Enter String 2: ";
	cin >> str2;
	str3=str1;
	cout << "Length of Given String 2: " << stringLen(&str2) << endl;
	stringConcate(&str1, &str2);
	cout << "Concate of Two strings: " << str1 << endl;
	stringRev(&str3);
	cout << "Reverse of string 1: " << str3 << endl;
	stringRev(&str2);
	cout << "Reverse of string 2: " << str2 << endl;
	return 0;
}
