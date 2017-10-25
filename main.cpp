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

double
one_dim_search(const Function &f, const Point &x, const Point &d)
{
    return 0.0001;
}



int main()
{
    Function func(f, df);
    Point x0{153, 327};


    wolfe::eps1 = 0.7;
    wolfe::eps2 = 0.9;

    dfp(func, x0, wolfe::wolfe);

    cout << "the end" << endl;
}