//
// Created by konstantin on 18.10.17.
//

#ifndef DFP_LINEAR_ALGEBRA_H
#define DFP_LINEAR_ALGEBRA_H

#include <vector>

typedef  std::vector<double> Point;


class Matrix
{
public:
    int m, n;
    std::vector<std::vector<double> > data;

    //std::vector<double> & operator [](int i);
    const std::vector<double> & operator [](int i) const;
    std::vector<double> & operator [](int i);



    Matrix(int m = 2, int n = 2, double d = 0.0);
    Matrix(const Point &v);

    Matrix(std::initializer_list< std::initializer_list<double> > l);

    void print();
    Matrix transpose();

};

Matrix operator +(const Matrix &A, const Matrix &B);
Matrix operator -(const Matrix &A, const Matrix &B);
Matrix operator *(const Matrix &A, const Matrix &B);


Matrix& operator *=(Matrix &A, double alpha);
Matrix operator *(const Matrix &A, double alpha);
Matrix operator *(double alpha, const Matrix &A);

Point& operator *=(Point &p, double alpha);
Point operator *(const Point &p, double alpha);
Point operator *(double alpha, const Point &p);


#endif //DFP_LINEAR_ALGEBRA_H
