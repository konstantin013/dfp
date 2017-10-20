//
// Created by konstantin on 20.10.17.
//

#ifndef DFP_DFP_H
#define DFP_DFP_H

#include "linear-algebra.h"
#include "function.h"

typedef double (*One_dim_search)(Function f, Point x, Point d);

Point
dfp(Function f, Point x0, One_dim_search s);

#endif //DFP_DFP_H
