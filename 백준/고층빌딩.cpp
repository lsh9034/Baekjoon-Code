#include<iostream>
using namespace std;

int N, L, R;
long long dp[101][101][101];
int check[101][101][101];
long long dynamic(int n, int l, int r)
{
	if (n <= 0 || n < l || n < r)return 0;
	if (check[n][l][r])return dp[n][l][r];

	int temp = n - 2;
	if (temp < 0)temp = 0;
	dp[n][l][r] = (dynamic(n - 1, l, r)*temp + dynamic(n - 1, l - 1, r) + dynamic(n - 1, l, r - 1)) % 1000000007;
	check[n][l][r] = 1;
	return dp[n][l][r];
}

int main(void)
{
	cin >> N >> L >> R;
	dp[1][1][1] = 1;
	check[1][1][1] = 1;
	int s = dynamic(N, L, R);
	cout << dp[N][L][R];
	return 0; 