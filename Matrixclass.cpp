#include <iostream>
#include "Matrixclass.h"

using namespace std;

istream& operator>>(istream&in, Matrix &a)
{
    cout << "Input Data in Matrix " << endl;
    for(int i = 0; i < a._rows; i++)
    {
        for(int j = 0; j < a._cols; j++)
        {
            in>>a.matrix[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const Matrix& a)
{
    for(int i = 0; i < a._rows; i++)
    {
        for(int j = 0; j < a._cols; j++)
        {
            out << a.matrix[i][j] << "\t";
        }
        out << endl;
    }

    return out;     // our program is complete now lets test
}

Matrix::Matrix(int rows, int cols)
{
    this->_rows = rows;
    this->_cols = cols;

    matrix = new double *[_rows];
    for(int i = 0; i < _rows; i++)       // Allocating Dynamic Memory
    {
        matrix[i] = new double[_cols];
    }
    for(int i = 0; i < _rows; i++)
    {
        for(int j = 0; j < _cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(int rows, int cols, double value)
{
    this->_rows = rows;
    this->_cols = cols;

    matrix = new double *[rows];
    for(int i = 0; i < rows; i++)       // Allocating Dynamic Memory
    {
        matrix[i] = new double[cols];
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            matrix[i][j] = value;
        }
    }
}

Matrix::Matrix(int rows, int cols, double value, int nghost)
{
    rows = rows + 2*nghost;
    cols = cols + 2*nghost;
    this->_rows = rows;
    this->_cols = cols;
    this->_nghost = nghost;

    matrix = new double *[rows];
    for(int i = 0; i < rows; i++)       // Allocating Dynamic Memory
    {
        matrix[i] = new double[cols];
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            matrix[i][j] = value;
        }
    }
}

Matrix::~Matrix()
    {
        if(_rows > 0)
        {
            // release the memory allocated for each row
            for(int i = 0; i < _rows; i++)
                {
                    delete[] matrix[i];
                }
        }
        if(_cols > 0)
        {
            delete[] matrix;
        }
    }

Matrix Matrix:: operator+(const Matrix &a)      // for (+) of two matrix
{
    Matrix result(a._rows, a._cols);

    for(int i = _nghost; i < _rows - _nghost; i++)
    {
        for(int j = _nghost; j < _cols- _nghost; j++)
        {
            result.matrix[i][j] = this->matrix[i][j] + a.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix:: operator+(const double &a)      // for (+) of two matrix
{
    Matrix result(_rows, _cols);

    for(int i = _nghost; i < _rows - _nghost; i++)
    {
        for(int j = _nghost; j < _cols - _nghost; j++)
        {
            result.matrix[i][j] = this->matrix[i][j] + a;
        }
    }
    return result;
}

Matrix Matrix:: operator-(const Matrix &a)      // for (-) of two matrix
{
    Matrix result(a._rows, a._cols);

    for(int i = _nghost; i < _rows - _nghost; i++)
    {
        for(int j = _nghost; j < _cols - _nghost; j++)
        {
            result.matrix[i][j] = a.matrix[i][j] - this->matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix:: operator*(const Matrix &a)
{
    Matrix result(a._rows, a._cols);
    for(int i = _nghost; i < a._rows - _nghost; i++)
    {
        for(int j = _nghost; j < a._cols - _nghost; j++)
        {
            result.matrix[i][j] = matrix[i][j] * a.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix:: operator*(const double &a)      // for (+) of two matrix
{
    Matrix result(_rows, _cols);

    for(int i = _nghost; i < _rows - _nghost; i++)
    {
        for(int j = _nghost; j < _cols - _nghost; j++)
        {
            result.matrix[i][j] = this->matrix[i][j] * a;
        }
    }
    return result;
}

Matrix Matrix::operator=(const Matrix &a)
{
    Matrix result(a._rows, a._cols);

    for(int i = 0; i < _rows; i++)
    {
        for(int j = 0; j < _cols; j++)
        {
            this->matrix[i][j] = a.matrix[i][j];
        }
    }
    return result;
}

