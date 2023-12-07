#include <iostream>
#include <string>
using namespace std;
class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& initialName, int initialAge) {
        name = initialName;
        age = initialAge;
    }
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};
int main() {
    Person p1("Shaik", 21);
    Person p2("Stark", 22);
    std::cout << "Person 1 Information:" << std::endl;
    p1.display();
    std::cout << "\nPerson 2 Information:" << std::endl;
    p2.display();
    return 0;
}
