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
  unsigned long long ABS( long long x, long long y)
{	unsigned long long t;
	 if(x>y) t=x-y;
	else t=y-x;
	return t;
}
 long long di(DIAN d)
{    long long xx=d.x;
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
{  long long e=1;
   int i;
	for(i=1;i<=n;i++) e=e*2;
	return e;
}
//int steps(DIAN a,DIAN b)
//{ 	int i=1,k,l;
//	 long long d=DI(a,b);
//	if(d%2==0) return -1;
//	else if(d%2!=0)
//	{    
//		while(i<=62)
//		{
//			if(er(i)-1>=d&&d>er(i-1)-1) break;
//			i++;
//		}
//	}
//	return i;
//}
int main()
{  int n,i,j,kx,ky,tx,ty;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
		{scanf("%lld %lld\n",&dian[i].x,&dian[i].y);}
		qsort(dian,n,sizeof(dian[0]),cmp);
		unsigned long long dx=ABS(dian[0].x,dian[1].x);
		 unsigned long long dy=ABS(dian[0].y,dian[1].y);
		 unsigned long long dis=dx+dy;
		if(dx>dis) printf("18446744073709551615\n");
		else printf("%llu\n",dis);
		int s=0;
		for(i=0;i<n-1;i++)
		{ if(dian[i].x==dian[i+1].x&&dian[i].y==dian[i+1].y) continue;
			dx=ABS(dian[i].x,dian[i+1].x);dy=ABS(dian[i].y,dian[i+1].y);
			dis=dx+dy;
			if(dx%2!=dy%2)
			{
				if(dis>((unsigned long long)1<<63))
				{
					s+=64;continue;
				}
				for(j=1;j<64;j++)
				{
					if(er(j)>=dx+1&&dx+1>er(j-1))
					{
						kx=j;
						tx=dx/pow(2,j-1);
					}
					if(er(j)>=dy+1&&dy+1>er(j-1))
					{
						ky=j;
						ty=dy/pow(2,j-1);
					}
				}
				int max=(kx>ky)?kx:ky;
				s+=max;
				//下面判断是否需要再加一
            //幂相同相加要加一
            //什么时候小幂会影响大幂？
            //小幂只比大幂小1，且系数/2加大幂系数＞2 
            // cout << "幂 " << P[i].power <<"  "<<PP[i].power<<endl;
            // cout <<"系数 " << P[i].coe <<"  "<<PP[i].coe<<endl;
				if(kx==ky) s++;
				else if(ky-kx==1)
				{  tx/=2;
				if((tx+ty)>2) s++;
				}
				else if(ky-kx==-1)
				{  ty/=2;
					if((tx+ty)>2) s++;
				}
			}
			else break;
		}
		printf("%d\n",s);
	return 0;
}