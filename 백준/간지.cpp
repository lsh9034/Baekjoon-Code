#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);
	
	a -= 4;
	if (a < 0)a += 60;
	printf("%c%d", a % 12 + 'A', a % 10);
	return 0;
}