#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int dp[21][1 << 20];
int Data[21] = { 0, };

int n, a, b, m;
pair<int, int> Move(int wallroom, int pos,int t)
{
	int zero_idx = -1;
	for (int i = pos; i < n&&i >= 0; i += t)
	{
		if ((wallroom&(1 << i)) == 0)
		{
			zero_idx = i;
			break;
		}
	}
	if (zero_idx == -1)return make_pair(0, -1); //오른쪽이나 왼쪽으로 밀 수 없을 떄
	for (int i = zero_idx; i !=pos; i -= t)
	{
		wallroom |= (1 << i);
	}
	wallroom &= ~(1<< pos);
	return make_pair(wallroom, abs(pos - zero_idx));
}
int main(void)
{
	scanf("%d %d %d %d", &n, &a, &b, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &Data[i]);
	int total = (1 << n) - 1;
	int wallroom = total;
	wallroom &= ~(1 << (a - 1));
	wallroom &= ~(1 << (b - 1));
	int s = total - (1 << n - 1) - (1 << n - 2); //원소를 제거하는 2가지 방법을 모두 써봤음 단 빼는건 해당 비트가 무조건 1이여야지 가능한거임 따라서 위에가 더 안전함.
	int e = total - 3;
	dp[0][wallroom] = 1; //다른 숫자들이 0이라서 1로 해준거임 사실 이동한 횟수는 0임 나중에 -1시키고 출력하면 됨.
	for (int i = 0; i < m; i++)
	{
		int pos = Data[i + 1] - 1;
		for (int j = s; j <= e; j++)
		{
			if (dp[i][j])
			{
				pair<int, int> moveL = Move(j, pos, 1);
				pair<int, int>moveR = Move(j, pos, -1);
				if (moveL.second != -1)
				{
					if (dp[i + 1][moveL.first])
						dp[i + 1][moveL.first] = min(dp[i + 1][moveL.first], dp[i][j] + moveL.second);
					else
						dp[i + 1][moveL.first] = dp[i][j] + moveL.second;
				}
				if (moveR.second != -1)
				{
					if (dp[i + 1][moveR.first])
						dp[i + 1][moveR.first] = min(dp[i + 1][moveR.first], dp[i][j] + moveR.second);
					else
						dp[i + 1][moveR.first] = dp[i][j] + moveR.second;
				}
			}
		}
	}
	int answer = 987654321;
	for (int i = s; i <= e; i++)
	{
		if (answer > dp[m][i] && dp[m][i]!=0)
			answer = dp[m][i];
	}
	printf("%d", answer - 1);
	return 0;
}