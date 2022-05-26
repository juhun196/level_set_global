#include <iostream>
#include "variables.h"


void nodeprint(Matrix &mat)     // print calculation region
{
    cout << "Calculation Region" << endl;
    for(int i = mat.getNghost(); i < mat.getRows() - mat.getNghost(); i++)
    {
        for(int j = mat.getNghost(); j < mat.getCols() - mat.getNghost(); j++)
        {
            cout << mat.getMatrix()[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void periodic_double_ghost(Matrix &mat, int nghost)
{
    int start = nghost, end = mat.getRows() - nghost;

    for(int i = 0; i < nghost; i++)
    {
        for(int j = start; j < end; j++)
        {
            mat.getMatrix()[i][j] = mat.getMatrix()[end-nghost+i][j];
            mat.getMatrix()[end+i][j] = mat.getMatrix()[start+i][j];
        }
    }

    end = mat.getCols() - nghost;

    for(int i = start; i < end; i++)
    {
        for(int j = 0; j < nghost; j++)
        {
            mat.getMatrix()[i][j] = mat.getMatrix()[i][end-nghost+j];
            mat.getMatrix()[i][end+j] = mat.getMatrix()[i][start+j];
        }
    }
}

