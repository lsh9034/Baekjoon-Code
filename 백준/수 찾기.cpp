#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Data;
int n;

bool Binary_search(int a)
{
	int s = 0;
	int e = n - 1;
	while (s <= e)
	{
		int m = (s + e) / 2;
		if (Data[m] == a)
			return true;
		else if (Data[m] < a)
			s = m + 1;
		else
			e = m - 1;
	}
	return false;
}
int main(void)
{
	scanf("%d", &n);
	Data.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &Data[i]);
	sort(Data.begin(), Data.end());
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int a;	
		scanf("%d", &a);
		printf("%d\n", Binary_search(a));
	}
	//while (1);
	return 0;
}