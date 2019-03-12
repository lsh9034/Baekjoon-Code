#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int date[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	string day[12] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int n_day = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i++)
		n_day += date[i];
	n_day += m;
	cout << day[n_day % 7];
	//while (1);
	return 0;
}