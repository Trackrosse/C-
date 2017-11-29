#include<iostream>
#include<cassert>
#include<cstdlib>
#include"matrix.h"

Matrix::Matrix(void) : Rows(0), Element(NULL) {
}

Matrix::Matrix(int rows, int cols) try : Rows(rows), Element(new Vector[Rows]){
	for (int i = 0; i<Rows; i++) {
		Element[i] = Vector(cols);
	}
}
catch (std::bad_alloc) {
	std::cerr << "Matrix::Matrix(int, int): Out of Memory" << std::endl;
	throw;
}

Matrix::Matrix(const Matrix &arg) try : Rows(arg.rows()), Element(new Vector[arg.rows()]){
	for (int i = 0; i<Rows; i++) {
		Element[i] = arg.Element[i];
	}
}
catch (std::bad_alloc) {
	std::cerr << "Matrix::Matrix(const Matrix &): Out of Memory" << std::endl;
	throw;
}

Matrix::~Matrix(void) {
	delete[] Element;
	return;
}


Matrix &Matrix::operator=(const Matrix& rhs) {
	if (this != &rhs) {
		if (Rows != rhs.rows()) {
			Rows = rhs.rows();
			delete[]Element;
			try {
				Element = new Vector[Rows];
			}
			catch (std::bad_alloc) {
				std::cerr << "Matrix::operator=(const Matrix &): Out of Memory" << std::endl;
				throw;
			}
		}
		for (int i = 0; i<Rows; i++) {
			Element[i] = rhs.Element[i];
		}
	}
	return *this;
}

int Matrix::rows(void) const {
	return Rows;
}

int Matrix::cols(void) const {
	if (Element == NULL) {
		return 0;
	}
	return Element[0].size();
}

Vector Matrix::operator[](int index) const {
	return Element[index];
}

Vector &Matrix::operator[](int index) {
	return Element[index];
}

std::ostream &Matrix::print(std::ostream &lhs) const {
	lhs << "(";
	int i;
	for (i = 0; i<Rows - 1; i++) {
		lhs << Element[i] << ",\n";
	}
	lhs << Element[i] << ")";
	return lhs;
}

std::ostream &operator<<(std::ostream &lhs, const Matrix &rhs) {
	return rhs.print(lhs);
}
//•„†‰‰ŽZŽq
Matrix Matrix::operator+(void) const {
	return *this;
}
//•„†‰‰ŽZŽq
Matrix Matrix::operator-(void) const {
	Matrix result(*this);
	for (int i = 0; i<Rows; i++) {
		result.Element[i] = -Element[i];
	}
	return result;
}
//‰ÁŽZ‘ã“ü‰‰ŽZŽq
Matrix &Matrix::operator+=(const Matrix &rhs) {
	if (Rows != rhs.rows() || Rows == 0) {
		std::cerr << "Matrix::operator+=(const Matrix &): Size unmatched" << std::endl;
		exit(1);
	}
	for (int i = 0; i<Rows; i++) {
		Element[i] += rhs[i];
	}
	return *this;
}
//‰ÁŽZ‰‰ŽZŽq
Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
	if (lhs.rows() != rhs.rows() || lhs.rows() == 0) {
		std::cerr << "operator+(const Matrix &, const Matrix &): Size Unmatched" << std::endl;
		exit(1);
	}
	Matrix result(lhs);
	return result += rhs;
}
//Œ¸ŽZ‘ã“ü‰‰ŽZŽq
Matrix &Matrix::operator-=(const Matrix &rhs) {
	if (Rows != rhs.rows() || Rows == 0) {
		std::cerr << "Matrix::operator-=(const Matrix &): Size unmatched" << std::endl;
		exit(1);
	}
	for (int i = 0; i<Rows; i++) {
		Element[i] -= rhs[i];
	}
	return *this;
}
//Œ¸ŽZ‰‰ŽZŽq
Matrix operator-(const Matrix &lhs, const Matrix &rhs) {
	if (lhs.rows() != rhs.rows() || lhs.rows() == 0) {
		std::cerr << "operator-(const Matrix &, const Matrix &): Size Unmatched" << std::endl;
		exit(1);
	}
	Matrix result(lhs);
	return result -= rhs;
}
//’è””{
Matrix operator*(double factor, const Matrix &rhs) {
	if (rhs.rows() == 0) {
		std::cerr << "operator*(double, const Matrix &): Size unmatched" << std::endl;
		exit(1);
	}
	Matrix result(rhs);
	for (int i = 0; i<result.rows(); i++) {
		result[i] = factor*result[i];
	}
	return result;
}
//s—ñ‚ÆƒxƒNƒgƒ‹‚ÌæŽZ
Vector operator*(const Matrix &lhs, const Vector &rhs) {
	if (lhs.cols() != rhs.size() || lhs.rows() == 0) {
		std::cerr << "operator*(const Matrix &, const Vector &): Size unmatched" << std::endl;
		exit(1);
	}
	Vector result(lhs.rows());
	for (int i = 0; i<lhs.rows(); i++) {
		result[i] = lhs[i] * rhs;
	}
	return result;
}
//s—ñ“¯Žm‚ÌæŽZ
Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
	if (lhs.cols() != rhs.rows() || lhs.rows() == 0 && rhs.cols() == 0) {
		std::cerr << "operator*(const Matrix &, const Matrix &): Size unmatched" << std::endl;
		exit(1);
	}
	Matrix result(lhs.rows(), rhs.cols());
	for (int i = 0; i<result.rows(); i++) {
		for (int j = 0; j<result.cols(); j++) {
			result[i][j] = 0.0;
		}
	}
	for (int i = 0; i<result.rows(); i++) {
		for (int j = 0; j<result.cols(); j++) {
			for (int k = 0; k<lhs.cols(); k++) {
				result[i][j] += lhs[i][k] * rhs[k][j];
			}
		}
	}
	return result;
}

bool Matrix::operator==(const Matrix &rhs) const {
	if (Rows != rhs.rows() || this->cols() != rhs.cols())return false;
	for (int i = 0; i<Rows; i++) {
		if (Element[i] != rhs[i])return false;
	}
	return true;
}

bool Matrix::operator!=(const Matrix &rhs) const {
	if (Rows != rhs.rows() || this->cols() != rhs.cols())return true;
	for (int i = 0; i<Rows; i++) {
		if (Element[i] != rhs[i])return true;
	}
	return false;
}
