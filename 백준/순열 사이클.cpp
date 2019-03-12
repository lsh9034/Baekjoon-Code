#include<iostream>
using namespace std;

void cycle(int a,int (&j)[1010]);

int Data[1010];

int sol(int n)
{
	int check[1010] = { 0, };
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			cycle(i,check);
			count++;
		}
	}
	return count;
}
void cycle(int v,int (&check)[1010])
{
	check[v] = 1;
	while (true)
	{
		if (check[Data[v]])
			break;
		v = Data[v];
		check[v] = 1;
	}
}
int main(void)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		for (int j = 1; j <= N; j++)
			cin >> Data[j];
		int answer = sol(N);
		cout << answer << endl;
	}
	//while (1);
	return 0;
}
