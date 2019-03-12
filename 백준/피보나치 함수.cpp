#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int dp[50][2] = { 0, };
	int T;
	int memo = 1;
	dp[0][0] = 1;
	dp[1][1] = 1;

	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int n;
		scanf("%d", &n);
		if (memo<n)
		{
			for (int i = memo + 1; i <= n; i++)
			{
				dp[i][0] += dp[i - 1][0] + dp[i - 2][0];
				dp[i][1] += dp[i - 1][1] + dp[i - 2][1];
			}
			memo = n;
		}
		printf("%d %d\n", dp[n][0], dp[n][1]);
	}
	return 0;
}