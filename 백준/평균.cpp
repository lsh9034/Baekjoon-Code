#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int n;
	int max = -1;
	vector<int> Data;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int score;
		cin >> score;
		Data.push_back(score);
		if (max < score)
			max = score;
	}
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		double temp = (double)Data[i] / max * 100;
		sum += temp;
	}
	cout << sum / n;
	//while (1);
	return 0;
}