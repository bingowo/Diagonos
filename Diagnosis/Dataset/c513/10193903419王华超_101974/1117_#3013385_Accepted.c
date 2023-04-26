#include <stdio.h>
#include <stdlib.h>
#include<math.h>
typedef struct{
	long long int x;
	long long int y;
}point;
int cmp(void*p1,void*p2)
{
	point a=*(point*)p1,b=*(point*)p2;
	long long int da=llabs(a.x)>llabs(a.y)?llabs(a.x):llabs(a.y);
	long long int db=llabs(b.x)>llabs(b.y)?llabs(b.x):llabs(b.y);
	if (da>db){
		return 1;
	}	
	else if(da<db)
	{
		return -1;
	}
	else{
		if (a.x==b.x){
			if(a.y<b.y){
				return -1;
			}
			else
			{
				return 1;
			}
		}
		else{
			if(a.x<b.x){
				return -1;
			}
			else{
				return 1;
			}
		}
	}
}
point l[1000000];
int main() 
{
	long long int x0,y0,x,y;
	scanf("%lld %lld",&x0,&y0);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld %lld",&x,&y);
		l[i].x=x-x0;
		l[i].y=y-y0; 
	}
	qsort(l,n,sizeof(point),cmp);
	printf("%lld\n",llabs(l[0].x)>llabs(l[0].y)?llabs(l[0].x):llabs(l[0].y));
	printf("%lld %lld",l[0].x+x0,l[0].y+y0);
	return 0;
}