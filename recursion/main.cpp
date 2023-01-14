#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
using namespace std;
double RecProduct(double, double);
double IterProduct(double, double);
int main()
{
	double N, k, P1, P2;
	system("chcp 1251");
	system("cls");
	cout << "Input k<25:";cin >> k;
while (k > 25) { cout << "Error!Input k<25:\t "; cin >> k; cout << endl; }
	N=k;
	P1 = RecProduct(k,N);
	cout << "Recursive product = " << P1<< endl;
	P2 = IterProduct(k, N);
	cout << "Iterative product = " << P2<< endl;
}
double RecProduct(double k, double N) {
	long double D = 1;
	if (k <= 25) {
		D = sqrt(1 + N / k) * RecProduct(k+1,N);
	}
		return D;
}
double IterProduct(double k, double N) {
	long double D = 1;
	for (k; k <= 25; k++) {
		D *= sqrt(1 + N / k);
	}
	return D;
}

