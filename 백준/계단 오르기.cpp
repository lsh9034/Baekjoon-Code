#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int n;
	int data[500] = { 0, };
	int dp[510][2] = { 0, };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &data[i]);

	dp[n][0] = data[n];
	for (int i = n; i >=2; i--)
	{
		if (dp[i - 2][0] < dp[i][0] + data[i - 2] && dp[i][0]!=0)
			dp[i - 2][0] = dp[i][0] + data[i - 2];

		if (dp[i - 1][1] < dp[i][0] + data[i - 1] && dp[i][0] != 0)
			dp[i - 1][1] = dp[i][0] + data[i - 1];

		if (dp[i - 2][0] < dp[i][1] + data[i - 2] && dp[i][1] != 0)
			dp[i - 2][0] = dp[i][1] + data[i - 2];
	}
	int a = dp[1][0] > dp[1][1] ? dp[1][0] : dp[1][1];
	int b = dp[2][0] > dp[2][1] ? dp[2][0] : dp[2][1];
	printf("%d", a > b ? a : b);
	return 0;
}