#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main(void)
{
	int S1, S2;
	scanf("%d %d", &S1, &S2);
	for (int i = 0; i < S1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a != b)
		{
			printf("Wrong Answer\n");
			return 0;
		}
	}
	for (int i = 0; i < S2; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a != b)
		{
			printf("Why Wrong!!!\n");
			return 0;
		}
	}
	printf("Accepted\n");
	//while (1);
	return 0;
}