#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	//freopen("input.txt", "r", stdin);
	int n, m;
	int Data[101] = { 0, };
	int Sum[101] = { 0, };
	int dp[101][101] = { 0, };
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &Data[i]);
		Sum[i] = Sum[i - 1] + Data[i];
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			dp[i][j] = -2100000000;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j == 1)
			{
				for (int k = i; k >= 1; k--)
					dp[i][j] = max(dp[i][j], Sum[i] - Sum[k - 1]);
			}
			else
			{
				for (int k = i; k >= 3; k--)
				{
					if (dp[k - 2][j - 1] == -2100000000)continue;
					dp[i][j] = max(dp[i][j], Sum[i] - Sum[k - 1] + dp[k - 2][j - 1]);
				}
			}
		}
	}
	cout << dp[n][m];
	return 0;
}