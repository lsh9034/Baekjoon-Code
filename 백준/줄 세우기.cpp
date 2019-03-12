#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<int> Data[32001];
int num_in[32001];
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		Data[s].push_back(e);
		num_in[e]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (num_in[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		printf("%d ", v);
		for (int i = 0; i < Data[v].size(); i++)
		{
			num_in[Data[v][i]]--;
			if (num_in[Data[v][i]] == 0)
				q.push(Data[v][i]);
		}
	}
	return 0;
}