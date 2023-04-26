#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>

int tr(char c)
{
	if(c=='R') return 0;
	else if(c=='B') return 1;
	else if(c=='Y') return 2;
	else if(c=='G') return 3;
	else if(c=='!') return -1;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		char ind[120];
		scanf("%s",ind);
		int l=strlen(ind);
		if(l>4){
		char a[5];
		for(int j=0;j<5;j++) a[j]='A';
		for(int k=0;k<4;k++)
		for(int j=k;j<l;j+=4)
		{
			if(ind[j]!='!') 
			{
				a[k]=ind[j];
				break;
			}
			
		}
		int an[5];
		for(int j=0;j<5;j++) an[j]=0;
	
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
		else if(l<=4)
		{
			int j;int ans[10];for(int q=0;q<10;q++) ans[q]=0;
		int n1=0,n2=0,n3=0,n4=0;
		for(j=0;j<l&&l-j>=4;j+=4)
		{
			int a=tr(ind[j]),b=tr(ind[j+1]),c=tr(ind[j+2]),d=tr(ind[j+3]);
			ans[0]++,ans[1]++,ans[2]++,ans[3]++;
			if(a>=0) ans[a]--,n1=0;
			else n1=1;
			if(b>=0) ans[b]--,n2=0;
			else n2=1;
			if(c>=0) ans[c]--,n3=0;
			else n3=1;
			if(d>=0) ans[d]--,n4=0;
			else n4=1;
		}
		if(j<l)
		{
			int k=l-4;
			int a=tr(ind[k]),b=tr(ind[k+1]),c=tr(ind[k+2]),d=tr(ind[k+3]);
			if(a<0&&n1==1) ans[a]++;
			if(b<0&&n2==1) ans[b]++;
			if(c<0&&n3==1) ans[c]++;
			if(d<0&&n4==1) ans[d]++;

		}
		printf("case #%d:\n",i);
		for(int i=0;i<3;i++) printf("%d ",ans[i]);
		printf("%d\n",ans[3]);
		}
		
	}
	return 0;
}