#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 200

typedef struct
{
	int cnt;//记录有效位数 
	int v[max];//记录每一位上的数字，v[0]个位，v[1]十位 
}BIGINT;// 表示最大可能位数小于N位的一个大正整数

BIGINT AaddB(BIGINT*A,BIGINT*B)//A+B
{   int carry=0,i=0,de=(A->cnt>B->cnt)?A->cnt:B->cnt;
	BIGINT R;
	for(i=0;i<de;i++)
	{   
		int t=A->v[i]+B->v[i]+carry;
		A->v[i]=t%10;
		carry=t/10;
	}
	while(carry>0)
	{	int t=A->v[i]+carry;
		A->v[i]=t%10;
		carry=t/10;
		i++;
	}
	if(i>A->cnt) A->cnt=i;
	R=*A;
	return R;
}

int main() 
{ 	int k,n;
	scanf("%d%d",&k,&n);
	BIGINT co[102]={0,0};
	co[0].cnt=1,co[0].v[0]=0;
	co[1].cnt=1,co[1].v[0]=1;
	int i,j;
	
	for(i=2;i<=n-1;i++)
	{if(i>=k) for(j=1;j<=k;j++) co[i]=AaddB(&co[i],&co[i-j]);
	else for(j=1;j<=i;j++) co[i]=AaddB(&co[i],&co[i-j]);
	}
	
	for(i=co[n-1].cnt-1;i>=0;i--) printf("%d",co[n-1].v[i]);
    return 0;
}
