#include <iostream>
#include "linear-algebra.h"
#include "function.h"
#include "dfp.h"
#include "wolfe.h"

using  namespace std;



double
f(const Point &x)
{
    double res = 0;
    double s;
    for (int i = 1; i < 6; ++i) {
        s = x[i] - (i + 1) * x[0];
        res += s * s * s * s;
    }

    res *= 150;

    s = x[0] - 2;
    res += s * s * s * s;

    return res;
}

Point
df(const Point &x)
{
    Point res(6);

    double s =  x[0] - 2;
    res[0] = 4 * s * s * s;

    for (int i = 1; i < 6; ++i) {
        s = (i + 1) * x[0] - x[i];
        res[0] += 150 * 4 * s * s * s * (i + 1);
    }

    for (int i = 1; i < 6; ++i) {
        s = x[i] - (i + 1) * x[0];
        res[i] = 150 * 4 * s * s * s;
    }

    return res;
}

double
g1(const Point &x)
{
    return scalar_product(x, x) - 363;
}

double
p(const Point &x)
{
    double g = g1(x);

    if (g < 0) {
        return 0;
    } else {
        return g * g;
    }
}

Point
dp(const Point &x)
{
    double g = g1(x);

    Point res(6, 0);
    if (g < 0) {
        return res;
    } else {
        for (int i = 0; i < 6; ++i) {
            res[i] = 4 * x[i] * g;
        }
        return res;
    }
}



int main()
{
    Function func(f, df);
    Function penalty(p, dp);
    Pfunction f(func, penalty, 0);

    Point x0(6, 0);

    wolfe::eps1 = 0.4;
    wolfe::eps2 = 0.7;
    double eps_stop = 1e-10;
    double c_max = 30;

    Point res = penalty_dfp(f, x0, wolfe::wolfe, eps_stop, c_max);

    //Point res = dfp(f, x0, wolfe::wolfe, 1e-9);
    cout << "g1(res): " << g1(res) << endl;

    cout << "the end" << endl;
}