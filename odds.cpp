#include "odds.h"

double** CalculateSplineOdds(double* c, double* y, double h)
{
    int N = sizeof(c);
    double** coeffs = new double* [N];      // coeffs = a b c d
    for (int i = 0; i < 4; ++i) {
        coeffs[i] = new double[N];
    }

    for (int i = 0; i < N; ++i){
        coeffs[2][i] = c[i];                    //c[i]
    }

    coeffs[3][N - 1] = (- c[N - 1])/(3*h);        //d[N - 1]
    for (int i = 0; i < N - 1; ++i) {
        coeffs[3][i] = (c[i + 1] - c[i])/(3*h);      //d[i]
    }

    coeffs[0][0] = y[0] - coeffs[1][0]*h - c[0]*h*h - coeffs[3][0]*h*h*h;   //a[0]
    for (int i = 1; i < N; ++i) {
        coeffs[0][i] = y[i - 1];                     //a[i]
    }

    for (int i = 1; i < N - 1; ++i) {
        coeffs[1][i] = (y[i] - y[i - 1])/h - h*(c[i + 1] + 2*c[i])/3;               //b[i]
    }
    coeffs[1][N - 1] = (y[N - 1] - y[N - 2])/h - 2*(h*c[N - 1])/3;                 //b[N - 1]
    coeffs[1][0] = (y[0] - coeffs[0][0] - c[0]*h*h - coeffs[3][0]*h*h*h)/h;       //b[0]

    return coeffs;
}
