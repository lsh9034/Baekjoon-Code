#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string Data;
	cin >> Data;
	string answer = "";
	answer += Data[0];
	for (int i = 1; i < Data.size()-1; i++)
	{
		if (Data[i] == '-')
			answer += Data[i + 1];
	}
	cout << answer;
	//while (1);
	return 0;
}
