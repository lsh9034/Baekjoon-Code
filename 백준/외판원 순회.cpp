#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

int n, allVisit;
int Data[20][20];
int dp[20][1 << 16];
int sol(int e, int path)
{
	if (path == allVisit)
	{
		if (Data[e][0] == 0)
			return 987654321;
		else
			return Data[e][0];
	}
	int &ref = dp[e][path];
	if (ref != 0)
		return ref;
	int m = INT_MAX - 17000000;
	for (int i = 1; i < n; i++)
	{
		if (((path&(1 << i)) == 0) && Data[e][i] != 0)
			m = min(m, sol(i, path | (1 << i)) + Data[e][i]);
	}
	ref = m;
	return ref;
}
int main(void)
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	allVisit = (1 << n) - 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &Data[i][j]);
	int answer = sol(0, 1);
	printf("%d", answer);
	//while (1);
	return 0;
}