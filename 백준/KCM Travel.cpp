#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
typedef pair<int, int> pii;

class Data
{
public:
	int v, c, d;
	Data(int v,int c,int d)
	{
		this->v = v;
		this->c = c;
		this->d = d;
	}
	bool operator < (const Data& j)const
	{
		return { this->d > j.d };
	}
};
vector<Data>graph[101];
vector<vector<int>> dp;
int N, M, K;

void dijkstra(int u)
{
	priority_queue<Data> pq;
	pq.push(Data(u,0,0));
	dp[u].clear();
	dp[u].resize(M + 1, 0);
	while (!pq.empty())
	{
		Data temp = pq.top();
		int u = temp.v;
		int time = temp.d;
		int cost = temp.c;
		pq.pop();
		if (time > dp[u][cost])
			continue;
		for (int i = 0; i < graph[u].size(); i++)
		{
			Data e = graph[u][i];
			if (cost + e.c <= M)
			{
				if (dp[e.v][cost + e.c] > dp[u][cost] + e.d)
				{
					dp[e.v][cost + e.c] = dp[u][cost] + e.d;
					pq.push(Data(e.v, cost + e.c, dp[e.v][cost + e.c]));
				}
			}
		}
	}
}
int main(void)
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M >> K;
		dp.resize(N + 1, vector<int>(M + 1, INT_MAX));

		for (int i = 0; i < K; i++)
		{
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			graph[u].push_back(Data(v, c, d));
		}
		dijkstra(1);
		
		int answer = INT_MAX;
		for (int i = 1; i <= M; i++)
		{
			if (answer > dp[N][i])
				answer = dp[N][i];
		}
		if (answer == INT_MAX)
			cout << "Poor KCM" << endl;
		else
			cout << answer << endl;

		for (int i = 1; i <= N; i++)
			graph[i].clear();
		dp.clear();
	}
	//while (1);
	return 0;
}
