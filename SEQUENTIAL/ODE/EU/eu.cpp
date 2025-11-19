
/*
* --------------------------------------------------------------------

* Numerical ODE
*
* Solves the ODE y' = exp(-x^2) * sin(y^2)
* using:
*   - Euler Method

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

double euler() {

    double x = 0.0;
    double y = Y0;
    double k1 = 0.0, k2 = 0.0;

    for(int i = 0; i < N; i++) {
        
        y += H * f(x, y);
        x += H;
    }

    return y;
}

int main(void) {

    double result = euler();  
    std::cout << result << std::endl;


    return 0;
}