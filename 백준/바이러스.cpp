#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int check[101];
int V,E;
vector<int>Data[101];
int main(void)
{
	//freopen("input.txt", "r", stdin);
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int s, e;
		cin >> s >> e;
		Data[s].push_back(e);
		Data[e].push_back(s);
	}
	 
	queue<int> q;
	q.push(1);
	check[1] = 1;
	int count = 0;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 0; i < Data[v].size(); i++)
		{
			if (!check[Data[v][i]])
			{
				check[Data[v][i]] = 1;
				q.push(Data[v][i]);
				count++;
			}
		}
	}
	cout << count << endl;
	//while (1);
	return 0;
}