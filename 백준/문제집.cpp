#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> Data[32001];
int indegree[32001];
int n, m;

int main(void)
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		Data[s].push_back(e);
		indegree[e]++;
	}
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			pq.push(-i);
	}

	while (!pq.empty())
	{
		int v = -pq.top();
		pq.pop();
		printf("%d ", v);
		for (int i = 0; i < Data[v].size(); i++)
		{
			indegree[Data[v][i]]--;
			if (indegree[Data[v][i]] == 0)
				pq.push(-Data[v][i]);
		}
	}
	return 0;
}