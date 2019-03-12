#include<iostream>
using namespace std;

int main(void)
{
	int max = -1;
	int num = 0;
	for (int i = 0; i < 4; i++)
	{
		int a, b;
		cin >> a >> b;
		num -= a;
		num += b;
		if (max < num)max = num;
	}
	cout << max;
	return 0;
}