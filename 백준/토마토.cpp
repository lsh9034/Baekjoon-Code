#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

int map[1001][1001];
int m, n;
struct Data
{
	int i, j, cnt;
	Data(int i, int j, int cnt)
	{
		this->i = i;
		this->j = j;
		this->cnt = cnt;
	}
};
bool isMap(int i, int j)
{
	if (i < 0 || i >= n || j < 0 || j >= m)
		return false;
	return true;
}
int main(void)
{
	//freopen("input.txt", "r", stdin);
	cin >> m >> n;
	queue<Data> q;
	int answer = -1;
	int direction[4][2] = {
		{ 0,-1 },{ 1,0 },{ 0,1 },{ -1,0 }
	};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				q.push(Data(i, j, 0));
		}
	}
	while (!q.empty())
	{
		Data tomato = q.front();
		q.pop();
		if (tomato.cnt > answer)
			answer = tomato.cnt;

		for (int i = 0; i < 4; i++)
		{
			int x = tomato.j + direction[i][0];
			int y = tomato.i + direction[i][1];
			if (isMap(y, x) && map[y][x] == 0)
			{
				map[y][x] = 1;
				q.push(Data(y, x, tomato.cnt + 1));
			}

		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
				answer = -1;
		}
	}
	cout << answer << endl;
	return 0;
}