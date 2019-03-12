//´Ù½Ã Çª»ï
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, L, K;
		cin >> N >> L >> K;
		vector<pair<int, int>>data;
		int ant[100000] = { 0, };
		int r = 0, l = 0;
		for (int i = 0; i < N; i++)
		{
			int pos, id;
			cin >> pos >> id;
			ant[r++] = id;
			if (id < 0)
				data.push_back(make_pair(pos, id));
			else
				data.push_back(make_pair(L - pos, id));
		}
		sort(data.begin(),data.end());
		r--;
		int count = 0;
		vector<int> log;
		for (int i = 0; i < K; i++)
		{
			if (data[i].first != data[i+1].first)
			{
				count++;
				int a = data[i].second;
				if (a < 0)
					log.push_back(ant[l++]);
				else
					log.push_back(ant[r--]);
			}
			else
			{
				int a = ant[l++];
				int b = ant[r--];
				if (a < b)
				{
					log.push_back(a);
					log.push_back(b);
				}
				else
				{
					log.push_back(b);
					log.push_back(a);
				}
				i++;
			}
		}
		cout << log[K - 1] << endl;
	}
	return 0;
}