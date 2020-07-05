#include <iostream>
#include "Matrix.h"

using namespace std;

void print_matrix(double **matrix, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

Matrix::Matrix(double **array, int array_size)
{
    data = array;
    size = array_size;
}

int Matrix::get_determinant()
{
    return determinant(data, size);
}

void Matrix::isolate(double **matrix, double **new_matrix, int i, int j, int size)
{
    int ki, kj, di, dj;
    for (ki = 0; ki < size; ki++)
    {
        if (ki != i)
        {
            for (kj = 0; kj < size; kj++)
            {
                if (kj != j)
                {
                    if (ki > i)
                    {
                        di = 1;
                    }
                    else
                    {
                        di = 0;
                    }

                    if (kj > j)
                    {
                        dj = 1;
                    }
                    else
                    {
                        dj = 0;
                    }

                    new_matrix[ki - di][kj - dj] = matrix[ki][kj];
                }
            }
        }
    }
}

double **Matrix::transponate(double **matrix, int size)
{
    double **new_matrix;
    new_matrix = new double *[size];
    for (int l = 0; l < size; l++)
    {
        new_matrix[l] = new double[size];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            new_matrix[i][j] = matrix[j][i];
        }
    }

    return new_matrix;
}

double **Matrix::multiply(double **matrix, int size, double num)
{
    double **new_matrix;
    new_matrix = new double *[size];
    for (int l = 0; l < size; l++)
    {
        new_matrix[l] = new double[size];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            new_matrix[i][j] = matrix[i][j] * num;
        }
    }

    return new_matrix;
}

int Matrix::determinant(double **matrix, int size)
{
    int d = 0, k = 1;

    double **new_matrix;
    new_matrix = new double *[size];
    for (int l = 0; l < size; l++)
    {
        new_matrix[l] = new double[size];
    }

    if (size < 1)
    {
        cerr << "Определитель вычислить невозможно!";
    }
    if (size == 1)
    {
        d = matrix[0][0];
        return (d);
    }
    if (size == 2)
    {
        d = matrix[0][0] * matrix[1][1] - (matrix[1][0] * matrix[0][1]);
        return (d);
    }
    if (size > 2)
    {
        for (int i = 0; i < size; i++)
        {
            isolate(matrix, new_matrix, i, 0, size);
            d = d + k * matrix[i][0] * determinant(new_matrix, size - 1);

            k = -k;
        }
    }

    delete[] new_matrix;
    return (d);
}

Matrix Matrix::get_invert()
{
    double determ = (1 / (double)determinant(data, size));

    double **temp;
    temp = new double *[size];
    for (int l = 0; l < size; l++)
    {
        temp[l] = new double[size];
    }

    minor(data, temp, size);
    double** result = multiply(temp, size, determ);

    print_matrix(result, size);

    return Matrix(result, size);
}

void Matrix::minor(double **matrix, double **minor_matrix, int size)
{
    int k = 1;

    matrix = transponate(matrix, size);

    double **new_matrix;
    new_matrix = new double *[size];
    for (int l = 0; l < size; l++)
    {
        new_matrix[l] = new double[size];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            isolate(matrix, new_matrix, i, j, size);
            int determ = determinant(new_matrix, size - 1);
            minor_matrix[i][j] = k * determ;

            k = -k;
        }

        k = -k;
    }

    delete[] new_matrix;
}