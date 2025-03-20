#include "iostream"
using namespace std;

class Shape {
protected:
    string position;
    string color;
    double borderThickness;

public:
    Shape(string pos, string col, double border = 1.0)
        : position(pos), color(col), borderThickness(border) {}

    virtual void draw() {
        cout << "Drawing a generic shape at " << position << " with color " << color << endl;
    }

    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(string pos, string col, double rad)
        : Shape(pos, col), radius(rad) {}

    void draw() override {
        cout << "Drawing a Circle at " << position << " with radius " << radius << " and color " << color << endl;
    }

    double calculateArea() override {
        return 3.14159*radius*radius;
    }

    double calculatePerimeter() override {
        return 2*3.14159*radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(string pos, string col, double w, double h)
        : Shape(pos, col), width(w), height(h) {}

    void draw() override {
        cout << "Drawing a Rectangle at " << position << " with width " << width << " and height " << height << " and color " << color << endl;
    }

    double calculateArea() override {
        return width*height;
    }

    double calculatePerimeter() override {
        return 2*(width + height);
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(string pos, string col, double b, double h)
        : Shape(pos, col), base(b), height(h) {}

    void draw() override {
        cout << "Drawing a Triangle at " << position << " with base " << base << " and height " << height << " and color " << color << endl;
    }

    double calculateArea() override {
        return (base *height)/2;
    }

    double calculatePerimeter() override {
        double hypotenuse = base+height;
        return base +height+hypotenuse;
    }
};

class Polygon : public Shape {
private:
    int numSides;
    double sideLength;

public:
    Polygon(string pos, string col, int sides, double length)
        : Shape(pos, col), numSides(sides), sideLength(length) {}

    void draw() override {
        cout << "Drawing a Polygon at " << position << " with " << numSides << " sides of length " << sideLength << " and color " << color << endl;
    }

    double calculateArea() override {
        return numSides*(sideLength*sideLength)/4;
    }

    double calculatePerimeter() override {
        return numSides * sideLength;
    }
};

int main() {
    Circle c("Center (6,6)", "White", 8);
    Rectangle r("Top right (4,4)", "Red", 6, 4);
    Triangle t("Vertex (5,5)", "Brown", 7, 7);
    Polygon p("Origin (0,0)", "Green", 2, 2);
    Shape* shapes[] = { &c, &r, &t, &p };

    for (Shape* shape : shapes) {
        shape->draw();
        cout << "Area: " << shape->calculateArea() << endl;
        cout << "Perimeter: " << shape->calculatePerimeter() << endl;
        cout << "---------------------------------\n";
    }
return 0;
}