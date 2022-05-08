#include "Matrix.h"

template <class T>
matrix<T>::matrix() {}

template <class T>
matrix<T>::matrix(int row, int col, int num[]) {
  this->row = row;
  this->mat.col = col;
  this->data = new T [row * col];
  for (int i = 0; i < row * col; i++){
    this->data[i] = num[i];
  }
}

template <class T>
matrix<T>::matrix(const matrix &mat){
    row = mat.row;
    col = mat.col;
    data = new T [row * col];
    for (int i = 0; i < mat.row * mat.col; i++){
        data [i] = mat.data[i];
    }
}

template <class T>
void matrix<T>::createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new T [row * col];
  for (int i = 0; i < row * col; i++){
    mat.data [i] = num [i];
    //cout << mat.data[i] << endl;
  }
}

template <class T>
matrix<T> matrix<T>::operator+( matrix<T> &mat) // Add if same dimensions
{
    assert((mat.row == this->row) && (mat.col == this->col));        //to sure if rows and cols are equal
    matrix<T> sum;
    sum.row = mat.row;
    sum.col = mat.col;
    sum.data = new T[mat.row * mat.col];
    for(int i=0; i < mat.row * mat.col; i++){
        sum.data[i] = mat.data[i] + this->data[i];
    }
    return sum;
}

template <class T>
matrix<T> matrix<T>::operator- (matrix &mat) // Sub if same dimensions
{
    assert((this->row == mat.row) && (this->col == mat.col));        //to make sure if rows and cols are equal
    matrix<T> sub;
    sub.row = mat.row;
    sub.col = mat.col;
    sub.data = new T[mat.row * mat.col];
    for(int i = 0; i < mat.row * mat.col; i++){
        sub.data[i] = this->data[i] - mat.data[i];
    }
    return sub;
}

template <class T>
matrix<T> matrix<T>::operator* (matrix &mat) // Multi if col1 == row2
{
    assert((this->col == mat.row));        //to sure if rows and cols are equal
    matrix<T> mul;
    mul.row = this->row;
    mul.col = mat.col;
    mul.data = new T[this->row * mat.col];
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < mat.col; j++) {
            int sum = 0;
            for (int k = 0; k < this->col; k++)
                sum = sum + this->data[i * this->col + k] * mat.data[k * mat.col + j];
            mul.data[i * mat.col + j] = sum;
        }
    }
    return mul;
}

template <class T>
matrix<T> matrix<T>::operator+ (int scalar)  // Add a scalar
{
    matrix<T> sum;
    sum.row = this->row;
    sum.col = this->col;
    sum.data = new T[this->row * this->col];
    for(int i=0; i < this->row * this->col; i++){
        sum.data[i] = this->data[i] + scalar;
    }
    return sum;
}

template <class T>
matrix<T> matrix<T>::operator- (int scalar)  // Subtract a scalar
{
    matrix<T> sub;
    sub.row = this->row;
    sub.col = this->col;
    sub.data = new T[this->row * this->col];
    for(int i=0; i < this->row * this->col; i++){
        sub.data[i] = this->data[i] - scalar;
    }
    return sub;
}

template <class T>
matrix<T> matrix<T>::operator* (int scalar)  // Multiple by scalar
{
    matrix<T> new_mat;
    new_mat.row = this->row;
    new_mat.col = this->col;
    new_mat.data = new T[this->row * this->col];
    for(int i = 0; i < this->row * this->col; i++){
        new_mat.data[i] = this->data[i] * scalar;
    }
    return new_mat;
}

// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;

template <class T2>
istream& operator>> (istream& in, matrix<T2> &mat)
{
    // Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
    // and return istream to allow cascading input
    cout << "Enter the number of rows: " << endl;
    in >> mat.row;
    cout << "Enter the number of columns: " << endl;
    in >> mat.col;
    cout << "Enter the matrix elements: " << endl;
    mat.data = new T2[mat.row * mat.col];
    for(int i = 0; i < mat.row * mat.col; i++){
        in >> mat.data[i];
    }
    return in;
}

template <class T2>
ostream& operator<< (ostream& out, matrix<T2> &mat)
{
    // Print matrix  as follows (2 x 3)			4	 6 	  8
    // and return ostream to cascade printing	9	12  	123
    for(int i=0; i < mat.row; i++){
        for(int j=0 ; j < mat.col ;j++){
            out << mat.data[i*mat.col + j];
            out << " ";
        }
        out << "\n";
    }
    return out;
}

template<class T>
matrix<T> matrix<T>::transpose(matrix<T>& mat)    // Return new matrix with the transpose
{
    matrix new_mat;
    new_mat.row = mat.col;
    new_mat.col = mat.row;
    new_mat.data = new T[mat.col * mat.row];
    for(int i=0; i < mat.row; i++){
        for(int j=0; j < mat.col; j++){
            new_mat.data[j * mat.row + i] = mat.data[i * mat.col + j];
        }
    }
    return new_mat;
}

template<class T>
matrix<T>::~matrix()
{
    //delete[] data;
}

