#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
char chr[105];
int tran[340],mid[340],res[340];
int main()
{
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		scanf("%s",&chr);
		int n=strlen(chr);
		for(int i=0;i<n;i++)tran[i+1]=chr[i]-'0';
		int cnt=0;tran[0]=n;
		for(int i=1;i<=334;i++)
		{
			if(tran[0]==0)
			{
				res[++cnt]=0;continue;
			}
			int y=0;mid[0]=tran[0];
			for(int j=1;j<=tran[0];j++)
			{
				y=y*10+tran[j];
				mid[j]=y/2;
				y%=2;
			}
			res[++cnt]=y;
			int pos=1;
			while(pos<=mid[0]&&mid[pos]==0)pos++;
			memset(tran,0,sizeof(tran));
			for(int j=pos;j<=mid[0];j++)tran[++tran[0]]=mid[j];
			memset(mid,0,sizeof(mid));
		}
		int pos1=1,pos2=1;
		for(int i=1;i<=334;i++)
		if(res[i]!=0){pos1=i;break;}
		for(int i=334;i>=1;i--)
		if(res[i]!=0){pos2=i;break;}
		tran[0]=0;cnt=0;
		for(int i=pos1;i<=pos2;i++)tran[++tran[0]]=res[i];
		while(tran[0]!=0)
		{
			int y=0;mid[0]=tran[0];
			for(int j=1;j<=tran[0];j++)
			{
				y=y*2+tran[j];
				mid[j]=y/10;
				y%=10;
			}
			res[++cnt]=y;
			int pos=1;
			while(pos<=mid[0]&&mid[pos]==0)pos++;
			memset(tran,0,sizeof(tran));
			for(int j=pos;j<=mid[0];j++)tran[++tran[0]]=mid[j];
			memset(mid,0,sizeof(mid));
		}
		printf("case #%d:\n",ct++);
		for(int i=cnt;i>=1;i--)printf("%d",res[i]);
		printf("\n");
	}
	return 0;
} 