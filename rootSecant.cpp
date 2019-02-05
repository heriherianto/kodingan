/*
	rootSecant.cpp
	Mencari akar persamaan dengan menggunakan metode Secant

	Herianto	| E:\KULIAH\T3\Fisika Komputasi\Program c++
				| https://github.com/heriherianto/kodingan/tree/cpp

	Compile : g++ rootSecant.cpp -o rootSecant
	Execute : ./rootSecant (using cygwin)
				rootSecant (using cmd)

	2019-01-25
	Start this program at Board in Sangkuriang Bandung.
	
	Latest update	: 2019-02-05
	Update content	: adding new comment
*/

#include <iostream>
#include <cmath>
#include <vector>

//define function
double f (double);

using namespace std;

int main (int argc, char *argv[]){

	//Check arguments
	if (argc < 4){
		cout << "Usage: rootSecant [x1 x2 eps]" << endl;
		cout << "x1\t1st x" << endl;
		cout << "x2\t2nd x" << endl;
		cout << "eps\taccuracy of f(xn) = 0" << endl;
		return 1;
	}

	//Get all parameters
	double xa = atof(argv[1]);
	double xb = atof(argv[2]);
	double eps = atof(argv[3]);

	int i = 0;
	cout << "# i\txi\tf(xi)" << endl;

	//Perform scanning process
	vector<double> root = {};
	double fa = f(xa);
	double fb = f(xb);
	double xc = xb - (xb - xa) * fb / (fb - fa);
	double fc = f(xc);
	while((fabs(fc) > eps) && (i < 1000)){
		fc = f(xc);
		cout << ++i << "\t";
		cout << xc << "\t" << fc << endl;

		if(fabs(fc) < eps){
			root.push_back(xc);
		}
		//Rumusan metode Secant
		xa = xb;
		xb = xc;
		fa = f(xa);
		fb = f(xb);		
		xc = xb - (xb - xa) * fb / (fb - fa);
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