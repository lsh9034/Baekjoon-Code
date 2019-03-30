#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int t;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		string s;
		int r;
		cin >> r >> s;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j < r; j++)
				cout << s[i];
		}
		cout << "\n";
	}
	return 0;
}