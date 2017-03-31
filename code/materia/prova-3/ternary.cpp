// EPS should be set accordingly
// MAXIT should be set to the maximum number of iterations
// f(double) is the function to do the search

#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e14;
const int MAXIT = 200;

double f(double x) {
    // function should be calculated here
}

// l is the left border of the interval
// r is the right border of the interval
// returns the x that is the maximum/minimum of f(x)
double ternary(double l, double r) {
    int i = 0;
    double m1, m2;
    while (fabs(r-l) > EPS && i < MAXIT) {
        m1 = l+(r-l)/3.0;
        m2 = r-(r-l)/3.0;
        // change < for min/max
        if (f(m1) < f(m2)) l = m1;
        else r = m2;
        i++;
    }
    return (l+r)/2.0;
}

int main() {

    return 0;
}
