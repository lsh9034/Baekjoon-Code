#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stack>
int main(void)
{
	char data[50];
	std::stack<char> st;
	scanf("%s", &data);
	for (int i = 0; data[i] != NULL; i++)
	{
		int temp = 0;
		st.push(data[i]);
		if (st.top() == ')')
		{
			st.pop();
			if (st.top() == '(')
			{
				st.pop();
				st.push(2);
			}
			else
			{
				while (st.top() != '(')
				{
					if (st.top() == '[')
					{
						printf("0");
						return 0;
					}
					temp += st.top();
					st.pop();
				}
				st.pop();
				st.push(temp * 2);
			}
		}
		else if (st.top() == ']')
		{
			st.pop();
			if (st.top() == '[')
			{
				st.pop();
				st.push(3);
			}
			else
			{
				while (st.top() != '[')
				{
					if (st.top() == '(')
					{
						printf("0");
						return 0;
					}
					temp += st.top();
					st.pop();
				}
				st.pop();
				st.push(temp * 3);
			}
		}
	}
	int count = 0;
	while(st.size())
	{
		if (st.top() == '(' || st.top() == '[' || st.top()==')' || st.top()==']')
		{
			printf("0");
			return 0;
		}
		count += st.top();
		st.pop();
	}
	printf("%d\n", count);
	return 0;
}