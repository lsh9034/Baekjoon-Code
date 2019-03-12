#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	long long dp[101] = { 0,1,1,1,2,2,3,4,5,7,9,0, };
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int n;
		scanf("%d", &n);
		if (n <= 5)
			printf("%lld\n", dp[n]);
		else
		{
			for (int i = 5; i <= n; i++)
			{
				dp[i] = dp[i - 1] + dp[i - 5];
			}
			printf("%lld\n", dp[n]);
		}
	}
	return 0;
}