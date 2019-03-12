#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<deque>
#include<string>
#include<iostream>
int main(void)
{
	std::deque<int> data;
	std::string input;
	int n,a;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> input;
		if (input == "push_back")
		{
			scanf("%d", &a);
			data.push_back(a);
		}
		else if (input == "push_front")
		{
			scanf("%d", &a);
			data.push_front(a);
		}
		else if (input == "pop_front")
		{
			if (data.size() == 0)printf("-1\n");
			else
			{
				printf("%d\n", data.front());
				data.pop_front();
			}
		}
		else if (input == "pop_back")
		{
			if (data.size() == 0)printf("-1\n");
			else
			{
				printf("%d\n", data.back());
				data.pop_back();
			}
		}
		else if (input == "empty")printf("%d\n", data.empty());
		else if (input == "front")
		{
			if (data.size() == 0)printf("-1\n");
			else printf("%d\n", data.front());
		}
		else if (input == "back")
		{
			if (data.size() == 0)printf("-1\n");
			else printf("%d\n", data.back());
		}
		else if (input == "size")printf("%d\n", data.size());
	}
	return 0;
}