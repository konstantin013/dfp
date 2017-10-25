//
// Created by konstantin on 25.10.17.
//

#ifndef DFP_WOLFE_H
#define DFP_WOLFE_H

#include "function.h"

namespace  wolfe {
    extern  double eps1, eps2;
    double wolfe(const Function &f, const Point &x, const Point &d);
}


#endif //DFP_WOLFE_H
