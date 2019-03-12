#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

struct Data
{
	Data(int i, int j, int c)
	{
		this->i = i;
		this->j = j;
		this->c = c;
	}
	int i, j, c;
};
int n, m;
char map[101][101] = { 0, };
bool isMap(int i, int j)
{
	if (i < 0 || i >= n || j < 0 || j >= m)
		return false;
	return true;
}
int main(void)
{
	freopen("input.txt", "r", stdin);
	int direction[4][2] = {
		{ 0,-1 },{ 1,0 },{ 0,1 },{ -1,0 }
	};

	queue<Data> q;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}
	q.push(Data(0, 0, 1));
	map[0][0] = '0';
	int answer = 987654321;
	while (!q.empty())
	{
		Data pos = q.front();
		q.pop();
		if (pos.i == n - 1 && pos.j == m - 1)
		{
			if (answer > pos.c)
				answer = pos.c;
		}
		for (int k = 0; k < 4; k++)
		{
			int x = pos.j + direction[k][0];
			int y = pos.i + direction[k][1];
			if (isMap(y, x) && map[y][x] == '1')
			{
				map[y][x] = '0';
				q.push(Data(y, x, pos.c + 1));
			}
		}
	}
	cout << answer;
	while (1);
	return 0;
}




