#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
	long long x;
	long long y;
}DIAN;
DIAN dian[101];
long long di(DIAN d)
{   long long xx=d.x;
	long long yy=d.y;
	if(xx<0) xx=-xx;
	if(yy<0) yy=-yy;
	long long t=xx+yy;
	return t; 
}
int cmp(const void*a,const void *b)
{  DIAN aa=*(DIAN*)a;
   DIAN bb=*(DIAN*)b;
   if(di(aa)!=di(bb)) {
   	if(di(bb)>di(aa)) return 1;
   	else return -1;
   }
   else {
   	if(aa.x!=bb.x) {
   		if(aa.x>bb.x) return 1;
   		else return -1;
	   }
	   else {
	   	if(aa.y>bb.y) return 1;
	   	else return -1;
	   }
   }
}
long long DI(DIAN a, DIAN b)
{
	long long xx=a.x-b.x;
	long long yy=a.y-b.y;
		if(xx<0) xx=-xx;
		if(yy<0) yy=-yy;
	long long t=xx+yy;
	return t;
}
long long er(int n)
{ long long e=1;
   int i;
	for(i=1;i<=n;i++) e*=2;
	return e;
}
long long steps(DIAN a,DIAN b)
{ 	int i=1;
	long long d=DI(a,b);
	if(d%2!=0) return -1;
	else if(d%2==0)
	{
		while(1)
		{
			if((er(i)-1)>=d&&d>(er(i-1)-1)) return i;
			i++;
		}
	}
	 
}
int main()
{  int n,i;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
		scanf("%lld %lld\n",&dian[i].x,&dian[i].y);
		qsort(dian,n,sizeof(dian[0]),cmp);
		long long s=0;
		for(i=0;i<n-1;i++)
		{
			s+=steps(dian[i],dian[i+1]);
		}
		printf("%lld\n",DI(dian[0],dian[1]));
		printf("%lld\n",s);
	return 0;
}

