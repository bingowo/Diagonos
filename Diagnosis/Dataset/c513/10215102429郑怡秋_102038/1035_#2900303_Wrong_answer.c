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
long long pow(int x,int y)
{
	long long ans=1;
	for(int i=0;i<y;i++)
	{
		ans*=x;
	}
	return ans;
}
int cmp_1(const void*a,const void*b)
{
	cylinder*p1=(cylinder*)a;cylinder*p2=(cylinder*)b;
	if(p1->RH>p2->RH) return -1;
	else if(p1->RH<p2->RH) return 1;
	else 
	{
		if(p1->R<p2->R) return 1;
		else return -1;
	}
}
int cmp_2(const void*a,const void*b)
{
	cylinder*p1=(cylinder*)a;cylinder*p2=(cylinder*)b;
	if(p1->R>p2->R) return -1;
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
		p[i].sur=pow(p[i].R,2)+2*(long long)p[i].R*(long long)p[i].H;
		p[i].RH=2*(long long)p[i].R*(long long)p[i].H;
	}
	qsort(p,n,sizeof(p[0]),cmp_1);  
	qsort(p,m,sizeof(p[0]),cmp_2);  
	long long ans1=p[0].sur-p[0].RH;
	for(int j=0;j<m;j++) ans1+=p[j].RH;
	
	qsort(p,n,sizeof(p[0]),cmp_2);  
	qsort(p,m,sizeof(p[0]),cmp_1);  
	long long ans2=p[0].sur-p[0].RH;
	for(int j=0;j<m;j++) ans2+=p[j].RH;
	if(ans1>ans2) ans2=ans1;
	free(p);
	printf("%lld",ans2);
}