#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
typedef struct{
	int a;
	int b;
}H;
int cmp(const void*a,const void*b)
{
	H*p1=(H*)a;H*p2=(H*)b;
	if(p1->a>p2->a) return 1;
	else return -1;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		H*p=(H*)malloc(n*sizeof(H));
		for(int j=0;j<n;j++) scanf("%d%d",&p[j].a,&p[j].b);
		qsort(p,n,sizeof(p[0]),cmp);
		int ans=0;
		for(int j=1;j<n;j++) 
		{
			if(p[j].a==p[j-1].a) 
			{
				if(p[j].b!=p[j-1].b) 
				{
					ans=1;
					break;
				}
			}
		}
		if(ans==1) printf("Poor dxw!\n");
		else printf("Lucky dxw!\n");
		
	}
	return 0;
}