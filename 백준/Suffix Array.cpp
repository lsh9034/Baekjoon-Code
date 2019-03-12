#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>group;
vector<int>perm;
vector<int>Rank;
vector<int>LCP;
int t = 1;
int n;
string S;
bool compare(int a,int b)
{
	if (group[a] != group[b]) return group[a] < group[b];
	return group[a + t] < group[b + t];
}
void lcp()
{
	Rank.resize(n + 1);
	LCP.resize(n + 1);
	for (int i = 0; i < n; i++)
		Rank[perm[i]] = i;

	int len = 0;
	for (int i = 0; i < n; i++)
	{
		int k = Rank[i];
		if (k)
		{
			int j = perm[k - 1];
			while (S[i + len] == S[j + len])
				len++;
			LCP[k] = len;
			if (len)
				len--;
		}
	}

}
int main(void)
{
	cin >> S;
	n = S.size();
	group.resize(n + 1);
	for (int i = 0; i < S.size(); i++)
		group[i] = S[i];
	group[n] = -1;
	perm.resize(n);
	for (int i = 0; i < n; i++)perm[i] = i;
	while (t < n)
	{
		sort(perm.begin(), perm.end(), compare);
		if (t * 2 >= n)break;
		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[0] = 0;
		for (int i = 1; i < n; i++)
		{
			if (compare(perm[i - 1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		}
		group = newGroup;
		t *= 2;
	}
	lcp();
	for (int i = 0; i < n; i++)
		printf("%d ", perm[i] + 1);
	printf("\nx ");
	for (int i = 1; i < n; i++)
		printf("%d ", LCP[i]);
	//while (1);
	return 0;
}