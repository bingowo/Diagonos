#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
typedef struct{
	int a;
	int b;
}H;
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
		int ans=p[0].b,anc=p[n-1].b;
		for(int j=1;j<n;j++) 
		{
			if(ans==p[j].a) ans=p[j].b;
			else break;
		}
		for(int j=n-2;j>=0;j--) 
		{
			if(anc==p[j].a) anc=p[j].b;
			else break;
		}
		if(ans==anc) printf("Lucky dxw!\n");
		else printf("Poor dxw!\n");
	}
	return 0;
}