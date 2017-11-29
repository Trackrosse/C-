#include<iostream>
#include<cstdlib>
#include<new>

class Vector {
private:
	int Size;
	double* Element;
public:
	Vector(void);
	explicit Vector(int n);//explicitéŒ¾
	Vector(const Vector &arg);
	Vector &operator=(const Vector &rhs);
	~Vector(void);
	int size(void) const;
	double operator[](int index) const;//“Yš‰‰Zq
	double &operator[](int index);//“Yš‰‰Zq
	std::ostream &print(std::ostream &lhs) const;
	Vector &operator+=(const Vector &rhs);//‰ÁZ‘ã“ü‰‰Zq
	Vector &operator-=(const Vector &rhs);//Œ¸Z‘ã“ü‰‰Zq
	Vector operator+(void) const;//operator+
	Vector operator-(void) const;//operator-
};

std::ostream &operator<<(std::ostream &lhs, const Vector &rhs);
Vector operator+(const Vector &lhs, const Vector &rhs);//‰ÁZ‰‰Zq
Vector operator-(const Vector &lhs, const Vector &rhs);//Œ¸Z‰‰Zq
double operator*(const Vector &lhs, const Vector &rhs);//“àÏ
Vector operator*(double lhs, const Vector &rhs);//’è””{
bool operator==(const Vector &lhs, const Vector &rhs);//”äŠr‰‰Zq
bool operator!=(const Vector &lhs, const Vector &rhs);//”äŠr‰‰Zq
