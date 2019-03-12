#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int gcd(int a, int b)
{
	if (b == 0)return a;
	return gcd(b, a%b);
}

int main(void)
{
	int data[101] = { 0, };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}
	int a = data[0];
	for (int i = 1; i < n; i++)
	{
		int c = gcd(a, data[i]);
		printf("%d/%d\n", a / c, data[i] / c);
	}
	return 0;
}