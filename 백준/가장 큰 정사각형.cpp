#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

char input[1001][1001];
int data[1001][1001];
int dp[1001][1001];//0은 가로 1은 세로
int m, n;
int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &input[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			data[i + 1][j + 1] = input[i][j]-'0';
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (data[i][j] == 0)continue;
			if (data[i][j] == 1)dp[i][j] = 1;
			int s = dp[i][j - 1] > dp[i - 1][j] ? dp[i - 1][j] : dp[i][j - 1];
			s = s > dp[i - 1][j - 1] ? dp[i - 1][j - 1] : s;
			dp[i][j] = s + 1;
			if (max < dp[i][j])max = dp[i][j];
		}
	}
	printf("%d", max*max);
	return 0;
}