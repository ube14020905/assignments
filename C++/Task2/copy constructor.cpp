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
    Person(const Person& copy) {
        name = copy.name;
        age = copy.age;
        cout<<"this is copy Constructor of : "<<name<<endl;
    }
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person p1("Shaik", 21);
    cout << "Person 1 Information:" << endl;
    p1.display();
    Person p2 = p1;
    cout << "\nPerson 2 (Copy of P1) Information:" << endl;
    p2.display();
    return 0;
}
