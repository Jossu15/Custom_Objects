//
// Created by Lenovo on 11/02/2024.
//
#include <iostream>
#include <vector>

class IntPoint{
public:
    int x;
    int y;

    IntPoint(int x , int y): x(y), y(y) {}
};

class Rectangle{
    IntPoint corner; // Location of the rectangle's lower-left corner
    int width;       // The rectangle's width
    int height;      // The rectangle's height
public:
    Rectangle(IntPoint pt, int w, int h):
            corner((pt.x < -100) ? -100 : (pt.x > 100 ? 100 : pt.x),
                   (pt.y < -100) ? -100 : (pt.y > 100 ? 100 : pt.y)),
                   width((w < 0) ? 0 : w), height((h < 0) ? 0 : h){}

    [[nodiscard]] int get_perimeter() const{
        return 2 * width + 2 * height;
    }

    [[nodiscard]] int get_area() const{
        return width * height;
    }

    [[nodiscard]] int get_width() const{
        return width;
    }

    [[nodiscard]] int get_height() const{
        return height;
    }

    // Returns true if rectangle r overlaps this
    // rectangle object.
    bool intersect(Rectangle r){
        std::vector<int> Point1 = {corner.x, corner.y,corner.x + r.width, corner.y + r.height};
        std::vector<int> Point2 = {corner.x, corner.y,corner.x + r.width, corner.y + r.height};

        if ((Point1[0] < Point2[2]) &&
            (Point1[1] < Point2[3]) &&
            (Point2[0] < Point1[2]) &&
            (Point2[1] < Point1[3])){
            return true;
        }
        return false;
    }

    // Returns the length of a diagonal rounded to the nearest
    // integer.
    [[nodiscard]] int diagonal() const{
        int a = width * width,
            b = height * height;
        return static_cast<int>(round(std::sqrt(a + b)));
    }

    // Returns the geometric center of the rectangle with
    // the (x,y) coordinates rounded to the nearest integer
    [[nodiscard]] IntPoint center() const{
        double Xcenter = round((corner.x + width) / 2);
        double Ycenter = round((corner.y + height) / 2);
        return {static_cast<int>(Xcenter), static_cast<int>(Ycenter)};

    }

    bool is_inside(IntPoint pt){
        // Details omitted
    }

};


int main(){
    Rectangle rect1(IntPoint(2,3), 5,7),
              rect2(IntPoint(2,3), 1,3),
              rect3(IntPoint(2,3), 15,3),
              rect4(IntPoint(2,3), 5,3);

    std::cout << rect1.intersect(rect2) << '\n';
    std::cout << rect1.diagonal() << '\n';


}
