//
// Created by konstantin on 25.10.17.
//

#ifndef DFP_WOLFE_H
#define DFP_WOLFE_H

#include "function.h"
#include "linear-algebra.h"

double epsss1 = 0.4, epsss2 = 0.6;
//double wolfe(const Function &f, const Point &x, const Point &d);


double wolfe(const Function &f, const Point &x, const Point &d) {
    double a1 = 0, a2 = 0, a = 1;

    while (true) {
        bool ul = f.f(x + a * d) <= f.f(x) + epsss1 * a * scalar_product(f.df(x), d);
        bool ur = scalar_product(f.df(x + a * d), d) >= epsss2 * scalar_product(f.df(x), d);

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


#endif //DFP_WOLFE_H
