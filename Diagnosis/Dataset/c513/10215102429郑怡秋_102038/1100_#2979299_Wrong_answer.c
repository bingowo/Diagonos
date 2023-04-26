#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int main()
{
	char ord[310];
	scanf("%s",ord);
	int l=strlen(ord);
	int t;
	scanf("%d",&t);
	long long x=0,y=0;
	long long qus[2];
	for(int i=0;i<t;i++)
	{
		x=0;y=0;
		scanf("%lld%lld",&qus[0],&qus[1]);
		int k;
		long long an[110][3],k1=0,k2=0;
		an[0][0]=0;an[0][1]=0;
		for(k=0;k<l;k++)
		{
			if(x==qus[0]&&y==qus[1]) break;
			if(ord[k]=='U') y++;
			else if(ord[k]=='D') y--;
			else if(ord[k]=='L') x--;
			else if(ord[k]=='R') x++;
			an[k+1][0]=x;an[k+1][1]=y;
		}//printf("%d %d\n",x,y);
		if(k<l) printf("Yes\n");
		else
		{
			int a=0;
			if(x!=0&&y!=0)

			k1=0,k2=0;
			if(x!=0&&y!=0) k1=qus[0]%x,k2=qus[1]%y;
			else if(x==0&&y!=0) k2=qus[1]%y;
			else if(x!=0&&y==0) k1=qus[0]%x;
			else k1=qus[0],k2=qus[1];
			//printf("%d\n",x);
			for(int k3=0;k3<l+1;k3++)
			{
				if(k1>0&&k2>0&&k1==an[k3][0]&&k2==an[k3][1])
				{
					a=1;
					break;
				}
			}
			if(a==1) printf("Yes\n");
			else printf("No\n");
		}
			
		
	}
	return 0;
}