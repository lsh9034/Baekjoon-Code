#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int input[101] = { 0, };
	int factor[1000] = { 0, };
	int f_size = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	sort(input, input + n);
	int tum = input[1] - input[0];
	for (int i = 2; i*i <= tum; i++)
	{
		if (tum%i == 0)
		{
			factor[f_size++] = i;
			if (i != tum / i)
				factor[f_size++] = tum / i;
		}
	}
	factor[f_size++] = tum;
	sort(factor, factor + f_size);
	for (int i = 0; i < f_size; i++)
	{
		int m = input[0] % factor[i];
		int j = 1;
		for (j; j < n; j++)
		{
			if (input[j] % factor[i] != m)
				break;
		}
		if (j == n)cout << factor[i] << " ";
	}
	return 0;
}
