#include<iostream>
#include<vector>
using namespace std;

pair<double, double>Data[4];
double weight[4][2] = { { 1,1 },{ -1,1 },{ -1,-1 },{ 1,-1 } };
double min_cost = 987654321;
double answer = 0;
double distance(pair<double, double>a, pair<double, double>b)
{
	double dx = abs(a.first - b.first);
	double dy = abs(a.second - b.second);
	return dx + dy;
}
double sol(double x)
{
	pair<double, double> stanPos[4];
	for (int j = 0; j < 4; j++)
	{
		stanPos[j].first = x * weight[j][0];
		stanPos[j].second = x * weight[j][1];
	}
	double check[4] = { 0, };
	double sum = 0;
	for (int j = 0; j < 4; j++)
	{
		double dis = distance(stanPos[j],)
	}
	if (min_cost > sum)
	{
		min_cost = sum;
		answer = x;
	}
	else if (min_cost == sum)
	{
		if (answer < x)
			answer = x;
	}
	return answer;
}
int main(void)
{
	for (int i = 0; i < 4; i++)
		cin >> Data[i].first >> Data[i].second;

	for (int i = 0; i < 4; i++)
	{
		double x = abs(Data[i].first);
		sol(x);
	}
	for (int i = 0; i < 4; i++)
	{
		double y = abs(Data[i].second);
		sol(y);
	}
	if (answer <= 0)
		cout << 1 << endl;
	else
		cout << answer*2 << endl;
	return 0;
}