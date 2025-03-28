#include<iostream>
#include <cstring>
#include <math.h>
using namespace std;
class Shape {
protected:
    char* name;
public:
    // Baiguulagch
    Shape(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    // Huulagch
    Shape(const Shape& sh) {
        name = new char[strlen(sh.name) + 1];
        strcpy(name, sh.name);
    }
    // Ustgagch
    ~Shape() {
        cout << "Ustagasan shape "<<endl;
        delete[] name;
    }
    const char* get_name() {
        return name;
    }
    void print() {
        cout << get_name() << endl;
    }
};

class Shape2D : public Shape {
public: 
    double center_x;
    double center_y;
public:
    // baiguulagch
    Shape2D(const char* name, double x, double y) 
        : Shape(name), center_x(x), center_y(y) {}

    // huulagch
    Shape2D(const Shape2D& shp) 
        : Shape(shp), center_x(shp.center_x), center_y(shp.center_y) {}
    // ustgagcj
    ~Shape2D() {
        cout << "Ustgasan Shape2D: " << name << endl;
    }
};

// Circle class
class Circle : public Shape2D {
private:
    double radius;
public:
    // baiguulagch
    Circle(const char* name, double center_x, double center_y, double radius)
        : Shape2D(name, center_x, center_y), radius(radius) {}
    // talbai oloh
    double area() {
        return M_PI * radius * radius;
    }
    // urt oloh
    double perimeter() {
        return 2 * M_PI * radius;
    }
    // hevleh
    void print() {
        cout << "Name: " << get_name() << ", Center: (" << center_x << ", " << center_y
             << "), Radius: " << radius << endl;
    }
    ~Circle() {
        cout << "Ustgasan Circle: " << name << endl;
    }
};


// Square class
class Square : public Shape2D {
private:
    double side_length;
    double coardinate[4][2]; // 4 oroin coardinate
public:
    // Baiguulagch
    Square(const char* name, double center_x, double center_y, double side_length)
        : Shape2D(name, center_x, center_y), side_length(side_length) {
        calculateVertices();
    }
    // Oroin coardinates
    void calculateVertices() {
        coardinate[0][0] = center_x;
        coardinate[0][1] = center_y;

        coardinate[1][0] = center_x + side_length;
        coardinate[1][1] = center_y;

        coardinate[2][0] = center_x + side_length;
        coardinate[2][1] = center_y - side_length;

        coardinate[3][0] = center_x;
        coardinate[3][1] = center_y - side_length;
    }
    double print_coardinate() {
        for(int i=0; i<4; i++) {
            for(int j=0; j<1; j++) {
                cout<< "    courdinate: "<< coardinate[i][j]<<" "<<coardinate[i][j+1];
            }
            cout << endl;
        }
    }
    // hevleh
    void print() {
        cout << "Name: " << get_name() << ", Center: (" << center_x << ", " << center_y
             << "), Taliin urt: " << side_length << endl;
    }
    // Talbai oloh
    double area() {
        return side_length * side_length;
    }
    // Perimeter oloh
    double perimeter() {
        return 4 * side_length;
    }
    ~Square() {
        cout << "Ustgasan Square: " << name << endl;
    }
};
// Triangle class
class Triangle : public Shape2D {
private:
    double side_length;
    double vertices[3][2]; // 3 oroin coardinates
public:
    // Baiguulagch
    Triangle(const char* name, double center_x, double center_y, double side_length)
        : Shape2D(name, center_x, center_y), side_length(side_length) {
        calculateVertices();
    }
    // Coordinates
    void calculateVertices() {
        double height = (sqrt(3) / 2) * side_length;

        vertices[0][0] = center_x;
        vertices[0][1] = center_y;

        vertices[1][0] = center_x - side_length / 2;
        vertices[1][1] = center_y - height;

        vertices[2][0] = center_x + side_length / 2;
        vertices[2][1] = center_y - height;
    }
    double print_coardinate() {
        for(int i=0; i<3; i++) {
            for(int j=0; j<1; j++) {
                cout<< "    courdinate: "<< vertices[i][j] << " "<<vertices[i][j+1];
            }
            cout << endl;
        }
    }
    // hevleh
    void print() {
        cout<<"Name: "<< get_name() << ", Center: (" << center_x << ", " << center_y
             << "), Taliin urt: " << side_length << endl;
    }
    // Talbai oloh function
    double area(){
        return (sqrt(3)/4 *side_length*side_length);
    }
    // Perimeter oloh 
    double perimeter() {
        return 3 * side_length;
    }
    ~Triangle() {
        cout << "Ustgasan Triangle: " << name << endl;
    }
};
main(){
    Shape sha1("Circle");
    sha1.print();
    Shape sha1_1 = sha1;
    sha1_1.print();
    Shape2D sha2("Square", 0, 0);
    sha2.print();
    Shape2D sha2_1 = sha2;
    sha2_1.print();

    Circle c1("circle", 0, 0, 5);
    cout << "Talbai:" << c1.area()<<endl;
    cout << "Urt: "<< c1.perimeter()<<endl;
    c1.print();

    Square s1("square", 0, 0, 10);
    cout << "Talbai:" << s1.area()<<endl;
    cout << "Perimeter: "<< s1.perimeter()<<endl;
    s1.print_coardinate();
    s1.print();

    Triangle t1("triangle", 0, 0, 7);
    cout << "Talbai:" << t1.area()<<endl;
    cout << "Perimetr: "<< t1.perimeter()<<endl;
    t1.print_coardinate();
    t1.print();

    return 0;
}