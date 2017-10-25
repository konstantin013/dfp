//
// Created by konstantin on 20.10.17.
//


#include "linear-algebra.h"
#include "function.h"


#ifndef DFP_DFP_H
#define DFP_DFP_H

typedef double (*One_dim_search)(const Function &f, const Point &x, const Point &d);

Point
dfp(const Function &f, Point x0, One_dim_search one_dim_search);


double wolfe(const Function &f, const Point &x, const Point &d);


#endif //DFP_DFP_H
