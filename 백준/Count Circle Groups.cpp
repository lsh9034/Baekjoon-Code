#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Data
{
	int x, y, r;
	Data(int x, int y, int r)
	{
		this->x = x;
		this->y = y;
		this->r = r;
	}
};
int T;

int sol(vector<Data> input,int n)
{
	vector<int> graph[3000];
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int x = (input[i].x - input[j].x);
			x *= x;
			int y = (input[i].y - input[j].y);
			y *= y;
			int r = input[i].r + input[j].r;
			r *= r;
			if (r >= x + y)
			{
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	int check[3001] = { 0, };
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (check[i] == 0)
		{
			count++;
			queue<int> q;
			q.push(i);
			while (!q.empty())
			{
				int v = q.front();
				q.pop();
				for (int k = 0; k < graph[v].size(); k++)
				{
					if (!check[graph[v][k]])
					{
						check[graph[v][k]] = 1;
						q.push(graph[v][k]);
					}
				}
			}
		}
	}
	return count;
}
int main(void)
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		vector<Data> input;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			int x, y, r;
			cin >> x >> y >> r;
			input.push_back(Data(x, y, r));
		}
		cout << sol(input, N) << endl;
	}
	//while (1);
	return 0;
}
