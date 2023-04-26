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
		int ans[10];
		for(int q=0;q<10;q++) ans[q]=0;
		char ind[110];
		scanf("%s",ind);
		int l=strlen(ind);
		int j;
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
	return 0;
}