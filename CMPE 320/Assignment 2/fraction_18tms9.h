//
// Created by travi on 2021-10-18.
//

#ifndef FRACTIONCLASS_FRACTION_18TMS9_H
#define FRACTIONCLASS_FRACTION_18TMS9_H
#include <iostream>
using namespace std;



class Fraction{

public:
    //fraction constructors for no argument, 1 argument and 2 argument
    Fraction();
    Fraction(int numerator);
    Fraction(int numerator, int denominator);

    //method to calculate the gcd of a fraction
    int GCD(int numerator, int denominator);

    //function to normalize the fraction
    void normalize();

    int numerator();
    int denominator();

    //overload negation operator
    Fraction operator-() const;
    //overload prefix increment operator
    Fraction& operator++();
    //overload postfix increment operator
    Fraction operator++(int);

    //Overload all 3 cases
    //overload addition operator
    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator+(const Fraction& f, int i);
    friend Fraction operator+(int i, const Fraction& f);

    //overload subtraction operator
    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
    friend Fraction operator-(const Fraction& f, int i);
    friend Fraction operator-(int i, const Fraction& f);

    //overload multiplication
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f, int i);
    friend Fraction operator*(int i, const Fraction& f);

    //overload division operator
    friend Fraction operator/(const Fraction& f1, const Fraction& f2);
    friend Fraction operator/(const Fraction& f, int i);
    friend Fraction operator/(int i, const Fraction& f);

    //Assignment operator overload 2 cases
    Fraction& operator+=(const Fraction& f);
    Fraction& operator+=(int i);

    //Comparison operators overload all 3 cases
    //overload less then
    friend bool operator<(const Fraction& f1, const Fraction& f2);
    friend bool operator<(const Fraction& f, int i);
    friend bool operator<(int i, const Fraction& f);

    //overload less than or equal
    friend bool operator<=(const Fraction& f1, const Fraction& f2);
    friend bool operator<=(const Fraction& f, int i);
    friend bool operator<=(int i, const Fraction& f);

    //overload greater than
    friend bool operator>(const Fraction& f1, const Fraction& f2);
    friend bool operator>(const Fraction& f, int i);
    friend bool operator>(int i, const Fraction& f);

    //overload greater than or equal
    friend bool operator>=(const Fraction& f1, const Fraction& f2);
    friend bool operator>=(const Fraction& f, int i);
    friend bool operator>=(int i, const Fraction& f);

    //overload equal too
    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator==(const Fraction& f, int i);
    friend bool operator==(int i, const Fraction& f);

    //overload not equal to
    friend bool operator!=(const Fraction& f1, const Fraction& f2);
    friend bool operator!=(const Fraction& f, int i);
    friend bool operator!=(int i, const Fraction& f);

    //overload I/O operators
    friend ostream &operator<<(ostream &os, const Fraction& f);
    friend istream &operator>>(istream &is, Fraction& f);

    //accessor functions for numerator and denominator
    void setNum(int a);
    void setDenom(int a);

private:
    int num;
    int denom;
};//end fraction class

//fraction exception class, used for throwing an error message for having an improper fraction (1/0)
class FractionException{
public:
    FractionException(const string& message);
    string& what();
private:
    string message;
};


#endif //FRACTIONCLASS_FRACTION_18TMS9_H
