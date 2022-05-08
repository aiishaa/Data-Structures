#include <iostream>
#include "FractionCalculator.h"
#include "Fraction.h"
using namespace std;

FractionCalculator::FractionCalculator(){

}
void FractionCalculator::calculator(){
    int option;
    Fraction f1;
    Fraction f2;

    cout << "Enter the first fraction.\n";
    cin >> f1;
    cout << "Enter the second fraction.\n";
    cin >> f2;

    while(true){

        cout <<
        "For adding, press 1.\n" <<
        "For subtracting, press 2.\n" <<
        "For multiplication, press 3.\n" <<
        "For dividing, press 4.\n" <<
        "For comparing, press 5.\n" <<
        "For fraction reduction, press 6.\n" <<
        "For exit, press 7.\n";

        cin >> option;
        cout << endl;
        switch(option){
        case 1:
            {
                Fraction f3 = f1 + f2;
                cout << "f1 + f2 = "<< f3 << endl << endl;
                break;
            }

        case 2:
            {
                Fraction f3 = f1 - f2;
                cout << "f1 - f2 = " << f3 << endl << endl;
                break;
            }

        case 3:
            {
                Fraction f3 = f2 * f1;
                cout << "f2 * f1 = "<< f3 << endl << endl;
                break;
            }

        case 4:
            {
                Fraction f3 = f1 / f2;
                cout << "f1 / f2 = " << f3 << endl << endl;
                break;
            }

        case 5:
            {
                cout << "Does f1 equal f2 ? " << (f1 == f2) << endl;
                cout << "Is f1 less than f2 ? " << (f1 < f2) << endl;
                cout << "Is f1 greater than f2 ? " << (f1 > f2) << endl;
                cout << "Is f1 less than or equal f2 ? " << (f1 <= f2) << endl;
                cout << "Is f1 greater than or equal f2 ? " << (f1 >= f2) << endl << endl;
                break;
            }

        case 6:
            {
                f1.reduce(f1);
                f2.reduce(f2);
                cout << "fraction 1 after reduction " << f1 << endl;
                cout << "fraction 2 after reduction " << f2 << endl << endl;
            }

        case 7:
            {
                exit(1);
            }
        }
    }
}
