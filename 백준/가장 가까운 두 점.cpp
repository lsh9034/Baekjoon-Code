#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<set>
#include<limits.h>
using namespace std;
typedef vector<pair<int, int>> vii;

int n;
int distance(pair<int, int>a, pair<int, int>b)
{
	int dx = a.first - b.first;
	int dy = a.second - b.second;
	return dx * dx + dy * dy;
}
set<pair<int, int>> s;
int main(void)
{
	cin >> n;
	vii Data(n);
	for (int i = 0; i < n; i++)
		cin >> Data[i].first >> Data[i].second;
	sort(Data.begin(), Data.end());
	int min_d = INT_MAX;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		while (cnt < i)
		{
			int d = Data[i].first - Data[cnt].first;
			d = d * d;
			if (min_d < d)
			{
				s.erase(Data[cnt]);
				cnt++;
			}
			else
				break;
		}
		auto l = s.lower_bound({ -2e9,Data[i].second - min_d });
		auto r = s.upper_bound({ 2e9,Data[i].second + min_d });
		for (l; l != r; l++)
		{
			pair<int, int>p((*l).second, (*l).first);
			int d = distance(Data[i], p);
			if (d < min_d)
				min_d = d;
		}
		s.insert(make_pair(Data[i].second, Data[i].first));
	}
	cout << min_d;
}