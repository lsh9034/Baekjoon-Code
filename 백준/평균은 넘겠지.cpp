#include<iostream>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		int Data[1000] = { 0, };
		double avg = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> Data[j];
			avg += Data[j];
		}
		avg = avg / n;
		int answer = 0;
		for (int j = 0; j < n; j++)
		{
			if (Data[j] > avg)
				answer++;
		}
		printf("%.3f%%\n", (double)answer / n * 100);
	}
	//while (1);
	return 0;
}