#include<iostream>
#include<cstdlib>
#include<new>

class Vector {
private:
	int Size;
	double* Element;
public:
	Vector(void);
	explicit Vector(int n);//explicit�錾
	Vector(const Vector &arg);
	Vector &operator=(const Vector &rhs);
	~Vector(void);
	int size(void) const;
	double operator[](int index) const;//�Y�����Z�q
	double &operator[](int index);//�Y�����Z�q
	std::ostream &print(std::ostream &lhs) const;
	Vector &operator+=(const Vector &rhs);//���Z������Z�q
	Vector &operator-=(const Vector &rhs);//���Z������Z�q
	Vector operator+(void) const;//operator+
	Vector operator-(void) const;//operator-
};

std::ostream &operator<<(std::ostream &lhs, const Vector &rhs);
Vector operator+(const Vector &lhs, const Vector &rhs);//���Z���Z�q
Vector operator-(const Vector &lhs, const Vector &rhs);//���Z���Z�q
double operator*(const Vector &lhs, const Vector &rhs);//����
Vector operator*(double lhs, const Vector &rhs);//�萔�{
bool operator==(const Vector &lhs, const Vector &rhs);//��r���Z�q
bool operator!=(const Vector &lhs, const Vector &rhs);//��r���Z�q
