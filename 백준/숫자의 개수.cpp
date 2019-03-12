#include<iostream>
using namespace std;

int main(void)
{
	int a, b, c;
	int result;
	int count[10] = { 0, };
	cin >> a >> b >> c;
	result = a * b*c;
	while (result)
	{
		count[result % 10]++;
		result /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << count[i] << endl;
	return 0;
}