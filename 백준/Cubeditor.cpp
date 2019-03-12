//pi를 구해야되지만 0번지부터 시작하는 접미사로만 구하는게 아니라 모든 부분문자열이기떄문에 0번지부터 끝까지 시작점을 두면서 접미사를 구하고 이를 
//통해 pi를 구하는 문제 주의할 점은 pi[begin+match-1]에서 대괄호안에 절대 +i를 하면 안됀다는 것이다. 저걸해도 머릿속으로 생각되는 예제들은
//다 통과하지만 예외가 분명있다. 만약 2번지부터 접미사를 구한다고하면 2번지와 3번지가 일치하면 2번째 문자에 대한 pi값이기 때문에 pi[1]에 들어가야된다.
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> pi;
string input;
int Max = 0;
void setPartialMatch()
{
	int m = input.size();
	for (int i = 0; i < m; i++)
	{
		int begin = 1, match = 0;
		while (begin + match + i < m)
		{
			if (input[begin + match] == input[match+i])
			{
				++match;
				pi[begin + match - 1] = match;
				if (Max < match)
					Max = match;
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
		pi.clear();
		pi.resize(m, 0);
	}
}
int main(void)
{
	cin >> input;
	pi.resize(input.size(), 0);
	setPartialMatch();
	cout << Max << endl;
	while (1);
	return 0;
}