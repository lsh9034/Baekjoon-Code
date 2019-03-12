#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int N, K, W;
		int time[1001][2] = { 0, };
		vector<int>data[1001];
		int end_num[1001] = { 0, };
		queue<int> q;
		int max_time[1001] = { 0, };
		int answer = 0;
		scanf("%d %d", &N, &K);
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &time[j][0]);
		}
		for (int j = 1; j <= K; j++)
		{
			int s, e;
			scanf("%d %d", &s, &e);
			data[s].push_back(e);
			end_num[e]++;
		}
		scanf("%d", &W);
		for (int j = 1; j <= N; j++)
		{
			if (end_num[j] == 0)
			{
				q.push(j);
				time[j][1] = time[j][0];
			}
		}
		while (!q.empty())
		{
			int s = q.front();
			q.pop();
			if (s == W)break;
			for (int j = 0; j < data[s].size(); j++)
			{
				end_num[data[s][j]]--;
				if (time[data[s][j]][1] < time[s][1])
					time[data[s][j]][1] = time[s][1];

				if (end_num[data[s][j]] == 0)
				{
					q.push(data[s][j]);
					time[data[s][j]][1] += time[data[s][j]][0];
				}
			}
		}
		printf("%d\n", time[W][1]);
	}
	return 0;
}