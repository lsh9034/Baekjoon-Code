//���� �ᱹ�� 8�������� �̵��Ҷ��� x,y�� �Ÿ��� ū �Ÿ��� �̵��ϸ� �� �ֳ��ϸ� ū�Ÿ��� �̵��ϸ鼭 �����Ÿ��� �밢������ �̵��ϸ� �� �������
//y�Ÿ��� �� ����ٸ� ���� x�Ÿ��� y�Ÿ��� �̵��Ҷ� �밢������ �̵��ϸ鼭 x�Ÿ��� 0���� ����� ������ �Ÿ���  ������ �Ʒ����� �̵��ؼ� ������ �̵��ϸ�
//�� �ؿ� �ڵ� ������ ����
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