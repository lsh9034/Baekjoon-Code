#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<climits>
#define MAX 10000000000
using namespace std;
typedef pair<int, int> pii;
vector<pii> Data[501];
vector<long long> dist;
int N, M, W;

bool edge_relaxation()
{
	bool ans = false;
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == MAX)continue;
		for (int j = 0; j < Data[i].size(); j++)
		{
			int e = Data[i][j].first;
			int cost = Data[i][j].second;
			if (dist[e] > dist[i] + cost)
			{
				dist[e] = dist[i] + cost;
				ans = true;
			}
		}
	}
	return ans;
}
void Bellman_ford(int v)
{
	dist[v] = 0;
	for (int i = 0; i < N - 1; i++)
	{
		edge_relaxation();
	}
	if (edge_relaxation())
		cout << "-1" << endl;
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == MAX)
				printf("-1\n");
			else
				printf("%lld\n", dist[i]);
		}
	}
}
int main(void)
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	dist.resize(N + 1, MAX);
	for (int i = 0; i < M; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		Data[s].push_back({ e,w });
	}
	Bellman_ford(1);
	//while (1);
	return 0;
}