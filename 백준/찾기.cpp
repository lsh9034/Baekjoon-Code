#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string T, P;
vector<int>pi;
vector<int>pos;
int Count;

void set_PartialMatch()
{
	int m = P.size();
	int begin = 1, match = 0;
	while (begin + match < m)
	{
		if (P[begin + match] == P[match])
		{
			++match;
			pi[begin + match-1] = match;
		}
		else
		{
			if (match == 0)
				++begin;
			else
			{
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
}
void KMP()
{
	set_PartialMatch();
	int n = T.size();
	int m = P.size();
	int begin = 0, match = 0;
	while (begin + match < n)
	{
		if (T[begin + match] == P[match])
		{
			++match;
			if (match == m)
			{
				++Count;
				pos.push_back(begin + 1);
			}
		}
		else
		{
			if (match == 0)
				++begin;
			else
			{
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
}
int main(void)
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	getline(cin, T);
	getline(cin, P);
	pi.resize(P.size(), 0);
	KMP();
	printf("%d\n", Count);
	for (int i = 0; i < pos.size(); i++)
		printf("%d\n", pos[i]);
	//while (1);
	return 0;
}