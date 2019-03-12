#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

int n;
long long Data[5001];

int binary_Search(int L, int R, int t)
{
	int s = L;
	int e = R;
	long long dt = 100000000000;
	int answer = 0;
	while (s <= e)
	{
		int m = (s + e) / 2;
		
		if (dt > abs(Data[m] - t))
		{
			dt = abs(Data[m] - t);
			answer = Data[m];
		}
		if (Data[m] < t)
			s = m + 1;
		else if (Data[m] > t)
			e = m - 1;
		else
			return Data[m];
	}
	return answer;
}
int main(void)
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &Data[i]);
	sort(Data, Data + n);
	long long answer[3] = { Data[0],Data[1],Data[2] };
	for(int i=0; i<n; i++)
	{
		for (int j = i + 2; j < n; j++)
		{
			int t = (Data[i] + Data[j]);
			t = binary_Search(i + 1, j - 1, -t);
			if (abs(Data[i] + Data[j] + t) < abs(answer[0] + answer[1] + answer[2]))
			{
				answer[0] = Data[i];
				answer[1] = t;
				answer[2] = Data[j];
			}
		}
	}
	printf("%lld %lld %lld", answer[0], answer[1], answer[2]);
	//while (1);
	return 0;
}