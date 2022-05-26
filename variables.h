#ifndef VARIABLES_H
#define VARIABLES_H
#include "Matrixclass.h"

#define PI 3.141592


void nodeprint(Matrix &mat);     // print calculation region
void periodic_double_ghost(Matrix &mat, int nghost);

struct variables
{
    int NX, NY, itr_max;
    int nghost;
    double x, y;
    double dx, dy, dt;
};

Matrix G(int &, int &, double &, int);
Matrix G_n1(int &, int &, double &, int);
Matrix G_nb(int &, int &, double &, int);
Matrix G_nc(int &, int &, double &, int);
Matrix G_new(int &, int &, double &, int);
Matrix u(int &, int &, double &, int);
Matrix v(int &, int &, double &, int);

#endif


