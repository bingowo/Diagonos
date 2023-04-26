#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{
	long long R,H,S;
}CI; 
int cmp(const void* a,const void* b)
{
	CI x=*(CI*)a;CI y=*(CI*)b;
	if(x.S>y.S)return -1;
	else return 1;
}
int main()
{
	CI a[1005];
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].R,&a[i].H);
		a[i].S=2*a[i].R*a[i].H;
	}
	qsort(a+1,n,sizeof(CI),cmp);
	long long maxs=0;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		long long sum=a[i].R*a[i].R+a[i].S;
		for(int j=1;j<=n;j++)
		{
			if(cnt==m-1)break;
			if(i!=j&&a[j].R<=a[i].R)
			{
				++cnt;sum+=a[j].S;
			}
		}
		if(cnt==m-1&&sum>maxs)maxs=sum;
	}
	printf("%lld",maxs);
}