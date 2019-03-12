#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int Sum[200001];
int n, m;
int bina(int a)
{
	int s = 0;
	int e = n - 1;
	while (s <= e)
	{
		int m = (s + e) / 2;
		if (a > Sum[m])
			s = m + 1;
		else if (a < Sum[m])
			e = m - 1;
		else
			return m;
	}
	return e;
}
int main(void)
{
	scanf("%d %d", &n, &m);
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		s += a;
		Sum[i] = s;
	}
	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);
		printf("%d\n", bina(a) + 1);
	}
	//while (1);
	return 0;
}