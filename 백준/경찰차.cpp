#include<iostream>
using namespace std;

struct Data
{
	int cost = 0;
	pair<int, int> car1;
	pair<int, int> car2;
};
int N, W;
int incident[1001][2];
Data dp[1001][2];
int cal(int y, int x, pair<int, int> car)
{
	return abs(y - car.first) + abs(x - car.second) + ;
}

int main(void)
{
	cin >> N >> W;
	for (int i = 1; i <= W; i++)
		cin >> incident[i][0] >> incident[i][1];
	dp[0][0].cost = dp[0][1].cost = 0;
	dp[0][0].car1.first = dp[0][0].car1.second = 1;
	dp[0][1].car2.first = dp[0][1].car2.second = N;
	for (int i = 1; i <= W; i++)
	{
		int a = 
	}
}