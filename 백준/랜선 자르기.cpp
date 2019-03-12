#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int k, n;
int Data[10010];
long long sum;
int main(void)
{
	scanf("%d %d", &k,&n);
	//Data.resize(k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &Data[i]);
		sum += Data[i];
	}
	long long s = 1, e = sum / n, m = 0;
	long long answer = -1;
	while (s <= e)
	{
		m = (s + e) / 2;
		long long stick = 0;
		for (int i = 0; i < k; i++)
		{
			stick += Data[i] / m;
		}
		if (stick < n)
			e = m - 1;
		else if (stick >= n)
		{
			if (answer < m)
				answer = m;
			s = m + 1;
		}
	}
	printf("%lld", answer);
	//while (1);
	return 0;
}
