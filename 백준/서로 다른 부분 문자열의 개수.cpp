#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int main(void)
{
	string Data;
	unordered_set<string> s;
	cin >> Data;
	int count = 0;
	for (int i = 0; i < Data.size(); i++)
	{
		string temp = "";
		for (int j = i; j < Data.size(); j++)
		{
			temp += Data[j];
			auto f = s.find(temp);
			if (f == s.end())
			{
				s.insert(temp);
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}