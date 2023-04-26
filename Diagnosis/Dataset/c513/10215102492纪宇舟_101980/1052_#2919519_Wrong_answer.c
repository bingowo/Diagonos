#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
	int ans[10];char s[25];
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		memset(ans,0,sizeof(ans));
		scanf("%s",s);
		int n=strlen(s);
		int O=0,R=0,F=0,S=0,I=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='Z')++ans[0];
			if(s[i]=='W')++ans[2];
			if(s[i]=='U')++ans[4];
			if(s[i]=='X')++ans[6];
			if(s[i]=='G')++ans[8];
			if(s[i]=='O')++O;
			if(s[i]=='R')++R;
			if(s[i]=='F')++F;
			if(s[i]=='S')++S;
			if(s[i]=='I')++I;
		}
		ans[1]=O-ans[0]-ans[2]-ans[4];
		ans[3]=R-ans[0]-ans[4];
		ans[5]=F-ans[4];
		ans[7]=S-ans[6];
		ans[9]=I-ans[6]-ans[8];
		printf("case #%d:\n",ct++);
		for(int i=0;i<=9;i++)
		for(int j=1;j<=ans[i];j++)printf("%d",i);
		printf("\n");
	} 
	return 0;
} 