#include<iostream>
using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0)return a;
	return gcd(b, a%b);
}
int main(void)
{
	long long a, b;
	cin >> a >> b;
	long long m = gcd(a, b);
	for (long long i = 0; i < m; i++)
		printf("1");
	return 0;

}