#include<iostream>
#include"vector.h"

#ifndef __MATRIX__
#define __MATRIX__

class Matrix {
private:
	int Rows;
	Vector *Element;
public:
	Matrix(void);
	Matrix(int rows, int cols);
	Matrix(const Matrix &arg);
	Matrix &operator=(const Matrix &rhs);
	~Matrix(void);
	int rows(void) const;
	int cols(void) const;
	Vector operator[](int index) const;
	Vector &operator[](int index);
	Matrix operator+(void) const;
	Matrix operator-(void) const;
	  Matrix &operator+=(const Matrix &rhs);
	  Matrix &operator-=(const Matrix &rhs);
	std::ostream &print(std::ostream &lhs) const;
	  bool operator==(const Matrix &rhs) const;
	  bool operator!=(const Matrix &rhs) const;
};

std::ostream &operator<<(std::ostream &lhs, const Matrix &rhs);
Matrix operator+(const Matrix &lhs, const Matrix &rhs);
Matrix operator-(const Matrix &lhs, const Matrix &rhs);
Matrix operator*(double factor, const Matrix &rhs);
Vector operator*(const Matrix &lhs, const Vector &rhs);
Matrix operator*(const Matrix &lhs, const Matrix &rhs);

#endif

