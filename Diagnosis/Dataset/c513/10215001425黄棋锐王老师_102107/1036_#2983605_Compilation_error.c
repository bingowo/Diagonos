#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
	unsigned long long x;
	unsigned long long y;
}DIAN;
DIAN dian[101];
unsigned long long ABS(unsigned long long x,unsigned long long y)
{
	unsigned long long t=x-y;
	if(t<0) t=-t;
	return t;
}
unsigned long long di(DIAN d)
{   unsigned long long xx=d.x;
	unsigned long long yy=d.y;
	if(xx<0) xx=-xx;
	if(yy<0) yy=-yy;
	unsigned long long t=xx+yy;
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
unsigned long long DI(DIAN a, DIAN b)
{
	unsigned long long xx=a.x-b.x;
	unsigned long long yy=a.y-b.y;
		if(xx<0) xx=-xx;
		if(yy<0) yy=-yy;
	unsigned long longt=xx+yy;
	return t;
}
unsigned long longer(int n)
{ unsigned long long e=1;
   int i;
	for(i=1;i<=n;i++) e=e*2;
	return e;
}
int steps(DIAN a,DIAN b)
{ 	int i=1,k,l;
	unsigned long long d=DI(a,b);
	if(d%2==0) return -1;
	else if(d%2!=0)
	{    
		while(i<=62)
		{
			if(er(i)-1>=d&&d>er(i-1)-1) break;
			i++;
		}
	}
	return i;
}
int main()
{  int n,i;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
		{scanf("%ulld %ulld\n",&dian[i].x,&dian[i].y);}
		qsort(dian,n,sizeof(dian[0]),cmp);
		unsigned long long dx=ABS(dian[0].x,dian[1].x);
		unsigned long long dy=ABS(dian[0].y,dian[1].y);
		unsigned long long dis=dx+dy;
		if(dx>dis) printf("18446744073709551615\n");
		else printf("%ulld\n",dis);
		int s=0;
		for(i=0;i<n-1&&steps(dian[i],dian[i+1])!=-1;i++)
		{ if(dian[i].x==dian[i+1].x&&dian[i].y==dian[i+1].y) continue;
			s+=steps(dian[i],dian[i+1]);
		}
		printf("%d\n",s);
	return 0;
}