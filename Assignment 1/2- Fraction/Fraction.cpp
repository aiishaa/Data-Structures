#include <iostream>
#include <bits/stdc++.h>
#include "Fraction.h"
using namespace std;

Fraction Fraction::operator+(const Fraction& frac){
    Fraction sum;
    int denominator = this->bottom * frac.bottom;
    sum.top = (float(denominator / this->bottom) * this->top) + (float(denominator / frac.bottom) * frac.top);
    sum.bottom = denominator;
    reduce(sum);
    return sum;
}

Fraction Fraction::operator-(const Fraction& frac){
    Fraction subtract;
    int denominator = this->bottom * frac.bottom;
    subtract.top = (float(denominator / this->bottom) * this->top) - (float(denominator / frac.bottom) * frac.top);
    subtract.bottom = denominator;
    reduce(subtract);
    return subtract;
}

Fraction Fraction::operator*(const Fraction& frac){
    Fraction multiply;
    multiply.top = this->top * frac.top;
    multiply.bottom = this->bottom * frac.bottom;
    reduce(multiply);
    return multiply;
}

Fraction Fraction::operator/(const Fraction& frac){
    Fraction division;
    division.top = frac.bottom;
    division.bottom = frac.top;
    division = (*this) * division;
    reduce(division);
    return division;
}

bool Fraction::operator== (const Fraction& frac){
    Fraction subtract = *this - frac;
    return (subtract.top == 0) ? true : false;
}

bool Fraction::operator< (const Fraction& frac){
    Fraction subtract = *this - frac;
    return (subtract.top < 0) ? true : false;
}

bool Fraction::operator> (const Fraction& frac){
    Fraction subtract = *this - frac;
    return (subtract.top > 0) ? true : false;
}

bool Fraction::operator<= (const Fraction& frac){
    return(!(*this > frac));
}

bool Fraction::operator>= (const Fraction& frac){
    return(!(*this < frac));
}

void Fraction::reduce(Fraction& frac){
    int d;
    d = __gcd(frac.top, frac.bottom);

    frac.top = frac.top / d;
    frac.bottom = frac.bottom / d;
}

istream& operator >> (istream& in, Fraction& f){
    cout << "Enter the numerator.\n";
    in >> f.top;
    cout << "Enter the denominator.\n";
    in >> f.bottom;
    return in;
}

ostream& operator << (ostream& out, Fraction& frac){
    out << frac.top << "/" << frac.bottom;
    return out;
}
