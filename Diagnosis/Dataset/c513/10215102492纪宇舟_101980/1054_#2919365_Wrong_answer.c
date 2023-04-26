#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
	char c;
	int M,n,cnt;
	int line[2001];
	char str[2001][2001];
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		n=cnt=0;
		scanf("%d\n",&M);
		while(c=getchar())
		{
			if((c==' '||c=='\n')&&cnt!=0)
			{
				line[n]=cnt;
				str[n][cnt]=0;
				n++;cnt=0;
			}
			if(c=='\n')break;
			if(c!=' ')str[n][cnt++]=c;
		}
		printf("case #%d:\n",ct++);
		int last=0,pos=0;
		while(1)
		{
			int sum=-1;
			while(pos<n&&sum+line[pos]+1<=M)sum+=line[pos++]+1;
			int space=M-sum+pos-last-1,num=pos-last;
			//printf("%d %d\n",space,num);
			if(pos==n)
			{
				for(int i=last;i<pos;i++)
				{
					printf("%s",str[i]);
					if(i!=pos-1)printf(" ");
				}printf("\n");
				break;
			}
			int ave=space,left;
			if(num!=0)ave=space/num;
			left=space-ave*num;
			for(int i=last;i<pos;i++)
			{
				printf("%s",str[i]);
				if(i!=pos-1)
				{
					for(int j=1;j<=ave;j++)printf(" ");
					if(pos-i-1<=left)printf(" ");
				}
			}
			last=pos;printf("\n");
		}
	}
} 