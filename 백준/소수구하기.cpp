#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int M, N;

int s(int a)
{
	if (a == 2)return 1;
	if (a==1 || a % 2 == 0)return 0;
	for (int i = 3; i*i <= a; i++)
	{
		if (a%i == 0)return 0;
	}
	return 1;
}

int main(void)
{
	scanf("%d %d", &M, &N);

	for (int i = M; i <= N; i++)
	{
		if (s(i))
		{
			printf("%d\n", i);
		}
	}
	return 0;
}