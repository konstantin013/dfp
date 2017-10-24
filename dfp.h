//
// Created by konstantin on 20.10.17.
//

#ifndef DFP_DFP_H
#define DFP_DFP_H

#include "linear-algebra.h"
#include "function.h"

typedef double (*One_dim_search)(const Function &f, const Point &x, const Point &d);

Point
dfp(const Function &f, Point x0, One_dim_search one_dim_search);

#endif //DFP_DFP_H
