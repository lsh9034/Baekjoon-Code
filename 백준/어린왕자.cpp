#include<iostream>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int s_x, s_y, e_x, e_y;
		int data1[51][3] = { 0, };
		int n;
		cin >> s_x >> s_y >> e_x >> e_y;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> data1[j][0] >> data1[j][1] >> data1[j][2];

		int count = 0;
		for (int j = 0; j < n; j++)
		{
			int sd_x = data1[j][0] - s_x;
			int sd_y = data1[j][1] - s_y;
			int ed_x = data1[j][0] - e_x;
			int ed_y = data1[j][1] - e_y;
			int r = data1[j][2] * data1[j][2];
			sd_x = sd_x * sd_x;
			sd_y = sd_y * sd_y;
			ed_x = ed_x * ed_x;
			ed_y = ed_y * ed_y;
			if (sd_x + sd_y<r && ed_x + ed_y>r)
				count++;
			else if (sd_x + sd_y > r && ed_x + ed_y < r)
				count++;
		}
		std::cout << count << endl;
	}
	return 0;
}