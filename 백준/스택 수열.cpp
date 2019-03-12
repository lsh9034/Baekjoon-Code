#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int n;
int data[100001];
int temp[100001];
char s[654321];
int count;
int num;
int size;
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (i==0 || (i > 0 && data[i - 1] < data[i]))
		{
			for (num; num < data[i]; )
			{
				s[size++] = '+';
				temp[++count] = ++num;
			}
			s[size++] = '-';
			temp[count--] = 0;
		}
		else if (data[i - 1] > data[i])
		{
			if (data[i] == temp[count])
			{
				s[size++] = '-';
				temp[count--] = 0;
			}
			else
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%c\n", s[i]);
	}
	return 0;
}