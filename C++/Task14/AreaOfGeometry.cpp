#include <iostream>
#include <cmath>
using namespace std;
class ShapeCalculator {
public:
    long calculateArea(long length, long width) {
        return length * width;
    }
    double calculateArea(double radius) {
        return M_PI * radius * radius;
    }
	double calculateArea(double base, double height) {
        return 0.5 * base * height;
    }

    long calculateAreaSquare(long side) {
        return side * side;
    }
};

int main() {
    ShapeCalculator calculator;
    double rectangleArea = calculator.calculateArea(4l, 6l);
    double circleArea = calculator.calculateArea(5.0);
    double triangleArea = calculator.calculateArea(3.0, 8.0);
    double squareArea = calculator.calculateAreaSquare(4);

    cout << "Area of Rectangle: " << rectangleArea << endl;
    cout << "Area of Circle: " << circleArea << endl;
    cout << "Area of Triangle: " << triangleArea << endl;
    cout << "Area of Square: " << squareArea << endl;
    return 0;
}
