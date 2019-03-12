#include<iostream>
using namespace std;

int check[10001];

int cal(int n)
{
	int a = n;
	int sum = 0;
	while (a)
	{
		sum += a % 10;
		a /= 10;
	}
	return n + sum;
}

int main(void)
{
	for (int i = 1; i <= 10000; i++)
	{
		int n;
		n = cal(i);
		check[n] = 1;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (!check[i])
			printf("%d\n", i);
	}
	//while (1);
	return 0;
}