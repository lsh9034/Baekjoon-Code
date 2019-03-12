#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		int a;
		scanf("%d", &a);
		sum += (a + 1) / 2;
	}
	if (sum >= n)
		printf("YES");
	else
		printf("NO");
	//while (1);
	return 0;
}