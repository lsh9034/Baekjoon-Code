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
	if (zero_idx == -1)return make_pair(0, -1); //�������̳� �������� �� �� ���� ��
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
	int s = total - (1 << n - 1) - (1 << n - 2); //���Ҹ� �����ϴ� 2���� ����� ��� ����� �� ���°� �ش� ��Ʈ�� ������ 1�̿����� �����Ѱ��� ���� ������ �� ������.
	int e = total - 3;
	dp[0][wallroom] = 1; //�ٸ� ���ڵ��� 0�̶� 1�� ���ذ��� ��� �̵��� Ƚ���� 0�� ���߿� -1��Ű�� ����ϸ� ��.
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