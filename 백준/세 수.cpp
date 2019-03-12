#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int in[3] = { 0, };
	for (int i = 0; i < 3; i++)
		cin >> in[i];
	sort(in, in + 3);
	cout << in[1];
	return 0;
}