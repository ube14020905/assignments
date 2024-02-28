#include <iostream>
#include <string>
using namespace std;

string longestSubstring(const string &str)
{
	int start = 0, max_length = 0;
	int char_index[256];
	fill_n(char_index, 256, -1);

	for (int end = 0, current_start = 0; end < str.length(); ++end)
	{
		current_start = max(char_index[char(str[end])] + 1, current_start);
		char_index[char(str[end])] = end;

		if (end - current_start + 1 > max_length)
		{
			max_length = end - current_start + 1;
			start = current_start;
		}
	}

	return str.substr(start, max_length);
}

int main()
{
	string str;
	cout << "Enter the string: ";
	cin >> str;

	string result = longestSubstring(str);
	cout << "Longest Substring: " << result << endl;

	return 0;
}
