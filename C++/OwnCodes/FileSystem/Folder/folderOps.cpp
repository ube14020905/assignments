#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

void createFolder(const string &path)
{
    try
    {
        if (fs::create_directory(path))
        {
            cout << "Folder Created Successfully!!!" << endl;
        }
        else
        {
            cerr << "Error occurred while creating folder!!!" << endl;
        }
    }
    catch (const exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
}

void deleteFolder(const string &path)
{
    try
    {
        fs::remove_all(path);
        cout << "Folder deleted successfully!!!" << endl;
    }
    catch (const exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
}

void renameFolder(string oldPath, string newPath)
{
    try
    {
        fs::rename(oldPath, newPath);
        cout << "Folder renamed successfully!!!" << endl;
    }
    catch (const exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
}

int main()
{
    string path = "sample";
    createFolder(path);
    renameFolder(path, "sample1");
    deleteFolder("sample1");
    return 0;
}
