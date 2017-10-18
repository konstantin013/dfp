//
// Created by konstantin on 18.10.17.
//

#ifndef DFP_LINEAR_ALGEBRA_H
#define DFP_LINEAR_ALGEBRA_H

#include <vector>

class Matrix
{
public:
    int m, n;

    std::vector<std::vector<double> > A;
    Matrix(int m = 2, int n = 2, double d = 0.0);
    void print();
    Matrix transpose();

};




#endif //DFP_LINEAR_ALGEBRA_H
