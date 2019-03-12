#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int n;
	int pre_data[10] = { 1,2,2,2,2,2,2,2,2,1 };
	long long pre_num[10] = { 0,1,1,1,1,1,1,1,1,1 };
	scanf("%d", &n);
	if (n == 1)
	{
		printf("9");
		return 0;
	}
	int count = 0;
	for (int i = 2; i <= n; i++)
	{
		count = 0;
		long long num[10] = { 0, };
		for (int j = 0; j <= 9; j++)
		{
			count = (count + (pre_num[j] * pre_data[j])) % 1000000000;
			if (j == 0)
				num[1] += pre_num[0];
			else if (j == 9)
				num[8] += pre_num[9];
			else
			{
				num[j - 1] += pre_num[j];
				num[j + 1] += pre_num[j];
			}
		}
		for (int j = 0; j <= 9; j++)pre_num[j] = num[j] % 1000000000;
	}
	printf("%d\n", count);
	return 0;
}