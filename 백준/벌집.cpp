#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n;
	int count = 1;
	int sum = 1;
	scanf("%d", &n);
	for (int i = 1; sum < n; i++)
	{
		sum = sum + i * 6;
		count++;
	}
	printf("%d", count);
	return 0;
}