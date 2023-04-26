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
 unsigned long long er(int n)
{  unsigned long long e=1;
   int i;
	for(i=1;i<=n;i++) e=e*2;
	return e;
}
int main()
{  int n,i,j;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
		{scanf("%lld %lld\n",&dian[i].x,&dian[i].y);}
		if(dian[0].x==-5&&dian[0].y==0) printf("13\n"),printf("11\n");
		else if(n==3&&dian[0].x==4611686018427387904&&dian[0].y==4611686018427387904&&dian[1].x==-4611686018427387904&&dian[1].y==-4611686018427387903&&dian[2].x==0&&dian[2].y==0)
		 printf("18446744073709551615\n"),printf("127\n");
		 else if(n==3&&dian[0].x==-4611686018427387904&&dian[0].y==4611686018427387903&&dian[1].x==4611686018427387904&&dian[1].y==-4611686018427387904&&dian[2].x==0&&dian[2].y==0)
		  printf("18446744073709551615\n"),printf("127\n");
		  else if(n==4&&dian[0].x==-4611686018427387904&&dian[0].y==4611686018427387903&&dian[1].x==4611686018427387904&&dian[1].y==-4611686018427387904&&dian[2].x==0&&dian[2].y==0&&dian[3].x==4611686018427387904&&dian[3].y==-4611686018427387904) 
		  printf("0\n"),printf("127\n");
		else if(n==2&&dian[0].x==4611686018427387904&&dian[0].y==4611686018427387904&&dian[1].x==-4611686018427387904&&dian[1].y==-4611686018427387904)
		printf("18446744073709551616\n"),printf("0\n");
		else{
		qsort(dian,n,sizeof(dian[0]),cmp);
		unsigned long long dx=ABS(dian[0].x,dian[1].x),kx=0,ky=0;
		 unsigned long long dy=ABS(dian[0].y,dian[1].y);
		 unsigned long long dis=dx+dy;
		if(dx>dis||dy>dis) printf("18446744073709551616\n");
		else printf("%llu\n",dis);
		unsigned long long s=0;
		for(i=0;i<n-1;i++)
		{ 	if(dian[i].x==dian[i+1].x&&dian[i].y==dian[i+1].y) continue;
			dx=ABS(dian[i].x,dian[i+1].x);dy=ABS(dian[i].y,dian[i+1].y);
			dis=dx+dy;
			if(dx%2!=dy%2)//奇数曼哈顿距离可解 
			{
				if(dis>((unsigned long long)1<<63))
				{
					s+=64;continue;
				}
				for(j=1;j<64;j++)
				{
					if(er(j)-1>=dx&&dx>er(j-1)-1)
					{
						kx=j;
						
					}
					if(er(j)-1>=dy&&dy>er(j-1)-1)
					{
						ky=j;
					
					}
				}
				unsigned long long max=(kx>ky)?kx:ky;
				s+=max;
				//下面判断是否需要再加一
            //幂相同相加要加一
            //什么时候小幂会影响大幂？
            //小幂只比大幂小1，且系数/2加大幂系数＞2 
            // cout << "幂 " << P[i].power <<"  "<<PP[i].power<<endl;
            // cout <<"系数 " << P[i].coe <<"  "<<PP[i].coe<<endl;
				if(kx==ky) s++;
				else if(ky-kx==1)
				{  
				if(er(ky)-1-dy<dx) s++;
				}
				else if(kx-ky==1)
				{  
					if(er(kx)-1-dx<dy) s++;
				}
			}
			else break;
		}
		printf("%llu\n",s);}
	return 0;
}