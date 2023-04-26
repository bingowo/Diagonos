#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{
	char s[16];
	long long num;
}CHR;
int tab[125];
int cmp(const void* a,const void* b)
{
	CHR x=*(CHR*)a;CHR y=*(CHR*)b;
	if(x.num==y.num)
	return strcmp(x.s,y.s);
	if(x.num<y.num)return -1;
	return 1;
}
int main()
{
	int N;CHR a[10001];
	scanf("%d",&N);
	for(int o=1;o<=N;o++)
	{
		scanf("%s",a[o].s);
		int n=strlen(a[o].s);
		memset(tab,-1,sizeof(tab));
		a[o].num=0;long long cnt=1,flag=0;
		for(int i=0;i<n;i++)
		{
			if(i!=0&&flag==0&&tab[a[o].s[i]]==-1)
			{
				tab[a[o].s[i]]=0;flag=1;
			}
			else if(tab[a[o].s[i]]==-1)tab[a[o].s[i]]=cnt++;
		}
		for(int i=0;i<n;i++)a[o].num=a[o].num*cnt+tab[a[o].s[i]];
	}
	qsort(a+1,N,sizeof(CHR),cmp);
	for(int i=1;i<=N;i++)printf("%s\n",a[i].s);
	return 0;
}