#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> Data[10001];
int num[10001];
int N, M;
int max1 = -1;
int BFS(int V)
{
	if (num[V])
		return num[V];
	vector<int>check(10001, 0);
	queue<pair<int, int>> q;
	q.push(make_pair(V, 1));
	check[V] = 1;
	while (!q.empty())
	{
		pair<int,int> v = q.front();
		num[v.first] = v.second;
		q.pop();
		if (max1 < num[v.first])max1 = num[v.first];
		for (int i = 0; i < Data[v.first].size(); i++)
		{
			if (!check[Data[v.first][i]])
			{
				check[Data[v.first][i]] = 1;
				q.push(make_pair(Data[v.first][i], v.second + 1));
			}
			else if (v.second != num[Data[v.first][i]])
				q.push(make_pair(Data[v.first][i], v.second));
		}
	}
	return num[V];
}
int BFS2(int V)
{
	vector<int>check(10001, 0);
	queue<pair<int, int>> q;
	q.push(make_pair(V, 1));
	check[V] = 1;
	int count = 0;
	while (!q.empty())
	{
		pair<int,int> v = q.front();
		q.pop();
		count++;
		for (int i = 0; i < Data[v.first].size(); i++)
		{
			if (!check[Data[v.first][i]])
			{
				check[Data[v.first][i]] = 1;
				q.push(make_pair(Data[v.first][i], v.second + 1));
			}
		}
	}
	return count;
}
int main(void)
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		Data[e].push_back(s);
	}
	for (int i = 1; i <= N; i++)
	{
		int val = BFS2(i);
		num[i] = val;
		if (max1 < val)
			max1 = val;
	}

	for (int i = 1; i <= N; i++)
	{
		if (num[i] >= max1)
			printf("%d ", i);
	}
	//while (1);
	return 0;
}