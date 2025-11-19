/*
* --------------------------------------------------------------------

* Numerical ODE
*
* Solves the ODE y' = exp(-x^2) * sin(y^2)
* using:
*   - RK4 (Fourth-order Runge–Kutta)

* --------------------------------------------------------------------
*/


#include <iostream>
#include <iomanip>
#include <cmath>

#define H 0.1
#define N 1000
#define Y0 2

inline double f(double x, double y) {
    return std::exp(-(x * x)) * std::sin(y * y);
}

double rk4() {

    double x  = 0.0;
    double y  = Y0;
    double k1 = 0.0, k2 = 0.0, k3 = 0.0, k4 = 0.0;

    for(int i = 0; i < N; i++) {

        k1 = f(x, y);
        k2 = f(x + H/2.0, y + H * k1 / 2.0);
        k3 = f(x + H/2.0, y + H * k2 / 2.0);
        k4 = f(x + H,     y + H * k3);

        y += (H / 6.0) * (k1 + 2*k2 + 2*k3 + k4);
        x += H;
    }
    return y;
}

int main(void) {







return 0;
}