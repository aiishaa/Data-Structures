#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

// A structure to store a matrix
template <class T>
class matrix
{
private:
  T* data;       // Pointer to 1-D array that will simulate matrix
  int row, col;
public:
    matrix();
    matrix(int row, int col, int num[]);
    matrix(const matrix &mat);
    void createMatrix (int row, int col, int num[], matrix& mat);
    matrix<T> operator+  (matrix<T> &mat);
    matrix<T> operator-  (matrix<T> &mat);
    matrix<T> operator*  (matrix<T> &mat);
    matrix<T> operator+  (int scalar);
    matrix<T> operator*  (int scalar);
    matrix<T> operator-  (int scalar);
    template <class T2>
    friend istream& operator>> (istream& in, matrix<T2> &mat);
    template <class T2>
    friend ostream& operator<< (ostream& out, matrix<T2> &mat);
    matrix<T> transpose(matrix<T>& mat);
    ~matrix();
};

#endif // MATRIX_H_INCLUDED
