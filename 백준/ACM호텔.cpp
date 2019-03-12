#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
//#include<Windows.h>
using namespace std;
int T;
int data1[100000][3];

int main(void)
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d", &data1[i][0], &data1[i][1], &data1[i][2]);
	}
	for (int i = 0; i < T; i++)
	{
		int w = data1[i][2] / data1[i][0] + 1;
		int h = data1[i][2] % data1[i][0];
		if (h == 0)
		{
			w--;
			h = data1[i][0];
		}
		std::string s = std::to_string(h);
		if (w < 10)s += "0" + std::to_string(w);
		else s += std::to_string(w);
		cout << s<<endl;
	}
	//system("pause");
	return 0;
}