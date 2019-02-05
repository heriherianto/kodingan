/*
	rootNewtonQz.cpp
	Mencari akar persamaan dengan menggunakan metode Newton Raphson
	dengan fungsi polinomial pangkat tiga, input koefisien dari user

	Herianto	| E:\KULIAH\T3\Fisika Komputasi\Program c++
				| https://github.com/heriherianto/kodingan/tree/cpp

	Compile : g++ rootNewtonQz.cpp -o rootNewtonQz
	Execute : ./rootNewtonQz (using cygwin)
				rootNewtonQz (using cmd)

	2019-01-23
	Start this program at class 9025, Oktagon, ITB Bandung.
	
	Latest update	: 2019-02-05
	Update content	: adding new comment
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

//define function
double f(double x, double a, double b, double c, double d);
double fx(double x, double a, double b, double c);

using namespace std;

int main (int argc, char *argv[])
{
	//check arguments
	if(argc < 7) 
	{
		cout << "Usage: rootNewton [a b c d x1 eps]" << endl;
		cout << "a" << endl;
		cout << "b" << endl;
		cout << "c" << endl;
		cout << "d" << endl;
		cout << "x1\t1st x" << endl;
		cout << "eps\taccuracy of f(xn) = 0" << endl;
		return 1;
	}
	//get all parameters
	double a = atof (argv[1]);
	double b = atof (argv[2]);
	double c = atof (argv[3]);
	double d = atof (argv[4]);
	double xa = atof(argv[5]);
	double eps = atof(argv[6]);
	
	int i = 0;
	cout << "# i\txi\tf(xi)\tf'(xi)" << endl;
	//perform scanning process
	vector<double> root = {};
	double fa = f(xa,a,b,c,d);
	
	while (fabs(fa) > eps)
	{
		fa = f(xa,a,b,c,d);
		cout << ++i << "\t";
		cout << xa << "\t" << fa << "\t" << fx(xa,a,b,c) << endl;
		
		if (fabs(fa) < eps)
		{
			root.push_back(xa);
		}
		//Rumusan Newton Raphson
		xa = xa - f(xa,a,b,c,d) / fx(xa,a,b,c);
	}
	//display result
	if (root.size() > 0)
	{
		cout << "1st root = " << root[0] << endl;
	}
	else
	{
		cout << "No root found with given parameters" << endl;
	}
	//terminate program
	return 0;
}
//define quadratic function
	double f(double x, double a, double b, double c, double d)
	{
		double fx = a*x*x*x + b*x*x + c*x + d;
		return fx;
	}
//define derivative of the quadratic function above
	double fx(double x, double a, double b, double c)
	{
		double fx = 3*a*x*x + 2*b*x + c;
		return fx;
	}
