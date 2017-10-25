//
// Created by konstantin on 20.10.17.
//

#include "dfp.h"

Point dfp(const Function &f, Point x0, One_dim_search one_dim_search) {
    int n = x0.size();
    Matrix Q0(n, n);

    std::cout << x0 << std::endl;

    while (norm(f.df(x0)) >= 1e-10) {
        Point d = -Q0 * f.df(x0);
        double alpha = one_dim_search(f, x0, d);
        Point x = x0 + alpha * d;


        Point r = x - x0;
        Point s = f.df(x) - f.df(x0);
        Matrix Q = Q0;
        Q += r * Matrix(r).transpose() / scalar_product(r, s);
        Matrix tmp = Q0 * s;
        Q -= tmp * tmp.transpose() / scalar_product(tmp, s);

        std::cout << x << std::endl;
        Q0 = Q;
        x0 = x;
    }


    std::cout << "result gradient is " << f.df(x0) << std::endl;
    return x0;
}


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
