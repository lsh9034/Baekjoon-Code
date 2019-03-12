#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#include<Windows.h>
int main(void)
{
	char data[8][4] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	char input[110] = { 0, };
	scanf("%s", &input);
	int count = 0;
	for (int i = 0; input[i] != NULL; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int k;
			for (k = 0; data[j][k] != NULL; k++)
			{
				if (input[i + k] != data[j][k])break;
			}
			if (data[j][k] == NULL)
			{
				i = i + k - 1;
				break;
			}
		}
		count++;
	}
	printf("%d", count);
	//system("pause");
	return 0;
}