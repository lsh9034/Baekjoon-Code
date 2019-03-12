#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)return a;
	return gcd(b, a%b);
}

int main(void)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int a, b;
		cin >> a >> b;
		int m = gcd(a, b);
		cout << m*(a/m)*(b/m)<<endl;
	}
	return 0;
}