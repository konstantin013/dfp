//
// Created by konstantin on 25.10.17.
//

#include "wolfe.h"


double wolfe(const Function &f, const Point &x, const Point &d) {
    double eps1 = 0.4, eps2 = 0.6;

    double a1 = 0, a2 = 0, a = 1;

    while (true) {
        bool ul = f.f(x + a * d) <= f.f(x) + eps1 * a * scalar_product(f.df(x), d);
        bool ur = scalar_product(f.df(x + a * d), d) >= eps2 * scalar_product(f.df(x), d);

        if (ul && ur) {
            return a;
        } else if (!ul) {
            a2 = a;
            a = (a1 + a2) / 2;
        } else {
            a1 = a;
            if (a1 == 0.0) {
                a = a2 * 2;
            }
        }
    }

}
