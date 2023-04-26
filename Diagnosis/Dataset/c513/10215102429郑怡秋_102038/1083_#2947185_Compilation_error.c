#include <stdio.h>
#include <stdlib.h>
int* add(int a[])
{
    if(a[0]==0) a[0]=1;
    else 
    {
        int i=1;
        while(a[i]!=0) a[i]=~a[i],i++;
        a[i]=1;
    }
    return a;
}
int* add2(int a[],int b[])
{
    int carry=0;
    for(int i=0;i<10001;i++)
    {
        a[i]+=b[i]+carry;
        if(a[i]==2) a[i]=0,carry=1;
        else if(a[i]==3) a[i]=1,carry=1;
        else carry=0;
    }
    return a;
}
void mul(int a[],int x,int j)
{
    int b[10000]={0};
    int c[10000]=add(b);
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<10001;j++)
        {
            if()
            
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a[10000];
        int m;
        scanf("%d",&m);
        int x=m;
        int j=0;
        while(x)
        {
            a[j++]=x&1;
            x>>=1;
        }#include<stdio.h>  
int T;
/*计算能被5整除的次数*/
void solve()
{
	int n;
	scanf("%d",&n);
	int ret=0;
	int m=5;
	while(n>=m)
	{
		ret+=n/m;
		m*=5;
	}
	printf("%d\n",&n);
}
int main()
{
	scanf("%d",&T);
	for(int step=0;step<T;step++)
	{
		printf("case #%d:\n",step);
		solve();
	}
	return 0;
}
        mul(a,x,j);
        printf("case #%d:\n%d\n",i,tump);
    }
    return 0;
}