#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int dp[1001][1001];
vector<pair<int,int> > Data_car1;
vector<pair<int,int> > Data_car2;
int n,w;
vector<int>answer;
int func(int car1,int car2)
{
	if(car1==w||car2==w)
		return 0;
	int &ref = dp[car1][car2];
	if(ref!=-1)
		return ref;
	
	int next=max(car1,car2)+1;
	int move_car1 = func(next,car2)+abs(Data_car1[next].first - Data_car1[car1].first)+abs(Data_car1[next].second - Data_car1[car1].second);
	int move_car2 = func(car1,next)+abs(Data_car2[next].first-Data_car2[car2].first)+abs(Data_car2[next].second - Data_car2[car2].second);

	return ref = min(move_car1,move_car2);
}
void number(int car1,int car2)
{

	if(car1==w||car2==w)
		return;

	int next=max(car1,car2)+1;
	int move_car1 = dp[next][car2]+abs(Data_car1[next].first - Data_car1[car1].first)+abs(Data_car1[next].second - Data_car1[car1].second);
	int move_car2 = dp[car1][next]+abs(Data_car2[next].first-Data_car2[car2].first)+abs(Data_car2[next].second - Data_car2[car2].second);
	if(move_car1<move_car2)
	{
		printf("1\n");
		number(next,car2);
	}
	else
	{
		printf("2\n");
		number(car1,next);
	}
}
int main(void)
{
	scanf("%d %d",&n,&w);
	Data_car1.push_back(make_pair(1,1));
	Data_car2.push_back(make_pair(n,n));
	memset(dp,-1,sizeof(dp)); 
	for(int i=0; i<w; i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		Data_car1.push_back(make_pair(x,y));
		Data_car2.push_back(make_pair(x,y));
	}
	int dis = func(0,0);
	printf("%d\n",dis);
	number(0,0);
	return 0;
}