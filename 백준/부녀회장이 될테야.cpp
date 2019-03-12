#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int T;
int data1[100000][2];
int apart[20][20];

int main(void)
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &data1[i][0], &data1[i][1]);
	}

	for (int i = 1; i <= 14; i++)
		apart[0][i] = i;

	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			apart[i][j] += apart[i - 1][j] + apart[i][j - 1];
		}
	}

	for (int i = 0; i < T; i++)
	{
		printf("%d\n", apart[data1[i][0]][data1[i][1]]);
	}
	return 0;
}