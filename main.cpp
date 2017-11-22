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

    return x * x * x * x + y * y;
}

Point
df(const Point &p)
{
    double x = p[0];
    double y = p[1];

    return  Point{4 * x * x * x, 2 * y};
}


int main()
{
    Function func(f, df);
    Point x0{1, 1};


    wolfe::eps1 = 0.4;
    wolfe::eps2 = 0.7;
    double eps_stop = 1e-20;


    dfp(func, x0, wolfe::wolfe, eps_stop);

    cout << "the end" << endl;
}