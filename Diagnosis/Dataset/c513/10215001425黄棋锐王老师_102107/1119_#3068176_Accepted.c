#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	double  dis;//与最后一辆车距离 
	double speed;
	double di;//与终点距离
	double time;//到终点时间 
}CAR;

int cmp(const void*a,const void*b)
{
	CAR aa=*(CAR*)a;
	CAR bb=*(CAR*)b;
	return aa.di-bb.di;
}

int main() 
{ 	CAR goal={0,0,0,0};
	scanf("%lf",&goal.di);
	int i,n;
	scanf("%d",&n);
	CAR ca[1000]={0,0,0,0};
	for(i=0;i<n;i++)
	{
		scanf("%lf %lf",&ca[i].dis,&ca[i].speed);
		ca[i].di=goal.di-ca[i].dis;
	}
	
	qsort(ca,n,sizeof(ca[0]),cmp);
	for(i=0;i<n;i++)
		ca[i].time=ca[i].di/ca[i].speed;

	double time=0;
	for(i=0;i<n;i++)//后车如果追得上前车，后车减速，前车速度不变，后车和前车一定同时到达终点，所以取最长到达时间 
		if(time<ca[i].time) time=ca[i].time;
		
	goal.speed=goal.di/time;
	printf("%lf",goal.speed);
    return 0;
}