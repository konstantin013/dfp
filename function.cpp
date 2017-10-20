//
// Created by konstantin on 20.10.17.
//

#include "function.h"

Function::Function(double (*f)(const Point &), Point (*df)(const Point &)):
f(f), df(df)  {}
