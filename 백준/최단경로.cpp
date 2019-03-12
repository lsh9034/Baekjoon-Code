#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

vector<pair<int,int>> Data[20001];
vector<int> dist(20001,INT_MAX);
int V, E, S;
int main(void)
{
	ios::sync_with_stdio(false), cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> V >> E;
	cin >> S;
	for (int i = 0; i < E; i++)
	{
		int u, e, w;
		cin >> u >> e >> w;
		Data[u].push_back(make_pair(e, w));
	}
	dist[S] = 0;
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, S));
	while (!q.empty())
	{
		pair<int,int> temp = q.top();
		int k = temp.second;
		q.pop();
		if (-temp.first > dist[k])
			continue;
		for (int i = 0; i < Data[k].size(); i++)
		{
			int e = Data[k][i].first;
			int cost = Data[k][i].second;
			if (dist[e] > dist[k] + cost)
			{
				dist[e] = dist[k] + cost;
				q.push(make_pair(-dist[e],e));
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] != INT_MAX)
			printf("%d\n", dist[i]);
		else
			printf("INF\n");
	}
	//while (1);
	return 0;
}
