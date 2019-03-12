#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

char data[5000][100];
int n;
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", data[i]);
	}
	for (int i = 0; i < n; i++)
	{
		char stack[100];
		int count = 0;
		for (int j = 0; data[i][j] != NULL; j++)
		{
			if (data[i][j] == '(')stack[count++] = '(';
			else if (data[i][j] == ')')
			{
				if (stack[--count] == '(')
				{
					stack[count] = 0;
				}
				else
				{
					break;
				}
			}
		}
		if (count == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}