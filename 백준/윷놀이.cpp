#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	for (int i = 0; i < 3; i++)
	{
		int count = 0;
		for (int j = 0; j < 4; j++)
		{
			int a;
			scanf("%d", &a);
			if (a == 0)count++;
		}
		if (count == 0)printf("E\n");
		else
			printf("%c\n", 'A' + count - 1);
	}
	return 0;
}