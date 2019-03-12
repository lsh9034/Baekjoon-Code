#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int data[501][501] = { 0, };
int dp1[501][501] = { 0, };
int main(void)
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			scanf("%d", &data[i][j]);
		}
	}
	dp1[0][0] = data[0][0];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (dp1[i + 1][j] - data[i + 1][j] < dp1[i][j])dp1[i + 1][j] = dp1[i][j] + data[i + 1][j];
			if (dp1[i + 1][j + 1] - data[i + 1][j + 1] < dp1[i][j])dp1[i + 1][j + 1] = dp1[i][j] + data[i + 1][j + 1];
		}
	}
	int min = -1;
	for (int i = 0; i < n; i++)
	{
		if (min < dp1[n - 1][i])min = dp1[n - 1][i];
	}
	printf("%d", min);
	return 0;
}