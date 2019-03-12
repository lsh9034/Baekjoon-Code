#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

int len(int a)
{
	int count = 0;
	while (a)
	{
		count++;
		a /= 10;
	}
	return count;
}
int main(void)
{
	int data;
	int m;
	int check[11] = { 0, };
	cin >> data;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		check[a] = 1;
	}

	int answer = 987654321;
	int tum = data - 100;
	if (tum < 0)tum = -tum;
	int size = len(data);
	if (tum <= size)
		printf("%d", tum);

	else
	{
		for (int i = 0; i <= 999999; i++)
		{
			char temp[10];
			sprintf(temp, "%d", i);
			int c = 0;
			for (int j = 0; temp[j] != NULL; j++)
			{
				if (check[temp[j] - '0'])
					c = 1;
			}
			if (!c || i==100)
			{
				int s = strlen(temp);
				if (i == 100)s = 0;
				int t = data - i;
				if (t < 0)t = -t;
				if (s + t < answer)
				{
					answer = s + t;
				}
			}
		}
		printf("%d", answer);
	}
	return 0;
}