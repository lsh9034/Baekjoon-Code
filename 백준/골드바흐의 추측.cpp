#include<stdio.h>

int n;
int data[10000];
int s(int a)
{
	if (a == 2)return 1;
	if (a == 1 || a % 2 == 0)return 0;
	for (int i = 3; i*i <= a; i++)
	{
		if (a%i == 0)return 0;
	}
	return 1;
}
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = data[i]/2; j>=2; j--)
		{
			if (s(j))
			{
				if (s(data[i] - j))
				{
					printf("%d %d\n", j, data[i] - j);
					break;
				}
			}
		}
	}
	return 0;
}