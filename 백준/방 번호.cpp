#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	char n[10] = { 0, };
	int count[10] = { 0, };
	scanf("%s", &n);
	int max = -1, index;
	for (int i = 0; n[i] != NULL; i++)
	{
		int a = ++count[n[i] - '0'];
		if (a > max)
		{
			max = a;
			index = n[i] - '0';
		}
	}
	if (index == 9 || index == 6)
	{
		int temp = count[9] + count[6];
		printf("%d", temp / 2 + temp % 2);
		return 0;
	}
	printf("%d", max);
	//while (1);
	return 0;
}