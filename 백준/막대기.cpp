#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	int count = 1;
	int sum = 64;
	int min = 64;
	while (sum!=n)
	{
		int a = min / 2;
		int b = sum - a;
		count++;
		if (b >= n)
		{
			sum = sum - a;
			count--;
		}
		min = a;
	}
	printf("%d", count);
	return 0;
}