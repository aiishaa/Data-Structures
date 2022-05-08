#include "MatrixCalculator.h"
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

template<class T>
void MatrixCalculator::Menu(matrix<T>& mat1){
    int option;
    T scalar;
    matrix<T> mat2, result;
    while(true){
        cout << "1- Add two matrices.\n" <<
        "2- Add a scalar to a matrix.\n" <<
        "3- Subtract two matrices.\n" <<
        "4- Subtract a scalar from a matrix.\n" <<
        "5- Multiply Two matrices.\n" <<
        "6- Multiply a matrix by a scalar.\n" <<
        "7- Transpose a matrix.\n" <<
        "8- Exit a program" << endl;

        cout << "Enter your option.\n";
        cin >> option;

        switch(option){
        case 1:
            {
                cout << "Enter the first matrix: \n";
                cin >> mat1;
                cout << "Your first matrix is: \n" << mat1;
                cout << "Enter the second matrix: \n";
                cin >> mat2;
                cout << "Your second matrix is: \n" << mat2;
                result = mat1 + mat2;
                cout << endl << "mat1 + mat2 = \n" << result << endl;
                break;
            }
        case 2:
            {
                cout << "Enter the matrix: \n";
                cin >> mat1;
                cout << "Your matrix is: \n" << mat1;
                cout << "Enter the scaler: \n";
                cin >> scalar;
                result = mat1 + scalar;
                cout << endl << "mat + "  << scalar  << " =" << endl << result << endl;
                break;
            }
        case 3:
            {
                cout << "Enter the first matrix: \n";
                cin >> mat1;
                cout << "Your first matrix is: \n" << mat1;
                cout << "Enter the second matrix: \n";
                cin >> mat2;
                cout << "Your second matrix is: \n" << mat2;
                result = mat1 - mat2;
                cout << endl << "mat1 - mat2 = \n" << result << endl;
                break;
            }
        case 4:
            {
                cout << "Enter the matrix: \n";
                cin >> mat1;
                cout << "Your matrix is: \n" << mat1;
                cout << "Enter the scaler: \n";
                cin >> scalar;
                result = mat1 - scalar;
                cout << endl << "mat - "  << scalar  << " =" << endl << result << endl;
                break;
            }
        case 5:
            {
                cout << "Enter the first matrix: \n";
                cin >> mat1;
                cout << "Your first matrix is: \n" << mat1;
                cout << "Enter the second matrix: \n";
                cin >> mat2;
                cout << "Your second matrix is: \n" << mat2;
                result = mat1 * mat2;
                cout << endl << "mat1 * mat2 = \n" << result << endl;
                break;
            }
        case 6:
            {
                cout << "Enter the matrix: \n";
                cin >> mat1;
                cout << "Your matrix is: \n" << mat1;
                cout << "Enter the scaler: \n";
                cin >> scalar;
                result = mat1 * scalar;
                cout << endl << "mat * scalar = \n" << result << endl;
                break;
            }
        case 7:
            {
                cout << "Enter the matrix: \n";
                cin >> mat1;
                cout << "Your matrix is: \n" << mat1;
                result = mat1.transpose(mat1);
                cout << "The transpose of your matrix is: \n" << result << endl;
                break;
            }
        case 8:
            exit(1);
        }
    }
}
