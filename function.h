//
// Created by konstantin on 20.10.17.
//

#include <cmath>
#include "linear-algebra.h"


#ifndef DFP_FUNCTION_H
#define DFP_FUNCTION_H


class Function {
public:
    double (*f)(const Point &);
    Point (*df)(const Point &);

    Function(double (*f)(const Point &), Point (*df)(const Point &));
};

class Pfunction {
public:
    Function f;
    Function p;
    double c;

    Pfunction(const Function&, const Function&, double);
    double  get_f(const Point &x) const;
    Point get_df(const Point &x) const;
};

#endif //DFP_FUNCTION_H
