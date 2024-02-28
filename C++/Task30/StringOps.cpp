#include "stringOps.h"

using namespace std;

string reverse(string str)
{
	return string(str.rbegin(), str.rend());
}

string concat(string str1, string str2)
{
	return str1 + str2;
}

string substr(string str, int start, int end)
{
	return str.substr(start, end);
}
