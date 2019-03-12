//답은 맞게 나오는데 시간초과가 됨 더 짧게 하는 방법은 잘 모르겠음.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int T;
int data[1000000][2];
int main(void)
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &data[i][0], &data[i][1]);
	}
	for (int i = 0; i < T; i++)
	{
		int s = data[i][1] - data[i][0];
		int count = 0;
		int sum = 0;
		bool check = true;
		for (int i = 1; sum < s; i = i + check * 1)
		{
			sum += i;
			count++;
			check = !check;
		}
		printf("%d\n", count);
	}
	return 0;
}