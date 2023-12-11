#include <iostream>
#include <string>
using namespace std;
class Person {
private:
    string name;
    int age;
public:
    Person(const string& Name, int Age) {
        name = Name;
        age = Age;
    }
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
int main() {
    Person p1("Shaik", 21);
    Person p2("Stark", 22);
    cout << "Person 1 Information:" << endl;
    p1.display();
    cout << "\nPerson 2 Information:" << endl;
    p2.display();
    return 0;
}
