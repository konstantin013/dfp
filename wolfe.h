//
// Created by konstantin on 25.10.17.
//

#ifndef DFP_WOLFE_H
#define DFP_WOLFE_H

#include "function.h"

namespace  wolfe {
    extern  double eps1, eps2, a_ub;
    double wolfe(const Function &f, const Point &x, const Point &d);
    inline bool ul(const Function &f, const Point &x, const Point &d, double a);
    inline bool ur(const Function &f, const Point &x, const Point &d, double a);
}


#endif //DFP_WOLFE_H
