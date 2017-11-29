#include<iostream>
#include<cmath>
#include<cstdlib>
#include"matrix.h"

#define M_PI 3.14159265398979323846

int main(void) try {
	Matrix A(2, 2);
	double theta = M_PI / 4.0;
	A[0][0] = cos(theta);
	A[0][1] = sin(theta);
	A[1][0] = -sin(theta);
	A[1][1] = cos(theta);
	A=0.9*A;

	Vector b(2);
	b[0] = 1.0;
	b[1] = 1.0;

	Vector x(2);
	x[0] = 1.0;
	x[1] = 0.0;


	  for(int i=0;i<100;i++){
	    x=A*x+b;
	    std::cout << x[0] << "\t" << x[1] << std::endl;
	  }


	Matrix X(5, 4);
	for (int i = 0; i<X.rows(); i++) {
		for (int j = 0; j<X.cols(); j++) {
			X[i][j] = (double)(i + j + 1);
		}
	}
	std::cout << "X=\n" << X << std::endl;
	std::cout << "X+=X=\n" << (X+=X) << std::endl;
	Matrix Z(X);
	std::cout << "X-=X=\n" << (Z-=X) << std::endl;
	std::cout << "X+X=\n" << X+X << std::endl;
	std::cout << "X-X=\n" << X-X << std::endl;
	std::cout << "1.2*X=\n" << 1.2*X << std::endl;
	Vector c(X.cols());
	for (int j = 0; j<c.size(); j++) {
		c[j] = (double)(j + 1);
	}
	std::cout << "c=" << c << std::endl;
	std::cout << "X*c=\n" << X*c << std::endl;
	Matrix Y(4, 6);
	for (int i = 0; i<Y.rows(); i++) {
		for (int j = 0; j<Y.cols(); j++) {
			Y[i][j] = (double)(i + j + 2);
		}
	}
	std::cout << "X+=Y=\n" << (X += Y) << std::endl;//Size Unmatched***/
	std::cout << "X-=Y=\n" << (X -= Y) << std::endl;//Size Unmatched***/
	std::cout << "Y=\n" << Y << std::endl;
	  std::cout << "X*Y=\n" << X*Y << std::endl;
	  if(X==X){
	    std::cout << "X==X" << std::endl;
	  }
	  else{
	    std::cout << "X!=X" << std::endl;
	  }
	  if(X==Y){
	    std::cout << "X==Y" << std::endl;
	  }
	  else{
	    std::cout << "X!=Y" << std::endl;
	  }
	  if(X!=Y){
	    std::cout << "X!=Y" << std::endl;
	  }
	  else{
	    std::cout << "X==Y" << std::endl;
	  }

	return 0;

}
catch (std::exception &e) {
	std::cerr << "main:" << e.what() << std::endl;
	exit(1);
}
