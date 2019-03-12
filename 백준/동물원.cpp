#include<iostream>
using namespace std;
int main(void)
{
	int n;
	int dp[3] = { 1,1,1};
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a = (dp[0] + dp[1] + dp[2])%9901;
		int b = (dp[0] + dp[1]) % 9901;
		int c = (dp[0] + dp[2]) % 9901;
		dp[0] = a; dp[1] = b; dp[2] = c;
	}
	cout << (dp[0] + dp[1] + dp[2]) % 9901;
	return 0;
}