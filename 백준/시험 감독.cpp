#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int Data[1000001];
int main(void)
{
	int n;
	int b, c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &Data[i]);
	scanf("%d %d", &b, &c);
	long long answer = 0;

	answer += n;
	for (int i = 0; i < n; i++)
		Data[i] -= b;
	for (int i = 0; i < n; i++)
	{
		if (Data[i] <= 0)continue;
		if (Data[i] % c == 0)
			answer += Data[i] / c;
		else
			answer += Data[i] / c + 1;
	}
	printf("%lld", answer);
	return 0;
}