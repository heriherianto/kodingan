/*
	rootNewtonR.cpp
	Mencari akar persamaan dengan menggunakan metode Newton Raphson

	Herianto	| E:\KULIAH\T3\Fisika Komputasi\Program c++
				| https://github.com/heriherianto/kodingan/tree/cpp

	Compile : g++ rootNewtonR.cpp -o rootNewtonR
	Execute : ./rootNewtonR (using cygwin)
				rootNewtonR (using cmd)

	2019-01-22
	Start this program at Board in Sangkuriang Bandung.
	
	Latest update	: 2019-02-05
	Update content	: adding new comment
*/

#include <iostream>
#include <cmath>

using namespace std;

double x0, dx, error;

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

int main (){

	//Get all parameters
	cout << "Masukkan tebakan nilai akar = ";
	cin >> x0; cout << endl;
	cout << "Masukkan ketelitian = ";
	cin >> dx; cout << endl;

	int iter = 0;
	error = abs(f(x0));
	cout << "# i\txi\tf(xi)" << endl;

	//Perform scanning process
	while(error > dx){
		cout << ++iter << "\t";
		cout << x0 << "\t" << f(x0) << endl;
		//Rumusan Newton Raphson
		x0 = x0 - f(x0) / dfdx(x0);
		error = abs(f(x0));
	}

	//Display result
	cout << ++iter << "\t";
    cout << x0 << "\t" << f(x0) << endl;
	cout << x0 << " is the root of the function" << endl;

	//Terminate program
	return 0;
}
