//
// Created by Lenovo on 10/02/2024.
//
#include <iostream>
#include <cstdlib>

class SimpleRational{
    int numerator;
    int denominator;

public:
    SimpleRational(int n, int d): numerator(n), denominator(d){
        if (d == 0){
            std::cout << "Zero denominator error\n";
            exit(1);
        }
    }

    void set_numerator(int n){
        numerator = n;
    }

    void set_denominator(int d){
        if (d != 0)
            denominator = d;
        else
        {
            std::cout << "Zero denominator error\n";
            exit(1);
        }
    }

    [[nodiscard]] int get_numerator() const{
        return numerator;
    }

    [[nodiscard]] int get_denominator() const{
        return denominator;
    }
};

SimpleRational add(SimpleRational r1, SimpleRational r2){

    if (r1.get_denominator() == r2.get_denominator())
        return {r1.get_numerator() + r2.get_numerator(), r1.get_denominator()};
    else
        return {r1.get_numerator() * r2.get_denominator() + r2.get_numerator() * r1.get_denominator(),
            r1.get_denominator() * r2.get_denominator()};
}

void print_fraction(SimpleRational R){
    std::cout << R.get_numerator() << "/" << R.get_denominator();
}

int main(){
    SimpleRational f1{1,7}, f2{4,2};
    auto sum = add(f1, f2);
    print_fraction(sum);
}