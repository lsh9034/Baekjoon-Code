#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<math.h>
using namespace std;

int Data[3000000];
int dp[3000000];
int k, N;
long long Max = -1;
long long find_max(int n)
{
	long long left = 0, right = 0;
	if (N >= 2 * n)
	{
		left = find_max(2 * n);
		right = find_max(2 * n + 1);
	}
	dp[n] =  left > right ? left + Data[n] : right + Data[n];
	return dp[n];
}
void sol(int n,int sum)
{
	if (n>N || sum==0)return;
	int big = dp[n];
	Data[n] += sum - big;
	sol(2 * n, sum - Data[n]);
	sol(2 * n + 1, sum - Data[n]);

}
int main(void)
{
	scanf("%d", &k);
	N = pow(2, k + 1) - 1;
	for (int i = 2; i <= N; i++)
		scanf("%d", &Data[i]);
	Max = find_max(1);
	sol(2, Max);
	sol(3, Max);
	int answer = 0;
	for (int i = 2; i <= N; i++)
		answer += Data[i];
	printf("%d", answer);
	//while (1);
	return 0;
}