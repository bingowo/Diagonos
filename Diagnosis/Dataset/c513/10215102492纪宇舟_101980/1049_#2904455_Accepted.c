#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{
	char s[501];
}CHR;
int cmp(const void* a,const void* b)
{
	CHR x=*(CHR*)a;CHR y=*(CHR*)b;
	return strcmp(x.s,y.s);
}
int n;
int main()
{
	int ct=0,T;scanf("%d\n",&T);
	CHR chr[501];char c,a[501];
	while(T--)
	{
		int len=0;n=0;
		while(c=getchar())
		{
			if(c<'a'||c>'z')
			{
				if(len!=0)
				{
					a[len]='\0';
					strcpy(chr[++n].s,a);
				}
				if(c=='\n')break;len=0;
			}
			else a[len++]=c;
		}
		qsort(chr+1,n,sizeof(CHR),cmp);
		printf("case #%d:\n",ct++);
		for(int i=1;i<=n;i++)
		if(i>1&&strcmp(chr[i].s,chr[i-1].s)==0)continue;
		else printf("%s ",chr[i].s);
		printf("\n");
	}
	return 0;
}