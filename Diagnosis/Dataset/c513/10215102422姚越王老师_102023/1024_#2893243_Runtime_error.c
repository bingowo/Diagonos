#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{char s[12];int point;} student;
int cmp(const void* a,const void* b)
{
	student *ax=(student*)a,*bx=(student*)b;
	if(ax->point<bx->point)return 1;
	else return strcmp(ax->s,bx->s);
}
int main()
{
	int n;scanf("%d",&n);
	for(int cnt=0;cnt<n;cnt++)
	{
		int N,M,G;scanf("%d%d%d",&N,&M,&G);
		int p[M];
		for(int i=0;i<M;i++)scanf("%d",&p[i]);
		student a[N];
		for(int i=0;i<N;i++)a[i].point=0;
		char str[100];
		for(int i=0;i<N;i++)
		{
			gets(str);
			int flag=0,j;
			char t[100];
			for(int i=0;str[i];i++)
			{
				if(str[i]==' '&&!flag){strncpy(a[i].s,str,i);flag=1;}
				else if(str[i]!=' ')
				{
					if(str[i]==1)
					{
						if(str[i+1]=='0'){a[i].point+=p[9];i++;}
						else a[i].point+=p[0];
					}
					else a[i].point+=p[str[i]-49];
				}
			}
		}
		qsort(a,N,sizeof(a[0]),cmp);
		int cnt2=0;
		for(int i=0;i<N;i++)if(a[i].point>=G)cnt2++;
		printf("case #%d:\n%d\n",cnt,cnt2);
		for(int i=0;i<N;i++)
		{
			if(a[i].point>G)
			{
				printf("%s ",a[i].s);
				printf("%d",a[i].point);
			}
			printf("\n");
		}
	}
	return 0;
}