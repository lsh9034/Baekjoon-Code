//두가지 버전으로 짯음 n^2 dp 그리고 lower_bound를 쓴 nlogn
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dp[1001];
int n;
int Data[1001] = { 0, };
vector<int>answer;
int lower(int k,int n)
{
	int s = 0;
	int e = n - 1;
	while (s < e)
	{
		int m = (s + e) / 2;
		if (answer[m] < k)
			s = m + 1;
		else if (answer[m] > k)
			e = m;
		else
			return m;
	}
	return s;
}
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &Data[i]);
	/*
	fill_n(dp, 1001, 1);
	for (int i = 1; i < n; i++)
	{
	for (int j = 0; j < i; j++)
	{
	if (Data[j] < Data[i])
	dp[i] = max(dp[i], dp[j] + 1);
	}
	}
	int answer = 0;
	for (int i = 0; i < n; i++)
	answer = max(answer, dp[i]);
	printf("%d", answer);
	*/
	answer.push_back(Data[0]);
	for (int i = 1; i < n; i++)
	{
		if (Data[i] > answer.back())
			answer.push_back(Data[i]);
		else
		{
			int k = lower(Data[i],answer.size());
			answer[k] = Data[i];
		}
	}
	printf("%d", answer.size());
	return 0;
}