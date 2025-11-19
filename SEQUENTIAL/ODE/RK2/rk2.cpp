
/*
* --------------------------------------------------------------------

* Numerical ODE
*
* Solves the ODE y' = exp(-x^2) * sin(y^2)
* using:
*   - RK2 (Second-order Runge–Kutta)

* --------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <cmath>

/*
* --------------------------------------------------------------------
* Global configuration
* --------------------------------------------------------------------
*/

#define H 0.1
#define N 1000
#define Y0 2

inline double f(double x, double y) {
    return std::exp(-(x * x)) * std::sin(y * y);
}

double rk2() {

    double x = 0.0;
    double y = Y0;
    double k1 = 0.0, k2 = 0.0;

    for(int i = 0; i < N; i++) {

        k1 = f(x, y);
        k2 = f(x + H, y + H * k1);
        
        y += (H / 2.0) * (k1 + k2);
        x += H;
    }

    return y;
}

int main(void) {

    double result = rk2();  
    std::cout << result << std::endl;


    return 0;
}