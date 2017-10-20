//
// Created by konstantin on 18.10.17.
//

#ifndef DFP_LINEAR_ALGEBRA_H
#define DFP_LINEAR_ALGEBRA_H

#include <vector>
#include <iostream>

typedef  std::vector<double> Point;


class Matrix
{
public:
    int m, n;
    std::vector<std::vector<double> > data;

    //std::vector<double> & operator [](int i);
    const std::vector<double> & operator [](int i) const;
    std::vector<double> & operator [](int i);



    Matrix(int m, int n);
    //create matrix with 1 in main diagonal and 0 else

    Matrix(const Point &v);

    Matrix(std::initializer_list< std::initializer_list<double> > l);

    void print();
    Matrix transpose();

    operator Point() const;
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

Point& operator +=(Point &a, const Point &b);
Point operator +(const Point &a, const Point &b);

Point operator -=(Point &a, const Point &b);
Point operator -(const Point &a, const Point &b);

Matrix operator -(const Matrix&);
Point operator -(const Point&);

std::ostream &operator<<(std::ostream &os, const Point &p);
std::ostream &operator<<(std::ostream &os, const Matrix &A);

double scalar_product(const Point &, const Point &);

#endif //DFP_LINEAR_ALGEBRA_H
