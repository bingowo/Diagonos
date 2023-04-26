#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 10000

typedef struct
{
	int cnt;
	int v[max];
}BIGINT;

BIGINT int2BIG(int x)
{
	BIGINT R={0,{0}};
	do
	{
		R.v[R.cnt++]=x%10;
		x/=10;
	}while(x>0);
	return R;
}

BIGINT mul(BIGINT S,BIGINT T)
{
	BIGINT R={S.cnt+T.cnt,{0}};
	int i,j,k,t;
	for(i=0;i<T.cnt;i++)
	{
		int carry=0;
		for(j=0;j<S.cnt;j++)
		{t=T.v[i]*S.v[j]+carry+R.v[i+j];
		R.v[i+j]=t%10;
		carry=t/10;
		}
		k=i+j;
		while(carry>0)
		{	t=R.v[k]+carry;
			R.v[k]=t%10;
			carry=t/10;
			k++;
		}
	}
	if(R.v[S.cnt+T.cnt-1]==0) R.cnt--;//最高位为0时不计入有效位数
	return R;
}

BIGINT POW(BIGINT a, int n)
{	BIGINT r;
	if(n==0) return int2BIG(1);
	if(n==1) return a;
	r=POW(a,n/2);
	r=mul(r,r);
	if(n%2!=0) r=mul(r,a);//奇数会少乘1个次方 
	return r;
}
int main() 
{ int k,T,A,B,N;
	scanf("%d\n",&T);
for(k=0;k<T;k++)
	{	scanf("%d %d %d",&A,&B,&N);
		printf("case #%d:\n",k);
		BIGINT a=int2BIG(A);
		a=POW(a,B);
		int i;
		for(i=N-1;i>=0;i--)
			printf("%d",a.v[i]);
		putchar('\n');
	} 	
	return 0;
}