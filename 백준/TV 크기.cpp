#include<iostream>
#include<math.h>
using namespace std;

int main(void)
{
	int n, dx, dy;
	cin >> n >> dx >> dy;
	int s = dx * dx + dy * dy;
	n *= n;
	double unit = (double)n / s;
	double x = sqrt(unit * (dx*dx));
	double y = sqrt(unit*(dy*dy));
	printf("%d %d", (int)x, (int)y);
	return 0;
}