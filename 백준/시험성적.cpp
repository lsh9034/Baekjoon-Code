#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	char answer = (99 - n) / 10 + 'A';
	if (answer >= 'E')
		cout << 'F';
	else
		cout << answer;
	while (1);
	return 0;
}