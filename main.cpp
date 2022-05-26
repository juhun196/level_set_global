#include <iostream>
#include <fstream>
#include "variables.h"

//#define PI 3.141592
#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b



int main()
{
    variables var{4, 4, 200, 3, 0, 0, 0.02, 0.02, 0.005};

    int NX = var.NX, NY = var.NY, itr_max = var.itr_max;
    int nghost = var.nghost;
    double x = var.x, y = var.y;
    double dx = var.dx, dy = var.dy, dt = var.dt;

    Matrix G(NX, NY, 0, nghost);
    Matrix G_n1(NX, NY, 0, nghost);
    Matrix G_nb(NX, NY, 0, nghost);
    Matrix G_nc(NX, NY, 0, nghost);
    Matrix G_new(NX, NY, 0, nghost);
    Matrix u(NX, NY, 0, nghost);
    Matrix v(NX, NY, 0, nghost);


    // NX = 4, NY = 4, nghost = 3
    
    int west_idx = nghost, east_idx = NX+nghost, north_idx = nghost, south_idx = NY+nghost;

    Matrix a(NX, NY, 0, nghost);
    
    for(int i = west_idx; i < east_idx; i++)
    {
        for(int j = north_idx; j < south_idx; j++)
        {
            a.getMatrix()[i][j] = j-(nghost-1) + NX*(i-nghost);
        }
    }

    // cout << "Calculation Region" << endl;
    // nodeprint(a);
    // cout << "All Region" << endl;
    // cout << a << endl;

    // periodic_double_ghost(a, nghost);


    // cout << "Calculation Region" << endl;
    // nodeprint(a);
    // cout << "All Region" << endl;
    // cout << a << endl;

    periodic_double_ghost(G, nghost);
    periodic_double_ghost(u, nghost);
    periodic_double_ghost(v, nghost);

    // Read Grid
    ifstream inFile;
    inFile.open("zaledisk_init.txt");

    

    for(int i = west_idx; i < east_idx; i++)
    {
        for(int j = north_idx; j < south_idx; j++)
        {
            x = (i - west_idx)*dx;
            y = (j - north_idx)*dy;

            inFile >> G.getMatrix()[i][j];
            //cout << G.getMatrix()[i][j] << " ";

            u.getMatrix()[i][j] = 1*(1 - y);
            v.getMatrix()[i][j] = 1*(x - 1);
        }
        //cout << endl;

    }

    nodeprint(u);
    cout << u << endl;

    nodeprint(v);
    cout << v << endl;

    inFile.close();

    return 0;
}



// void CIR_Glinear(Matrix &mat_u, Matrix &mat_v, Matrix &mat_G, Matrix &mat_new_G, double dt)
// {

// }



