#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int tab[12][12];
int main()
{
	int n,m,xunhuan,ans,pos;
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		xunhuan=0;pos=0;
		scanf("%d%d",&n,&m);
		printf("case #%d:\n",ct++);
		printf("%d.",n/m);
		n=n-m*(n/m);
		memset(tab,0,sizeof(tab));
		while(n!=0)
		{
			++pos;//printf("fuck");
			n*=10;ans=n/m;n%=m;
			if(tab[ans][n])
			{
				xunhuan=1;printf("\n%d-%d",tab[ans][n],pos-1);
				break;
			}
			tab[ans][n]=pos;printf("%d",ans);
		}
		if(n==0)printf("\n");
	}
	return 0;
}