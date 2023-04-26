#include<stdio.h>
#include<stdlib.h>

typedef struct {
	long long int x,y,d;
}xy;

int cmp(const void*p1,const void*p2)
{
	xy *a = (xy*)p1;
	xy *b = (xy*)p2;
	if(a->d!=b->d)
		return a->d - b->d;
	if(a->x!=b->x)
		return a->x - b->x; 
	return a->y - b->y;
}

int main()
{
	int x0,y0,n;
	scanf("%d%d%d",&x0,&y0,&n);
	xy point[10000];
	int a,b;
	for(int i=0;i<n;i++){
		scanf("%d%d",&point[i].x,&point[i].y);
		a = x0 - point[i].x;
		b = y0 - point[i].y;
		if(a<0)	a = -a;
		if(b<0) b = -b;
		if(a>b)
			point[i].d = a;
		else
			point[i].d = b;
	}
	qsort(point,n,sizeof(xy),cmp);
	printf("%d\n",point[0].d);
	printf("%d %d",point[0].x,point[0].y);
	return 0;
 } 