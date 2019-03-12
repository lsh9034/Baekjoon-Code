#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
int n, m, v;
int data[1001][1001];

void bfs()
{
	std::queue<int> q;
	int check[1001] = { 0, };
	q.push(v);
	check[v] = 1;
	while (!q.empty())
	{
		int s = q.front();
		printf("%d ", s);
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (data[s][i] == 1 && check[i]==0)
			{
				q.push(i);
				check[i] = 1;
			}
		}
	}
}
int dfs_check[1001];
void dfs(int cnt)
{
	printf("%d ", cnt);
	for (int i = 1; i <= n; i++)
	{
		if (data[cnt][i] == 1 && dfs_check[i] == 0)
		{
			dfs_check[i] = 1;
			dfs(i);
		}
	}
	return;
}
int main(void)
{
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		data[s][e] = 1;
		data[e][s] = 1;
	}
	dfs_check[v] = 1;
	dfs(v);
	printf("\n");
	bfs();
	return 0;
}