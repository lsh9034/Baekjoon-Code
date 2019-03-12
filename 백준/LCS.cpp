#include<iostream>
#include<string>
using namespace std;

int dp[1001][1001];

int max(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	string origin;
	string compare;
	cin >> origin >> compare;

	for (int i = 1; i <= compare.size(); i++)
	{
		int x = i - 1;
		for (int j = 1; j <= origin.size(); j++)
		{
			int y = j - 1;
			if (origin[y] == compare[x])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[compare.size()][origin.size()] << endl;

	int i = compare.size();
	int j = origin.size();
	string answer = "";
	while (dp[i][j] != 0)
	{
		if (dp[i][j] == dp[i - 1][j])
			i--;
		else if (dp[i][j] == dp[i][j - 1])
			j--;
		else if (dp[i][j] - 1 == dp[i - 1][j - 1])
		{
			answer += compare[i - 1];
			i--;
			j--;
		}
	}
	for (int i = answer.size() - 1; i >= 0; i--)
		cout << answer[i];
	cout << endl;
	return 0;
}