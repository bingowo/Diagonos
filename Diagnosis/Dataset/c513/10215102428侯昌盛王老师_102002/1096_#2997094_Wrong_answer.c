#include <stdio.h>
#include <string.h> 
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int a[101][101];
		memset(a,0,sizeof(a));
		int f[n],l[n],k,t,j=0,e=0;
		for(j;j<n;j++)
		{
			scanf("%d %d",&k,&t);
			if(k==t) continue;
			if(a[k][t]==1) continue;
			a[k][t]=1;
			f[e]=k;
			l[e]=t;
			e++;
		}

		for(j=0;j<e-1;j++)
		{
			if(l[j]==f[j+1])
			{
				printf("Poor dwx!\n");
				goto p;
			}
		
		}
		for(j=0;j<e-1;j++)
			for(k=j+1;k<e;k++)
				if(f[j]==f[k])
					if(l[j]==l[k])
					{
						printf("Poor dwx!\n");
						goto p;
					}
		
		printf("Lucky dxw!\n");
		p: k=0;
				
			
			
	}
	return 0;
}