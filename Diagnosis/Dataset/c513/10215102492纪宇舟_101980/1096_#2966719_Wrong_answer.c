#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int fath[105],son[105],way[105][105],x[105],y[105];
int main()
{
	int n,u,v,sig=0,ans;
	int T;scanf("%d",&T);
	while(T--)
	{
		++sig;ans=0;
		scanf("%d",&n);
		memset(son,0,sizeof(son));
		memset(fath,0,sizeof(fath));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&u,&v);
			x[i]=u;y[i]=v;
			son[u]++;fath[v]++;
			way[u][v]=sig;
		}
		for(int i=1;i<=n;i++)
		{
			if(fath[x[i]]>1||son[y[i]]>1)
			{
				ans=1;break;
			}
			if(son[y[i]]==1&&way[y[i]][x[i]]!=sig)
			{
				ans=1;break;
			}
		}
		if(ans)printf("Poor dxw!\n");
		else printf("Lucky dxw!\n");
	}
	return 0;
}