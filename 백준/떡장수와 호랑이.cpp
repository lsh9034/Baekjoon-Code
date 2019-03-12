#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> Data[1001];
int answer[1001];
int Count[1001][10];
bool check = false;
void sol(int cnt,int past)
{
	if (cnt == n)
	{
		check = true;
		for (int i = 0; i < n; i++)
			printf("%d\n", answer[i]);
		return;
	}
	for (int i = 0; i < Data[cnt].size(); i++)
	{
		if (past == Data[cnt][i] || Count[cnt][Data[cnt][i]])continue;
		Count[cnt][Data[cnt][i]] = 1;
		Count[cnt][0]++;
		answer[cnt] = Data[cnt][i];
		sol(cnt + 1, answer[cnt]);
		if (check)break;
	}
	if (Count[cnt][0] == Data[cnt].size() && check == false)
	{
		check = true;
		printf("-1");
	}
}
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{
			int a;
			scanf("%d", &a);
			Data[i].push_back(a);
		}
	}
	sol(0, -1);
	return 0;
}