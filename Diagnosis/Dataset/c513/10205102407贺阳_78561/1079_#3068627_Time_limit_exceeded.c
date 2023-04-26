#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void*b);
int main(){
	int T;
	scanf("%d",&T);
	int i=0;
	for(;i<T;i++)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		printf("case #%d:\n",i);
		int s[1010]={0};
		int j=0;
		for(;j<n;j++)
		{
			scanf("%d",&s[j]);
		}
		int x=0;
		int b[500510];
		int d=0;
		for(;x<n;x++)
		{
			int y=x;
			for(;y<n;y++)
			{
				int q=0,p=x;
				for(;p<y+1;p++)
				{
					q+=s[p];
				}
				b[d++]=q;
			}
		}
		qsort(b,d,sizeof(b[0]),cmp);
		j=0;
		for(;j<m;j++)
		{
			int l,u;
			scanf("%d %d",&l,&u);
			int x1=l-1;
			int ans=0;
			for(;x1<u-1;x++)
			{
				
				ans+=b[x1];
			}
			printf("%d\n",ans);
		}
	} 
	return 0;
}
int cmp(const void *a,const void *b)
{
	return ((int*)a-(int*)b);
}
