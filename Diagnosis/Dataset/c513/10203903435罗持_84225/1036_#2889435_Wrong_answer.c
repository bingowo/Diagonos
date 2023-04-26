#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
struct node
{
	long long x,y,mhd,st,len;
}a[111];
int mycmp(const void*aa,const void*bb)
{
	struct node a = *(struct node*)aa;
	struct node b = *(struct node*)bb;
	if(a.mhd == b.mhd)
	{
		if(a.x == b.x)
		{
			if(a.y > b.y) return 1;
			else return -1; 
		}
		else
		{
			if(a.x > b.x) return 1;
			else return -1;
		}
	}
	else
	{
		if(a.mhd < b.mhd) return 1;
		else return -1;
	}
}
long long cal(long long x1,long long y1,long long x2,long long y2)
{
	long long dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
	struct node q[3000];
	struct node n1,n2;
	n1.x = x1,n1.y = y1,n1.st = 0,n1.len = 1;
	int head = 0,tail = 0;
	q[tail] = n1;
	tail++;
	long long ret = -1;
	while(tail!=head)
	{
		//printf("%d\n",head);
		n2 = q[head];
		head++;
		if(head > 500) break;
		if(n2.x == x2 && n2.y == y2)
		{
			ret = n2.st;
			break;
		}
		for(int i=0;i<4;i++)
		{
			long long fx = n2.x+dx[i]*n2.len;
			long long fy = n2.y+dy[i]*n2.len;
			n1.x = fx;
			n1.y = fy;
			n1.st = n2.st+1;
			n1.len = n2.len*2;
			q[tail] = n1;
			tail++;
		}
	}
	return ret;
}
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld",&a[i].x,&a[i].y);
		a[i].mhd = llabs(a[i].x)+llabs(a[i].y);
	}
	qsort(a+1,n,sizeof(a[0]),mycmp);
	long long res = llabs(a[1].x-a[2].x) + llabs(a[1].y-a[2].y);
	printf("%lld\n",res);
	long long step = 0;
	for(int i=1;i<n;i++)
	{
		long long x2 = llabs(a[i+1].x-a[i].x);
		long long y2 = llabs(a[i+1].y-a[i].y);
		long long add = cal(0,0,x2,y2);
		if(add == -1) break;
		else step += add;
	}
	printf("%lld",step);
	return 0;
}