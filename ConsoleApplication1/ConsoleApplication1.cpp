#include <iostream>
#include <cmath> 
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

class Fraction {
private:
    int numerator_;
    int denominator_;

    void normalize() {
        if (denominator_ == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        int common = gcd(abs(numerator_), abs(denominator_));
        numerator_ /= common;
        denominator_ /= common;
        if (denominator_ < 0) {
            numerator_ *= -1;
            denominator_ *= -1;
        }
    }

public:
    Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
        normalize();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator_ * other.denominator_ + other.numerator_ * denominator_, denominator_ * other.denominator_);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator_ * other.denominator_ - other.numerator_ * denominator_, denominator_ * other.denominator_);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator_ == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
    }

    Fraction operator-() const {
        return Fraction(-numerator_, denominator_);
    }

    Fraction& operator++() {
        numerator_ += denominator_;
        normalize();
        return *this;
    }

    Fraction operator++(int) {
        Fraction temp = *this;
        numerator_ += denominator_;
        normalize();
        return temp;
    }

    Fraction& operator--() {
        numerator_ -= denominator_;
        normalize();
        return *this;
    }

    Fraction operator--(int) {
        Fraction temp = *this;
        numerator_ -= denominator_;
        normalize();
        return temp;
    }

    void print() const {
        std::cout << numerator_ << "/" << denominator_;
    }
};





int main() {

    setlocale(LC_ALL, "Russian");
    
    int num1_num, num1_den, num2_num, num2_den;

    std::cout << "Введите числитель дроби 1: ";
    std::cin >> num1_num;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> num1_den;
    std::cout << "Введите числитель дроби 2: ";
    std::cin >> num2_num;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> num2_den;

    Fraction f1(num1_num, num1_den);
    Fraction f2(num2_num, num2_den);

    f1.print(); std::cout << " + "; f2.print(); std::cout << " = "; (f1 + f2).print(); std::cout << std::endl;
    f1.print(); std::cout << " - "; f2.print(); std::cout << " = "; (f1 - f2).print(); std::cout << std::endl;
    f1.print(); std::cout << " * "; f2.print(); std::cout << " = "; (f1 * f2).print(); std::cout << std::endl;
    f1.print(); std::cout << " / "; f2.print(); std::cout << " = "; (f1 / f2).print(); std::cout << std::endl;

    ++f1;
    std::cout << "++"; f1.print(); std::cout << " * "; f2.print(); std::cout << " = "; (f1 * f2).print(); std::cout << std::endl;
    std::cout << "Значение дроби 1 = "; f1.print(); std::cout << std::endl;

    f1--;
    f1.print(); std::cout << "-- * "; f2.print(); std::cout << " = "; (f1-- * f2).print(); std::cout << std::endl;
    std::cout << "Значение дроби 1 = "; f1.print(); std::cout << std::endl;

    return 0;
}

