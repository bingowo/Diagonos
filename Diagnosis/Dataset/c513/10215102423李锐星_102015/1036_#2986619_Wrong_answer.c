#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	long long x;
	long long y;
	unsigned long long d;
}POINT;

int cmp(const void* a,const void* b)
{
	POINT m,n;
	m=*(POINT*)a;
	n=*(POINT*)b;
	if(m.d>n.d){
		return -1;
	}
	else if(m.d<n.d){
		return 1;
	}
	else{
		if(m.x<n.x){
			return -1;
		}
		else if(m.x>n.x){
			return 1;
		}
		else{
			if(m.y<n.y){
				return -1;
			}
			return 1;
		}
	}
}

int cal(unsigned long long x,unsigned long long y)
{
	int m=0;
	while(x!=0||y!=0){
		if(x%2==1&&y%2==0){
			if(x==1&&y==0){
				x--;
			}
			else if((x+1)/2%2!=y/2%2){
				x++;
			}
			else{
				x--;
			}
			x/=2;
			y/=2;
			m++;
		}
		else if(x%2==0&&y%2==1){
			if(x==0&&y==1){
				y--;
			}
			else if(x/2%2!=(y+1)/2%2){
				y++;
			}
			else{
				y--;
			}
			x/=2;
			y/=2;
			m++;
		}
		else{
			break;
		}
	}
	return m;
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
	printf("%llu\n",llabs(point[0].x-point[1].x)+llabs(point[0].y-point[1].y));
	unsigned long long x1,y1,step=0;
	int m=1;
	i=0;
	if(point[i].x==point[i+1].x&&point[i].y==point[i+1].y) i++;
	for(;i<n-1&&m!=0;i++){
		x1=llabs(point[i].x-point[i+1].x);
		y1=llabs(point[i].y-point[i+1].y);
		m=cal(x1,y1);
		step+=m;
	}
	printf("%llu\n",step);
	return 0;
}