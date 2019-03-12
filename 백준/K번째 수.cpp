#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Data[5000001];
int N, K;
long long L1 = -1000000010;
long long R1 = 1000000010;

void swap(int i, int j)
{
	int temp = Data[i];
	Data[i] = Data[j];
	Data[j] = temp;
}
int find_mid(int L, int R)
{
	long long pv = (L1 + R1) / 2;
	int a, b;
	int idx = L;
	a = Data[idx];
	for (int i = L + 1; i <= R; i++)
	{
		a = abs(pv - Data[idx]);
		b = abs(pv - Data[i]);
		if (b < a)
			idx = i;
	}
	return idx;
}
int quick_selection(int L, int R)
{
	//if (L >= R)return;
	int mid = find_mid(L, R);
	int pv = Data[mid];
	int l = L;
	int r = R - 1;
	swap(R, mid);
	while (l <= r)
	{
		while (Data[l] < pv)
			l++;
		while (Data[r] > pv && r >L)
			r--;
		if (l >= r)break;
		swap(l, r);
		l++;
		r--;
	}
	swap(l, R);
	if (l == K - 1)
		return Data[l];
	else if (l < K - 1)
	{
		L1 = (L1 + R1) / 2;
		return quick_selection(l + 1, R);
	}
	else if (l > K - 1)
	{
		R1 = (L1 + R1) / 2;
		return quick_selection(L, l - 1);
	}
}
int lownum(int v) {
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (Data[i] <= v)
			res++;
	}
	return res;
}
int main(void)
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> K;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &Data[i]);
	}
	long long l = -1000000010;
	long long r = 1000000010;
	int k = K;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		if (lownum(mid) < k)
			l = mid;
		else
			r = mid;
	}
	printf("%d", r);
	//while (1);
	return 0;
}