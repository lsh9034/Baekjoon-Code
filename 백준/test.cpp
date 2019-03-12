#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int mod(char *S, int p)
{
	// S는 수를 문자열로 표현한 것, 1324 -> "1324"
	int ret = 0;
	for (int i = 0; S[i]; i++)
	{
		ret = (ret * 10 + (S[i] - '0')) % p;
	}
	return ret;
}

int main(void)
{
	int n = 105;
	char S[4] = "105";
	cout<< mod(S, 200);
	while (1);
	return 0;
}