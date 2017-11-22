#include <iostream>
#include "linear-algebra.h"
#include "function.h"
#include "dfp.h"
#include "wolfe.h"

using  namespace std;

double
f(const Point &p)
{
    double x = p[0];
    double y = p[1];

    return (x - 4) * (x - 4) + (y - 7) * (y - 7);
}

Point
df(const Point &p)
{
    double x = p[0];
    double y = p[1];

    return  Point{2 * (x - 4), 2 * (y - 7)};
}

double
p(const Point &u)
{
    double x = u[0];
    double y = u[1];

    double g = x * x + y * y - 1;
    if (g <= 0) {
        return 0;
    } else {
        return g;
    }
}

Point
dp(const Point &u)
{
    double x = u[0];
    double y = u[1];

    if (x * x + y * y <= 1) {
        return Point{0, 0};
    } else {
        return Point{2 * x, 2 * y};
    }
}


int main()
{
    Function func(f, df);
    Function penalty(p, dp);
    Pfunction f(func, penalty, 0);

    Point x0{0, 0};

    wolfe::eps1 = 0.4;
    wolfe::eps2 = 0.7;
    double eps_stop = 1e-5;


    penalty_dfp(f, x0, wolfe::wolfe, eps_stop);

    cout << "the end" << endl;
}