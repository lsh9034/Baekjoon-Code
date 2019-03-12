#include<iostream>
#include<algorithm>
using namespace std;

char buf[1110000];

inline int readint()
{
	static int i = 0;
	bool flag = false;
	if (buf[i] == '-')
	{
		i++;
		flag = true;
	}
	int n = buf[i++] - '0';
	while (buf[i] >= '0')
	{
		n *= 10;
		n += buf[i++] - '0';
	}
	i++;
	if (flag)
		n = -n;
	return n;
}


int main(void)
{
	fread(buf, 1, sizeof(buf), stdin);
	int Data[100000];
	int n = readint();
	for (int i = 0; i < n; i++)
		Data[i] = readint();
	sort(Data, Data + n);
	int l = 0, r = n - 1;
	int answer[2] = { Data[l],Data[r] };
	while (l < r)
	{
		if (abs(answer[0] + answer[1]) > abs(Data[l] + Data[r]))
		{
			answer[0] = Data[l];
			answer[1] = Data[r];
		}
		if (Data[l] + Data[r] > 0)
			r--;
		else if (Data[l] + Data[r] < 0)
			l++;
		else
			break;
	}
	printf("%d %d", answer[0], answer[1]);
	//while (1);
	return 0;
}