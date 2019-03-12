#include<iostream>
using namespace std;

int main(void)
{
	double a, b, c;
	cin >> a >> b >> c;
	double answer = a * b / c > a / b * c ? a * b / c : a / b * c;
	printf("%d", (int)answer);
	return 0;
}