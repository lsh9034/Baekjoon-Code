#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int n;
int data[100000];
int dp[100000];
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	dp[0] = data[0];

	int max = dp[0];
	for (int i = 1; i < n; i++)
	{
		if (data[i] < dp[i - 1] + data[i])
			dp[i] = dp[i - 1] + data[i];
		else
			dp[i] = data[i];
		if (max < dp[i])max = dp[i];
	}
	printf("%d\n", max);
	return 0;
}