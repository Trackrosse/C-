#include"vector.h"

Vector::Vector(void) :Size(0), Element(NULL) {
}

Vector::Vector(int n) try : Size(n), Element(new double[Size]){
}
catch (std::bad_alloc) {
	std::cerr << "Out of Memory" << std::endl;
	throw;
}

Vector::Vector(const Vector &arg) try : Size(arg.size()), Element(new double[arg.size()]){
	for (int i = 0; i<Size; i++) {
		Element[i] = arg.Element[i];
	}
}
catch (std::bad_alloc) {
	std::cerr << "Out of Memory" << std::endl;
	throw;
}


Vector &Vector::operator=(const Vector &rhs) {
	if (this != &rhs) {
		if (Size != rhs.size()) {
			Size = rhs.size();
			delete[]Element;
			try {
				Element = new double[Size];
			}
			catch (std::bad_alloc) {
				std::cerr << "Vector::operator=: Out of Memory" << std::endl;
				throw;
			}
		}
		for (int i = 0; i<Size; i++) {
			Element[i] = rhs.Element[i];
		}
	}
	return *this;
}

Vector::~Vector(void) {
	delete[]Element;
}

int Vector::size(void) const {
	return Size;
}

//�Y�����Z�q
double Vector::operator[](int index) const {
	return Element[index];
}

//�Y�����Z�q
double &Vector::operator[](int index) {
	return Element[index];
}

//���Z������Z�q
Vector &Vector::operator+=(const Vector &rhs) {
	if (Size != rhs.size()) {
		std::cerr << "Vector::operator+=: Size Unmatched" << std::endl;
		exit(1);
	}
	for (int i = 0; i<Size; i++) {
		Element[i] += rhs[i];
	}
	return *this;
}

//���Z������Z�q
Vector &Vector::operator-=(const Vector &rhs) {
	if (Size != rhs.size()) {
		std::cerr << "Vector::operator-=: Size Unmatched" << std::endl;
		exit(1);
	}
	for (int i = 0; i<Size; i++) {
		Element[i] -= rhs[i];
	}
	return *this;
}

std::ostream &Vector::print(std::ostream &lhs) const {
	lhs << "(";
	for (int i = 0; i<Size; i++) {
		lhs << Element[i] << ", ";
	}
	lhs << ")";
	return lhs;
}

//�������Z�q
Vector Vector::operator+(void) const {
	return *this;
}

//�������Z�q
Vector Vector::operator-(void) const {
	Vector result(*this);
	for (int i = 0; i<Size; i++) {
		result[i] = -result[i];
	}
	return result;
}

std::ostream &operator<<(std::ostream &lhs, const Vector &rhs) {
	return rhs.print(lhs);
}

//���Z���Z�q
Vector operator+(const Vector &lhs, const Vector &rhs) {
	Vector result(lhs);
	return result += rhs;
}

//���Z���Z�q
Vector operator-(const Vector &lhs, const Vector &rhs) {
	Vector result(lhs);
	return result -= rhs;
}

//����
double operator*(const Vector &lhs, const Vector &rhs) {
	if (lhs.size() != rhs.size()) {
		std::cerr << "operator*(const Vector &, const Vector &): Size Unmatched" << std::endl;
		exit(1);
	}
	double result = 0.0;
	for (int i = 0; i<lhs.size(); i++) {
		result += lhs[i] * rhs[i];
	}
	return result;
}

//�萔�{
Vector operator*(double lhs, const Vector &rhs) {
	Vector result(rhs);
	for (int i = 0; i<result.size(); i++) {
		result[i] = lhs*rhs[i];
	}
	return result;
}

//��r���Z�q
bool operator==(const Vector &lhs, const Vector &rhs) {
	if (lhs.size() != rhs.size()) {
		return false;
	}
	for (int i = 0; i<lhs.size(); i++) {
		if (lhs[i] != rhs[i]) {
			return false;
		}
	}
	return true;
}

//��r���Z�q
bool operator!=(const Vector &lhs, const Vector &rhs) {
	if (lhs.size() != rhs.size()) {
		return true;
	}
	for (int i = 0; i<lhs.size(); i++) {
		if (lhs[i] != rhs[i]) {
			return true;
		}
	}
	return false;
}
