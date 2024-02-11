//
// Created by Lenovo on 10/02/2024.
//
#include <iostream>
#include <cstdlib>

class SimpleRational{
    int numerator;
    int denominator;

    static int iterative_gcd(int num1, int num2){
        int min = (num1 < num2) ? num1 : num2;
        int largestFactor = 1;
        for (int i = 1; i <= min; i++)
            if (num1% i == 0 && num2 % i == 0)
                largestFactor = i;
        return largestFactor;
    }

public:
    SimpleRational(int n, int d): numerator(n), denominator(d){
        if (d == 0){
            std::cout << "Zero denominator error\n";
            exit(1);
        }
    }

    SimpleRational(): numerator(0), denominator(1){}

    [[nodiscard]] int get_numerator() const{
        return numerator;
    }

    [[nodiscard]] int get_denominator() const{
        return denominator;
    }

    [[nodiscard]] SimpleRational reduce() const {
        int factor = iterative_gcd(numerator, denominator);
        return {get_numerator() / factor, get_denominator() / factor};
    }

    static void print_fraction(SimpleRational p){
        if (p.reduce().denominator == 1)
            std::cout << "The result: " << p.reduce().numerator << '\n';
        else
            std::cout << "The result: " << p.reduce().numerator << "/" << p.reduce().denominator;
    }
};

int main(){
   SimpleRational frac{12,6};
   SimpleRational::print_fraction(frac);
}
