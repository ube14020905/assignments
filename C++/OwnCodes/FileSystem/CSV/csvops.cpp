#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;
namespace fs = filesystem;
int columns = 4;
vector<string> splitString(string data)
{
    vector<string> res;
    stringstream ss(data);
    string value;
    while (getline(ss, value, ','))
    {
        res.push_back(value);
    }
    return res;
}
void createFile(string path)
{
    ofstream file(path);
    if (file.is_open())
    {
        cout << "file created successfully!!!" << endl;
        file.close();
    }
    else
    {
        cerr << "Error while creating file!!!" << endl;
        file.close();
    }
}
void deleteFile(string path)
{
    try
    {
        fs::remove(path);
        cout << "One file removed successfully!!!" << endl;
    }
    catch (exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
}
void renameFile(string OldPath, string NewPath)
{
    try
    {
        fs::rename(OldPath, NewPath);
        cout << "File renamed successfully!!!" << endl;
    }
    catch (exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
}
void writeFile(string path)
{
    ofstream file(path, ios::app);

    if (!file.is_open())
    {
        cerr << "Error in opening the file!!!" << endl;
        return;
    }
    cout << "Enter no of rows you want to insert: ";
    int count;
    cin >> count;
    cout << "Enter data to insert into the file: " << endl;
    cout << "enter name age dept salary separated by spaces: " << endl;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            string val;
            cin >> val;
            file << val + ",";
        }
        file << "\n";
    }
}
void readCSV(string path)
{
    ifstream file(path);
    if (!file.is_open())
    {
        cerr << "Error in opening the file!!!" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        vector<string> data = splitString(line);
        for (auto it = data.begin(); it != data.end(); it++)
        {
            cout << *it << "\t\t";
        }
        cout << endl;
    }
}
int main()
{
    string path = "employee.csv";
    // createFile(path);
    writeFile(path);
    readCSV(path);
}