#include <iostream>
#include <sstream>
#include <vector>
#include  <string>
#include "fraction.h"

using namespace std;

Fraction::Fraction(void):num(0), denom(1){}

//fraction with one arg
Fraction::Fraction(const int numerator):num(numerator), denom(1){}

//fraction with 2 arg
Fraction::Fraction(const int num, const int denom):num(num), denom(denom){
    //check for invalid denominator
    if (denom ==0){
        throw FractionException("Denominator cannot be zero.");
    }
    //reduce a proper fraction
    normalize();
}//end fraction with 2 arg constructor

int Fraction::numerator() {
    return num;
}

int Fraction::denominator() {
    return denom;
}

void Fraction::normalize() {
    //find the gcd
    int div= GCD(this->num, this->denom);

    //divide by found gcd
    this->num= this->num/div;
    this->denom= this->denom/div;

    //if both numerator and denominator are neg, set both to positive
    if(this->num<0 && this->denom<0){
       //set both to the absolute values
        this->num=abs(this->num);
        this->denom=abs(this->denom);
    }

    if(this->num>0 && this->denom<0){
        //set both to the absolute values
        this->num= -(this->num);
        this->denom=abs(this->denom);
    }
}//end normalize

//function for finding the greatest common divisor
int Fraction::GCD(int a, int b) {
    // get the absolutes of the numerator and denominator
    int absA=abs(a);
    int absB=abs(b);
    //if the numerator is greater than or equal and if the denominator is a multiple of the numerator
    if(absB<=absA && absA%absB==0){
        return absB;
    }else if(absA<absB){    //if the numerator is less than the denominator, recursivly call it inverted
        GCD(b,a);
    }else{                  //recursivly call GCD with the denominator and the value of a mod b
        GCD(b,a%b);
    }
}//end GCD

// addition operator for 2 fractions, and 1 fraction 1 int in opposite orders
Fraction operator+(const Fraction& frac1, const Fraction& frac2){
    Fraction frac;
    frac.num=(frac1.num * frac2.denom)+(frac1.denom * frac2.num);
    frac.denom=frac1.denom * frac2.denom;
    frac.normalize();
    return frac;
}
Fraction operator+(const Fraction& f, int i){
    Fraction frac;
    frac.num = (f.num +i*f.denom);
    frac.denom= f.denom;
    frac.normalize();
    return frac;
}
Fraction operator+(int i, const Fraction& f){
    Fraction frac;
    frac.num = (f.num +i*f.denom);
    frac.denom= f.denom;
    frac.normalize();
    return frac;
}
// subtraction operator for 2 fractions, and 1 fraction 1 int in opposite orders
Fraction operator-(const Fraction& frac1, const Fraction& frac2){
    Fraction frac;
    frac.num=(frac1.num * frac2.denom)-(frac1.denom * frac2.num);
    frac.denom=frac1.denom * frac2.denom;
    int div= frac.GCD(frac.num, frac.denom);
    frac.num=frac.num/div;
    frac.denom=frac.denom/div;
    frac.normalize();
    return frac;
}
Fraction operator-(const Fraction& f, int i){
    Fraction frac;
    frac.num = (f.num -i*f.denom);
    frac.denom= f.denom;
    frac.normalize();
    return frac;
}
Fraction operator-(int i, const Fraction& f){
    Fraction frac;
    frac.num = (i*f.denom-f.num);
    frac.denom= f.denom;
    frac.normalize();
    return frac;
}

// multiplication operator for 2 fractions, and 1 fraction 1 int in opposite orders
Fraction operator*(const Fraction& f1, const Fraction& f2){
    Fraction frac;
    frac.num=f1.num * f2.num;
    frac.denom=f1.denom * f2.denom;
    frac.normalize();
    return frac;
}
Fraction operator*(const Fraction& f, int i){
    Fraction frac;
    frac.num=f.num *i;
    frac.denom=f.denom;
    frac.normalize();
    return frac;
}
Fraction operator*(int i, const Fraction& f){
    Fraction frac;
    frac.num=f.num *i;
    frac.denom=f.denom;
    frac.normalize();
    return frac;
}

// division operator for 2 fractions, and 1 fraction 1 int in opposite orders
Fraction operator/(const Fraction& f1, const Fraction& f2){
    Fraction frac;
    frac.num=f1.num * f2.denom;
    frac.denom=f1.denom * f2.num;
    frac.normalize();
    return frac;
}
Fraction operator/(const Fraction& f, int i){
    Fraction frac;
    frac.num=f.num;
    frac.denom=f.denom*i;
    frac.normalize();
    return frac;
}
Fraction operator/(int i, const Fraction& f){
    Fraction frac;
    frac.num=f.num;
    frac.denom=f.denom*i;
    frac.normalize();
    return frac;
}

//output stream operator
ostream &operator<<(ostream &os, const Fraction& f){
    //output numerator and denominator separated by a /
    os<<f.num<< '/' <<f.denom;
    return os;
}//end ostream

//accessor functions for numerator and denominator
void Fraction::setDenom(int a){
    denom=a;
    return;
}
void Fraction::setNum(int a){
    num= a;
    return;
}

//input stream operator
istream& operator >> (istream& is, Fraction& f){
    //initialize the string, input, and set that to the input from the user
    string input;
    is >> input;
    //initialize string stream to the input
    stringstream ss(input);
    //initialize the string for the position in the vector and initialize the vector
    string number;
    vector<string> bin;

    //push the first number before the / into bin, then loop again to push in the denominator
    while(getline(ss, number, '/')) {
        bin.push_back(number);
    }
    //if there is only one number in the bin, ie. there is just an int, make the fraction the int over 1
    if (bin.size()<2){
        f.setNum(stoi(bin[0]));
        f.setDenom(1);
    }else if (stoi(bin[1])==0){     //check if the number in the first position is a 0, and if yes throw error
        throw FractionException("Error: denominator cannot be 0");
    }else{                          //if you have inputed a proper fraction, set the numerator and denominator
        f.setNum(stoi(bin[0]));
        f.setDenom(stoi(bin[1]));
    }
    return is;
}

//fraction exception constructor
FractionException::FractionException(const string& message): message(message){}

//method for fraction exception
string& FractionException::what(){
    return message;
}
