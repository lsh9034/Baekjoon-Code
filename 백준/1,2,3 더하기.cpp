#include<iostream>
using namespace std;

int answer = 0;
void sol(int sum, int n)
{
	if (sum > n)return;
	if (sum == n)
	{
		answer++;
		return;
	}
	for (int i = 1; i <= 3; i++)
	{
		sol(sum + i, n);
	}
}
int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		sol(0, n);
		cout << answer << endl;
		answer = 0;
	}
	return 0;
}