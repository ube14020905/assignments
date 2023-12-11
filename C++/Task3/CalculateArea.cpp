#include<iostream>

using namespace std;

class Shape
{
public:
    virtual void area(void) = 0;
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
    void area(void)
    {
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
        cout << "Area of Circle: " << ar << endl;
    }
};
int main()
{
    Rectangle rec(4, 5);
    Circle cir(3);
    cout << "Rectangle ";
    rec.area();

    cout << "Circle ";
    cir.area();

    return 0;
}
