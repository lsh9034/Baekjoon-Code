#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int pos_in[1000001];
int pos_pre[1000001];
int Data[1000001];

int get_mid(int l,int r)
{
	if (l > r)return -1;
	int min = 987654321, answer;
	for (int i = l; i <= r; i++)
	{
		if (min > pos_pre[Data[i]])
		{
			min = pos_pre[Data[i]];
			answer = Data[i];
		}
	}
	return answer;
}

void tree(int l,int r,int m)
{
	if (l > m)return;
	int l_m = get_mid(l, m - 1);
	int r_m = get_mid(m + 1, r);
	if(l_m!=-1)
		tree(l, m-1, pos_in[l_m]);
	if(r_m!=-1)
		tree(m + 1, r, pos_in[r_m]);
	printf("%d\n", Data[m]);
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	int v, cnt = 0, root;
	while (scanf("%d", &v) != EOF)
		Data[cnt++] = v;
	root = Data[0];
	for (int i = 0; i < cnt; i++)
		pos_pre[Data[i]] = i;
	sort(Data, Data + cnt);
	for (int i = 0; i < cnt; i++)
		pos_in[Data[i]] = i;
	tree(0, cnt - 1, pos_in[root]);
	//while (1);
	return 0;
}