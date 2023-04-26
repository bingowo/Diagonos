#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int table[26];
typedef struct{
	char S[21];
	int num;
}STR;
int cmp(const void* a,const void* b)
{
	STR x=*(STR*)a;STR y=*(STR*)b;
	if(x.num>y.num)return -1;
	else if(x.num==y.num)return strcmp(x.S,y.S);
	else return 1;
}
int main()
{
	int ct=0,T;scanf("%d",&T);
	STR str[105];
	while(T--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			memset(table,0,sizeof(table));
			str[i].num=0;
			scanf("%s",str[i].S);
			int len=strlen(str[i].S),cnt=0;
			for(int j=0;j<len;j++)
			if(table[str[i].S[j]-'A']==0)
			{
				table[str[i].S[j]-'A']=1;
				++cnt;
			}
			str[i].num=cnt;//printf("cnt=%d\n",cnt);
		}
		qsort(str+1,n,sizeof(STR),cmp);
		printf("case #%d:\n",ct++);
		for(int i=1;i<=n;i++)printf("%s\n",str[i].S);
	}
	return 0;
}