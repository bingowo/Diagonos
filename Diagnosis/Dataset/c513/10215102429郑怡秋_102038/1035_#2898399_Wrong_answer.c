#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
typedef struct{
	int R;
	int H;
	long long sur;
	long long RH;
}cylinder;
unsigned long long pow(int x,int y)
{
	unsigned long long ans=1;
	for(int i=0;i<y;i++)
	{
		ans*=x;
	}
	return ans;
}
int cmp_1(const void*a,const void*b)
{
	cylinder*p1=(cylinder*)a;cylinder*p2=(cylinder*)b;
	if(p1->sur>p2->sur) return -1;
	else return 1;
}
int cmp_2(const void*a,const void*b)
{
	cylinder*p1=(cylinder*)a;cylinder*p2=(cylinder*)b;
	if(p1->RH>p2->RH) return -1;
	else return 1;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	cylinder* p=(cylinder*)malloc(n*sizeof(cylinder));
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].R,&p[i].H);
		p[i].sur=pow(p[i].R,2)+2*(unsigned long long)p[i].R*(unsigned long long)p[i].H;
		p[i].RH=2*(unsigned long long)p[i].R*(unsigned long long)p[i].H;
	}
	qsort(p,n,sizeof(p[0]),cmp_1);
	unsigned long long ans=p[0].sur;
	p[0].RH=0;
	qsort(p,n,sizeof(p[0]),cmp_2);
	//long long ans=p[0].sur;
	for(int j=0;j<m-1;j++)
	{
		ans+=p[j].RH;
	}
	free(p);
	printf("%u",ans);
}
