#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string Data;
	cin >> Data;
	printf("%c", Data[0]);
	for (int i = 1; i < Data.size(); i++)
	{
		if (i % 10 == 0)
			printf("\n");
		printf("%c", Data[i]);
	}
	//while (1);
	return 0;
}
