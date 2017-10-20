//
// Created by konstantin on 20.10.17.
//

#ifndef DFP_FUNCTION_H
#define DFP_FUNCTION_H


#include <cmath>
#include "linear-algebra.h"

class Function {
public:
    double (*f)(const Point &);
    Point (*df)(const Point &);

    Function(double (*f)(const Point &), Point (*df)(const Point &));
};


#endif //DFP_FUNCTION_H
