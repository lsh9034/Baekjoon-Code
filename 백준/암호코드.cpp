#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
int dp[5001];
int main(void)
{
	string n;
	cin >> n;
	dp[0] = 1; dp[1] = 1;
	if (n[0] == '0')
	{
		cout << 0;
		return 0;
	}
	for (int i = 2; i <= n.size(); i++)
	{
		int present = n[i - 1] - '0';
		int past = n[i - 2] - '0';
		int num = present + past * 10;
		if (present < 0 || present>9 || past < 0 || past>9 || num <= 0)
		{
			cout << 0;
			return 0;
		}
		else if (num <= 26)
		{
			if (present == 0)
				dp[i] = dp[i - 2];
			else if (past == 0)
				dp[i] = dp[i - 1];
			else
				dp[i] = (dp[i - 1] + dp[i - 2])%1000000;
		}
		else
			dp[i] = dp[i - 1];
	}
	cout << dp[n.size()];
	//while (1);
	return 0;
}