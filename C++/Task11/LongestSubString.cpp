#include <iostream>
#include <string>
using namespace std;

string longestSubstring(const string &s)
{
	int start = 0, max_length = 0;
	int char_index[256];
	fill_n(char_index, 256, -1);

	for (int end = 0, current_start = 0; end < s.length(); ++end)
	{
		current_start = max(char_index[char(s[end])] + 1, current_start);
		char_index[char(s[end])] = end;

		if (end - current_start + 1 > max_length)
		{
			max_length = end - current_start + 1;
			start = current_start;
		}
	}

	return s.substr(start, max_length);
}

int main()
{
	string input_string;
	cout << "Enter the string: ";
	cin >> input_string;

	string result = longestSubstring(input_string);
	cout << "Longest Substring with Unique Characters: " << result << endl;

	return 0;
}
