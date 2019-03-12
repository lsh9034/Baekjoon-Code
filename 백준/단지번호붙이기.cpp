#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

char map[30][30];
int n;
vector<int> groups;
bool isMap(int i, int j)
{
	if (i < 0 || i >= n || j < 0 || j >= n)
		return false;
	return true;
}
int BFS(int i,int j)
{
	int direction[4][2] = {
		{-1,0},{0,1},{1,0},{0,-1}
	};
	int count = 1;
	queue<pair<int,int>> q;
	q.push(make_pair(i, j));
	map[i][j] = 0;
	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int x = pos.second + direction[k][1];
			int y = pos.first + direction[k][0];
			if (isMap(y, x) && map[y][x] == '1')
			{
				map[y][x] = 0;
				q.push(make_pair(y, x));
				count++;
			}
		}
	}
	return count;
}
int main(void)
{
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '1')
				groups.push_back(BFS(i, j));
		}
	}
	sort(groups.begin(), groups.end());
	cout << groups.size() << endl;
	for (int i = 0; i < groups.size(); i++)
		printf("%d\n", groups[i]);

	//while (1);
	return 0;
}