//pi�� ���ؾߵ����� 0�������� �����ϴ� ���̻�θ� ���ϴ°� �ƴ϶� ��� �κй��ڿ��̱⋚���� 0�������� ������ �������� �θ鼭 ���̻縦 ���ϰ� �̸� 
//���� pi�� ���ϴ� ���� ������ ���� pi[begin+match-1]���� ���ȣ�ȿ� ���� +i�� �ϸ� �ȉ´ٴ� ���̴�. �����ص� �Ӹ������� �����Ǵ� ��������
//�� ��������� ���ܰ� �и��ִ�. ���� 2�������� ���̻縦 ���Ѵٰ��ϸ� 2������ 3������ ��ġ�ϸ� 2��° ���ڿ� ���� pi���̱� ������ pi[1]�� ���ߵȴ�.
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