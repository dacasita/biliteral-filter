#define _USE_MATH_DEFINES
#include <cmath>
#include "../matplotlibcpp.h"
#include <vector>

namespace plt = matplotlibcpp;

int main() {

    std::vector<int> n;
    for (int i = 0; i <= 100; ++i) {
        n.push_back(i);
    }

    srand(time(NULL));
    double An = 0.01;

    std::vector<int> x;
    std::vector<double> y;
    for (int i : n) {
        double noise_0_to_1 = (double) rand() / (RAND_MAX);
        double noise = An * noise_0_to_1 - 0.5;
        if (0 <= i && i <= 50)  
        {
            x.push_back(1);
            y.push_back(noise + 1);
        } 
        else 
        {
            x.push_back(0);
            y.push_back(noise);
        }
    }

    plt::plot(n, x);
    plt::title("n & x");
    plt::show();
    
    plt::plot(n, y);
    plt::title("n & y");
    plt::show();

    std::vector<double> x_o(y.size());

    double k1 = 0.3;
    double k2 = 5;
    int L = 10;
    for(int n = 0; n < y.size(); n++)
    {
        double C = 0;
        for(int m = n - L; m <= n + L; m++)
        {
        double power_term = exp(-k1 * pow(n-m,2)) * exp(-k2*pow((y[n]-y[m]),2)) ;
        C += power_term;
        x_o[n] += y[m] * power_term;
        }
        C = 1 / C;
        x_o[n] *= C;
    }
    plt::plot(n, x_o);
    plt::title("n & x_o");
    plt::show();

    return 0;
}

