#include<iostream>
#include<cstdlib>
#include<new>

class Vector {
private:
	int Size;
	double* Element;
public:
	Vector(void);
	explicit Vector(int n);//explicitιΎ
	Vector(const Vector &arg);
	Vector &operator=(const Vector &rhs);
	~Vector(void);
	int size(void) const;
	double operator[](int index) const;//YZq
	double &operator[](int index);//YZq
	std::ostream &print(std::ostream &lhs) const;
	Vector &operator+=(const Vector &rhs);//ΑZγόZq
	Vector &operator-=(const Vector &rhs);//ΈZγόZq
	Vector operator+(void) const;//operator+
	Vector operator-(void) const;//operator-
};

std::ostream &operator<<(std::ostream &lhs, const Vector &rhs);
Vector operator+(const Vector &lhs, const Vector &rhs);//ΑZZq
Vector operator-(const Vector &lhs, const Vector &rhs);//ΈZZq
double operator*(const Vector &lhs, const Vector &rhs);//ΰΟ
Vector operator*(double lhs, const Vector &rhs);//θ{
bool operator==(const Vector &lhs, const Vector &rhs);//δrZq
bool operator!=(const Vector &lhs, const Vector &rhs);//δrZq
