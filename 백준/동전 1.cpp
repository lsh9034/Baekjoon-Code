#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int dp[2][10010];
int data[101];
int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &data[i]);

	for (int i = 1; i <= n; i++)
	{
		for (int j=1; j <= k; j++)
		{
			if (j < data[i])
				dp[1][j] = dp[0][j];
			else if (j == data[i])
				dp[1][j] = dp[0][j] + 1;
			else
				dp[1][j] = dp[1][j - data[i]] + dp[0][j];
		}
		for (int j = 1; j <= k; j++)
		{
			dp[0][j] = dp[1][j];
			dp[1][j] = 0;
		}
	}
	printf("%d", dp[0][k]);
}