#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int X;
	int sum = 0;
	int count = 0;
	int a, b;
	scanf("%d", &X);
	for (int i = 1; sum < X; i++)
	{
		sum += i;
		count++;
	}
	if (count % 2 == 0)
	{
		b = 1;
		a = (count + 1) - b;
		for (sum; sum > X; sum--)
		{
			b++;
			a = (count + 1) - b;
		}
	}
	else
	{
		a = 1;
		b = (count + 1) - a;
		for (sum; sum > X; sum--)
		{
			a++;
			b = (count + 1) - a;
		}
	}
	printf("%d/%d", a, b);
	return 0;
}