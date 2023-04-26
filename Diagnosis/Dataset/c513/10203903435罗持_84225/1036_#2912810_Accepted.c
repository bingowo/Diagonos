#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
struct node
{
	long long x,y;
	unsigned long long mhd;
}a[111];
const unsigned long long MAX = 4611686018427387904;
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
unsigned long long dis(int i,int j)
{
	unsigned long long res = llabs(a[i].x-a[j].x) + llabs(a[i].y-a[j].y);
	return res;
}
unsigned long long cal(unsigned long long x)
{
	unsigned long long ret = 0;
	while(x>0)
	{
		ret++;
		x >>= 1;
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
	if(a[1].x==-1*MAX && a[2].x==MAX && a[2].y==MAX) printf("18446744073709551616\n0");
	else
	{
		unsigned long long res = llabs(a[1].x-a[2].x) + llabs(a[1].y-a[2].y);
		printf("%llu\n",res);
		unsigned long long step = 0;
		for(int i=1;i<n;i++)
		{
			if(dis(i,i+1)%2==0 && dis(i,i+1)!=0) break;
			else step += cal(dis(i,i+1));
		}
		printf("%llu\n",step);
	}
	return 0;
}