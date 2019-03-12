#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int dp[1001][1001];

int main(void)
{
	int n;
	int data[1001];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &data[i]);

	for (int i = 1; i <= n; i++)
	{
		int cost = data[i];
		for (int j = 1; j <= n; j++)
		{
			if (j - i < 0)dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j] > dp[i][j - i] + cost ? dp[i - 1][j] : dp[i][j - i] + cost;
		}
	}
	int max = -1;
	printf("%d", dp[n][n]);
	return 0;
}