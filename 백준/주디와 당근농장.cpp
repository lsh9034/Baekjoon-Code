#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
char map[101][101] = { 0, };
int n, r, c;

bool isMap(int i, int j)
{
	if (i < 1 || i > n || j < 1 || j > n)
		return false;
	return true;
}
int main(void)
{
	//freopen("input.txt", "r", stdin);
	cin >> n >> r >> c;
	queue<pii> q;
	int answer = -1;
	int direction[4][2] = {
		{ -1,-1 },{ -1,1 },{ 1,1 },{ 1,-1 }
	};
	map[r][c] = 'v';
	q.push(make_pair(r, c));
	while (!q.empty())
	{
		pii tomato = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int y = tomato.first + direction[i][0];
			int x = tomato.second + direction[i][1];
			if (isMap(y, x) && map[y][x] == 0)
			{
				map[y][x] = 'v';
				q.push(make_pair(y,x));
			}

		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 0)
				printf(".");
			else
				printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}