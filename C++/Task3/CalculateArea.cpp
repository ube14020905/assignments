#include<iostream>
using namespace std;
class Shape
{
public:
    virtual void area(void) = 0;
    void display(){
        cout<<"Shape: ";
        area();
    }
};
class Rectangle : public Shape
{
private:
    int l;
    int b;

public:
    Rectangle(int x, int y)
    {
        l = x;
        b = y;
    }
    void area()
    {
        cout << "Rectangle"<< endl;
        cout << "Area of rectangle: " << l * b << endl;
    }
};

class Circle : public Shape
{
private:
    int r;

public:
    Circle(int a)
    {
        r = a;
    }
    void area(void)
    {
        double pi = 22.0 / 7.0;
        double ar = pi * r * r;
        cout << "Circle" << endl;
        cout << "Area of Circle: " << ar << endl;
    }
};

int main()
{
    Rectangle rec(4, 5);
    Circle cir(3);
    rec.display();
    cir.display();
    return 0;
}
