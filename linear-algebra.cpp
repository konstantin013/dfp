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

std::vector<double> &Matrix::operator[](int i){
    return data[i];
}

const std::vector<double> &Matrix::operator[](int i) const {
    return data[i];
}

Matrix operator+(const Matrix &A, const Matrix &B) {
    Matrix C(A.m, A.n);

    for (int r = 0; r < A.m; ++r) {
        for (int c = 0; c < A.n; ++c) {
            C[r][c] = A[r][c] + B[r][c];
        }
    }
    return C;
}

Matrix operator-(const Matrix &A, const Matrix &B) {
    Matrix C(A.m, A.n);

    for (int r = 0; r < A.m; ++r) {
        for (int c = 0; c < A.n; ++c) {
            C[r][c] = A[r][c] - B[r][c];
        }
    }
    return C;
}



Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix C(A.m, B.n);

    for (int i = 0; i < C.m; ++i) {
        for (int j = 0; j < C.n; ++j) {
            for (int k = 0; k < A.n; ++k) {
                std::cout << "pos " << i << ' ' << k << ' ' << j << std::endl;
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}



