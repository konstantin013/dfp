//
// Created by konstantin on 20.10.17.
//


#include "linear-algebra.h"
#include "function.h"


#ifndef DFP_DFP_H
#define DFP_DFP_H

typedef double (*One_dim_search)(const Pfunction &f, const Point &x, const Point &d);

Point
dfp(const Pfunction &f, Point x0, One_dim_search one_dim_search, double eps_stop);


Point
penalty_dfp(Pfunction &f, Point x0, One_dim_search one_dim_search, double eps_stop, double c_max);




#endif //DFP_DFP_H
