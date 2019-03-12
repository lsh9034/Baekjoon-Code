#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string input;
	cin >> input;
	int sum = 0;
	for (int i = 0; i < input.size(); i++)
		sum += input[i] - '0';
	cout << sum;
	return 0;
}