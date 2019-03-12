#include<iostream>
using namespace std;

int main(void)
{
	int n;
	int count = 0;
	cin >> n;
	int N = n;
	while (true)
	{
		int temp = n / 10 + n % 10;
		int a = n % 10 * 10 + temp%10;
		count++;
		if (a == N)
			break;
		n = a;
	}
	cout << count;
	return 0;
}