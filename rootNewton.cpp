/*
	rootNewton.cpp
	Mencari akar persamaan dengan menggunakan metode Newton Raphson

	Herianto	| E:\KULIAH\T3\Fisika Komputasi\Program c++
				| https://github.com/heriherianto/kodingan

	Compile : g++ rootNewton.cpp -o rootNewton
	Execute : ./rootNewton (using cygwin)
				rootNewton (using cmd)

	2019-01-22
	Start this program at Board in Sangkuriang Bandung.
*/

#include <iostream>
#include <cmath>
#include <vector>

double f (double);
double dfdx (double);

using namespace std;

int main (int argc, char *argv[]){

	//Check arguments
	if (argc < 3){
		cout << "Usage: rootNewton [x1 eps]" << endl;
		cout << "x1\t1st x" << endl;
		cout << "eps\taccuracy of f(xn) = 0" << endl;
		return 1;
	}

	//Get all parameters
	double xa = atof(argv[1]);
	double eps = atof(argv[2]);

	int i = 0;
	cout << "# i\txc\tf(xc)" << endl;

	//Perform scanning process
	vector<double> root = {};
	double fa = f(xa);
	while(fabs(fa) > eps){
		fa = f(xa);
		cout << ++i << "\t";
		cout << xa << "\t" << fa << endl;

		if(fabs(fa) < eps){
			root.push_back(xa);
		}
		//rumusan metode Newton Raphson
		xa = xa - f(xa) / dfdx(xa);
	}

	//Display result
	if(root.size() > 0){
		cout << "1st root = " << root[0] << endl;
	} else {
		cout << "No root found with given parameters" << endl;
	}

	//Terminate program
	return 0;
}

//Define the function
double f(double x){
	double result = (1.25 - x) * (x - 6.25);
	return result;
}

//Define derivative of the function
double dfdx(double x){
	double result = -1 * (x - 6.25) + (1.25 - x) * 1;
	return result;
}