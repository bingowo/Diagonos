#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>
#include <math.h>
int po(int x)
{
	int ans=1;
	for(int i=0;i<x;i++)
	{
		ans*=2;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char A[101];
		scanf("%s",A);
		int B[808];int index=0;
		for(int j=0;j<strlen(A);j++)
		{
			int tump=(int)A[j];
			for(int k=0;k<8;k++)
			{
				B[index++]=(tump>>(7-k))&1;//printf("%d",B[index-1]);
			}
		}
		while(index%6!=0) B[index++]=0;
		//for(int j=0;j<index;j++) printf("%d",B[j]);
		int D[300]={0};
		int p=0;
		int k=0;
		while(k<index)
		{
			for(int l=5;l>=0;l--)
			{
				D[p]+=B[k++]*po(l);
			}
			p++;//printf("%d\n",D[p-1]);
		}
		printf("case #%d:\n",i);
		char E[201];
		int q=0;
		for(;q<p;q++)
		{
			if(D[q]==43) E[q]='+';
			else if(D[q]==45) E[q]='-';
			else if(D[q]>=0&&D[q]<=25) E[q]=D[q]+'A';
			else if(D[q]>=26&&D[q]<=51) E[q]=D[q]+71;
			else if(D[q]>=52&&D[q]<=61) E[q]=D[q]-4;
		}
		while(q%4!=0) E[q++]='='; 
		E[q]='\0';
		printf("%s\n",E);
		
	}
	return 0;
}