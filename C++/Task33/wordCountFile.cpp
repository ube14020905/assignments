#include<iostream>
#include<fstream>
#include<map>
#include<string>

using namespace std;

string lowerAndOnlyChar(string word) {
    string out;
    for (char ch : word) {
        if (isalpha(ch)) {
            out += tolower(ch);
        }
    }
    return out;
}

void readfile(string path, map<string, int>& data) {
    ifstream source(path);
    string word;
    while (source >> word) {
        string cleanedWord = lowerAndOnlyChar(word);
        data[cleanedWord]++;
    }
}

void writefile(string path, map<string, int>& data) {
    ofstream dest(path);
    for (auto it = data.begin(); it != data.end(); it++) {
        dest << it->first << "\t" << it->second << "\n";
    }
}

int main() {
    string source = "jarvis.txt";
    string destiny = "friday.txt";

    map<string, int> wordFrequency;

    readfile(source, wordFrequency);
    writefile(destiny, wordFrequency);

    cout << "Word frequencies written to: " << destiny << endl;

    return 0;
}
