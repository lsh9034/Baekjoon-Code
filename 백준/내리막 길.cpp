#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;
int map[502][502] = { 0, };
int count1[502][502] = { 0, };
int dp[502][502] = { 0, };
int direc[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } };
int main(void)
{
	queue<pair<int,int>> q;
	int N, M;
	cin >> M >> N;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (map[i + direc[k][0]][j + direc[k][1]] > map[i][j])
					count1[i][j]++;
			}
			if(count1[i][j]==0)
				q.push(make_pair(i, j));
		}
	}
	dp[1][1] = 1;
	while (!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		int val = dp[i][j];
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			if (map[i + direc[k][0]][j + direc[k][1]] < map[i][j])
			{
				count1[i + direc[k][0]][j + direc[k][1]] -= 1;
				dp[i + direc[k][0]][j + direc[k][1]] += val;
				if (count1[i + direc[k][0]][j + direc[k][1]] == 0)
					q.push(make_pair(i + direc[k][0], j + direc[k][1]));
			}
		}
	}
	cout << dp[M][N] << endl;
	return 0;
}