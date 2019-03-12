//주석 쳐놓은 곳으로 바꿔해도 맞음 두 가지 방법 다 해봄
#include<iostream>
#include<queue>
#include<stdlib.h>
#include<functional>
using namespace std;

struct s
{
	int a, b;
	s(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
};
bool operator<(s i, s j)
{
	if(j.a!=i.a)return j.a < i.a;
	return j.b < j.a;
}
int main(void)
{
	//priority_queue<pair<int,int>,vector<pair<int, int>>,greater<pair<int,int>>> pq;
	priority_queue<s> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		/*if (temp < 0)pq.push(pair<int, int>(-temp, temp));
		else pq.push(pair<int, int>(temp, temp));*/
		if (temp == 0)
		{
			if (pq.size())
			{
				cout << pq.top().b << endl;
				pq.pop();
			}
			else cout << "0" << endl;
		}
		else if (temp < 0)pq.push(s(-temp, temp));
		else pq.push(s(temp, temp));
	}
	return 0;
}