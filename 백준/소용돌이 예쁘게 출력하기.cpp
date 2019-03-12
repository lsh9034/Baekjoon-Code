#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int max(int a, int b)
{
	return a > b ? a : b;
}
int value(int a, int b)
{
	int c = abs(a);
	int d = abs(b);
	int m = max(c, d);
	int num = (m * 2 + 1)*(m * 2 + 1);
	int x = m, y = m;
	int count = 0, cut = m * 2;
	bool toggle = 1;
	int toggle2 = 1;
	if (x == a && y == b)return num;
	y--;
	num--;
	while (!(x == a && y == b))
	{
		count++;
		if (count%cut == 0)
		{
			toggle = !toggle;
			if ((count / cut) % 2 == 0)toggle2 = -toggle2;
		}
		y = y - (toggle2*1 * toggle);
		x = x - (toggle2*1 * (1 - toggle));
		num--;
	}
	return num;
}
int data[50][50];
int main(void)
{
	int r1, c1, r2, c2;
	int m = -1;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	int i = r1, j = c1;
	for (int x = r1; x <= r2; x++)
	{
		for (int y = c1; y <= c2; y++)
		{
			int result = value(x, y);
			data[x - i][y - j] = result;
			int count = 0;
			while (result)
			{
				count++;
				result /= 10;
			}
			if (m < count)m = count;
		}
	}
	for (int i = 0; i <= r2 - r1; i++)
	{
		for (int j = 0; j <= c2 - c1; j++)
		{
			printf("%*d ", m, data[i][j]);
		}
		if(i!=r2-r1)printf("\n");
	}
	return 0;
}