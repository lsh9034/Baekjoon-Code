#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int Data[1000001];
int N, M;
int cnt = 0;

void cal(int pos)
{
	if (pos == 0 && !Data[pos + 1])cnt++;
	else if (pos == N && !Data[N - 1])cnt++;
	else if (Data[pos - 1] && Data[pos + 1])
		cnt--;
	else if (Data[pos - 1] == 0 && Data[pos + 1] == 0)
		cnt++;
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		int a;
		scanf("%d", &a);
		if (a)
		{
			cal(i);
			Data[i] = a;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int order;
		scanf("%d", &order);
		if (order == 1)
		{
			int pos;
			scanf("%d", &pos);
			if (!Data[pos])
				cal(pos);
			Data[pos] = 1;
		}
		else
			printf("%d\n", cnt);
	}
	//while (1);
	return 0;
}