#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int a[165][81],len[165];
int main()
{
	char s[88];
	while(scanf("%s",s)!=EOF)
	{
		int n=strlen(s);
		memset(a,0,sizeof(a));
		memset(len,0,sizeof(len));
		int H=81,LH=81,MH=81;a[81][0]=s[0];len[81]=0;
		for(int i=1;i<n;i++)
		{
			if(s[i]>s[i-1])++H;
			else if(s[i]<s[i-1])--H;
			if(H>MH)MH=H;if(H<LH)LH=H;
			a[H][i]=s[i];
			if(i>len[H])len[H]=i;
		}
		for(int i=MH;i>=LH;i--)
		{
			for(int j=0;j<=len[i];j++)
			if(a[i][j]!=0)printf("%c",a[i][j]);
			else printf(" ");
			printf("\n");
		}
	}
	return 0;
}