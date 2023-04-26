#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 95//结果最多95位 
//为了使得数组表示大整数有一定的通用性，
//可以通过一个结构体类型记录一个大整数的位数及每一位的值。
typedef struct
{
	int cnt;//记录有效位数 
	int v[N];//记录每一位上的数字，v[0]个位，v[1]十位 
}BIGINT;// 表示最大可能位数小于N位的一个大正整数

BIGINT int2BIG(int x)//把int转换成BIGINT 
{
	BIGINT R={0,{0}};
	do
	{
		R.v[R.cnt++]=x%10;
		x/=10;
	 } while(x>0);
	 return R;
}
BIGINT mul(BIGINT S,BIGINT T)//大整数相乘, S.v[i]*T.v[j]->R.v[i+j] ,  R.v[i+j]上大于10进1 
{   
	BIGINT R={S.cnt+T.cnt,{0}};//位数至少为S.cnt+T.cnt
	int i,j,k,t;
	for(i=0;i<T.cnt;i++)
	{
		int carry=0;
		for(j=0;j<S.cnt;j++)
		{
			t=T.v[i]*S.v[j]+carry+R.v[i+j];//R.V[i+j]的计算值 
			R.v[i+j]=t%10;//有效十进制数 
			carry=t/10;//进位数 
		}
		k=i+j;//此次计算最高位 k
		while(carry>0)//看R.v[k]是否需要进位 
		{
			t=R.v[k]+carry;//计算值
			R.v[k]=t%10;
			carry=t/10;
			k++;//下一步算R.v[k+1] 
		} 
	}
	if(R.v[S.cnt+T.cnt-1]==0) R.cnt--;//最高位为0时不计入有效位数 
	return R;
}
BIGINT POW(BIGINT a,int n)//计算a的n次方，二分法 
{
	BIGINT r;
	if(n==0) return int2BIG(1);
	if(n==1) return a;
	r=POW(a,n/2);
	r=mul(r,r);
	if(n%2!=0) r=mul(r,a);// 奇数时前两步会少乘一个次方；
	return r; 
}
int main()
{   int k,T;
 scanf("%d",&T);
 for(k=0;k<T;k++)
 { int a,n,i;
    scanf("%d %d",&a,&n);
 	printf("case #%d:\n",k);
 	BIGINT aa=int2BIG(a);
 	aa=POW(aa,n);
	for(i=aa.cnt-1;i>=0;i--) printf("%d",aa.v[i]);
	printf("\n");
 }
	return 0;
}