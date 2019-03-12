//¡¡¿∫ øπ 10 10 1 2 10 10
#include<iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	int n; 
	int data[10010] = { 0, };
	int dp[10010] = { 0, };
	int maximum = -1;
	int idx = 0;
	int IDX = 0;
	cin >> n;
	for (int i = 3; i < n + 3; i++)
	{
		cin >> data[i];
	}
	for (int i = 3; i < n + 3; i++)
	{
		if (maximum < dp[i - 3])
		{
			maximum = dp[i - 3];
			idx = i - 3;
		}
		dp[i] = max(dp[idx] + data[i - 1] + data[i], dp[i - 2] + data[i]);
	}
	for (int i = n; i < n + 3; i++)
		if (maximum < dp[i])maximum = dp[i];
	cout << maximum << endl;
	return 0;
} 