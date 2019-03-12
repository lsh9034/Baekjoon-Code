#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	int data1[100] = { 0, };
	int q[100] = { 0, };
	for (int i = 1; i <= M; i++)
	{
		cin >> data1[i];
	}
	for (int i = 1; i <= N; i++)
	{
		q[i] = i;
	}
	int count = 0;
	for (int i = 1; i <= M; i++)
	{
		int p;
		for (int j = i; j <= N; j++)
		{
			if (data1[i] == q[j])
			{
				p = j;
				break;
			}
		}
		int l = p - 1 - (i - 1);
		int r = N - p + 1; //오른쪽 숫자 갯수뿐만 아니라 해당 숫자를 맨 앞으로 보내야하기 떄문에 +1
		if (l <= r)
		{
			count += l;
			while (l)
			{
				int temp = q[i];
				for (int j = i; j <= N; j++)
					q[j] = q[j + 1];
				q[N] = temp;
				l--;
			}
		}
		else
		{
			count += r;
			while (r)
			{
				int temp = q[N];
				for (int j = N; j >=i; j--)
					q[j] = q[j - 1];
				q[i] = temp;
				r--;
			}
		}
	}
	cout << count << endl;
	return 0;
}