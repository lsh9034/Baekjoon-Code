#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;
int main(void)
{
	int n;
	int data[1010][3] = { 0, };
	vector<int> dp[1010];
	dp[0].resize(3, 0);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &data[i][0], &data[i][1], &data[i][2]);
		dp[i].resize(3, 987654321);
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (j == k)continue;
				if (dp[i][j] > data[i][j] + dp[i - 1][k])dp[i][j] = data[i][j] + dp[i - 1][k];
			}
		}
	}
	int min = 987654321;
	for (int i = 0; i <= 2; i++)
	{
		if (dp[n][i] < min)min = dp[n][i];
	}
	printf("%d", min);
	return 0; 
}