#include <stdio.h>
#include <stdlib.h>

typedef struct { int cnt,v[100]; } BIGINT ;
BIGINT a[120]={0,{0}};
BIGINT BigIntAdd(BIGINT p,BIGINT q,int n)
{
	//BIGINT ans={0,{0}};
	int carry=0;
	int max = p.cnt>q.cnt?p.cnt:q.cnt;
	for(int i=0;i<max;i++)
	{
		int x=p.v[i] + q.v[i] + carry;
		a[n].v[a[n].cnt++]=x%10;
		carry=x/10;
	}
	if(carry)
		a[n].v[a[n].cnt++]=carry;
	return a[n];
}
BIGINT F(int n)
{
	//BIGINT ans={0,{0}};
	if(n==0) 
		return (a[n].cnt=1,a[n]);
	else if(n==1 || n==2)
		return (a[n].cnt=1,a[n].v[0]=1,a[n]);
	else if(a[n].cnt)
		return a[n];
	else
		return BigIntAdd(F(n-1),F(n-2),n);
	
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		
		BIGINT ans = F(n);
		printf("case #%d:\n",i);
		for(int i=ans.cnt-1;i>=0;i--)
			printf("%d",ans.v[i]);
		putchar('\n');
	}
}