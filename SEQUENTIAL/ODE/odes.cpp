#include <iostream>
#include <iomanip>
#include <cmath>

#define H 0.1
#define N 10000000

inline double f(double x, double y) {
    return std::exp(-(x * x)) * std::sin(y * y);
}

void rk4() {

    double x  = 0.0;
    double y  = 2.0;
    double k1 = 0.0, k2 = 0.0, k3 = 0.0, k4 = 0.0;

    for(int i = 0; i < N; i++) {

        k1 = f(x, y);
        k2 = f(x + H/2.0, y + H * k1 / 2.0);
        k3 = f(x + H/2.0, y + H * k2 / 2.0);
        k4 = f(x + H,     y + H * k3);

        y += (H / 6.0) * (k1 + 2*k2 + 2*k3 + k4);
        x += H;
    }

    std::cout << "RK4 result: " << y << std::endl;
}

void rk2() {

    double x = 0.0;
    double y = 2.0;
    double k1 = 0.0, k2 = 0.0;

    for(int i = 0; i < N; i++) {

        k1 = f(x, y);
        k2 = f(x + H, y + H * k1);
      
        y += (H / 2.0) * (k1 + k2);
        x += H;
    }

    std::cout << "RK2 result: " << y << std::endl;
}

int main() {

    std::cout << std::fixed << std::setprecision(50);

    rk4();
    rk2();

    return 0;
}
