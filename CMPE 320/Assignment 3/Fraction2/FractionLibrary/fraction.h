#ifndef FRACTION_H
#define FRACTION_H

#include "Fraction_global.h"
#include <iostream>

using namespace std;

class FRACTION_EXPORT Fraction
{
public:
    Fraction();
    Fraction(int numerator);
    Fraction(int numerator, int denominator);

    //method to calculate the gcd of a fraction
     int GCD(int numerator, int denominator);

     //function to normalize the fraction
     void normalize();

     int numerator();
     int denominator();

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

#endif // FRACTION_H
