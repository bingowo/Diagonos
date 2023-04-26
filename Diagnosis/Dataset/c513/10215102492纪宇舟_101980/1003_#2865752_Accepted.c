#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
typedef struct{
	int s;
	long long num;
} NUM;
int trans[64],bin[64];
int cal(long long x)
{
	int cnt=0;
	int sig=0,ans=0;
	if(x<0){sig=1;x=-x;}
	while(x)
	{
		trans[cnt++]=x%2;x/=2;// trans 0->cnt 右->左  bin 0-63 左->右 
	}
	memset(bin,0,sizeof(bin));
	for(int i=63,j=0;i>0&&j<cnt;i--,j++)bin[i]=trans[j];
		//for(int i=0;i<64;i++)printf("%d",bin[i]);
	if(sig)
	{
		bin[0]=1;
		for(int i=1;i<64;i++)bin[i]=1-bin[i];
		++bin[63];
		for(int i=62;i>0;i--)
		if(bin[i+1]==2){bin[i+1]=0;bin[i]++;}
	}
	for(int i=0;i<64;i++)if(bin[i])++ans;
	return ans;
}
int cmp(const void *a,const void *b)
{
	NUM x=*(NUM*)a;NUM y=*(NUM*)b;
	if(x.s==y.s)
	{
		if(x.num<y.num)return -1;
		else return 1;
	}
	else if(x.s>y.s)return -1;
	else return 1;
}
int main()
{
	//int y=cal(15);
	int ct=0,T;scanf("%d",&T);
	int n;
	NUM a[10005];
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].num);
			a[i].s=cal(a[i].num);
		}
		qsort(a+1,n,sizeof(NUM),cmp);
		printf("case #%d:\n",ct++);
		for(int i=1;i<=n;i++)printf("%lld ",a[i].num);
		printf("\n");
	}
	return 0;
}