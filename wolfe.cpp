//
// Created by konstantin on 25.10.17.
//

#include "wolfe.h"



double ::wolfe::eps1, ::wolfe::eps2;
double ::wolfe::a_ub = 10000;

bool
::wolfe::ur(const Function &f, const Point &x, const Point &d, double a) {
    return f.f(x + a * d) <= f.f(x) + eps1 * a * scalar_product(f.df(x), d);
}

bool
::wolfe::ul(const Function &f, const Point &x, const Point &d, double a) {
    return scalar_product(f.df(x + a * d), d) >= eps2 * scalar_product(f.df(x), d);
}

double ::wolfe::wolfe(const Function &f, const Point &x, const Point &d) {

    double a2 = 1;

    while (!ul(f, x, d, a2) && a2 < a_ub) {
        a2 *= 2;
    }
    if (a2 >= a_ub) {
        return -1;
    }

    if (ur(f, x, d, a2)) {
        return a2;
    }

    double a1 = 0;
    while (true) {
        double a = (a1 + a2) / 2;
        if (ul(f, x, d, a)) {
            if (ur(f, x, d, a)) {
                return a;
            } else {
                a2 = a;
            }
        } else {
            a1 = a;
        }
    }
}


