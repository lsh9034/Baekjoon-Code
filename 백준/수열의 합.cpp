#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
int main(void)
{
	int n;
	int l;
	scanf("%d %d", &n, &l);
	for (int i = l; i <= 100; i++)
	{
		int k = n / i;
		int sum = k;
		int p = 1;
		int data[101] = { 0, };
		int size = 0;
		data[size++] = k;
		for (int j = 2; j <= i; j++)
		{
			sum = sum + (k + p);
			if (sum > n || k+p<0)break;
			data[size++] = k + p;
			if (p < 0)p = p - 1;
			p = -p;
		}
		if (sum == n)
		{
			std::sort(data, data + size);
			for (int j = 0; j < size; j++)
				printf("%d ", data[j]);
			return 0;
		}
	}
	printf("-1");
	return 0;
}