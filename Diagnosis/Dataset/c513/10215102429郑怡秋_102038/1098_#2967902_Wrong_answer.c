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
		char ind[120];
		scanf("%s",ind);
		int l=strlen(ind);
		char a[5];int ii=0;
		for(int k=0;k<4;k++)
		for(int j=k;j<l;j+=4)
		{
			if(ind[j]!='!') 
			{
				a[ii++]=ind[j];
				break;
			}
		}
		int an[5];
		for(int j=0;j<5;j++) an[j]=0;
		a[ii]='\0';
		//printf("%s",a);
		for(int k=0;k<4;k++)
		for(int j=k;j<l;j+=4)
		{
			if(ind[j]!=a[k]) an[k]++;
		}
		printf("case #%d:\n",i);
		for(int j=0;j<4;j++) if(a[j]=='R') printf("%d ",an[j]);
		for(int j=0;j<4;j++)  if(a[j]=='B') printf("%d ",an[j]);
		for(int j=0;j<4;j++)  if(a[j]=='Y') printf("%d ",an[j]);
		for(int j=0;j<4;j++)  if(a[j]=='G') printf("%d\n",an[j]);
		
		
	}
	return 0;
}