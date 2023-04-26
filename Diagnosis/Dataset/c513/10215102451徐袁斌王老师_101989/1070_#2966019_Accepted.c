#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int d00[21],d01[21],d1[21],n;
	d00[1]=1;d01[1]=0;d1[1]=1;
	d00[2]=1;d01[2]=1;d1[2]=2;
	for(int n=3;n<=20;n++)
	{
		d00[n]=d00[n-1]+d01[n-1];
		d01[n]=d1[n-1];
		d1[n]=d1[n-1]+d00[n-1];
	}
	while(1)
	{
		scanf("%d",&n);
		if(n==-1) break;
		else printf("%d\n",d00[n]+d01[n]+d1[n]);
	}
}