#include <iostream>
#include <cctype>
using namespace std;
void noSpaceLower(string &str) {
    string result;
    for (char &ch : str) {
        if (!isspace(ch)) {
            result += tolower(ch);
        }
    }
    str = result;
}
bool isPalin(string &str) {
	noSpaceLower(str);
    for (int i = 0; i < str.length() / 2; ++i) {
        if (str[i] != str[str.length() - i - 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    if (isPalin(s)) {
        cout << "PALINDROME" << endl;
    } else {
        cout << "NOT A PALINDROME" << endl;
    }
    return 0;
}
