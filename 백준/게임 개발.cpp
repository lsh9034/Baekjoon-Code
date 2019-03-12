#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<int>Data[501];
int num_in[501][2] = { 0, };
int costs[501];
int answer[501];
queue<int> q;

int main(void)
{
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int cost, v = 0;
		cin >> cost;
		costs[i] = cost;
		while (true)
		{
			cin >> v;
			if (v == -1)break;
			Data[v].push_back(i);
			num_in[i][0]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (num_in[i][0] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		num_in[v][1] += costs[v];
		answer[v] = num_in[v][1];
		for (int i = 0; i < Data[v].size(); i++)
		{
			num_in[Data[v][i]][0]--;
			if (num_in[Data[v][i]][1] < num_in[v][1])
				num_in[Data[v][i]][1] = num_in[v][1];
			if (num_in[Data[v][i]][0] == 0)
				q.push(Data[v][i]);
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", answer[i]);
	return 0;
}