//g++ 6.3.0

#include <iostream>
#include <stdlib.h>
#include "Matrix.h"
using namespace std;

void print_mx(double **matrix, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int a_size = 4;
    double **a = new double *[a_size];
    for (int i = 0; i < a_size; i++)
    {
        a[i] = new double[a_size];
        for (int j = 0; j < a_size; j++)
        {
            a[i][j] = rand()%4 - rand()%3;
        }
    }

    Matrix math(a, a_size);
    cout << "(" << math.get_determinant() << ")" << endl;
    math.get_invert();

    return 0;
}
