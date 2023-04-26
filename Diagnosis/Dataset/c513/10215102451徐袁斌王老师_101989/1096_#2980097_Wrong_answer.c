#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,a,b,x[100]={0},y[100]={0};
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<100;j++) {x[j]=0;y[j]=0;}
		int s,ans=0;
		scanf("%d",&s);
		for(int j=0;j<s;j++)
		{
			scanf("%d%d",&a,&b);
			if(y[a]!=0) {ans++;}
			x[a]++;
			if(x[b]!=0) {ans++;}
			y[b]++;
		}
		if(ans==0) printf("Lucky dxw!\n");
		else printf("Poor dxw!\n");
		
	}
		
		
	
}