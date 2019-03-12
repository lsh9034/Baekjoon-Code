//무슨 숫자로 나눈 나머지를 출력할 때 +=을 쓰지말고 = (변수 +ㅁㄴㅇㄻㅇㄹ)%숫자를 쓰도록하자 이것 때문에 계속 틀림.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> Data[100001];
bool check[100001];
long long answer = 0;
long long mod = 1000000007;
//vector<int> cache[100001];
long long DFS(long long root,long long direct_cost)
{
	if (check[root])return 0;
	check[root] = 1;
	long long path_cost = 0;
	long long sum_cost = 0;
	for (int i = 0; i < Data[root].size(); i++)
	{
		if (!check[Data[root][i].first])
		{
			//sum_cost += Data[root][i].second;
			long long temp = DFS(Data[root][i].first, Data[root][i].second) % mod;
			path_cost = (path_cost + sum_cost * temp) % mod;
			sum_cost = (sum_cost + temp) % mod;
		}
	}
	answer = (answer + path_cost + sum_cost)%mod;
	return (sum_cost * direct_cost + direct_cost) % mod;
}
int main(void)
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int s, e,w;
		cin >> s >> e >> w;
		Data[s].push_back(make_pair(e, w));
		Data[e].push_back(make_pair(s, w));
	}
	DFS(1,0);
	cout << answer << endl;
	//while (1);
	return 0;
}