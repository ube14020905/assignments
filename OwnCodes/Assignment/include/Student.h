#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
class Student {
private:
    int id;
    std::string name;
    float grade;
public:
    Student();
    Student(int id, std::string name, float grade);
    virtual ~Student();  
    virtual void displayDetails() const = 0;
    int getID() const;
    std::string getName() const;
    float getGrade() const;
    virtual float getFinalScore()const;
    virtual void calculateFinalScore();
    void setID(int ID);
    void setName(const std::string& Name);
    void setGrade(float Grade);

    static bool isValidID(int ID);
    static bool isValidName(const std::string& Name);
    static bool isValidGrade(float Grade);
};

std::ostream& operator<<(std::ostream& os, const Student& student);
std::istream& operator>>(std::istream& is, Student& student);

#endif
