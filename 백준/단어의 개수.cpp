#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	//freopen("input.txt", "r", stdin);
	string Data;
	getline(cin, Data);
	int count = 0;
	for (int i = 0; i < Data.size(); i++)
	{
		if (Data[i] == ' ')
		{
			if (i == 0 || i == Data.size() - 1)
				continue;
			count++;
		}
	}
	if (Data == " ")
		cout << 0;
	else
		cout << count + 1;
	//while (1);
	return 0;
}