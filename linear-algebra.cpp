//
// Created by konstantin on 18.10.17.
//


#include <vector>
#include <iostream>
#include "linear-algebra.h"




void Matrix::print() {
    for (const auto &v: A) {
        for (double d: v) {
            std::cout << d << ' ';
        }
        std::cout << std::endl;
    }
}

Matrix::Matrix(int m, int n, double d): m(m), n(n) {
    A.resize(m, std::vector<double>(n, d));
}

Matrix Matrix::transpose() {
    Matrix B(n, m);
    for (unsigned int r = 0; r < m; ++r) {
        for (unsigned int c = 0; c < n; ++c) {
            B.A[c][r] = A[r][c];
        }
    }

    return B;
}