#include<iostream>
using namespace std;

int dp[101][10][1 << 10];
int main(void)
{
	int n;
	int a = 0;
	cin >> n;
	for (int i = 1; i <= 9; i++)
		dp[1][i][1 << i] = 1;
	int full = (1 << 10) - 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= full; k++)
			{
				if (k == 500)
					a = 2;
				if (dp[i][j][k])
				{
					if (j == 0)
						dp[i + 1][1][(1 << 1) | k] = (dp[i + 1][1][(1 << 1) | k] + dp[i][j][k]) % 1000000000;
					else if (j == 9)
						dp[i + 1][8][(1 << 8) | k] = (dp[i + 1][8][(1 << 8) | k] + dp[i][j][k]) % 1000000000;
					else
					{
						dp[i + 1][j + 1][(1 << (j + 1)) | k] = (dp[i + 1][j + 1][(1 << (j + 1)) | k] + dp[i][j][k]) % 1000000000;
						dp[i + 1][j - 1][(1 << (j - 1)) | k] = (dp[i + 1][j - 1][(1 << (j - 1)) | k] + dp[i][j][k]) % 1000000000;
					}
				}
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 10; i++)
		answer = (answer + dp[n][i][full]) % 1000000000;
	cout << answer;
	return 0;
}