#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encrypt(const string &text, const string &key)
{
    string encryptedText = text;
    size_t keyIndex = 0;

    for (char &c : encryptedText)
    {
        c = c ^ key[keyIndex];
        keyIndex = (keyIndex + 1) % key.size();
    }

    return encryptedText;
}

void readFile(string path, string &data)
{
    ifstream inFile(path);
    if (!inFile.is_open())
    {
        cerr << "Error opening input file: " << path << endl;
        return;
    }
    string line;
    while (getline(inFile, line))
    {
        data += line;
    }
    inFile.close();
}
void writeFile(string path, string &data)
{
    ofstream outFile(path);
    if (!outFile.is_open())
    {
        cerr << "Error opening output file: " << path << endl;
        return;
    }

    outFile << data;
    outFile.close();

    cout << "Encryption successful. Encrypted text written to: " << path << endl;
}
int main()
{

    string inputFile = "edith.txt";
    string outputFile = "encrypt.txt";

    string encryptionKey, data;
    cout << "Enter a key to encrypt data: ";
    cin >> encryptionKey;
    readFile(inputFile, data);
    string encryptedText = encrypt(data, encryptionKey);

    writeFile(outputFile, encryptedText);
    return 0;
}
