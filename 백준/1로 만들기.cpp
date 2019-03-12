#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int n;
int dp[1000010];
int main(void)
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		int two = 987654321, three = 987654321, minus = 987654321;
		if (i % 2 == 0)
			two = dp[i / 2] + 1;
		if (i % 3 == 0)
			three = dp[i / 3] + 1;
		minus = dp[i - 1] + 1;
		int min = two < three ? two : three;
		min = min < minus ? min : minus;
		dp[i] = min;
	}
	printf("%d", dp[n]);
	return 0;
}