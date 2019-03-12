#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;

int main(void)
{
	double n;
	cin >> n;
	cout << fixed;
	cout.precision(6);
	cout << n * n*M_PI<<endl;
	cout << n * n * 2;
	cout << sizeof(float) << sizeof(long);
	return 0;
}