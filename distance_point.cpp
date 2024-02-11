//
// Created by Lenovo on 10/02/2024.
//
#include <iostream>

class Point{
    double x;
    double y;
public:
    Point(double X, double Y): x(X), y(Y){}
    Point(): x(0), y(1){}

    static double distance(Point p1, Point p2){
        double rest1 = std::pow(p2.x - p1.x,2);
        double rest2 = std::pow(p2.y - p1.y,2);
        double sum = rest1 + rest2;
        return std::sqrt(sum);
    }
};

int main(){
    Point po1{1,2}, po2{4,5};
    std::cout << Point::distance(po1, po2);
}