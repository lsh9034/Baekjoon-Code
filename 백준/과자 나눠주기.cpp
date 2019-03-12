//정말 문제에서 숫자 범위 체크 잘하자... 정 짜증나면 그냥 문제 범위 좀 크다 싶으면 인풋배열 받는거 빼고는 싹다 longlong하면 
//생각할거리가 줄어들긴한다. 이거 때문에 3번 틀렸다. 18
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int Data[1000001];
int N, M;
long long sum;
int main(void)
{
	ios::sync_with_stdio(false);
	cin>>N>>M;
	//Data.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> Data[i];
		sum += Data[i];
	}
	long long e = sum / M, s = 1;
	int answer = 0;
	while (s <= e)
	{
		long long m = (s + e) / 2;
		long long cnt = 0;
		for (int i = 0; i < N; i++)
			cnt += Data[i] / m;
		if (cnt >= M)
		{
			s = m + 1;
			answer = m;
		}
		else
			e = m - 1;
	}
	cout << answer;
	//while (1);
	return 0;
}