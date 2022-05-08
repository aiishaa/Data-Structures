#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED
#include <iostream>

using namespace std;
class Fraction{
private:
    int top;
    int bottom;
public:
    Fraction(){}
    Fraction(int top, int bottom){
        this->top = top;
        this->bottom = bottom;
    }
    Fraction operator+ (const Fraction& frac);
    Fraction operator- (const Fraction& frac);
    Fraction operator* (const Fraction& frac);
    Fraction operator/ (const Fraction& frac);
    bool operator== (const Fraction& frac);
    bool operator< (const Fraction& frac);
    bool operator> (const Fraction& frac);
    bool operator<= (const Fraction& frac);
    bool operator>= (const Fraction& frac);
    void reduce(Fraction& frac);
    friend istream & operator >> (istream &in,  Fraction &frac);
    friend ostream& operator<< (ostream& out, Fraction& frac);
};

#endif // FRACTION_H_INCLUDED
