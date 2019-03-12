#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
typedef pair<int, int> pii;

vector<pii> Data[801];
int A, B, V, E;

vector<int> dist[3];

void dijkstra(int standard,int s)
{
	priority_queue<pii> pq;
	pq.push({ 0,s });
	dist[standard][s] = 0;
	while (!pq.empty())
	{
		pii top = pq.top();
		int cost = -top.first;
		int k = top.second;
		pq.pop();
		if (cost > dist[standard][k])
			continue;
		for (int i = 0; i < Data[k].size(); i++)
		{
			int e = Data[k][i].first;
			int cost = Data[k][i].second;
			if (dist[standard][e] > dist[standard][k] + cost)
			{
				dist[standard][e] = dist[standard][k] + cost;
				pq.push({ -dist[standard][e],e });
			}
		}
	}
}

pii min_cost(int stan)
{
	return dist[stan][A] < dist[stan][B] ?
		make_pair(A, dist[stan][A]) : make_pair(B, dist[stan][B]);
}
int main(void)
{
	//freopen("input.txt", "r", stdin);
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		Data[s].push_back({ e,w });
		Data[e].push_back({ s,w });
	}
	cin >> A >> B;
	for (int i = 0; i < 3; i++)
		dist[i].resize(V + 1, INT_MAX);
	dijkstra(0, 1);
	dijkstra(1, A);
	dijkstra(2, V);
	pii start_cost = min_cost(0);
	pii end_cost = min_cost(2);
	long long answer = min(dist[0][A] + dist[1][B] + dist[2][B], dist[0][B] + dist[1][B] + dist[2][A]);
	if (start_cost.second == INT_MAX || end_cost.second == INT_MAX || dist[1][B] == INT_MAX) //생각해보면 start,end 코스트 변수 필요없긴함.
		cout << -1;
	else
		cout << answer;
	//while (1);
	return 0;
}