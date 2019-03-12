//어는 말씀 어 임
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<iostream>
int main(void)
{
	char input[200] = { "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv" };
	char output[200] = { "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up" };
	char check[300];
	char data[110] = { 0, };
	for (int i = 0; input[i] != NULL; i++)
	{
		check[input[i]] = output[i];
	}
	check['z'] = 'q';
	check['q'] = 'z';
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{	
		std::cin.getline(data,sizeof(data),'\n');
		for (int i = 0; data[i] != NULL; i++)
		{
			data[i] = check[data[i]];
		}
		printf("Case #%d: %s\n", i + 1, data);
	}
	return 0;
}