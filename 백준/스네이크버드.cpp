#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int n, h;
int Data[1001];
int main(void)
{
	scanf("%d %d", &n, &h);
	for (int i = 0; i < n; i++)
		scanf("%d", &Data[i]);
	sort(Data, Data + n);

	for (int i = 0; i < n; i++)
	{
		if (Data[i] <= h)
			h++;
	}
	printf("%d", h);
	return 0;
}
