//
// Created by konstantin on 18.10.17.
//


#include <vector>
#include <iostream>
#include "linear-algebra.h"




void Matrix::print() {
    for (const auto &v: data) {
        for (double d: v) {
            std::cout << d << ' ';
        }
        std::cout << std::endl;
    }
}

Matrix::Matrix(int m, int n, double d): m(m), n(n) {
    data.resize(m, std::vector<double>(n, d));
}

Matrix Matrix::transpose() {
    Matrix B(n, m);
    for (unsigned int r = 0; r < m; ++r) {
        for (unsigned int c = 0; c < n; ++c) {
            B.data[c][r] = data[r][c];
        }
    }

    return B;
}

Matrix::Matrix(const Point &v): m(v.size()), n(1) {
    data.resize(v.size());
    for (int r = 0; r < m; ++r) {
        data[r].resize(1, v[r]);
    }
}

Matrix operator+(const Matrix &A, const Matrix &B) {
    Matrix C(A.m, A.n);

    for (int r = 0; r < A.m; ++r) {
        for (int c = 0; c < A.n; ++c) {
            C.data[r][c] = A.data[r][c] + B.data[r][c];
        }
    }
    return C;
}

Matrix operator-(const Matrix &A, const Matrix &B) {
    Matrix C(A.m, A.n);

    for (int r = 0; r < A.m; ++r) {
        for (int c = 0; c < A.n; ++c) {
            C.data[r][c] = A.data[r][c] - B.data[r][c];
        }
    }
    return C;
}
