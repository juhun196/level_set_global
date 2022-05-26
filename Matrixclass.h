#ifndef MATRIXCLASS_H
#define MATRIXCLASS_H
using namespace std;

class Matrix
{
private:
    int _rows, _cols, _nghost;
    double **matrix;   // 2D Array

public:
    
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, double value);
    Matrix(int rows, int cols, double value, int nghost);
    ~Matrix();
    Matrix operator+(const Matrix &);
    Matrix operator+(const double &);
    Matrix operator-(const Matrix &);
    Matrix operator*(const Matrix &);
    Matrix operator*(const double &);
    Matrix operator=(const Matrix &);

    int getRows() {return _rows;}
    int getCols() {return _cols;}
    int getNghost() {return _nghost;}

    double **getMatrix() {return matrix;}
    
    void nodeprint(Matrix &mat);     // print calculation region
    void periodic_double_ghost(Matrix &mat, int nghost);

    friend istream& operator>>(istream&in, Matrix &a);
    friend ostream& operator<<(ostream& out, const Matrix& a);
};



#endif