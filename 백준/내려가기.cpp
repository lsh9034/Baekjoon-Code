#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

vector<int> max_dp(3);
vector<int> min_dp(3);
int n;
int Min(int a, int b)
{
	return a < b ? a : b;
}
int Max(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int Data[3];
		vector<int> temp_min(3,987654321);
		vector<int> temp_max(3);
		scanf("%d %d %d", &Data[0], &Data[1], &Data[2]);
		for (int j = 0; j < 3; j++)
		{
			for (int k = -1; k < 2; k++)
			{
				if (j + k < 0 || j + k>2)continue;
				temp_min[j] = Min(temp_min[j], min_dp[j + k] + Data[j]);
				temp_max[j] = Max(temp_max[j], max_dp[j + k] + Data[j]);
			}
		}
		min_dp = temp_min;
		max_dp = temp_max;
	}
	int min_an = 987654321, max_an = -1;
	for (int i = 0; i < 3; i++)
	{
		if (min_an > min_dp[i])min_an = min_dp[i];
		if (max_an < max_dp[i])max_an = max_dp[i];
	}
	printf("%d %d", max_an, min_an);
	//while (1);
	return 0;
}
