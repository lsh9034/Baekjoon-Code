#include<iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	n--;
	for (int i = 1; i <= n; i++)
	{
		if (i*(i + 1) == n)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}