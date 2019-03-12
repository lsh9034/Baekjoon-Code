//ㅆㅂ 결국에 8방향으로 이동할때는 x,y의 거리중 큰 거리만 이동하면 됨 왜냐하면 큰거리를 이동하면서 작은거리는 대각선으로 이동하면 됨 예를들어
//y거리가 더 길었다면 작은 x거리는 y거리를 이동할때 대각선으로 이동하면서 x거리를 0으로 만들고 나머지 거리는  위던지 아래던지 이동해서 나머지 이동하면
//됨 밑에 코드 개쓰렉 ㅆㅂ
#include<iostream>
using namespace std;
typedef pair<int, int> pii;

int main(void)
{
	pii Data[3];
	for (int i = 0; i < 3; i++)
		cin >> Data[i].first >> Data[i].second;
	int d = abs(Data[2].first - Data[1].first) + abs(Data[2].second - Data[1].second);
	int b = 0;
	int temp_y = abs(Data[0].first - Data[2].first);
	int temp_x = abs(Data[0].second - Data[2].second);
	if (temp_y < temp_x)
	{
		b += temp_y;
		Data[0].first = Data[2].first;
		Data[0].second = Data[0].second +  temp_x / (Data[2].second - Data[0].second) * temp_y;
	}
	else
	{
		b += temp_x;
		Data[0].second = Data[2].second;
		Data[0].first += temp_y / (Data[2].first - Data[0].first) * temp_x;
	}
	b+= abs(Data[2].first - Data[0].first) + abs(Data[2].second - Data[0].second);
	if (b < d)
		cout << "bessie";
	else if (d < b)
		cout << "daisy";
	else
		cout << "tie";
	return 0;
}