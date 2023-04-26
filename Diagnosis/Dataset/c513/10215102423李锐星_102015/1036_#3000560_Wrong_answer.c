#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
typedef struct{
	long long x;
	long long y;
	long long d;
}POINT;

int cmp(const void* a,const void* b)
{
	POINT m,n;
	m=*(POINT*)a;
	n=*(POINT*)b;
	if(m.d>n.d) return -1;
	if(m.d<n.d) return 1;
	if(m.x<n.x) return -1;
	if(m.x>n.x) return 1;
	if(m.y<n.y) return -1;
	return 1;
}

int cal(unsigned long long x,unsigned long long y)
{
	if(x==0&&y==0){
		return 0;
	}
	else if((x+y)%2==0){
		return 0;
	}
	else{
		unsigned long long t;
		t=x+y+1;
		int i;
		unsigned long long l=1;
		for (i=0;i<65;i++){
			if(t>l&&t<=2*l){
				return i+1;
			}
			else{
				l*=2;
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	POINT point[101]; 
	int i;
	for (i=0;i<n;i++){
		scanf("%lld%lld",&point[i].x,&point[i].y);
		point[i].d=llabs(point[i].x)+llabs(point[i].y);
	}
	qsort(point,n,sizeof(POINT),cmp);
	unsigned long long d1,d2;
	d1=llabs(point[0].x-point[1].x);
	d2=llabs(point[0].y-point[1].y);
	if(d1+d2==0&&d1>0){
		printf("18446744073709551616\n");
	}
	else{
		printf("%llu\n",d1+d2);
	}
	unsigned long long x1,y1,step=0;
	int m=1;
	for (i=0;i<n-1&&m!=0;i++){
		x1=llabs(point[i].x-point[i+1].x);
		y1=llabs(point[i].y-point[i+1].y);
		m=cal(x1,y1);
		step+=m;
	}
	printf("%llu\n",step);
	return 0;
}