#include <stdio.h>
#include <stdlib.h>
long long xx,yy,n;
struct node
{
	long long dis,x,y;
}res[1000010];
int mycmp(const void* a, const void*b)
{
	struct node *x = (struct node*) a;
	struct node *y = (struct node*) b;
	if(x->dis==y->dis)
	{
		if(x->x == y->x) return x->y > y->y;
		return x->x > y->x;
	}
	return x->dis > y->dis;
}
int main(void)
{
	scanf("%lld %lld %lld",&xx,&yy,&n);
	for(int i=0;i<n;i++)
	{
		long long x,y;
		scanf("%lld %lld",&x,&y);
		long long a,b;
		if(x>=0 && xx>=0) 
		{
			if (x>xx) a = x-xx;
			else a = xx-x;
		}
		else if(x>=0 && xx<0) a = x-xx;
		else if(x<0 && xx>=0) a = xx-x;
		else
		{
			x *= -1;
			xx *= -1;
			if(x>xx) a = x-xx;
			else a = xx-x;
			x *= -1;
			xx *= -1;
		}
		if(y>=0 && yy>=0) 
		{
			if (y>yy) b = y-yy;
			else b = yy-y;
		}
		else if(y>=0 && yy<0) b = y-yy;
		else if(y<0 && yy>=0) b = yy-y;
		else
		{
			y *= -1;
			yy *= -1;
			if(y>yy) b = y-yy;
			else b = yy-y;
			y *= -1;
			yy *= -1;
		}
		if(a>b) res[i].dis = a;
		else res[i].dis = b;
		//printf("%lld %lld %lld %lld %lld\n",x,y,a,b,res[i].dis);
		res[i].x = x;
		res[i].y = y;
	}
	qsort(res,n,sizeof(res[0]),mycmp);
	printf("%lld\n",res[0].dis);
	printf("%lld %lld\n",res[0].x,res[0].y);
	return 0;
}