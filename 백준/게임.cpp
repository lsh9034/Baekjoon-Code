#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int in[51][51];
string map[51];
int n, m;
int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
int check[51][51];
int max_cnt[51][51];
int V;
bool is_Map(int i, int j)
{
	if (i < 0 || j < 0 || i >= n || j >= m)
		return false;
	return true;
}

void get_in(int a,int b)
{
	int d = map[a][b] - '0';
	check[a][b] = 1;
	V++;
	if (map[a][b] == 'H')return;
	for (int i = 0; i < 4; i++)
	{
		int d_i = d * dir[i][0];
		int d_j = d * dir[i][1];
		if (is_Map(a + d_i, b + d_j))
		{
			in[a + d_i][b + d_j]++;
			if (!check[a + d_i][b + d_j])
			{
				get_in(a + d_i, b + d_j);
			}
		}
	}

}
int Max = -1;
int Count = 0;
void dfs(int a, int b,int cnt)
{
	int d = map[a][b] - '0';
	int m_cnt = max_cnt[a][b];
	Count++;
	if (Max < m_cnt)
		Max = m_cnt;
	if (map[a][b] == 'H')return;
	for (int i = 0; i < 4; i++)
	{
		int d_i = d * dir[i][0];
		int d_j = d * dir[i][1];
		if (is_Map(a + d_i, b + d_j))
		{
			in[a + d_i][b + d_j]--;
			if (max_cnt[a + d_i][b + d_j] < m_cnt + 1)
				max_cnt[a + d_i][b + d_j] = m_cnt + 1;
			if (in[a + d_i][b + d_j] == 0)
				dfs(a + d_i, b + d_j, m_cnt + 1);
		}
		else
		{
			if (Max < m_cnt + 1)
				Max = m_cnt + 1;
		}
	}
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	get_in(0, 0);
	if (in[0][0] != 0)
		cout << -1;
	else
	{
		dfs(0, 0, 0);
		if (Count != V)
			cout << -1;
		else
			cout << Max;
	}
	//while (1);
	return 0;
}