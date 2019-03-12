#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include <cstdio>
#include <cmath>

int n;
int data[500010];
int check[8010];
int temp[500010];

char buf[1 << 15];
int idx = 1 << 15;

inline char read()
{
	if (idx == 1 << 15)
	{
		fread(buf, 1, 1 << 15, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt()
{
	int sum = 0;
	bool flg = false;
	char now = read();

	while (now == ' ' || now == '\n') now = read();
	if (now == '-') flg = true, now = read();
	while (now >= '0' && now <= '9')
	{
		sum = sum * 10 + now - 48;
		now = read();
	}

	return flg ? -sum : sum;
}

void merge_sort(int s, int e)
{
	if (e <= s)return;
	int m = (s + e) / 2;
	merge_sort(s, m);
	merge_sort(m + 1, e);
	for (int i = s, j = m + 1, cnt = 0; ;)
	{
		if (data[i] < data[j])
		{
			temp[cnt++] = data[i];
			i++;
		}
		else
		{
			temp[cnt++] = data[j];
			j++;
		}
		if (i > m)
		{
			for (j; j <= e; j++)
			{
				temp[cnt++] = data[j];
			}
			break;
		}
		else if (j > e)
		{
			for (i; i <= m; i++)
			{
				temp[cnt++] = data[i];
			}
			break;
		}
	}
	for (int i = s, j = 0; i <= e; i++, j++)data[i] = temp[j];
	return;
}

int main(void)
{
	long long sum = 0, max = -987654321, min = 987654321;
	n = readInt();
	for (int i = 0; i < n; i++)
	{
		data[i] = readInt();
		sum += data[i];
		if (max < data[i])max = data[i];
		if (min > data[i])min = data[i];
		check[data[i] + 4000]++;
		
	}
	int count = 0;
	for (int i = 0; i <= 8000; i++)
	{
		count += check[i];
		if (count > n / 2)
		{
			count = i - 4000;
			break;
		}
	}
	int num[2][2] = { 0, };
	bool c = false;
	for (int i = 0; i <= 8000; i++)
	{
		if (num[0][0] < check[i])
		{
			num[0][0] = check[i];
			num[0][1] = i;
			c = true;
		}
		else if (num[0][0] == check[i] && c)
		{
			num[0][1] = i;
			c = false;
		}
	}
	printf("%.0f\n", (double)sum / n);
	printf("%d\n", count);
	printf("%d\n", num[0][1] - 4000);
	printf("%d\n", max - min);
	//while (1);
	return 0;
}