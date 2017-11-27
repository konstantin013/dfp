//
// Created by konstantin on 20.10.17.
//

#include <unistd.h>
#include "dfp.h"

Point dfp(const Pfunction &f, Point x0, One_dim_search one_dim_search, double eps_stop) {

    int n = x0.size();
    Matrix Q0(n, n);

    std::cout << x0 << std::endl;

    while (norm(f.get_df(x0)) >= eps_stop) {
        Point d = -Q0 * f.get_df(x0);
        double alpha = one_dim_search(f, x0, d);

        if (alpha < -1) {
            std::cout << "can't make step by wolfe rule\n";
            if (alpha == -1) {
                std::cout << "can't find a2\n";
            }
            return x0;
        }

        Point x = x0 + alpha * d;

        Point r = x - x0;
        Point s = f.get_df(x) - f.get_df(x0);
        Matrix Q = Q0;
        Q += r * Matrix(r).transpose() / scalar_product(r, s);
        Matrix tmp = Q0 * s;
        Q -= tmp * tmp.transpose() / scalar_product(tmp, s);

        std::cout << x << std::endl;
        Q0 = Q;
        x0 = x;
    }

    return x0;
}


Point
penalty_dfp(Pfunction &f, Point x0, One_dim_search one_dim_search, double eps_stop, double c_max)
{

    for (; ; f.c = f.c + 1) {
        std::cout << "c = " << f.c << std::endl;
        Point x1 = dfp(f, x0, one_dim_search, 1e-7);
        double step = norm(x1 - x0);
        std::cout << "make step " << step << std::endl;
        //sleep(1);
        if (f.c == c_max) {
            return x1;
        }

        x0 = x1;
    }
}

