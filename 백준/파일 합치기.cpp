#include<iostream>
#include<string.h>
#include<limits.h>
using namespace std;

int dp[501][501];
int data1[501] = { 0, };
int sum[501] = { 0, };

int min(int a, int b)
{
	return a < b ? a : b;
}
int solve(int s, int e)
{
	if (dp[s][e] != 0x3f3f3f3f)
		return dp[s][e];
	else if (s == e)
		return dp[s][e] = 0;
	else if (s + 1 == e)
		return dp[s][e]=data1[s] + data1[e];

	for (int mid = s; mid < e; mid++)
	{
		solve(s, mid);
		solve(mid + 1, e);
		dp[s][e] = min(dp[s][e], dp[s][mid] + dp[mid + 1][e] + sum[e] - sum[s - 1]);
	}
}

int main(void)
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int K;
		cin >> K;
		for (int i = 1; i <= K; i++)
		{
			cin >> data1[i];
			sum[i] = sum[i - 1] + data1[i];
		}
		for (int d = 1; d <= K - 1; d++)
		{
			for (int i = 1; i <= K - d; i++)
			{
				int j = i + d;
				dp[i][j] = INT_MAX;
				if (i == j)dp[i][j] = 0;
				if (i + 1 == j)dp[i][j] = data1[i] + data1[j];
				for (int k = i; k < j; k++)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
				}
			}
		}
		//memset(dp, 0x3f, sizeof(dp));
		//solve(1, K);
		printf("%d\n", dp[1][K]);
	}
	return 0;
}