#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
typedef struct{
	double o;
	double p;
}node;
int cmp(const void*a,const void*b)
{
node p1=*((node*)a);
node p2=*((node*)b);
if(p1.o!=p2.o){
if(p1.o>p2.o)return 1;
else return -1; 
} 
else {
	if(p1.p>p2.p)return -1;
else return 1;
}

} 
int main()
{
	int T;
	scanf("%d",&T);
	node t[1000]={0};
	for(int i=0;i<T;i++)
	{
		int n;
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			double x,y;
			scanf("%lf%lf",&x,&y);
			t[j].p=sqrt(x*x+y*y);
			t[j].o=atan2(y,x);
			if(t[j].o<0)t[j].o=2*3.1415926-t[j].o;
		}
		qsort(t,n,sizeof(t[0]),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<n;j++)
		printf("(%.4f,%.4f)\n",t[j].p,t[j].o);
		
		
		
	}
	return 0; 
} 