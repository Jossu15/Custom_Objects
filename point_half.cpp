//
// Created by Lenovo on 11/02/2024.
//
#include <iostream>

class Point{
    double x;
    double y;
public:
    Point(double X, double Y): x(X), y(Y){}
    Point(): x(0), y(1){}

    [[nodiscard]] double distance(Point p) const{
        double rest1 = std::pow(x - p.x,2);
        double rest2 = std::pow(y - p.y,2);
        double sum = rest1 + rest2;
        return std::sqrt(sum);
    }
};

int main(){
    Point po1{1,2}, po2{4,5};
    std::cout << po1.distance(po2) << '\n';
}