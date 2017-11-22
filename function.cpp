//
// Created by konstantin on 20.10.17.
//

#include "function.h"

Function::Function(double (*f)(const Point &), Point (*df)(const Point &)):
f(f), df(df)  {}

Pfunction::Pfunction(const Function &f, const Function &p, double c) :
f(f), p(p), c(c) {}

double
Pfunction::get_f(const Point &x) const
{
    return f.f(x) + c * p.f(x);
}


Point
Pfunction::get_df(const Point &x) const
{
    return f.df(x) + c * p.df(x);
}

