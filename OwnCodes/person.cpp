#include <iostream>
#include <string>
#include<memory>
using namespace std;
class Person
{
private:
    string name;
    int age;

public:
    Person() : name(""), age(0) {}
    Person(string name, int age) : name(name), age(age) {}
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    virtual void Display()
    {
        cout << "Name:   " << name << "    Age:    " << age;
    }
    ~Person()
    {
        cout << "Distructor called for Person: " << name << endl;
    }
};
class Student : public Person
{
private:
    double grade;

public:
    Student() : Person("", 0) {}
    Student(string name, int age, double grade) : Person(name, age), grade(grade) {}
    void Display() override
    {
        Person::Display();
        cout << "    grade:    " << grade << endl;
    }
    ~Student()
    {
        cout << "Distroctor called for student: " << Person::getName() << endl;
    }
};
class Teacher : public Person
{
private:
    string sub;

public:
    Teacher() : Person("", 0) {}
    Teacher(string name, int age, string sub) : Person(name, age), sub(sub) {}
    void Display() override
    {
        Person::Display();
        cout<< "    sub:    " << sub << endl;
    }
    ~Teacher()
    {
        cout << "Distroctor called for Teacher: " << Person::getName() << endl;
    }
};
int findPersonIndex(const unique_ptr<Person> persons[], int size, const string &name)
{
    for (int i = 0; i < size; ++i)
    {
        if (persons[i] && persons[i]->getName() == name)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int MAX_PERSONS = 100;
    unique_ptr<Person> persons[MAX_PERSONS];
    int count = 0;
    int choice;
    while (true)
    {
        cout << "Choose an option:" << endl;
        cout << "1. Add Person:" << endl;
        cout << "2. Delete Person:" << endl;
        cout << "3. Search Person:" << endl;
        cout << "4. Display All Persons:" << endl;
        cout << "5. Exit:" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            char personType;
            cout << "Enter person type (S for student, T for teacher): ";
            cin >> personType;
            string name;
            int age;
            cout << "Enter name: ";
            cin >> name;
            int index = findPersonIndex(persons, count + 1, name);
            if (index == -1)
            {
                if (personType == 'S')
                {
                    int age;
                    cout << "Enter Age: ";
                    cin >> age;
                    float grade;
                    cout << "Enter grade: ";
                    cin >> grade;
                    persons[count] = make_unique<Student>(name, age, grade);
                    count++;
                }
                else if (personType == 'T')
                {
                    int age;
                    cout << "Enter Age: ";
                    cin >> age;
                    string subject;
                    cout << "Enter subject: ";
                    cin >> subject;
                    persons[count] = make_unique<Teacher>(name, age, subject);
                    count++;
                }
                else
                {
                    cout << "Invalid person type!" << endl;
                }
            }
            else
            {
                cout << "Person with the same name already exists!" << endl;
            }
        }
        break;

        case 2:
        {
            string name;
            cout << "Enter name to delete: ";
            cin >> name;
            int index = findPersonIndex(persons, count + 1, name);
            if (index != -1)
            {
                persons[index].reset();
                cout << "Person deleted" << endl;
            }
            else
            {
                cout << "Person not found" << endl;
            }
        }
        break;
        case 3:
        {
            string name;
            cout << "Enter name to search: ";
            cin >> name;
            for (int i = 0; i < count + 1; i++)
            {
                if (persons[i] && persons[i]->getName() == name)
                {
                    persons[i]->Display();
                    break;
                }
            }
        }
        break;
        case 4:
        {
            cout << "All Persons Information:" << endl;
            for (int i = 0; i <=count; i++)
            {
                if(persons[i]){
                    persons[i]->Display();
                }
            }
        }
        break;
        case 5:
            cout << "Exiting program" << endl;
            return 0;
            break;
        default:
            cout << "Invalid choice. Try again" << endl;
        }
    }
    return 0;
}
