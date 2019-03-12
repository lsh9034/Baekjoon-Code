//최소공배수 구하는 식 : a*b/gdc(a,b)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct Data1
{
	int M, N, x, y;
};

Data1 data1;


int gcd(int a, int b)
{
	if (b == 0) return a;

	return gcd(b, a%b);
}

int s(int M,int N,int x,int y)
{
	int max;
	max = gcd(M, N);
	int min;
	min = M*N / max;
	int sol = -1;
	int i = x, j = y;
	while(1)
	{	
		if (i < j)
		{
			i += M;
		}
		else if (j < i)
		{
			j += N;
		}
		else
			return i;
		if (i > min && j > min)
			break;
	}
	return sol;
}

int main(void)
{
	int T;
	int i = 0;
	scanf("%d", &T);
	for (i =0; i < T; i++)
	{
		scanf("%d %d %d %d", &data1.M, &data1.N, &data1.x, &data1.y);
		printf("%d\n", s(data1.M, data1.N, data1.x, data1.y));
	}

	return 0;
}