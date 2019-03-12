#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
int n_data[500000];
int m_data[500000];
int n, m;

bool binary_search(int cnt)
{
	int s = 0, e = n - 1;
	int m;
	while (s <= e)
	{
		m = (s + e) / 2;
		if (n_data[m] < cnt)s = m + 1;
		else if (n_data[m] > cnt)e = m - 1;
		else return 1;
	}
	return 0;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &n_data[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &m_data[i]);

	std::sort(n_data, n_data + n);
	for (int i = 0; i < m; i++)
	{
		if (binary_search(m_data[i]))printf("1 ");
		else printf("0 ");
	}
	return 0;
}