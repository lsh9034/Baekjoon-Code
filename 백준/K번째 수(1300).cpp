#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	int s = 1, e = k, an = -1;
	while (s <= e)
	{
		int m = (s + e) / 2;
		int count = 0;
		for (int i = 1; i <= n; i++)
			count += min(m / i, n);
		if (count < k)
			s = m + 1;
		else
		{
			an = m;
			e = m - 1;
		}
	}
	cout << an;
	//while (1); 
	return 0;
}