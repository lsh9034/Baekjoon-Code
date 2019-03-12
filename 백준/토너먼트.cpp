#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int n;
	int a, b;
	scanf("%d %d %d", &n, &a, &b);
	
	int max = a > b ? a : b;
	int min = a < b ? a : b;
	int count = 0;
	while (1)
	{
		count++;
		if (min + 1 == max && min % 2 == 1)
			break;

		if (min % 2 == 1)
			min = (min + 1) / 2;
		else
			min /= 2;
		if (max % 2 == 1)
			max = (max + 1) / 2;
		else
			max /= 2;
	}
	printf("%d", count);
	return 0;
}
