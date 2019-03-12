#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)return a;
	gcd(b, a%b);
}

int main(void)
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int a, b;
		int s;
		cin >> a >> b;
		while (a!=1)
		{
			for (int i = 2; i <= b + 1; i++)
			{
				if (b < a*i)
				{
					s = i;
					break;
				}
			}
			a = a * s;
			a -= b;
			b = b * s;
			int m = gcd(a, b);
			a /= m;
			b /= m;
		}
		cout << b << endl;
	}
	return 0;
}