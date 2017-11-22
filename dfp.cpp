//
// Created by konstantin on 20.10.17.
//

#include "dfp.h"

Point dfp(const Function &f, Point x0, One_dim_search one_dim_search, double eps_stop) {
    int n = x0.size();
    Matrix Q0(n, n);

    std::cout << x0 << std::endl;

    while (norm(f.df(x0)) >= eps_stop) {
        Point d = -Q0 * f.df(x0);
        double alpha = one_dim_search(f, x0, d);

        if (alpha == -1) {
            std::cout << "can't make step by wolfe rule" << std::endl;
            return x0;
        }

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

