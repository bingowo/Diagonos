#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>


int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int a[105],b[105];
		int v[105][105];
		for(int j=0;j<105;j++) a[j]=0,b[j]=0;
		for(int j=0;j<105;j++) for(int k=0;k<105;k++) v[j][k]=0;
		int x,y;
		for(int j=0;j<n;j++) 
		{
			scanf("%d%d",&x,&y);
			if(v[x][y]==0) a[x]++,b[y]++,v[x][y]=1; 
		}
		int ans=0;
		for(int j=0;j<105;j++) 
		{
			if(a[j]>1||(a[j]+b[j]>=2)) ans=1;
		}
		if(ans==1) printf("Poor dxw!\n");
		else printf("Lucky dxw!\n");
		for(int j=0;j<105;j++) a[j]=0,b[j]=0;
		for(int j=0;j<105;j++) for(int k=0;k<105;k++) v[j][k]=0;
	}
	return 0;
}