#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int main()
{
	char ord[110];
	scanf("%s",ord);
	int l=strlen(ord);
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		long long x=0,y=0;
		long long qus[2];
		scanf("%lld%lld",&qus[0],&qus[1]);
		int k;
		long long an[110][3];//int a=0,b=0;
		for(k=0;k<l;k++)
		{
			if(x==qus[0]&&y==qus[1]) break;
			if(ord[k]=='U') y++;
			else if(ord[k]=='D') y--;
			else if(ord[k]=='L') x--;
			else if(ord[k]=='R') x++;
			an[k][0]=x;an[k][1]=y;//printf("x:%d y:%d\n",an[k][0],an[k][1]); 
		}printf("%d %d\n",l,k);
		if(k<l) printf("Yes\n");
		else{
		int a=0;//printf("-----\n");printf("%d %d\n",qus[0],an[1][0]);
//		if(qus[0]<0||qus[1]<0) qus[0]+=x,qus[1]+=y;
		for(int kk=0;kk<100;kk++)
		{
			long long k1=qus[0]-kk*x,k2=qus[1]-kk*y;
			if(x!=0) k1=qus[0]-(qus[0]/x)*x;
			if(y!=0) k2=qus[1]-(qus[1]/y)*y;
			for(int k3=0;k3<l;k3++)
			{
				if(k1==an[k3][0]&&k2==an[k3][1])
				{
					a=1;
					break;
				}
			}
			if(a==1) break;
		}
		if(a==1) printf("Yes\n");
		else printf("No\n");
		}
	}
	return 0;
}