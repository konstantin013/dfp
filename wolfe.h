//
// Created by konstantin on 25.10.17.
//

#ifndef DFP_WOLFE_H
#define DFP_WOLFE_H

#include "function.h"
#include <unistd.h>

namespace  wolfe {
    extern  double eps1, eps2, a_ub;
    double wolfe(const Pfunction &f, const Point &x, const Point &d);
    inline bool ul(const Pfunction &f, const Point &x, const Point &d, double a);
    inline bool ur(const Pfunction &f, const Point &x, const Point &d, double a);
}


#endif //DFP_WOLFE_H
