#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);
	priority_queue<int> me;
	priority_queue<int> owner;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		me.push(a);
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		owner.push(a);
	}
	int count = 0;
	while (!me.empty())
	{
		if (owner.top() > me.top())
		{
			count++;
			owner.pop();
		}
		me.pop();
	}
	if (count >= (n + 1) / 2)
		printf("YES");
	else
		printf("NO");
	//while (1);
	return 0;
}