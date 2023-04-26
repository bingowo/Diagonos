#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	int  dis;//与最后一辆车距离 
	int speed;
	int di;//与终点距离 
}CAR;

int main() 
{ 	CAR goal={0,0,0};
	scanf("%d",&goal.di);
	int i,n;
	scanf("%d",&n);
	CAR ca[1000]={0,0};
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&ca[i].dis,&ca[i].speed);
		ca[i].di=goal.di-ca[i].dis;
	}
	
	for(i=0;i<n;i++)
	
    return 0;
}