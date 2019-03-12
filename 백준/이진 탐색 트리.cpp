#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(void)
{
	printf("%d", 'w');
	int N;
	long long c = 0;
	map<int, int> m;
	scanf("%d", &N);
	m.insert(make_pair(-1, -1));
	m.insert(make_pair(300001, -1));
	for (int i = 0; i < N; i++)
	{
		int x, pre_dep, post_dep, dep;
		scanf("%d", &x);
		auto it = m.lower_bound(x);
		post_dep = it->second;
		pre_dep = (--it)->second;
		dep = pre_dep > post_dep ? pre_dep : post_dep;
		m.insert(make_pair(x, dep + 1));
		c += dep + 1;
		printf("%lld\n", c);
	}
	//while (1);
	return 0;
}