#include<iostream>
#include<string>
using namespace std;

string convert(int n,int b)
{
	if (n <= 0)return "";
	char a = n % b;
	if (a >= 10)
		a += 'A' - 10;
	else
		a += '0';
	return convert(n / b, b) + a;
}
int main(void)
{
	int n, b;
	cin >> n >> b;
	string answer = convert(n, b);
	cout << answer;
	return 0;
}